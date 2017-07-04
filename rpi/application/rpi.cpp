#include <iostream>
#include <utils/Logger/Logger.hpp>
#include <event/core/EventMain.hpp>
#include <event/queue/EventQueue.hpp>
#include <testClass.h>

int main(int argc, char *argv[])
{
	testClass testclass;
	event::EventMain evMain;
	event::EventQueue::getInstance().push(0);
	nannyLogInfo("ala ma kota");
	nannyLogError("ala ma kota");
	nannyLogWarning("ala ma kota");
}
