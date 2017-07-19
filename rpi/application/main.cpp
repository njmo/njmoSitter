#include <iostream>
#include "Nanny.hpp"
#include <chrono>
#include <cstdio>

int main(int argc, char *argv[])
{
	app::Nanny nanny;
	nanny.create();
	std::getchar();
}
