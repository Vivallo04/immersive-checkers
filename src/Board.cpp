#include "../include/Board.hpp"
#include <SFML/Graphics.hpp>
#include "boost/log/trivial.hpp"
#include <boost/timer/timer.hpp>


Board::Board(sf::RenderWindow &gameWindow)
{
    BOOST_LOG_TRIVIAL(info) << "Board constructor called";
    this -> gameWindow = &gameWindow;
    this -> gameWindow->setKeyRepeatEnabled(false);
    this -> InitBoard();
    this -> HighlightTile(0, 0);
}

Board::~Board()
{

}

void Board::Init()
{
    this -> Draw();
}

void Board::Draw()
{
    for (int i = 0; i < boardSize; i++)
    {
        for (int j = 0; j < boardSize; j++)
        {
            if ((i + j) % 2 == 0)
            {
                sf::RectangleShape rect(sf::Vector2f(tileSize, tileSize));
                rect.setPosition(boardPositionX + (i * tileSize), boardPositionY + (j * tileSize));
                rect.setFillColor(sf::Color(255, 207, 159, 255));
                gameWindow -> draw(rect);
            } else
            {
                sf::RectangleShape rect(sf::Vector2f(tileSize, tileSize));
                rect.setPosition(boardPositionX + (i * tileSize), boardPositionY + (j * tileSize));
                rect.setFillColor(sf::Color(209, 139, 71, 255));
                gameWindow -> draw(rect);
            }
        }
    }
}

void Board::InitBoard()
{
    SetBoard();
    PopulateBoard();
}

void Board::Update()
{
    //Draw();
}

void Board::HandleEvents()
{
    sf::Event event;
    while (gameWindow -> pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        {
            gameWindow -> close();
        }
        if (event.type == sf::Event::KeyPressed)
        {
            if (event.key.code == sf::Keyboard::Up)
            {
                if (highlightedTileY > 0)
                {
                    highlightedTileY--;
                }
            }
            if (event.key.code == sf::Keyboard::Down)
            {
                if (highlightedTileY < 7)
                {
                    highlightedTileY++;
                }
            }
            if (event.key.code == sf::Keyboard::Left)
            {
                if (highlightedTileX > 0)
                {
                    highlightedTileX--;
                }
            }
            if (event.key.code == sf::Keyboard::Right)
            {
                if (highlightedTileX < 7)
                {
                    highlightedTileX++;
                }
            }
            if (event.key.code == sf::Keyboard::Enter)
            {
                HighlightPiece(highlightedTileX, highlightedTileY);
            }
        }
    }
    HighlightTile(highlightedTileX, highlightedTileY);
}

// returns a matrix with zeros
int** Board::SetBoard()
{
    for (int i = 0; i < boardSize; i++)
    {
        this -> board[i] = new int[boardSize];
        for (int j = 0; j < boardSize; j++)
        {
            this -> board[i][j] = 0;
        }
    }

    BOOST_LOG_TRIVIAL(debug) << "Board initialized";
    return this -> board;
}

// populates the board with checkers
int **Board::PopulateBoard()
{
    for (int i = 0; i < boardSize; i++)
    {
        for (int j = 0; j < boardSize; j++)
        {
            if (i % 2 == 0)
            {
                if (j % 2 == 0)
                {
                    this -> board[i][j] = 0;
                } else
                {
                    if (j < 3)
                    {
                        this -> board[i][j] = 1;
                    } else if (j > 4)
                    {
                        this -> board[i][j] = 2;
                    } else
                    {
                        this -> board[i][j] = 0;
                    }
                }
            } else
            {
                if (j % 2 == 0)
                {
                    if (j < 3)
                    {
                        this -> board[i][j] = 1;
                    } else if (j > 4)
                    {
                        this -> board[i][j] = 2;
                    } else
                    {
                        this -> board[i][j] = 0;
                    }
                } else
                {
                    this -> board[i][j] = 0;
                }
            }
        }
    }
    BOOST_LOG_TRIVIAL(debug) << "Board populated";
    return this -> board;
}

void Board::RenderPieces()
{
    for (int i = 0; i < boardSize; i++)
    {
        for (int j = 0; j < boardSize; j++)
        {
            if (this -> board[i][j] == 1)
            {
                sf::CircleShape circle(tileSize/2);
                circle.setFillColor(sf::Color(255, 0, 0, 255));
                circle.setPosition(boardPositionX + (i * tileSize), boardPositionY + (j * tileSize));
                gameWindow -> draw(circle);
            }
            if (this -> board[i][j] == 2)
            {
                sf::CircleShape circle(tileSize/2);
                circle.setFillColor(sf::Color(255, 255, 255, 255));
                circle.setPosition(boardPositionX + (i * tileSize), boardPositionY + (j * tileSize));
                gameWindow -> draw(circle);
            }
        }
    }
}

void Board::HighlightTile(int x, int y)
{
    sf::RectangleShape tile(sf::Vector2f(tileSize, tileSize));
    tile.setFillColor(sf::Color(0, 0, 0, 0));
    tile.setOutlineThickness(4.0f);
    tile.setPosition(boardPositionX + (x * tileSize), boardPositionY + (y * tileSize));
    gameWindow -> draw(tile);
}

[[maybe_unused]] void Board::MoveHighlightWithArrowKeys()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        if (this -> highlightedTileX > 0)
        {
            this -> highlightedTileX--;
            BOOST_LOG_TRIVIAL(info) << "Current position: " << board[highlightedTileX][highlightedTileY];
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        if (this -> highlightedTileX < 7)
        {
            this -> highlightedTileX++;
            BOOST_LOG_TRIVIAL(info) << "Current position: " << board[highlightedTileX][highlightedTileY];
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        if (this -> highlightedTileY > 0)
        {
            this -> highlightedTileY--;
            BOOST_LOG_TRIVIAL(info) << "Current position: " << board[highlightedTileX][highlightedTileY];
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        if (this -> highlightedTileY < 7)
        {
            this -> highlightedTileY++;
            BOOST_LOG_TRIVIAL(info) << "Current position: " << board[highlightedTileX][highlightedTileY];
        }
    }
    HighlightTile(highlightedTileX, highlightedTileY);
}

void Board::GetCurrentTilePosition(int x, int y)
{
    BOOST_LOG_TRIVIAL(info) << "Current position: " << board[x][y];
}

void Board::MovePiece(int x, int y)
{
    if (this -> board[x][y] == 1)
    {
        this -> board[x][y] = 0;
        this -> board[x-1][y-1] = 1;
        this -> board[x+1][y-1] = 1;
    }
    if (this -> board[x][y] == 2)
    {
        this -> board[x][y] = 0;
        this -> board[x-1][y+1] = 2;
        this -> board[x+1][y+1] = 2;
    }
}

[[maybe_unused]] void Board::CheckForJump()
{
    for (int i = 0; i < boardSize; i++)
    {
        for (int j = 0; j < boardSize; j++)
        {
            if (this->board[i][j] == 1)
            {
                if (this->board[i - 1][j - 1] == 2 && this->board[i - 2][j - 2] == 0)
                {
                    this->board[i - 1][j - 1] = 0;
                }
                if (this->board[i + 1][j - 1] == 2 && this->board[i + 2][j - 2] == 0)
                {
                    this->board[i + 1][j - 1] = 0;
                }
            }
            if (this->board[i][j] == 2)
            {
                if (this->board[i - 1][j + 1] == 1 && this->board[i - 2][j + 2] == 0)
                {
                    this->board[i - 1][j + 1] = 0;
                }
                if (this->board[i + 1][j + 1] == 1 && this->board[i + 2][j + 2] == 0)
                {
                    this->board[i + 1][j + 1] = 0;
                }
            }
        }
    }
}


void Board::HighlightMoveableTiles()
{
    for (int i = 0; i < boardSize; i++)
    {
        for (int j = 0; j < boardSize; j++)
        {
            if (this->board[i][j] == 1)
            {
                if (this->board[i - 1][j - 1] == 0)
                {
                    sf::RectangleShape rect(sf::Vector2f(tileSize, tileSize));
                    rect.setFillColor(sf::Color(0, 0, 0, 0));
                    rect.setOutlineThickness(4.0f);
                    rect.setPosition(boardPositionX + ((i - 1) * tileSize), boardPositionY + ((j - 1) * tileSize));
                    gameWindow->draw(rect);
                }
                if (this->board[i + 1][j - 1] == 0)
                {
                    sf::RectangleShape rect(sf::Vector2f(tileSize, tileSize));
                    rect.setFillColor(sf::Color(0, 0, 0, 0));
                    rect.setOutlineThickness(4.0f);
                    rect.setPosition(boardPositionX + ((i + 1) * tileSize), boardPositionY + ((j - 1) * tileSize));
                    gameWindow->draw(rect);
                }
            }
            if (this->board[i][j] == 2)
            {
                if (this->board[i - 1][j + 1] == 0)
                {
                    sf::RectangleShape rect(sf::Vector2f(tileSize, tileSize));
                    rect.setFillColor(sf::Color(0, 0, 0, 0));
                    rect.setOutlineThickness(4.0f);
                    rect.setPosition(boardPositionX + ((i - 1) * tileSize), boardPositionY + ((j + 1) * tileSize));
                    gameWindow->draw(rect);
                }
                if (this->board[i + 1][j + 1] == 0)
                {
                    sf::RectangleShape rect(sf::Vector2f(tileSize, tileSize));
                    rect.setFillColor(sf::Color(0, 0, 0, 0));
                    rect.setOutlineThickness(4.0f);
                    rect.setPosition(boardPositionX + ((i + 1) * tileSize), boardPositionY + ((j + 1) * tileSize));
                    gameWindow->draw(rect);
                }
            }
        }
    }
}

void Board::HighlightPiece(int x, int y)
{
    BOOST_LOG_TRIVIAL(info) << "Highlighting piece at: " << x << "," << y;
    sf::RectangleShape rect(sf::Vector2f(tileSize, tileSize));
    rect.setFillColor(sf::Color(0, 255, 0, 0));
    rect.setOutlineThickness(4.0f);
    rect.setPosition(boardPositionX + (x * tileSize), boardPositionY + (y * tileSize));
    gameWindow->draw(rect);
}

void Board::MoveHighlightedPiece(int x, int y)
{
    if (this->board[x][y] == 1)
    {
        this->board[x][y] = 0;
        this->board[x - 1][y - 1] = 1;
        this->board[x + 1][y - 1] = 1;
    }
}

void Board::HighlightJumpableTiles(int x, int y)
{
    if (this->board[x][y] == 1)
    {
        if (this->board[x - 1][y - 1] == 2 && this->board[x - 2][y - 2] == 0)
        {
            sf::RectangleShape rect(sf::Vector2f(tileSize, tileSize));
            rect.setFillColor(sf::Color(0, 0, 0, 0));
            rect.setOutlineThickness(4.0f);
            rect.setPosition(boardPositionX + ((x - 2) * tileSize), boardPositionY + ((y - 2) * tileSize));
            gameWindow->draw(rect);
        }
        if (this->board[x + 1][y - 1] == 2 && this->board[x + 2][y - 2] == 0)
        {
            sf::RectangleShape rect(sf::Vector2f(tileSize, tileSize));
            rect.setFillColor(sf::Color(0, 0, 0, 0));
            rect.setOutlineThickness(4.0f);
            rect.setPosition(boardPositionX + ((x + 2) * tileSize), boardPositionY + ((y - 2) * tileSize));
            gameWindow->draw(rect);
        }
    }
    if (this->board[x][y] == 2)
    {
        if (this->board[x - 1][y + 1] == 1 && this->board[x - 2][y + 2] == 0)
        {
            sf::RectangleShape rect(sf::Vector2f(tileSize, tileSize));
            rect.setFillColor(sf::Color(0, 0, 0, 0));
            rect.setOutlineThickness(4.0f);
            rect.setPosition(boardPositionX + ((x - 2) * tileSize), boardPositionY + ((y + 2) * tileSize));
            gameWindow->draw(rect);
        }
        if (this->board[x + 1][y + 1] == 1 && this->board[x + 2][y + 2] == 0)
        {
            sf::RectangleShape rect(sf::Vector2f(tileSize, tileSize));
            rect.setFillColor(sf::Color(0, 0, 0, 0));
            rect.setOutlineThickness(4.0f);
            rect.setPosition(boardPositionX + ((x + 2) * tileSize), boardPositionY + ((y + 2) * tileSize));
        }
    }
}

[[maybe_unused]] void Board::CheckForWin()
{
    int player1Count = 0;
    int player2Count = 0;
    for (int i = 0; i < boardSize; i++)
    {
        for (int j = 0; j < boardSize; j++)
        {
            if (this->board[i][j] == 1)
            {
                player1Count++;
            }
            if (this->board[i][j] == 2)
            {
                player2Count++;
            }
        }
    }
    if (player1Count == 0)
    {
        BOOST_LOG_TRIVIAL(info) << "Player 2 wins!";
        gameWindow->close();
    }
    if (player2Count == 0)
    {
        BOOST_LOG_TRIVIAL(info) << "Player 1 wins!";
        gameWindow->close();
    }
}