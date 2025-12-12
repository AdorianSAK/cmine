#include <iostream>
#include <random>

const int worldWidth = 2001;
const int worldHeigh = 2001;
int obstaclePercent = 33;
int minePercent = 4;
int gemsPercent = 1;

int playerSpawnRatio = 4;
int obstaclesInSpawn = 2;

int world[worldHeigh][worldWidth];
int worldLength = worldWidth * worldHeigh;
int expectedObstacles = (worldLength * obstaclePercent) / 100;
int walkablePath = worldLength - expectedObstacles;
int expectedMines = minePercent * walkablePath / 100;
int expectedGems = worldLength * gemsPercent / 100;

int worldCenter = worldWidth / 2;

bool gameIsOn = true;

int randomSelect(int floor, int ceiling)
{
	std::random_device roll;
	std::uniform_int_distribution<int> dice(floor, ceiling);

	return dice(roll);
}
