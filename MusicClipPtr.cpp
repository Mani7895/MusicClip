#include "MusicClipPtr.h"

int MusicClipPtr::numPtrs = 0;
queue<MusicClipPtr*> MusicClipPtr::loadedPointers;

MusicClipPtr::MusicClipPtr()
:id(numPtrs), musicClip(), memory()
{
    numPtrs++;
}

MusicClipPtr::~MusicClipPtr()
{
	if (musicClip != NULL)
	{
		memory.saveMusicClip(*musicClip);
		delete musicClip;
		musicClip = NULL;
		numPtrs--;
	}
}

MusicClip* MusicClipPtr::operator->()
{
	if (musicClip == NULL)
	{
		if (loadedPointers.size() >= 3)
		{
			loadedPointers.front()->~MusicClipPtr();
			loadedPointers.pop();
		}
		loadedPointers.push(this);
		memory.loadMusicClip(id, musicClip);
	}
	return musicClip;
}

MusicClip& MusicClipPtr::operator*()
{
	if (musicClip == NULL)
	{
		if (loadedPointers.size() >= 3)
		{
			loadedPointers.front()->~MusicClipPtr();
			loadedPointers.pop();
		}
		loadedPointers.push(this);
		memory.loadMusicClip(id, musicClip);
	}
	return *musicClip;
}
int MusicClipPtr::getID()
{
    return id;
}

