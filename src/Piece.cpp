#include "../include/Piece.hpp"
//#include "../src/util.hpp"

Directions QueenMoves[4] = {UP_LEFT, UP_RIGHT, BACK_LEFT, BACK_RIGHT};
Directions pieceMoves[2] = {UP_LEFT, UP_RIGHT};

Piece::Piece(Board& board)
{
    this -> board = &board;
    xPos = 0;
    yPos = 0;
    potential = -99999999;
    isQueen = false;

}

void Piece::Init()
{
    // texture
    //LoadTexture(checkerTexture, "assets/checker.png");
}

void Piece::PopulatePieceOnBoard()
{

}

void Piece::DrawCheckersOnBoard()
{
    checkerSprite.setTexture(checkerTexture);
    checkerSprite.setPosition(xPos * checkersSize, yPos * checkersSize);

}

void Piece::FindLargestPotential()
{
    int largest = directionValues[0];
    for (int i = 1; i < 4; i++)
    {
        if (largest < directionValues[i])
        {
            largest = directionValues[i];
        }
    }
    potential = largest;
}

void Piece::FindBestDirection()
{
    int largest = directionValues[0];
    std::vector<int> largestVector;

    for (int i = 1; i < 4; i++)
    {
        if (largest < directionValues[i])
        {
            largest = directionValues[i];
        }
    }

    for (int j = 0; j < 4; j++)
    {
        if (largest <= directionValues[j])
        {
            largestVector.push_back(j);
        }
    }

    srand(static_cast<unsigned int>(time(NULL)));
    int bestIndex = rand() % largestVector.size();

    for (auto & QueenMove : QueenMoves)
    {
        if (QueenMove == largestVector[bestIndex])
        {
            bestDirection = QueenMove;
        }
    }

}

void Piece::SetPoint(int x, int y)
{
    this -> xPos = x;
    this -> yPos = y;

}

bool Piece::IsQueen() const
{
    return isQueen;
}

void Piece::MakeQueen()
{
    isQueen = true;
}

void Piece::Move()
{

}

void Piece::CenterInBoard()
{

}
