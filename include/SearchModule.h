#ifndef SEARCHMODULE_H
#define SEARCHMODULE_H

#include "Playlist.h"
#include <string>
#include <vector>

class SearchModule {
public:
    static std::vector<Song> searchByTitle(const Playlist& playlist, const std::string& titlePart);
    static std::vector<Song> searchByArtist(const Playlist& playlist, const std::string& artistPart);
};

#endif
