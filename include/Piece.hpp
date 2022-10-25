//
// Created by josev on 24/10/22.
//

#ifndef IMMERSIVE_CHECKERS_PIECE_H
#define IMMERSIVE_CHECKERS_PIECE_H

#include "vector"
#include "cstdlib"
#include "stdlib.h"
#include "time.h"

enum Directions{
    LEFT,
    RIGHT,
    BACK_LEFT,
    BACK_RIGHT
};



class Piece {
public:
    Piece();
    void setPoint(int, int);
    bool isQueen();//This method permits to know if the piece is a queen

    void makeQueen();//This method permits to make a piece a queen

    int x;//This variable permits to know the x position of the piece

    int y;// This variable permits to know the y position of the piece

    int potential;// This variable permits to know the potential of the piece

    int directionValues[4] = {-999,-999,-999,-999};// This array permits to know the potential of the piece in each direction

    Directions bestDirection;// This variable permits to know the best direction of the piece

    void findBestDirection();// This method permits to find the best direction of the piece

    void findLargestPotential();// This method permits to find the largest potential of the piece

private:
    bool queen;// This variable permits to know if the piece is a queen
};



#endif //IMMERSIVE_CHECKERS_PIECE_H
