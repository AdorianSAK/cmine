#include <iostream>
#include <random>

extern const int worldWidth;
extern const int worldHeigh;
extern int obstaclePercent;
extern int minePercent;
extern int gemsPercetn;
extern int screenWidth;
extern int screenHeigh;

extern int playerSpawnRatio;
extern int obstaclesInSpawn;

extern int world[][2001];
extern int worldLength;
extern int expectedObstacles;
extern int walkablePath;
extern int expectedMines;
extern int expectedGems;

int randomSelect(int floor, int ceiling);

extern int score;
extern int pickaxe;
extern int pickCharge;
extern bool activePickaxe;
extern char control;

extern int worldCenter;
extern int localX;
extern int localY;
extern int playerX;
extern int playerY;

extern std::string systemColor;

extern bool gameIsOn;

#define WHITE "\e[38;5;255m"
#define RESET "\033[0m"
#define GREEN "\e[38;5;46m"
#define BLUE "\e[38;5;21m"
#define DARKGREEN "\e[38;5;28m"
#define RED "\e[38;5;160m"
#define DARKYELLOW "\e[38;5;142m"
#define DARKRED "\e[38;5;124m"
#define DARKCYAN "\e[38;5;31m"
#define BLACK "\e[38;5;232m"
#define DARKGRAY "\e[38;5;240m"
#define YELLOW "\e[38;5;226m"