#include "SearchModule.h"
#include <algorithm>

std::vector<Song> SearchModule::searchByTitle(const Playlist& playlist, const std::string& titlePart) {
    std::vector<Song> matches;
    for (int i = 0; i < playlist.getSize(); ++i) {
        Song song = playlist.getSongAt(i);
        if (song.title.find(titlePart) != std::string::npos) {
            matches.push_back(song);
        }
    }
    return matches;
}

std::vector<Song> SearchModule::searchByArtist(const Playlist& playlist, const std::string& artistPart) {
    std::vector<Song> matches;
    for (int i = 0; i < playlist.getSize(); ++i) {
        Song song = playlist.getSongAt(i);
        if (song.artist.find(artistPart) != std::string::npos) {
            matches.push_back(song);
        }
    }
    return matches;
}
