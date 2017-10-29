#include<stdint.h>

class CSerial
{
public:
    CSerial();

    ~CSerial();

    bool Open(char * t_pszSerialDevice);

    bool Close();

    bool SetBaudRate(uint64_t t_baud);

    uint64_t GetBaudRate(){return m_uBaudRate;};

    int GetSerial(){return m_fdSerial;};

private:
    int m_fdSerial;
    uint64_t m_uBaudRate;
    char * m_pszSerialDevice;
};