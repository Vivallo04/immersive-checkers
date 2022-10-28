//
// Created by josev on 27/10/22.
//

#include "../include/SerialPort.h"
//Linux headers
#include <fcntl.h> // Contains file controls like O_RDWR
#include <errno.h> // Error integer and strerror() function
#include <termios.h> // Contains POSIX terminal control definitions
#include <unistd.h> // write(), read(), close()

SerialPort::SerialPort(const char *portName)
{
    serialPort = open(portName, O_RDWR);
    if (serialPort == -1)
    {
        std::cout << "Error " << errno << " opening " << portName << ": " << strerror(errno) << std::endl;
    }
    else
    {
        connected = true;
        fcntl(serialPort, F_SETFL, 0);
    }

}

SerialPort::~SerialPort()
{
    //close serial port
    //Only made if by default

}

char SerialPort::readSerialPort(char *buffer, unsigned int buf_size)//read data from serial port
{
    //Read data from serial port
    int bytesRead = read(serialPort, buffer, buf_size);

    return *buffer;
}

char SerialPort::writeSerialPort(char *buffer, unsigned int buf_size)
{

    //Write data to serial port
    int bytesWritten = write(serialPort, buffer, buf_size);

    return *buffer;
}

char SerialPort::getKeypadInput()
{
    char bufferkey[256];
    char keypadCord = readSerialPort(char*bufferkey, sizeof(bufferkey));

    int counter = 0;
    while (counter <2){//read the two first touches of the keypad
        readSerialPort(char* bufferkey, sizeof(bufferkey));
        counter ++;
    }
    return keypadCord;

}

int SerialPort::closeSerialPort()
{
    close(serialPort);
    return 0;
}

