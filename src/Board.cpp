#include "../include/Board.hpp"
#include <SFML/Graphics.hpp>
#include "boost/log/trivial.hpp"
#include <boost/timer/timer.hpp>


Board::~Board()
{
    delete[] this -> board;
}

void Board::Draw(sf::RenderWindow& window)
{
    sf::RectangleShape tile;
    tile.setSize(sf::Vector2f((float)tileSize, (float)tileSize));
    for (int i = 0;i < size;i++)
    {
        for (int j = 0;j < size;j++)
        {
            tile.setPosition(sf::Vector2f((float)tileSize * i, (float)tileSize * j));
            if ((i + j) % 2 == 0)
            {
                tile.setFillColor(sf::Color(255, 207, 159, 255));
            }
            else
            {
                tile.setFillColor(sf::Color(209, 139, 71, 255));
            }
            window.draw(tile);
        }
    }
}

void Board::HandleEvents()
{
    sf::Event event{};
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
                HighlightWithRectangle(highlightedTileX, highlightedTileY);
            }
        }
    }
    HighlightWithRectangle(highlightedTileX, highlightedTileY);
}

void Board::HighlightWithRectangle(int x, int y)
{
    sf::RectangleShape tile(sf::Vector2f((float)tileSize, (float)tileSize));
    tile.setFillColor(sf::Color(0, 0, 0, 0));
    tile.setOutlineThickness(4.0f);
    tile.setPosition((float)(x * tileSize), (float)(y * tileSize));
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
    HighlightWithRectangle(highlightedTileX, highlightedTileY);
}

[[maybe_unused]] void Board::CheckForJump()
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
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
/*
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
}*/

void Board::Highlight(sf::RenderWindow& window, int x, int y) const
{
    sf::RectangleShape tile;
    tile.setSize(sf::Vector2f((float) tileSize, (float)tileSize));
    tile.setFillColor(sf::Color::Green);
    tile.setPosition(sf::Vector2f((float) tileSize * (float)x, (float)tileSize * (float)y));
    window.draw(tile);
}
