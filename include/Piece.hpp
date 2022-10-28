#ifndef IMMERSIVE_CHECKERS_PIECE_H
#define IMMERSIVE_CHECKERS_PIECE_H

#include "Board.hpp"
#include <SFML/Graphics.hpp>

enum Directions
{
    UP_LEFT,
    UP_RIGHT,
    BACK_LEFT,
    BACK_RIGHT
};


class Piece
{
public:
    explicit Piece(Board& board);
    void Init();
    void SetPoint(int x, int y);
    bool IsQueen() const;
    void MakeQueen();//This method permits to make a piece a isQueen
    void FindBestDirection();// This method permits to find the best direction of the piece
    void FindLargestPotential();// This method permits to find the largest potential of the piece
    void DrawCheckersOnBoard();
    void PopulatePieceOnBoard();
    void Move();
    void CenterInBoard();

private:
    // Graphics
    int checkersSize = 50;

    // In-game position
    int xPos; // This variable permits to know the xPos position of the piece
    int yPos; // This variable permits to know the yPos position of the piece

    // Attributes
    int potential; // This variable permits to know the potential of the piece
    Board *board;
    Directions bestDirection; // This variable permits to know the best direction of the piece
    int directionValues[4] = {-999, -999, -999,-999};// This array permits to know the potential of the piece in each direction
    bool isQueen; // This variable permits to know if the piece is a isQueen


    // SFML
    sf::Texture checkerTexture;
    sf::Sprite checkerSprite;
};


#endif //IMMERSIVE_CHECKERS_PIECE_H
