//Control_CLASS.h

#include "SDL.h"
#include "SDL_ttf.h"
#include "SDL_mixer.h"
#include "SDL_image.h"
//#include "SDL_rotozoom.h"

//-------------------------------------------------------------------------------------------------
#define DirectionZERO	0
#define UP				1
#define DOWN			2
#define LEFT			3
#define RIGHT			4

#define ON				1
#define OFF				0

#define Any				0
#define Mouse			1
#define Keyboard		2
#define Joystick1		3
#define Joystick2		4
#define NoMouse			5
#define NoKeyboard		6

class Control
{
public:

	Control(void);
	virtual ~Control(void);

	char KeyOnKeyboardPressedByUser;

	Uint16 DelayUserInput;

	Uint8 JoystickDirection[7];
	Uint8 JoystickButton1[7];
	bool JoystickButton1ActionTaken[7];
	Uint8 JoystickButton2[7];
	bool JoystickButton2ActionTaken[7];
	bool JoystickUPActionTaken[7];
	bool JoystickDOWNActionTaken[7];
	bool JoystickLEFTActionTaken[7];
	bool JoystickRIGHTActionTaken[7];

	bool SingleMovementForJoystick;

	int MouseX;
	int MouseY;

	SDL_Joystick *joystick1;
	SDL_Joystick *joystick2;

	void ZeroOutAllJoysticks(void);
	void GetInputFromUser(void);
};
