#include "Command.h"
#include <iostream>

Listor::Listor(LinkedList& musicClipList)
: musicClips(musicClipList)
{
}

void Listor::execute()
{
	for (Iterator iter = musicClips.begin(); iter != musicClips.end(); iter++)
	{
		if (iter->getData().operator->() != NULL)
		{
			cout << "\t Music Clip ID: " << iter->getData()->getID() << endl;

            cout << "\t Index: " << iter->getData()->getIndex() << endl;

            cout << "\t Artist: " << iter->getData()->getArtist() << endl;

			cout << "\t Genre Type: ";
			GenreType type = iter->getData()->getType();
 			switch (type)
			{
			case POP_MUSIC:
				cout << "Pop Music" << endl;
				break;
			case FOLK_MUSIC:
				cout << "Folk Music" << endl;
				break;
			case JAZZ:
				cout << "Jazz" << endl;
				break;
            case BLUES:
                cout << "Blues" << endl;
				break;
            case CLASSICAL:
                cout << "Classical" << endl;
                break;
            case OPERA:
                cout << "Opera" << endl;
                break;
            case COUNTRY_MUSIC:
                cout << "Country Music" << endl;
                break;
            case REGGAE:
                cout << "Reggae" << endl;
                break;
            case ROCK:
                cout << "Rock" << endl;
                break;
            case OTHER:
                cout << "OTHER" << endl;
                break;
			};

			cout << "\t People:" << endl;
			for (string& people : iter->getData()->getPeople())
			{
				cout << "\t\t" << people << endl;
			}

            cout << "\t Title: " << iter->getData()->getTitle() << endl;

			cout << "\t Price: $" << iter->getData()->getPrice() << endl;

			cout << endl;
			musicClips.setCurrentNode(iter);
		}
	}
}
