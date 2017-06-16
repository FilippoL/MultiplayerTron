
#include "Game.h"

#define WIDTH 1600
#define HEIGHT 900




int main(int argc, char* argv[])
{
	
	TheGame::Instance()->Initialise("fff", WIDTH, HEIGHT);

	TheGame::Instance()->Run();

	TheGame::Instance()->ShutDown();

	return 0;
}





		
