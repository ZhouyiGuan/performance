#pragma once
#include "serialPort.h" 

DWORD
WINAPI
thread_write(HANDLE hDev) 
{
    printf("***********\n");

    uint8_t* buffer = new uint8_t[SEND_SPEED_BYTE_S];//1MB
    size_t i = 0;
    DWORD dwBytesWritten = 0;
    auto start = std::chrono::steady_clock::now();

    for (size_t i = 0; i < SEND_SPEED_BYTE_S; ++i) {
        buffer[i] = 'a' + i % 26;
    }
    
    while (1) 
    {   
        if (!WriteFile(hDev, buffer, SEND_SPEED_BYTE_S, &dwBytesWritten, NULL))
        {
            printf("Error: WriteFile failed with error %lu\n", GetLastError());
            break;
        }


        if (dwBytesWritten != SEND_SPEED_BYTE_S)
        {
            printf("Warning: Not all bytes were written to the device. Expected %lu, written %lu\n", SEND_SPEED_BYTE_S, dwBytesWritten);
        }

        i += dwBytesWritten;

        auto now = std::chrono::steady_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(now - start).count();
        printf("total: %lld MB, time: %lld ms \n", i/(1024*1024) , duration);

    }    


    delete[] buffer;
    return 0;
}

