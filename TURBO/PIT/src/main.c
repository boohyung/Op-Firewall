#include "pittarget.h"
#include "pitcmd.h"
#include "general.h"
int main(int argc, char *argv[]) {
	if (argc > 2) {
		puts ("USAGE: pit <script-file>");
		return 0;
	}
	puts ("\n");
	puts ("---------------------------------------------------------");
	printf ("PIT (version %u.%u.%u.%u)\n", 1, 2, 1, 1);
	puts ("---------------------------------------------------------");
	puts ("* Enter \"help\" for command listing");
	puts ("* Use arrow keys to scroll through command history");
	putchar('\n');
	pitTarget_init ();
	pitCmd_init ();		// sym.pitCmd_init
	if (argc == 2) {
		// je 0x8048d91
	}
	//pitCmd_processCmdLine (); // sym.pitCmd_processCmdLine
	//continue at 0x08048d7d
}
