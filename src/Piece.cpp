#include "../include/Piece.hpp"


void Piece::Draw(sf::RenderWindow window)
{
    if (isAlive)
    {
        sf::CircleShape shape(radius);
        shape.setFillColor(color);
        if (isKing)
        {
            shape.setOutlineThickness(3.f);
            shape.setOutlineColor(sf::Color::Yellow);
        }
        shape.setPosition(sf::Vector2f(x * 75 + (75 - radius * 2) / 2, y * 75 + (75 - 2 * radius) / 2));
        window.draw(shape);
    }
}
