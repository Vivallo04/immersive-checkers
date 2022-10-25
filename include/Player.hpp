//
// Created by josev on 25/10/22.
//

#ifndef IMMERSIVE_CHECKERS_PLAYER_HPP
#define IMMERSIVE_CHECKERS_PLAYER_HPP

#include "Board.hpp"
#include "Piece.hpp"


class ArduinoButton;
//class ArduinoLed;
//class ArduinoLedMatrix;


class Player {// This class permits to create a generic player, which will be inherited by the HumanPlayer and the AIPlayer classes
public:
    Player(bool, Board*,ArduinoButton*);// This constructor permits to create a player

    ~Player();// This destructor permits to destroy a player

    virtual bool makeMove();

    std::vector<Piece*> pieces;// This vector permits to know the pieces of the player

    bool turn;// This variable permits to know if it is the turn of the player

    void UpdatePieces();// This method permits to update the pieces of the player

    void UpdateQueens();// This method permits to update the queens of the player

    bool KillWasMade();// This method permits to know if a kill was made

protected:
    Board* board;// This variable permits to know the board of the player

    ArduinoButton* button;// This variable permits to know the button of the player

    void movePiece(std::vector<std::vector<int>>&,std::vector<Piece>, int,int,int);// This method permits to move a piece

    void InitTeam();// This method permits to initialize the team of the player

    bool sameTeam(int ,int);// This method permits to know if two pieces are of the same team

    int pieceTeamIndexXY(int,int);// This method permits to know the index of a piece in the pieces vector

    int currentIndex;// This variable permits to know the index of the piece that is being moved

    bool topSide;// This variable permits to know if the player is on the top side of the board

    int ONE;

    //These variables permit to know if the player o the AI is playing
    int TEAM_NUMBER;
    int ENEMY_TEAM_NUMBER;

};


#endif //IMMERSIVE_CHECKERS_PLAYER_HPP
