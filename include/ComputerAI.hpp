#ifndef IMMERSIVE_CHECKERS_COMPUTERAI_HPP
#define IMMERSIVE_CHECKERS_COMPUTERAI_HPP


#include "Board.hpp"

class ComputerAI
{
public:
    ComputerAI(Board &board);
    void MovePiece(int x, int y);
    void CheckForJump();


private:
    Board *board;
};


#endif //IMMERSIVE_CHECKERS_COMPUTERAI_HPP
