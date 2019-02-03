#include "Command.h"
#include <queue>
#include <iostream>

Saver::Saver(queue<MusicClipPtr*> pointers)
:loadedPointers(pointers)
{
}

void Saver::saveFilesInMemory()
{
	while (!loadedPointers.empty())
	{
		MusicClip* temp = loadedPointers.front()->operator->();
		memory.saveMusicClip(*temp);

		cout << "#Music Clip with ID " << temp->getID() << " saved" << endl;

		loadedPointers.pop();
	}
}

void Saver::execute()
{
	saveFilesInMemory();
}

