#include <iostream>
#include "nanny/Nanny.hpp"
#include <event/core/EventMain.hpp>
#include <utils/timeout_generator/TimeoutGenerator.hpp>
#include <chrono>
#include <cstdio>
#include <utils/Broadcaster.hpp>

int main(int argc, char *argv[])
{
	app::Nanny nanny;
	event::EventMain eventMain(nanny);
	TimeoutGenerator timeoutGenerator(1000,nanny);

	eventMain.wakeUp();
	nanny.create();
	timeoutGenerator.wakeUp();

	std::getchar();

	timeoutGenerator.kill();
	eventMain.kill();
	eventMain.join();
	timeoutGenerator.join();
}
