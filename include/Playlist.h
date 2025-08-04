#ifndef PLAYLIST_H
#define PLAYLIST_H

#include "Song.h"
#include <iostream>
#include <functional>

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

    Node* getNodeAt(int index) const;  // Add 'const'

public:
    // int getSize() const;
    // Song getSongAt(int index) const;
    void clear();

    int getSize() const;
    Song getSongAt(int index) const;


    Playlist();
    ~Playlist();

    void addSong(const Song& song);
    void deleteSong(int index);
    void moveSong(int fromIndex, int toIndex);
    void reversePlaylist();
    void display() const;
    void sort(std::function<bool(const Song&, const Song&)> comparator);

    // Add these if you're using a sorting module
    void sortByTitle();
    void sortByDuration();
};

#endif
