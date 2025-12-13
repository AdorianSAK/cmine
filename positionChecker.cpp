#include "variables.h"

void clearScreen();

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

	//	More shit here
}