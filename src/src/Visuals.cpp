// Visuals_CLASS.cpp

#include "SDL.h"
#include "SDL_ttf.h"
#include "SDL_mixer.h"
#include "SDL_image.h"
//#include "SDL_rotozoom.h"

#include "Visuals.h"

//-------------------------------------------------------------------------------------------------
Visuals::Visuals(void)
{

}

//-------------------------------------------------------------------------------------------------
Visuals::~Visuals(void)
{

}

//-------------------------------------------------------------------------------------------------
int Visuals::LoadAllSpritesIntoMemory(void)
{
SDL_Surface * surface;

	surface = SDL_LoadBMP("data/visuals/FadeIn_FadeOut_Screen.bmp");
	Sprite[0] = SDL_DisplayFormat(surface);
	SDL_FreeSurface(surface);
	if (Sprite[0] == NULL)
	{
        fprintf(stderr, "Couldn't load %s: %s\n", "-", SDL_GetError());
		return(-1);
	}

	if (Sprite[0]->format->palette && Screen->format->palette)
	{
		SDL_SetColors(Screen, Sprite[0]->format->palette->colors, 0, Sprite[0]->format->palette->ncolors);
	}
//	#define COLORKEY0 255, 255, 255 // Transparent color
//	SDL_SetColorKey( Sprite[0], SDL_SRCCOLORKEY, SDL_MapRGB(Sprite[0]->format, COLORKEY0) );
//------------------------------------------
	surface = IMG_Load("data/visuals/Simple_Directmedia_Layer_Logo.gif");
	Sprite[1] = SDL_DisplayFormat(surface);
	SDL_FreeSurface(surface);
	if (Sprite[1] == NULL)
	{
		fprintf(stderr, "Couldn't load %s: %s\n", "-",IMG_GetError());
		return(-1);
	}

	if (Sprite[1]->format->palette && Screen->format->palette)
	{
		SDL_SetColors(Screen, Sprite[1]->format->palette->colors, 0, Sprite[1]->format->palette->ncolors);
	}
//	#define COLORKEY1 255, 255, 255 // Transparent color
//	SDL_SetColorKey( Sprite[1], SDL_SRCCOLORKEY, SDL_MapRGB(Sprite[1]->format, COLORKEY1) );
//------------------------------------------
	surface = IMG_Load("data/visuals/Silent_Hero_Productions_Logo.gif");
	Sprite[2] = SDL_DisplayFormat(surface);
	SDL_FreeSurface(surface);
	if (Sprite[2] == NULL)
	{
		fprintf(stderr, "Couldn't load %s: %s\n", "-", IMG_GetError());
		return(-1);
	}

	if (Sprite[2]->format->palette && Screen->format->palette)
	{
		SDL_SetColors(Screen, Sprite[2]->format->palette->colors, 0, Sprite[2]->format->palette->ncolors);
	}
	#define COLORKEY2 0, 255, 0 // Transparent color
	SDL_SetColorKey( Sprite[2], SDL_SRCCOLORKEY, SDL_MapRGB(Sprite[2]->format, COLORKEY2) );
//------------------------------------------
	surface = IMG_Load("data/visuals/Silent_Hero_Productions_Logo_Text.gif");
	Sprite[3] = SDL_DisplayFormat(surface);
	SDL_FreeSurface(surface);
	if (Sprite[3] == NULL)
	{
		fprintf(stderr, "Couldn't load %s: %s\n", "-", IMG_GetError());
		return(-1);
	}

	if (Sprite[3]->format->palette && Screen->format->palette)
	{
		SDL_SetColors(Screen, Sprite[3]->format->palette->colors, 0, Sprite[3]->format->palette->ncolors);
	}
	#define COLORKEY3 0, 0, 0 // Transparent color
	SDL_SetColorKey( Sprite[3], SDL_SRCCOLORKEY, SDL_MapRGB(Sprite[3]->format, COLORKEY3) );
//------------------------------------------
	surface = IMG_Load("data/visuals/Kremlin_Background.gif");
	Sprite[4] = SDL_DisplayFormat(surface);
	SDL_FreeSurface(surface);
	if (Sprite[4] == NULL)
	{
		fprintf(stderr, "Couldn't load %s: %s\n", "-", IMG_GetError());
		return(-1);
	}

	if (Sprite[4]->format->palette && Screen->format->palette)
	{
		SDL_SetColors(Screen, Sprite[4]->format->palette->colors, 0, Sprite[4]->format->palette->ncolors);
	}
//	#define COLORKEY4 0, 0, 0 // Transparent color
//	SDL_SetColorKey( Sprite[4], SDL_SRCCOLORKEY, SDL_MapRGB(Sprite[4]->format, COLORKEY4) );
//------------------------------------------
	surface = IMG_Load("data/visuals/Tetri_Logo.gif");
	Sprite[5] = SDL_DisplayFormat(surface);
	SDL_FreeSurface(surface);
	if (Sprite[5] == NULL)
	{
		fprintf(stderr, "Couldn't load %s: %s\n", "-", IMG_GetError());
		return(-1);
	}

	if (Sprite[5]->format->palette && Screen->format->palette)
	{
		SDL_SetColors(Screen, Sprite[5]->format->palette->colors, 0, Sprite[5]->format->palette->ncolors);
	}
	#define COLORKEY5 153, 102, 0 // Transparent color
	SDL_SetColorKey( Sprite[5], SDL_SRCCOLORKEY, SDL_MapRGB(Sprite[5]->format, COLORKEY5) );
//------------------------------------------
	surface = IMG_Load("data/visuals/Crisis_Logo.gif");
	Sprite[6] = SDL_DisplayFormat(surface);
	SDL_FreeSurface(surface);
	if (Sprite[6] == NULL)
	{
		fprintf(stderr, "Couldn't load %s: %s\n", "-", IMG_GetError());
		return(-1);
	}

	if (Sprite[6]->format->palette && Screen->format->palette)
	{
		SDL_SetColors(Screen, Sprite[6]->format->palette->colors, 0, Sprite[6]->format->palette->ncolors);
	}
	#define COLORKEY6 153, 102, 0 // Transparent color
	SDL_SetColorKey( Sprite[6], SDL_SRCCOLORKEY, SDL_MapRGB(Sprite[6]->format, COLORKEY6) );
//------------------------------------------
	surface = IMG_Load("data/visuals/100Percent_Logo.gif");
	Sprite[7] = SDL_DisplayFormat(surface);
	SDL_FreeSurface(surface);
	if (Sprite[7] == NULL)
	{
		fprintf(stderr, "Couldn't load %s: %s\n", "-", IMG_GetError());
		return(-1);
	}

	if (Sprite[7]->format->palette && Screen->format->palette)
	{
		SDL_SetColors(Screen, Sprite[7]->format->palette->colors, 0, Sprite[7]->format->palette->ncolors);
	}
	#define COLORKEY7 153, 102, 0 // Transparent color
	SDL_SetColorKey( Sprite[7], SDL_SRCCOLORKEY, SDL_MapRGB(Sprite[7]->format, COLORKEY7) );
//------------------------------------------
	surface = IMG_Load("data/visuals/Box_Black.gif");
	Sprite[8] = SDL_DisplayFormat(surface);
	SDL_FreeSurface(surface);
	if (Sprite[8] == NULL)
	{
		fprintf(stderr, "Couldn't load %s: %s\n", "-", IMG_GetError());
		return(-1);
	}

	if (Sprite[8]->format->palette && Screen->format->palette)
	{
		SDL_SetColors(Screen, Sprite[8]->format->palette->colors, 0, Sprite[8]->format->palette->ncolors);
	}
//	#define COLORKEY8 153, 102, 0 // Transparent color
//	SDL_SetColorKey( Sprite[8], SDL_SRCCOLORKEY, SDL_MapRGB(Sprite[8]->format, COLORKEY8) );
//------------------------------------------
	surface = IMG_Load("data/visuals/Box_Red.gif");
	Sprite[9] = SDL_DisplayFormat(surface);
	SDL_FreeSurface(surface);
	if (Sprite[9] == NULL)
	{
		fprintf(stderr, "Couldn't load %s: %s\n", "-", IMG_GetError());
		return(-1);
	}

	if (Sprite[9]->format->palette && Screen->format->palette)
	{
		SDL_SetColors(Screen, Sprite[9]->format->palette->colors, 0, Sprite[9]->format->palette->ncolors);
	}
//	#define COLORKEY9 153, 102, 0 // Transparent color
//	SDL_SetColorKey( Sprite[9], SDL_SRCCOLORKEY, SDL_MapRGB(Sprite[9]->format, COLORKEY9) );
//------------------------------------------
	surface = IMG_Load("data/visuals/Box_Orange.gif");
	Sprite[10] = SDL_DisplayFormat(surface);
	SDL_FreeSurface(surface);
	if (Sprite[10] == NULL)
	{
		fprintf(stderr, "Couldn't load %s: %s\n", "-", IMG_GetError());
		return(-1);
	}

	if (Sprite[10]->format->palette && Screen->format->palette)
	{
		SDL_SetColors(Screen, Sprite[10]->format->palette->colors, 0, Sprite[10]->format->palette->ncolors);
	}
//	#define COLORKEY10 153, 102, 0 // Transparent color
//	SDL_SetColorKey( Sprite[10], SDL_SRCCOLORKEY, SDL_MapRGB(Sprite[10]->format, COLORKEY10) );
//------------------------------------------
	surface = IMG_Load("data/visuals/Box_Aqua.gif");
	Sprite[11] = SDL_DisplayFormat(surface);
	SDL_FreeSurface(surface);
	if (Sprite[11] == NULL)
	{
		fprintf(stderr, "Couldn't load %s: %s\n", "-", IMG_GetError());
		return(-1);
	}

	if (Sprite[11]->format->palette && Screen->format->palette)
	{
		SDL_SetColors(Screen, Sprite[11]->format->palette->colors, 0, Sprite[11]->format->palette->ncolors);
	}
//	#define COLORKEY11 153, 102, 0 // Transparent color
//	SDL_SetColorKey( Sprite[11], SDL_SRCCOLORKEY, SDL_MapRGB(Sprite[11]->format, COLORKEY11) );
//------------------------------------------
	surface = IMG_Load("data/visuals/Box_Yellow.gif");
	Sprite[12] = SDL_DisplayFormat(surface);
	SDL_FreeSurface(surface);
	if (Sprite[12] == NULL)
	{
		fprintf(stderr, "Couldn't load %s: %s\n", "-", IMG_GetError());
		return(-1);
	}

	if (Sprite[12]->format->palette && Screen->format->palette)
	{
		SDL_SetColors(Screen, Sprite[12]->format->palette->colors, 0, Sprite[12]->format->palette->ncolors);
	}
//	#define COLORKEY12 153, 102, 0 // Transparent color
//	SDL_SetColorKey( Sprite[12], SDL_SRCCOLORKEY, SDL_MapRGB(Sprite[12]->format, COLORKEY12) );
//------------------------------------------
	surface = IMG_Load("data/visuals/Box_Green.gif");
	Sprite[13] = SDL_DisplayFormat(surface);
	SDL_FreeSurface(surface);
	if (Sprite[13] == NULL)
	{
		fprintf(stderr, "Couldn't load %s: %s\n", "-", IMG_GetError());
		return(-1);
	}

	if (Sprite[13]->format->palette && Screen->format->palette)
	{
		SDL_SetColors(Screen, Sprite[13]->format->palette->colors, 0, Sprite[13]->format->palette->ncolors);
	}
//	#define COLORKEY13 153, 102, 0 // Transparent color
//	SDL_SetColorKey( Sprite[13], SDL_SRCCOLORKEY, SDL_MapRGB(Sprite[13]->format, COLORKEY13) );
//------------------------------------------
	surface = IMG_Load("data/visuals/Box_Blue.gif");
	Sprite[14] = SDL_DisplayFormat(surface);
	SDL_FreeSurface(surface);
	if (Sprite[14] == NULL)
	{
		fprintf(stderr, "Couldn't load %s: %s\n", "-", IMG_GetError());
		return(-1);
	}

	if (Sprite[14]->format->palette && Screen->format->palette)
	{
		SDL_SetColors(Screen, Sprite[14]->format->palette->colors, 0, Sprite[14]->format->palette->ncolors);
	}
//	#define COLORKEY14 153, 102, 0 // Transparent color
//	SDL_SetColorKey( Sprite[14], SDL_SRCCOLORKEY, SDL_MapRGB(Sprite[14]->format, COLORKEY14) );
//------------------------------------------
	surface = IMG_Load("data/visuals/Box_Purple.gif");
	Sprite[15] = SDL_DisplayFormat(surface);
	SDL_FreeSurface(surface);
	if (Sprite[15] == NULL)
	{
		fprintf(stderr, "Couldn't load %s: %s\n", "-", IMG_GetError());
		return(-1);
	}

	if (Sprite[15]->format->palette && Screen->format->palette)
	{
		SDL_SetColors(Screen, Sprite[15]->format->palette->colors, 0, Sprite[15]->format->palette->ncolors);
	}
//	#define COLORKEY15 153, 102, 0 // Transparent color
//	SDL_SetColorKey( Sprite[15], SDL_SRCCOLORKEY, SDL_MapRGB(Sprite[15]->format, COLORKEY15) );
//------------------------------------------
	surface = IMG_Load("data/visuals/Box_Border.gif");
	Sprite[16] = SDL_DisplayFormat(surface);
	SDL_FreeSurface(surface);
	if (Sprite[16] == NULL)
	{
		fprintf(stderr, "Couldn't load %s: %s\n", "-", IMG_GetError());
		return(-1);
	}

	if (Sprite[16]->format->palette && Screen->format->palette)
	{
		SDL_SetColors(Screen, Sprite[16]->format->palette->colors, 0, Sprite[16]->format->palette->ncolors);
	}
//	#define COLORKEY16 153, 102, 0 // Transparent color
//	SDL_SetColorKey( Sprite[16], SDL_SRCCOLORKEY, SDL_MapRGB(Sprite[16]->format, COLORKEY16) );
//------------------------------------------
	surface = IMG_Load("data/visuals/Box_White.gif");
	Sprite[17] = SDL_DisplayFormat(surface);
	SDL_FreeSurface(surface);
	if (Sprite[17] == NULL)
	{
		fprintf(stderr, "Couldn't load %s: %s\n", "-", IMG_GetError());
		return(-1);
	}

	if (Sprite[17]->format->palette && Screen->format->palette)
	{
		SDL_SetColors(Screen, Sprite[17]->format->palette->colors, 0, Sprite[17]->format->palette->ncolors);
	}
//	#define COLORKEY17 153, 102, 0 // Transparent color
//	SDL_SetColorKey( Sprite[17], SDL_SRCCOLORKEY, SDL_MapRGB(Sprite[17]->format, COLORKEY17) );
//------------------------------------------
	surface = IMG_Load("data/visuals/Kremlin_Background.gif");
	KremlinAlphaDark = SDL_DisplayFormat(surface);
	SDL_FreeSurface(surface);
	if (KremlinAlphaDark == NULL)
	{
		fprintf(stderr, "Couldn't load %s: %s\n", "-", IMG_GetError());
		return(-1);
	}

	if (KremlinAlphaDark->format->palette && Screen->format->palette)
	{
		SDL_SetColors(Screen, KremlinAlphaDark->format->palette->colors, 0, KremlinAlphaDark->format->palette->ncolors);
	}

	return(1);
}

//-------------------------------------------------------------------------------------------------
void Visuals::UnloadAllSpritesFromMemory(void)
{
Uint8 spriteIndex;

	for (spriteIndex = 0; spriteIndex < SpriteTotal; spriteIndex++)
	{
		SDL_FreeSurface(Sprite[spriteIndex]);
		Sprite[spriteIndex] = NULL;
	}

	SDL_FreeSurface(KremlinAlphaDark);
	KremlinAlphaDark = NULL;
}

//-------------------------------------------------------------------------------------------------
void Visuals::EraseScreenBufferWithColor(Sint32 red, Sint32 green, Sint32 blue)
{
	#define COLORKEYFILL red, green, blue
	SDL_FillRect( Screen, NULL, SDL_MapRGB(Screen->format, COLORKEYFILL) );
}

//-------------------------------------------------------------------------------------------------
void Visuals::DisplaySpriteOnScreenBufferGlass(Sint8 spriteNumber, Sint16 xScreenPos, Sint16 yScreenPos, Uint8 alpha)
{
	SDL_SetAlpha(Sprite[spriteNumber], SDL_SRCALPHA, alpha);

	SDL_Rect destinationRectangle;
	destinationRectangle.x = xScreenPos;
	destinationRectangle.y = yScreenPos;

	SDL_BlitSurface(Sprite[spriteNumber], NULL, Screen, &destinationRectangle);

	SDL_SetAlpha(Sprite[spriteNumber], 0, 255);
}

//-------------------------------------------------------------------------------------------------
void Visuals::DisplaySpriteOnScreenBufferRotoZoom(Sint8 spriteNumber, Sint16 xScreenPos, Sint16 yScreenPos, double angle, double zoom)
{
/*	SDL_Rect destinationRectangle;

	SDL_Surface *temp = Sprite[spriteNumber];
//	SDL_Surface *temp2 = rotozoomSurface(temp, angle, zoom, 1);

	int spriteWidth = temp2->w;
	int spriteHeight = temp2->h;
	destinationRectangle.x = xScreenPos-(spriteWidth/2);
	destinationRectangle.y = yScreenPos-(spriteHeight/2);

	SDL_BlitSurface(temp2, NULL, Screen, &destinationRectangle);
*/
}

//-------------------------------------------------------------------------------------------------
void Visuals::FadeInScreenBuffer(void)
{
SDL_Surface *screenTEMP = SDL_ConvertSurface(Screen, Screen->format, SDL_SWSURFACE);// = SDL_LoadBMP("data/visuals/FadeIn_FadeOut_Screen.bmp");
Uint8 alphaValueOfFade;
Uint16 tileScreenX;
Uint16 tileScreenY;

	SDL_BlitSurface(Screen, NULL, screenTEMP, NULL);

	for (alphaValueOfFade = 255; alphaValueOfFade > 25; alphaValueOfFade-=25)
	{
		SDL_BlitSurface(screenTEMP, NULL, Screen, NULL);

		for (tileScreenY = 0; tileScreenY < 640; tileScreenY+=12)
			for (tileScreenX = 0; tileScreenX < 640; tileScreenX+=12)
				DisplaySpriteOnScreenBufferGlass(0, tileScreenX, tileScreenY, alphaValueOfFade);

		SDL_Flip(Screen);
	}

	SDL_FreeSurface(screenTEMP);
	screenTEMP = NULL;

//	SDL_BlitSurface(screenTEMP, NULL, Screen, NULL);
//
//	for (tileScreenY = 0; tileScreenY < 640; tileScreenY+=12)
//		for (tileScreenX = 0; tileScreenX < 640; tileScreenX+=12)
//			DisplaySpriteOnScreenBufferGlass(0, tileScreenX, tileScreenY, 0);
//
//	SDL_Flip(Screen);
}

//-------------------------------------------------------------------------------------------------
void Visuals::FadeOutScreenBuffer(void)
{
SDL_Surface *screenTEMP = SDL_ConvertSurface(Screen, Screen->format, SDL_SWSURFACE);// = SDL_LoadBMP("data/visuals/FadeIn_FadeOut_Screen.bmp");
Uint8 alphaValueOfFade;
Uint16 tileScreenX;
Uint16 tileScreenY;

	SDL_BlitSurface(Screen, NULL, screenTEMP, NULL);

	for (alphaValueOfFade = 0; alphaValueOfFade < 225; alphaValueOfFade+=25)
	{
		SDL_BlitSurface(screenTEMP, NULL, Screen, NULL);

		for (tileScreenY = 0; tileScreenY < 640; tileScreenY+=12)
			for (tileScreenX = 0; tileScreenX < 640; tileScreenX+=12)
				DisplaySpriteOnScreenBufferGlass(0, tileScreenX, tileScreenY, alphaValueOfFade);

		SDL_Flip(Screen);
	}

	SDL_FreeSurface(screenTEMP);
	screenTEMP = NULL;

//	SDL_BlitSurface(screenTEMP, NULL, Screen, NULL);
//
//	for (tileScreenY = 0; tileScreenY < 640; tileScreenY+=12)
//		for (tileScreenX = 0; tileScreenX < 640; tileScreenX+=12)
//			DisplaySpriteOnScreenBufferGlass(0, tileScreenX, tileScreenY, 255);
//
//	SDL_Flip(Screen);
}

//-------------------------------------------------------------------------------------------------
void Visuals::DrawTextOnScreenBuffer(Uint8 fontNumber, const char *text, Sint32 red, Sint32 green, Sint32 blue, Sint32 alpha, Sint32 xScreenPos, Sint32 yScreenPos, Uint8 xJustification)
{
Sint32 x, y;
int textWidth;
int textHeight;
SDL_Surface *sText;
SDL_Rect rcDest;

	if (xJustification == TextCenterX)
	{
		TTF_SizeText(FontLibrary[fontNumber], text, &textWidth, &textHeight);
		xScreenPos = (640 - textWidth) / 2;
	}
	else if (xJustification == TextRightX)
	{
		TTF_SizeText(FontLibrary[fontNumber], text, &textWidth, &textHeight);
		xScreenPos = ( (640 - textWidth) - xScreenPos );
	}

	SDL_Color textColor = {0 , 0 , 0, 0};
	sText = TTF_RenderText_Solid( FontLibrary[fontNumber], text, textColor );

	for (y = -3; y < 4; y++)
	{
		for (x = -3; x < 4; x++)
		{
			rcDest.x = xScreenPos+x;
			rcDest.y = yScreenPos+y;
			SDL_BlitSurface( sText, NULL, Screen, &rcDest );
		}
	}

	SDL_FreeSurface(sText);

	SDL_Color textColor2 = {red , green , blue, alpha};
	sText = TTF_RenderText_Blended( FontLibrary[fontNumber], text, textColor2 );
	rcDest.x = xScreenPos;
	rcDest.y = yScreenPos;
	SDL_BlitSurface( sText, NULL, Screen, &rcDest );
	SDL_FreeSurface(sText);
}

//-------------------------------------------------------------------------------------------------
void Visuals::DrawTextOnScreenBufferFast(Uint8 fontNumber, const char *text, Sint32 red, Sint32 green, Sint32 blue, Sint32 alpha, Sint32 xScreenPos, Sint32 yScreenPos, Uint8 xJustification)
{
int textWidth;
int textHeight;
SDL_Surface *sText;
SDL_Rect rcDest;

	if (xJustification == TextCenterX)
	{
		TTF_SizeText(FontLibrary[fontNumber], text, &textWidth, &textHeight);
		xScreenPos = (640 - textWidth) / 2;
	}
	else if (xJustification == TextRightX)
	{
		TTF_SizeText(FontLibrary[fontNumber], text, &textWidth, &textHeight);
		xScreenPos = ( (640 - textWidth) - xScreenPos );
	}

	SDL_Color textColor2 = {red , green , blue, alpha};

	sText = TTF_RenderText_Solid( FontLibrary[fontNumber], text, textColor2 );

	rcDest.x = xScreenPos;
	rcDest.y = yScreenPos;
	SDL_BlitSurface( sText, NULL, Screen, &rcDest );
	SDL_FreeSurface(sText);
}
