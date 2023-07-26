#pragma once
#ifndef  _SERIALPORT_H
#define  _SERIALPORT_H
 
  
#include "protocol.h"  
     
bool PORT_open(_In_ HANDLE& hDev, _In_ LPCTSTR port, _In_ DWORD flag);
bool PORT_close(_In_ HANDLE& hDev) ;
bool PORT_set(_In_ HANDLE& hDev);


 
#endif