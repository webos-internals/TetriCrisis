// Tetri_CLASS.cpp

#include "SDL.h"
#include "SDL_ttf.h"
#include "SDL_mixer.h"
#include "SDL_image.h"
//#include "SDL_rotozoom.h"

#include "Tetri.h"
#include "Visuals.h"
#include "Game.h"
#include "Audio.h"
#include "Control.h"

extern Visuals* visuals;
extern Game* game;
extern Audio* audio;
extern Control* control;

/*
     _________________
    \___   _   _  ___/
       / / / / / /             TM
  T+B / / / / / / PerfecT+EnginE   Version 5.0  [SinglE+PlayeR]
   __/ /_/ /_/ /__
 /________________\
*/
//-------------------------------------------------------------------------------------------------
Tetri_EnginE::Tetri_EnginE(void)
{
Uint8 gameMode;

	ScreenDirty = true;
	GameMode = OriginalMode;
	NewGameGarbageLevel = 0;
	NewGameStartingLevel = 0;
	DisplayNextPiece = 1;
	DisplayDropShadow = 0;
	DisplayBackground = 0;
	PressingUPAction = 0;
	TimeAttackTimer = 0;
	CrisisModeTimer = 0;
	CrisisModeDangerTimer = 0;

	RotationDirection = 0;

	for (gameMode = 0; gameMode < 7; gameMode++)
	{
		strcpy(HighScoresName[gameMode][0],"JeZ+Lee");//'JeZ+Lee';
		HighScoresLevel[gameMode][0] = 10;
		HishScoresLines[gameMode][0] = 100;
		HishScoresScore[gameMode][0] = 5000;

		strcpy(HighScoresName[gameMode][1],"JeZ+Lee");//'JeZ+Lee';
		HighScoresLevel[gameMode][1] = 9;
		HishScoresLines[gameMode][1] = 90;
		HishScoresScore[gameMode][1] = 4000;

		strcpy(HighScoresName[gameMode][2],"JeZ+Lee");//'JeZ+Lee';
		HighScoresLevel[gameMode][2] = 8;
		HishScoresLines[gameMode][2] = 80;
		HishScoresScore[gameMode][2] = 3000;

		strcpy(HighScoresName[gameMode][3],"JeZ+Lee");//'JeZ+Lee';
		HighScoresLevel[gameMode][3] = 7;
		HishScoresLines[gameMode][3] = 70;
		HishScoresScore[gameMode][3] = 2000;

		strcpy(HighScoresName[gameMode][4],"JeZ+Lee");//'JeZ+Lee';
		HighScoresLevel[gameMode][4] = 6;
		HishScoresLines[gameMode][4] = 60;
		HishScoresScore[gameMode][4] = 1000;
	}

	NewHighScoreIndex = 5;
	NewHighScoreNameIndex = 0;

	NewTopHighScoreAchieved = false;

	FlashAnimationTimer = -1;
	FlashAnimationTimerLevelUp = -1;
	FlashAnimationTimerHighScore = -1;
	WhichAnimationToDisplay = -1;
	NumberOfCompletedLines = -1;
	NumberOfProcessedCompletedLines = -1;

	GameOverDisplayFrame = -1;

	AddIncompleteLineWhenAnimationFinished = false;
}

//-------------------------------------------------------------------------------------------------
Tetri_EnginE::~Tetri_EnginE(void)
{

}

//-------------------------------------------------------------------------------------------------
void Tetri_EnginE::InitializePieceData(void)
{
Uint8 piece, rotation, box;

    for (piece = 0; piece < 8; piece++)
        for (rotation = 0; rotation < 5; rotation++)
            for (box = 0; box < 17; box++)
                PieceData [piece] [rotation] [box] = 0;

    //RED "S Piece"...
    PieceData [1] [1] [10] = 1; // 01 02 03 04
    PieceData [1] [1] [11] = 1; // 05 06 07 08
    PieceData [1] [1] [13] = 1; // 09 [] [] 12
    PieceData [1] [1] [14] = 1; // [] [] 15 16

    PieceData [1] [2] [ 5] = 1;
    PieceData [1] [2] [ 9] = 1;
    PieceData [1] [2] [10] = 1;
    PieceData [1] [2] [14] = 1;

    PieceData [1] [3] [10] = 1;
    PieceData [1] [3] [11] = 1;
    PieceData [1] [3] [13] = 1;
    PieceData [1] [3] [14] = 1;

    PieceData [1] [4] [ 5] = 1;
    PieceData [1] [4] [ 9] = 1;
    PieceData [1] [4] [10] = 1;
    PieceData [1] [4] [14] = 1;


    //ORANGE "Z Piece"...
    PieceData [2] [1] [ 9] = 1;
    PieceData [2] [1] [10] = 1;
    PieceData [2] [1] [14] = 1;
    PieceData [2] [1] [15] = 1;

    PieceData [2] [2] [ 6] = 1;
    PieceData [2] [2] [ 9] = 1;
    PieceData [2] [2] [10] = 1;
    PieceData [2] [2] [13] = 1;

    PieceData [2] [3] [ 9] = 1;
    PieceData [2] [3] [10] = 1;
    PieceData [2] [3] [14] = 1;
    PieceData [2] [3] [15] = 1;

    PieceData [2] [4] [ 6] = 1;
    PieceData [2] [4] [ 9] = 1;
    PieceData [2] [4] [10] = 1;
    PieceData [2] [4] [13] = 1;


    //AQUA "T Piece"...
    PieceData [3] [1] [ 9] = 1;
    PieceData [3] [1] [10] = 1;
    PieceData [3] [1] [11] = 1;
    PieceData [3] [1] [14] = 1;

    PieceData [3] [2] [ 6] = 1;
    PieceData [3] [2] [ 9] = 1;
    PieceData [3] [2] [10] = 1;
    PieceData [3] [2] [14] = 1;

    PieceData [3] [3] [ 6] = 1;
    PieceData [3] [3] [ 9] = 1;
    PieceData [3] [3] [10] = 1;
    PieceData [3] [3] [11] = 1;

    PieceData [3] [4] [ 6] = 1;
    PieceData [3] [4] [10] = 1;
    PieceData [3] [4] [11] = 1;
    PieceData [3] [4] [14] = 1;


    //YELLOW "L Piece"...
    PieceData [4] [1] [ 9] = 1;
    PieceData [4] [1] [10] = 1;
    PieceData [4] [1] [11] = 1;
    PieceData [4] [1] [13] = 1;

    PieceData [4] [2] [ 5] = 1;
    PieceData [4] [2] [ 6] = 1;
    PieceData [4] [2] [10] = 1;
    PieceData [4] [2] [14] = 1;

    PieceData [4] [3] [ 7] = 1;
    PieceData [4] [3] [ 9] = 1;
    PieceData [4] [3] [10] = 1;
    PieceData [4] [3] [11] = 1;

    PieceData [4] [4] [ 6] = 1;
    PieceData [4] [4] [10] = 1;
    PieceData [4] [4] [14] = 1;
    PieceData [4] [4] [15] = 1;


    //GREEN "Backwards L Piece"...
    PieceData [5] [1] [ 9] = 1;
    PieceData [5] [1] [10] = 1;
    PieceData [5] [1] [11] = 1;
    PieceData [5] [1] [15] = 1;

    PieceData [5] [2] [ 6] = 1;
    PieceData [5] [2] [10] = 1;
    PieceData [5] [2] [13] = 1;
    PieceData [5] [2] [14] = 1;

    PieceData [5] [3] [ 5] = 1;
    PieceData [5] [3] [ 9] = 1;
    PieceData [5] [3] [10] = 1;
    PieceData [5] [3] [11] = 1;

    PieceData [5] [4] [ 6] = 1;
    PieceData [5] [4] [ 7] = 1;
    PieceData [5] [4] [10] = 1;
    PieceData [5] [4] [14] = 1;


    //BLUE "Box Piece"...
    PieceData [6] [1] [10] = 1;
    PieceData [6] [1] [11] = 1;
    PieceData [6] [1] [14] = 1;
    PieceData [6] [1] [15] = 1;

    PieceData [6] [2] [10] = 1;
    PieceData [6] [2] [11] = 1;
    PieceData [6] [2] [14] = 1;
    PieceData [6] [2] [15] = 1;

    PieceData [6] [3] [10] = 1;
    PieceData [6] [3] [11] = 1;
    PieceData [6] [3] [14] = 1;
    PieceData [6] [3] [15] = 1;

    PieceData [6] [4] [10] = 1;
    PieceData [6] [4] [11] = 1;
    PieceData [6] [4] [14] = 1;
    PieceData [6] [4] [15] = 1;


    //PURPLE "Line Piece"...
    PieceData [7] [1] [ 9] = 1;
    PieceData [7] [1] [10] = 1;
    PieceData [7] [1] [11] = 1;
    PieceData [7] [1] [12] = 1;

    PieceData [7] [2] [ 2] = 1;
    PieceData [7] [2] [ 6] = 1;
    PieceData [7] [2] [10] = 1;
    PieceData [7] [2] [14] = 1;

    PieceData [7] [3] [ 9] = 1;
    PieceData [7] [3] [10] = 1;
    PieceData [7] [3] [11] = 1;
    PieceData [7] [3] [12] = 1;

    PieceData [7] [4] [ 2] = 1;
    PieceData [7] [4] [ 6] = 1;
    PieceData [7] [4] [10] = 1;
    PieceData [7] [4] [14] = 1;
}

//-------------------------------------------------------------------------------------------------
void Tetri_EnginE::ClearPlayfieldWithCollisionDetection(void)
{
Uint8 x, y;

	for (y = 0; y < 21; y++)
		for (x = 0; x < 15; x++)
			Playfield[x][y] = 8;

	for (y = 0; y < 19; y++)
		for (x = 2; x < 12; x++)
			Playfield[x][y] = 0;
}

//-------------------------------------------------------------------------------------------------
Uint8 Tetri_EnginE::GetRandomPiece(void)
{
Uint32 random = rand()%100;

	if      (random < 20)  return(1);
    else if (random < 40)  return(2);
    else if (random < 54)  return(3);
    else if (random < 67)  return(4);
    else if (random < 80)  return(5);
    else if (random < 92)  return(6);
	else  return(7);
}

//-------------------------------------------------------------------------------------------------
Uint16 Tetri_EnginE::GetNewPieceFallCountdownTimer(void)
{
Sint16 returnValue;

	if (GameMode != CrisisMode)
	{
		returnValue = 42 - (2 * Level);
		if (returnValue < 0)  returnValue = 2;
	}
	else
	{
		returnValue = 42 - (4 * Level);
		if (returnValue < 0)  returnValue = 2;
	}

	return(returnValue);
}

//-------------------------------------------------------------------------------------------------
void Tetri_EnginE::AddPieceToPlayfieldMemory(void)
{
    if (PieceData [Piece] [PieceRotation] [ 1] == 1)
        Playfield [PiecePlayfieldX  ] [PiecePlayfieldY  ] = Piece;
    if (PieceData [Piece] [PieceRotation] [ 2] == 1)
        Playfield [PiecePlayfieldX+1] [PiecePlayfieldY  ] = Piece;
    if (PieceData [Piece] [PieceRotation] [ 3] == 1)
        Playfield [PiecePlayfieldX+2] [PiecePlayfieldY  ] = Piece;
    if (PieceData [Piece] [PieceRotation] [ 4] == 1)
        Playfield [PiecePlayfieldX+3] [PiecePlayfieldY  ] = Piece;

    if (PieceData [Piece] [PieceRotation] [ 5] == 1)
        Playfield [PiecePlayfieldX  ] [PiecePlayfieldY+1] = Piece;
    if (PieceData [Piece] [PieceRotation] [ 6] == 1)
        Playfield [PiecePlayfieldX+1] [PiecePlayfieldY+1] = Piece;
    if (PieceData [Piece] [PieceRotation] [ 7] == 1)
        Playfield [PiecePlayfieldX+2] [PiecePlayfieldY+1] = Piece;
    if (PieceData [Piece] [PieceRotation] [ 8] == 1)
        Playfield [PiecePlayfieldX+3] [PiecePlayfieldY+1] = Piece;

    if (PieceData [Piece] [PieceRotation] [ 9] == 1)
        Playfield [PiecePlayfieldX  ] [PiecePlayfieldY+2] = Piece;
    if (PieceData [Piece] [PieceRotation] [10] == 1)
        Playfield [PiecePlayfieldX+1] [PiecePlayfieldY+2] = Piece;
    if (PieceData [Piece] [PieceRotation] [11] == 1)
        Playfield [PiecePlayfieldX+2] [PiecePlayfieldY+2] = Piece;
    if (PieceData [Piece] [PieceRotation] [12] == 1)
        Playfield [PiecePlayfieldX+3] [PiecePlayfieldY+2] = Piece;

    if (PieceData [Piece] [PieceRotation] [13] == 1)
        Playfield [PiecePlayfieldX  ] [PiecePlayfieldY+3] = Piece;
    if (PieceData [Piece] [PieceRotation] [14] == 1)
        Playfield [PiecePlayfieldX+1] [PiecePlayfieldY+3] = Piece;
    if (PieceData [Piece] [PieceRotation] [15] == 1)
        Playfield [PiecePlayfieldX+2] [PiecePlayfieldY+3] = Piece;
    if (PieceData [Piece] [PieceRotation] [16] == 1)
        Playfield [PiecePlayfieldX+3] [PiecePlayfieldY+3] = Piece;
}

//-------------------------------------------------------------------------------------------------
void Tetri_EnginE::DeletePieceFromPlayfieldMemory(void)
{
    if (PieceData [Piece] [PieceRotation] [ 1] == 1)
        Playfield [PiecePlayfieldX  ] [PiecePlayfieldY  ] = 0;
    if (PieceData [Piece] [PieceRotation] [ 2] == 1)
        Playfield [PiecePlayfieldX+1] [PiecePlayfieldY  ] = 0;
    if (PieceData [Piece] [PieceRotation] [ 3] == 1)
        Playfield [PiecePlayfieldX+2] [PiecePlayfieldY  ] = 0;
    if (PieceData [Piece] [PieceRotation] [ 4] == 1)
        Playfield [PiecePlayfieldX+3] [PiecePlayfieldY  ] = 0;

    if (PieceData [Piece] [PieceRotation] [ 5] == 1)
        Playfield [PiecePlayfieldX  ] [PiecePlayfieldY+1] = 0;
    if (PieceData [Piece] [PieceRotation] [ 6] == 1)
        Playfield [PiecePlayfieldX+1] [PiecePlayfieldY+1] = 0;
    if (PieceData [Piece] [PieceRotation] [ 7] == 1)
        Playfield [PiecePlayfieldX+2] [PiecePlayfieldY+1] = 0;
    if (PieceData [Piece] [PieceRotation] [ 8] == 1)
        Playfield [PiecePlayfieldX+3] [PiecePlayfieldY+1] = 0;

    if (PieceData [Piece] [PieceRotation] [ 9] == 1)
        Playfield [PiecePlayfieldX  ] [PiecePlayfieldY+2] = 0;
    if (PieceData [Piece] [PieceRotation] [10] == 1)
        Playfield [PiecePlayfieldX+1] [PiecePlayfieldY+2] = 0;
    if (PieceData [Piece] [PieceRotation] [11] == 1)
        Playfield [PiecePlayfieldX+2] [PiecePlayfieldY+2] = 0;
    if (PieceData [Piece] [PieceRotation] [12] == 1)
        Playfield [PiecePlayfieldX+3] [PiecePlayfieldY+2] = 0;

    if (PieceData [Piece] [PieceRotation] [13] == 1)
        Playfield [PiecePlayfieldX  ] [PiecePlayfieldY+3] = 0;
    if (PieceData [Piece] [PieceRotation] [14] == 1)
        Playfield [PiecePlayfieldX+1] [PiecePlayfieldY+3] = 0;
    if (PieceData [Piece] [PieceRotation] [15] == 1)
        Playfield [PiecePlayfieldX+2] [PiecePlayfieldY+3] = 0;
    if (PieceData [Piece] [PieceRotation] [16] == 1)
        Playfield [PiecePlayfieldX+3] [PiecePlayfieldY+3] = 0;
}

//-------------------------------------------------------------------------------------------------
bool Tetri_EnginE::PieceCollision(void)
{
Sint8 x, y;
Uint8 box = 1;
bool returnValue = false;

    for (y = 0; y < 4; y++)
        for (x = 0; x < 4; x++)
            {
            if ( (Playfield [ PiecePlayfieldX + x ] [ PiecePlayfieldY + y ] > 0)
                &&(PieceData [Piece] [PieceRotation] [box] > 0) )
                    returnValue = true;

            box++;
            }

    return(returnValue);
}

//-------------------------------------------------------------------------------------------------
bool Tetri_EnginE::PieceCollisionLEFT(void)
{
Sint8 x, y;
Uint8 box = 1;
bool returnValue = false;

    for (y = 0; y < 4; y++)
        for (x = -1; x < 3; x++)
            {
            if ( (Playfield [PiecePlayfieldX + x] [PiecePlayfieldY + y] > 0)
               &&(PieceData [Piece] [PieceRotation] [box] > 0) )
                    returnValue = true;

            box++;
            }

    return(returnValue);
}

//-------------------------------------------------------------------------------------------------
bool Tetri_EnginE::PieceCollisionRIGHT(void)
{
Sint8 x, y;
Uint8 box = 1;
bool returnValue = false;

    for (y = 0; y < 4; y++)
        for (x = 1; x < 5; x++)
            {
            if ( (Playfield [PiecePlayfieldX + x] [PiecePlayfieldY + y] > 0)
               &&(PieceData [Piece] [PieceRotation] [box] > 0) )
                    returnValue = true;

            box++;
            }

    return(returnValue);
}

//-------------------------------------------------------------------------------------------------
bool Tetri_EnginE::PieceCollisionDOWN(void)
{
Sint8 x, y;
Uint8 box = 1;
bool returnValue = false;

	if (PiecePlayfieldX == -100 && PiecePlayfieldY == -100)  return(false);

    for (y = 1; y < 5; y++)
        for (x = 0; x < 4; x++)
            {
            if ( (Playfield [PiecePlayfieldX + x] [PiecePlayfieldY + y] > 0)
               &&(PieceData [Piece] [PieceRotation] [box] > 0) )
                    returnValue = true;

            box++;
            }

    return(returnValue);
}

//-------------------------------------------------------------------------------------------------
bool Tetri_EnginE::BoxesOnTopRowOfPlayfield(void)
{
Uint8 x;

	for (x = 2; x < 12; x++)
	{
		if (Playfield[x][0] > 0)  return(true);
	}

	return(false);
}

//-------------------------------------------------------------------------------------------------
void Tetri_EnginE::FlashCompletedLinesOnScreen(void)
{
Uint8 x, y;
Uint8 boxesInLineTotal;

	if (FlashAnimationTimer == 10 || FlashAnimationTimer == 8 || FlashAnimationTimer == 6 || FlashAnimationTimer == 4 || FlashAnimationTimer == 2)
	{
		for (y = 0; y < 19; y++)
		{
			boxesInLineTotal = 0;

			for (x = 2; x < 12; x++)
			{
				if (Playfield[x][y] > 0)  boxesInLineTotal++;
			}

			if (boxesInLineTotal == 10)
			{
				for (x = 2; x < 12; x++) Playfield[x][y] = 9;
			}
		}

		DrawEntirePlayfieldScreenOntoScreenBuffer(false);
		SDL_Flip(visuals->Screen);
	}
	else if (FlashAnimationTimer == 9 || FlashAnimationTimer == 7 || FlashAnimationTimer == 5 || FlashAnimationTimer == 3 || FlashAnimationTimer == 1)
	{
		for (y = 0; y < 19; y++)
		{
			boxesInLineTotal = 0;

			for (x = 2; x < 12; x++)
			{
				if (Playfield[x][y] > 0)  boxesInLineTotal++;
			}

			if (boxesInLineTotal == 10)
			{
				for (x = 2; x < 12; x++) Playfield[x][y] = PlayfieldTEMP[x][y];

			}
		}

		DrawEntirePlayfieldScreenOntoScreenBuffer(false);
		SDL_Flip(visuals->Screen);
	}

	if (FlashAnimationTimer == 0)
	{
		WhichAnimationToDisplay = ClearCompletedLines;
		FlashAnimationTimer = 10;

		NumberOfProcessedCompletedLines = 0;

		if (NumberOfCompletedLines == 4)  audio->PlayDigitalSoundFX(5);
	}
}

//-------------------------------------------------------------------------------------------------
void Tetri_EnginE::ClearCompletedLinesOnScreen(void)
{
Uint8 x, y;
Uint8 boxesInLineTotal;
Uint8 y2;

	if (FlashAnimationTimer > -1)  FlashAnimationTimer--;

	if (FlashAnimationTimer == 0)
	{
		for (y = 0; y < 19; y++)
		{
			boxesInLineTotal = 0;

			for (x = 2; x < 12; x++)
			{
				if (Playfield[x][y] > 0)  boxesInLineTotal++;
			}

			if (boxesInLineTotal == 10)
			{
				for (y2 = y; y2 > 0; y2--)
				{
					for (x = 2; x < 12; x++)
					{
						Playfield[x][y2] = Playfield[x][y2-1];
					}
				}

				for (x = 2; x < 12; x++)  Playfield[x][0] = 0;

				Lines++;
				if (Lines % 10 == 0)
				{
					Level++;

					audio->PlayDigitalSoundFX(6);
					FlashAnimationTimerLevelUp = 10;

					if ( (GameMode == CrisisMode)&&(Level == 7) )  audio->PlayMusic(15, -1);

					if ( (Level == 10)&&(GameMode == CrisisMode) )  { game->GameScreen = StaffScreen; CrisisModeWon = true; }
				}

				NumberOfProcessedCompletedLines++;

				y = 100;

				if (NumberOfProcessedCompletedLines < NumberOfCompletedLines)  FlashAnimationTimer = 10;

				audio->PlayDigitalSoundFX(4);
				DrawEntirePlayfieldScreenOntoScreenBuffer(false);
				SDL_Flip(visuals->Screen);
			}
		}
	}

	if (FlashAnimationTimer == 0 && NumberOfProcessedCompletedLines == NumberOfCompletedLines)
	{
		if (NumberOfCompletedLines == 1)  Score+= ( 40* (1+Level) );
		else if (NumberOfCompletedLines == 2)  Score+= ( 100* (1+Level) );
		else if (NumberOfCompletedLines == 3)  Score+= ( 300* (1+Level) );
		else if (NumberOfCompletedLines == 4)  Score+= ( 1200* (1+Level) );

		SetupNewPiece();

		NumberOfCompletedLines = -1;
		WhichAnimationToDisplay = -1;
	}
}

//-------------------------------------------------------------------------------------------------
void Tetri_EnginE::CheckForCompletedLinesAndClear(void)
{
Uint8 x, y;
Uint8 boxesInLineTotal;

	if (WhichAnimationToDisplay != -1)  return;

	NumberOfCompletedLines = 0;
	for (y = 0; y < 19; y++)
	{
		boxesInLineTotal = 0;

		for (x = 2; x < 12; x++)
		{
			if (Playfield[x][y] > 0)  boxesInLineTotal++;
		}

		if (boxesInLineTotal == 10)
		{
			NumberOfCompletedLines++;
		}
	}

	NumberOfProcessedCompletedLines = -1;
	if (NumberOfCompletedLines == 0)  return;

	for (y = 0; y < 19; y++)
	{
		for (x = 2; x < 12; x++)
		{
			PlayfieldTEMP[x][y] = Playfield[x][y];
		}
	}

	WhichAnimationToDisplay = FlashCompletedLines;
	FlashAnimationTimer = 10;
}

//-------------------------------------------------------------------------------------------------
void Tetri_EnginE::AddAnIncompleteLineToThePlayfield(void)
{
Uint8 x, y;

	for (x = 2; x < 12; x++)
	{
		if (Playfield[x][0] > 0)
		{
			GameOverDisplayFrame = 0;
			FlashAnimationTimer = 0;
			game->GameScreen = GameOverScreen;
			return;
		}
	}

	if (AddIncompleteLineWhenAnimationFinished == false)
	{
		if (PieceCollisionDOWN() == true)
		{
			AddPieceToPlayfieldMemory();
			Score+=DropScoreBonus;
			audio->PlayDigitalSoundFX(3);

			PiecePlayfieldX = -100;
			PiecePlayfieldY = -100;

			CheckForCompletedLinesAndClear();
			if (FlashAnimationTimer  == -1)  SetupNewPiece();
			else
			{
				AddIncompleteLineWhenAnimationFinished = true;
				return;
			}
		}
	}

	for (y = 0; y < 18; y++)
		for (x = 2; x < 12; x++)
			Playfield[x][y] = Playfield[x][y+1];

	Uint8 boxTotalForLineX = 0;
	for (Uint8 x = 2; x < 12; x++)
	{
		Uint32 random = rand()%7;

		if (random > 0)  boxTotalForLineX++;

		Playfield[x][18] = random;

		if ( (x == 11)&&(boxTotalForLineX == 10) )  Playfield[x][18] = 0;

		ScreenDirty = true;
		audio->PlayDigitalSoundFX(7);

	}
}

//-------------------------------------------------------------------------------------------------
void Tetri_EnginE::MovePieceLeft(void)
{
	if (PieceMovementDelay > -100)  PieceMovementDelay--;

	if (PieceMovementDelay > -1)  PieceMovementDelay = -1;

	if ( (PieceMovementDelay == -1)||(PieceMovementDelay == -3)||(PieceMovementDelay == -5)||(PieceMovementDelay < -6) )
	{
		if (PieceCollisionLEFT() == false)
		{
			PiecePlayfieldX--;
			PieceScreenX-=32;
			audio->PlayDigitalSoundFX(0);
			ScreenDirty = true;
		}
	}
}

//-------------------------------------------------------------------------------------------------
void Tetri_EnginE::MovePieceRight(void)
{
	if (PieceMovementDelay < 100)  PieceMovementDelay++;

	if (PieceMovementDelay < 1)  PieceMovementDelay = 1;

	if ( (PieceMovementDelay == 1)||(PieceMovementDelay == 3)||(PieceMovementDelay == 5)||(PieceMovementDelay > 6) )
	{
		if (PieceCollisionRIGHT() == false)
		{
			PiecePlayfieldX++;
			PieceScreenX+=32;
			audio->PlayDigitalSoundFX(0);
			ScreenDirty = true;
		}
	}
}

//-------------------------------------------------------------------------------------------------
void Tetri_EnginE::SetupNewPiece(void)
{
	Piece = NextPiece;
	PieceRotation = 1;
	PiecePlayfieldX = 5;
	PiecePlayfieldY = 0;
	PieceScreenX = ( 32 * (PiecePlayfieldX-1) ) + 15;
	PieceScreenY = -15;

	NextPiece = GetRandomPiece();

	if (PieceCollision() == true)
	{
		GameOverDisplayFrame = 0;
		FlashAnimationTimer = 0;
		game->GameScreen = GameOverScreen;
		return;
	}

	DropScoreBonus = 0;
	ScreenDirty = true;
}

//-------------------------------------------------------------------------------------------------
void Tetri_EnginE::MovePieceDown(void)
{
	if (PieceCollisionDOWN() == true)
	{
		AddPieceToPlayfieldMemory();
		Score+=DropScoreBonus;
		audio->PlayDigitalSoundFX(3);
		CheckForCompletedLinesAndClear();

		if (WhichAnimationToDisplay == -1)  SetupNewPiece();
	}
	else
	{
		PiecePlayfieldY++;
		PieceScreenY+=32;
		DropScoreBonus++;
		ScreenDirty = true;
	}
}

//-------------------------------------------------------------------------------------------------
void Tetri_EnginE::MovePieceDownFast(void)
{
	while(PieceCollisionDOWN() == false)
	{
		PiecePlayfieldY++;
		PieceScreenY+=32;
		DropScoreBonus++;
	}

	if (PieceCollisionDOWN() == true)
	{
		AddPieceToPlayfieldMemory();
		Score+=DropScoreBonus;
		audio->PlayDigitalSoundFX(3);
		CheckForCompletedLinesAndClear();
		if (WhichAnimationToDisplay == -1)  SetupNewPiece();
	}
}

//-------------------------------------------------------------------------------------------------
void Tetri_EnginE::RotatePieceClockwise(void)
{
	if (PieceRotation == 1)  PieceRotation = 4;
	else  PieceRotation--;

	if (PieceCollision() == true)
	{
		if (PieceRotation == 4)  PieceRotation = 1;
		else  PieceRotation++;

		if (RotationDirection == 0)  RotationDirection = 1;
		else  RotationDirection = 0;
	}
	else
	{
		audio->PlayDigitalSoundFX(1);
		ScreenDirty = true;
	}
}

//-------------------------------------------------------------------------------------------------
void Tetri_EnginE::RotatePieceCounterClockwise(void)
{
	if (PieceRotation == 4)  PieceRotation = 1;
	else  PieceRotation++;

	if (PieceCollision() == true)
	{
		if (PieceRotation == 1)  PieceRotation = 4;
		else  PieceRotation--;

		if (RotationDirection == 0)  RotationDirection = 1;
		else  RotationDirection = 0;
	}
	else
	{
		audio->PlayDigitalSoundFX(1);
		ScreenDirty = true;
	}
}

//-------------------------------------------------------------------------------------------------
void Tetri_EnginE::SetUpForNewGame(void)
{
	InitializePieceData();
	ClearPlayfieldWithCollisionDetection();

	Piece = GetRandomPiece();
	PieceRotation = 1;
	PiecePlayfieldX = 5;
	PiecePlayfieldY = 0;
	PieceScreenX = ( 32 * (PiecePlayfieldX-1) ) + 15;
	PieceScreenY = -15;

	NextPiece = GetRandomPiece();

	Score = 0;
	DropScoreBonus = 0;
	Lines = 0;
	Level = NewGameStartingLevel;

	PieceFallCountdownTimer = GetNewPieceFallCountdownTimer();

	Uint8 boxTotalForLineX = 0;
	Uint8 y = 18;
	for (Uint8 garbageLineCounter = 0; garbageLineCounter < NewGameGarbageLevel; garbageLineCounter++)
	{
		for (Uint8 x = 2; x < 12; x++)
		{
			Uint32 random = rand()%7;

			if (random > 0)  boxTotalForLineX++;

			if (GameMode != GarbageMode) Playfield[x][y] = random;
			else if (random > 0) Playfield[x][y] = 8;

			if ( (x == 11)&&(boxTotalForLineX == 10) )  Playfield[x][y] = 0;
		}

		boxTotalForLineX = 0;
		y--;
	}

	if (GameMode == TimeAttack30Mode)  TimeAttackTimer = 3000;
	else if (GameMode == TimeAttack60Mode)  TimeAttackTimer = 6000;
	else if (GameMode == TimeAttack120Mode)  TimeAttackTimer = 12000;

	CrisisModeTimer = 290;

	CrisisModeDangerTimer = 0;

	control->SingleMovementForJoystick = false;

	NewHighScoreIndex = 5;
	NewHighScoreNameIndex = 0;

	NewTopHighScoreAchieved = false;

	ScreenDirty = true;

	CrisisModeWon = false;
	EasterEggStaffRoll = false;

	game->StaffLineY[0] = 650;
	game->StaffLineY[1] = 690;

	game->StaffLineY[2] = 750;
	game->StaffLineY[3] = 790;

	game->StaffLineY[4] = 850;
	game->StaffLineY[5] = 890;

	game->StaffLineY[6] = 950;
	game->StaffLineY[7] = 990;

	game->StaffLineY[8] = 1050;
	game->StaffLineY[9] = 1090;

	game->StaffLineY[10] = 1150;
	game->StaffLineY[11] = 1190;

	game->StaffLineY[12] = 1250;
	game->StaffLineY[13] = 1290;

	game->StaffLineY[14] = 1350;
	game->StaffLineY[15] = 1390;

	game->StaffLineY[16] = 1450;
	game->StaffLineY[17] = 1490;

	game->StaffLineY[18] = 1550;
	game->StaffLineY[19] = 1590;

	game->StaffLineY[20] = 1650;
	game->StaffLineY[21] = 1690;

	game->StaffLineY[22] = 1750;
	game->StaffLineY[23] = 1790;

	game->StaffLineY[24] = 1850;
	game->StaffLineY[25] = 1890;

	game->StaffLineY[26] = 1950;
	game->StaffLineY[27] = 1990;

	game->StaffLineY[28] = 2050;
	game->StaffLineY[29] = 2090;

	game->StaffLineY[30] = 2350;
	game->StaffLineY[31] = 2410;
	game->StaffLineY[32] = 2450;
	game->StaffLineY[33] = 2510;

	game->StaffLineY[34] = 2570;

	NewHighScoreFlashTimer = 0;

	FlashAnimationTimer = -1;
	FlashAnimationTimerLevelUp = -1;
	FlashAnimationTimerHighScore = -1;
	WhichAnimationToDisplay = -1;
	NumberOfCompletedLines = -1;
	NumberOfProcessedCompletedLines = -1;

	GameOverDisplayFrame = -1;
}

//-------------------------------------------------------------------------------------------------
void Tetri_EnginE::DrawEntirePlayfieldScreenOntoScreenBuffer(bool displayPieceAndShadow)
{
Uint8 x, y, box;
Sint16 screenX = 15, screenY = -15;
Uint8 nextPieceDisplay[6][4];
Uint8 piecePlayfieldY_TEMP;

	if (Score > HishScoresScore[GameMode][0])
	{
		if (NewTopHighScoreAchieved == false)
		{
			audio->PlayDigitalSoundFX(9);
			FlashAnimationTimerHighScore = 10;
			NewTopHighScoreAchieved = true;
		}
	}

	if (DisplayBackground == 0)  visuals->DisplaySpriteOnScreenBufferGlass(4, 0, 0, 255);
	else  visuals->EraseScreenBufferWithColor(0, 0, 0);

	visuals->DrawTextOnScreenBuffer(1,"Hi-Score:", 255, 255, 255, 0, 420, 110, TextLeftX);

	if (NewTopHighScoreAchieved == false)  sprintf(visuals->VariableText, "%d", HishScoresScore[GameMode][0]);
	else  sprintf(visuals->VariableText, "%d", Score);

	visuals->DrawTextOnScreenBuffer(1,visuals->VariableText, 255, 255, 255, 0, 420, 140, TextLeftX);

	if ( (BoxesOnTopRowOfPlayfield() == true)&&(GameMode == CrisisMode) )
	{
		{
			visuals->DrawTextOnScreenBuffer(1,"<=DANGER!", 255, 0, 0, 0, 404, 0, TextLeftX);
		}
	}

	visuals->DrawTextOnScreenBuffer(1,"Lines:", 255, 255, 255, 0, 420, 290, TextLeftX);
	sprintf(visuals->VariableText, "%d", Lines);
	visuals->DrawTextOnScreenBuffer(1,visuals->VariableText, 255, 255, 255, 0, 520, 290, TextLeftX);

	if (FlashAnimationTimerHighScore == 10 || FlashAnimationTimerHighScore == 8 || FlashAnimationTimerHighScore == 6 || FlashAnimationTimerHighScore == 4 || FlashAnimationTimerHighScore == 2)
	{
		visuals->DrawTextOnScreenBuffer(1,"Score:", 0, 0, 0, 0, 420, 190, TextLeftX);
		sprintf(visuals->VariableText, "%d", Score);
		visuals->DrawTextOnScreenBuffer(1,visuals->VariableText, 0, 0, 0, 0, 420, 220, TextLeftX);
	}
	else if (FlashAnimationTimerHighScore == 9 || FlashAnimationTimerHighScore == 7 || FlashAnimationTimerHighScore == 5 || FlashAnimationTimerHighScore == 3 || FlashAnimationTimerHighScore < 2)
	{
		visuals->DrawTextOnScreenBuffer(1,"Score:", 255, 255, 255, 0, 420, 190, TextLeftX);
		sprintf(visuals->VariableText, "%d", Score);
		visuals->DrawTextOnScreenBuffer(1,visuals->VariableText, 255, 255, 255, 0, 420, 220, TextLeftX);
	}

	if (FlashAnimationTimerLevelUp == 10 || FlashAnimationTimerLevelUp == 8 || FlashAnimationTimerLevelUp == 6 || FlashAnimationTimerLevelUp == 4 || FlashAnimationTimerLevelUp == 2)
	{
		visuals->DrawTextOnScreenBuffer(1,"Level:", 0, 0, 0, 0, 420, 350, TextLeftX);
		sprintf(visuals->VariableText, "%d", Level);
		visuals->DrawTextOnScreenBuffer(1,visuals->VariableText, 0, 0, 0, 0, 520, 350, TextLeftX);
	}
	else if (FlashAnimationTimerLevelUp == 9 || FlashAnimationTimerLevelUp == 7 || FlashAnimationTimerLevelUp == 5 || FlashAnimationTimerLevelUp == 3 || FlashAnimationTimerLevelUp < 2)
	{
		visuals->DrawTextOnScreenBuffer(1,"Level:", 255, 255, 255, 0, 420, 350, TextLeftX);
		sprintf(visuals->VariableText, "%d", Level);
		visuals->DrawTextOnScreenBuffer(1,visuals->VariableText, 255, 255, 255, 0, 520, 350, TextLeftX);
	}

	Uint16 actualTimeAttackTimer = (TimeAttackTimer / 100);
	if ( (GameMode == TimeAttack30Mode)||(GameMode == TimeAttack60Mode)||(GameMode == TimeAttack120Mode) )
	{
		visuals->DrawTextOnScreenBuffer(1,"Time:", 255, 255, 255, 0, 420, 410, TextLeftX);
		sprintf(visuals->VariableText, "%d", actualTimeAttackTimer);
		visuals->DrawTextOnScreenBuffer(1,visuals->VariableText, 255, 255, 255, 0, 520, 410, TextLeftX);
	}
//------------------------------------------
	for (y = 0; y < 20; y++)
	{
		for (x = 1; x < 13; x++)
		{
			if (Playfield[x][y] != 0)
				visuals->DisplaySpriteOnScreenBufferGlass(Playfield[x][y]+8, screenX, screenY, 255);
			else if (DisplayBackground == 0)
				visuals->DisplaySpriteOnScreenBufferGlass(Playfield[x][y]+8, screenX, screenY, 127);

			screenX+=32;
		}

		screenY+=32;
		screenX = 15;
	}
//------------------------------------------
if ( (displayPieceAndShadow == true)&&(DisplayDropShadow == 1) )
{
	piecePlayfieldY_TEMP = PiecePlayfieldY;

	for (PiecePlayfieldY = PiecePlayfieldY; PiecePlayfieldY < 18; PiecePlayfieldY++)
	{
		if (PieceCollisionDOWN() == true)  break;
	}

	screenX = PieceScreenX;
	screenY = (32*PiecePlayfieldY) - 15;
	box = 1;

	if ( (PiecePlayfieldY - piecePlayfieldY_TEMP) > 4 )
	for (y = 0; y < 4; y++)
	{
		for (x = 0; x < 4; x++)
		{
			if (PieceData[Piece][PieceRotation][box] == 1)
				visuals->DisplaySpriteOnScreenBufferGlass(17, screenX, screenY, 127);

			screenX+=32;
			box++;
		}

		screenX = PieceScreenX;
		screenY+=32;
	}

	PiecePlayfieldY = piecePlayfieldY_TEMP;
}
//------------------------------------------
if (displayPieceAndShadow == true)
{
	screenX = PieceScreenX;
	screenY = PieceScreenY;
	box = 1;
	for (y = 0; y < 4; y++)
	{
		for (x = 0; x < 4; x++)
		{
			if (PieceData[Piece][PieceRotation][box] == 1)
			{
				if (PiecePlayfieldX > -1 && PiecePlayfieldY > -1)
					visuals->DisplaySpriteOnScreenBufferGlass(Piece+8, screenX, screenY, 255);

				if (PiecePlayfieldX > -1 && PiecePlayfieldY > -1)
					if (game->GameScreen == GameOverScreen)  visuals->DisplaySpriteOnScreenBufferGlass(17, screenX, screenY, 127);
			}

			screenX+=32;
			box++;
		}

		screenX = PieceScreenX;
		screenY+=32;
	}
}
//------------------------------------------
	for (y = 0; y < 4; y++)
		for (x = 0; x < 6; x++)
			nextPieceDisplay[x][y] = 8;

	for (y = 1; y < 3; y++)
		for (x = 1; x < 5; x++)
			nextPieceDisplay[x][y] = 0;

	box = 9;
	for (y = 1; y < 3; y++)
	{
		for (x = 1; x < 5; x++)
		{
			if (PieceData[NextPiece][1][box] == 1)  nextPieceDisplay[x][y] = NextPiece;
			box++;
		}
	}

	screenX = 420;
	screenY = 497;
	for (y = 0; y < 4; y++)
	{
		for (x = 0; x < 6; x++)
		{
			if (nextPieceDisplay[x][y] != 0)
			{
				if ((DisplayNextPiece == 0)&&(nextPieceDisplay[x][y] < 8) )
				{
					visuals->DisplaySpriteOnScreenBufferGlass(8, screenX, screenY, 128);
				}
				else  visuals->DisplaySpriteOnScreenBufferGlass(nextPieceDisplay[x][y]+8, screenX, screenY, 255);
			}
			else
				visuals->DisplaySpriteOnScreenBufferGlass(nextPieceDisplay[x][y]+8, screenX, screenY, 127);

			screenX+=32;
		}

		screenY+=32;
		screenX = 420;
	}

	visuals->DrawTextOnScreenBuffer(1,"NEXT", 255, 255, 255, 0, 467, 480, TextLeftX);
}
