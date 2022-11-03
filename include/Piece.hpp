#ifndef IMMERSIVE_CHECKERS_PIECE_HPP
#define IMMERSIVE_CHECKERS_PIECE_HPP
#include <SFML/Graphics.hpp>

class Piece
{
public:
    float radius = 30;
    int x, y;
    bool isAlive;
    bool isKing;
    sf::Color color;

    void Draw(sf::RenderWindow  window);

};


#endif //IMMERSIVE_CHECKERS_PIECE_HPP
