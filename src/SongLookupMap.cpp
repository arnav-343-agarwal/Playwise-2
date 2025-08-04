#include "SongLookupMap.h"

void SongLookupMap::addSong(const Song& song) {
    idMap[song.id] = song;
    titleMap[song.title] = song;
}

void SongLookupMap::deleteSong(const std::string& songId) {
    auto it = idMap.find(songId);
    if (it != idMap.end()) {
        titleMap.erase(it->second.title);
        idMap.erase(it);
    }
}

Song* SongLookupMap::getSongById(const std::string& songId) {
    auto it = idMap.find(songId);
    return it != idMap.end() ? &it->second : nullptr;
}

Song* SongLookupMap::getSongByTitle(const std::string& title) {
    auto it = titleMap.find(title);
    return it != titleMap.end() ? &it->second : nullptr;
}
