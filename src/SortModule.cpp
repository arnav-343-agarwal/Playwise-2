#include "SortModule.h"
#include <vector>
#include <algorithm>

void SortModule::sortByTitle(Playlist& playlist) {
    playlist.sort([](const Song& a, const Song& b) {
        return a.title < b.title;
    });
}

void SortModule::sortByArtist(Playlist& playlist) {
    playlist.sort([](const Song& a, const Song& b) {
        return a.artist < b.artist;
    });
}

void SortModule::sortByDuration(Playlist& playlist) {
    playlist.sort([](const Song& a, const Song& b) {
        return a.duration < b.duration;
    });
}
