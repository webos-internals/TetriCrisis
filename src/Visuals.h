//Visuals_CLASS.h

#include "SDL.h"
#include "SDL_ttf.h"
#include "SDL_mixer.h"
#include "SDL_image.h"
//#include "SDL_rotozoom.h"

//-------------------------------------------------------------------------------------------------
#define TextLeftX			0
#define TextCenterX			1
#define TextRightX			2

#define SpriteTotal			18

class Visuals
{
public:

	Visuals(void);
	virtual ~Visuals(void);

	SDL_Surface *Screen;

	SDL_Surface *KremlinAlphaDark;

	SDL_Surface *Sprite[SpriteTotal];

	TTF_Font *FontLibrary[2];
	char VariableText[64];

	int LoadAllSpritesIntoMemory(void);
	void UnloadAllSpritesFromMemory(void);
	void EraseScreenBufferWithColor(Sint32 red, Sint32 green, Sint32 blue);
	void DisplaySpriteOnScreenBufferGlass(Sint8 spriteNumber, Sint16 xScreenPos, Sint16 yScreenPos, Uint8 alpha);
	void DisplaySpriteOnScreenBufferRotoZoom(Sint8 spriteNumber, Sint16 xScreenPos, Sint16 yScreenPos, double angle, double zoom);
	void FadeInScreenBuffer(void);
	void FadeOutScreenBuffer(void);
	void DrawTextOnScreenBuffer(Uint8 fontNumber, const char *text, Sint32 red, Sint32 green, Sint32 blue, Sint32 alpha, Sint32 xScreenPos, Sint32 yScreenPos, Uint8 xJustification);
	void DrawTextOnScreenBufferFast(Uint8 fontNumber, const char *text, Sint32 red, Sint32 green, Sint32 blue, Sint32 alpha, Sint32 xScreenPos, Sint32 yScreenPos, Uint8 xJustification);
};
