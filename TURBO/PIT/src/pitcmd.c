#include "general.h"
#include "pitcmd.h"
#include "pbdcmd.h"
#include "datapriv.h"

void collectCmd_init() {
	dataPriv_expandCryptoVar (cryptoVar, keySchedule);
	int i;
	for (i=0; i< 7; i++) {
		cryptoCounter[i] = (uint8_t) rand ();
	}
	pktSequenceNum = rand ();
}

void pitCmd_init() {
	pbdCmd_init ();
	collectCmd_init ();
}
