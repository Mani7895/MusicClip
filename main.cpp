#include <iostream>
#include "Command.h"
#include <fstream>
#include <vector>
using namespace std;

char cmd = '0';
LinkedList musicClipList(10);

Command* commandFactory()
{
	if (cmd == 'l')
	{
		return new Listor(musicClipList);
	}
	else if (cmd == 'e')
	{
	    int id_change;
	    cout << "Enter the Index to be set to the Current Field: ";
	    cin >> id_change;
		return new Editor(id_change, musicClipList);
	}
	else if (cmd == 'c')
	{
		return new Creator(musicClipList);
	}
	else if(cmd == 'y')
    {
        return new Copying(musicClipList.getCurrentNode());
    }
    else if(cmd == 'i')
    {
        char array[20];
        short loop = 0;
        ifstream infile("input.inp");
        string sLine;
        int length{0};
        if(infile.is_open())
        {
            while(!infile.eof())
            {
                infile.get(array[loop]);
                loop++;
                length++;
            }
            infile.close();
        }
        for(int i{0}; i < length; i++)
        {
            cmd = array[i];
            cout << array[i];
            Command* command = commandFactory();
            if(command != NULL)
            {
                command ->execute();
            }
        }
    }
	else if (cmd == 'p')
	{
		return new PriceChanger(musicClipList.getCurrentNode());
	}
	else if (cmd == 's')
	{
		return new Saver(MusicClipPtr::loadedPointers);
	}
	else if(cmd == 'q')
    {
        cout << "Goodbye...." << endl;
    }
    else
    {
        cout << "Unknown selection, please try again" << endl << endl;
    }
	return NULL;
}

int main()
{
    do{
        cout << "l - List all music clips" << endl;
        cout << "e - Edit a MusicClip instance" << endl;
        cout << "c - Create a music clip" << endl;
        cout << "y - Copy the current clip" << endl;
        cout << "i - Read commands from file" << endl;
        cout << "p - Change price of current clip" << endl;
        cout << "s - Save all clips" << endl;
        cout << "q - Quit" << endl << endl;
        cout << "Enter your choice: ";
        cin >> cmd;

        Command* command = commandFactory();
        if(command != NULL)
        {
            command ->execute();
        }
    }while(cmd != 'q');
    return 0;
}
