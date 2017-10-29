#include "SerialPort.h"
#include <stdio.h>   /* Standard input/output definitions */
#include <string.h>  /* String function definitions */
#include <unistd.h>  /* UNIX standard function definitions */
#include <fcntl.h>   /* File control definitions */
#include <errno.h>   /* Error number definitions */
#include <termios.h> /* POSIX terminal control definitions */

CSerial::CSerial():
    m_fdSerial(0),
    m_uBaudRate(0),
    m_pszSerialDevice(nullptr)
{

}

bool CSerial::Open(char * t_pszSerialDevice)
{
    m_pszSerialDevice = t_pszSerialDevice;
    m_fdSerial = open(m_pszSerialDevice, O_RDWR | O_NOCTTY | O_NDELAY);

    if (m_fdSerial == -1)
    {
        printf("Can't open %s",m_pszSerialDevice);
        perror("ERROR");

        return false;
    }

    return true;
}

CSerial::~CSerial()
{

}