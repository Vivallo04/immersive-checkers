//
// Created by josev on 27/10/22.
//

#include "../include/ArduinoController.hpp"

//First we must create the serialPort object which will be used to communicate with the Arduino
SerialPort serialPort("/dev/ttyACM0");
//Then we must create the
char bufferInit[2];
char bufferEnd[2];
std::string ArduinoController::getInitCords()
{
    for (int i = 0; i < 2; ++i)
    {
        char keypad = serialPort.getKeypadInput();
        std::cout << "Keypad: " << keypad << std::endl;
        bufferInit[i] = keypad;
    }
    if(bufferInit[0] == '1'){
        bufferInit[0] = 'a';
    }
    if (bufferInit[0] == '2'){
        bufferInit[0] = 'b';
    }
    if (bufferInit[0] == '3'){
        bufferInit[0] = 'c';
    }
    if (bufferInit[0] == '4'){
        bufferInit[0] = 'd';
    }
    if (bufferInit[0] == '5'){
        bufferInit[0] = 'e';
    }
    if (bufferInit[0] == '6'){
        bufferInit[0] = 'f';
    }
    if (bufferInit[0] == '7'){
        bufferInit[0] = 'g';
    }
    if (bufferInit[0] == '8'){
        bufferInit[0] = 'h';
    }
    if (bufferInit[0] == '9'){
        bufferInit[0] = ' ';
        bufferInit[1] = ' ';
        return getInitCords();
    }
    std::cout << "Buffer space 0: " << bufferInit[0] << std::endl;
    std::cout << "Buffer space 1: " << bufferInit[1] << std::endl;
    std::cout << "Board coords: " << bufferInit[0]<<bufferInit[1] << std::endl;
    std::string boardCoords = reinterpret_cast<const char *>(bufferInit[0] + bufferInit[1]);
    bufferInit[0] = ' ';
    bufferInit[1] = ' ';
    std::cout << "Board coords: " << boardCoords << std::endl;
    return boardCoords;
}

std::string ArduinoController::getFinalCords()
{
    for (int i = 0; i < 2; ++i)
    {
        char keypad = serialPort.getKeypadInput();
        std::cout << "Keypad: " << keypad << std::endl;
        bufferEnd[i] = keypad;
    }
    if(bufferEnd[0] == '1'){
        bufferEnd[0] = 'a';
    }
    if (bufferEnd[0] == '2'){
        bufferEnd[0] = 'b';
    }
    if (bufferEnd[0] == '3'){
        bufferEnd[0] = 'c';
    }
    if (bufferEnd[0] == '4'){
        bufferEnd[0] = 'd';
    }
    if (bufferEnd[0] == '5'){
        bufferEnd[0] = 'e';
    }
    if (bufferEnd[0] == '6'){
        bufferEnd[0] = 'f';
    }
    if (bufferEnd[0] == '7'){
        bufferEnd[0] = 'g';
    }
    if (bufferEnd[0] == '8'){
        bufferEnd[0] = 'h';
    }
    if (bufferEnd[0] == '9'){
        bufferEnd[0] = ' ';
        bufferEnd[1] = ' ';

        return getFinalCords();
    }
    std::cout << "Buffer space 0: " << bufferEnd[0] << std::endl;
    std::cout << "Buffer space 1: " << bufferEnd[1] << std::endl;
    std::cout << "Board coords: " << bufferEnd[0]<<bufferEnd[1] << std::endl;
    std::string boardCoords = reinterpret_cast<const char *>(bufferEnd[0] + bufferEnd[1]);
    bufferEnd[0] = ' ';
    bufferEnd[1] = ' ';
    return boardCoords;
}

int ArduinoController::getAttackLEDred()
{
    //This function will turn on the red LED on the Arduino
    //when the checker attacks a piece
    turnLEDon();
    sleep(10);
    turnLEDoff();
    return 0;
}

int ArduinoController::turnLEDon()
{
    serialPort.writeSerialPort('B');
    return 0;
}

int ArduinoController::closeSerialPort()
{
    serialPort.closeSerialPort();
    delete &serialPort;
    return 0;
}

int ArduinoController::turnLEDoff()
{
    serialPort.writeSerialPort('C');
    return 0;
}

