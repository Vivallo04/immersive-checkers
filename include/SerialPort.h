//
// Created by josev on 27/10/22.
//

#ifndef IMMERSIVE_CHECKERS_SERIALPORT_H
#define IMMERSIVE_CHECKERS_SERIALPORT_H

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
    ~SerialPort();
    char getKeypadInput();//read the two first touches of the keypad
    char writeSerialPort(char buffer_received);//write data to serial port
    int closeSerialPort();//close serial port

private:
    int serialPort;//declare serial port
    bool connected = false;//check if the serial port is connected
};






#endif //IMMERSIVE_CHECKERS_SERIALPORT_H
