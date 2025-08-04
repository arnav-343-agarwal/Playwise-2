#include "Playlist.h"
#include "SortModule.h"
#include <vector>
#include <algorithm> // for std::sort
#include <functional>

Playlist::Playlist() : head(nullptr), tail(nullptr), size(0) {}

Playlist::~Playlist() {
    Node* current = head;
    while (current) {
        Node* next = current->next;
        delete current;
        current = next;
    }
}

void Playlist::addSong(const Song& song) {
    // ✅ Prevent adding if artist is blocked
    if (isBlocked(song.artist)) {
        std::cout << "Cannot add \"" << song.title << "\" by " << song.artist << " (artist is blocked).\n";
        return;
    }

    Node* newNode = new Node(song);
    if (!head) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
    size++;
}

// ✅ Blocklist methods

void Playlist::blockArtist(const std::string& artistName) {
    blockedArtists.insert(artistName);
    std::cout << "Artist \"" << artistName << "\" has been blocked.\n";
}

void Playlist::unblockArtist(const std::string& artistName) {
    blockedArtists.erase(artistName);
    std::cout << "Artist \"" << artistName << "\" has been unblocked.\n";
}

bool Playlist::isBlocked(const std::string& artistName) const {
    return blockedArtists.find(artistName) != blockedArtists.end();
}


void Playlist::deleteSong(int index) {
    if (index < 0 || index >= size) return;
    Node* node = getNodeAt(index);
    if (!node) return;

    if (node->prev) node->prev->next = node->next;
    else head = node->next;

    if (node->next) node->next->prev = node->prev;
    else tail = node->prev;

    delete node;
    size--;
}

void Playlist::moveSong(int fromIndex, int toIndex) {
    if (fromIndex == toIndex || fromIndex < 0 || fromIndex >= size || toIndex < 0 || toIndex >= size)
        return;

    Node* node = getNodeAt(fromIndex);
    if (!node) return;

    if (node->prev) node->prev->next = node->next;
    else head = node->next;

    if (node->next) node->next->prev = node->prev;
    else tail = node->prev;

    Node* target = getNodeAt(toIndex);
    if (toIndex < fromIndex) {
        node->prev = target->prev;
        node->next = target;
        if (target->prev) target->prev->next = node;
        else head = node;
        target->prev = node;
    } else {
        node->next = target->next;
        node->prev = target;
        if (target->next) target->next->prev = node;
        else tail = node;
        target->next = node;
    }
}

void Playlist::reversePlaylist() {
    Node* curr = head;
    Node* temp = nullptr;
    while (curr) {
        temp = curr->prev;
        curr->prev = curr->next;
        curr->next = temp;
        curr = curr->prev;
    }
    if (temp) head = temp->prev;
}

void Playlist::display() const {
    Node* current = head;
    int index = 0;
    while (current) {
        std::cout << index++ << ". " << current->song.title << " by " << current->song.artist
                  << " (" << current->song.duration << "s)\n";
        current = current->next;
    }
}

Playlist::Node* Playlist::getNodeAt(int index) const {
    Playlist::Node* current = head;
    for (int i = 0; i < index && current != nullptr; ++i) {
        current = current->next;
    }
    return current;
}



void Playlist::sortByTitle() {
    SortModule::sortByTitle(*this);
}

void Playlist::sortByDuration() {
    SortModule::sortByDuration(*this);
}

int Playlist::getSize() const {
    return size;
}

Song Playlist::getSongAt(int index) const {
    Node* node = getNodeAt(index);
    if (node) return node->song;
    return Song();  // default empty Song
}

void Playlist::sort(std::function<bool(const Song&, const Song&)> comparator) {
    if (!head || !head->next) return;

    // Step 1: Copy songs into a vector
    std::vector<Song> songs;
    Node* current = head;
    while (current) {
        songs.push_back(current->song);
        current = current->next;
    }

    // Step 2: Sort the vector using the comparator
    std::sort(songs.begin(), songs.end(), comparator);

    // Step 3: Write sorted songs back to the playlist
    current = head;
    for (const auto& song : songs) {
        current->song = song;
        current = current->next;
    }
}

