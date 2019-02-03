#include <string>
#include <vector>
#include <stdint.h>

using namespace std;
enum GenreType{
    POP_MUSIC,
    FOLK_MUSIC,
    JAZZ,
    BLUES,
    CLASSICAL,
    OPERA,
    COUNTRY_MUSIC,
    REGGAE,
    ROCK,
    OTHER
};

class MusicClip
{
private:
    int id;
    int index;
    string artist;
    GenreType type;
    vector<string> people;
    string title;
    vector<uint8_t> clip;
    float price;

public:
    MusicClip();
    MusicClip(const MusicClip&);
    MusicClip(int, int, string, GenreType, vector<string>, string, vector<uint8_t>, float);
    int getID();
    void setID(int);
    int getIndex();
    void setIndex(int);
    string getArtist();
    void setArtist(string);
    GenreType getType();
    void setType(GenreType);
    vector<string> getPeople();
    void setPeople(vector<string>);
    string getTitle();
    void setTitle(string);
    vector<uint8_t> getClip();
    float getPrice();
    void setPrice(float);
};
