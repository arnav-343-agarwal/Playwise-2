#ifndef SORTMODULE_H
#define SORTMODULE_H

#include "Playlist.h"
#include <functional>

class SortModule {
public:
    static void sortByTitle(Playlist& playlist);
    static void sortByArtist(Playlist& playlist);
    static void sortByDuration(Playlist& playlist);
};

#endif
