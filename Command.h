#include "LinkedList.h"

class Command
{
public:
    virtual void execute() = 0;
};

class Creator : public Command
{
private:
	Memory memory;
	int id;
    int index;
    string artist;
    GenreType type;
    vector<string> people;
    string title;
    vector<uint8_t> clip;
    float price;
    LinkedList& musicClips;

	void getID();
	void getIndex();
	void getArtist();
	void getType();
	void getPeople();
	void getTitle();
	void getClip();
	void getPrice();
	void musicClipPrompt();
	void saveToPointer(MusicClip&);
public:
	Creator(LinkedList&);
	void execute();
};

class Editor : public Command
{
private:
    int id;
	LinkedList& musicClips;
public:
	Editor(int, LinkedList&);
	void execute();
};

class Listor : public Command
{
private:
	LinkedList& musicClips;
public:
	Listor(LinkedList&);
	void execute();
};

class Copying : public Command
{
private:
    Iterator& currentMusicClip;
public:
	Copying(Iterator&);
	void execute();
};

class PriceChanger : public Command
{
private:
	Iterator& currentMusicClip;
	float newPrice;

	void promptPrice();
public:
	PriceChanger(Iterator&);
	void execute();
};

class Saver : public Command
{
private:
	Memory memory;
	queue<MusicClipPtr*> loadedPointers;
	void saveFilesInMemory();
public:
	Saver(queue<MusicClipPtr*>);
	void execute();
};

