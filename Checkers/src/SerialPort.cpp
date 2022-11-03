//
// Created by josev on 27/10/22.
//

#include "../include/SerialPort.hpp"
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






int SerialPort::writeSerialPort(char data_read)//
{
    char data = data_read;
    //Write data to serial port
    int bytesWritten = write(serialPort, &data, sizeof(data_read));
    //std::cout << "Write data read: " << data << std::endl;
    //std::cout << "Write bytes written : " << bytesWritten << std::endl;
    return bytesWritten;
}



int SerialPort::closeSerialPort()
{
    close(serialPort);
    return 0;
}

int SerialPort::readSerialPort()
{

    char buffer;
    int readBuffer = read(serialPort, &buffer, sizeof(buffer));
    if (readBuffer < 0)
    {
        BOOST_LOG_TRIVIAL(error) << "Error reading: " << strerror(errno);
    }
    else
    {
        BOOST_LOG_TRIVIAL(info) << "Read: " << buffer;
    }
    return buffer;
}

char SerialPort::getKeypadInput()//read the two first touches of the keypad
{
    char key = readSerialPort();
    //std::cout << "Key: " << key << std::endl;

    int counter = 0;
    while (counter <2){
        readSerialPort();
        counter++;
    }

    return key;

}

int  SerialPort::getSerialPort()
{
    return serialPort;

}

void SerialPort::available()
{
    connected = true;

}

