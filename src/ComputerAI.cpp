#include "ComputerAI.hpp"

ComputerAI::ComputerAI(Board &board)
{
    this -> board = &board;
}

void ComputerAI::CheckForJump()
{/*
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (this->board[i][j] == 2)
            {
                if (this -> board[i + 1][j + 1] == 1)
                {
                    if (this -> board[i + 2][j + 2] == 0)
                    {
                        MovePiece(i + 2, j + 2);
                    }
                }
                if (this -> board[i + 1][j - 1] == 1)
                {
                    if (this -> board[i + 2][j - 2] == 0)
                    {
                        MovePiece(i + 2, j - 2);
                    }
                }
            }
            if (this -> board[i][j] == 4)
            {
                if (this -> board[i - 1][j + 1] == 3)
                {
                    if (this -> board[i - 2][j + 2] == 0)
                    {
                        MovePiece(i - 2, j + 2);
                    }
                }
                if (this -> board[i - 1][j - 1] == 3)
                {
                    if (this -> board[i - 2][j - 2] == 0)
                    {
                        MovePiece(i - 2, j - 2);
                    }
                }
            }
        }
    }*/
}
