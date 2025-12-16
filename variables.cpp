#include "variables.h"

//	This are the modifiable Variables

//	!! CAUTION !!
//	Do not set the screen size values less than 5
//		Default is 21

//	Default is 2001 !Keep Heigh and Width the same to aviud bugs! Also remember to use odd numbers.
const int worldWidth = 2001;
//	Default is 2001 !Keep Heigh and Width the same to aviud bugs! Also remember to use odd numbers.
const int worldHeigh = 2001;
int obstaclePercent = 33;	//	Default 33
int minePercent = 4;	//	Default 4
int gemsPercent = 1;	//	Default 1
int screenWidth = 21;	//	Default 21 - Only odd numbers.
int screenHeigh = 21;	//	Default 21 - Only off numbers.

int playerSpawnRatio = 4;	//	Default 4
int obstaclesInSpawn = 2;	// 1 = 10%. Default 2

//	Composite Variables.
int world[worldHeigh][worldWidth];
int worldLength = worldWidth * worldHeigh;
int expectedObstacles = (worldLength * obstaclePercent) / 100;
int walkablePath = worldLength - expectedObstacles;
int expectedMines = minePercent * walkablePath / 100;
int expectedGems = worldLength * gemsPercent / 100;

//	Initial Player Values.
int score;
int pickaxe;
int pickCharge;
bool activePickaxe;
char control;

//	Screen Variables.
int worldCenter = worldWidth / 2;
int localX = worldCenter - (screenWidth / 2);
int localY = worldCenter - (screenHeigh / 2);
int playerX = localX + (screenWidth / 2);
int playerY = localY + (screenHeigh / 2);

//	Control of the colors in screen.
std::string systemColor;

//	Classic "game on" boolean.
bool gameIsOn = true;

//	Required random function.
int randomSelect(int floor, int ceiling)
{
	std::random_device roll;
	std::uniform_int_distribution<int> dice(floor, ceiling);

	return dice(roll);
}
