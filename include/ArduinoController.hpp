//
// Created by josev on 27/10/22.
//
#ifndef IMMERSIVE_CHECKERS_ARDUINOCONTROLLER_H
#define IMMERSIVE_CHECKERS_ARDUINOCONTROLLER_H

#include <iostream>
#include "unistd.h"
#include "SerialPort.h"
#include "thread"

class ArduinoController
{

public://Arduino keypad functions

    ArduinoController();//Constructor
    int* ChoosePosition();//Move the cursor to the position and press the button
    int Checkposition();//Check if the position is occupied
    int *MovePiece();//Move the piece to the position
    int closeSerialPort();//Close the serial port







    SerialPort *serialport;
};


#endif //IMMERSIVE_CHECKERS_ARDUINOCONTROLLER_H
