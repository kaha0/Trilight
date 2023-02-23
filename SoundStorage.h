#pragma once

#include<dsound.h>
#include<map>
#include<fstream>
#include<stdexcept>

class SoundStorage
{
private:
	LPDIRECTSOUND8 Dsound;
	SoundStorage() {}
	bool ReadWavToBuffer(const char * file, LPDIRECTSOUNDBUFFER * buff);
public:
	enum SoundName
	{
		ZombieGrowl_1, InceptionSound
	};
	std::map<SoundName, LPDIRECTSOUNDBUFFER> * Sounds;

	SoundStorage(LPDIRECTSOUND8 dsound);
	LPDIRECTSOUNDBUFFER GetSound(SoundName sn);
	LPDIRECTSOUNDBUFFER LoadSound(SoundName sn);
	void ReleaseSound(SoundName sn);
	void ReleaseSounds();
	~SoundStorage();
};