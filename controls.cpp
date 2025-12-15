#include "variables.h"
#include <termios.h>
#include <unistd.h>
#include <charconv>

char readKey();
void playerMove(char playerInput);
void bannerPlacer(int playerInput);
void pauseScreen();
void treasureCollect();
void stepOnMine();
void minedObstacle();

void controller()
{
	control = readKey();
	playerMove(control);
}

void pauseControl()
{
	control = readKey();
	switch(control)
	{
	case '\n':
		return;
	case 'q':
		gameIsOn = false; return;
	default:
		pauseScreen(); break;
	}
}

int directionFourSensor(int x, int y)
{
	int direction = 0;
	direction = world[x + 0][y - 1] == 1? direction | 1 : direction;
	direction = world[x + 1][y - 0] == 1? direction | 2 : direction;
	direction = world[x + 0][y + 1] == 1? direction | 4 : direction;
	direction = world[x - 1][y - 0] == 1? direction | 8 : direction;
	return direction;
}

void playerMove(char playerInput)
{
	int x = 0;
	int y = 0;
	int posssibleInput = 0;

    if(playerInput >= '0' && playerInput <= '9')
    {
        int posibleInput = playerInput - '0';
        bannerPlacer(posibleInput);
        return;
    }

    switch(playerInput)
    {
    case 'w':
    	if((directionFourSensor(playerX, playerY) & 1) == 0 || activePickaxe)
    		y = -1; break;
    case 'd':
    	if((directionFourSensor(playerX, playerY) & 2) == 0 || activePickaxe)
    		x = 1; break;
    case 's':
    	if((directionFourSensor(playerX, playerY) & 4) == 0 || activePickaxe)
    		y = 1; break;
    case 'a':
    	if((directionFourSensor(playerX, playerY) & 8) == 0 || activePickaxe)
    		x = -1; break;
    case ' ':
    	if(pickaxe > 0)
    	{
    		activePickaxe =! activePickaxe;;
    	} return;
    case 'p':
    	pauseScreen();
    	return;
    }

    localX += x;
    localY += y;
    playerX += x;
    playerY += y;

    if(world[playerX][playerY] == 3)
    {
    	treasureCollect();
    }else if(world[playerX][playerY] == 2 || world[playerX][playerY] == 7 || world[playerX][playerY] == 8)
    {
    	stepOnMine();
    }else if(world[playerX][playerY] == 1)
    {
    	minedObstacle();
    }
}

void bannerPlacer(int playerInput)
{
	int x = 0;
	int y = 0;
	switch(playerInput)
	{
	case 1:
		x = -1; y = 1; break;
	case 2:
		x = 0; y = 1; break;
	case 3:
		x = 1; y = 1; break;
	case 4:
		x = -1; y = 0; break;
	case 6:
		x = 1; y = 0; break;
	case 7:
		x = -1; y = -1; break;
	case 8:
		x = 0; y = -1; break;
	case 9:
		x = 1; y = -1; break;
	default:
		return;
	}

	int markerX = playerX + x;
	int markerY = playerY + y;

	if(world[markerX][markerY] == 0 || world[markerX][markerY] == 2)
	{
		world[markerX][markerY] = world[markerX][markerY] == 0? 5 : 7;
	}else if(world[markerX][markerY] == 5 || world[markerX][markerY] == 7)
	{
		world[markerX][markerY] = world[markerX][markerY] == 5? 6 : 8;
	}else if(world[markerX][markerY] == 6 || world[markerX][markerY] == 8)
	{
		world[markerX][markerY] = world[markerX][markerY] == 6? 0 : 2;
	}
}

char readKey()
{
    termios old_tio, new_tio;

    //	Gets actual terminal configuration
    tcgetattr(STDIN_FILENO, &old_tio);
    new_tio = old_tio;

    //	Non canon nor echo mode
    new_tio.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &new_tio);

    char c = getchar(); //	Inmediatly reads a single character

    // Restores terminal configuration
    tcsetattr(STDIN_FILENO, TCSANOW, &old_tio);

    return c;
}