// Control_CLASS.cpp

#include "SDL.h"
#include "SDL_ttf.h"
#include "SDL_mixer.h"
#include "SDL_image.h"
//#include "SDL_rotozoom.h"

#include "Control.h"
#include "Game.h"
#include "Tetri.h"
#include "Audio.h"

extern Game* game;
extern Tetri_EnginE* tetri_EnginE;
extern Audio* audio;

//-------------------------------------------------------------------------------------------------
Control::Control(void)
{
Uint8 joystick;

	for (joystick = 0; joystick < 6; joystick++)
	{
		JoystickDirection[joystick] = DirectionZERO;
		JoystickButton1[joystick] = OFF;
		JoystickButton1ActionTaken[joystick] = false;
		JoystickButton2[joystick] = OFF;
		JoystickButton2ActionTaken[joystick] = false;
		JoystickUPActionTaken[joystick] = false;
		JoystickDOWNActionTaken[joystick] = false;
		JoystickLEFTActionTaken[joystick] = false;
		JoystickRIGHTActionTaken[joystick] = false;
	}

	SingleMovementForJoystick = true;

	joystick1 = NULL;
	joystick2 = NULL;

	DelayUserInput = 0;
}

//-------------------------------------------------------------------------------------------------
Control::~Control(void)
{

}

//-------------------------------------------------------------------------------------------------
void Control::ZeroOutAllJoysticks(void)
{
Uint8 joystick;

	for (joystick = 0; joystick < 6; joystick++)
	{
		JoystickDirection[joystick] = DirectionZERO;
		JoystickButton1[joystick] = OFF;
		JoystickButton1ActionTaken[joystick] = false;
		JoystickButton2[joystick] = OFF;
		JoystickButton2ActionTaken[joystick] = false;
		JoystickUPActionTaken[joystick] = false;
	}
}

//-------------------------------------------------------------------------------------------------
void Control::GetInputFromUser(void)
{
Uint8 joystick;

    if (game->EXITgame == true)
    {
        return;
    }

	for (joystick = 0; joystick < 6; joystick++)
	{
		JoystickDirection[joystick] = DirectionZERO;
		JoystickButton1[joystick] = OFF;
		JoystickButton2[joystick] = OFF;
	}

	KeyOnKeyboardPressedByUser = (char) NULL;

	Uint8 *keystates = SDL_GetKeyState( NULL );

	switch( game->Event.type )
	{
		case SDL_QUIT:
			game->EXITgame = true;
			break;

		case SDL_KEYDOWN:
			switch( game->Event.key.keysym.sym )
			{
				case SDLK_ESCAPE:
					game->EXITgame = true;
					break;

				case SDLK_a:
					if ( (keystates[SDLK_LSHIFT])||(keystates[SDLK_RSHIFT]) )  KeyOnKeyboardPressedByUser = 'A';
					else  KeyOnKeyboardPressedByUser = 'a';
					break;

				case SDLK_b:
					if ( (keystates[SDLK_LSHIFT])||(keystates[SDLK_RSHIFT]) )  KeyOnKeyboardPressedByUser = 'B';
					else  KeyOnKeyboardPressedByUser = 'b';
					break;

				case SDLK_c:
					if ( (keystates[SDLK_LSHIFT])||(keystates[SDLK_RSHIFT]) )  KeyOnKeyboardPressedByUser = 'C';
					else  KeyOnKeyboardPressedByUser = 'c';
					break;

				case SDLK_d:
					if ( (keystates[SDLK_LSHIFT])||(keystates[SDLK_RSHIFT]) )  KeyOnKeyboardPressedByUser = 'D';
					else  KeyOnKeyboardPressedByUser = 'd';
					break;

				case SDLK_e:
					if ( (keystates[SDLK_LSHIFT])||(keystates[SDLK_RSHIFT]) )  KeyOnKeyboardPressedByUser = 'E';
					else  KeyOnKeyboardPressedByUser = 'e';
					break;

				case SDLK_f:
					if ( (keystates[SDLK_LSHIFT])||(keystates[SDLK_RSHIFT]) )  KeyOnKeyboardPressedByUser = 'F';
					else  KeyOnKeyboardPressedByUser = 'f';
					break;

				case SDLK_g:
					if ( (keystates[SDLK_LSHIFT])||(keystates[SDLK_RSHIFT]) )  KeyOnKeyboardPressedByUser = 'G';
					else  KeyOnKeyboardPressedByUser = 'g';
					break;

				case SDLK_h:
					if ( (keystates[SDLK_LSHIFT])||(keystates[SDLK_RSHIFT]) )  KeyOnKeyboardPressedByUser = 'H';
					else  KeyOnKeyboardPressedByUser = 'h';
					break;

				case SDLK_i:
					if ( (keystates[SDLK_LSHIFT])||(keystates[SDLK_RSHIFT]) )  KeyOnKeyboardPressedByUser = 'I';
					else  KeyOnKeyboardPressedByUser = 'i';
					break;

				case SDLK_j:
					if ( (keystates[SDLK_LSHIFT])||(keystates[SDLK_RSHIFT]) )  KeyOnKeyboardPressedByUser = 'J';
					else  KeyOnKeyboardPressedByUser = 'j';
					break;

				case SDLK_k:
					if ( (keystates[SDLK_LSHIFT])||(keystates[SDLK_RSHIFT]) )  KeyOnKeyboardPressedByUser = 'K';
					else  KeyOnKeyboardPressedByUser = 'k';
					break;

				case SDLK_l:
					if ( (keystates[SDLK_LSHIFT])||(keystates[SDLK_RSHIFT]) )  KeyOnKeyboardPressedByUser = 'L';
					else  KeyOnKeyboardPressedByUser = 'l';
					break;

				case SDLK_m:
					if ( (keystates[SDLK_LSHIFT])||(keystates[SDLK_RSHIFT]) )  KeyOnKeyboardPressedByUser = 'M';
					else  KeyOnKeyboardPressedByUser = 'm';
					break;

				case SDLK_n:
					if ( (keystates[SDLK_LSHIFT])||(keystates[SDLK_RSHIFT]) )  KeyOnKeyboardPressedByUser = 'N';
					else  KeyOnKeyboardPressedByUser = 'n';
					break;

				case SDLK_o:
					if ( (keystates[SDLK_LSHIFT])||(keystates[SDLK_RSHIFT]) )  KeyOnKeyboardPressedByUser = 'O';
					else  KeyOnKeyboardPressedByUser = 'o';
					break;

				case SDLK_p:
					if ( (keystates[SDLK_LSHIFT])||(keystates[SDLK_RSHIFT]) )  KeyOnKeyboardPressedByUser = 'P';
					else  KeyOnKeyboardPressedByUser = 'p';
					break;

				case SDLK_q:
					if ( (keystates[SDLK_LSHIFT])||(keystates[SDLK_RSHIFT]) )  KeyOnKeyboardPressedByUser = 'Q';
					else  KeyOnKeyboardPressedByUser = 'q';
					break;

				case SDLK_r:
					if ( (keystates[SDLK_LSHIFT])||(keystates[SDLK_RSHIFT]) )  KeyOnKeyboardPressedByUser = 'R';
					else  KeyOnKeyboardPressedByUser = 'r';
					break;

				case SDLK_s:
					if ( (keystates[SDLK_LSHIFT])||(keystates[SDLK_RSHIFT]) )  KeyOnKeyboardPressedByUser = 'S';
					else  KeyOnKeyboardPressedByUser = 's';
					break;

				case SDLK_t:
					if ( (keystates[SDLK_LSHIFT])||(keystates[SDLK_RSHIFT]) )  KeyOnKeyboardPressedByUser = 'T';
					else  KeyOnKeyboardPressedByUser = 't';
					break;

				case SDLK_u:
					if ( (keystates[SDLK_LSHIFT])||(keystates[SDLK_RSHIFT]) )  KeyOnKeyboardPressedByUser = 'U';
					else  KeyOnKeyboardPressedByUser = 'u';
					break;

				case SDLK_v:
					if ( (keystates[SDLK_LSHIFT])||(keystates[SDLK_RSHIFT]) )  KeyOnKeyboardPressedByUser = 'V';
					else  KeyOnKeyboardPressedByUser = 'v';
					break;

				case SDLK_w:
					if ( (keystates[SDLK_LSHIFT])||(keystates[SDLK_RSHIFT]) )  KeyOnKeyboardPressedByUser = 'W';
					else  KeyOnKeyboardPressedByUser = 'w';
					break;

				case SDLK_x:
					if ( (keystates[SDLK_LSHIFT])||(keystates[SDLK_RSHIFT]) )  KeyOnKeyboardPressedByUser = 'X';
					else  KeyOnKeyboardPressedByUser = 'x';
					break;

				case SDLK_y:
					if ( (keystates[SDLK_LSHIFT])||(keystates[SDLK_RSHIFT]) )  KeyOnKeyboardPressedByUser = 'Y';
					else  KeyOnKeyboardPressedByUser = 'y';
					break;

				case SDLK_z:
					if ( (keystates[SDLK_LSHIFT])||(keystates[SDLK_RSHIFT]) )  KeyOnKeyboardPressedByUser = 'Z';
					else  KeyOnKeyboardPressedByUser = 'z';
					break;

				case SDLK_KP_PLUS:
					KeyOnKeyboardPressedByUser = '+';
					break;

				case SDLK_0:
					KeyOnKeyboardPressedByUser = '0';
					break;

				case SDLK_1:
					KeyOnKeyboardPressedByUser = '1';
					break;

				case SDLK_2:
					KeyOnKeyboardPressedByUser = '2';
					break;

				case SDLK_3:
					KeyOnKeyboardPressedByUser = '3';
					break;

				case SDLK_4:
					KeyOnKeyboardPressedByUser = '4';
					break;

				case SDLK_5:
					KeyOnKeyboardPressedByUser = '5';
					break;

				case SDLK_6:
					KeyOnKeyboardPressedByUser = '6';
					break;

				case SDLK_7:
					KeyOnKeyboardPressedByUser = '7';
					break;

				case SDLK_8:
					KeyOnKeyboardPressedByUser = '8';
					break;

				case SDLK_9:
					KeyOnKeyboardPressedByUser = '9';
					break;

				case SDLK_BACKSPACE:
					KeyOnKeyboardPressedByUser = '<';
					break;

				case SDLK_RETURN:
					KeyOnKeyboardPressedByUser = '>';
					break;

				case SDLK_SPACE:
				KeyOnKeyboardPressedByUser = ' ';
				break;

				default:
				break;
			}
	}

//------------------------------------------
	if ( keystates[ SDLK_UP ]    )
	{
		if (JoystickUPActionTaken[Keyboard] == false)  JoystickDirection[Keyboard] = UP;
		JoystickUPActionTaken[Keyboard] = true;
	}
	else  JoystickUPActionTaken[Keyboard] = false;


	if (SingleMovementForJoystick == false)
	{
		if ( keystates[ SDLK_DOWN ]  )  JoystickDirection[Keyboard] = DOWN;
		else if ( keystates[ SDLK_LEFT ]  )  JoystickDirection[Keyboard] = LEFT;
		else if ( keystates[ SDLK_RIGHT ] )  JoystickDirection[Keyboard] = RIGHT;
	}
	else
	{
		if ( keystates[ SDLK_DOWN ]    )
		{
			if (JoystickDOWNActionTaken[Keyboard] == false)  JoystickDirection[Keyboard] = DOWN;
			JoystickDOWNActionTaken[Keyboard] = true;
		}
		else  JoystickDOWNActionTaken[Keyboard] = false;

		if ( keystates[ SDLK_LEFT ]    )
		{
			if (JoystickLEFTActionTaken[Keyboard] == false)  JoystickDirection[Keyboard] = LEFT;
			JoystickLEFTActionTaken[Keyboard] = true;
		}
		else  JoystickLEFTActionTaken[Keyboard] = false;

		if ( keystates[ SDLK_RIGHT ]    )
		{
			if (JoystickRIGHTActionTaken[Keyboard] == false)  JoystickDirection[Keyboard] = RIGHT;
			JoystickRIGHTActionTaken[Keyboard] = true;
		}
		else  JoystickRIGHTActionTaken[Keyboard] = false;
	}

	if (game->GameScreen != NewHighScoreNameInputScreen)
	{
		if ( keystates[ SDLK_z ] )
		{
			if (JoystickButton1ActionTaken[Keyboard] == false)  JoystickButton1[Keyboard] = ON;
			JoystickButton1ActionTaken[Keyboard] = true;
		}
		else  JoystickButton1ActionTaken[Keyboard] = false;

		if ( keystates[ SDLK_x ] )
		{
			if (JoystickButton2ActionTaken[Keyboard] == false)  JoystickButton2[Keyboard] = ON;
			JoystickButton2ActionTaken[Keyboard] = true;
		}
		else JoystickButton2ActionTaken[Keyboard] = false;
	}
//------------------------------------------
	SDL_GetMouseState(&MouseX, &MouseY);

	if ( SDL_GetMouseState(NULL, NULL)&SDL_BUTTON(1) )
	{
		if (JoystickButton1ActionTaken[Mouse] == false)  JoystickButton1[Mouse] = ON;
		JoystickButton1ActionTaken[Mouse] = true;
	}
	else JoystickButton1ActionTaken[Mouse] = false;

	if ( SDL_GetMouseState(NULL, NULL)&SDL_BUTTON(3) )
	{
		if (JoystickButton2ActionTaken[Mouse] == false)  JoystickButton2[Mouse] = ON;
		JoystickButton2ActionTaken[Mouse] = true;
	}
	else JoystickButton2ActionTaken[Mouse] = false;
//------------------------------------------
	if (joystick1)
	{
		SDL_JoystickUpdate();

		Sint16 joystickXmovement = SDL_JoystickGetAxis(joystick1, 0);
		Sint16 joystickYmovement = SDL_JoystickGetAxis(joystick1, 1);

		if (joystickYmovement < -16383)
		{
			if (JoystickUPActionTaken[Joystick1] == false)  JoystickDirection[Joystick1] = UP;
			JoystickUPActionTaken[Joystick1] = true;
		}
		else  JoystickUPActionTaken[Joystick1] = false;

		if (SingleMovementForJoystick == false)
		{
			if (joystickYmovement >  16383)  JoystickDirection[Joystick1] = DOWN;
			else if (joystickXmovement < -16383)  JoystickDirection[Joystick1] = LEFT;
			else if (joystickXmovement >  16383)  JoystickDirection[Joystick1] = RIGHT;
		}
		else
		{
			if (joystickYmovement >  16383)
			{
				if (JoystickDOWNActionTaken[Joystick1] == false)  JoystickDirection[Joystick1] = DOWN;
				JoystickDOWNActionTaken[Joystick1] = true;
			}
			else  JoystickDOWNActionTaken[Joystick1] = false;

			if (joystickXmovement < -16383)
			{
				if (JoystickLEFTActionTaken[Joystick1] == false)  JoystickDirection[Joystick1] = LEFT;
				JoystickLEFTActionTaken[Joystick1] = true;
			}
			else  JoystickLEFTActionTaken[Joystick1] = false;

			if (joystickXmovement >  16383)
			{
				if (JoystickRIGHTActionTaken[Joystick1] == false)  JoystickDirection[Joystick1] = RIGHT;
				JoystickRIGHTActionTaken[Joystick1] = true;
			}
			else  JoystickRIGHTActionTaken[Joystick1] = false;
		}

		if ( SDL_JoystickGetButton(joystick1, 0) )
		{
			if (JoystickButton1ActionTaken[Joystick1] == false)  JoystickButton1[Joystick1] = ON;
			JoystickButton1ActionTaken[Joystick1] = true;
		}
		else JoystickButton1ActionTaken[Joystick1] = false;

		if ( SDL_JoystickGetButton(joystick1, 1) )
		{
			if (JoystickButton2ActionTaken[Joystick1] == false)  JoystickButton2[Joystick1] = ON;
			JoystickButton2ActionTaken[Joystick1] = true;
		}
		else JoystickButton2ActionTaken[Joystick1] = false;
	}
//------------------------------------------
	if (joystick2)
	{
		Sint16 joystickXmovement = SDL_JoystickGetAxis(joystick2, 0);
		Sint16 joystickYmovement = SDL_JoystickGetAxis(joystick2, 1);

		if (joystickYmovement < -16383)
		{
			if (JoystickUPActionTaken[Joystick2] == false)  JoystickDirection[Joystick2] = UP;
			JoystickUPActionTaken[Joystick2] = true;
		}
		else  JoystickUPActionTaken[Joystick2] = false;

		if (SingleMovementForJoystick == false)
		{
			if (joystickYmovement >  16383)  JoystickDirection[Joystick2] = DOWN;
			else if (joystickXmovement < -16383)  JoystickDirection[Joystick2] = LEFT;
			else if (joystickXmovement >  16383)  JoystickDirection[Joystick2] = RIGHT;
		}
		else
		{
			if (joystickYmovement >  16383)
			{
				if (JoystickDOWNActionTaken[Joystick2] == false)  JoystickDirection[Joystick2] = DOWN;
				JoystickDOWNActionTaken[Joystick2] = true;
			}
			else  JoystickDOWNActionTaken[Joystick2] = false;

			if (joystickXmovement < -16383)
			{
				if (JoystickLEFTActionTaken[Joystick2] == false)  JoystickDirection[Joystick2] = LEFT;
				JoystickLEFTActionTaken[Joystick2] = true;
			}
			else  JoystickLEFTActionTaken[Joystick2] = false;

			if (joystickXmovement >  16383)
			{
				if (JoystickRIGHTActionTaken[Joystick2] == false)  JoystickDirection[Joystick2] = RIGHT;
				JoystickRIGHTActionTaken[Joystick2] = true;
			}
			else  JoystickRIGHTActionTaken[Joystick2] = false;
		}

		if ( SDL_JoystickGetButton(joystick2, 0) )
		{
			if (JoystickButton1ActionTaken[Joystick2] == false)  JoystickButton1[Joystick2] = ON;
			JoystickButton1ActionTaken[Joystick2] = true;
		}
		else JoystickButton1ActionTaken[Joystick2] = false;

		if ( SDL_JoystickGetButton(joystick2, 1) )
		{
			if (JoystickButton2ActionTaken[Joystick2] == false)  JoystickButton2[Joystick2] = ON;
			JoystickButton2ActionTaken[Joystick2] = true;
		}
		else JoystickButton2ActionTaken[Joystick2] = false;
	}

//------------------------------------------
	Uint8 howManyJoysticks = 0;
	if (joystick1)  howManyJoysticks++;
	if (joystick2)  howManyJoysticks++;

	for (Uint8 controller = 1; controller < (3 + howManyJoysticks); controller++)
	{
		if (JoystickDirection[controller] == UP) JoystickDirection[Any] = UP;
		else if (JoystickDirection[controller] == DOWN) JoystickDirection[Any] = DOWN;
		else if (JoystickDirection[controller] == LEFT) JoystickDirection[Any] = LEFT;
		else if (JoystickDirection[controller] == RIGHT) JoystickDirection[Any] = RIGHT;

		if (JoystickButton1[controller] == ON)  JoystickButton1[Any] = ON;
		if (JoystickButton2[controller] == ON)  JoystickButton2[Any] = ON;
	}
//------------------------------------------
	howManyJoysticks = 0;
	if (joystick1)  howManyJoysticks++;
	if (joystick2)  howManyJoysticks++;

	for (Uint8 controller = 1; controller < (3 + howManyJoysticks); controller++)
	{
		if (controller != Mouse)
		{
			if (JoystickDirection[controller] == UP) JoystickDirection[NoMouse] = UP;
			else if (JoystickDirection[controller] == DOWN) JoystickDirection[NoMouse] = DOWN;
			else if (JoystickDirection[controller] == LEFT) JoystickDirection[NoMouse] = LEFT;
			else if (JoystickDirection[controller] == RIGHT) JoystickDirection[NoMouse] = RIGHT;

			if (JoystickButton1[controller] == ON)  JoystickButton1[NoMouse] = ON;
			if (JoystickButton2[controller] == ON)  JoystickButton2[NoMouse] = ON;
		}
	}
//------------------------------------------
	howManyJoysticks = 0;
	if (joystick1)  howManyJoysticks++;
	if (joystick2)  howManyJoysticks++;

	for (Uint8 controller = 1; controller < (3 + howManyJoysticks); controller++)
	{
		if (controller != Keyboard)
		{
			if (JoystickDirection[controller] == UP) JoystickDirection[NoKeyboard] = UP;
			else if (JoystickDirection[controller] == DOWN) JoystickDirection[NoKeyboard] = DOWN;
			else if (JoystickDirection[controller] == LEFT) JoystickDirection[NoKeyboard] = LEFT;
			else if (JoystickDirection[controller] == RIGHT) JoystickDirection[NoKeyboard] = RIGHT;

			if (JoystickButton1[controller] == ON)  JoystickButton1[NoKeyboard] = ON;
			if (JoystickButton2[controller] == ON)  JoystickButton2[NoKeyboard] = ON;
		}
	}

	if (DelayUserInput > 0)
	{
		KeyOnKeyboardPressedByUser = (char)NULL;
		ZeroOutAllJoysticks();
		DelayUserInput--;
	}
}
