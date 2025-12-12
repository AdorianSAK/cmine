#include "variables.h"
#include <iomanip>

void clearScreen();
void positionMarker();
int directionFourSensor(int x, int y);
std::string systemColorSelector();
int eightSensor(int x, int y, int criteria);
void screenDrawer();
void upperMargindrawer();

void drawMap()
{
	clearScreen();
	positionMarker();
	systemColor = systemColorSelector();
	std::cout << systemColor;
	upperMargindrawer();
	screenDrawer();
}

void positionMarker()
{
	std::string chargeBar = "";
	std::cout << RESET << "\n\t\tPosition: "
			  << std::setw(4) << playerX + 1 << ", "
			  << std::setw(4) << playerY + 1 << "\t"
			  << std::setw(3) << "Score: " << score;
	if(activePickaxe)
	{
		std::cout << GREEN;
	}else
	{
		std::cout << RESET;
	}
	std::cout << (activePickaxe? "\t\t►►►" : "\t\t   ")
			  << "⛏️  X " << std::setw(3) << pickaxe
			  << (activePickaxe? "◄◄◄\n" : "\n")
			  << RESET << "\tCBV: " << directionFourSensor(playerX, playerY)
			  << "\t\t\t\t\t\t\t[" << GREEN;
	for(int i = 0; i < pickCharge; i ++)
	{
		chargeBar += "█";
	}
	std::cout << std::setw(9) << std::left << chargeBar << RESET << "]\n\n"; 
}

void screenDrawer()
{
	for(int y = 0; y < screenHeigh; y ++)
	{
		std::cout << "\t\t\t||";
		for(int x = 0; x < screenWidth; x ++)
		{
			if(x == screenWidth / 2 && y == screenWidth / 2)
			{
				std::cout << GREEN << "☻ ";
			}else if(world[localX + x][localY + y] == 6 || world[localX + x][localY + y] == 8)
			{
				std::cout << systemColor << "? ";
			}else if(world[localX + x][localY + y] == 5 || world[localX + x][localY + y] == 7)
			{
				std::cout << "🚩 ";
			}else if(world[localX + x][localY + y] == 4)
			{
				std::cout << DARKGRAY << "▒▒";
			}else if(world[localX + x][localY + y] == 3)
			{
				std::cout << "💎";
			}else if(world[localX + x][localY + y] == 1)
			{
				std::cout << systemColor << "██";
			}else
			{
				std::cout << YELLOW << "▒▒";
			}
			std::cout << systemColor;
		}
		std::cout << "||\n";
	}
}

void upperMargindrawer()
{
	std::cout << "\t\t\t💀";
	for(int i = 0; i < screenWidth; i ++)
	{
		std::cout << "==";
	}
	std::cout << "💀\n";
}

int totalDetected()
{
	return eightSensor(playerX, playerY, 2) + eightSensor(playerX, playerY, 7) +
		eightSensor(playerX, playerY, 8);
}

std::string systemColorSelector()
{
	switch(totalDetected())
	{
	case 1:
		return BLUE; break;
	case 2:
		return DARKGREEN; break;
	case 3:
		return RED; break;
	case 4:
		return DARKYELLOW; break;
	case 5:
		return DARKRED; break;
	case 6:
		return DARKCYAN; break;
	case 7:
		return BLACK; break;
	case 8:
		return DARKGRAY; break;
	default:
		return  WHITE; break;
	}
}

void clearScreen()
{
	std::cout << "\033[2J\033[1;1H";
}