#include <iostream>
#include "SerialPort.h"
#include <termios.h> /* POSIX terminal control definitions */

/*
    Command line:
        argv[1] = serial device

        serial  /dev/ttyUSB0

        **default baud rate: 9600;
*/

int main(int argc, char * argv[])
{

    CSerial ss;

    ss.Open(argv[1]);
    ss.SetBaudRate(B9600);
    
    getchar();

    return 0;
}