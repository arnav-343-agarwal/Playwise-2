#include "PlaybackHistory.h"
#include <stdexcept>

void PlaybackHistory::playSong(const Song& song) {
    history.push(song);
}

bool PlaybackHistory::canUndo() const {
    return !history.empty();
}

Song PlaybackHistory::undoLastPlay() {
    if (history.empty())
        throw std::runtime_error("No song to undo.");
    Song last = history.top();
    history.pop();
    return last;
}
