#ifndef PLAYLIST_H
#define PLAYLIST_H

#include "Song.h"
#include <iostream>
#include <functional>
#include <unordered_set>  // ✅ for blocklist

class Playlist {
private:
    struct Node {
        Song song;
        Node* prev;
        Node* next;
        Node(const Song& s) : song(s), prev(nullptr), next(nullptr) {}
    };

    Node* head;
    Node* tail;
    int size;

    Node* getNodeAt(int index) const;

    // ✅ Blocklist
    std::unordered_set<std::string> blockedArtists;

public:
    Playlist();
    ~Playlist();

    void addSong(const Song& song);
    void deleteSong(int index);
    void moveSong(int fromIndex, int toIndex);
    void reversePlaylist();
    void display() const;
    void clear();

    int getSize() const;
    Song getSongAt(int index) const;

    void sort(std::function<bool(const Song&, const Song&)> comparator);
    void sortByTitle();
    void sortByDuration();

    // ✅ Blocklist functions
    void blockArtist(const std::string& artistName);
    void unblockArtist(const std::string& artistName);
    bool isBlocked(const std::string& artistName) const;
};

#endif
