#include "../include/Piece.hpp"


void Piece::Draw(sf::RenderWindow& window) const
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
        shape.setPosition(sf::Vector2f(x * size + (size - radius * 2) / 2, y * size + (size - 2 * radius) / 2));
        window.draw(shape);
    }
}
