//
// Created by josev on 27/10/22.
//

#ifndef IMMERSIVE_CHECKERS_SERIALPORT_HPP
#define IMMERSIVE_CHECKERS_SERIALPORT_HPP

//C library headers
#include <iostream>
#include <stdio.h>
#include <string.h>

/*//Linux headers
#include <fcntl.h> // Contains file controls like O_RDWR
#include <errno.h> // Error integer and strerror() function
#include <termios.h> // Contains POSIX terminal control definitions
#include <unistd.h> // write(), read(), close()*/

//References
//https://www.cmrr.umn.edu/~strupp/serial.html
//https://blog.mbedded.ninja/programming/operating-systems/linux/linux-serial-ports-using-c-cpp/


class SerialPort
{
public:

    SerialPort(const char *portName);//constructor
    int readSerialPort();//read data from serial port
    char getKeypadInput();//read the two first touches of the keypad
    int writeSerialPort(char data_read);//write data to serial port
    int closeSerialPort();//close serial port

    int getSerialPort();

    void available();

private:
    int serialPort;//declare serial port
    bool connected;//check if the serial port is connected
};








#endif //IMMERSIVE_CHECKERS_SERIALPORT_HPP
