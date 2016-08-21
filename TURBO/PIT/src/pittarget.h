#ifndef PITTARGET_H
#define PITTARGET_H

#include <stdio.h>
#include <string.h>

struct PITTargetInfo {
	char ip[8]; // 0x00
	// unknown
	unsigned int PITTargetInfo_14h;
	unsigned short tport; // target port // 0x18
	unsigned short sport; // source port // 0x1a
	unsigned int node; // 0x1c
} targetInfo; // base 0x8051620

void pitTarget_init();
#endif
