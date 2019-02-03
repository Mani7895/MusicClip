#include "Command.h"
#include <iostream>
#include <fstream>

Copying::Copying(Iterator& iter)
	:currentMusicClip(iter)
{
}

void Copying::execute()
{
    ofstream outputFile("temp.clip");
	//outputFile << currentMusicClip->getData()->getID() << endl;
	outputFile << currentMusicClip->getData()->getIndex() << endl;
	outputFile << currentMusicClip->getData()->getArtist() << endl;
	outputFile << currentMusicClip->getData()->getType() << endl;
	outputFile << currentMusicClip->getData()->getTitle() << endl;
	outputFile << currentMusicClip->getData()->getPrice() << endl;
	for (string& people : currentMusicClip->getData()->getPeople())
    {
        outputFile << people << endl;
    }
	outputFile.close();
	cout << "Done" << endl;
}


