#include <iostream>
#include "Nanny.hpp"
#include <chrono>
#include <cstdio>
#include <utils/Broadcaster.hpp>

int main(int argc, char *argv[])
{
	//app::Nanny nanny;
	//nanny.create();
	//std::getchar();
	InterfaceFinder finder;
	finder.init("wlan0");
	Broadcaster b(finder);
	b.broadcastNannyAddress();

}
