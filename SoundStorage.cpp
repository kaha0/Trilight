#include<SoundStorage.h>

using namespace std;

unsigned int ReadUINT_BE(ifstream & r)
{
	unsigned int ui = 0;
	unsigned int aux = 0;
	unsigned char c;

	if (r.peek() == -1) throw exception();
	r >> c;
	aux = c;
	aux = aux << 24;
	ui += aux;
	if (r.peek() == -1) throw exception();
	r >> c;
	aux = c;
	aux = aux << 16;
	ui += aux;
	if (r.peek() == -1) throw exception();
	r >> c;
	aux = c;
	aux = aux << 8;
	ui += aux;
	if (r.peek() == -1) throw exception();
	r >> c;
	aux = c;
	ui += aux;

	return ui;
}

unsigned int ReadUINT_LE(ifstream & r)
{
	unsigned int ui = 0;
	unsigned int aux = 0;
	unsigned char c;

	if (r.peek() == -1) throw exception();
	r >> c;
	aux = c;
	ui += aux;
	if (r.peek() == -1) throw exception();
	r >> c;
	aux = c;
	aux = aux << 8;
	ui += aux;
	if (r.peek() == -1) throw exception();
	r >> c;
	aux = c;
	aux = aux << 16;
	ui += aux;
	if (r.peek() == -1) throw exception();
	r >> c;
	aux = c;
	aux = aux << 24;
	ui += aux;

	return ui;
}

short ReadShort_LE(ifstream & r)
{
	short s = 0;
	short aux = 0;
	unsigned char c;

	if (r.peek() == -1) throw exception();
	r >> c;
	aux = c;
	s += aux;
	if (r.peek() == -1) throw exception();
	r >> c;
	aux = c;
	aux = aux << 8;
	s += aux;

	return s;
}

float ReadFloat_LE(ifstream & r)
{
	union
	{
		unsigned int ui;
		float f;
	} convert;
	convert.ui = ReadUINT_LE(r);
	return convert.f;
}

bool SoundStorage::ReadWavToBuffer(const char * file, LPDIRECTSOUNDBUFFER * buff)
{
	ifstream r;
	try
	{
		r.open(file, ios_base::binary);
		if (!r.is_open()) throw exception();
	}
	catch (...)
	{ return false; }

	r >> noskipws;  // !!

	try
	{
		unsigned int ui = ReadUINT_BE(r);
		if (ui != 0x52494646) throw exception();  // "RIFF"
		unsigned int length = ReadUINT_LE(r);
		ui = ReadUINT_BE(r);
		if (ui != 0x57415645) throw exception();  // "WAVE"
		ui = ReadUINT_BE(r);
		while (ui != 0x666d7420)  // "fmt "
		{
			ui = ReadUINT_LE(r);
			for (unsigned int i = 0; i < ui; ++i)
			{
				if (r.peek() == -1) throw exception();
				unsigned char c;
				r >> c;
			}
			ui = ReadUINT_BE(r);
		}

		// naèetli jsme "fmt "
		ui = ReadUINT_LE(r);  // subchunk size, must be 16 for PCM
		if (ui != 16) throw exception();
		short s = ReadShort_LE(r);
		if (s != 1) throw exception();

		WAVEFORMATEX wf;
		memset(&wf, 0, sizeof(WAVEFORMATEX));
		wf.wFormatTag = WAVE_FORMAT_PCM;

		s = ReadShort_LE(r);
		wf.nChannels = s;

		ui = ReadUINT_LE(r);
		wf.nSamplesPerSec = ui;

		ui = ReadUINT_LE(r);
		wf.nAvgBytesPerSec = ui;

		s = ReadShort_LE(r);
		wf.nBlockAlign = s;
		
		s = ReadShort_LE(r);
		wf.wBitsPerSample = s;

		ui = ReadUINT_BE(r);
		while (ui != 0x64617461)  // "data"
		{
			ui = ReadUINT_LE(r);
			for (unsigned int i = 0; i < ui; ++i)
			{
				if (r.peek() == -1) throw exception();
				unsigned char c;
				r >> c;
			}
			ui = ReadUINT_BE(r);
		}

		//naèetli jsme "data"
		length = ReadUINT_LE(r);

		DSBUFFERDESC bd;
		memset(&bd, 0, sizeof(DSBUFFERDESC));
		bd.dwSize = sizeof(DSBUFFERDESC);
		bd.dwFlags = DSBCAPS_CTRLPAN | DSBCAPS_CTRLVOLUME | DSBCAPS_CTRLFREQUENCY | DSBCAPS_GLOBALFOCUS; 
		bd.dwBufferBytes = length;  // celej soubor se nacpe do bufferu
		bd.lpwfxFormat = &wf;
		LPDIRECTSOUNDBUFFER pdsb;

		if (FAILED(Dsound->CreateSoundBuffer(&bd, &pdsb, NULL))) throw exception();
		LPVOID writepos;
		DWORD bufflength;
		if (FAILED(pdsb->Lock(0, 0, &writepos, &bufflength, NULL, NULL, DSBLOCK_ENTIREBUFFER)))
		{
			pdsb->Release();
			throw exception();
		}
		if (bufflength < length) length = bufflength;  // ??

		try
		{
			unsigned char * cwritepos = (unsigned char *)writepos;
			for (unsigned int i = 0; i < length; ++i)
			{
				if (r.peek() == -1) throw exception();
				unsigned char c;
				r >> c;
				(*cwritepos) = c;
				++cwritepos;
			}
			r.close();
			pdsb->Unlock(writepos, bufflength, NULL, 0);
			(*buff) = pdsb;
			return true;
		}
		catch (...)
		{
			pdsb->Unlock(writepos, bufflength, NULL, 0);
			pdsb->Release();
			r.close();
			return false;
		}
	}
	catch (...)
	{
		r.close();
		return false;
	}
}

SoundStorage::SoundStorage(LPDIRECTSOUND8 dsound)
{
	Dsound = dsound;
	Sounds = new map<SoundName, LPDIRECTSOUNDBUFFER>();
}

LPDIRECTSOUNDBUFFER SoundStorage::GetSound(SoundName sn)
{
	map<SoundName, LPDIRECTSOUNDBUFFER>::iterator it = Sounds->find(sn);
	if (it == Sounds->end()) return LoadSound(sn);
	else return it->second;
}

LPDIRECTSOUNDBUFFER SoundStorage::LoadSound(SoundName sn)
{
	map<SoundName, LPDIRECTSOUNDBUFFER>::iterator it = Sounds->find(sn);
	if (it != Sounds->end()) return it->second;

	LPDIRECTSOUNDBUFFER dsb;
	switch (sn)
	{
	case SoundName::InceptionSound:
		ReadWavToBuffer("data\\sound\\b.wav", &dsb);
		Sounds->insert(pair<SoundName, LPDIRECTSOUNDBUFFER>(sn, dsb));
		return dsb;

	case SoundName::ZombieGrowl_1:
		ReadWavToBuffer("data\\sound\\a.wav", &dsb);
		Sounds->insert(pair<SoundName, LPDIRECTSOUNDBUFFER>(sn, dsb));
		return dsb;
	}
}

void SoundStorage::ReleaseSound(SoundName sn)
{
	map<SoundName, LPDIRECTSOUNDBUFFER>::iterator it = Sounds->find(sn);
	if (it == Sounds->end()) return;
	it->second->Release();
	Sounds->erase(it);
}

void SoundStorage::ReleaseSounds()
{
	for (map<SoundName, LPDIRECTSOUNDBUFFER>::iterator it = Sounds->begin(); it != Sounds->end(); ++it)
	{
		if (it->second) it->second->Release();
	}
	Sounds->clear();
}

SoundStorage::~SoundStorage()
{
	//ReleaseSounds();  NE! když voláme ~Game() tak už bylo voláno Dsound->Release()
	//					u DirectX to nevadí ale DirectSound vyhazuje chybu
	delete Sounds;
}