#ifndef IMMERSIVE_CHECKERS_BOARD_HPP
#define IMMERSIVE_CHECKERS_BOARD_HPP

#include <SFML/Graphics.hpp>
#include <boost/timer/timer.hpp>

class Board
{
public:
    Board(sf::RenderWindow &gameWindow);
    ~Board();

    void Init();
    void Update();
    void HandleEvents();
    int **PopulateBoard();
    int **SetBoard();
    void RenderPieces();
    void InitBoard();
    void HighlightTile(int x, int y);
    void MoveHighlightWithArrowKeys();


private:
    sf::RenderWindow *gameWindow;
    int boardPositionX = 1280/5;
    int boardPositionY = 720/16;
    int tileSize = 60;
    int boardSize = 8;

    int highlightedTileX = 0;
    int highlightedTileY = 0;
    int** board = new int*[boardSize];


    void Draw();
};


#endif //IMMERSIVE_CHECKERS_BOARD_HPP