#include "Memory.h"
#include <queue>

class MusicClipPtr
{
    private:
        static const int maxMusicClipLoaded = 3;
		static int numPtrs;
		int id;
        MusicClip* musicClip;
        Memory memory;
    protected:
        MusicClipPtr(const MusicClipPtr& musicClipPtr);
        MusicClipPtr& operator = (const MusicClipPtr& musicClipPtr);
    public:
		static queue<MusicClipPtr*> loadedPointers;

        MusicClipPtr();
        ~MusicClipPtr();
        MusicClip* operator->();
        MusicClip& operator*();
		int getID();
};
