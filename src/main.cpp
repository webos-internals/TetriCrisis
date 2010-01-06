/*
 _______________________________________________________________________________________________________
|                                                                                                       |
|                          TM           |                              __      _                        |
|    S.D.L.(R)PerfecT+EnginE VeR5.0     |      __      ____    ____   /  \   / /                        |
|                                       |     /  |    /  _ \  /  _ \  |()|  / /                         |
|                TM                     |    /_  |    | | | | | | | | \__/ / /      (Jesse Lee Palser)  |
| TetriCrisis 100% Version 5.9 Remix... |      | |    | | | | | | | |     / /                           /
| ------------------------------------- | A    | |    | | | | | | | |    / /     By  JeZ+Lee!!!        <
|  -=(Cross-Platform for Computers)=-   |      | |    | | | | | | | |   / / __                          \
|                                       |    __| |__  | |_| | | |_| |  / / /  \     (SLNTHERO@aol.com)  |
| (C)2009 by Silent Hero Productions(R) |   |_______| \____/  \____/  / /  |()|                         |
|                                       |                            /_/   \__/                         |
|     www.SilentHeroProductions.com     |                                                               |
|_______________________________________________________________________________________________________|
*/

//-------------------------------------------------------------------------------------------------
#include <iostream>
using namespace std;
#include <fstream>

#include "SDL.h"
#include "SDL_ttf.h"
#include "SDL_mixer.h"
#include "SDL_image.h"
//#include "SDL_rotozoom.h"

#include "Visuals.h"
#include "Game.h"
#include "Control.h"
#include "Audio.h"
#include "Tetri.h"
#include "Buttons.h"
#include "Settings.h"

//-------------------------------------------------------------------------------------------------
Visuals *visuals;
Game *game;
Control *control;
Audio *audio;
Tetri_EnginE *tetri_EnginE;
Buttons *buttons;
Settings *settings;

//-------------------------------------------------------------------------------------------------
void DisplayPlayingGameScreen(void);

//-------------------------------------------------------------------------------------------------
void DisplayPleaseVisitWebSiteScreen(void)
{
    if (game->EXITgame == true) return;

	if (game->GameScreenDisplayed == false)
	{
		visuals->EraseScreenBufferWithColor(60, 60, 60);

		visuals->DrawTextOnScreenBuffer(1,"Thank you for playing:", 160, 160, 160, 0, 0, 5, TextCenterX);
		visuals->DrawTextOnScreenBuffer(1,"TM", 255, 255, 0, 0, 307, 43, TextLeftX);
		visuals->DrawTextOnScreenBuffer(1,"TetriCrisis 100%", 255, 255, 0, 0, 46, 55, TextLeftX);
		visuals->DrawTextOnScreenBuffer(1,"Ver. 5.9 Remix", 255, 255, 0, 0, 360, 55, TextLeftX);
		visuals->DrawTextOnScreenBuffer(1,"_______________________________", 255, 255, 255, 0, 0, 62, TextCenterX);

		visuals->DrawTextOnScreenBuffer(0,"Hi, my name is Jesse (AKA: JeZ+Lee)...", 255, 255, 255, 0, 0, 100, TextCenterX);
		visuals->DrawTextOnScreenBuffer(0,"I am a disabled person with Autism.", 255, 255, 255, 0, 0, 140, TextCenterX);

		visuals->DrawTextOnScreenBuffer(0,"This game is 100% FREE.", 255, 255, 255, 0, 0, 196, TextCenterX);
		visuals->DrawTextOnScreenBuffer(0,"All i ask for in return...", 255, 255, 255, 0, 0, 230, TextCenterX);

		visuals->DrawTextOnScreenBuffer(0,"(1) Visit:", 0, 255, 0, 0, 0, 295, TextCenterX);
		visuals->DrawTextOnScreenBuffer(1,"www.SilentHeroProductions.com", 255, 255, 0, 0, 0, 330, TextCenterX);
		visuals->DrawTextOnScreenBuffer(0,"web site for other great FREE games!", 0, 255, 0, 0, 0, 360, TextCenterX);

		visuals->DrawTextOnScreenBuffer(0,"(2) E-mail:", 0, 255, 0, 0, 0, 425, TextCenterX);
		visuals->DrawTextOnScreenBuffer(1,"www.SilentHeroProductions.com", 255, 255, 0, 0, 0, 460, TextCenterX);
		visuals->DrawTextOnScreenBuffer(0,"web site address to friends & family.", 0, 255, 0, 0, 0, 490, TextCenterX);

		visuals->DrawTextOnScreenBuffer(0,"Thanks and enjoy...", 255, 255, 255, 0, 0, 538, TextCenterX);

		visuals->DrawTextOnScreenBuffer(1,"_______________________________", 255, 255, 255, 0, 0, 550, TextCenterX);
		visuals->DrawTextOnScreenBuffer(1,"Hit [SPACEBAR] to continue...", 160, 160, 160, 0, 0, 590, TextCenterX);

		visuals->FadeInScreenBuffer();
		game->GameScreenDisplayed = true;
	}

	if ( (control->KeyOnKeyboardPressedByUser == ' ')||(control->JoystickButton1[Any] == ON)||(control->JoystickButton2[Any] == ON) )
	{
		game->GameScreenDisplayed = false;
		visuals->FadeOutScreenBuffer();
		game->GameScreen = PublishedByclnetScreen;
		control->DelayUserInput = 7;
		game->GameScreenTimer = 175;
	}
}

//-------------------------------------------------------------------------------------------------
void DisplayPublishedByclnetScreen(void)
{
    if (game->EXITgame == true) return;

	if (game->GameScreenDisplayed == false)
	{
		audio->PlayMusic(0,1);

		visuals->EraseScreenBufferWithColor(0, 0, 0);
		visuals->DrawTextOnScreenBuffer(1,"Published by c|net(R)", 255, 255, 255, 0, 0, 285, TextCenterX);
		visuals->DrawTextOnScreenBuffer(1,"www.Download.com", 200, 200, 200, 0, 0, 345, TextCenterX);
		visuals->FadeInScreenBuffer();
		game->GameScreenDisplayed = true;
	}

	game->GameScreenTimer--;

	if ( (game->GameScreenTimer == 0)||(control->KeyOnKeyboardPressedByUser == ' ')||(control->JoystickButton1[Any] == ON)||(control->JoystickButton2[Any] == ON) )
	{
		game->GameScreenDisplayed = false;
		visuals->FadeOutScreenBuffer();
		game->GameScreen = SDLInformationScreen;
		control->DelayUserInput = 7;
		game->GameScreenTimer = 215;
	}
}

//-------------------------------------------------------------------------------------------------
void DisplaySDLInformationScreen(void)
{
    if (game->EXITgame == true) return;

	if (game->GameScreenDisplayed == false)
	{
		visuals->EraseScreenBufferWithColor(173, 214, 255);
		visuals->DisplaySpriteOnScreenBufferGlass(1, 150, 200, 255);
		visuals->DrawTextOnScreenBuffer(1,"www.LibSDL.org", 255, 255, 255, 0, 0, 500, TextCenterX);
		visuals->FadeInScreenBuffer();
		game->GameScreenDisplayed = true;
	}

	game->GameScreenTimer--;

	if ( (game->GameScreenTimer == 0)||(control->KeyOnKeyboardPressedByUser == ' ')||(control->JoystickButton1[Any] == ON)||(control->JoystickButton2[Any] == ON) )
	{
		game->GameScreenDisplayed = false;
		visuals->FadeOutScreenBuffer();
		game->GameScreen = SilentHeroProductionsScreen;
		control->DelayUserInput = 7;
		game->GameScreenTimer = 200;
	}
}

//-------------------------------------------------------------------------------------------------
void DisplaySilentHeroProductionsScreen(void)
{
    if (game->EXITgame == true) return;

	if (game->GameScreenDisplayed == false)
	{
		audio->PlayMusic(1,Loop);
		visuals->EraseScreenBufferWithColor(0, 0, 0);
		visuals->DisplaySpriteOnScreenBufferGlass(2, 0, 200, 255);
		visuals->DisplaySpriteOnScreenBufferGlass(3, 18, 466, 255);
		visuals->DrawTextOnScreenBuffer(1,"www.SilentHeroProductions.com", 255, 255, 0, 0, 0, 560, TextCenterX);
		visuals->FadeInScreenBuffer();
		game->GameScreenDisplayed = true;
	}

	game->GameScreenTimer--;
	if ( (game->GameScreenTimer == 0)||(control->KeyOnKeyboardPressedByUser == ' ')||(control->JoystickButton1[Any] == ON)||(control->JoystickButton2[Any] == ON) )
	{
		game->GameScreenDisplayed = false;
		visuals->FadeOutScreenBuffer();
		game->GameScreen = TitleScreen;
		control->DelayUserInput = 7;
		game->GameScreenTimer = 150;
	}
}

//-------------------------------------------------------------------------------------------------
void DisplayTitleScreen(void)
{
    if (game->EXITgame == true) return;

	if (game->GameScreenDisplayed == false)
	{
		if (tetri_EnginE->DisplayBackground == 0)  visuals->DisplaySpriteOnScreenBufferGlass(4, 0, 0, 255);
		else  visuals->EraseScreenBufferWithColor(0, 0, 0);

		visuals->DisplaySpriteOnScreenBufferGlass(5, 2, 20, 255);
		visuals->DisplaySpriteOnScreenBufferGlass(6, 253, 2, 255);
		visuals->DrawTextOnScreenBuffer(1,"TM", 255, 255, 255, 0, 4, 8, TextRightX);
		visuals->DisplaySpriteOnScreenBufferGlass(7, 464, 128, 255);
		visuals->DrawTextOnScreenBuffer(1,"5.9 Remix", 255, 255, 0, 0, 4, 184, TextRightX);

		visuals->DrawTextOnScreenBuffer(1, &tetri_EnginE->HighScoresName[tetri_EnginE->GameMode][0][0], 255, 255, 255, 0, 0, 130, TextCenterX);
		sprintf(visuals->VariableText, "%d", tetri_EnginE->HishScoresScore[tetri_EnginE->GameMode][0]);
		visuals->DrawTextOnScreenBuffer(1,visuals->VariableText, 255, 255, 255, 0, 0, 180, TextCenterX);

		buttons->SetUpNewButtonForUserInput(0, 0, 0, 230, 200, ButtonCenterX);
		buttons->SetUpNewButtonForUserInput(1, 1, 0, 280, 200, ButtonCenterX);
		buttons->SetUpNewButtonForUserInput(2, 2, 0, 330, 200, ButtonCenterX);
		buttons->SetUpNewButtonForUserInput(3, 3, 0, 380, 200, ButtonCenterX);
		buttons->SetUpNewButtonForUserInput(4, 4, 0, 430, 200, ButtonCenterX);
		buttons->SetUpNewButtonForUserInput(5, 5, 0, 480, 200, ButtonCenterX);

		if (game->CurrentlySelectedScreenOption == 0)
		{
			visuals->DrawTextOnScreenBuffer(1,"=>", 255, 255, 0, 0, 150, 230, TextLeftX);
			visuals->DrawTextOnScreenBuffer(1,"<=", 255, 255, 0, 0, 150, 230, TextRightX);
		}
		else if (game->CurrentlySelectedScreenOption == 1)
		{
			visuals->DrawTextOnScreenBuffer(1,"=>", 255, 255, 0, 0, 150, 280, TextLeftX);
			visuals->DrawTextOnScreenBuffer(1,"<=", 255, 255, 0, 0, 150, 280, TextRightX);
		}
		else if (game->CurrentlySelectedScreenOption == 2)
		{
			visuals->DrawTextOnScreenBuffer(1,"=>", 255, 255, 0, 0, 150, 330, TextLeftX);
			visuals->DrawTextOnScreenBuffer(1,"<=", 255, 255, 0, 0, 150, 330, TextRightX);
		}
		else if (game->CurrentlySelectedScreenOption == 3)
		{
			visuals->DrawTextOnScreenBuffer(1,"=>", 255, 255, 0, 0, 150, 380, TextLeftX);
			visuals->DrawTextOnScreenBuffer(1,"<=", 255, 255, 0, 0, 150, 380, TextRightX);
		}
		else if (game->CurrentlySelectedScreenOption == 4)
		{
			visuals->DrawTextOnScreenBuffer(1,"=>", 255, 255, 0, 0, 150, 430, TextLeftX);
			visuals->DrawTextOnScreenBuffer(1,"<=", 255, 255, 0, 0, 150, 430, TextRightX);
		}
		else if (game->CurrentlySelectedScreenOption == 5)
		{
			visuals->DrawTextOnScreenBuffer(1,"=>", 255, 255, 0, 0, 150, 480, TextLeftX);
			visuals->DrawTextOnScreenBuffer(1,"<=", 255, 255, 0, 0, 150, 480, TextRightX);
		}

		visuals->DrawTextOnScreenBuffer(1,"Game (C)opyright 2009 by", 255, 255, 255, 0, 0, 522, TextCenterX);
		visuals->DrawTextOnScreenBuffer(1,"www.SilentHeroProductions.com", 255, 255, 0, 0, 0, 560, TextCenterX);
		visuals->DrawTextOnScreenBuffer(1,"Original Concept by Alexey Pajitnov", 255, 255, 255, 0, 0, 599, TextCenterX);

		SDL_Flip(visuals->Screen);
		game->GameScreenDisplayed = true;
	}

	if (tetri_EnginE->GameMode == CrisisMode)
	{
		tetri_EnginE->NewGameGarbageLevel = 0;
		tetri_EnginE->NewGameStartingLevel = 0;
	}

	if (control->JoystickDirection[Any] == UP)
	{
		if (game->CurrentlySelectedScreenOption > 0)  game->CurrentlySelectedScreenOption--;
		else  game->CurrentlySelectedScreenOption = 5;
		game->GameScreenDisplayed = false;
		audio->PlayDigitalSoundFX(2);
	}
	else if (control->JoystickDirection[Any] == DOWN)
	{
		if (game->CurrentlySelectedScreenOption < 5)  game->CurrentlySelectedScreenOption++;
		else  game->CurrentlySelectedScreenOption = 0;
		game->GameScreenDisplayed = false;
		audio->PlayDigitalSoundFX(2);
	}

	if (buttons->ButtonClickedByUser(0) == true)
	{
		game->GameScreenDisplayed = false;
		visuals->FadeOutScreenBuffer();
		buttons->DeleteAllRegisteredButtons();
		game->GameScreen = MusicSelectionScreen;
		game->CurrentlySelectedScreenOption = 0;
	}
	else if (buttons->ButtonClickedByUser(1) == true)
	{
		game->GameScreenDisplayed = false;
		visuals->FadeOutScreenBuffer();
		buttons->DeleteAllRegisteredButtons();
		game->GameScreen = OptionsScreen;
		game->CurrentlySelectedScreenOption = 0;
	}
	else if (buttons->ButtonClickedByUser(2) == true)
	{
		game->GameScreenDisplayed = false;
		visuals->FadeOutScreenBuffer();
		buttons->DeleteAllRegisteredButtons();
		audio->PlayMusic(12,Loop);
		game->GameScreen = HighScoresScreen;
		game->CurrentlySelectedScreenOption = 1;
	}
	else if (buttons->ButtonClickedByUser(3) == true)
	{
		game->GameScreenDisplayed = false;
		visuals->FadeOutScreenBuffer();
		buttons->DeleteAllRegisteredButtons();
		game->GameScreen = HowToPlayScreen;
		game->SentenceLineY = 0;
		game->ParagraphPosition = 0;
		game->CurrentlySelectedScreenOption = 1;
	}
	else if (buttons->ButtonClickedByUser(4) == true)
	{
		game->GameScreenDisplayed = false;
		visuals->FadeOutScreenBuffer();
		buttons->DeleteAllRegisteredButtons();
		game->GameScreen = HistoryScreen;
		game->SentenceLineY = 0;
		game->ParagraphPosition = 0;
		game->CurrentlySelectedScreenOption = 1;
	}
	else if (buttons->ButtonClickedByUser(5) == true)
	{
		game->EXITgame = true;
	}
}

//-------------------------------------------------------------------------------------------------
void DisplayOptionsScreen(void)
{
    if (game->EXITgame == true) return;

	if (game->GameScreenDisplayed == false)
	{
		if (tetri_EnginE->DisplayBackground == 0)
		{
			SDL_BlitSurface(visuals->KremlinAlphaDark, NULL, visuals->Screen, NULL);
		}
		else  visuals->EraseScreenBufferWithColor(0, 0, 0);

		visuals->DrawTextOnScreenBuffer(1,"OPTIONS", 255, 255, 0, 0, 0, 2, TextCenterX);
		visuals->DrawTextOnScreenBuffer(1,"__________________________________", 255, 255, 0, 0, 0, 10, TextCenterX);

		visuals->DrawTextOnScreenBuffer(1,"Game Mode:", 255, 255, 0, 0, 45, 53, TextLeftX);

		if (tetri_EnginE->GameMode == OriginalMode)
		{
			visuals->DrawTextOnScreenBuffer(1,"Original", 255, 255, 0, 0, 45, 53, TextRightX);
			visuals->DrawTextOnScreenBuffer(1,"100% Gameboy Conversion", 0, 255, 0, 0, 0, 90, TextCenterX);
		}
		else if (tetri_EnginE->GameMode == Challenge25LineMode)
		{
			visuals->DrawTextOnScreenBuffer(1,"25 Line Challenge", 255, 255, 0, 0, 45, 53, TextRightX);
			visuals->DrawTextOnScreenBuffer(1,"Cleared Line Limit = 25 Lines", 0, 255, 0, 0, 0, 90, TextCenterX);
		}
		else if (tetri_EnginE->GameMode == TimeAttack30Mode)
		{
			visuals->DrawTextOnScreenBuffer(1,"Time Attack 30", 255, 255, 0, 0, 45, 53, TextRightX);
			visuals->DrawTextOnScreenBuffer(1,"Timed Game - Short", 0, 255, 0, 0, 0, 90, TextCenterX);
		}
		else if (tetri_EnginE->GameMode == TimeAttack60Mode)
		{
			visuals->DrawTextOnScreenBuffer(1,"Time Attack 60", 255, 255, 0, 0, 45, 53, TextRightX);
			visuals->DrawTextOnScreenBuffer(1,"Timed Game - Medium", 0, 255, 0, 0, 0, 90, TextCenterX);
		}
		else if (tetri_EnginE->GameMode == TimeAttack120Mode)
		{
			visuals->DrawTextOnScreenBuffer(1,"Time Attack 120", 255, 255, 0, 0, 45, 53, TextRightX);
			visuals->DrawTextOnScreenBuffer(1,"Timed Game - Long", 0, 255, 0, 0, 0, 90, TextCenterX);
		}
		else if (tetri_EnginE->GameMode == GarbageMode)
		{
			visuals->DrawTextOnScreenBuffer(1,"Garbage Mode", 255, 255, 0, 0, 45, 53, TextRightX);
			visuals->DrawTextOnScreenBuffer(1,"Unbreakable Garbage Boxes", 255, 0, 0, 0, 0, 90, TextCenterX);
		}
		else if (tetri_EnginE->GameMode == CrisisMode)
		{
			visuals->DrawTextOnScreenBuffer(1,"Crisis+Mode", 255, 255, 0, 0, 45, 53, TextRightX);
			visuals->DrawTextOnScreenBuffer(1,"Think Fast Or Die Crisis+Mode!", 255, 153, 0, 0, 0, 90, TextCenterX);
		}

		visuals->DrawTextOnScreenBuffer(1,"__________________________________", 255, 255, 0, 0, 0, 106, TextCenterX);

		visuals->DrawTextOnScreenBuffer(1,"New Game Garbage Level:", 255, 255, 0, 0, 45, 157, TextLeftX);
		sprintf(visuals->VariableText, "%d", tetri_EnginE->NewGameGarbageLevel);
		visuals->DrawTextOnScreenBuffer(1,visuals->VariableText, 255, 255, 0, 0, 45, 157, TextRightX);

		visuals->DrawTextOnScreenBuffer(1,"New Game Starting Level:", 255, 255, 0, 0, 45, 211, TextLeftX);
		sprintf(visuals->VariableText, "%d", tetri_EnginE->NewGameStartingLevel);
		visuals->DrawTextOnScreenBuffer(1,visuals->VariableText, 255, 255, 0, 0, 45, 211, TextRightX);

		visuals->DrawTextOnScreenBuffer(1,"Display Next Piece:", 255, 255, 0, 0, 45, 265, TextLeftX);
		if (tetri_EnginE->DisplayNextPiece == 0)
			visuals->DrawTextOnScreenBuffer(1,"Off", 255, 255, 0, 0, 45, 265, TextRightX);
		else if (tetri_EnginE->DisplayNextPiece == 1)
			visuals->DrawTextOnScreenBuffer(1,"On", 255, 255, 0, 0, 45, 265, TextRightX);

		visuals->DrawTextOnScreenBuffer(1,"Display Drop Shadow:", 255, 255, 0, 0, 45, 319, TextLeftX);
		if (tetri_EnginE->DisplayDropShadow == 0)
			visuals->DrawTextOnScreenBuffer(1,"Off", 255, 255, 0, 0, 45, 319, TextRightX);
		else if (tetri_EnginE->DisplayDropShadow == 1)
			visuals->DrawTextOnScreenBuffer(1,"On", 255, 255, 0, 0, 45, 319, TextRightX);

		visuals->DrawTextOnScreenBuffer(1,"Display Background:", 255, 255, 0, 0, 45, 373, TextLeftX);
		if (tetri_EnginE->DisplayBackground == 0)
			visuals->DrawTextOnScreenBuffer(1,"Kremlin", 255, 255, 0, 0, 45, 373, TextRightX);
		if (tetri_EnginE->DisplayBackground == 1)
			visuals->DrawTextOnScreenBuffer(1,"Off", 255, 255, 0, 0, 45, 373, TextRightX);

		visuals->DrawTextOnScreenBuffer(1,"Pressing [UP]:", 255, 255, 0, 0, 45, 427, TextLeftX);
		if (tetri_EnginE->PressingUPAction == 0)
			visuals->DrawTextOnScreenBuffer(1,"Off", 255, 255, 0, 0, 45, 427, TextRightX);
		else if (tetri_EnginE->PressingUPAction == 1)
			visuals->DrawTextOnScreenBuffer(1,"Instant Piece Drop", 255, 255, 0, 0, 45, 427, TextRightX);
		else if (tetri_EnginE->PressingUPAction == 2)
			visuals->DrawTextOnScreenBuffer(1,"Rotate Piece", 255, 255, 0, 0, 45, 427, TextRightX);

		visuals->DrawTextOnScreenBuffer(1,"__________________________________", 255, 255, 0, 0, 0, 458, TextCenterX);

		visuals->DrawTextOnScreenBuffer(1,"Music Volume:", 255, 255, 0, 0, 45, 500, TextLeftX);
		if (audio->MusicVolume == 128)
			visuals->DrawTextOnScreenBuffer(1,"Max", 255, 255, 0, 0, 45, 500, TextRightX);
		else if (audio->MusicVolume == 96)
			visuals->DrawTextOnScreenBuffer(1,"High", 255, 255, 0, 0, 45, 500, TextRightX);
		else if (audio->MusicVolume == 64)
			visuals->DrawTextOnScreenBuffer(1,"Medium", 255, 255, 0, 0, 45, 500, TextRightX);
		else if (audio->MusicVolume == 32)
			visuals->DrawTextOnScreenBuffer(1,"Low", 255, 255, 0, 0, 45, 500, TextRightX);
		else if (audio->MusicVolume == 0)
			visuals->DrawTextOnScreenBuffer(1,"Off", 255, 255, 0, 0, 45, 500, TextRightX);

		visuals->DrawTextOnScreenBuffer(1,"Sound Effects Volume:", 255, 255, 0, 0, 45, 545, TextLeftX);
		if (audio->SoundVolume == 128)
			visuals->DrawTextOnScreenBuffer(1,"Max", 255, 255, 0, 0, 45, 545, TextRightX);
		else if (audio->SoundVolume == 96)
			visuals->DrawTextOnScreenBuffer(1,"High", 255, 255, 0, 0, 45, 545, TextRightX);
		else if (audio->SoundVolume == 64)
			visuals->DrawTextOnScreenBuffer(1,"Medium", 255, 255, 0, 0, 45, 545, TextRightX);
		else if (audio->SoundVolume == 32)
			visuals->DrawTextOnScreenBuffer(1,"Low", 255, 255, 0, 0, 45, 545, TextRightX);
		else if (audio->SoundVolume == 0)
			visuals->DrawTextOnScreenBuffer(1,"Off", 255, 255, 0, 0, 45, 545, TextRightX);

		visuals->DrawTextOnScreenBuffer(1,"__________________________________", 255, 255, 0, 0, 0, 555, TextCenterX);
		buttons->SetUpNewButtonForUserInput(6, 9, 0, 596, 200, ButtonCenterX);

		if (game->CurrentlySelectedScreenOption == 0)
		{
			visuals->DrawTextOnScreenBuffer(1,"<=", 255, 255, 0, 0, 1, 53, TextLeftX);
			visuals->DrawTextOnScreenBuffer(1,"=>", 255, 255, 0, 0, 1, 53, TextRightX);
		}
		else if (game->CurrentlySelectedScreenOption == 1)
		{
			visuals->DrawTextOnScreenBuffer(1,"<=", 255, 255, 0, 0, 1, 157, TextLeftX);
			visuals->DrawTextOnScreenBuffer(1,"=>", 255, 255, 0, 0, 1, 157, TextRightX);
		}
		else if (game->CurrentlySelectedScreenOption == 2)
		{
			visuals->DrawTextOnScreenBuffer(1,"<=", 255, 255, 0, 0, 1, 211, TextLeftX);
			visuals->DrawTextOnScreenBuffer(1,"=>", 255, 255, 0, 0, 1, 211, TextRightX);
		}
		else if (game->CurrentlySelectedScreenOption == 3)
		{
			visuals->DrawTextOnScreenBuffer(1,"<=", 255, 255, 0, 0, 1, 265, TextLeftX);
			visuals->DrawTextOnScreenBuffer(1,"=>", 255, 255, 0, 0, 1, 265, TextRightX);
		}
		else if (game->CurrentlySelectedScreenOption == 4)
		{
			visuals->DrawTextOnScreenBuffer(1,"<=", 255, 255, 0, 0, 1, 319, TextLeftX);
			visuals->DrawTextOnScreenBuffer(1,"=>", 255, 255, 0, 0, 1, 319, TextRightX);
		}
		else if (game->CurrentlySelectedScreenOption == 5)
		{
			visuals->DrawTextOnScreenBuffer(1,"<=", 255, 255, 0, 0, 1, 373, TextLeftX);
			visuals->DrawTextOnScreenBuffer(1,"=>", 255, 255, 0, 0, 1, 373, TextRightX);
		}
		else if (game->CurrentlySelectedScreenOption == 6)
		{
			visuals->DrawTextOnScreenBuffer(1,"<=", 255, 255, 0, 0, 1, 427, TextLeftX);
			visuals->DrawTextOnScreenBuffer(1,"=>", 255, 255, 0, 0, 1, 427, TextRightX);
		}
		else if (game->CurrentlySelectedScreenOption == 7)
		{
			visuals->DrawTextOnScreenBuffer(1,"<=", 255, 255, 0, 0, 1, 500, TextLeftX);
			visuals->DrawTextOnScreenBuffer(1,"=>", 255, 255, 0, 0, 1, 500, TextRightX);
		}
		else if (game->CurrentlySelectedScreenOption == 8)
		{
			visuals->DrawTextOnScreenBuffer(1,"<=", 255, 255, 0, 0, 1, 545, TextLeftX);
			visuals->DrawTextOnScreenBuffer(1,"=>", 255, 255, 0, 0, 1, 545, TextRightX);
		}
		else if (game->CurrentlySelectedScreenOption == 9)
		{
			visuals->DrawTextOnScreenBuffer(1,"=>", 255, 255, 0, 0, 150, 596, TextLeftX);
			visuals->DrawTextOnScreenBuffer(1,"<=", 255, 255, 0, 0, 150, 596, TextRightX);
		}

		SDL_Flip(visuals->Screen);
		game->GameScreenDisplayed = true;
	}

	if (control->JoystickDirection[Any] == UP)
	{
		if (game->CurrentlySelectedScreenOption > 0)  game->CurrentlySelectedScreenOption--;
		else  game->CurrentlySelectedScreenOption = 9;
		game->GameScreenDisplayed = false;
		audio->PlayDigitalSoundFX(2);
	}
	else if (control->JoystickDirection[Any] == DOWN)
	{
		if (game->CurrentlySelectedScreenOption < 9)  game->CurrentlySelectedScreenOption++;
		else  game->CurrentlySelectedScreenOption = 0;
		game->GameScreenDisplayed = false;
		audio->PlayDigitalSoundFX(2);
	}
	else if (control->JoystickDirection[Any] == LEFT)
	{
		if (game->CurrentlySelectedScreenOption == 0)
		{
			if (tetri_EnginE->GameMode > 0)  tetri_EnginE->GameMode--;
			else  tetri_EnginE->GameMode = 6;
		}
		else if (game->CurrentlySelectedScreenOption == 1)
		{
			if (tetri_EnginE->NewGameGarbageLevel > 0)  tetri_EnginE->NewGameGarbageLevel--;
			else  tetri_EnginE->NewGameGarbageLevel = 15;
		}
		else if (game->CurrentlySelectedScreenOption == 2)
		{
			if (tetri_EnginE->NewGameStartingLevel > 0)  tetri_EnginE->NewGameStartingLevel--;
			else  tetri_EnginE->NewGameStartingLevel = 9;
		}
		else if (game->CurrentlySelectedScreenOption == 3)
		{
			if (tetri_EnginE->DisplayNextPiece > 0)  tetri_EnginE->DisplayNextPiece--;
			else  tetri_EnginE->DisplayNextPiece = 1;
		}
		else if (game->CurrentlySelectedScreenOption == 4)
		{
			if (tetri_EnginE->DisplayDropShadow > 0)  tetri_EnginE->DisplayDropShadow--;
			else  tetri_EnginE->DisplayDropShadow = 1;
		}
		else if (game->CurrentlySelectedScreenOption == 5)
		{
			if (tetri_EnginE->DisplayBackground > 0)  tetri_EnginE->DisplayBackground--;
			else  tetri_EnginE->DisplayBackground = 1;
		}
		else if (game->CurrentlySelectedScreenOption == 6)
		{
			if (tetri_EnginE->PressingUPAction > 0)  tetri_EnginE->PressingUPAction--;
			else  tetri_EnginE->PressingUPAction = 2;
		}
		else if (game->CurrentlySelectedScreenOption == 7)
		{
			if (audio->MusicVolume > 0)  audio->MusicVolume-=32;
			else  audio->MusicVolume = 128;

			Mix_VolumeMusic(audio->MusicVolume);
			audio->PlayMusic(1, -1);
		}
		else if (game->CurrentlySelectedScreenOption == 8)
		{
			if (audio->SoundVolume > 0)  audio->SoundVolume-=32;
			else  audio->SoundVolume = 128;

			Uint8 channelIndex;
			for (channelIndex = 0; channelIndex < 16; channelIndex++)
			{
				Mix_Volume( channelIndex, audio->SoundVolume);
			}

			Uint8 soundIndex;
			for (soundIndex = 0; soundIndex < SoundTotal; soundIndex++)
			{
				Mix_VolumeChunk(audio->SoundFX[soundIndex], audio->SoundVolume);
			}
		}

		audio->PlayDigitalSoundFX(2);
		game->GameScreenDisplayed = false;
	}
	else if (control->JoystickDirection[Any] == RIGHT)
	{
		if (game->CurrentlySelectedScreenOption == 0)
		{
			if (tetri_EnginE->GameMode < 6)  tetri_EnginE->GameMode++;
			else  tetri_EnginE->GameMode = 0;
		}
		else if (game->CurrentlySelectedScreenOption == 1)
		{
			if (tetri_EnginE->NewGameGarbageLevel < 15)  tetri_EnginE->NewGameGarbageLevel++;
			else  tetri_EnginE->NewGameGarbageLevel = 0;
		}
		else if (game->CurrentlySelectedScreenOption == 2)
		{
			if (tetri_EnginE->NewGameStartingLevel < 9)  tetri_EnginE->NewGameStartingLevel++;
			else  tetri_EnginE->NewGameStartingLevel = 0;
		}
		else if (game->CurrentlySelectedScreenOption == 3)
		{
			if (tetri_EnginE->DisplayNextPiece < 1)  tetri_EnginE->DisplayNextPiece++;
			else  tetri_EnginE->DisplayNextPiece = 0;
		}
		else if (game->CurrentlySelectedScreenOption == 4)
		{
			if (tetri_EnginE->DisplayDropShadow < 1)  tetri_EnginE->DisplayDropShadow++;
			else  tetri_EnginE->DisplayDropShadow = 0;
		}
		else if (game->CurrentlySelectedScreenOption == 5)
		{
			if (tetri_EnginE->DisplayBackground < 1)  tetri_EnginE->DisplayBackground++;
			else  tetri_EnginE->DisplayBackground = 0;
		}
		else if (game->CurrentlySelectedScreenOption == 6)
		{
			if (tetri_EnginE->PressingUPAction < 2)  tetri_EnginE->PressingUPAction++;
			else  tetri_EnginE->PressingUPAction = 0;
		}
		else if (game->CurrentlySelectedScreenOption == 7)
		{
			if (audio->MusicVolume < 128)  audio->MusicVolume+=32;
			else  audio->MusicVolume = 0;

			Mix_VolumeMusic(audio->MusicVolume);
			audio->PlayMusic(1, -1);
		}
		else if (game->CurrentlySelectedScreenOption == 8)
		{
			if (audio->SoundVolume < 128)  audio->SoundVolume+=32;
			else  audio->SoundVolume = 0;

			Uint8 channelIndex;
			for (channelIndex = 0; channelIndex < 16; channelIndex++)
			{
				Mix_Volume( channelIndex, audio->SoundVolume);
			}

			Uint8 soundIndex;
			for (soundIndex = 0; soundIndex < SoundTotal; soundIndex++)
			{
				Mix_VolumeChunk(audio->SoundFX[soundIndex], audio->SoundVolume);
			}
		}

		audio->PlayDigitalSoundFX(2);
		game->GameScreenDisplayed = false;
	}

	if (control->JoystickButton1[Mouse] == ON)
	{
		if ( (control->MouseX < 320)&&(control->MouseY > 49 && control->MouseY < 136) )
		{
			game->CurrentlySelectedScreenOption = 0;
			if (tetri_EnginE->GameMode > 0)  tetri_EnginE->GameMode--;
			else  tetri_EnginE->GameMode = 6;
		}
		else if ( (control->MouseX > 320)&&(control->MouseY > 49 && control->MouseY < 136) )
		{
			game->CurrentlySelectedScreenOption = 0;
			if (tetri_EnginE->GameMode < 6)  tetri_EnginE->GameMode++;
			else  tetri_EnginE->GameMode = 0;
		}
		else if ( (control->MouseX < 320)&&(control->MouseY > 125 && control->MouseY < 203) )
		{
			game->CurrentlySelectedScreenOption = 1;
			if (tetri_EnginE->NewGameGarbageLevel > 0)  tetri_EnginE->NewGameGarbageLevel--;
			else  tetri_EnginE->NewGameGarbageLevel = 15;
		}
		else if ( (control->MouseX > 320)&&(control->MouseY > 125 && control->MouseY < 203) )
		{
			game->CurrentlySelectedScreenOption = 1;
			if (tetri_EnginE->NewGameGarbageLevel < 15)  tetri_EnginE->NewGameGarbageLevel++;
			else  tetri_EnginE->NewGameGarbageLevel = 0;
		}
		else if ( (control->MouseX < 320)&&(control->MouseY > 203 && control->MouseY < 256) )
		{
			game->CurrentlySelectedScreenOption = 2;
			if (tetri_EnginE->NewGameStartingLevel > 0)  tetri_EnginE->NewGameStartingLevel--;
			else  tetri_EnginE->NewGameStartingLevel = 9;
		}
		else if ( (control->MouseX > 320)&&(control->MouseY > 203 && control->MouseY < 256) )
		{
			game->CurrentlySelectedScreenOption = 2;
			if (tetri_EnginE->NewGameStartingLevel < 9)  tetri_EnginE->NewGameStartingLevel++;
			else  tetri_EnginE->NewGameStartingLevel = 0;
		}
		else if ( (control->MouseX < 320)&&(control->MouseY > 256 && control->MouseY < 312) )
		{
			game->CurrentlySelectedScreenOption = 3;
			if (tetri_EnginE->DisplayNextPiece > 0)  tetri_EnginE->DisplayNextPiece--;
			else  tetri_EnginE->DisplayNextPiece = 1;
		}
		else if ( (control->MouseX > 320)&&(control->MouseY > 256 && control->MouseY < 312) )
		{
			game->CurrentlySelectedScreenOption = 3;
			if (tetri_EnginE->DisplayNextPiece < 1)  tetri_EnginE->DisplayNextPiece++;
			else  tetri_EnginE->DisplayNextPiece = 0;
		}
		else if ( (control->MouseX < 320)&&(control->MouseY > 312 && control->MouseY < 366) )
		{
			game->CurrentlySelectedScreenOption = 4;
			if (tetri_EnginE->DisplayDropShadow > 0)  tetri_EnginE->DisplayDropShadow--;
			else  tetri_EnginE->DisplayDropShadow = 1;
		}
		else if ( (control->MouseX > 320)&&(control->MouseY > 312 && control->MouseY < 366) )
		{
			game->CurrentlySelectedScreenOption = 4;
			if (tetri_EnginE->DisplayDropShadow < 1)  tetri_EnginE->DisplayDropShadow++;
			else  tetri_EnginE->DisplayDropShadow = 0;
		}
		else if ( (control->MouseX < 320)&&(control->MouseY > 366 && control->MouseY < 420) )
		{
			game->CurrentlySelectedScreenOption = 5;
			if (tetri_EnginE->DisplayBackground > 0)  tetri_EnginE->DisplayBackground--;
			else  tetri_EnginE->DisplayBackground = 1;
		}
		else if ( (control->MouseX > 320)&&(control->MouseY > 366 && control->MouseY < 420) )
		{
			game->CurrentlySelectedScreenOption = 5;
			if (tetri_EnginE->DisplayBackground < 1)  tetri_EnginE->DisplayBackground++;
			else  tetri_EnginE->DisplayBackground = 0;
		}
		else if ( (control->MouseX < 320)&&(control->MouseY > 420 && control->MouseY < 488) )
		{
			game->CurrentlySelectedScreenOption = 6;
			if (tetri_EnginE->PressingUPAction > 0)  tetri_EnginE->PressingUPAction--;
			else  tetri_EnginE->PressingUPAction = 2;
		}
		else if ( (control->MouseX > 320)&&(control->MouseY > 420 && control->MouseY < 488) )
		{
			game->CurrentlySelectedScreenOption = 6;
			if (tetri_EnginE->PressingUPAction < 2)  tetri_EnginE->PressingUPAction++;
			else  tetri_EnginE->PressingUPAction = 0;
		}
		else if ( (control->MouseX < 320)&&(control->MouseY > 488 && control->MouseY < 542) )
		{
			game->CurrentlySelectedScreenOption = 7;
			if (audio->MusicVolume > 0)  audio->MusicVolume-=32;
			else  audio->MusicVolume = 128;

			Mix_VolumeMusic(audio->MusicVolume);
			audio->PlayMusic(1, -1);
		}
		else if ( (control->MouseX > 320)&&(control->MouseY > 488 && control->MouseY < 542) )
		{
			game->CurrentlySelectedScreenOption = 7;
			if (audio->MusicVolume < 128)  audio->MusicVolume+=32;
			else  audio->MusicVolume = 0;

			Mix_VolumeMusic(audio->MusicVolume);
			audio->PlayMusic(1, -1);
		}
		else if ( (control->MouseX < 320)&&(control->MouseY > 542 && control->MouseY < 585) )
		{
			game->CurrentlySelectedScreenOption = 8;
			if (audio->SoundVolume > 0)  audio->SoundVolume-=32;
			else  audio->SoundVolume = 128;

			Uint8 channelIndex;
			for (channelIndex = 0; channelIndex < 16; channelIndex++)
			{
				Mix_Volume( channelIndex, audio->SoundVolume);
			}

			Uint8 soundIndex;
			for (soundIndex = 0; soundIndex < SoundTotal; soundIndex++)
			{
				Mix_VolumeChunk(audio->SoundFX[soundIndex], audio->SoundVolume);
			}
		}
		else if ( (control->MouseX > 320)&&(control->MouseY > 542 && control->MouseY < 585) )
		{
			game->CurrentlySelectedScreenOption = 8;
			if (audio->SoundVolume < 128)  audio->SoundVolume+=32;
			else  audio->SoundVolume = 0;

			Uint8 channelIndex;
			for (channelIndex = 0; channelIndex < 16; channelIndex++)
			{
				Mix_Volume( channelIndex, audio->SoundVolume);
			}

			Uint8 soundIndex;
			for (soundIndex = 0; soundIndex < SoundTotal; soundIndex++)
			{
				Mix_VolumeChunk(audio->SoundFX[soundIndex], audio->SoundVolume);
			}
		}

		audio->PlayDigitalSoundFX(2);
		game->GameScreenDisplayed = false;
	}

	if (buttons->ButtonClickedByUser(6) == true)
	{
		game->GameScreenDisplayed = false;
		visuals->FadeOutScreenBuffer();
		buttons->DeleteAllRegisteredButtons();
		game->GameScreen = TitleScreen;
		game->CurrentlySelectedScreenOption = 0;
	}
}

//-------------------------------------------------------------------------------------------------
void DisplayMusicSelectionScreen(void)
{
Uint16 tileScreenX;
Uint16 tileScreenY;

    if (game->EXITgame == true) return;

	if (audio->MusicVolume == 0)
	{
		game->GameScreenDisplayed = false;
		visuals->FadeOutScreenBuffer();
		game->GameScreen = PlayingTetri_GameScreen;
		tetri_EnginE->SetUpForNewGame();
		tetri_EnginE->DrawEntirePlayfieldScreenOntoScreenBuffer(true);
		visuals->FadeInScreenBuffer();
		return;
	}

	if (game->GameScreenDisplayed == false)
	{
		audio->PlayMusic(audio->CurrentlySelectedMusicTrack+2, Loop);

		if (tetri_EnginE->DisplayBackground == 0)
		{
			SDL_BlitSurface(visuals->KremlinAlphaDark, NULL, visuals->Screen, NULL);
		}
		else  visuals->EraseScreenBufferWithColor(0, 0, 0);

		visuals->DisplaySpriteOnScreenBufferGlass(5, 2, 20, 255);
		visuals->DisplaySpriteOnScreenBufferGlass(6, 253, 2, 255);
		visuals->DrawTextOnScreenBuffer(1,"TM", 255, 255, 255, 0, 0, 8, TextRightX);
		visuals->DisplaySpriteOnScreenBufferGlass(7, 464, 128, 255);
		visuals->DrawTextOnScreenBuffer(1,"5.9 Remix", 255, 255, 0, 0, 4, 184, TextRightX);

		visuals->DrawTextOnScreenBuffer(1, &tetri_EnginE->HighScoresName[tetri_EnginE->GameMode][0][0], 255, 255, 255, 0, 0, 130, TextCenterX);
		sprintf(visuals->VariableText, "%d", tetri_EnginE->HishScoresScore[tetri_EnginE->GameMode][0]);
		visuals->DrawTextOnScreenBuffer(1,visuals->VariableText, 255, 255, 255, 0, 0, 180, TextCenterX);

		visuals->DrawTextOnScreenBuffer(1,"Game (C)opyright 2009 by", 255, 255, 255, 0, 0, 522, TextCenterX);
		visuals->DrawTextOnScreenBuffer(1,"www.SilentHeroProductions.com", 255, 255, 0, 0, 0, 560, TextCenterX);
		visuals->DrawTextOnScreenBuffer(1,"Original Concept by Alexey Pajitnov", 255, 255, 255, 0, 0, 599, TextCenterX);

		for (tileScreenY = 0; tileScreenY < 640; tileScreenY+=12)
			for (tileScreenX = 0; tileScreenX < 640; tileScreenX+=12)
				visuals->DisplaySpriteOnScreenBufferGlass(0, tileScreenX, tileScreenY, 127);

		visuals->DrawTextOnScreenBuffer(1,"_______________________________", 255, 255, 255, 0, 0, 210, TextCenterX);
		visuals->DrawTextOnScreenBuffer(1,"SELECT IN GAME MUSIC:", 255, 255, 0, 0, 0, 270, TextCenterX);
		visuals->DrawTextOnScreenBuffer(1,"Press [LEFT] and [RIGHT] to change", 230, 230, 230, 0, 0, 330, TextCenterX);
		visuals->DrawTextOnScreenBuffer(1,"<=", 255, 255, 0, 0, 0, 390, TextLeftX);
		visuals->DrawTextOnScreenBuffer(1,"=>", 255, 255, 0, 0, 0, 390, TextRightX);

		if (audio->CurrentlySelectedMusicTrack == 0)  visuals->DrawTextOnScreenBuffer(1,"Music Track #1", 255, 255, 255, 0, 0, 390, TextCenterX);
		else if (audio->CurrentlySelectedMusicTrack == 1)  visuals->DrawTextOnScreenBuffer(1,"Music Track #2", 255, 255, 255, 0, 0, 390, TextCenterX);
		else if (audio->CurrentlySelectedMusicTrack == 2)  visuals->DrawTextOnScreenBuffer(1,"Music Track #3", 255, 255, 255, 0, 0, 390, TextCenterX);
		else if (audio->CurrentlySelectedMusicTrack == 3)  visuals->DrawTextOnScreenBuffer(1,"Music Track #4", 255, 255, 255, 0, 0, 390, TextCenterX);
		else if (audio->CurrentlySelectedMusicTrack == 4)  visuals->DrawTextOnScreenBuffer(1,"Music Track #5", 255, 255, 255, 0, 0, 390, TextCenterX);
		else if (audio->CurrentlySelectedMusicTrack == 5)  visuals->DrawTextOnScreenBuffer(1,"Music Track #6", 255, 255, 255, 0, 0, 390, TextCenterX);
		else if (audio->CurrentlySelectedMusicTrack == 6)  visuals->DrawTextOnScreenBuffer(1,"Music Track #7", 255, 255, 255, 0, 0, 390, TextCenterX);
		else if (audio->CurrentlySelectedMusicTrack == 7)  visuals->DrawTextOnScreenBuffer(1,"Music Track #8", 255, 255, 255, 0, 0, 390, TextCenterX);
		else if (audio->CurrentlySelectedMusicTrack == 8)  visuals->DrawTextOnScreenBuffer(1,"Bonus Track #9", 255, 255, 255, 0, 0, 390, TextCenterX);
		else if (audio->CurrentlySelectedMusicTrack == 9)  visuals->DrawTextOnScreenBuffer(1,"Bonus Track #10", 255, 255, 255, 0, 0, 390, TextCenterX);

		visuals->DrawTextOnScreenBuffer(1,"Press [Z] or [X] to START!", 230, 230, 230, 0, 0, 450, TextCenterX);
		visuals->DrawTextOnScreenBuffer(1,"_______________________________", 255, 255, 255, 0, 0, 480, TextCenterX);

		SDL_Flip(visuals->Screen);
		game->GameScreenDisplayed = true;
	}

	if (control->JoystickDirection[Any] == LEFT)
	{
		if (audio->CurrentlySelectedMusicTrack == 0)  audio->CurrentlySelectedMusicTrack = 9;
		else audio->CurrentlySelectedMusicTrack--;
		game->GameScreenDisplayed = false;
	}
	else if (control->JoystickDirection[Any] == RIGHT)
	{
		if (audio->CurrentlySelectedMusicTrack == 9)  audio->CurrentlySelectedMusicTrack = 0;
		else audio->CurrentlySelectedMusicTrack++;
		game->GameScreenDisplayed = false;
	}

	if ( (control->JoystickButton1[Any] == ON)||(control->JoystickButton2[Any] == ON) )
	{
		game->GameScreenDisplayed = false;
		visuals->FadeOutScreenBuffer();
		game->GameScreen = PlayingTetri_GameScreen;
		tetri_EnginE->SetUpForNewGame();
		tetri_EnginE->DrawEntirePlayfieldScreenOntoScreenBuffer(true);
		visuals->FadeInScreenBuffer();
	}
}

//-------------------------------------------------------------------------------------------------
void DisplayPlayingTetri_GameScreen(void)
{
    if (game->EXITgame == true) return;

	if (game->PAUSEgame != true)
	{
		if (tetri_EnginE->FlashAnimationTimer == -1)
		{
			if (control->JoystickDirection[Any] == UP)
			{
				if (tetri_EnginE->PressingUPAction == 1)  tetri_EnginE->MovePieceDownFast();
				else if (tetri_EnginE->PressingUPAction == 2)
				{
					if (tetri_EnginE->RotationDirection == 0)  tetri_EnginE->RotatePieceClockwise();
					else  tetri_EnginE->RotatePieceCounterClockwise();
				}
			}

			if (control->JoystickDirection[Any] == LEFT)  tetri_EnginE->MovePieceLeft();
			else if (tetri_EnginE->PieceMovementDelay < 0)  tetri_EnginE->PieceMovementDelay = 0;

			if (control->JoystickDirection[Any] == RIGHT)  tetri_EnginE->MovePieceRight();
			else if (tetri_EnginE->PieceMovementDelay > 0)  tetri_EnginE->PieceMovementDelay = 0;

			if (control->JoystickDirection[Any] == DOWN)  tetri_EnginE->MovePieceDown();
			else tetri_EnginE->DropScoreBonus = 0;

			if (control->JoystickButton1[Any] == ON) tetri_EnginE->RotatePieceClockwise();
			else if (control->JoystickButton2[Any] == ON) tetri_EnginE->RotatePieceCounterClockwise();

			if (control->JoystickDirection[Any] != DOWN)  tetri_EnginE->PieceFallCountdownTimer--;
			if (tetri_EnginE->PieceFallCountdownTimer == 0)
			{
				tetri_EnginE->MovePieceDown();
				audio->PlayDigitalSoundFX(2);
				tetri_EnginE->PieceFallCountdownTimer = tetri_EnginE->GetNewPieceFallCountdownTimer();
			}

			if ( (tetri_EnginE->BoxesOnTopRowOfPlayfield() == true)&&(tetri_EnginE->GameMode == CrisisMode) )
			{
				tetri_EnginE->CrisisModeDangerTimer++;

				if (tetri_EnginE->CrisisModeDangerTimer == 50)
				{
					audio->PlayDigitalSoundFX(10);
					tetri_EnginE->CrisisModeDangerTimer = 0;
				}
			}

			if ( (tetri_EnginE->GameMode == Challenge25LineMode)&&(tetri_EnginE->Lines > 24) )
			{
				game->GameScreen = GameOverScreen;
				tetri_EnginE->GameOverDisplayFrame = 0;
				tetri_EnginE->FlashAnimationTimer = 0;
			}

			if ( (tetri_EnginE->GameMode == TimeAttack30Mode)||(tetri_EnginE->GameMode == TimeAttack60Mode)||(tetri_EnginE->GameMode == TimeAttack120Mode) )
			{
				if (tetri_EnginE->TimeAttackTimer > 0)  tetri_EnginE->TimeAttackTimer--;

				if (tetri_EnginE->TimeAttackTimer == 0)
				{
					tetri_EnginE->GameOverDisplayFrame = 0;
					tetri_EnginE->FlashAnimationTimer = 0;
					game->GameScreen = GameOverScreen;;
					return;
				}
			}

			if (tetri_EnginE->GameMode == CrisisMode)
			{
				tetri_EnginE->CrisisModeTimer--;
				if (tetri_EnginE->CrisisModeTimer == 0)
				{
					tetri_EnginE->AddAnIncompleteLineToThePlayfield();
					tetri_EnginE->CrisisModeTimer = 360;
				}
			}

			if (control->KeyOnKeyboardPressedByUser == 'w')
			{
				if (tetri_EnginE->GameMode == CrisisMode)
				{
					audio->PlayDigitalSoundFX(6);
					audio->PlayMusic(15, Loop);
					tetri_EnginE->EasterEggStaffRoll = true;
					control->DelayUserInput = 7;
				}
			}

			if (control->KeyOnKeyboardPressedByUser == 'p')
			{
				if (audio->CurrentlySelectedMusicTrack < 9)  audio->CurrentlySelectedMusicTrack++;
				else  audio->CurrentlySelectedMusicTrack = 0;
				audio->PlayMusic(audio->CurrentlySelectedMusicTrack+2, Loop);
				audio->PlayDigitalSoundFX(6);
				control->DelayUserInput = 7;
			}

			if (control->KeyOnKeyboardPressedByUser == ' ')
			{
				game->PAUSEgame = true;
				audio->PlayDigitalSoundFX(6);
				Mix_PauseMusic();
				control->DelayUserInput = 7;
			}

			if ( (tetri_EnginE->FlashAnimationTimer == -1)&&(tetri_EnginE->AddIncompleteLineWhenAnimationFinished == true) )
			{
					tetri_EnginE->AddAnIncompleteLineToThePlayfield();
					tetri_EnginE->CrisisModeTimer = 360;
					tetri_EnginE->AddIncompleteLineWhenAnimationFinished = false;
			}

			if (tetri_EnginE->ScreenDirty == true)
			{
				tetri_EnginE->DrawEntirePlayfieldScreenOntoScreenBuffer(true);
				SDL_Flip(visuals->Screen);
				tetri_EnginE->ScreenDirty = false;
			}

			if (tetri_EnginE->FlashAnimationTimerHighScore == 10 || tetri_EnginE->FlashAnimationTimerHighScore == 8 || tetri_EnginE->FlashAnimationTimerHighScore == 6 || tetri_EnginE->FlashAnimationTimerHighScore == 4 || tetri_EnginE->FlashAnimationTimerHighScore == 2)
			{
				visuals->DrawTextOnScreenBuffer(1,"Score:", 0, 0, 0, 0, 420, 190, TextLeftX);
				sprintf(visuals->VariableText, "%d", tetri_EnginE->Score);
				visuals->DrawTextOnScreenBuffer(1,visuals->VariableText, 0, 0, 0, 0, 420, 220, TextLeftX);
				SDL_Flip(visuals->Screen);
			}
			else if (tetri_EnginE->FlashAnimationTimerHighScore == 9 || tetri_EnginE->FlashAnimationTimerHighScore == 7 || tetri_EnginE->FlashAnimationTimerHighScore == 5 || tetri_EnginE->FlashAnimationTimerHighScore == 3 || tetri_EnginE->FlashAnimationTimerHighScore == 1)
			{
				visuals->DrawTextOnScreenBuffer(1,"Score:", 255, 255, 255, 0, 420, 190, TextLeftX);
				sprintf(visuals->VariableText, "%d", tetri_EnginE->Score);
				visuals->DrawTextOnScreenBuffer(1,visuals->VariableText, 255, 255, 255, 0, 420, 220, TextLeftX);
				SDL_Flip(visuals->Screen);
			}
			if (tetri_EnginE->FlashAnimationTimerHighScore > -1)  tetri_EnginE->FlashAnimationTimerHighScore--;

			if (tetri_EnginE->FlashAnimationTimerLevelUp == 10 || tetri_EnginE->FlashAnimationTimerLevelUp == 8 || tetri_EnginE->FlashAnimationTimerLevelUp == 6 || tetri_EnginE->FlashAnimationTimerLevelUp == 4 || tetri_EnginE->FlashAnimationTimerLevelUp == 2)
			{
				visuals->DrawTextOnScreenBuffer(1,"Level:", 0, 0, 0, 0, 420, 350, TextLeftX);
				sprintf(visuals->VariableText, "%d", tetri_EnginE->Level);
				visuals->DrawTextOnScreenBuffer(1,visuals->VariableText, 0, 0, 0, 0, 520, 350, TextLeftX);
				SDL_Flip(visuals->Screen);
			}
			else if (tetri_EnginE->FlashAnimationTimerLevelUp == 9 || tetri_EnginE->FlashAnimationTimerLevelUp == 7 || tetri_EnginE->FlashAnimationTimerLevelUp == 5 || tetri_EnginE->FlashAnimationTimerLevelUp == 3 || tetri_EnginE->FlashAnimationTimerLevelUp == 1)
			{
				visuals->DrawTextOnScreenBuffer(1,"Level:", 255, 255, 255, 0, 420, 350, TextLeftX);
				sprintf(visuals->VariableText, "%d", tetri_EnginE->Level);
				visuals->DrawTextOnScreenBuffer(1,visuals->VariableText, 255, 255, 255, 0, 520, 350, TextLeftX);
				SDL_Flip(visuals->Screen);
			}
			if (tetri_EnginE->FlashAnimationTimerLevelUp > -1)  tetri_EnginE->FlashAnimationTimerLevelUp--;
		}
		else
		{
			if (tetri_EnginE->WhichAnimationToDisplay == FlashCompletedLines)
			{
				tetri_EnginE->FlashCompletedLinesOnScreen();
			}
			else if (tetri_EnginE->WhichAnimationToDisplay == ClearCompletedLines)
			{
				tetri_EnginE->ClearCompletedLinesOnScreen();
			}

			if (tetri_EnginE->FlashAnimationTimer > -1)  tetri_EnginE->FlashAnimationTimer--;

			if  (tetri_EnginE->FlashAnimationTimer == -1)  tetri_EnginE->WhichAnimationToDisplay = -1;
		}

	}
	else
	{
		visuals->DrawTextOnScreenBuffer(1,"GAME PAUSED", 255, 255, 255, 0, 80, 280, TextLeftX);
		visuals->DrawTextOnScreenBuffer(1,"Press [SPACE] To Play", 255, 255, 255, 0, 30, 320, TextLeftX);
		SDL_Flip(visuals->Screen);
		if (control->KeyOnKeyboardPressedByUser == ' ')
		{
			game->PAUSEgame = false;
			audio->PlayDigitalSoundFX(6);
			Mix_ResumeMusic();
			control->DelayUserInput = 7;
		}
	}
}

//-------------------------------------------------------------------------------------------------
void CheckForNewHighScore(void)
{
Uint8 highScoresIndex;

	if (tetri_EnginE->Score >= tetri_EnginE->HishScoresScore[tetri_EnginE->GameMode][0])
		tetri_EnginE->NewHighScoreIndex = 0;
	else if (tetri_EnginE->Score >= tetri_EnginE->HishScoresScore[tetri_EnginE->GameMode][1])
		tetri_EnginE->NewHighScoreIndex = 1;
	else if (tetri_EnginE->Score >= tetri_EnginE->HishScoresScore[tetri_EnginE->GameMode][2])
		tetri_EnginE->NewHighScoreIndex = 2;
	else if (tetri_EnginE->Score >= tetri_EnginE->HishScoresScore[tetri_EnginE->GameMode][3])
		tetri_EnginE->NewHighScoreIndex = 3;
	else if (tetri_EnginE->Score >= tetri_EnginE->HishScoresScore[tetri_EnginE->GameMode][4])
		tetri_EnginE->NewHighScoreIndex = 4;
	else  tetri_EnginE->NewHighScoreIndex = 5;

	if (tetri_EnginE->NewHighScoreIndex > 4)  return;

	for (highScoresIndex =  4; highScoresIndex > tetri_EnginE->NewHighScoreIndex; highScoresIndex--)
	{
		strcpy(tetri_EnginE->HighScoresName[tetri_EnginE->GameMode][highScoresIndex], tetri_EnginE->HighScoresName[tetri_EnginE->GameMode][highScoresIndex-1]);
		tetri_EnginE->HighScoresLevel[tetri_EnginE->GameMode][highScoresIndex] = tetri_EnginE->HighScoresLevel[tetri_EnginE->GameMode][highScoresIndex-1];
		tetri_EnginE->HishScoresLines[tetri_EnginE->GameMode][highScoresIndex] = tetri_EnginE->HishScoresLines[tetri_EnginE->GameMode][highScoresIndex-1];
		tetri_EnginE->HishScoresScore[tetri_EnginE->GameMode][highScoresIndex] = tetri_EnginE->HishScoresScore[tetri_EnginE->GameMode][highScoresIndex-1];
	}

	for (Uint8 index = 0; index < 12; index++)
	{
		tetri_EnginE->HighScoresName[tetri_EnginE->GameMode][highScoresIndex][index] = (char) NULL;
	}

	tetri_EnginE->HighScoresLevel[tetri_EnginE->GameMode][highScoresIndex] = tetri_EnginE->Level;
	tetri_EnginE->HishScoresLines[tetri_EnginE->GameMode][highScoresIndex] = tetri_EnginE->Lines;
	tetri_EnginE->HishScoresScore[tetri_EnginE->GameMode][highScoresIndex] = tetri_EnginE->Score;
}

//-------------------------------------------------------------------------------------------------
void DisplayGameOverScreen(void)
{
    if (game->EXITgame == true) return;

	if (tetri_EnginE->FlashAnimationTimer == 0)
	{
		if (tetri_EnginE->GameOverDisplayFrame == 0 || tetri_EnginE->GameOverDisplayFrame == 2 || tetri_EnginE->GameOverDisplayFrame == 4 || tetri_EnginE->GameOverDisplayFrame == 6)
		{
			tetri_EnginE->DrawEntirePlayfieldScreenOntoScreenBuffer(false);
			SDL_Flip(visuals->Screen);
			audio->PlayDigitalSoundFX(0);
		}
		else if (tetri_EnginE->GameOverDisplayFrame == 1 || tetri_EnginE->GameOverDisplayFrame == 3 || tetri_EnginE->GameOverDisplayFrame == 5 || tetri_EnginE->GameOverDisplayFrame == 7)
		{
			tetri_EnginE->DrawEntirePlayfieldScreenOntoScreenBuffer(true);
			SDL_Flip(visuals->Screen);
			audio->PlayDigitalSoundFX(0);
		}
		else if (tetri_EnginE->GameOverDisplayFrame == 8)
		{
			visuals->DrawTextOnScreenBuffer(1,"G", 255, 255, 255, 0, 105, 300, TextLeftX);
			SDL_Flip(visuals->Screen);
			audio->PlayDigitalSoundFX(0);
		}
		else if (tetri_EnginE->GameOverDisplayFrame == 9)
		{
			visuals->DrawTextOnScreenBuffer(1,"GA", 255, 255, 255, 0, 105, 300, TextLeftX);
			SDL_Flip(visuals->Screen);
			audio->PlayDigitalSoundFX(0);
		}
		else if (tetri_EnginE->GameOverDisplayFrame == 10)
		{
			visuals->DrawTextOnScreenBuffer(1,"GAM", 255, 255, 255, 0, 105, 300, TextLeftX);
			SDL_Flip(visuals->Screen);
			audio->PlayDigitalSoundFX(0);
		}
		else if (tetri_EnginE->GameOverDisplayFrame == 11)
		{
			visuals->DrawTextOnScreenBuffer(1,"GAME", 255, 255, 255, 0, 105, 300, TextLeftX);
			SDL_Flip(visuals->Screen);
			audio->PlayDigitalSoundFX(0);
		}
		else if (tetri_EnginE->GameOverDisplayFrame == 12)
		{
			visuals->DrawTextOnScreenBuffer(1,"GAME ", 255, 255, 255, 0, 105, 300, TextLeftX);
			SDL_Flip(visuals->Screen);
			audio->PlayDigitalSoundFX(0);
		}
		else if (tetri_EnginE->GameOverDisplayFrame == 13)
		{
			visuals->DrawTextOnScreenBuffer(1,"GAME O", 255, 255, 255, 0, 105, 300, TextLeftX);
			SDL_Flip(visuals->Screen);
			audio->PlayDigitalSoundFX(0);
		}
		else if (tetri_EnginE->GameOverDisplayFrame == 14)
		{
			visuals->DrawTextOnScreenBuffer(1,"GAME OV", 255, 255, 255, 0, 105, 300, TextLeftX);
			SDL_Flip(visuals->Screen);
			audio->PlayDigitalSoundFX(0);
		}
		else if (tetri_EnginE->GameOverDisplayFrame == 15)
		{
			visuals->DrawTextOnScreenBuffer(1,"GAME OVE", 255, 255, 255, 0, 105, 300, TextLeftX);
			SDL_Flip(visuals->Screen);
			audio->PlayDigitalSoundFX(0);
		}
		else if (tetri_EnginE->GameOverDisplayFrame == 16)
		{
			visuals->DrawTextOnScreenBuffer(1,"GAME OVER", 255, 255, 255, 0, 105, 300, TextLeftX);
			SDL_Flip(visuals->Screen);
			audio->PlayDigitalSoundFX(4);
		}
		else if (tetri_EnginE->GameOverDisplayFrame == 17)
		{
			audio->PlayDigitalSoundFX(8);
		}
		else if (tetri_EnginE->GameOverDisplayFrame == 24)
		{
			visuals->FadeOutScreenBuffer();
			game->GameScreen = StaffScreen;
		}

		tetri_EnginE->FlashAnimationTimer = 5;
	}

	if (tetri_EnginE->FlashAnimationTimer > 0)  tetri_EnginE->FlashAnimationTimer--;
	if (tetri_EnginE->FlashAnimationTimer == 0)  tetri_EnginE->GameOverDisplayFrame++;
}

//-------------------------------------------------------------------------------------------------
void DisplayHighScoresScreen(void)
{
    if (game->EXITgame == true) return;

	if (game->GameScreenDisplayed == false)
	{
		if (tetri_EnginE->DisplayBackground == 0)
		{
			SDL_BlitSurface(visuals->KremlinAlphaDark, NULL, visuals->Screen, NULL);
		}
		else  visuals->EraseScreenBufferWithColor(0, 0, 0);

		visuals->DrawTextOnScreenBuffer(1,"HIGH SCORES", 255, 255, 0, 0, 0, 2, TextCenterX);
		visuals->DrawTextOnScreenBuffer(1,"__________________________________", 255, 255, 0, 0, 0, 10, TextCenterX);

		if (tetri_EnginE->GameMode == OriginalMode)
			visuals->DrawTextOnScreenBuffer(1,"Original Mode", 255, 255, 0, 0, 0, 60, TextCenterX);
		else if (tetri_EnginE->GameMode == Challenge25LineMode)
			visuals->DrawTextOnScreenBuffer(1,"25 Line Challenge Mode", 255, 255, 0, 0, 0, 60, TextCenterX);
		else if (tetri_EnginE->GameMode == TimeAttack30Mode)
			visuals->DrawTextOnScreenBuffer(1,"Time Attack 30 Mode", 255, 255, 0, 0, 0, 60, TextCenterX);
		else if (tetri_EnginE->GameMode == TimeAttack60Mode)
			visuals->DrawTextOnScreenBuffer(1,"Time Attack 60 Mode", 255, 255, 0, 0, 0, 60, TextCenterX);
		else if (tetri_EnginE->GameMode == TimeAttack120Mode)
			visuals->DrawTextOnScreenBuffer(1,"Time Attack 120 Mode", 255, 255, 0, 0, 0, 60, TextCenterX);
		else if (tetri_EnginE->GameMode == GarbageMode)
			visuals->DrawTextOnScreenBuffer(1,"Garbage Mode", 255, 255, 0, 0, 0, 60, TextCenterX);
		else if (tetri_EnginE->GameMode == CrisisMode)
			visuals->DrawTextOnScreenBuffer(1,"Crisis+Mode", 255, 255, 0, 0, 0, 60, TextCenterX);

		visuals->DrawTextOnScreenBuffer(1,"Name", 255, 255, 0, 0, 40, 120, TextLeftX);
		visuals->DrawTextOnScreenBuffer(1,"Level", 255, 255, 0, 0, 270, 120, TextLeftX);
		visuals->DrawTextOnScreenBuffer(1,"Lines", 255, 255, 0, 0, 370, 120, TextLeftX);
		visuals->DrawTextOnScreenBuffer(1,"Score", 255, 255, 0, 0, 470, 120, TextLeftX);
//------------------------------------------
		visuals->DrawTextOnScreenBuffer(1,"1.", 255, 255, 0, 0, 5, 170, TextLeftX);
		visuals->DrawTextOnScreenBuffer(1,&tetri_EnginE->HighScoresName[tetri_EnginE->GameMode][0][0], 255, 255, 0, 0, 40, 170, TextLeftX);

		if ( (tetri_EnginE->GameMode == CrisisMode)&&(tetri_EnginE->HighScoresLevel[tetri_EnginE->GameMode][0] == 10) )
		{
			visuals->DrawTextOnScreenBuffer(1,"WON!", 255, 255, 0, 0, 270, 170, TextLeftX);
		}
		else
		{
			sprintf(visuals->VariableText, "%d", tetri_EnginE->HighScoresLevel[tetri_EnginE->GameMode][0]);
			visuals->DrawTextOnScreenBuffer(1,visuals->VariableText, 255, 255, 0, 0, 270, 170, TextLeftX);
		}

		sprintf(visuals->VariableText, "%d", tetri_EnginE->HishScoresLines[tetri_EnginE->GameMode][0]);
		visuals->DrawTextOnScreenBuffer(1,visuals->VariableText, 255, 255, 0, 0, 370, 170, TextLeftX);
		sprintf(visuals->VariableText, "%d", tetri_EnginE->HishScoresScore[tetri_EnginE->GameMode][0]);
		visuals->DrawTextOnScreenBuffer(1,visuals->VariableText, 255, 255, 0, 0, 470, 170, TextLeftX);
//------------------------------------------
		visuals->DrawTextOnScreenBuffer(1,"2.", 255, 255, 0, 0, 5, 250, TextLeftX);
		visuals->DrawTextOnScreenBuffer(1,&tetri_EnginE->HighScoresName[tetri_EnginE->GameMode][1][0], 255, 255, 0, 0, 40, 250, TextLeftX);

		if ( (tetri_EnginE->GameMode == CrisisMode)&&(tetri_EnginE->HighScoresLevel[tetri_EnginE->GameMode][1] == 10) )
		{
			visuals->DrawTextOnScreenBuffer(1,"WON!", 255, 255, 0, 0, 270, 250, TextLeftX);
		}
		else
		{
			sprintf(visuals->VariableText, "%d", tetri_EnginE->HighScoresLevel[tetri_EnginE->GameMode][1]);
			visuals->DrawTextOnScreenBuffer(1,visuals->VariableText, 255, 255, 0, 0, 270, 250, TextLeftX);
		}

		sprintf(visuals->VariableText, "%d", tetri_EnginE->HishScoresLines[tetri_EnginE->GameMode][1]);
		visuals->DrawTextOnScreenBuffer(1,visuals->VariableText, 255, 255, 0, 0, 370, 250, TextLeftX);
		sprintf(visuals->VariableText, "%d", tetri_EnginE->HishScoresScore[tetri_EnginE->GameMode][1]);
		visuals->DrawTextOnScreenBuffer(1,visuals->VariableText, 255, 255, 0, 0, 470, 250, TextLeftX);
//------------------------------------------
		visuals->DrawTextOnScreenBuffer(1,"3.", 255, 255, 0, 0, 5, 330, TextLeftX);
		visuals->DrawTextOnScreenBuffer(1,&tetri_EnginE->HighScoresName[tetri_EnginE->GameMode][2][0], 255, 255, 0, 0, 40, 330, TextLeftX);

		if ( (tetri_EnginE->GameMode == CrisisMode)&&(tetri_EnginE->HighScoresLevel[tetri_EnginE->GameMode][2] == 10) )
		{
			visuals->DrawTextOnScreenBuffer(1,"WON!", 255, 255, 0, 0, 270, 330, TextLeftX);
		}
		else
		{
			sprintf(visuals->VariableText, "%d", tetri_EnginE->HighScoresLevel[tetri_EnginE->GameMode][2]);
			visuals->DrawTextOnScreenBuffer(1,visuals->VariableText, 255, 255, 0, 0, 270, 330, TextLeftX);
		}

		sprintf(visuals->VariableText, "%d", tetri_EnginE->HishScoresLines[tetri_EnginE->GameMode][2]);
		visuals->DrawTextOnScreenBuffer(1,visuals->VariableText, 255, 255, 0, 0, 370, 330, TextLeftX);
		sprintf(visuals->VariableText, "%d", tetri_EnginE->HishScoresScore[tetri_EnginE->GameMode][2]);
		visuals->DrawTextOnScreenBuffer(1,visuals->VariableText, 255, 255, 0, 0, 470, 330, TextLeftX);
//------------------------------------------
		visuals->DrawTextOnScreenBuffer(1,"4.", 255, 255, 0, 0, 5, 410, TextLeftX);
		visuals->DrawTextOnScreenBuffer(1,&tetri_EnginE->HighScoresName[tetri_EnginE->GameMode][3][0], 255, 255, 0, 0, 40, 410, TextLeftX);

		if ( (tetri_EnginE->GameMode == CrisisMode)&&(tetri_EnginE->HighScoresLevel[tetri_EnginE->GameMode][3] == 10) )
		{
			visuals->DrawTextOnScreenBuffer(1,"WON!", 255, 255, 0, 0, 270, 410, TextLeftX);
		}
		else
		{
			sprintf(visuals->VariableText, "%d", tetri_EnginE->HighScoresLevel[tetri_EnginE->GameMode][3]);
			visuals->DrawTextOnScreenBuffer(1,visuals->VariableText, 255, 255, 0, 0, 270, 410, TextLeftX);
		}

		sprintf(visuals->VariableText, "%d", tetri_EnginE->HishScoresLines[tetri_EnginE->GameMode][3]);
		visuals->DrawTextOnScreenBuffer(1,visuals->VariableText, 255, 255, 0, 0, 370, 410, TextLeftX);
		sprintf(visuals->VariableText, "%d", tetri_EnginE->HishScoresScore[tetri_EnginE->GameMode][3]);
		visuals->DrawTextOnScreenBuffer(1,visuals->VariableText, 255, 255, 0, 0, 470, 410, TextLeftX);
//------------------------------------------
		visuals->DrawTextOnScreenBuffer(1,"5.", 255, 255, 0, 0, 5, 490, TextLeftX);
		visuals->DrawTextOnScreenBuffer(1,&tetri_EnginE->HighScoresName[tetri_EnginE->GameMode][4][0], 255, 255, 0, 0, 40, 490, TextLeftX);

		if ( (tetri_EnginE->GameMode == CrisisMode)&&(tetri_EnginE->HighScoresLevel[tetri_EnginE->GameMode][4] == 10) )
		{
			visuals->DrawTextOnScreenBuffer(1,"WON!", 255, 255, 0, 0, 270, 490, TextLeftX);
		}
		else
		{
			sprintf(visuals->VariableText, "%d", tetri_EnginE->HighScoresLevel[tetri_EnginE->GameMode][4]);
			visuals->DrawTextOnScreenBuffer(1,visuals->VariableText, 255, 255, 0, 0, 270, 490, TextLeftX);
		}

		sprintf(visuals->VariableText, "%d", tetri_EnginE->HishScoresLines[tetri_EnginE->GameMode][4]);
		visuals->DrawTextOnScreenBuffer(1,visuals->VariableText, 255, 255, 0, 0, 370, 490, TextLeftX);
		sprintf(visuals->VariableText, "%d", tetri_EnginE->HishScoresScore[tetri_EnginE->GameMode][4]);
		visuals->DrawTextOnScreenBuffer(1,visuals->VariableText, 255, 255, 0, 0, 470, 490, TextLeftX);
//------------------------------------------
		if ( (tetri_EnginE->NewHighScoreFlashTimer > 10)
		   &&(tetri_EnginE->Score == tetri_EnginE->HishScoresScore[tetri_EnginE->GameMode][0])
		   &&(tetri_EnginE->Lines == tetri_EnginE->HishScoresLines[tetri_EnginE->GameMode][0])
		   &&(tetri_EnginE->Level == tetri_EnginE->HighScoresLevel[tetri_EnginE->GameMode][0]) )
		{
			visuals->DrawTextOnScreenBuffer(1,"1.", 255, 0, 0, 0, 5, 170, TextLeftX);
			visuals->DrawTextOnScreenBuffer(1,&tetri_EnginE->HighScoresName[tetri_EnginE->GameMode][0][0], 255, 0, 0, 0, 40, 170, TextLeftX);

		if ( (tetri_EnginE->GameMode == CrisisMode)&&(tetri_EnginE->HighScoresLevel[tetri_EnginE->GameMode][0] == 10) )
		{
			visuals->DrawTextOnScreenBuffer(1,"WON!", 255, 0, 0, 0, 270, 170, TextLeftX);
		}
		else
		{
			sprintf(visuals->VariableText, "%d", tetri_EnginE->HighScoresLevel[tetri_EnginE->GameMode][0]);
			visuals->DrawTextOnScreenBuffer(1,visuals->VariableText, 255, 0, 0, 0, 270, 170, TextLeftX);
		}

			sprintf(visuals->VariableText, "%d", tetri_EnginE->HishScoresLines[tetri_EnginE->GameMode][0]);
			visuals->DrawTextOnScreenBuffer(1,visuals->VariableText, 255, 0, 0, 0, 370, 170, TextLeftX);
			sprintf(visuals->VariableText, "%d", tetri_EnginE->HishScoresScore[tetri_EnginE->GameMode][0]);
			visuals->DrawTextOnScreenBuffer(1,visuals->VariableText, 255, 0, 0, 0, 470, 170, TextLeftX);
		}
//------------------------------------------
		else if ( (tetri_EnginE->NewHighScoreFlashTimer > 10)
		   &&(tetri_EnginE->Score == tetri_EnginE->HishScoresScore[tetri_EnginE->GameMode][1])
		   &&(tetri_EnginE->Lines == tetri_EnginE->HishScoresLines[tetri_EnginE->GameMode][1])
		   &&(tetri_EnginE->Level == tetri_EnginE->HighScoresLevel[tetri_EnginE->GameMode][1]) )
		{
			visuals->DrawTextOnScreenBuffer(1,"2.", 255, 0, 0, 0, 5, 250, TextLeftX);
			visuals->DrawTextOnScreenBuffer(1,&tetri_EnginE->HighScoresName[tetri_EnginE->GameMode][1][0], 255, 0, 0, 0, 40, 250, TextLeftX);

		if ( (tetri_EnginE->GameMode == CrisisMode)&&(tetri_EnginE->HighScoresLevel[tetri_EnginE->GameMode][1] == 10) )
		{
			visuals->DrawTextOnScreenBuffer(1,"WON!", 255, 0, 0, 0, 270, 250, TextLeftX);
		}
		else
		{
			sprintf(visuals->VariableText, "%d", tetri_EnginE->HighScoresLevel[tetri_EnginE->GameMode][1]);
			visuals->DrawTextOnScreenBuffer(1,visuals->VariableText, 255, 0, 0, 0, 270, 250, TextLeftX);
		}

			sprintf(visuals->VariableText, "%d", tetri_EnginE->HishScoresLines[tetri_EnginE->GameMode][1]);
			visuals->DrawTextOnScreenBuffer(1,visuals->VariableText, 255, 0, 0, 0, 370, 250, TextLeftX);
			sprintf(visuals->VariableText, "%d", tetri_EnginE->HishScoresScore[tetri_EnginE->GameMode][1]);
			visuals->DrawTextOnScreenBuffer(1,visuals->VariableText, 255, 0, 0, 0, 470, 250, TextLeftX);
		}
//------------------------------------------
		else if ( (tetri_EnginE->NewHighScoreFlashTimer > 10)
		   &&(tetri_EnginE->Score == tetri_EnginE->HishScoresScore[tetri_EnginE->GameMode][2])
		   &&(tetri_EnginE->Lines == tetri_EnginE->HishScoresLines[tetri_EnginE->GameMode][2])
		   &&(tetri_EnginE->Level == tetri_EnginE->HighScoresLevel[tetri_EnginE->GameMode][2]) )
		{
			visuals->DrawTextOnScreenBuffer(1,"3.", 255, 0, 0, 0, 5, 330, TextLeftX);
			visuals->DrawTextOnScreenBuffer(1,&tetri_EnginE->HighScoresName[tetri_EnginE->GameMode][2][0], 255, 0, 0, 0, 40, 330, TextLeftX);

		if ( (tetri_EnginE->GameMode == CrisisMode)&&(tetri_EnginE->HighScoresLevel[tetri_EnginE->GameMode][2] == 10) )
		{
			visuals->DrawTextOnScreenBuffer(1,"WON!", 255, 0, 0, 0, 270, 330, TextLeftX);
		}
		else
		{
			sprintf(visuals->VariableText, "%d", tetri_EnginE->HighScoresLevel[tetri_EnginE->GameMode][2]);
			visuals->DrawTextOnScreenBuffer(1,visuals->VariableText, 255, 0, 0, 0, 270, 330, TextLeftX);
		}

			sprintf(visuals->VariableText, "%d", tetri_EnginE->HishScoresLines[tetri_EnginE->GameMode][2]);
			visuals->DrawTextOnScreenBuffer(1,visuals->VariableText, 255, 0, 0, 0, 370, 330, TextLeftX);
			sprintf(visuals->VariableText, "%d", tetri_EnginE->HishScoresScore[tetri_EnginE->GameMode][2]);
			visuals->DrawTextOnScreenBuffer(1,visuals->VariableText, 255, 0, 0, 0, 470, 330, TextLeftX);
		}
//------------------------------------------
		else if ( (tetri_EnginE->NewHighScoreFlashTimer > 10)
		   &&(tetri_EnginE->Score == tetri_EnginE->HishScoresScore[tetri_EnginE->GameMode][3])
		   &&(tetri_EnginE->Lines == tetri_EnginE->HishScoresLines[tetri_EnginE->GameMode][3])
		   &&(tetri_EnginE->Level == tetri_EnginE->HighScoresLevel[tetri_EnginE->GameMode][3]) )
		{
			visuals->DrawTextOnScreenBuffer(1,"4.", 255, 0, 0, 0, 5, 410, TextLeftX);
			visuals->DrawTextOnScreenBuffer(1,&tetri_EnginE->HighScoresName[tetri_EnginE->GameMode][3][0], 255, 0, 0, 0, 40, 410, TextLeftX);

		if ( (tetri_EnginE->GameMode == CrisisMode)&&(tetri_EnginE->HighScoresLevel[tetri_EnginE->GameMode][3] == 10) )
		{
			visuals->DrawTextOnScreenBuffer(1,"WON!", 255, 0, 0, 0, 270, 410, TextLeftX);
		}
		else
		{
			sprintf(visuals->VariableText, "%d", tetri_EnginE->HighScoresLevel[tetri_EnginE->GameMode][3]);
			visuals->DrawTextOnScreenBuffer(1,visuals->VariableText, 255, 0, 0, 0, 270, 410, TextLeftX);
		}

			sprintf(visuals->VariableText, "%d", tetri_EnginE->HishScoresLines[tetri_EnginE->GameMode][3]);
			visuals->DrawTextOnScreenBuffer(1,visuals->VariableText, 255, 0, 0, 0, 370, 410, TextLeftX);
			sprintf(visuals->VariableText, "%d", tetri_EnginE->HishScoresScore[tetri_EnginE->GameMode][3]);
			visuals->DrawTextOnScreenBuffer(1,visuals->VariableText, 255, 0, 0, 0, 470, 410, TextLeftX);
		}
//------------------------------------------
		else if ( (tetri_EnginE->NewHighScoreFlashTimer > 10)
		   &&(tetri_EnginE->Score == tetri_EnginE->HishScoresScore[tetri_EnginE->GameMode][4])
		   &&(tetri_EnginE->Lines == tetri_EnginE->HishScoresLines[tetri_EnginE->GameMode][4])
		   &&(tetri_EnginE->Level == tetri_EnginE->HighScoresLevel[tetri_EnginE->GameMode][4]) )
		{
			visuals->DrawTextOnScreenBuffer(1,"5.", 255, 0, 0, 0, 5, 490, TextLeftX);
			visuals->DrawTextOnScreenBuffer(1,&tetri_EnginE->HighScoresName[tetri_EnginE->GameMode][4][0], 255, 0, 0, 0, 40, 490, TextLeftX);

		if ( (tetri_EnginE->GameMode == CrisisMode)&&(tetri_EnginE->HighScoresLevel[tetri_EnginE->GameMode][4] == 10) )
		{
			visuals->DrawTextOnScreenBuffer(1,"WON!", 255, 0, 0, 0, 270, 490, TextLeftX);
		}
		else
		{
			sprintf(visuals->VariableText, "%d", tetri_EnginE->HighScoresLevel[tetri_EnginE->GameMode][4]);
			visuals->DrawTextOnScreenBuffer(1,visuals->VariableText, 255, 0, 0, 0, 270, 490, TextLeftX);
		}

			sprintf(visuals->VariableText, "%d", tetri_EnginE->HishScoresLines[tetri_EnginE->GameMode][4]);
			visuals->DrawTextOnScreenBuffer(1,visuals->VariableText, 255, 0, 0, 0, 370, 490, TextLeftX);
			sprintf(visuals->VariableText, "%d", tetri_EnginE->HishScoresScore[tetri_EnginE->GameMode][4]);
			visuals->DrawTextOnScreenBuffer(1,visuals->VariableText, 255, 0, 0, 0, 470, 490, TextLeftX);
		}
//------------------------------------------
		if (game->CurrentlySelectedScreenOption == 0)
		{
			visuals->DrawTextOnScreenBuffer(1,"<=", 255, 255, 0, 0, 1, 60, TextLeftX);
			visuals->DrawTextOnScreenBuffer(1,"=>", 255, 255, 0, 0, 1, 60, TextRightX);
		}
		else if (game->CurrentlySelectedScreenOption == 1)
		{
			visuals->DrawTextOnScreenBuffer(1,"=>", 255, 255, 0, 0, 150, 596, TextLeftX);
			visuals->DrawTextOnScreenBuffer(1,"<=", 255, 255, 0, 0, 150, 596, TextRightX);
		}

		visuals->DrawTextOnScreenBuffer(1,"__________________________________", 255, 255, 0, 0, 0, 555, TextCenterX);
		buttons->SetUpNewButtonForUserInput(6, 1, 0, 596, 200, ButtonCenterX);

		SDL_Flip(visuals->Screen);
		game->GameScreenDisplayed = true;
	}

	tetri_EnginE->NewHighScoreFlashTimer++;
	if (tetri_EnginE->NewHighScoreFlashTimer > 20)  tetri_EnginE->NewHighScoreFlashTimer = 0;

	if ( (tetri_EnginE->NewHighScoreFlashTimer == 0)||(tetri_EnginE->NewHighScoreFlashTimer == 11) )
		game->GameScreenDisplayed = false;

	if (control->JoystickDirection[Any] == UP)
	{
		if (game->CurrentlySelectedScreenOption > 0)  game->CurrentlySelectedScreenOption--;
		else  game->CurrentlySelectedScreenOption = 1;
		game->GameScreenDisplayed = false;
		audio->PlayDigitalSoundFX(2);
	}
	else if (control->JoystickDirection[Any] == DOWN)
	{
		if (game->CurrentlySelectedScreenOption < 1)  game->CurrentlySelectedScreenOption++;
		else  game->CurrentlySelectedScreenOption = 0;
		game->GameScreenDisplayed = false;
		audio->PlayDigitalSoundFX(2);
	}
	else if ( (control->JoystickDirection[Any] == LEFT)&&(game->CurrentlySelectedScreenOption == 0) )
	{
		if (tetri_EnginE->GameMode > 0)  tetri_EnginE->GameMode--;
		else  tetri_EnginE->GameMode = 6;
		if (tetri_EnginE->GameMode == CrisisMode)
		{
			tetri_EnginE->NewGameGarbageLevel = 0;
			tetri_EnginE->NewGameStartingLevel = 0;
		}
		game->GameScreenDisplayed = false;
		audio->PlayDigitalSoundFX(2);
	}
	else if ( (control->JoystickDirection[Any] == RIGHT)&&(game->CurrentlySelectedScreenOption == 0) )
	{
		if (tetri_EnginE->GameMode < 6)  tetri_EnginE->GameMode++;
		else  tetri_EnginE->GameMode = 0;
		if (tetri_EnginE->GameMode == CrisisMode)
		{
			tetri_EnginE->NewGameGarbageLevel = 0;
			tetri_EnginE->NewGameStartingLevel = 0;
		}
		game->GameScreenDisplayed = false;
		audio->PlayDigitalSoundFX(2);
	}

	if (control->JoystickButton1[Mouse] == ON)
	{
		if ( (control->MouseX < 320)&&(control->MouseY > 49 && control->MouseY < 115) )
		{
			game->CurrentlySelectedScreenOption = 0;
			if (tetri_EnginE->GameMode > 0)  tetri_EnginE->GameMode--;
			else  tetri_EnginE->GameMode = 6;
			if (tetri_EnginE->GameMode == CrisisMode)
			{
				tetri_EnginE->NewGameGarbageLevel = 0;
				tetri_EnginE->NewGameStartingLevel = 0;
			}
			game->GameScreenDisplayed = false;
			audio->PlayDigitalSoundFX(2);
		}
		else if ( (control->MouseX > 320)&&(control->MouseY > 49 && control->MouseY < 115) )
		{
			game->CurrentlySelectedScreenOption = 0;
			if (tetri_EnginE->GameMode < 6)  tetri_EnginE->GameMode++;
			else  tetri_EnginE->GameMode = 0;
			if (tetri_EnginE->GameMode == CrisisMode)
			{
				tetri_EnginE->NewGameGarbageLevel = 0;
				tetri_EnginE->NewGameStartingLevel = 0;
			}
			game->GameScreenDisplayed = false;
			audio->PlayDigitalSoundFX(2);
		}
	}

	if (buttons->ButtonClickedByUser(6) == true)
	{
		game->GameScreenDisplayed = false;
		visuals->FadeOutScreenBuffer();
		buttons->DeleteAllRegisteredButtons();
		audio->PlayMusic(1,Loop);
		game->GameScreen = TitleScreen;
		game->CurrentlySelectedScreenOption = 0;
	}
}

//-------------------------------------------------------------------------------------------------
void DisplayNewHighScoreNameInputScreen(void)
{
    if (game->EXITgame == true) return;

	if (game->GameScreenDisplayed == false)
	{
		if (tetri_EnginE->DisplayBackground == 0)
		{
			SDL_BlitSurface(visuals->KremlinAlphaDark, NULL, visuals->Screen, NULL);
		}
		else  visuals->EraseScreenBufferWithColor(0, 0, 0);

		visuals->DrawTextOnScreenBuffer(1,"HIGH SCORES", 255, 255, 0, 0, 0, 2, TextCenterX);
		visuals->DrawTextOnScreenBuffer(1,"__________________________________", 255, 255, 0, 0, 0, 10, TextCenterX);

		visuals->DrawTextOnScreenBuffer(1,"Congratulations...", 255, 255, 0, 0, 0, 90, TextCenterX);
		visuals->DrawTextOnScreenBuffer(1,"You achieved a new high score!", 255, 255, 0, 0, 0, 140, TextCenterX);

		visuals->DrawTextOnScreenBuffer(1,"Enter your name using the keyboard:", 255, 255, 0, 0, 0, 230, TextCenterX);

		visuals->DrawTextOnScreenBuffer(1,&tetri_EnginE->HighScoresName[tetri_EnginE->GameMode][tetri_EnginE->NewHighScoreIndex][0], 255, 255, 0, 0, 0, 330, TextCenterX);

		visuals->DrawTextOnScreenBuffer(1,"Press [Backspace] key to erase.", 255, 255, 0, 0, 0, 440, TextCenterX);
		visuals->DrawTextOnScreenBuffer(1,"Press [Enter] key when done.", 255, 255, 0, 0, 0, 510, TextCenterX);

		if (game->CurrentlySelectedScreenOption == 1)
		{
			visuals->DrawTextOnScreenBuffer(1,"=>", 255, 255, 0, 0, 150, 596, TextLeftX);
			visuals->DrawTextOnScreenBuffer(1,"<=", 255, 255, 0, 0, 150, 596, TextRightX);
		}

		visuals->DrawTextOnScreenBuffer(1,"__________________________________", 255, 255, 0, 0, 0, 555, TextCenterX);
		buttons->SetUpNewButtonForUserInput(5, 1, 0, 596, 200, ButtonCenterX);

		SDL_Flip(visuals->Screen);
		game->GameScreenDisplayed = true;
	}

	if (control->KeyOnKeyboardPressedByUser == '<')
	{
		tetri_EnginE->HighScoresName[tetri_EnginE->GameMode][tetri_EnginE->NewHighScoreIndex][tetri_EnginE->NewHighScoreNameIndex] = (char) NULL;//' ';
		if (tetri_EnginE->NewHighScoreNameIndex > 0)  tetri_EnginE->NewHighScoreNameIndex--;
		tetri_EnginE->HighScoresName[tetri_EnginE->GameMode][tetri_EnginE->NewHighScoreIndex][tetri_EnginE->NewHighScoreNameIndex] = (char) NULL;//' ';
		game->GameScreenDisplayed = false;
		audio->PlayDigitalSoundFX(2);
		control->DelayUserInput = 5;
	}
	else if ( (control->KeyOnKeyboardPressedByUser != '>')&&(control->KeyOnKeyboardPressedByUser != (char)NULL) )
	{
		if (tetri_EnginE->NewHighScoreNameIndex < 10)
		{
			tetri_EnginE->HighScoresName[tetri_EnginE->GameMode][tetri_EnginE->NewHighScoreIndex][tetri_EnginE->NewHighScoreNameIndex] = control->KeyOnKeyboardPressedByUser;
			tetri_EnginE->NewHighScoreNameIndex++;
			game->GameScreenDisplayed = false;
			audio->PlayDigitalSoundFX(2);
			control->DelayUserInput = 5;
		}
	}

	if (buttons->ButtonClickedByUser(5) == true)
	{
		control->DelayUserInput = 20;
		game->GameScreenDisplayed = false;
		visuals->FadeOutScreenBuffer();
		buttons->DeleteAllRegisteredButtons();
		audio->PlayMusic(12,Loop);
		game->GameScreen = HighScoresScreen;
		game->CurrentlySelectedScreenOption = 1;
	}
}

//-------------------------------------------------------------------------------------------------
void DisplayStaffScreen(void)
{
Uint8 counter;

    if (game->EXITgame == true) return;

	if (tetri_EnginE->GameMode != CrisisMode)  game->StaffLineY[32] = -61;

	if ( (tetri_EnginE->CrisisModeWon != true)&&(tetri_EnginE->EasterEggStaffRoll != true) )  game->StaffLineY[34] = -61;

	if (game->StaffLineY[0] == 650)
	{
		visuals->EraseScreenBufferWithColor(0, 0, 0);
		audio->PlayMusic(16, 1);
	}

	visuals->DrawTextOnScreenBufferFast(1,"TetriCrisis 100% Version 5.9 Remix", 0, 0, 0, 0, 0, game->StaffLineY[0], TextCenterX);
	visuals->DrawTextOnScreenBufferFast(1,"STAFF:", 0, 0, 0, 0, 0, game->StaffLineY[1], TextCenterX);

	visuals->DrawTextOnScreenBufferFast(1,"Original Tetris(R) Concept:", 0, 0, 0, 0, 0, game->StaffLineY[2], TextCenterX);
	visuals->DrawTextOnScreenBufferFast(1,"Alexey Pajitnov", 0, 0, 0, 0, 0, game->StaffLineY[3], TextCenterX);

	visuals->DrawTextOnScreenBufferFast(1,"Visual C++ Development I.D.E.:", 0, 0, 0, 0, 0, game->StaffLineY[4], TextCenterX);
	visuals->DrawTextOnScreenBufferFast(1,"Code::Blocks 8.02", 0, 0, 0, 0, 0, game->StaffLineY[5], TextCenterX);

	visuals->DrawTextOnScreenBufferFast(1,"Video Game Engine:", 0, 0, 0, 0, 0, game->StaffLineY[6], TextCenterX);
	visuals->DrawTextOnScreenBufferFast(1,"JeZ+Lee's SDL(R)PerfecT+EnginE 5.0", 0, 0, 0, 0, 0, game->StaffLineY[7], TextCenterX);

	visuals->DrawTextOnScreenBufferFast(1,"Tetris(R) Gameplay Engine:", 0, 0, 0, 0, 0, game->StaffLineY[8], TextCenterX);
	visuals->DrawTextOnScreenBufferFast(1,"JeZ+Lee's T+B///PerfecT+EnginE 5.0", 0, 0, 0, 0, 0, game->StaffLineY[9], TextCenterX);

	visuals->DrawTextOnScreenBufferFast(1,"Lead Game Designer:", 0, 0, 0, 0, 0, game->StaffLineY[10], TextCenterX);
	visuals->DrawTextOnScreenBufferFast(1,"Jesse ''JeZ+Lee'' Palser", 0, 0, 0, 0, 0, game->StaffLineY[11], TextCenterX);

	visuals->DrawTextOnScreenBufferFast(1,"Lead Game Programmer:", 0, 0, 0, 0, 0, game->StaffLineY[12], TextCenterX);
	visuals->DrawTextOnScreenBufferFast(1,"Jesse ''JeZ+Lee'' Palser", 0, 0, 0, 0, 0, game->StaffLineY[13], TextCenterX);

	visuals->DrawTextOnScreenBufferFast(1,"Lead Game Beta Tester:", 0, 0, 0, 0, 0, game->StaffLineY[14], TextCenterX);
	visuals->DrawTextOnScreenBufferFast(1,"Jesse ''JeZ+Lee'' Palser", 0, 0, 0, 0, 0, game->StaffLineY[15], TextCenterX);

	visuals->DrawTextOnScreenBufferFast(1,"Linux OS Porter:", 0, 0, 0, 0, 0, game->StaffLineY[16], TextCenterX);
	visuals->DrawTextOnScreenBufferFast(1,"Matt ''mattmatteh'' Hull", 0, 0, 0, 0, 0, game->StaffLineY[17], TextCenterX);

	visuals->DrawTextOnScreenBufferFast(1,"Mac OS X Porter:", 0, 0, 0, 0, 0, game->StaffLineY[18], TextCenterX);
//	visuals->DrawTextOnScreenBufferFast(1,"Michael ''mc'' Otteneder", 0, 0, 0, 0, 0, game->StaffLineY[19], TextCenterX);
	visuals->DrawTextOnScreenBufferFast(1,"Matt ''mattmatteh'' Hull", 0, 0, 0, 0, 0, game->StaffLineY[19], TextCenterX);

	visuals->DrawTextOnScreenBufferFast(1,"Music Soundtrack Composer:", 0, 0, 0, 0, 0, game->StaffLineY[20], TextCenterX);
	visuals->DrawTextOnScreenBufferFast(1,"D.J. Fading Twilight", 0, 0, 0, 0, 0, game->StaffLineY[21], TextCenterX);

	visuals->DrawTextOnScreenBufferFast(1,"Final Countdown MOD Composer:", 0, 0, 0, 0, 0, game->StaffLineY[22], TextCenterX);
	visuals->DrawTextOnScreenBufferFast(1,"Mendim Chengaj", 0, 0, 0, 0, 0, game->StaffLineY[23], TextCenterX);

	visuals->DrawTextOnScreenBufferFast(1,"Graphic Artist:", 0, 0, 0, 0, 0, game->StaffLineY[24], TextCenterX);
	visuals->DrawTextOnScreenBufferFast(1,"Jesse ''JeZ+Lee'' Palser", 0, 0, 0, 0, 0, game->StaffLineY[25], TextCenterX);

	visuals->DrawTextOnScreenBufferFast(1,"Sound Effects Artist:", 0, 0, 0, 0, 0, game->StaffLineY[26], TextCenterX);
	visuals->DrawTextOnScreenBufferFast(1,"Jesse ''JeZ+Lee'' Palser", 0, 0, 0, 0, 0, game->StaffLineY[27], TextCenterX);

	visuals->DrawTextOnScreenBufferFast(1,"Support Beta Testers:", 0, 0, 0, 0, 0, game->StaffLineY[28], TextCenterX);
	visuals->DrawTextOnScreenBufferFast(1,"You!", 0, 0, 0, 0, 0, game->StaffLineY[29], TextCenterX);

	visuals->DrawTextOnScreenBufferFast(1,"You have won:", 0, 0, 0, 0, 0, game->StaffLineY[30], TextCenterX);
	visuals->DrawTextOnScreenBufferFast(1,"TetriCrisis 100% Version 5.9 Remix", 0, 0, 0, 0, 0, game->StaffLineY[31], TextCenterX);
	visuals->DrawTextOnScreenBufferFast(1,"A 100% by JeZ+Lee!", 0, 0, 0, 0, 0, game->StaffLineY[32], TextCenterX);
	visuals->DrawTextOnScreenBufferFast(1,"Thanks for playing...", 0, 0, 0, 0, 0, game->StaffLineY[33], TextCenterX);

	if (tetri_EnginE->CrisisModeWon != true)  visuals->DrawTextOnScreenBufferFast(1,"Now win without cheating!", 0, 0, 0, 0, 0, game->StaffLineY[34], TextCenterX);
	else  visuals->DrawTextOnScreenBufferFast(1,"FUCK YOU E.A.Games and Handmark!!!", 0, 0, 0, 0, 0, game->StaffLineY[34], TextCenterX);

	for (counter = 0; counter < 35; counter++)
		game->StaffLineY[counter]-=1;

	visuals->DrawTextOnScreenBufferFast(1,"TetriCrisis 100% Version 5.9 Remix", 255, 255, 0, 0, 0, game->StaffLineY[0], TextCenterX);
	visuals->DrawTextOnScreenBufferFast(1,"STAFF:", 255, 255, 255, 0, 0, game->StaffLineY[1], TextCenterX);

	visuals->DrawTextOnScreenBufferFast(1,"Original Tetris(R) Concept:", 255, 255, 0, 0, 0, game->StaffLineY[2], TextCenterX);
	visuals->DrawTextOnScreenBufferFast(1,"Alexey Pajitnov", 255, 255, 255, 0, 0, game->StaffLineY[3], TextCenterX);

	visuals->DrawTextOnScreenBufferFast(1,"Visual C++ Development I.D.E.:", 255, 255, 0, 0, 0, game->StaffLineY[4], TextCenterX);
	visuals->DrawTextOnScreenBufferFast(1,"Code::Blocks 8.02", 255, 255, 255, 0, 0, game->StaffLineY[5], TextCenterX);

	visuals->DrawTextOnScreenBufferFast(1,"Video Game Engine:", 255, 255, 0, 0, 0, game->StaffLineY[6], TextCenterX);
	visuals->DrawTextOnScreenBufferFast(1,"JeZ+Lee's SDL(R)PerfecT+EnginE 5.0", 255, 255, 255, 0, 0, game->StaffLineY[7], TextCenterX);

	visuals->DrawTextOnScreenBufferFast(1,"Tetris(R) Gameplay Engine:", 255, 255, 0, 0, 0, game->StaffLineY[8], TextCenterX);
	visuals->DrawTextOnScreenBufferFast(1,"JeZ+Lee's T+B///PerfecT+EnginE 5.0", 255, 255, 255, 0, 0, game->StaffLineY[9], TextCenterX);

	visuals->DrawTextOnScreenBufferFast(1,"Lead Game Designer:", 255, 255, 0, 0, 0, game->StaffLineY[10], TextCenterX);
	visuals->DrawTextOnScreenBufferFast(1,"Jesse ''JeZ+Lee'' Palser", 255, 255, 255, 0, 0, game->StaffLineY[11], TextCenterX);

	visuals->DrawTextOnScreenBufferFast(1,"Lead Game Programmer:", 255, 255, 0, 0, 0, game->StaffLineY[12], TextCenterX);
	visuals->DrawTextOnScreenBufferFast(1,"Jesse ''JeZ+Lee'' Palser", 255, 255, 255, 0, 0, game->StaffLineY[13], TextCenterX);

	visuals->DrawTextOnScreenBufferFast(1,"Lead Game Beta Tester:", 255, 255, 0, 0, 0, game->StaffLineY[14], TextCenterX);
	visuals->DrawTextOnScreenBufferFast(1,"Jesse ''JeZ+Lee'' Palser", 255, 255, 255, 0, 0, game->StaffLineY[15], TextCenterX);

	visuals->DrawTextOnScreenBufferFast(1,"Linux OS Porter:", 255, 255, 0, 0, 0, game->StaffLineY[16], TextCenterX);
	visuals->DrawTextOnScreenBufferFast(1,"Matt ''mattmatteh'' Hull", 255, 255, 255, 0, 0, game->StaffLineY[17], TextCenterX);

	visuals->DrawTextOnScreenBufferFast(1,"Mac OS X Porter:", 255, 255, 0, 0, 0, game->StaffLineY[18], TextCenterX);
//	visuals->DrawTextOnScreenBufferFast(1,"Michael ''mc'' Otteneder", 255, 255, 255, 0, 0, game->StaffLineY[19], TextCenterX);
	visuals->DrawTextOnScreenBufferFast(1,"Matt ''mattmatteh'' Hull", 255, 255, 255, 0, 0, game->StaffLineY[19], TextCenterX);

	visuals->DrawTextOnScreenBufferFast(1,"Music Soundtrack Composer:", 255, 255, 0, 0, 0, game->StaffLineY[20], TextCenterX);
	visuals->DrawTextOnScreenBufferFast(1,"D.J. Fading Twilight", 255, 255, 255, 0, 0, game->StaffLineY[21], TextCenterX);

	visuals->DrawTextOnScreenBufferFast(1,"Final Countdown MOD Composer:", 255, 255, 0, 0, 0, game->StaffLineY[22], TextCenterX);
	visuals->DrawTextOnScreenBufferFast(1,"Mendim Chengaj", 255, 255, 255, 0, 0, game->StaffLineY[23], TextCenterX);

	visuals->DrawTextOnScreenBufferFast(1,"Graphic Artist:", 255, 255, 0, 0, 0, game->StaffLineY[24], TextCenterX);
	visuals->DrawTextOnScreenBufferFast(1,"Jesse ''JeZ+Lee'' Palser", 255, 255, 255, 0, 0, game->StaffLineY[25], TextCenterX);

	visuals->DrawTextOnScreenBufferFast(1,"Sound Effects Artist:", 255, 255, 0, 0, 0, game->StaffLineY[26], TextCenterX);
	visuals->DrawTextOnScreenBufferFast(1,"Jesse ''JeZ+Lee'' Palser", 255, 255, 255, 0, 0, game->StaffLineY[27], TextCenterX);

	visuals->DrawTextOnScreenBufferFast(1,"Support Beta Testers:", 255, 255, 0, 0, 0, game->StaffLineY[28], TextCenterX);
	visuals->DrawTextOnScreenBufferFast(1,"You!", 255, 255, 255, 0, 0, game->StaffLineY[29], TextCenterX);

	visuals->DrawTextOnScreenBufferFast(1,"You have won:", 255, 255, 255, 0, 0, game->StaffLineY[30], TextCenterX);
	visuals->DrawTextOnScreenBufferFast(1,"TetriCrisis 100% Version 5.9 Remix", 255, 255, 0, 0, 0, game->StaffLineY[31], TextCenterX);
	visuals->DrawTextOnScreenBufferFast(1,"A 100% by JeZ+Lee!", 255, 255, 255, 0, 0, game->StaffLineY[32], TextCenterX);
	visuals->DrawTextOnScreenBufferFast(1,"Thanks for playing...", 255, 255, 255, 0, 0, game->StaffLineY[33], TextCenterX);

	if (tetri_EnginE->CrisisModeWon != true)
		visuals->DrawTextOnScreenBufferFast(1,"Now win without cheating!", 255, 255, 255, 0, 0, game->StaffLineY[34], TextCenterX);
	else  visuals->DrawTextOnScreenBufferFast(1,"FUCK YOU E.A.Games and Handmark!!!", 255, 255, 255, 0, 0, game->StaffLineY[34], TextCenterX);

	SDL_Flip(visuals->Screen);

	if (game->StaffLineY[34] < -60)
	{
		CheckForNewHighScore();

		if (tetri_EnginE->NewHighScoreIndex < 5)
		{
			game->GameScreen = NewHighScoreNameInputScreen;

			if (tetri_EnginE->NewHighScoreIndex == 0)  audio->PlayMusic(13,Loop);
			else  audio->PlayMusic(14, Loop);
		}
		else
		{
			game->GameScreen = HighScoresScreen;
			audio->PlayMusic(12,Loop);
		}

		game->CurrentlySelectedScreenOption = 1;

		control->SingleMovementForJoystick = true;
	}
}

//-------------------------------------------------------------------------------------------------
void DisplayHowToPlayScreen(void)
{
Uint16 textLine = 0;
Uint16 textLineY[13] = { 56, 96, 136, 176, 216, 256, 296, 336, 376, 416, 456, 496, 536 };
Uint16 paragraphPositionIndex[16] = { 0, 4, 11, 15, 19, 24, 29, 35, 40, 45, 52, 59, 63, 67, 70, 79 };

    if (game->EXITgame == true) return;

	if (game->GameScreenDisplayed == false)
	{
		if (tetri_EnginE->DisplayBackground == 0)
		{
			SDL_BlitSurface(visuals->KremlinAlphaDark, NULL, visuals->Screen, NULL);
		}
		else  visuals->EraseScreenBufferWithColor(0, 0, 0);

		visuals->DrawTextOnScreenBuffer(1,"HOW TO PLAY", 255, 255, 0, 0, 0, 2, TextCenterX);
		visuals->DrawTextOnScreenBuffer(1,"__________________________________", 255, 255, 0, 0, 0, 16, TextCenterX);

		if (game->CurrentlySelectedScreenOption == 1)
		{
			visuals->DrawTextOnScreenBuffer(1,"=>", 255, 255, 0, 0, 150, 596, TextLeftX);
			visuals->DrawTextOnScreenBuffer(1,"<=", 255, 255, 0, 0, 150, 596, TextRightX);
		}

		if ( (game->SentenceLineY < 1)&&(textLine < 13) )
		{
			visuals->DrawTextOnScreenBuffer(1,"Object of the game:", 255, 255, 0, 0, 10, textLineY[textLine], TextLeftX);
			textLine++;
		}
		if ( (game->SentenceLineY < 2)&&(textLine < 13) )
		{
			visuals->DrawTextOnScreenBuffer(1,"Obtain the highest possible score", 255, 255, 255, 0, 10, textLineY[textLine], TextLeftX);
			textLine++;
		}
		if ( (game->SentenceLineY < 3)&&(textLine < 13) )
		{
			visuals->DrawTextOnScreenBuffer(1,"before the game is over.", 255, 255, 255, 0, 10, textLineY[textLine], TextLeftX);
			textLine++;
		}
		if ( (game->SentenceLineY < 4)&&(textLine < 13) )
		{
			visuals->DrawTextOnScreenBuffer(1,"", 255, 255, 255, 0, 10, textLineY[textLine], TextLeftX);
			textLine++;
		}
		if ( (game->SentenceLineY < 5)&&(textLine < 13) )
		{
			visuals->DrawTextOnScreenBuffer(1,"Playing the game:", 255, 255, 0, 0, 10, textLineY[textLine], TextLeftX);
			textLine++;
		}
		if ( (game->SentenceLineY < 6)&&(textLine < 13) )
		{
			visuals->DrawTextOnScreenBuffer(1,"1.Game starts with a clear playfield", 255, 255, 255, 0, 10, textLineY[textLine], TextLeftX);
			textLine++;
		}
		if ( (game->SentenceLineY < 7)&&(textLine < 13) )
		{
			visuals->DrawTextOnScreenBuffer(1,"(10 cells wide by 19 cells high) and", 255, 255, 255, 0, 10, textLineY[textLine], TextLeftX);
			textLine++;
		}
		if ( (game->SentenceLineY < 8)&&(textLine < 13) )
		{
			visuals->DrawTextOnScreenBuffer(1,"shapes (called pieces) randomly", 255, 255, 255, 0, 10, textLineY[textLine], TextLeftX);
			textLine++;
		}
		if ( (game->SentenceLineY < 9)&&(textLine < 13) )
		{
			visuals->DrawTextOnScreenBuffer(1,"falling one at a time from the top", 255, 255, 255, 0, 10, textLineY[textLine], TextLeftX);
			textLine++;
		}
		if ( (game->SentenceLineY < 10)&&(textLine < 13) )
		{
			visuals->DrawTextOnScreenBuffer(1,"of the playfield.", 255, 255, 255, 0, 10, textLineY[textLine], TextLeftX);
			textLine++;
		}
		if ( (game->SentenceLineY < 11)&&(textLine < 13) )
		{
			visuals->DrawTextOnScreenBuffer(1,"", 255, 255, 255, 0, 10, textLineY[textLine], TextLeftX);
			textLine++;
		}
		if ( (game->SentenceLineY < 12)&&(textLine < 13) )
		{
			visuals->DrawTextOnScreenBuffer(1,"2. Pieces are made of four adjacent", 255, 255, 255, 0, 10, textLineY[textLine], TextLeftX);
			textLine++;
		}
		if ( (game->SentenceLineY < 13)&&(textLine < 13) )
		{
			visuals->DrawTextOnScreenBuffer(1,"blocks arranged into seven different", 255, 255, 255, 0, 10, textLineY[textLine], TextLeftX);
			textLine++;
		}
		if ( (game->SentenceLineY < 14)&&(textLine < 13) )
		{
			visuals->DrawTextOnScreenBuffer(1,"patterns.", 255, 255, 255, 0, 10, textLineY[textLine], TextLeftX);
			textLine++;
		}
		if ( (game->SentenceLineY < 15)&&(textLine < 13) )
		{
			visuals->DrawTextOnScreenBuffer(1,"", 255, 255, 255, 0, 10, textLineY[textLine], TextLeftX);
			textLine++;
		}
		if ( (game->SentenceLineY < 16)&&(textLine < 13) )
		{
			visuals->DrawTextOnScreenBuffer(1,"3. Player must arrange the falling", 255, 255, 255, 0, 10, textLineY[textLine], TextLeftX);
			textLine++;
		}
		if ( (game->SentenceLineY < 17)&&(textLine < 13) )
		{
			visuals->DrawTextOnScreenBuffer(1,"pieces to complete horizontal lines", 255, 255, 255, 0, 10, textLineY[textLine], TextLeftX);
			textLine++;
		}
		if ( (game->SentenceLineY < 18)&&(textLine < 13) )
		{
			visuals->DrawTextOnScreenBuffer(1,"within the playfield.", 255, 255, 255, 0, 10, textLineY[textLine], TextLeftX);
			textLine++;
		}
		if ( (game->SentenceLineY < 19)&&(textLine < 13) )
		{
			visuals->DrawTextOnScreenBuffer(1,"", 255, 255, 255, 0, 10, textLineY[textLine], TextLeftX);
			textLine++;
		}
		if ( (game->SentenceLineY < 20)&&(textLine < 13) )
		{
			visuals->DrawTextOnScreenBuffer(1,"4. Player may affect the falling pieces", 255, 255, 255, 0, 10, textLineY[textLine], TextLeftX);
			textLine++;
		}
		if ( (game->SentenceLineY < 21)&&(textLine < 13) )
		{
			visuals->DrawTextOnScreenBuffer(1,"by moving them left or right or rotating", 255, 255, 255, 0, 10, textLineY[textLine], TextLeftX);
			textLine++;
		}
		if ( (game->SentenceLineY < 21)&&(textLine < 13) )
		{
			visuals->DrawTextOnScreenBuffer(1,"them clockwise or counter-clockwise", 255, 255, 255, 0, 10, textLineY[textLine], TextLeftX);
			textLine++;
		}
		if ( (game->SentenceLineY < 22)&&(textLine < 13) )
		{
			visuals->DrawTextOnScreenBuffer(1,"withing the playfield while they are", 255, 255, 255, 0, 10, textLineY[textLine], TextLeftX);
			textLine++;
		}
		if ( (game->SentenceLineY < 23)&&(textLine < 13) )
		{
			visuals->DrawTextOnScreenBuffer(1,"still falling.", 255, 255, 255, 0, 10, textLineY[textLine], TextLeftX);
			textLine++;
		}
		if ( (game->SentenceLineY < 24)&&(textLine < 13) )
		{
			visuals->DrawTextOnScreenBuffer(1,"", 255, 255, 255, 0, 10, textLineY[textLine], TextLeftX);
			textLine++;
		}
		if ( (game->SentenceLineY < 25)&&(textLine < 13) )
		{
			visuals->DrawTextOnScreenBuffer(1,"5. When a completed line is formed,", 255, 255, 255, 0, 10, textLineY[textLine], TextLeftX);
			textLine++;
		}
		if ( (game->SentenceLineY < 26)&&(textLine < 13) )
		{
			visuals->DrawTextOnScreenBuffer(1,"that line is eliminated from the", 255, 255, 255, 0, 10, textLineY[textLine], TextLeftX);
			textLine++;
		}
		if ( (game->SentenceLineY < 27)&&(textLine < 13) )
		{
			visuals->DrawTextOnScreenBuffer(1,"playfield, and the player scores", 255, 255, 255, 0, 10, textLineY[textLine], TextLeftX);
			textLine++;
		}
		if ( (game->SentenceLineY < 28)&&(textLine < 13) )
		{
			visuals->DrawTextOnScreenBuffer(1,"points.", 255, 255, 255, 0, 10, textLineY[textLine], TextLeftX);
			textLine++;
		}
		if ( (game->SentenceLineY < 29)&&(textLine < 13) )
		{
			visuals->DrawTextOnScreenBuffer(1,"", 255, 255, 255, 0, 10, textLineY[textLine], TextLeftX);
			textLine++;
		}
		if ( (game->SentenceLineY < 30)&&(textLine < 13) )
		{
			visuals->DrawTextOnScreenBuffer(1,"6. The pieces come to rest when they", 255, 255, 255, 0, 10, textLineY[textLine], TextLeftX);
			textLine++;
		}
		if ( (game->SentenceLineY < 31)&&(textLine < 13) )
		{
			visuals->DrawTextOnScreenBuffer(1,"either hit the bottom line of the", 255, 255, 255, 0, 10, textLineY[textLine], TextLeftX);
			textLine++;
		}
		if ( (game->SentenceLineY < 32)&&(textLine < 13) )
		{
			visuals->DrawTextOnScreenBuffer(1,"playfield, or when their movement is", 255, 255, 255, 0, 10, textLineY[textLine], TextLeftX);
			textLine++;
		}
		if ( (game->SentenceLineY < 33)&&(textLine < 13) )
		{
			visuals->DrawTextOnScreenBuffer(1,"blocked by other pieces that have", 255, 255, 255, 0, 10, textLineY[textLine], TextLeftX);
			textLine++;
		}
		if ( (game->SentenceLineY < 34)&&(textLine < 13) )
		{
			visuals->DrawTextOnScreenBuffer(1,"already come to rest in the playfield.", 255, 255, 255, 0, 10, textLineY[textLine], TextLeftX);
			textLine++;
		}
		if ( (game->SentenceLineY < 35)&&(textLine < 13) )
		{
			visuals->DrawTextOnScreenBuffer(1,"", 255, 255, 255, 0, 10, textLineY[textLine], TextLeftX);
			textLine++;
		}
		if ( (game->SentenceLineY < 36)&&(textLine < 13) )
		{
			visuals->DrawTextOnScreenBuffer(1,"7. If player cannot complete lines, the", 255, 255, 255, 0, 10, textLineY[textLine], TextLeftX);
			textLine++;
		}
		if ( (game->SentenceLineY < 37)&&(textLine < 13) )
		{
			visuals->DrawTextOnScreenBuffer(1,"pieces eventually build upon each other", 255, 255, 255, 0, 10, textLineY[textLine], TextLeftX);
			textLine++;
		}
		if ( (game->SentenceLineY < 38)&&(textLine < 13) )
		{
			visuals->DrawTextOnScreenBuffer(1,"and reach the top of the playfield,", 255, 255, 255, 0, 10, textLineY[textLine], TextLeftX);
			textLine++;
		}
		if ( (game->SentenceLineY < 39)&&(textLine < 13) )
		{
			visuals->DrawTextOnScreenBuffer(1,"thus ending the game.", 255, 255, 255, 0, 10, textLineY[textLine], TextLeftX);
			textLine++;
		}
		if ( (game->SentenceLineY < 40)&&(textLine < 13) )
		{
			visuals->DrawTextOnScreenBuffer(1,"", 255, 255, 255, 0, 10, textLineY[textLine], TextLeftX);
			textLine++;
		}
		if ( (game->SentenceLineY < 41)&&(textLine < 13) )
		{
			visuals->DrawTextOnScreenBuffer(1,"Note: Although the order in which the", 255, 255, 255, 0, 10, textLineY[textLine], TextLeftX);
			textLine++;
		}
		if ( (game->SentenceLineY < 42)&&(textLine < 13) )
		{
			visuals->DrawTextOnScreenBuffer(1,"different pieces fall is random, the", 255, 255, 255, 0, 10, textLineY[textLine], TextLeftX);
			textLine++;
		}
		if ( (game->SentenceLineY < 43)&&(textLine < 13) )
		{
			visuals->DrawTextOnScreenBuffer(1,"next piece set to appear is shown in the", 255, 255, 255, 0, 10, textLineY[textLine], TextLeftX);
			textLine++;
		}
		if ( (game->SentenceLineY < 44)&&(textLine < 13) )
		{
			visuals->DrawTextOnScreenBuffer(1,"lower right hand corner of the screen.", 255, 255, 255, 0, 10, textLineY[textLine], TextLeftX);
			textLine++;
		}
		if ( (game->SentenceLineY < 45)&&(textLine < 13) )
		{
			visuals->DrawTextOnScreenBuffer(1,"", 255, 255, 255, 0, 10, textLineY[textLine], TextLeftX);
			textLine++;
		}
		if ( (game->SentenceLineY < 46)&&(textLine < 13) )
		{
			visuals->DrawTextOnScreenBuffer(1,"How to move pieces :", 255, 255, 0, 0, 10, textLineY[textLine], TextLeftX);
			textLine++;
		}
		if ( (game->SentenceLineY < 47)&&(textLine < 13) )
		{
			visuals->DrawTextOnScreenBuffer(1,"1. Player controls the falling pieces by", 255, 255, 255, 0, 10, textLineY[textLine], TextLeftX);
			textLine++;
		}
		if ( (game->SentenceLineY < 48)&&(textLine < 13) )
		{
			visuals->DrawTextOnScreenBuffer(1,"using the [ARROW] keys on the", 255, 255, 255, 0, 10, textLineY[textLine], TextLeftX);
			textLine++;
		}
		if ( (game->SentenceLineY < 49)&&(textLine < 13) )
		{
			visuals->DrawTextOnScreenBuffer(1,"keyboard and by using [Z] and [X] keys", 255, 255, 255, 0, 10, textLineY[textLine], TextLeftX);
			textLine++;
		}
		if ( (game->SentenceLineY < 50)&&(textLine < 13) )
		{
			visuals->DrawTextOnScreenBuffer(1,"on keyboard to rotate the pieces.", 255, 255, 255, 0, 10, textLineY[textLine], TextLeftX);
			textLine++;
		}
		if ( (game->SentenceLineY < 51)&&(textLine < 13) )
		{
			visuals->DrawTextOnScreenBuffer(1,"(Note: A joystick may also be used too.)", 255, 255, 255, 0, 10, textLineY[textLine], TextLeftX);
			textLine++;
		}
		if ( (game->SentenceLineY < 52)&&(textLine < 13) )
		{
			visuals->DrawTextOnScreenBuffer(1,"", 255, 255, 255, 0, 10, textLineY[textLine], TextLeftX);
			textLine++;
		}
		if ( (game->SentenceLineY < 53)&&(textLine < 13) )
		{
			visuals->DrawTextOnScreenBuffer(1,"2. Any filled cell of the playfield is an", 255, 255, 255, 0, 10, textLineY[textLine], TextLeftX);
			textLine++;
		}
		if ( (game->SentenceLineY < 54)&&(textLine < 13) )
		{
			visuals->DrawTextOnScreenBuffer(1,"obstacle for the current piece moving", 255, 255, 255, 0, 10, textLineY[textLine], TextLeftX);
			textLine++;
		}
		if ( (game->SentenceLineY < 55)&&(textLine < 13) )
		{
			visuals->DrawTextOnScreenBuffer(1,"around the playfield. Movement of the", 255, 255, 255, 0, 10, textLineY[textLine], TextLeftX);
			textLine++;
		}
		if ( (game->SentenceLineY < 56)&&(textLine < 13) )
		{
			visuals->DrawTextOnScreenBuffer(1,"piece is allowed only when all", 255, 255, 255, 0, 10, textLineY[textLine], TextLeftX);
			textLine++;
		}
		if ( (game->SentenceLineY < 57)&&(textLine < 13) )
		{
			visuals->DrawTextOnScreenBuffer(1,"individual cells needed to accomodate", 255, 255, 255, 0, 10, textLineY[textLine], TextLeftX);
			textLine++;
		}
		if ( (game->SentenceLineY < 58)&&(textLine < 13) )
		{
			visuals->DrawTextOnScreenBuffer(1,"the move are completely empty.", 255, 255, 255, 0, 10, textLineY[textLine], TextLeftX);
			textLine++;
		}
		if ( (game->SentenceLineY < 59)&&(textLine < 13) )
		{
			visuals->DrawTextOnScreenBuffer(1,"", 255, 255, 255, 0, 10, textLineY[textLine], TextLeftX);
			textLine++;
		}
		if ( (game->SentenceLineY < 60)&&(textLine < 13) )
		{
			visuals->DrawTextOnScreenBuffer(1,"3. A piece cannot be moved or rotated", 255, 255, 255, 0, 10, textLineY[textLine], TextLeftX);
			textLine++;
		}
		if ( (game->SentenceLineY < 61)&&(textLine < 13) )
		{
			visuals->DrawTextOnScreenBuffer(1,"if part of the piece will fall outside", 255, 255, 255, 0, 10, textLineY[textLine], TextLeftX);
			textLine++;
		}
		if ( (game->SentenceLineY < 62)&&(textLine < 13) )
		{
			visuals->DrawTextOnScreenBuffer(1,"the playfield in its new position.", 255, 255, 255, 0, 10, textLineY[textLine], TextLeftX);
			textLine++;
		}
		if ( (game->SentenceLineY < 63)&&(textLine < 13) )
		{
			visuals->DrawTextOnScreenBuffer(1,"", 255, 255, 255, 0, 10, textLineY[textLine], TextLeftX);
			textLine++;
		}
		if ( (game->SentenceLineY < 64)&&(textLine < 13) )
		{
			visuals->DrawTextOnScreenBuffer(1,"Levels:", 255, 255, 0, 0, 10, textLineY[textLine], TextLeftX);
			textLine++;
		}
		if ( (game->SentenceLineY < 65)&&(textLine < 13) )
		{
			visuals->DrawTextOnScreenBuffer(1,"1. The game advances to the next level", 255, 255, 255, 0, 10, textLineY[textLine], TextLeftX);
			textLine++;
		}
		if ( (game->SentenceLineY < 66)&&(textLine < 13) )
		{
			visuals->DrawTextOnScreenBuffer(1,"each time the player clears 10 lines.", 255, 255, 255, 0, 10, textLineY[textLine], TextLeftX);
			textLine++;
		}
		if ( (game->SentenceLineY < 67)&&(textLine < 13) )
		{
			visuals->DrawTextOnScreenBuffer(1,"", 255, 255, 255, 0, 10, textLineY[textLine], TextLeftX);
			textLine++;
		}
		if ( (game->SentenceLineY < 68)&&(textLine < 13) )
		{
			visuals->DrawTextOnScreenBuffer(1,"2. The higher the level, the more", 255, 255, 255, 0, 10, textLineY[textLine], TextLeftX);
			textLine++;
		}
		if ( (game->SentenceLineY < 69)&&(textLine < 13) )
		{
			visuals->DrawTextOnScreenBuffer(1,"quickly the pieces fall.", 255, 255, 255, 0, 10, textLineY[textLine], TextLeftX);
			textLine++;
		}
		if ( (game->SentenceLineY < 70)&&(textLine < 13) )
		{
			visuals->DrawTextOnScreenBuffer(1,"", 255, 255, 255, 0, 10, textLineY[textLine], TextLeftX);
			textLine++;
		}
		if ( (game->SentenceLineY < 71)&&(textLine < 13) )
		{
			visuals->DrawTextOnScreenBuffer(1,"Scoring:", 255, 255, 0, 0, 10, textLineY[textLine], TextLeftX);
			textLine++;
		}
		if ( (game->SentenceLineY < 72)&&(textLine < 13) )
		{
			visuals->DrawTextOnScreenBuffer(1,"1. Points are awarded for clearing", 255, 255, 255, 0, 10, textLineY[textLine], TextLeftX);
			textLine++;
		}
		if ( (game->SentenceLineY < 73)&&(textLine < 13) )
		{
			visuals->DrawTextOnScreenBuffer(1,"lines as follows:", 255, 255, 255, 0, 10, textLineY[textLine], TextLeftX);
			textLine++;
		}
		if ( (game->SentenceLineY < 74)&&(textLine < 13) )
		{
			visuals->DrawTextOnScreenBuffer(1,"", 255, 255, 255, 0, 10, textLineY[textLine], TextLeftX);
			textLine++;
		}
		if ( (game->SentenceLineY < 75)&&(textLine < 13) )
		{
			visuals->DrawTextOnScreenBuffer(1,"Single: 40 points", 255, 255, 255, 0, 10, textLineY[textLine], TextLeftX);
			textLine++;
		}
		if ( (game->SentenceLineY < 76)&&(textLine < 13) )
		{
			visuals->DrawTextOnScreenBuffer(1,"Double: 100 points", 255, 255, 255, 0, 10, textLineY[textLine], TextLeftX);
			textLine++;
		}
		if ( (game->SentenceLineY < 76)&&(textLine < 13) )
		{
			visuals->DrawTextOnScreenBuffer(1,"Triple: 300 points", 255, 255, 255, 0, 10, textLineY[textLine], TextLeftX);
			textLine++;
		}
		if ( (game->SentenceLineY < 78)&&(textLine < 13) )
		{
			visuals->DrawTextOnScreenBuffer(1,"(4 lines): 1200 points", 255, 255, 255, 0, 10, textLineY[textLine], TextLeftX);
			textLine++;
		}
		if ( (game->SentenceLineY < 79)&&(textLine < 13) )
		{
			visuals->DrawTextOnScreenBuffer(1,"", 255, 255, 255, 0, 10, textLineY[textLine], TextLeftX);
			textLine++;
		}
		if ( (game->SentenceLineY < 80)&&(textLine < 13) )
		{
			visuals->DrawTextOnScreenBuffer(1,"2. The points for clearing lines and", 255, 255, 255, 0, 10, textLineY[textLine], TextLeftX);
			textLine++;
		}
		if ( (game->SentenceLineY < 81)&&(textLine < 13) )
		{
			visuals->DrawTextOnScreenBuffer(1,"scoring are multiplied by the current", 255, 255, 255, 0, 10, textLineY[textLine], TextLeftX);
			textLine++;
		}
		if ( (game->SentenceLineY < 82)&&(textLine < 13) )
		{
			visuals->DrawTextOnScreenBuffer(1,"level plus one. For example, clearing", 255, 255, 255, 0, 10, textLineY[textLine], TextLeftX);
			textLine++;
		}
		if ( (game->SentenceLineY < 83)&&(textLine < 13) )
		{
			visuals->DrawTextOnScreenBuffer(1,"one line of blocks on level 2 earns", 255, 255, 255, 0, 10, textLineY[textLine], TextLeftX);
			textLine++;
		}
		if ( (game->SentenceLineY < 84)&&(textLine < 13) )
		{
			visuals->DrawTextOnScreenBuffer(1,"120 points (40*(2+1)).", 255, 255, 255, 0, 10, textLineY[textLine], TextLeftX);
			textLine++;
		}
		if ( (game->SentenceLineY < 85)&&(textLine < 13) )
		{
			visuals->DrawTextOnScreenBuffer(1,"", 255, 255, 255, 0, 10, textLineY[textLine], TextLeftX);
			textLine++;
		}
		if ( (game->SentenceLineY < 86)&&(textLine < 13) )
		{
			visuals->DrawTextOnScreenBuffer(1,"Top Secret 'Easter Egg' Codes:", 255, 255, 0, 0, 10, textLineY[textLine], TextLeftX);
			textLine++;
		}
		if ( (game->SentenceLineY < 87)&&(textLine < 13) )
		{
			visuals->DrawTextOnScreenBuffer(1,"[W] = Win Crisis+Mode and see staff!", 255, 255, 255, 0, 10, textLineY[textLine], TextLeftX);
			textLine++;
		}
		if ( (game->SentenceLineY < 88)&&(textLine < 13) )
		{
			visuals->DrawTextOnScreenBuffer(1,"[P] = Change in-game music track.", 255, 255, 255, 0, 10, textLineY[textLine], TextLeftX);
			textLine++;
		}
		if ( (game->SentenceLineY < 89)&&(textLine < 13) )
		{
			visuals->DrawTextOnScreenBuffer(1,"", 255, 255, 255, 0, 10, textLineY[textLine], TextLeftX);
			textLine++;
		}
		if ( (game->SentenceLineY < 90)&&(textLine < 13) )
		{
			visuals->DrawTextOnScreenBuffer(1,"5.9 Remix 100% | 09-14-09", 180, 180, 180, 0, 10, textLineY[textLine], TextCenterX);
			textLine++;
		}

		visuals->DrawTextOnScreenBuffer(1,"__________________________________", 255, 255, 0, 0, 0, 555, TextCenterX);
		buttons->SetUpNewButtonForUserInput(6, 1, 0, 596, 200, ButtonCenterX);

		SDL_Flip(visuals->Screen);
		game->GameScreenDisplayed = true;
	}

	if (control->JoystickDirection[Any] == UP)
	{
		if (game->ParagraphPosition > 0)  game->ParagraphPosition--;

		game->SentenceLineY = paragraphPositionIndex[game->ParagraphPosition];

		game->GameScreenDisplayed = false;
		audio->PlayDigitalSoundFX(2);
	}
	else if (control->JoystickDirection[Any] == DOWN)
	{
		if (game->ParagraphPosition < 15)  game->ParagraphPosition++;

		game->SentenceLineY = paragraphPositionIndex[game->ParagraphPosition];

		game->GameScreenDisplayed = false;
		audio->PlayDigitalSoundFX(2);
	}

	if (buttons->ButtonClickedByUser(6) == true)
	{
		game->GameScreenDisplayed = false;
		visuals->FadeOutScreenBuffer();
		buttons->DeleteAllRegisteredButtons();
		game->GameScreen = TitleScreen;
		game->CurrentlySelectedScreenOption = 0;
	}
}

//-------------------------------------------------------------------------------------------------
void DisplayHistoryScreen(void)
{
Uint16 textLine = 0;
Uint16 textLineY[13] = { 56, 96, 136, 176, 216, 256, 296, 336, 376, 416, 456, 496, 536 };
Uint16 paragraphPositionIndex[11] = { 0, 4, 9, 14, 20, 27, 32, 38, 40, 47, 52, };

    if (game->EXITgame == true) return;

	if (game->GameScreenDisplayed == false)
	{
		if (tetri_EnginE->DisplayBackground == 0)
		{
			SDL_BlitSurface(visuals->KremlinAlphaDark, NULL, visuals->Screen, NULL);
		}
		else  visuals->EraseScreenBufferWithColor(0, 0, 0);

		visuals->DrawTextOnScreenBuffer(1,"HISTORY", 255, 255, 0, 0, 0, 2, TextCenterX);
		visuals->DrawTextOnScreenBuffer(1,"__________________________________", 255, 255, 0, 0, 0, 16, TextCenterX);

		if (game->CurrentlySelectedScreenOption == 1)
		{
			visuals->DrawTextOnScreenBuffer(1,"=>", 255, 255, 0, 0, 150, 596, TextLeftX);
			visuals->DrawTextOnScreenBuffer(1,"<=", 255, 255, 0, 0, 150, 596, TextRightX);
		}

		if ( (game->SentenceLineY < 1)&&(textLine < 13) )
		{
			visuals->DrawTextOnScreenBuffer(1,"Message from TetriCrisis100%  creator:", 255, 255, 0, 0, 0, textLineY[textLine], TextCenterX);
			textLine++;
		}
		if ( (game->SentenceLineY < 2)&&(textLine < 13) )
		{
			visuals->DrawTextOnScreenBuffer(0,"Hi, my name is Jesse (AKA: JeZ+Lee).", 255, 255, 255, 0, 10, textLineY[textLine], TextLeftX);
			textLine++;
		}
		if ( (game->SentenceLineY < 3)&&(textLine < 13) )
		{
			visuals->DrawTextOnScreenBuffer(0,"I am a learning disabled person with Autism.", 255, 255, 255, 0, 10, textLineY[textLine], TextLeftX);
			textLine++;
		}
		if ( (game->SentenceLineY < 4)&&(textLine < 13) )
		{
			visuals->DrawTextOnScreenBuffer(0,"", 255, 255, 255, 0, 10, textLineY[textLine], TextLeftX);
			textLine++;
		}
		if ( (game->SentenceLineY < 5)&&(textLine < 13) )
		{
			visuals->DrawTextOnScreenBuffer(0,"All persons with Autism usually have a", 255, 255, 255, 0, 10, textLineY[textLine], TextLeftX);
			textLine++;
		}
		if ( (game->SentenceLineY < 6)&&(textLine < 13) )
		{
			visuals->DrawTextOnScreenBuffer(0,"single major point of interest that consumes", 255, 255, 255, 0, 10, textLineY[textLine], TextLeftX);
			textLine++;
		}
		if ( (game->SentenceLineY < 7)&&(textLine < 13) )
		{
			visuals->DrawTextOnScreenBuffer(0,"their time and energy. Mine happens to be", 255, 255, 255, 0, 10, textLineY[textLine], TextLeftX);
			textLine++;
		}
		if ( (game->SentenceLineY < 8)&&(textLine < 13) )
		{
			visuals->DrawTextOnScreenBuffer(0,"the popular video game Tetris...", 255, 255, 255, 0, 10, textLineY[textLine], TextLeftX);
			textLine++;
		}
		if ( (game->SentenceLineY < 9)&&(textLine < 13) )
		{
			visuals->DrawTextOnScreenBuffer(0,"", 255, 255, 255, 0, 10, textLineY[textLine], TextLeftX);
			textLine++;
		}
		if ( (game->SentenceLineY < 10)&&(textLine < 13) )
		{
			visuals->DrawTextOnScreenBuffer(0,"I have been making Tetris for over a decade,", 255, 255, 255, 0, 10, textLineY[textLine], TextLeftX);
			textLine++;
		}
		if ( (game->SentenceLineY < 11)&&(textLine < 13) )
		{
			visuals->DrawTextOnScreenBuffer(0,"and TetriCrisis100% for Palm OS has been the", 255, 255, 255, 0, 10, textLineY[textLine], TextLeftX);
			textLine++;
		}
		if ( (game->SentenceLineY < 12)&&(textLine < 13) )
		{
			visuals->DrawTextOnScreenBuffer(0,"most popular so I decided to make it for the", 255, 255, 255, 0, 10, textLineY[textLine], TextLeftX);
			textLine++;
		}
		if ( (game->SentenceLineY < 13)&&(textLine < 13) )
		{
			visuals->DrawTextOnScreenBuffer(0,"desktop computer systems too.", 255, 255, 255, 0, 10, textLineY[textLine], TextLeftX);
			textLine++;
		}
		if ( (game->SentenceLineY < 14)&&(textLine < 13) )
		{
			visuals->DrawTextOnScreenBuffer(0,"", 255, 255, 255, 0, 10, textLineY[textLine], TextLeftX);
			textLine++;
		}
		if ( (game->SentenceLineY < 15)&&(textLine < 13) )
		{
			visuals->DrawTextOnScreenBuffer(0,"I developed this game originally for Palm.", 255, 255, 255, 0, 10, textLineY[textLine], TextLeftX);
			textLine++;
		}
		if ( (game->SentenceLineY < 16)&&(textLine < 13) )
		{
			visuals->DrawTextOnScreenBuffer(0,"I developed the game over a two year period,", 255, 255, 255, 0, 10, textLineY[textLine], TextLeftX);
			textLine++;
		}
		if ( (game->SentenceLineY < 17)&&(textLine < 13) )
		{
			visuals->DrawTextOnScreenBuffer(0,"spending 100's of man hours and $1000's of", 255, 255, 255, 0, 10, textLineY[textLine], TextLeftX);
			textLine++;
		}
		if ( (game->SentenceLineY < 18)&&(textLine < 13) )
		{
			visuals->DrawTextOnScreenBuffer(0,"dollars and facing challenges you could not", 255, 255, 255, 0, 10, textLineY[textLine], TextLeftX);
			textLine++;
		}
		if ( (game->SentenceLineY < 19)&&(textLine < 13) )
		{
			visuals->DrawTextOnScreenBuffer(0,"imagine.", 255, 255, 255, 0, 10, textLineY[textLine], TextLeftX);
			textLine++;
		}
		if ( (game->SentenceLineY < 20)&&(textLine < 13) )
		{
			visuals->DrawTextOnScreenBuffer(0,"", 255, 255, 255, 0, 10, textLineY[textLine], TextLeftX);
			textLine++;
		}
		if ( (game->SentenceLineY < 21)&&(textLine < 13) )
		{
			visuals->DrawTextOnScreenBuffer(0,"This game was considered to be published by", 255, 255, 255, 0, 10, textLineY[textLine], TextLeftX);
			textLine++;
		}
		if ( (game->SentenceLineY < 22)&&(textLine < 13) )
		{
			visuals->DrawTextOnScreenBuffer(0,"E.A.Games as Tetris 2.0 for Palm.", 255, 255, 255, 0, 10, textLineY[textLine], TextLeftX);
			textLine++;
		}
		if ( (game->SentenceLineY < 23)&&(textLine < 13) )
		{
			visuals->DrawTextOnScreenBuffer(0,"E.A.Games regretably changed their mind", 255, 255, 255, 0, 10, textLineY[textLine], TextLeftX);
			textLine++;
		}
		if ( (game->SentenceLineY < 24)&&(textLine < 13) )
		{
			visuals->DrawTextOnScreenBuffer(0,"and theatened me (an Autistic person) with a", 255, 255, 255, 0, 10, textLineY[textLine], TextLeftX);
			textLine++;
		}
		if ( (game->SentenceLineY < 25)&&(textLine < 13) )
		{
			visuals->DrawTextOnScreenBuffer(0,"lawsuit if I ever attempted to release the", 255, 255, 255, 0, 10, textLineY[textLine], TextLeftX);
			textLine++;
		}
		if ( (game->SentenceLineY < 26)&&(textLine < 13) )
		{
			visuals->DrawTextOnScreenBuffer(0,"game for sale to the public...", 255, 255, 255, 0, 10, textLineY[textLine], TextLeftX);
			textLine++;
		}
		if ( (game->SentenceLineY < 27)&&(textLine < 13) )
		{
			visuals->DrawTextOnScreenBuffer(0,"", 255, 255, 255, 0, 10, textLineY[textLine], TextLeftX);
			textLine++;
		}
		if ( (game->SentenceLineY < 28)&&(textLine < 13) )
		{
			visuals->DrawTextOnScreenBuffer(0,"Well (again) you now have the game for", 255, 255, 255, 0, 10, textLineY[textLine], TextLeftX);
			textLine++;
		}
		if ( (game->SentenceLineY < 29)&&(textLine < 13) )
		{
			visuals->DrawTextOnScreenBuffer(0,"FREE!!! I did not spend all this time and", 255, 255, 255, 0, 10, textLineY[textLine], TextLeftX);
			textLine++;
		}
		if ( (game->SentenceLineY < 30)&&(textLine < 13) )
		{
			visuals->DrawTextOnScreenBuffer(0,"money not to release this game to the public", 255, 255, 255, 0, 10, textLineY[textLine], TextLeftX);
			textLine++;
		}
		if ( (game->SentenceLineY < 31)&&(textLine < 13) )
		{
			visuals->DrawTextOnScreenBuffer(0,"E.A Games!!!", 255, 255, 255, 0, 10, textLineY[textLine], TextLeftX);
			textLine++;
		}
		if ( (game->SentenceLineY < 32)&&(textLine < 13) )
		{
			visuals->DrawTextOnScreenBuffer(0,"", 255, 255, 255, 0, 10, textLineY[textLine], TextLeftX);
			textLine++;
		}
		if ( (game->SentenceLineY < 33)&&(textLine < 13) )
		{
			visuals->DrawTextOnScreenBuffer(0,"Since its 1st release on c|net's", 255, 255, 255, 0, 10, textLineY[textLine], TextLeftX);
			textLine++;
		}
		if ( (game->SentenceLineY < 34)&&(textLine < 13) )
		{
			visuals->DrawTextOnScreenBuffer(0,"www.Download.com web site, this game has", 255, 255, 255, 0, 10, textLineY[textLine], TextLeftX);
			textLine++;
		}
		if ( (game->SentenceLineY < 35)&&(textLine < 13) )
		{
			visuals->DrawTextOnScreenBuffer(0,"been downloaded over 300,000+ times, and", 255, 255, 255, 0, 10, textLineY[textLine], TextLeftX);
			textLine++;
		}
		if ( (game->SentenceLineY < 36)&&(textLine < 13) )
		{
			visuals->DrawTextOnScreenBuffer(0,"has been on the top 5 most popular list", 255, 255, 255, 0, 10, textLineY[textLine], TextLeftX);
			textLine++;
		}
		if ( (game->SentenceLineY < 37)&&(textLine < 13) )
		{
			visuals->DrawTextOnScreenBuffer(0,"ever week since its release!", 255, 255, 255, 0, 10, textLineY[textLine], TextLeftX);
			textLine++;
		}
		if ( (game->SentenceLineY < 38)&&(textLine < 13) )
		{
			visuals->DrawTextOnScreenBuffer(0,"", 255, 255, 255, 0, 10, textLineY[textLine], TextLeftX);
			textLine++;
		}
		if ( (game->SentenceLineY < 39)&&(textLine < 13) )
		{
			visuals->DrawTextOnScreenBuffer(0,"Well, thats the story about my game...", 255, 255, 255, 0, 10, textLineY[textLine], TextLeftX);
			textLine++;
		}
		if ( (game->SentenceLineY < 40)&&(textLine < 13) )
		{
			visuals->DrawTextOnScreenBuffer(0,"", 255, 255, 255, 0, 10, textLineY[textLine], TextLeftX);
			textLine++;
		}
		if ( (game->SentenceLineY < 41)&&(textLine < 13) )
		{
			visuals->DrawTextOnScreenBuffer(0,"To summarize:", 255, 255, 0, 0, 10, textLineY[textLine], TextLeftX);
			textLine++;
		}
		if ( (game->SentenceLineY < 42)&&(textLine < 13) )
		{
			visuals->DrawTextOnScreenBuffer(0,"I am Autistic.", 255, 255, 255, 0, 10, textLineY[textLine], TextLeftX);
			textLine++;
		}
		if ( (game->SentenceLineY < 43)&&(textLine < 13) )
		{
			visuals->DrawTextOnScreenBuffer(0,"E.A. Games wants to sue me.", 255, 255, 255, 0, 10, textLineY[textLine], TextLeftX);
			textLine++;
		}
		if ( (game->SentenceLineY < 44)&&(textLine < 13) )
		{
			visuals->DrawTextOnScreenBuffer(0,"c|net (again) published this game.", 255, 255, 255, 0, 10, textLineY[textLine], TextLeftX);
			textLine++;
		}
		if ( (game->SentenceLineY < 45)&&(textLine < 13) )
		{
			visuals->DrawTextOnScreenBuffer(0,"And 300,000+ people around the world are", 255, 255, 255, 0, 10, textLineY[textLine], TextLeftX);
			textLine++;
		}
		if ( (game->SentenceLineY < 46)&&(textLine < 13) )
		{
			visuals->DrawTextOnScreenBuffer(0,"now playing this game for FREE!!!", 255, 255, 255, 0, 10, textLineY[textLine], TextLeftX);
			textLine++;
		}
		if ( (game->SentenceLineY < 47)&&(textLine < 13) )
		{
			visuals->DrawTextOnScreenBuffer(0,"", 255, 255, 255, 0, 10, textLineY[textLine], TextLeftX);
			textLine++;
		}
		if ( (game->SentenceLineY < 48)&&(textLine < 13) )
		{
			visuals->DrawTextOnScreenBuffer(0,"Oh, and this part of my life is called:", 255, 255, 255, 0, 10, textLineY[textLine], TextCenterX);
			textLine++;
		}
		if ( (game->SentenceLineY < 49)&&(textLine < 13) )
		{
			visuals->DrawTextOnScreenBuffer(0,"E.A. Games", 255, 255, 0, 0, 10, textLineY[textLine], TextCenterX);
			textLine++;
		}
		if ( (game->SentenceLineY < 50)&&(textLine < 13) )
		{
			visuals->DrawTextOnScreenBuffer(0,"V.S.", 255, 255, 0, 0, 10, textLineY[textLine], TextCenterX);
			textLine++;
		}
		if ( (game->SentenceLineY < 51)&&(textLine < 13) )
		{
			visuals->DrawTextOnScreenBuffer(0,"Silent Hero Productions", 255, 255, 0, 0, 10, textLineY[textLine], TextCenterX);
			textLine++;
		}
		if ( (game->SentenceLineY < 52)&&(textLine < 13) )
		{
			visuals->DrawTextOnScreenBuffer(0,"", 255, 255, 255, 0, 10, textLineY[textLine], TextCenterX);
			textLine++;
		}
		if ( (game->SentenceLineY < 53)&&(textLine < 13) )
		{
			visuals->DrawTextOnScreenBuffer(0,"Sincerely,", 255, 255, 255, 0, 10, textLineY[textLine], TextCenterX);
			textLine++;
		}
		if ( (game->SentenceLineY < 54)&&(textLine < 13) )
		{
			visuals->DrawTextOnScreenBuffer(0,"Jesse ''JeZ+Lee'' Palser", 255, 255, 255, 0, 10, textLineY[textLine], TextCenterX);
			textLine++;
		}
		if ( (game->SentenceLineY < 55)&&(textLine < 13) )
		{
			visuals->DrawTextOnScreenBuffer(0,"C.E.O. of Silent Hero Productions", 255, 255, 255, 0, 10, textLineY[textLine], TextCenterX);
			textLine++;
		}
		if ( (game->SentenceLineY < 56)&&(textLine < 13) )
		{
			visuals->DrawTextOnScreenBuffer(0,"www.SilentHeroProductions.com", 255, 255, 255, 0, 10, textLineY[textLine], TextCenterX);
			textLine++;
		}
		if ( (game->SentenceLineY < 57)&&(textLine < 13) )
		{
			visuals->DrawTextOnScreenBuffer(0,"", 255, 255, 255, 0, 10, textLineY[textLine], TextCenterX);
			textLine++;
		}
		if ( (game->SentenceLineY < 58)&&(textLine < 13) )
		{
			visuals->DrawTextOnScreenBuffer(0,"E-Mail Me At:", 0, 255, 0, 0, 10, textLineY[textLine], TextCenterX);
			textLine++;
		}
		if ( (game->SentenceLineY < 59)&&(textLine < 13) )
		{
			visuals->DrawTextOnScreenBuffer(1,"SLNTHERO@aol.com", 0, 255, 0, 0, 10, textLineY[textLine], TextCenterX);
			textLine++;
		}

		visuals->DrawTextOnScreenBuffer(1,"__________________________________", 255, 255, 0, 0, 0, 555, TextCenterX);
		buttons->SetUpNewButtonForUserInput(6, 1, 0, 596, 200, ButtonCenterX);

		SDL_Flip(visuals->Screen);
		game->GameScreenDisplayed = true;
	}

	if (control->JoystickDirection[Any] == UP)
	{
		if (game->ParagraphPosition > 0)  game->ParagraphPosition--;

		game->SentenceLineY = paragraphPositionIndex[game->ParagraphPosition];

		game->GameScreenDisplayed = false;
		audio->PlayDigitalSoundFX(2);
	}
	else if (control->JoystickDirection[Any] == DOWN)
	{
		if (game->ParagraphPosition < 10)  game->ParagraphPosition++;

		game->SentenceLineY = paragraphPositionIndex[game->ParagraphPosition];

		game->GameScreenDisplayed = false;
		audio->PlayDigitalSoundFX(2);
	}

	if (buttons->ButtonClickedByUser(6) == true)
	{
		game->GameScreenDisplayed = false;
		visuals->FadeOutScreenBuffer();
		buttons->DeleteAllRegisteredButtons();
		game->GameScreen = TitleScreen;
		game->CurrentlySelectedScreenOption = 0;
	}
}

//-------------------------------------------------------------------------------------------------
void LoadOptionsAndHighScores(void)
{
char filename[256];
fstream fileStream;
char textBuffer[20];
Uint8 gameMode, rank;

	strcpy(filename, settings->GetUserConfigPath()); // OPTIONS...
	strcat(filename, "TC100_01.cfg");

	fileStream.open (filename, fstream::in);

	if (fileStream.is_open())
	{
		fileStream.getline (textBuffer, 20);
		tetri_EnginE->GameMode = atoi(textBuffer);

		fileStream.getline (textBuffer, 20);
		tetri_EnginE->NewGameGarbageLevel = atoi(textBuffer);

		fileStream.getline (textBuffer, 20);
		tetri_EnginE->NewGameStartingLevel = atoi(textBuffer);

		fileStream.getline (textBuffer, 20);
		tetri_EnginE->DisplayNextPiece = atoi(textBuffer);

		fileStream.getline (textBuffer, 20);
		tetri_EnginE->DisplayDropShadow = atoi(textBuffer);

		fileStream.getline (textBuffer, 20);
		tetri_EnginE->DisplayBackground = atoi(textBuffer);

		fileStream.getline (textBuffer, 20);
		tetri_EnginE->PressingUPAction = atoi(textBuffer);

		fileStream.getline (textBuffer, 20);
		audio->MusicVolume = atoi(textBuffer);

		fileStream.getline (textBuffer, 20);
		audio->SoundVolume = atoi(textBuffer);

		fileStream.getline (textBuffer, 20);
		audio->CurrentlySelectedMusicTrack = atoi(textBuffer);

		fileStream.close();
	}

	strcpy(filename, settings->GetUserConfigPath()); // HIGH SCORES...
	strcat(filename, "TC100_02.cfg");

	fileStream.open (filename, fstream::in);

	if (fileStream.is_open())
	{
		for (gameMode = 0; gameMode < 7; gameMode++)
		{
			for (rank = 0; rank < 5; rank++)
			{
				fileStream.getline (textBuffer, 20);
				strcpy(tetri_EnginE->HighScoresName[gameMode][rank], textBuffer);

				fileStream.getline (textBuffer, 20);
				tetri_EnginE->HighScoresLevel[gameMode][rank] = atoi(textBuffer);

				fileStream.getline (textBuffer, 20);
				tetri_EnginE->HishScoresLines[gameMode][rank] = atoi(textBuffer);

				fileStream.getline (textBuffer, 20);
				tetri_EnginE->HishScoresScore[gameMode][rank] = atoi(textBuffer);
			}
		}

		fileStream.close();
	}
}

//-------------------------------------------------------------------------------------------------
void SaveOptionsAndHighScores(void)
{
char filename[256];
fstream fileStream;
char textBuffer[20];
Uint8 gameMode, rank;

	strcpy(filename, settings->GetUserConfigPath()); // OPTIONS...
	strcat(filename, "TC100_01.cfg");

	fileStream.open (filename, fstream::out);

	if (fileStream.is_open())
	{
		sprintf(textBuffer, "%d", tetri_EnginE->GameMode);
		fileStream<<textBuffer;
		fileStream<<"\n";

		sprintf(textBuffer, "%d", tetri_EnginE->NewGameGarbageLevel);
		fileStream<<textBuffer;
		fileStream<<"\n";

		sprintf(textBuffer, "%d", tetri_EnginE->NewGameStartingLevel);
		fileStream<<textBuffer;
		fileStream<<"\n";

		sprintf(textBuffer, "%d", tetri_EnginE->DisplayNextPiece);
		fileStream<<textBuffer;
		fileStream<<"\n";

		sprintf(textBuffer, "%d", tetri_EnginE->DisplayDropShadow);
		fileStream<<textBuffer;
		fileStream<<"\n";

		sprintf(textBuffer, "%d", tetri_EnginE->DisplayBackground);
		fileStream<<textBuffer;
		fileStream<<"\n";

		sprintf(textBuffer, "%d", tetri_EnginE->PressingUPAction);
		fileStream<<textBuffer;
		fileStream<<"\n";

		sprintf(textBuffer, "%d", audio->MusicVolume);
		fileStream<<textBuffer;
		fileStream<<"\n";

		sprintf(textBuffer, "%d", audio->SoundVolume);
		fileStream<<textBuffer;
		fileStream<<"\n";

		sprintf(textBuffer, "%d", audio->CurrentlySelectedMusicTrack);
		fileStream<<textBuffer;
		fileStream<<"\n";

		fileStream.close();
	}

	strcpy(filename, settings->GetUserConfigPath()); // HIGH SCORES...
	strcat(filename, "TC100_02.cfg");

	fileStream.open (filename, fstream::out);

	if (fileStream.is_open())
	{
		for (gameMode = 0; gameMode < 7; gameMode++)
		{
			for (rank = 0; rank < 5; rank++)
			{
				strcpy(textBuffer, tetri_EnginE->HighScoresName[gameMode][rank]);
				fileStream<<textBuffer;
				fileStream<<"\n";

				sprintf(textBuffer, "%d", tetri_EnginE->HighScoresLevel[gameMode][rank]);
				fileStream<<textBuffer;
				fileStream<<"\n";

				sprintf(textBuffer, "%d", tetri_EnginE->HishScoresLines[gameMode][rank]);
				fileStream<<textBuffer;
				fileStream<<"\n";

				sprintf(textBuffer, "%d", tetri_EnginE->HishScoresScore[gameMode][rank]);
				fileStream<<textBuffer;
				fileStream<<"\n";
			}
		}

		fileStream.close();
	}
}

//-------------------------------------------------------------------------------------------------
int main( int argc, char* args[] )
{
	if ( SDL_Init( SDL_INIT_AUDIO | SDL_INIT_VIDEO | SDL_INIT_TIMER ) == -1 )
	{
		fprintf(stderr, "Could not initialize SDL: %s.\n", SDL_GetError());
		return(-1);
	}
	else fprintf(stdout, "SDL (everything) initialized...\n");
	atexit(SDL_Quit);

	visuals = new Visuals();
	game = new Game();
	control = new Control();
	audio = new Audio();
	tetri_EnginE = new Tetri_EnginE();
	buttons = new Buttons();
	settings = new Settings(0, 0);

	SDL_WM_SetCaption("TetriCrisis 100% Version 5.9 Remix", NULL);
	SDL_Surface *littleIcon;
	littleIcon = SDL_LoadBMP("data/visuals/icon.bmp");
	SDL_WM_SetIcon(littleIcon, NULL);

	putenv(strdup("SDL_VIDEO_CENTERED=1"));

	visuals->Screen = SDL_SetVideoMode(640, 640, 16, SDL_SWSURFACE|SDL_ASYNCBLIT);
	if ( visuals->Screen == NULL )
	{
		fprintf(stderr, "Couldn't set 640x640 video mode: %s\n", SDL_GetError());
		return(-1);
	}
	else fprintf(stdout, "SDL SetVideoMode initialized...\n");

	SDL_SetClipRect(visuals->Screen, NULL);

	if ( TTF_Init() == -1 )
	{
		fprintf(stderr, "TTF_Init: %s\n", TTF_GetError());
		return(-1);
	}
	else fprintf(stdout, "SDL TTF initialized...\n");

	visuals->FontLibrary[0] = TTF_OpenFont( "data/fonts/Autism_Screen_Font.font", 38 );
	if (!visuals->FontLibrary[0])
	{
		fprintf(stderr, "TTF_OpenFont: %s\n", TTF_GetError());
		return(-1);
	}
	else fprintf(stdout, "SDL TTF (font1) initialized...\n");

	visuals->FontLibrary[1] = TTF_OpenFont( "data/fonts/Game_Font.font", 33 );
	if (!visuals->FontLibrary[1])
	{
		fprintf(stderr, "TTF_OpenFont: %s\n", TTF_GetError());
		return(-1);
	}
	else fprintf(stdout, "SDL TTF (font2) initialized...\n");

	if (visuals->LoadAllSpritesIntoMemory() == -1)
	{
		fprintf(stderr, "Could not load visuals");
		return(-1);
	}
	else fprintf(stdout, "Sprites initialized...\n");


	if (buttons->LoadAllButtonsIntoMemoryAndInitialize() == -1)
	{
		fprintf(stderr, "Could not load buttons");
		return(-1);
	}
	else fprintf(stdout, "Buttons initialized...\n");

	if(Mix_OpenAudio(MIX_DEFAULT_FREQUENCY/*44100*/, MIX_DEFAULT_FORMAT, 1/*MIX_DEFAULT_CHANNELS*/, 512)==-1)
	{
		fprintf(stderr, "Mix_OpenAudio: %s\n", Mix_GetError());
		audio->SDL_Audio_Enabled = false;
	}
	else {audio->SDL_Audio_Enabled = true; fprintf(stdout, "SDL Mixer initialized...\n");}

	audio->LoadMusicIntoMemory();

	Mix_AllocateChannels(16);

	for (int channel = 0; channel < 16; channel++)
	{
		Mix_Volume( channel, audio->SoundVolume);
	}
	audio->LoadDigitalSoundFXIntoMemory();

	if (SDL_NumJoysticks()>0)
	{
		control->joystick1 = SDL_JoystickOpen(0);
		fprintf(stdout, "Joystick 1 initialized...\n");
	}

	if (SDL_NumJoysticks()>1)
	{
		control->joystick2 = SDL_JoystickOpen(1);
	}

	srand( (unsigned)time( NULL ) );

	fprintf(stdout, "EVERYTHING working...\n");

	visuals->EraseScreenBufferWithColor(0, 0, 0);
	visuals->DisplaySpriteOnScreenBufferGlass(4, 0, 0, 255);

	for (Uint16 tileScreenY = 0; tileScreenY < 640; tileScreenY+=12)
		for (Uint16 tileScreenX = 0; tileScreenX < 640; tileScreenX+=12)
			visuals->DisplaySpriteOnScreenBufferGlass(0, tileScreenX, tileScreenY, 127);

	SDL_BlitSurface(visuals->Screen, NULL, visuals->KremlinAlphaDark, NULL);

	LoadOptionsAndHighScores();

	while (game->EXITgame == false)
	{
        game->SystemTicks = SDL_GetTicks();
        game->NextFrameTicks = game->SystemTicks + 47;

		while( SDL_PollEvent( &game->Event ) )
		{

		}

		control->GetInputFromUser();

        if (game->GameScreen == PleaseVisitWebSiteScreen)  DisplayPleaseVisitWebSiteScreen();
        else if (game->GameScreen == PublishedByclnetScreen)  DisplayPublishedByclnetScreen();
        else if (game->GameScreen == SDLInformationScreen)  DisplaySDLInformationScreen();
        else if (game->GameScreen == SilentHeroProductionsScreen)  DisplaySilentHeroProductionsScreen();
        else if (game->GameScreen == TitleScreen)  DisplayTitleScreen();
        else if (game->GameScreen == MusicSelectionScreen)  DisplayMusicSelectionScreen();
        else if (game->GameScreen == PlayingTetri_GameScreen)  DisplayPlayingTetri_GameScreen();
        else if (game->GameScreen == GameOverScreen)  DisplayGameOverScreen();
        else if (game->GameScreen == OptionsScreen)  DisplayOptionsScreen();
        else if (game->GameScreen == HighScoresScreen)  DisplayHighScoresScreen();
        else if (game->GameScreen == NewHighScoreNameInputScreen)  DisplayNewHighScoreNameInputScreen();
        else if (game->GameScreen == StaffScreen)  DisplayStaffScreen();
        else if (game->GameScreen == HowToPlayScreen)  DisplayHowToPlayScreen();
        else if (game->GameScreen == HistoryScreen)  DisplayHistoryScreen();

		Mix_VolumeMusic(audio->MusicVolume);

        game->SystemTicks = SDL_GetTicks();
        if (game->NextFrameTicks > game->SystemTicks)  SDL_Delay(game->NextFrameTicks-game->SystemTicks);
	}

	SaveOptionsAndHighScores();

	if ( SDL_JoystickOpened(0) )  SDL_JoystickClose(control->joystick1);
	if ( SDL_JoystickOpened(1) )  SDL_JoystickClose(control->joystick2);

	buttons->UnloadAllButtonsFromMemory();
	visuals->UnloadAllSpritesFromMemory();

	audio->UnloadDigitalSoundFXFromMemory();
	Mix_AllocateChannels(0);
	audio->UnloadMusicFromMemory();
	Mix_CloseAudio();

	SDL_Quit();

	delete visuals;
	delete game;
	delete control;
	delete audio;
	delete tetri_EnginE;
	delete buttons;
	delete settings;

	return 0;
}

// A 100% By JeZ+Lee!
