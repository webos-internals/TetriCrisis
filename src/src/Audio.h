//Audio_CLASS.h

#include "SDL.h"
#include "SDL_ttf.h"
#include "SDL_mixer.h"
#include "SDL_image.h"
//#include "SDL_rotozoom.h"

//-------------------------------------------------------------------------------------------------
#define MusicTotal 	17
#define SoundTotal 	11

#define Loop		-1

class Audio
{
public:

	Audio(void);
	virtual ~Audio(void);

	bool SDL_Audio_Enabled;

	Mix_Music *MusicTrack[MusicTotal];
	int MusicVolume;

	Uint8 CurrentlySelectedMusicTrack;

	Mix_Chunk *SoundFX[SoundTotal];
	int SoundVolume;

	void LoadMusicIntoMemory(void);
	void UnloadMusicFromMemory(void);
	void PlayMusic(Uint8 musicIndex, int loop);
	void LoadDigitalSoundFXIntoMemory(void);
	void UnloadDigitalSoundFXFromMemory(void);
	void PlayDigitalSoundFX(Uint8 soundIndex);
};
