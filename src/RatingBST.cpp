#include "RatingBST.h"

RatingBST::RatingBST() : root(nullptr) {}

RatingBST::~RatingBST() {
    destroy(root);
}

void RatingBST::destroy(Node* node) {
    if (!node) return;
    destroy(node->left);
    destroy(node->right);
    delete node;
}

RatingBST::Node* RatingBST::insert(Node* node, const Song& song, int rating) {
    if (!node)
        return new Node(rating);

    if (rating < node->rating)
        node->left = insert(node->left, song, rating);
    else if (rating > node->rating)
        node->right = insert(node->right, song, rating);
    else
        node->songs.push_back(song);

    return node;
}

void RatingBST::insertSong(const Song& song, int rating) {
    if (rating < 1 || rating > 5) return;
    root = insert(root, song, rating);
}

void RatingBST::search(Node* node, int rating, std::vector<Song>& result) const {
    if (!node) return;

    if (rating < node->rating)
        search(node->left, rating, result);
    else if (rating > node->rating)
        search(node->right, rating, result);
    else
        result = node->songs;
}

std::vector<Song> RatingBST::searchByRating(int rating) const {
    std::vector<Song> result;
    search(root, rating, result);
    return result;
}

RatingBST::Node* RatingBST::remove(Node* node, const std::string& songId) {
    if (!node) return nullptr;

    for (auto it = node->songs.begin(); it != node->songs.end(); ++it) {
        if (it->id == songId) {
            node->songs.erase(it);
            break;
        }
    }

    if (node->songs.empty()) {
        if (!node->left) {
            Node* right = node->right;
            delete node;
            return right;
        } else if (!node->right) {
            Node* left = node->left;
            delete node;
            return left;
        } else {
            Node* minNode = findMin(node->right);
            node->rating = minNode->rating;
            node->songs = minNode->songs;
            node->right = remove(node->right, minNode->songs[0].id);
        }
    }

    node->left = remove(node->left, songId);
    node->right = remove(node->right, songId);
    return node;
}

RatingBST::Node* RatingBST::findMin(Node* node) {
    while (node && node->left)
        node = node->left;
    return node;
}

void RatingBST::deleteSong(const std::string& songId) {
    root = remove(root, songId);
}

