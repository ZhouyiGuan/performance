#include"serialPort.h"

bool PORT_open(_In_ HANDLE& hDev, _In_ LPCTSTR port, _In_ DWORD flag) 
{
    if (flag == NULL) {
        hDev = CreateFile(port,
            GENERIC_READ | GENERIC_WRITE,
            NULL,
            NULL,
            OPEN_EXISTING,
            NULL,
            NULL);
    }
    else if (flag == FILE_FLAG_OVERLAPPED) {
        hDev = CreateFile(port,
            GENERIC_READ | GENERIC_WRITE,
            NULL,
            NULL,
            OPEN_EXISTING,
            FILE_FLAG_OVERLAPPED,
            NULL);
    }

    if (hDev == INVALID_HANDLE_VALUE || hDev == NULL) {
        printf("Error: opening port:%p.\n", port);
        return FAIL;
    }
    else {
        return SUCCESS;
    }   
}

bool PORT_close(_In_ HANDLE& hDev)
{
    CloseHandle(hDev);
    return SUCCESS;
}

bool PORT_set(_In_ HANDLE& hDev) 
{
    SetupComm(hDev, COMM_BUFFER_SIZE, COMM_BUFFER_SIZE);

    DCB dcbSerialParams = { 0 };
    if (!GetCommState(hDev, &dcbSerialParams)) {
        printf("Error: getting current state of the device.\n");
        return FAIL;
    }
    dcbSerialParams.BaudRate = BAUDRATE;
    if (!SetCommState(hDev, &dcbSerialParams)) {
        printf("Error: setting serial port state.\n");
        return FAIL;
    }

    //COMMTIMEOUTS timeouts = { 0 };
    //timeouts.ReadIntervalTimeout = MAXDWORD;
    //timeouts.ReadTotalTimeoutConstant = 0;
    //timeouts.ReadTotalTimeoutMultiplier = 0;
    //SetCommTimeouts(hDev, &timeouts);

    return  SUCCESS;
}

