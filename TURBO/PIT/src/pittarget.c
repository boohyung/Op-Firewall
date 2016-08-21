#include "pittarget.h"
static void pitTarget_displayInfo() {
	puts ("---------------------------------------------------------");
	puts ("TARGET INFORMATION");
	puts ("---------------------------------------------------------");
	printf ("Target node number = 0x%.8x\n", targetInfo.node);
	printf ("Target IP address  = %s\n", targetInfo.ip);
	printf ("Target port number = %u", targetInfo.tport);
	if (targetInfo.tport == 0) {
		printf("(RANDOM)");
	}
	putchar ('\n');
	printf ("Source port number = %u", targetInfo.sport);
	if (targetInfo.tport == 0) {
		printf("(RANDOM)");
	}
	puts ("\n");
	//TODO
	// printing Message throttle
	// printing recv timeout
}
void pitTarget_init() {
	strncpy (targetInfo.ip, "0.0.0.0", 8);
	targetInfo.PITTargetInfo_14h = 0;
	targetInfo.tport = 0;
	targetInfo.sport = 0;
	targetInfo.node = 0;
	pitTarget_displayInfo ();
	return;
}
