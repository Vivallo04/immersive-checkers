//
// Created by josev on 27/10/22.
//
#ifndef IMMERSIVE_CHECKERS_ARDUINOCONTROLLER_H
#define IMMERSIVE_CHECKERS_ARDUINOCONTROLLER_H


#include <unistd.h>//sleep
#include <thread>//thread
#include <iostream>
#include "SerialPort.hpp"//SerialPort class
#include "boost/log/trivial.hpp"//Logging

class ArduinoController
{
public:

    std::string getInitCords();
    std::string getFinalCords();
    int getAttackLEDred();
    int turnLEDon();
    int turnLEDoff();
    int closeSerialPort();
    int getEvent();

    void getSerial();


};





#endif //IMMERSIVE_CHECKERS_ARDUINOCONTROLLER_H
