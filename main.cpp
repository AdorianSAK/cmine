#include <iostream>

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