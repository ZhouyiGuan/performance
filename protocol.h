#pragma once
#ifndef _PROTOCOL_H
#define _PROTOCOL_H
   

#include <winsock2.h>
#include <windows.h>
#include <winbase.h>
#include <iostream>
#include <process.h>     
#include <chrono>

#define SEND_SPEED_BYTE_S 1 * 1024 * 1024
#define COMM_BUFFER_SIZE 10 * 1024  
#define BAUDRATE  115200

#define SUCCESS 1
#define FAIL 0


#endif
