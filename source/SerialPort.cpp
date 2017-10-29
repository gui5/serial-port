#include "SerialPort.h"
#include <stdio.h>   /* Standard input/output definitions */
#include <string.h>  /* String function definitions */
#include <unistd.h>  /* UNIX standard function definitions */
#include <fcntl.h>   /* File control definitions */
#include <errno.h>   /* Error number definitions */
#include <termios.h> /* POSIX terminal control definitions */

CSerial::CSerial():
    m_fdSerial(-1),
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

bool CSerial::SetBaudRate(uint64_t t_uBaud)
{
    if(m_fdSerial != -1)
    {
        struct termios options;

        tcgetattr(m_fdSerial, &options);
        cfsetispeed(&options, t_uBaud);
        cfsetospeed(&options, t_uBaud);
        options.c_cflag |= (CLOCAL | CREAD);
        tcsetattr(m_fdSerial, TCSANOW, &options);

        return true;
    }
   
    return false;
}

bool CSerial::Close()
{
    if(m_fdSerial != -1)
    {
        close(m_fdSerial);
    }
    return false;
}

CSerial::~CSerial()
{
    if(m_fdSerial != -1)
    {
        close(m_fdSerial);
    }
    
}