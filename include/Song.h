#ifndef SONG_H
#define SONG_H

#include <string>

struct Song {
    std::string id;
    std::string title;
    std::string artist;
    int duration;

    Song() : id(""), title(""), artist(""), duration(0) {}  // default constructor

    Song(std::string id, std::string title, std::string artist, int duration)
        : id(std::move(id)), title(std::move(title)), artist(std::move(artist)), duration(duration) {}
};

#endif
