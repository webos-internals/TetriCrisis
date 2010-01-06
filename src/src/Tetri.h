//Tetri_CLASS.h

#include "SDL.h"
#include "SDL_ttf.h"
#include "SDL_mixer.h"
#include "SDL_image.h"
//#include "SDL_rotozoom.h"

//-------------------------------------------------------------------------------------------------
#define OriginalMode			0
#define Challenge25LineMode		1
#define TimeAttack30Mode		2
#define TimeAttack60Mode		3
#define TimeAttack120Mode		4
#define GarbageMode				5
#define CrisisMode				6

class Tetri_EnginE
{
public:

	Uint8 PieceData [8] [5] [17];
	Uint8 Playfield [15] [21];

	Uint8 Piece;
	Sint8 PieceMovementDelay;
	Uint8 PieceRotation;
	Sint16 PiecePlayfieldX;
	Sint16 PiecePlayfieldY;
	Sint16 PieceScreenX;
	Sint16 PieceScreenY;
	Uint8 NextPiece;

	Uint32 Score;
	Uint16 DropScoreBonus;
	Uint16 Lines;
	Uint8 Level;

	Uint16 PieceFallCountdownTimer;

	bool ScreenDirty;

	Uint8 GameMode;
	Uint8 NewGameGarbageLevel;
	Uint8 NewGameStartingLevel;
	Uint8 DisplayNextPiece;
	Uint8 DisplayDropShadow;
	Uint8 DisplayBackground;
	Uint8 PressingUPAction;

	Uint16 TimeAttackTimer;
	Uint16 CrisisModeTimer;
	bool AddIncompleteLineWhenAnimationFinished;


	Uint16 CrisisModeDangerTimer;

	bool RotationDirection;

	char HighScoresName[7][5][12];
	Uint16 HighScoresLevel[7][5];
	Uint16 HishScoresLines[7][5];
	Uint32 HishScoresScore[7][5];

	Uint8 NewHighScoreIndex;
	Uint8 NewHighScoreNameIndex;

	Uint16 NewHighScoreFlashTimer;

	bool NewTopHighScoreAchieved;

	bool CrisisModeWon;
	bool EasterEggStaffRoll;

	Sint16 FlashAnimationTimer;
	Sint8 FlashAnimationTimerLevelUp;
	Sint8 FlashAnimationTimerHighScore;
	#define FlashCompletedLines			0
	#define ClearCompletedLines			1
	#define DisplayGameOver				2
	Sint8 WhichAnimationToDisplay;
	Sint16 GameOverDisplayFrame;
	Sint8 NumberOfCompletedLines;
	Sint8 NumberOfProcessedCompletedLines;
	Uint8 PlayfieldTEMP[12][19];

	Tetri_EnginE(void);
	virtual ~Tetri_EnginE(void);

	void InitializePieceData(void);
	void ClearPlayfieldWithCollisionDetection(void);
	Uint8 GetRandomPiece(void);
	Uint16 GetNewPieceFallCountdownTimer(void);
	void AddPieceToPlayfieldMemory(void);
	void DeletePieceFromPlayfieldMemory(void);
	bool PieceCollision(void);
	bool PieceCollisionLEFT(void);
	bool PieceCollisionRIGHT(void);
	bool PieceCollisionDOWN(void);
	bool BoxesOnTopRowOfPlayfield(void);
	void FlashCompletedLinesOnScreen(void);
	void ClearCompletedLinesOnScreen(void);
	void CheckForCompletedLinesAndClear(void);
	void AddAnIncompleteLineToThePlayfield(void);
	void MovePieceLeft(void);
	void MovePieceRight(void);
	void SetupNewPiece(void);
	void MovePieceDown(void);
	void MovePieceDownFast(void);
	void RotatePieceClockwise(void);
	void RotatePieceCounterClockwise(void);
	void SetUpForNewGame(void);
	void DrawEntirePlayfieldScreenOntoScreenBuffer(bool displayPieceAndShadow);
};
