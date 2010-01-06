// Game_CLASS.cpp

#include "SDL.h"
#include "SDL_ttf.h"
#include "SDL_mixer.h"
#include "SDL_image.h"
//#include "SDL_rotozoom.h"

#include "Visuals.h"
#include "Control.h"
#include "Buttons.h"
#include "Audio.h"
#include "Game.h"

extern Visuals* visuals;
extern Control* control;
extern Audio* audio;
extern Game* game;

//-------------------------------------------------------------------------------------------------
Buttons::Buttons(void)
{
	CurrentButtonThatWasClicked = -1;
	ButtonClickedAnimationTimer = -1;
}

//-------------------------------------------------------------------------------------------------
Buttons::~Buttons(void)
{

}

//-------------------------------------------------------------------------------------------------
int Buttons::LoadAllButtonsIntoMemoryAndInitialize(void)
{
SDL_Surface * surface;

//------------------------------------------
	surface = IMG_Load("data/visuals/Button_Start.gif");
	ButtonsInfoArray[0].ButtonsImages[0] = SDL_DisplayFormat(surface);
	SDL_FreeSurface(surface);
	if (ButtonsInfoArray[0].ButtonsImages[0] == NULL)
	{
		fprintf(stderr, "Couldn't load %s: %s\n", "-", IMG_GetError());
		return(-1);
	}

	if (ButtonsInfoArray[0].ButtonsImages[0]->format->palette && visuals->Screen->format->palette)
	{
		SDL_SetColors(visuals->Screen, ButtonsInfoArray[0].ButtonsImages[0]->format->palette->colors, 0, ButtonsInfoArray[0].ButtonsImages[0]->format->palette->ncolors);
	}
	#define COLORKEY0 0, 255, 0 // Transparent color
	SDL_SetColorKey( ButtonsInfoArray[0].ButtonsImages[0], SDL_SRCCOLORKEY, SDL_MapRGB(ButtonsInfoArray[0].ButtonsImages[0]->format, COLORKEY0) );

	ButtonsInfoArray[0].ButtonActive = false;
	ButtonsInfoArray[0].ButtonScreenX = 0;
	ButtonsInfoArray[0].ButtonScreenY = 0;
	ButtonsInfoArray[0].ButtonWidth = ButtonsInfoArray[0].ButtonsImages[0]->w;
	ButtonsInfoArray[0].ButtonWidth = ButtonsInfoArray[0].ButtonsImages[0]->h;
//------------------------------------------
	surface = IMG_Load("data/visuals/Button_Start_Selected.gif");
	ButtonsInfoArray[0].ButtonsImages[1] = SDL_DisplayFormat(surface);
	SDL_FreeSurface(surface);
	if (ButtonsInfoArray[0].ButtonsImages[1] == NULL)
	{
		fprintf(stderr, "Couldn't load %s: %s\n", "-", IMG_GetError());
		return(-1);
	}

	if (ButtonsInfoArray[0].ButtonsImages[1]->format->palette && visuals->Screen->format->palette)
	{
		SDL_SetColors(visuals->Screen, ButtonsInfoArray[0].ButtonsImages[1]->format->palette->colors, 0, ButtonsInfoArray[0].ButtonsImages[1]->format->palette->ncolors);
	}
	#define COLORKEY0 0, 255, 0 // Transparent color
	SDL_SetColorKey( ButtonsInfoArray[0].ButtonsImages[0], SDL_SRCCOLORKEY, SDL_MapRGB(ButtonsInfoArray[0].ButtonsImages[1]->format, COLORKEY0) );

	ButtonsInfoArray[0].ButtonActive = false;
	ButtonsInfoArray[0].ButtonScreenX = 0;
	ButtonsInfoArray[0].ButtonScreenY = 0;
	ButtonsInfoArray[0].ButtonWidth = ButtonsInfoArray[0].ButtonsImages[1]->w;
	ButtonsInfoArray[0].ButtonWidth = ButtonsInfoArray[0].ButtonsImages[1]->h;
//------------------------------------------
	surface = IMG_Load("data/visuals/Button_Options.gif");
	ButtonsInfoArray[1].ButtonsImages[0] = SDL_DisplayFormat(surface);
	SDL_FreeSurface(surface);
	if (ButtonsInfoArray[1].ButtonsImages[0] == NULL)
	{
		fprintf(stderr, "Couldn't load %s: %s\n", "-", IMG_GetError());
		return(-1);
	}

	if (ButtonsInfoArray[1].ButtonsImages[0]->format->palette && visuals->Screen->format->palette)
	{
		SDL_SetColors(visuals->Screen, ButtonsInfoArray[1].ButtonsImages[0]->format->palette->colors, 0, ButtonsInfoArray[1].ButtonsImages[0]->format->palette->ncolors);
	}
	#define COLORKEY1 0, 255, 0 // Transparent color
	SDL_SetColorKey( ButtonsInfoArray[1].ButtonsImages[0], SDL_SRCCOLORKEY, SDL_MapRGB(ButtonsInfoArray[1].ButtonsImages[0]->format, COLORKEY1) );

	ButtonsInfoArray[1].ButtonActive = false;
	ButtonsInfoArray[1].ButtonScreenX = 0;
	ButtonsInfoArray[1].ButtonScreenY = 0;
	ButtonsInfoArray[1].ButtonWidth = ButtonsInfoArray[1].ButtonsImages[0]->w;
	ButtonsInfoArray[1].ButtonWidth = ButtonsInfoArray[1].ButtonsImages[0]->h;
//------------------------------------------
	surface = IMG_Load("data/visuals/Button_Options_Selected.gif");
	ButtonsInfoArray[1].ButtonsImages[1] = SDL_DisplayFormat(surface);
	SDL_FreeSurface(surface);
	if (ButtonsInfoArray[1].ButtonsImages[1] == NULL)
	{
		fprintf(stderr, "Couldn't load %s: %s\n", "-", IMG_GetError());
		return(-1);
	}

	if (ButtonsInfoArray[1].ButtonsImages[1]->format->palette && visuals->Screen->format->palette)
	{
		SDL_SetColors(visuals->Screen, ButtonsInfoArray[1].ButtonsImages[1]->format->palette->colors, 0, ButtonsInfoArray[1].ButtonsImages[1]->format->palette->ncolors);
	}
	#define COLORKEY1 0, 255, 0 // Transparent color
	SDL_SetColorKey( ButtonsInfoArray[1].ButtonsImages[1], SDL_SRCCOLORKEY, SDL_MapRGB(ButtonsInfoArray[1].ButtonsImages[1]->format, COLORKEY1) );

	ButtonsInfoArray[1].ButtonActive = false;
	ButtonsInfoArray[1].ButtonScreenX = 0;
	ButtonsInfoArray[1].ButtonScreenY = 0;
	ButtonsInfoArray[1].ButtonWidth = ButtonsInfoArray[1].ButtonsImages[1]->w;
	ButtonsInfoArray[1].ButtonWidth = ButtonsInfoArray[1].ButtonsImages[1]->h;
//------------------------------------------
	surface = IMG_Load("data/visuals/Button_High_Scores.gif");
	ButtonsInfoArray[2].ButtonsImages[0] = SDL_DisplayFormat(surface);
	SDL_FreeSurface(surface);
	if (ButtonsInfoArray[2].ButtonsImages[0] == NULL)
	{
		fprintf(stderr, "Couldn't load %s: %s\n", "-", IMG_GetError());
		return(-1);
	}

	if (ButtonsInfoArray[2].ButtonsImages[0]->format->palette && visuals->Screen->format->palette)
	{
		SDL_SetColors(visuals->Screen, ButtonsInfoArray[2].ButtonsImages[0]->format->palette->colors, 0, ButtonsInfoArray[2].ButtonsImages[0]->format->palette->ncolors);
	}
	#define COLORKEY2 0, 255, 0 // Transparent color
	SDL_SetColorKey( ButtonsInfoArray[2].ButtonsImages[0], SDL_SRCCOLORKEY, SDL_MapRGB(ButtonsInfoArray[2].ButtonsImages[0]->format, COLORKEY2) );

	ButtonsInfoArray[2].ButtonActive = false;
	ButtonsInfoArray[2].ButtonScreenX = 0;
	ButtonsInfoArray[2].ButtonScreenY = 0;
	ButtonsInfoArray[2].ButtonWidth = ButtonsInfoArray[2].ButtonsImages[0]->w;
	ButtonsInfoArray[2].ButtonWidth = ButtonsInfoArray[2].ButtonsImages[0]->h;
//------------------------------------------
	surface = IMG_Load("data/visuals/Button_High_Scores_Selected.gif");
	ButtonsInfoArray[2].ButtonsImages[1] = SDL_DisplayFormat(surface);
	SDL_FreeSurface(surface);
	if (ButtonsInfoArray[2].ButtonsImages[1] == NULL)
	{
		fprintf(stderr, "Couldn't load %s: %s\n", "-", IMG_GetError());
		return(-1);
	}

	if (ButtonsInfoArray[2].ButtonsImages[1]->format->palette && visuals->Screen->format->palette)
	{
		SDL_SetColors(visuals->Screen, ButtonsInfoArray[2].ButtonsImages[1]->format->palette->colors, 0, ButtonsInfoArray[2].ButtonsImages[1]->format->palette->ncolors);
	}
	#define COLORKEY2 0, 255, 0 // Transparent color
	SDL_SetColorKey( ButtonsInfoArray[2].ButtonsImages[1], SDL_SRCCOLORKEY, SDL_MapRGB(ButtonsInfoArray[2].ButtonsImages[1]->format, COLORKEY2) );

	ButtonsInfoArray[2].ButtonActive = false;
	ButtonsInfoArray[2].ButtonScreenX = 0;
	ButtonsInfoArray[2].ButtonScreenY = 0;
	ButtonsInfoArray[2].ButtonWidth = ButtonsInfoArray[2].ButtonsImages[1]->w;
	ButtonsInfoArray[2].ButtonWidth = ButtonsInfoArray[2].ButtonsImages[1]->h;
//------------------------------------------
	surface = IMG_Load("data/visuals/Button_How_To_Play.gif");
	ButtonsInfoArray[3].ButtonsImages[0] = SDL_DisplayFormat(surface);
	SDL_FreeSurface(surface);
	if (ButtonsInfoArray[3].ButtonsImages[0] == NULL)
	{
		fprintf(stderr, "Couldn't load %s: %s\n", "-", IMG_GetError());
		return(-1);
	}

	if (ButtonsInfoArray[3].ButtonsImages[0]->format->palette && visuals->Screen->format->palette)
	{
		SDL_SetColors(visuals->Screen, ButtonsInfoArray[3].ButtonsImages[0]->format->palette->colors, 0, ButtonsInfoArray[3].ButtonsImages[0]->format->palette->ncolors);
	}
	#define COLORKEY3 0, 255, 0 // Transparent color
	SDL_SetColorKey( ButtonsInfoArray[3].ButtonsImages[0], SDL_SRCCOLORKEY, SDL_MapRGB(ButtonsInfoArray[3].ButtonsImages[0]->format, COLORKEY3) );

	ButtonsInfoArray[3].ButtonActive = false;
	ButtonsInfoArray[3].ButtonScreenX = 0;
	ButtonsInfoArray[3].ButtonScreenY = 0;
	ButtonsInfoArray[3].ButtonWidth = ButtonsInfoArray[3].ButtonsImages[0]->w;
	ButtonsInfoArray[3].ButtonWidth = ButtonsInfoArray[3].ButtonsImages[0]->h;
//------------------------------------------
	surface = IMG_Load("data/visuals/Button_How_To_Play_Selected.gif");
	ButtonsInfoArray[3].ButtonsImages[1] = SDL_DisplayFormat(surface);
	SDL_FreeSurface(surface);
	if (ButtonsInfoArray[3].ButtonsImages[1] == NULL)
	{
		fprintf(stderr, "Couldn't load %s: %s\n", "-", IMG_GetError());
		return(-1);
	}

	if (ButtonsInfoArray[3].ButtonsImages[1]->format->palette && visuals->Screen->format->palette)
	{
		SDL_SetColors(visuals->Screen, ButtonsInfoArray[3].ButtonsImages[1]->format->palette->colors, 0, ButtonsInfoArray[3].ButtonsImages[1]->format->palette->ncolors);
	}
	#define COLORKEY3 0, 255, 0 // Transparent color
	SDL_SetColorKey( ButtonsInfoArray[3].ButtonsImages[1], SDL_SRCCOLORKEY, SDL_MapRGB(ButtonsInfoArray[3].ButtonsImages[1]->format, COLORKEY3) );

	ButtonsInfoArray[3].ButtonActive = false;
	ButtonsInfoArray[3].ButtonScreenX = 0;
	ButtonsInfoArray[3].ButtonScreenY = 0;
	ButtonsInfoArray[3].ButtonWidth = ButtonsInfoArray[3].ButtonsImages[1]->w;
	ButtonsInfoArray[3].ButtonWidth = ButtonsInfoArray[3].ButtonsImages[1]->h;
//------------------------------------------
	surface = IMG_Load("data/visuals/Button_History.gif");
	ButtonsInfoArray[4].ButtonsImages[0] = SDL_DisplayFormat(surface);
	SDL_FreeSurface(surface);
	if (ButtonsInfoArray[4].ButtonsImages[0] == NULL)
	{
		fprintf(stderr, "Couldn't load %s: %s\n", "-", IMG_GetError());
		return(-1);
	}

	if (ButtonsInfoArray[4].ButtonsImages[0]->format->palette && visuals->Screen->format->palette)
	{
		SDL_SetColors(visuals->Screen, ButtonsInfoArray[4].ButtonsImages[0]->format->palette->colors, 0, ButtonsInfoArray[4].ButtonsImages[0]->format->palette->ncolors);
	}
	#define COLORKEY4 0, 255, 0 // Transparent color
	SDL_SetColorKey( ButtonsInfoArray[4].ButtonsImages[0], SDL_SRCCOLORKEY, SDL_MapRGB(ButtonsInfoArray[4].ButtonsImages[0]->format, COLORKEY4) );

	ButtonsInfoArray[4].ButtonActive = false;
	ButtonsInfoArray[4].ButtonScreenX = 0;
	ButtonsInfoArray[4].ButtonScreenY = 0;
	ButtonsInfoArray[4].ButtonWidth = ButtonsInfoArray[4].ButtonsImages[0]->w;
	ButtonsInfoArray[4].ButtonWidth = ButtonsInfoArray[4].ButtonsImages[0]->h;
//------------------------------------------
	surface = IMG_Load("data/visuals/Button_History_Selected.gif");
	ButtonsInfoArray[4].ButtonsImages[1] = SDL_DisplayFormat(surface);
	SDL_FreeSurface(surface);
	if (ButtonsInfoArray[4].ButtonsImages[1] == NULL)
	{
		fprintf(stderr, "Couldn't load %s: %s\n", "-", IMG_GetError());
		return(-1);
	}

	if (ButtonsInfoArray[4].ButtonsImages[1]->format->palette && visuals->Screen->format->palette)
	{
		SDL_SetColors(visuals->Screen, ButtonsInfoArray[4].ButtonsImages[1]->format->palette->colors, 0, ButtonsInfoArray[4].ButtonsImages[1]->format->palette->ncolors);
	}
	#define COLORKEY4 0, 255, 0 // Transparent color
	SDL_SetColorKey( ButtonsInfoArray[4].ButtonsImages[1], SDL_SRCCOLORKEY, SDL_MapRGB(ButtonsInfoArray[4].ButtonsImages[1]->format, COLORKEY4) );

	ButtonsInfoArray[4].ButtonActive = false;
	ButtonsInfoArray[4].ButtonScreenX = 0;
	ButtonsInfoArray[4].ButtonScreenY = 0;
	ButtonsInfoArray[4].ButtonWidth = ButtonsInfoArray[4].ButtonsImages[1]->w;
	ButtonsInfoArray[4].ButtonWidth = ButtonsInfoArray[4].ButtonsImages[1]->h;
//------------------------------------------
	surface = IMG_Load("data/visuals/Button_Exit.gif");
	ButtonsInfoArray[5].ButtonsImages[0] = SDL_DisplayFormat(surface);
	SDL_FreeSurface(surface);
	if (ButtonsInfoArray[5].ButtonsImages[0] == NULL)
	{
		fprintf(stderr, "Couldn't load %s: %s\n", "-", IMG_GetError());
		return(-1);
	}

	if (ButtonsInfoArray[5].ButtonsImages[0]->format->palette && visuals->Screen->format->palette)
	{
		SDL_SetColors(visuals->Screen, ButtonsInfoArray[5].ButtonsImages[0]->format->palette->colors, 0, ButtonsInfoArray[5].ButtonsImages[0]->format->palette->ncolors);
	}
	#define COLORKEY5 0, 255, 0 // Transparent color
	SDL_SetColorKey( ButtonsInfoArray[5].ButtonsImages[0], SDL_SRCCOLORKEY, SDL_MapRGB(ButtonsInfoArray[5].ButtonsImages[0]->format, COLORKEY5) );

	ButtonsInfoArray[5].ButtonActive = false;
	ButtonsInfoArray[5].ButtonScreenX = 0;
	ButtonsInfoArray[5].ButtonScreenY = 0;
	ButtonsInfoArray[5].ButtonWidth = ButtonsInfoArray[5].ButtonsImages[0]->w;
	ButtonsInfoArray[5].ButtonWidth = ButtonsInfoArray[5].ButtonsImages[0]->h;
//------------------------------------------
	surface = IMG_Load("data/visuals/Button_Exit_Selected.gif");
	ButtonsInfoArray[5].ButtonsImages[1] = SDL_DisplayFormat(surface);
	SDL_FreeSurface(surface);
	if (ButtonsInfoArray[5].ButtonsImages[1] == NULL)
	{
		fprintf(stderr, "Couldn't load %s: %s\n", "-", IMG_GetError());
		return(-1);
	}

	if (ButtonsInfoArray[5].ButtonsImages[1]->format->palette && visuals->Screen->format->palette)
	{
		SDL_SetColors(visuals->Screen, ButtonsInfoArray[5].ButtonsImages[1]->format->palette->colors, 0, ButtonsInfoArray[5].ButtonsImages[1]->format->palette->ncolors);
	}
	#define COLORKEY5 0, 255, 0 // Transparent color
	SDL_SetColorKey( ButtonsInfoArray[5].ButtonsImages[1], SDL_SRCCOLORKEY, SDL_MapRGB(ButtonsInfoArray[5].ButtonsImages[1]->format, COLORKEY5) );

	ButtonsInfoArray[5].ButtonActive = false;
	ButtonsInfoArray[5].ButtonScreenX = 0;
	ButtonsInfoArray[5].ButtonScreenY = 0;
	ButtonsInfoArray[5].ButtonWidth = ButtonsInfoArray[5].ButtonsImages[1]->w;
	ButtonsInfoArray[5].ButtonWidth = ButtonsInfoArray[5].ButtonsImages[1]->h;
//------------------------------------------
	surface = IMG_Load("data/visuals/Button_Back.gif");
	ButtonsInfoArray[6].ButtonsImages[0] = SDL_DisplayFormat(surface);
	SDL_FreeSurface(surface);
	if (ButtonsInfoArray[6].ButtonsImages[0] == NULL)
	{
		fprintf(stderr, "Couldn't load %s: %s\n", "-", IMG_GetError());
		return(-1);
	}

	if (ButtonsInfoArray[6].ButtonsImages[0]->format->palette && visuals->Screen->format->palette)
	{
		SDL_SetColors(visuals->Screen, ButtonsInfoArray[6].ButtonsImages[0]->format->palette->colors, 0, ButtonsInfoArray[6].ButtonsImages[0]->format->palette->ncolors);
	}
	#define COLORKEY6 0, 255, 0 // Transparent color
	SDL_SetColorKey( ButtonsInfoArray[6].ButtonsImages[0], SDL_SRCCOLORKEY, SDL_MapRGB(ButtonsInfoArray[6].ButtonsImages[0]->format, COLORKEY6) );

	ButtonsInfoArray[6].ButtonActive = false;
	ButtonsInfoArray[6].ButtonScreenX = 0;
	ButtonsInfoArray[6].ButtonScreenY = 0;
	ButtonsInfoArray[6].ButtonWidth = ButtonsInfoArray[6].ButtonsImages[0]->w;
	ButtonsInfoArray[6].ButtonWidth = ButtonsInfoArray[6].ButtonsImages[0]->h;
//------------------------------------------
	surface = IMG_Load("data/visuals/Button_Back_Selected.gif");
	ButtonsInfoArray[6].ButtonsImages[1] = SDL_DisplayFormat(surface);
	SDL_FreeSurface(surface);
	if (ButtonsInfoArray[6].ButtonsImages[1] == NULL)
	{
		fprintf(stderr, "Couldn't load %s: %s\n", "-", IMG_GetError());
		return(-1);
	}

	if (ButtonsInfoArray[6].ButtonsImages[1]->format->palette && visuals->Screen->format->palette)
	{
		SDL_SetColors(visuals->Screen, ButtonsInfoArray[6].ButtonsImages[1]->format->palette->colors, 0, ButtonsInfoArray[6].ButtonsImages[1]->format->palette->ncolors);
	}
	#define COLORKEY6 0, 255, 0 // Transparent color
	SDL_SetColorKey( ButtonsInfoArray[6].ButtonsImages[1], SDL_SRCCOLORKEY, SDL_MapRGB(ButtonsInfoArray[6].ButtonsImages[1]->format, COLORKEY5) );

	ButtonsInfoArray[6].ButtonActive = false;
	ButtonsInfoArray[6].ButtonScreenX = 0;
	ButtonsInfoArray[6].ButtonScreenY = 0;
	ButtonsInfoArray[6].ButtonWidth = ButtonsInfoArray[6].ButtonsImages[1]->w;
	ButtonsInfoArray[6].ButtonWidth = ButtonsInfoArray[6].ButtonsImages[1]->h;

	return(1);
}

//-------------------------------------------------------------------------------------------------
void Buttons::UnloadAllButtonsFromMemory(void)
{
Uint8 buttonIndex;

	for (buttonIndex = 0; buttonIndex < NumberOfButtons; buttonIndex++)
	{
		SDL_FreeSurface(ButtonsInfoArray[buttonIndex].ButtonsImages[0]);
		ButtonsInfoArray[buttonIndex].ButtonsImages[0] = NULL;

		SDL_FreeSurface(ButtonsInfoArray[buttonIndex].ButtonsImages[1]);
		ButtonsInfoArray[buttonIndex].ButtonsImages[1] = NULL;
	}
}

//-------------------------------------------------------------------------------------------------
void Buttons::SetUpNewButtonForUserInput(Uint8 buttonIndex, Uint8 buttonScreenOptionValue, Sint16 buttonScreenX, Sint16 buttonScreenY, Uint8 alpha, Uint8 buttonXJustification)
{
	ButtonsInfoArray[buttonIndex].ButtonActive = true;
	ButtonsInfoArray[buttonIndex].ButtonScreenOptionValue = buttonScreenOptionValue;
	ButtonsInfoArray[buttonIndex].ButtonScreenX = buttonScreenX;
	ButtonsInfoArray[buttonIndex].ButtonScreenY = buttonScreenY;
	ButtonsInfoArray[buttonIndex].ButtonWidth = ButtonsInfoArray[buttonIndex].ButtonsImages[0]->w;
	ButtonsInfoArray[buttonIndex].ButtonHeight = ButtonsInfoArray[buttonIndex].ButtonsImages[0]->h;

	if (buttonXJustification == ButtonCenterX)
	{
		ButtonsInfoArray[buttonIndex].ButtonScreenX = 320 - (ButtonsInfoArray[buttonIndex].ButtonWidth / 2);
	}

	SDL_SetAlpha(ButtonsInfoArray[buttonIndex].ButtonsImages[0], SDL_SRCALPHA, alpha);

	SDL_Rect destinationRectangle;

	destinationRectangle.x = ButtonsInfoArray[buttonIndex].ButtonScreenX;
	destinationRectangle.y = ButtonsInfoArray[buttonIndex].ButtonScreenY;

	SDL_BlitSurface(ButtonsInfoArray[buttonIndex].ButtonsImages[0], NULL, visuals->Screen, &destinationRectangle);

	SDL_SetAlpha(ButtonsInfoArray[buttonIndex].ButtonsImages[0], 0, 255);
}

//-------------------------------------------------------------------------------------------------
void Buttons::DeleteAllRegisteredButtons(void)
{
Uint8 buttonIndex;

	for (buttonIndex = 0; buttonIndex < NumberOfButtons; buttonIndex++)
	{
		ButtonsInfoArray[buttonIndex].ButtonActive = false;
		ButtonsInfoArray[buttonIndex].ButtonScreenOptionValue = -1;
		ButtonsInfoArray[buttonIndex].ButtonScreenX = 0;
		ButtonsInfoArray[buttonIndex].ButtonScreenY = 0;
		ButtonsInfoArray[buttonIndex].ButtonWidth = ButtonsInfoArray[buttonIndex].ButtonsImages[0]->w;
		ButtonsInfoArray[buttonIndex].ButtonHeight = ButtonsInfoArray[buttonIndex].ButtonsImages[0]->h;
	}
}

//-------------------------------------------------------------------------------------------------
bool Buttons::ButtonClickedByUser(Uint8 button)
{
	SDL_Rect destinationRectangle;

	if (ButtonsInfoArray[button].ButtonActive == false)  return(false);

	if (    (   (control->JoystickButton1[Mouse] == ON)
		&&(  (control->MouseX > ButtonsInfoArray[button].ButtonScreenX)
		&&(control->MouseX < (ButtonsInfoArray[button].ButtonScreenX + ButtonsInfoArray[button].ButtonWidth) )
		&&(control->MouseY > ButtonsInfoArray[button].ButtonScreenY)
		&&(control->MouseY < (ButtonsInfoArray[button].ButtonScreenY + ButtonsInfoArray[button].ButtonHeight) )  )   )
		||(  (game->CurrentlySelectedScreenOption == ButtonsInfoArray[button].ButtonScreenOptionValue)&&( (control->JoystickButton1[NoMouse] == ON)||(control->KeyOnKeyboardPressedByUser == '>') )  )    )
	{
		audio->PlayDigitalSoundFX(2);

		CurrentButtonThatWasClicked = button;
		ButtonClickedAnimationTimer = 10;
		control->DelayUserInput = 20;
	}

	if (ButtonClickedAnimationTimer > -1 && button == CurrentButtonThatWasClicked)
	{
		if (ButtonClickedAnimationTimer == 10)
		{
			destinationRectangle.x = ButtonsInfoArray[CurrentButtonThatWasClicked].ButtonScreenX;
			destinationRectangle.y = ButtonsInfoArray[CurrentButtonThatWasClicked].ButtonScreenY;
			SDL_BlitSurface(ButtonsInfoArray[CurrentButtonThatWasClicked].ButtonsImages[1], NULL, visuals->Screen, &destinationRectangle);
			SDL_Flip(visuals->Screen);
		}
		else if (ButtonClickedAnimationTimer == 5)
		{
			destinationRectangle.x = ButtonsInfoArray[CurrentButtonThatWasClicked].ButtonScreenX;
			destinationRectangle.y = ButtonsInfoArray[CurrentButtonThatWasClicked].ButtonScreenY;
			SDL_BlitSurface(ButtonsInfoArray[CurrentButtonThatWasClicked].ButtonsImages[0], NULL, visuals->Screen, &destinationRectangle);
			SDL_Flip(visuals->Screen);
		}
		else if (ButtonClickedAnimationTimer == 0)
		{
			CurrentButtonThatWasClicked = -1;
			ButtonClickedAnimationTimer = -1;
			return(true);
		}

		if (ButtonClickedAnimationTimer > 0)  ButtonClickedAnimationTimer--;
	}

	return(false);
}
