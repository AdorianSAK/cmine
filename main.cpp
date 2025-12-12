#include "variables.h"

void worldGenerator();
void drawMap();

int main()
{
	worldGenerator();

	while(gameIsOn)
	{
		drawMap();
	}

	return 0;
}