#include "variables.h"

void clearScreen();
void applyValues();
int eightSensor(int x, int y, int criteria);
void worldGenerator();
char readKey();

void treasureCollect()
{
	world[playerX][playerY] = 0;
	score ++;
	pickCharge ++;
	if(pickCharge == 10)
	{
		pickaxe ++;
		pickCharge = 0;
	}

	if(eightSensor(playerX, playerY, 1) >= 3)
	{
		world[playerX][playerY] = 4;
	}
}

void stepOnMine()
{
	clearScreen();
	std::cout << "\n\n\t\tGame Over\n";
	for(int y = 0; y < worldHeigh; y ++)
	{
		for(int x = 0; x < worldWidth; x ++)
		{
			score += world[x][y] == 7? 1 : 0;
			score -= world[x][y] == 5? 1 : 0;
		}
	}
	std::cout << "\n\n\t\tYour Score is: " << score << '\n';

	//	More shit here, about scoring

	applyValues();
	worldGenerator();
	std::cout << "\n\t\tPress any key to restart.\n";
	readKey();
}