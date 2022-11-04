/*
//
// Created by josev on 27/10/22.
//
#ifndef IMMERSIVE_CHECKERS_ARDUINOCONTROLLER_H
#define IMMERSIVE_CHECKERS_ARDUINOCONTROLLER_H

#include <iostream>
#include "unistd.h"
#include "SerialPort.h"
#include "thread"
#include "third-party/include/serial/serial.h"


class ArduinoController
{

public://Arduino keypad functions

    ArduinoController();//Constructor

    bool Checkposition(int row, int column);//Check if the position is occupied
    int *MoveCursor(int x, int y);//Move the cursor to the position and press the button
    bool isConected();//Check if the arduino is connected
    void moveRight(int x, int y);//Move the cursor to the right
    void moveLeft(int x, int y);//Move the cursor to the left
    void moveUp(int x, int y);//Move the cursor to the up
    void moveDown(int x, int y);//Move the cursor to the down
    char getKeypadInput();//Get the keypad input
    int *MovePiece(int x, int y);//Move the piece to the position
    bool isSelected();//Check if the piece is selected
    bool isQueen();//Check if the piece is a queen
    bool isChecker();//Check if the piece is a checker

    int makeQueen();//Make the piece a queen
    int closeSerialPort();//Close the serial port
    //serial::Serial my_serial("/dev/ttyACM0", 9600, serial::Timeout::simpleTimeout(1000));
private:

    int boardmatrix[8][8] = {
            {0, 3, 0, 3, 0, 3, 0, 3},
            {3, 0, 3, 0, 3, 0, 3, 0},
            {0, 3, 0, 3, 0, 3, 0, 3},
            {1, 0, 1, 0, 1, 0, 1, 0},
            {0, 1, 0, 1, 0, 1, 0, 1},
            {2, 0, 2, 0, 2, 0, 2, 0},
            {0, 2, 0, 2, 0, 2, 0, 2},
            {2, 0, 2, 0, 2, 0, 2, 0}
    };//Board matrix
    SerialPort *serialport;
    bool connectioncomplete = false;
    int cursorposition = boardmatrix[0][0];//Initialize the cursor position
    int rows_size = sizeof(boardmatrix) / sizeof(boardmatrix[0]);
    int columns_size = sizeof(boardmatrix[0]) / sizeof(boardmatrix[0][0]);

};


#endif //IMMERSIVE_CHECKERS_ARDUINOCONTROLLER_H*/
