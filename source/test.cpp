#include <iostream>
#include "SerialPort.h"

/*
    Command line:
        argv[1] = serial device
        argv[2] = baud rate

        serial --port /dev/ttyUSB0 --baudrate 9600
*/

int main(int argc, char * argv[])
{

    CSerial ss;

    ss.Open(argv[1]);

    getchar();

    return 0;
}