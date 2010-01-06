// Game_CLASS.cpp

#include "SDL.h"
#include "SDL_ttf.h"
#include "SDL_mixer.h"
#include "SDL_image.h"
//#include "SDL_rotozoom.h"

#include "Game.h"


Game::Game(void)
{
	EXITgame = false;
	PAUSEgame = false;
	GameScreen = PleaseVisitWebSiteScreen;
	GameScreenDisplayed = false;
	CurrentlySelectedScreenOption = 0;
}

//-------------------------------------------------------------------------------------------------
Game::~Game(void)
{

}
