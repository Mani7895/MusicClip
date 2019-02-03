#include "Command.h"
#include <iostream>

string cr;

Creator::Creator(LinkedList& list)
: memory(), id(-1), index(-1), artist("NA"), type(OTHER), people(), title("NA"), clip(), price(-1.0), musicClips(list)
{
}

void Creator::getID()
{
	while (id < 0 || id > 9)
	{
		cout << endl << "\t Music Clip ID (0 - 9): ";
		cin >> id;
		getline(cin, cr);
	}
}

void Creator::getIndex()
{
	while (index < 0 || index > 9)
	{
		cout << endl << "\t Music Clip Index (0 - 9): ";
		cin >> index;
		getline(cin, cr);
	}
}

void Creator::getArtist()
{
	cout << endl << "\t Artist name: ";
	getline(cin, artist);
}

void Creator::getType()
{
	int type = -1;

	cout << endl << "\t Genre Types:";
	cout << endl << "\t\tPop Music      : 0";
	cout << endl << "\t\tFolk Music     : 1";
	cout << endl << "\t\tJazz           : 2";
	cout << endl << "\t\tBlues          : 3";
	cout << endl << "\t\tClassical      : 4";
	cout << endl << "\t\tOpera          : 5";
	cout << endl << "\t\tCountry Music  : 6";
	cout << endl << "\t\tReggae         : 7";
	cout << endl << "\t\tRock           : 8";
	cout << endl << "\t\tOther          : 9";

	while (type < 0 || type > 9)
	{
		cout << endl << "\t Genre Type (0 - 9): ";
		cin >> type;
		getline(cin, cr);
	}

	this->type = (GenreType)(type);
}

void Creator::getTitle()
{
	cout << endl << "\t Title name: ";
	getline(cin, title);
}

void Creator::getClip()
{
	string temp = "/";
	cout << endl << "\t Enter Clip - Byte Array (enter '//' to end input): " << endl << "\t\t";

	getline(cin, temp);

	while (temp.compare("//") != 0)
	{
		clip.push_back(temp[0]);
		cout << "\t\t";
		getline(cin, temp);
	}

}

void Creator::getPrice()
{
	cout << endl << "\t Price: ";
	cin >> price;
	getline(cin, cr);
}

void Creator::getPeople()
{
	string temp = "/";
	cout << endl << "\t People (enter '//' to end input): " << endl << "\t\t";

	getline(cin, temp);

	while (temp.compare("//") != 0)
	{
		people.push_back(temp);
		cout << "\t\t";
		getline(cin, temp);
	}

}

void Creator::musicClipPrompt()
{
	getID();
	getIndex();
	getArtist();
	getType();
	getTitle();
	getClip();
	getPrice();
	getPeople();
}

void Creator::saveToPointer(MusicClip& musicClip)
{
	for (Iterator iter = musicClips.begin(); iter != musicClips.end(); iter++)
	{
		if (iter->getData()->getID() == id)
		{
			*(iter->getData()) = musicClip;
			return;
		}
	}
}

void Creator::execute()
{
	musicClipPrompt();

	MusicClip musicClip(id, index, artist, type, people, title, clip, price);

	memory.saveMusicClip(musicClip);

	saveToPointer(musicClip);

}

