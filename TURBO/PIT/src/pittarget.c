#include "pittarget.h"
#include "pitcomm.h"

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
	unsigned int thrtl = pitComm_getMsgThrottle ();
	unsigned int tmout = pitComm_getRecvTimeout ();
	printf ("* Message throttling is ");
	if (!thrtl) {
		puts ("OFF (as fast as possible)");
	} else {
		printf ("set to %u seconds\n", thrtl);
	}
	printf ("* Receive timeout is set to %u seconds\n", tmout);
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
