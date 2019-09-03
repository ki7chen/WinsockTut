// Copyright (C) 2012-present prototyped.cn All rights reserved.
// Distributed under the terms and conditions of the Apache License. 
// See accompanying files LICENSE.

#pragma once

#include <stdint.h>
#include "TimerSched.h"
#include "OverlapFd.h"


enum IOServiceType
{
    IOOverlapped = 1,
    IOAlertable = 2,
    IOCompletionPort = 3,
};

// Async I/O service for TCP sockets
class IOServiceBase : public TimerSched
{
public:
    IOServiceBase();
    virtual ~IOServiceBase();

    virtual int AsyncConnect(SOCKET fd, const addrinfo* pinfo, ConnectCallback cb) = 0;
    virtual int AsyncAccept(SOCKET acceptor, AcceptCallback cb) = 0;
    virtual int AsyncRead(void* buf, int size, ReadCallback cb) = 0;
    virtual int AsyncWrite(const void* buf, int size, WriteCallback cb) = 0;
    virtual int CancelFd(SOCKET fd) = 0;
    virtual int Run(int timeout) = 0;
};

IOServiceBase* CreateIOService(IOServiceType type);