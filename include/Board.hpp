#ifndef IMMERSIVE_CHECKERS_BOARD_HPP
#define IMMERSIVE_CHECKERS_BOARD_HPP
#include <SFML/Graphics.hpp>

class Board
{

public:
    Board(sf::RenderWindow &gameWindow);

    ~Board();
    void Init();
    void Update();
    void HandleEvents();

private:
    sf::RenderWindow *gameWindow;
    int boardPositionX = 0;
    int boardPositionY = 0;
    int tileSize = 30;
    int boardSize = 8;

    void Draw();
};


#endif //IMMERSIVE_CHECKERS_BOARD_HPP
