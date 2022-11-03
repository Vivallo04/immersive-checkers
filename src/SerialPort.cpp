//
// Created by josev on 27/10/22.
//

#include "../include/SerialPort.h"
//Linux headers
#include <fcntl.h> // Contains file controls like O_RDWR
#include <errno.h> // Error integer and strerror() function
#include <termios.h> // Contains POSIX terminal control definitions
#include <unistd.h> // write(), read(), close()
#include <boost/log/trivial.hpp>

SerialPort::SerialPort(const char *portName)
{
    serialPort = open(portName, O_RDWR);
    if (serialPort == -1)
    {
        BOOST_LOG_TRIVIAL(error) << "Error " << errno << " opening " << portName << ": " << strerror(errno);

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

char SerialPort::getKeypadInput()
{
    //First we must read the first touch of the keypad
    char buffer;
    int bytesRead = read(serialPort, &buffer, 1);
    char key_input = buffer;
    int limit = 2;
    //When we press the keypad we get a 0x0D, so we must read the next two bytes
    for (int i = 0; i <2 ; ++i)
    {
        bytesRead = read(serialPort, &buffer, 1);

    }
    return key_input;

}

char SerialPort::writeSerialPort(char buffer_received)
{
    //This method is going to be used for the LED ATTACHMENT
    char buffer;
    buffer = buffer_received;
    //Write data to serial port
    write(serialPort, &buffer, 1);

    return buffer;
}

int SerialPort::closeSerialPort()
{
    close(serialPort);
    return 0;
}

