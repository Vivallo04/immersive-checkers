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
    int boardPositionX = (int) gameWindow->getView().getSize().x / 2000;
    int boardPositionY = (int) gameWindow->getView().getSize().y / 4;
    int tileSize = 60;
    int boardSize = 8;

    void Draw();
};


#endif //IMMERSIVE_CHECKERS_BOARD_HPP
