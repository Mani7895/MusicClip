#include "Command.h"
#include <iostream>

Editor::Editor(int newID, LinkedList& newList)
	:id(newID), musicClips(newList)
{
}

void Editor::execute()
{
	for (Iterator iter = musicClips.begin(); iter != musicClips.end(); iter++)
	{
		if (iter->getData()->getID() == id)
		{

			musicClips.setCurrentNode(iter);

			cout << "# Current music clip was set to " << id << endl;

			break;
		}

	}
}


