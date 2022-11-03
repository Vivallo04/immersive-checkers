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
    void GetCurrentTilePosition(int x, int y);
    void MovePiece(int x, int y);
    void CheckForJump();
    void HighlightMoveableTiles();
    void CheckForWin();
    void ResetBoard();
    void HighlightPiece(int x, int y);
    void HighlightMoveableTiles(int x, int y);
    void MoveHighlightedPiece(int x, int y);
    void HighlightJumpableTiles(int x, int y);



private:
    sf::RenderWindow *gameWindow;
    int boardPositionX = 1280/5;
    int boardPositionY = 720/16;
    int tileSize = 60;
    int boardSize = 8;

    bool isTileHighlighted = false;
    int highlightedTileX = 0;
    int highlightedTileY = 0;
    int** board = new int*[boardSize];


    void Draw();
};


#endif //IMMERSIVE_CHECKERS_BOARD_HPP