#include "variables.h"
#include <thread>
#include <chrono>

void worldGenerator();
void drawMap();
void controller();
void clearScreen();

int main()
{
	worldGenerator();

	while(gameIsOn)
	{
		drawMap();
		controller();
		std::this_thread::sleep_for(std::chrono::milliseconds(16));
	}

	clearScreen();
	//std

	return 0;
}