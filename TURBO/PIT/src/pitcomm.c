#include "pitcomm.h"

unsigned int msgThrottleSec = 0;
unsigned int recvTimeout = 3;

unsigned int pitComm_getMsgThrottle() {
	return msgThrottleSec;
}

unsigned int pitComm_getRecvTimeout() {
	return recvTimeout;
}
