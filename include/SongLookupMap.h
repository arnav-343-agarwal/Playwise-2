#ifndef SONG_LOOKUP_MAP_H
#define SONG_LOOKUP_MAP_H

#include "Song.h"
#include <unordered_map>
#include <string>

class SongLookupMap {
private:
    std::unordered_map<std::string, Song> idMap;
    std::unordered_map<std::string, Song> titleMap;

public:
    void addSong(const Song& song);
    void deleteSong(const std::string& songId);
    Song* getSongById(const std::string& songId);
    Song* getSongByTitle(const std::string& title);
};

#endif
