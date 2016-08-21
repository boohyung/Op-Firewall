#ifndef PITCOMM_H
#define PITCOMM_H

extern unsigned int msgThrottleSec;
extern unsigned int recvTimeout;


unsigned int pitComm_getMsgThrottle();
unsigned int pitComm_getRecvTimeout();

#endif
