#ifndef IMMERSIVE_CHECKERS_BOARD_HPP
#define IMMERSIVE_CHECKERS_BOARD_HPP
#include <SFML/Graphics.hpp>

class Board
{
private:
    sf::RenderWindow gameWindow;

public:
    Board();
    ~Board();
    void Init();
    void Update();
    void HandleEvents();
    void Draw();
};


#endif //IMMERSIVE_CHECKERS_BOARD_HPP
