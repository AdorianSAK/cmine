//	Just a minor reminder, these are the values that the cells can have an it's meaning;

//	0 = ▒▒ Sand: Risky cells which may contain mines, if the cells's value is 0, then it's safe.
//	1 = ██ Obstacle: A solid unpassable wall, it is drawed as a solid square.
//	2 = Mine: Any cell with this value means it has a mine, it should look exactly as a sand cell.
//	3 = 💎 Diamond: Represented by an emoji, when taken they add +1 to score.
//	4 = Rock Floor: Similar to translucent gray tone, it's a safe cell with no mines at all.
//	5 & 7 = 🚩 Flag: Represented by an emoji, 5 means a flagged cell with no mines and 7 has a mine.
//	6 & 8 = ? Inquiry: The question mark, 6 means no mines, and 8 has a mine.
#include <iostream>
#include "tools.h"

void porcentualGenerator(int expected, int otherCheck, int brush);
int eightSensor(int x, int y, int criteria);

void worldGenerator()
{
	//	First convert all values in the grid to 0s.
	for(int y = 0; y < worldHeigh; y ++)
	{
		for(int x = 0; x < worldWidth; x ++)
		{
			world[x][y] = 0;
		}
	}

	//	== == == == == Obstacle Generation == == == == ==
	porcentualGenerator(expectedObstacles, 2, 1);
	std::cout << "Obstacles generated.\n";

	//	== == == == == Rock Floor Generator == == == == ==
	for(int y = 1; y < worldHeigh - 1; y ++)
	{
		for(int x = 1; x < worldWidth - 1; x ++)
		{
			if(world[x][y] == 1)
			{
				continue;
			}
			if(eightSensor(x, y, 1) >= 3)
			{
				world[x][y] = 4;
			}
		}
	}
	std::cout << "Rock Floor Generted.\n";
}

void porcentualGenerator(int expected, int otherCheck, int brush)
{
	int x, y;
	for(int i = 0; i < expected; i ++)
	{
		do
		{
			x = randomSelect(0, worldWidth - 1);
			y = randomSelect(0, worldHeigh - 1);
			if(world[x][y] != 1 && world[x][y] != otherCheck)
			{
				world[x][y] = brush;
				break;
			}
		}while(true);
		//std::cout << "One cell correctly painted." << i << '\n';
	}
}

int eightSensor(int x, int y, int criteria)
{
	int count = 0;
	count += world[x - 1][y - 1] == criteria? 1 : 0;
	count += world[x - 0][y - 1] == criteria? 1 : 0;
	count += world[x + 1][y - 1] == criteria? 1 : 0;
	count += world[x - 1][y - 0] == criteria? 1 : 0;
	count += world[x + 1][y - 0] == criteria? 1 : 0;
	count += world[x - 1][y + 1] == criteria? 1 : 0;
	count += world[x - 0][y + 1] == criteria? 1 : 0;
	count += world[x + 1][y + 1] == criteria? 1 : 0;
	return count;
}