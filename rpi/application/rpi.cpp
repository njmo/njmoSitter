#include <iostream>
#include "server/phoneThread.h"

int main(int argc, char *argv[])
{
	phoneThread th;

	for(int i=0;i<200000;i++)
		;


	th.join();
	return 1;
}
