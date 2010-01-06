//Game_CLASS.h

#include "SDL.h"
#include "SDL_ttf.h"
#include "SDL_mixer.h"
#include "SDL_image.h"
//#include "SDL_rotozoom.h"

//-------------------------------------------------------------------------------------------------
#define PleaseVisitWebSiteScreen			0
#define PublishedByclnetScreen				1
#define SDLInformationScreen				2
#define SilentHeroProductionsScreen			3
#define TitleScreen							4
#define MusicSelectionScreen				5
#define PlayingTetri_GameScreen				6
#define GameOverScreen						7
#define OptionsScreen						8
#define HighScoresScreen					9
#define NewHighScoreNameInputScreen			10
#define StaffScreen							11
#define HowToPlayScreen						12
#define HistoryScreen						13

class Game
{
public:

	Game(void);
	virtual ~Game(void);

	SDL_Event Event;
	bool PAUSEgame;
	bool EXITgame;

	Uint8 GameScreen;
	Uint16 GameScreenTimer;
	bool GameScreenDisplayed;

	Uint32 SystemTicks;
	Uint32 NextFrameTicks;

	Uint8 CurrentlySelectedScreenOption;

	Sint32 StaffLineY[40];

	Sint16 SentenceLineY;
	Sint16 ParagraphPosition;
};
