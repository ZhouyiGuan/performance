#include "thread.h"

#define PORT L"COM2"


int main(int argc, char* argv[])    
{

    HANDLE hThread1;
    DWORD dwThreadId1;
    HANDLE hDev = NULL;

    if (!PORT_open(hDev, PORT, NULL))
        return -1;

    if (!PORT_set(hDev))
        return -1;

    printf("init successful.\n");

    hThread1 = CreateThread(
        NULL,
        0,
        (LPTHREAD_START_ROUTINE)thread_write, 
        hDev,  
        0,
        &dwThreadId1);

    if (hThread1 == NULL) 
    {
        printf("Error:unable to create thread.\n");
        ExitProcess(1);
    }

    WaitForSingleObject(hThread1, INFINITE);
}    