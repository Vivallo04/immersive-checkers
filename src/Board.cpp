#include "../include/Board.hpp"
#include <SFML/Graphics.hpp>
#include "boost/log/trivial.hpp"
#include <boost/timer/timer.hpp>


Board::Board(sf::RenderWindow &gameWindow)
{
    BOOST_LOG_TRIVIAL(info) << "Board constructor called";
    this -> gameWindow = &gameWindow;
    this->gameWindow->setKeyRepeatEnabled(false);
    this -> InitBoard();
    this ->HighlightTile(0, 0);
    //this->HandleEvents();

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
    sf::RectangleShape rect(sf::Vector2f(tileSize, tileSize));
    rect.setFillColor(sf::Color(0, 0, 0, 0));
    rect.setOutlineThickness(4.0f);
    rect.setPosition(boardPositionX + (x * tileSize), boardPositionY + (y * tileSize));
    gameWindow -> draw(rect);
}

void Board::MoveHighlightWithArrowKeys()
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


