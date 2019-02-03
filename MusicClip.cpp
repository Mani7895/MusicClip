#include "MusicClip.h"

MusicClip::MusicClip()
:id(0), index(-1), artist("N/A"), type(OTHER), title("N/A"), price(-1.0)
{
}

MusicClip::MusicClip(int newID, int newIndex, string newArtist, GenreType newType, vector<string> newPeople, string newTitle, vector<uint8_t> newClip, float newPrice)
:id(newID), index(newIndex), artist(newArtist), type(newType), people(newPeople), title(newTitle), clip(newClip), price(newPrice)
{
}

MusicClip::MusicClip(const MusicClip& newMusicClip)
:id(newMusicClip.id), index(newMusicClip.index), artist(newMusicClip.artist), type(newMusicClip.type), people(newMusicClip.people), title(newMusicClip.title), clip(newMusicClip.clip), price(newMusicClip.price)
{
}

int MusicClip::getID()
{
    return id;
}
void MusicClip::setID(int id)
{
    this -> id;
}
int MusicClip::getIndex()
{
    return index;
}
void MusicClip::setIndex(int index)
{
    this -> index;
}
string MusicClip::getArtist()
{
    return artist;
}
void MusicClip::setArtist(string artist)
{
    this -> artist = artist;
}
GenreType MusicClip::getType()
{
    return type;
}
void MusicClip::setType(GenreType)
{
    this -> type = type;
}
vector<string> MusicClip::getPeople()
{
    return people;
}
void MusicClip::setPeople(vector<string>)
{
    this -> people = people;
}
string MusicClip::getTitle()
{
    return title;
}
void MusicClip::setTitle(string)
{
    this -> title = title;
}
vector<uint8_t> MusicClip::getClip()
{
    return clip;
}
float MusicClip::getPrice()
{
    return price;
}
void MusicClip::setPrice(float price)
{
    this -> price = price;
}

