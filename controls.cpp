#include "variables.h"

int directionFourSensor(int x, int y)
{
	int direction = 0;
	direction = world[x + 0][y - 1] == 1? direction | 1 : direction;
	direction = world[x + 1][y - 0] == 1? direction | 2 : direction;
	direction = world[x + 0][y + 1] == 1? direction | 4 : direction;
	direction = world[x - 1][y - 0] == 1? direction | 1 : direction;
	return direction;
}