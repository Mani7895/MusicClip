#include "Memory.h"
#include <fstream>
#include <stdint.h>
#include <iostream>
void Memory::loadMusicClip(int id, MusicClip*& musicclip)
{
    string line;
    ifstream inputFile(to_string(id));
    if(!inputFile.good())
    {
        musicclip = NULL;
        return;
    }

    int index = -1;
    string artist = "NA";
    GenreType type = (GenreType)(9);
    vector<string> people;
    string title = "NA";
    vector<uint8_t> clip;
    float price = -1.0;

    getline(inputFile, line);
	index = stoi(line);

    getline(inputFile, line);
	artist = line;


    getline(inputFile, line);
    type = (GenreType)(stoi(line));

    //getline(inputFile, line);  //Skipping for people

    getline(inputFile, line);
    title = line;

    getline(inputFile, line);
	price = stof(line);
    while (getline(inputFile, line))
	{
		people.push_back(line);
	}
	musicclip = new MusicClip(id, index, artist, type, people, title, clip, price);
}
void Memory::saveMusicClip(MusicClip& musicClip)
{
	ofstream outputFile(to_string(musicClip.getID()));
    //outputFile << musicClip.getID() << endl;
    outputFile << musicClip.getIndex() << endl;
    outputFile << musicClip.getArtist() << endl;
    //outputFile << musicClip.getPeople() << endl;
	outputFile << musicClip.getType() << endl;
	outputFile << musicClip.getTitle() << endl;
	outputFile << musicClip.getPrice() << endl;

	for (string& people : musicClip.getPeople())
	{
		outputFile << people << endl;
	}
}

