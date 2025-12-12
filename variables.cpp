#include "variables.h"

const int worldWidth = 2001;
const int worldHeigh = 2001;
int obstaclePercent = 33;
int minePercent = 4;
int gemsPercent = 1;
int screenWidth = 21;
int screenHeigh = 21;

int playerSpawnRatio = 4;
int obstaclesInSpawn = 2;

int world[worldHeigh][worldWidth];
int worldLength = worldWidth * worldHeigh;
int expectedObstacles = (worldLength * obstaclePercent) / 100;
int walkablePath = worldLength - expectedObstacles;
int expectedMines = minePercent * walkablePath / 100;
int expectedGems = worldLength * gemsPercent / 100;

int score;
int pickaxe;
int pickCharge;
bool activePickaxe;
char control;

int worldCenter = worldWidth / 2;
int localX = worldCenter - (screenWidth / 2);
int localY = worldCenter - (screenHeigh / 2);
int playerX = localX + (screenWidth / 2);
int playerY = localY + (screenHeigh / 2);

std::string systemColor;

bool gameIsOn = true;

int randomSelect(int floor, int ceiling)
{
	std::random_device roll;
	std::uniform_int_distribution<int> dice(floor, ceiling);

	return dice(roll);
}
