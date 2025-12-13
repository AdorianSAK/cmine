#include "variables.h"

void worldGenerator();
void drawMap();
void controller();

int main()
{
	worldGenerator();

	while(gameIsOn)
	{
		drawMap();
		controller();
	}

	return 0;
}