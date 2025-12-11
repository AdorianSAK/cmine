#include <iostream>
#include <random>

const int worldWidth = 2001;
const int worldHeigh = 2001;
int obstaclePercent = 33;

int world[worldHeigh][worldWidth];
int worldLength = worldWidth * worldHeigh;
int expectedObstacles = (worldLength * obstaclePercent) / 100;

int randomSelect(int floor, int ceiling)
{
	std::random_device roll;
	std::uniform_int_distribution<int> dice(floor, ceiling);

	return dice(roll);
}