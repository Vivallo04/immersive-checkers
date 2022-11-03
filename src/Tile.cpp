//
// Created by vivallo on 02/11/22.
//

#include "../include/Tile.hpp"

Tile::Tile(int tileSize, int x, int y, sf::Color color)
{
    this -> tileSize = tileSize;
    this -> gridX = x;
    this -> gridY = y;
    this -> x = (this -> gridX - 1) * 32;
    this -> y = (this -> gridY - 1) * 32;
    this -> color = color;
}


