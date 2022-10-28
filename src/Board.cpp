#include "../include/Board.hpp"
#include <SFML/Graphics.hpp>
#include "boost/log/trivial.hpp"


Board::Board(sf::RenderWindow &gameWindow)
{
    BOOST_LOG_TRIVIAL(info) << "Board constructor called";
    this->gameWindow = &gameWindow;
}

Board::~Board()
{

}

void Board::Init()
{
    this->Draw();
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
                gameWindow->draw(rect);
            } else
            {
                sf::RectangleShape rect(sf::Vector2f(tileSize, tileSize));
                rect.setPosition(boardPositionX + (i * tileSize), boardPositionY + (j * tileSize));
                rect.setFillColor(sf::Color(209, 139, 71, 255));
                gameWindow->draw(rect);
            }
        }
    }
}

void Board::Update()
{
    //Draw();
}

void Board::HandleEvents()
{

}