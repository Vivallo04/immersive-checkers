//
// Created by vivallo on 02/11/22.
//

#include "../include/Checker.hpp"

void Checker::play()
{
    /*//backtracking algorithm
    //if the checker is not in the end zone
    if(!isKing)
    {
        //if the checker is in the first row
        if (row == 0)
        {
            //if the checker is at the left side of the board
            if (col == 0)
            {
                //if the next position is free
                if (board[row + 1][col + 1] == nullptr)
                {
                    //move the checker to the next position
                    board[row + 1][col + 1] = this;
                    //set the previous position to null
                    board[row][col] = nullptr;
                }
            }
                //if the checker is at the right side of the board
            else if (col == 7)
            {
                //if the next position is free
                if (board[row + 1][col - 1] == nullptr)
                {
                    //move the checker to the next position
                    board[row + 1][col - 1] = this;
                    //set the previous position to null
                    board[row][col] = nullptr;
                }
            }
                //if the checker is in the middle of the board
            else
            {
                //if the next position is free
                if (board[row + 1][col + 1] == nullptr)
                {
                    //move the checker to the next position
                    board[row + 1][col + 1] = this;
                    //set the previous position to null
                    board[row][col] = nullptr;
                }
                //if the next position is free
                if (board[row + 1][col - 1] == nullptr)
                {
                    //move the checker to the next position
                    board[row + 1][col - 1] = this;
                    //set the previous position to null
                    board[row][col] = nullptr;
                }
            }
        }
            //if the checker is in the second row
        else if (row == 1)
        {
            //if the checker is at the left side of the board
            if (col == 0)
            {
                //if the next position is free
                if (board[row + 1][col + 1] == nullptr)
                {
                    //move the checker to the next position
                    board[row + 1][col + 1] = this;
                    //set the previous position to null
                    board[row][col] = nullptr;
                }
                //if the next position is free
                if (board[row - ][col + 1] == nullptr)
                {
                    //move the checker to the next position
                    board[row - 1][col + 1] = this;
                    //set the previous position to null
                    board[row][col] = nullptr;
                }
            }
        }
    }*/
}
