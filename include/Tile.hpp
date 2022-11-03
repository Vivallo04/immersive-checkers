#ifndef IMMERSIVE_CHECKERS_TILE_HPP
#define IMMERSIVE_CHECKERS_TILE_HPP
#include <SFML/Graphics.hpp>

class Tile
{
public:
    Tile(int tileSize, int x, int y, sf::Color color);

private:
    int tileSize;
    int gridX;
    int gridY;
    int x;
    int y;
    sf::Color color;
};



#endif //IMMERSIVE_CHECKERS_TILE_HPP
