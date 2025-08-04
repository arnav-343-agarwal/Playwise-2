#ifndef RATING_BST_H
#define RATING_BST_H

#include "Song.h"
#include <vector>
#include <string>

class RatingBST {
private:
    struct Node {
        int rating;
        std::vector<Song> songs;
        Node* left;
        Node* right;

        Node(int r) : rating(r), left(nullptr), right(nullptr) {}
    };

    Node* root;

    Node* insert(Node* node, const Song& song, int rating);
    Node* remove(Node* node, const std::string& songId);
    void search(Node* node, int rating, std::vector<Song>& result) const;
    Node* findMin(Node* node);
    void destroy(Node* node);

public:
    RatingBST();
    ~RatingBST();

    void insertSong(const Song& song, int rating);
    void deleteSong(const std::string& songId);
    std::vector<Song> searchByRating(int rating) const;
};

#endif
