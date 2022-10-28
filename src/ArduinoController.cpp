//
// Created by josev on 27/10/22.
//

#include "../include/ArduinoController.hpp"


ArduinoController::ArduinoController()
{
    //This instance permits to open the serial port and also to check if it is connected
    serialport = new SerialPort("/dev/ttyACM0");
}

int *ArduinoController::ChoosePosition()
{
    //Move the cursor to the position and press the button
    return 0;
}

int ArduinoController::Checkposition()
{
    return 0;
}

int *ArduinoController::MovePiece()
{
    return 0;
}

int ArduinoController::closeSerialPort()
{
    return 0;
}

