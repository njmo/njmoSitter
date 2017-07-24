#include <iostream>
#include "nanny/Nanny.hpp"
#include <event/core/EventMain.hpp>
#include <utils/timeout_generator/TimeoutGenerator.hpp>
#include <chrono>
#include <cstdio>
#include <utils/Broadcaster.hpp>
#include <server/NannyServer.hpp>

int main(int argc, char *argv[])
{
	app::Nanny nanny;
	event::EventMain eventMain(nanny);
	TimeoutGenerator timeoutGenerator(500,nanny);
	NannyServer nannyServer(1234);
	nannyServer.init();
	nanny.create();


	eventMain.wakeUp();
	timeoutGenerator.wakeUp();
	nannyServer.run();

	std::getchar();

	timeoutGenerator.kill();
	eventMain.kill();
	nannyServer.stop();

	nannyLogInfo("nannyServer");
	nannyServer.detach();
	nannyLogInfo("eventMain");
	eventMain.join();
	nannyLogInfo("timeoutGenerator");
	timeoutGenerator.join();
}
