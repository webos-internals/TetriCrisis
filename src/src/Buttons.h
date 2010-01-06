//Buttons_CLASS.h

#include "SDL.h"
#include "SDL_ttf.h"
#include "SDL_mixer.h"
#include "SDL_image.h"
//#include "SDL_rotozoom.h"

//-------------------------------------------------------------------------------------------------
#define NumberOfButtons		7
#define ButtonCenterX		1

class Buttons
{
public:

	Buttons(void);
	virtual ~Buttons(void);

	Sint8 CurrentButtonThatWasClicked;
	Sint8 ButtonClickedAnimationTimer;

	struct ButtonsInfo
	{
		SDL_Surface *ButtonsImages[2];
		bool ButtonActive;
		Sint8 ButtonScreenOptionValue;
		Sint16 ButtonScreenX;
		Sint16 ButtonScreenY;
		Sint16 ButtonWidth;
		Sint16 ButtonHeight;
	} ButtonsInfoArray[NumberOfButtons];

	int LoadAllButtonsIntoMemoryAndInitialize(void);
	void UnloadAllButtonsFromMemory(void);
	void SetUpNewButtonForUserInput(Uint8 buttonIndex, Uint8 buttonScreenOptionValue, Sint16 buttonScreenX, Sint16 buttonScreenY, Uint8 alpha, Uint8 buttonXJustification);
	bool ButtonClickedByUser(Uint8 button);
	void DeleteAllRegisteredButtons(void);
};
