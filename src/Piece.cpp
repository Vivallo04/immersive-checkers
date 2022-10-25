//
// Created by josev on 24/10/22.
//



#include "../include/Piece.hpp"

Directions kingMoves[4]= {LEFT,RIGHT,BACK_LEFT,BACK_RIGHT};

Directions pieceMoves[2]= {LEFT,RIGHT};

Piece::Piece() {

    x= 0;
    y= 0;
    potential= -99999999;
    queen = false;

}

void Piece::setPoint(int xLocation, int yLocation) {
    x = xLocation;
    y = yLocation;

}


bool Piece::isQueen() {
    return queen;

}


void Piece::makeQueen()  {
    queen = true;

}



void Piece::findLargestPotential() {
    int largest = directionValues[0];

    for (int i=1; i<4; i++) {
        if (largest < directionValues[i]) {
            largest = directionValues[i];
        }
    }
    potential = largest;
}


void Piece::findBestDirection (){
    int largest = directionValues[0];
    std::vector<int> largestVector;

    for (int i=1; i<4; i++) {
        if (largest < directionValues[i]) {
            largest = directionValues[i];
        }
    }

    for(int j=0; j<4; j++){
        if (largest <= directionValues[j]) {
            largestVector.push_back(j);
        }
    }

    srand(static_cast<unsigned int>(time(NULL)));
    int bestIndex = rand() % largestVector.size();

    for(int k=0; k<4; k++){
        if (kingMoves[k] == largestVector[bestIndex]) {
            bestDirection = kingMoves[k];
        }
    }

}



