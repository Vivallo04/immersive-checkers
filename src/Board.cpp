#include "../include/Board.hpp"
#include <SFML/Graphics.hpp>
#include "boost/log/trivial.hpp"

Board::Board()
{
    //Init();
}


Board::~Board()
{

}

void Board::Init()
{
    //Draw();
}

void Board::Draw()
{
    BOOST_LOG_TRIVIAL(info) << "Board is being drawn";
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if ((i + j) % 2 == 0)
            {
                sf::RectangleShape rect(sf::Vector2f(100, 100));
                rect.setPosition(i * 100, j * 100);
                rect.setFillColor(sf::Color(0, 0, 0, 255));
                gameWindow.draw(rect);
            }
            else
            {
                sf::RectangleShape rect(sf::Vector2f(100, 100));
                rect.setPosition(i * 100, j * 100);
                rect.setFillColor(sf::Color(255, 255, 255, 255));
                gameWindow.draw(rect);
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
