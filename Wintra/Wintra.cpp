// Wintra.cpp : Defines the entry point for the application.
//

#include "Wintra.h"

#include "Logtra.h"

using namespace std;

int main()
{
	Logtra::Logger logger;

	LGA_USE_LOGGER(logger);

	LGA_SUCCESS("LGA Successfully started");

	return 0;
}
