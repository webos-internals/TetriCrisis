// Audio_CLASS.cpp

#include "SDL.h"
#include "SDL_ttf.h"
#include "SDL_mixer.h"
#include "SDL_image.h"
//#include "SDL_rotozoom.h"

#include "Audio.h"

//-------------------------------------------------------------------------------------------------
Audio::Audio(void)
{
	SDL_Audio_Enabled = false;

	CurrentlySelectedMusicTrack = 0;

	SoundVolume = 64;
	MusicVolume = 64;
}

//-------------------------------------------------------------------------------------------------
Audio::~Audio(void)
{

}

//-------------------------------------------------------------------------------------------------
void Audio::LoadMusicIntoMemory(void)
{
	MusicTrack[0] = Mix_LoadMUS("data/music/Opening_Music.ogg");
	if(!MusicTrack[0])
	{
		fprintf(stderr, "Couldn't load %s: %s\n", "Music", Mix_GetError());
	}
//------------------------------------------
	MusicTrack[1] = Mix_LoadMUS("data/music/Title_Screen_Music.mus");
	if(!MusicTrack[1])
	{
		fprintf(stderr, "Couldn't load %s: %s\n", "Music", Mix_GetError());
	}
//------------------------------------------
	MusicTrack[2] = Mix_LoadMUS("data/music/Tetri_Music.mus");
	if(!MusicTrack[2])
	{
		fprintf(stderr, "Couldn't load %s: %s\n", "Music", Mix_GetError());
	}
//------------------------------------------
	MusicTrack[3] = Mix_LoadMUS("data/music/Final_Countdown_Music.mus");
	if(!MusicTrack[3])
	{
		fprintf(stderr, "Couldn't load %s: %s\n", "Music", Mix_GetError());
	}
//------------------------------------------
	MusicTrack[4] = Mix_LoadMUS("data/music/In-Game_Music_03.mus");
	if(!MusicTrack[4])
	{
		fprintf(stderr, "Couldn't load %s: %s\n", "Music", Mix_GetError());
	}
//------------------------------------------
	MusicTrack[5] = Mix_LoadMUS("data/music/In-Game_Music_04.mus");
	if(!MusicTrack[5])
	{
		fprintf(stderr, "Couldn't load %s: %s\n", "Music", Mix_GetError());
	}
//------------------------------------------
	MusicTrack[6] = Mix_LoadMUS("data/music/In-Game_Music_05.mus");
	if(!MusicTrack[6])
	{
		fprintf(stderr, "Couldn't load %s: %s\n", "Music", Mix_GetError());
	}
//------------------------------------------
	MusicTrack[7] = Mix_LoadMUS("data/music/In-Game_Music_06.mus");
	if(!MusicTrack[7])
	{
		fprintf(stderr, "Couldn't load %s: %s\n", "Music", Mix_GetError());
	}
//------------------------------------------
	MusicTrack[8] = Mix_LoadMUS("data/music/In-Game_Music_07.mus");
	if(!MusicTrack[8])
	{
		fprintf(stderr, "Couldn't load %s: %s\n", "Music", Mix_GetError());
	}
//------------------------------------------
	MusicTrack[9] = Mix_LoadMUS("data/music/In-Game_Music_08.mus");
	if(!MusicTrack[9])
	{
		fprintf(stderr, "Couldn't load %s: %s\n", "Music", Mix_GetError());
	}
//------------------------------------------
	MusicTrack[10] = Mix_LoadMUS("data/music/In-Game_Music_09.mus");
	if(!MusicTrack[10])
	{
		fprintf(stderr, "Couldn't load %s: %s\n", "Music", Mix_GetError());
	}
//------------------------------------------
	MusicTrack[11] = Mix_LoadMUS("data/music/In-Game_Music_10.mus");
	if(!MusicTrack[11])
	{
		fprintf(stderr, "Couldn't load %s: %s\n", "Music", Mix_GetError());
	}
//------------------------------------------
	MusicTrack[12] = Mix_LoadMUS("data/music/High_Scores_Screen_Display.mus");
	if(!MusicTrack[12])
	{
		fprintf(stderr, "Couldn't load %s: %s\n", "Music", Mix_GetError());
	}
//------------------------------------------
	MusicTrack[13] = Mix_LoadMUS("data/music/NewNumber1Score.mus");
	if(!MusicTrack[13])
	{
		fprintf(stderr, "Couldn't load %s: %s\n", "Music", Mix_GetError());
	}
//------------------------------------------
	MusicTrack[14] = Mix_LoadMUS("data/music/NewHighScore2nd-5th.mus");
	if(!MusicTrack[14])
	{
		fprintf(stderr, "Couldn't load %s: %s\n", "Music", Mix_GetError());
	}
//------------------------------------------
	MusicTrack[15] = Mix_LoadMUS("data/music/CrisisMode_Level_7.mus");
	if(!MusicTrack[15])
	{
		fprintf(stderr, "Couldn't load %s: %s\n", "Music", Mix_GetError());
	}
//------------------------------------------
	MusicTrack[16] = Mix_LoadMUS("data/music/Staff_Screen.mus");
	if(!MusicTrack[15])
	{
		fprintf(stderr, "Couldn't load %s: %s\n", "Music", Mix_GetError());
	}
//------------------------------------------

	Mix_VolumeMusic(MusicVolume);
}

//-------------------------------------------------------------------------------------------------
void Audio::UnloadMusicFromMemory(void)
{
Uint8 musicIndex;

	Mix_HaltMusic();

	for (musicIndex = 0; musicIndex < MusicTotal; musicIndex++)
	{
		Mix_FreeMusic(MusicTrack[musicIndex]);
		MusicTrack[musicIndex] = NULL;
	}
}

//-------------------------------------------------------------------------------------------------
void Audio::PlayMusic(Uint8 musicIndex, int loop)
{
	if (SDL_Audio_Enabled == false)  return;
	if (Mix_PlayingMusic() == 1)  Mix_HaltMusic();
	if (MusicVolume == 0)  return;

	if(Mix_PlayMusic(MusicTrack[musicIndex], loop)==-1)
	{
		printf("Mix_PlayMusic: %s\n", Mix_GetError());
	}

	Mix_VolumeMusic(MusicVolume);
}

//-------------------------------------------------------------------------------------------------
void Audio::LoadDigitalSoundFXIntoMemory(void)
{
//------------------------------------------
	SoundFX[0] = Mix_LoadWAV("data/sounds/Move_Piece.wav");
	if(!SoundFX[0])
	{
		fprintf(stderr, "Couldn't load %s: %s\n", "Sound", Mix_GetError());
	}
	Mix_VolumeChunk(SoundFX[0], 128);
//------------------------------------------
	SoundFX[1] = Mix_LoadWAV("data/sounds/Piece_Rotate.wav");
	if(!SoundFX[1])
	{
		fprintf(stderr, "Couldn't load %s: %s\n", "Sound", Mix_GetError());
	}
	Mix_VolumeChunk(SoundFX[1], 128);
//------------------------------------------
	SoundFX[2] = Mix_LoadWAV("data/sounds/Piece_Drop.wav");
	if(!SoundFX[2])
	{
		fprintf(stderr, "Couldn't load %s: %s\n", "Sound", Mix_GetError());
	}
	Mix_VolumeChunk(SoundFX[2], 128);
//------------------------------------------
	SoundFX[3] = Mix_LoadWAV("data/sounds/Piece_Collision.wav");
	if(!SoundFX[3])
	{
		fprintf(stderr, "Couldn't load %s: %s\n", "Sound", Mix_GetError());
	}
	Mix_VolumeChunk(SoundFX[3], MIX_MAX_VOLUME);
//------------------------------------------
	SoundFX[4] = Mix_LoadWAV("data/sounds/Line_Cleared.wav");
	if(!SoundFX[4])
	{
		fprintf(stderr, "Couldn't load %s: %s\n", "Sound", Mix_GetError());
	}
	Mix_VolumeChunk(SoundFX[4], 128);
//------------------------------------------
	SoundFX[5] = Mix_LoadWAV("data/sounds/Tetris_Cleared.wav");
	if(!SoundFX[5])
	{
		fprintf(stderr, "Couldn't load %s: %s\n", "Sound", Mix_GetError());
	}
	Mix_VolumeChunk(SoundFX[5], 128);
//------------------------------------------
	SoundFX[6] = Mix_LoadWAV("data/sounds/Level_Up.wav");
	if(!SoundFX[6])
	{
		fprintf(stderr, "Couldn't load %s: %s\n", "Sound", Mix_GetError());
	}
	Mix_VolumeChunk(SoundFX[6], 128);
//------------------------------------------
	SoundFX[7] = Mix_LoadWAV("data/sounds/Incoming_Line.wav");
	if(!SoundFX[7])
	{
		fprintf(stderr, "Couldn't load %s: %s\n", "Sound", Mix_GetError());
	}
	Mix_VolumeChunk(SoundFX[7], 128);
//------------------------------------------
	SoundFX[8] = Mix_LoadWAV("data/sounds/Game_Over.wav");
	if(!SoundFX[8])
	{
		fprintf(stderr, "Couldn't load %s: %s\n", "Sound", Mix_GetError());
	}
	Mix_VolumeChunk(SoundFX[7], 128);
//------------------------------------------
	SoundFX[9] = Mix_LoadWAV("data/sounds/New_Top_High_Score.wav");
	if(!SoundFX[9])
	{
		fprintf(stderr, "Couldn't load %s: %s\n", "Sound", Mix_GetError());
	}
	Mix_VolumeChunk(SoundFX[7], 128);
//------------------------------------------
	SoundFX[10] = Mix_LoadWAV("data/sounds/Danger.wav");
	if(!SoundFX[10])
	{
		fprintf(stderr, "Couldn't load %s: %s\n", "Sound", Mix_GetError());
	}
	Mix_VolumeChunk(SoundFX[7], 128);
//------------------------------------------
}

//-------------------------------------------------------------------------------------------------
void Audio::UnloadDigitalSoundFXFromMemory(void)
{
Uint8 soundIndex;

	Mix_HaltChannel(-1);

	for (soundIndex = 0; soundIndex < SoundTotal; soundIndex++)
	{
		Mix_FreeChunk(SoundFX[soundIndex]);
		SoundFX[soundIndex] = NULL;
	}
}

//-------------------------------------------------------------------------------------------------
void Audio::PlayDigitalSoundFX(Uint8 soundIndex)
{
	if (SDL_Audio_Enabled == false)  return;

	Mix_Volume( 0, SoundVolume);
	Mix_Volume( 1, SoundVolume);
	Mix_Volume( 2, SoundVolume);
	Mix_Volume( 3, SoundVolume);
	Mix_Volume( 4, SoundVolume);
	Mix_Volume( 5, SoundVolume);
	Mix_Volume( 6, SoundVolume);
	Mix_Volume( 7, SoundVolume);
	Mix_Volume( 8, SoundVolume);
	Mix_Volume( 9, SoundVolume);
	Mix_Volume(10, SoundVolume);
	Mix_Volume(11, SoundVolume);
	Mix_Volume(12, SoundVolume);
	Mix_Volume(13, SoundVolume);
	Mix_Volume(14, SoundVolume);
	Mix_Volume(15, SoundVolume);

	if(Mix_PlayChannel(-1, SoundFX[soundIndex], 0)==-1)
	{
		printf("Mix_PlayChannel: %s\n",Mix_GetError());
	}
}
