#ifndef IMMERSIVE_CHECKERS_PIECE_HPP
#define IMMERSIVE_CHECKERS_PIECE_HPP
#include <SFML/Graphics.hpp>

class Piece
{
public:
    float radius = 30;
    int x, y;
    int size = 75;
    bool isAlive;
    bool isKing = false;
    sf::Color color;

    void Draw(sf::RenderWindow& window) const;

};


#endif //IMMERSIVE_CHECKERS_PIECE_HPP
