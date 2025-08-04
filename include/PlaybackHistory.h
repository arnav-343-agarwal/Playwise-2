#ifndef PLAYBACK_HISTORY_H
#define PLAYBACK_HISTORY_H

#include "Song.h"
#include <stack>

class PlaybackHistory {
private:
    std::stack<Song> history;

public:
    void playSong(const Song& song);
    bool canUndo() const;
    Song undoLastPlay();
};

#endif
