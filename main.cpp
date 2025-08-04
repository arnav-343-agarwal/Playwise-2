#include "Playlist.h"
#include "PlaybackHistory.h"
#include "RatingBST.h"
#include "SongLookupMap.h"
#include <iostream>


int main() {
    Playlist playlist;
    PlaybackHistory history;
    RatingBST ratingTree;
    SongLookupMap lookup;

    Song s1("1", "Shape of You", "Ed Sheeran", 240);
    Song s2("2", "Blinding Lights", "The Weeknd", 200);
    Song s3("3", "Levitating", "Dua Lipa", 220);
    Song s4("4", "Mere naina", "Lata mangeshkar", 250);

    playlist.addSong(s1);
    playlist.addSong(s2);
    playlist.addSong(s3);
    playlist.addSong(s4);

    lookup.addSong(s1);
    lookup.addSong(s2);
    lookup.addSong(s3);
    lookup.addSong(s4);


    std::cout << "\nLooking up song by ID '2':\n";
    Song* foundById = lookup.getSongById("2");
    if (foundById) {
        std::cout << foundById->title << " by " << foundById->artist << "\n";
    }

    std::cout << "\nLooking up song by title 'Levitating':\n";
    Song* foundByTitle = lookup.getSongByTitle("Levitating");
    if (foundByTitle) {
        std::cout << foundByTitle->title << " by " << foundByTitle->artist << "\n";
    }

    std::cout << "\nDeleting 'Blinding Lights' from lookup...\n";
    lookup.deleteSong("2");

    if (!lookup.getSongById("2")) {
        std::cout << "Song with ID '2' not found.\n";
    }

        std::cout << "\nAll songs in playlist:\n";
    for (int i = 0; i < playlist.getSize(); ++i) {
        Song song = playlist.getSongAt(i);
        std::cout << song.id << ": " << song.title << " by " << song.artist << " (" << song.duration << "s)\n";
    }






    std::cout << "\nDeleting song at index 1 (Blinding Lights)...\n";
    playlist.deleteSong(1);

    std::cout << "Playlist after removal:\n";
    for (int i = 0; i < playlist.getSize(); ++i) {
        Song song = playlist.getSongAt(i);
        std::cout << song.id << ": " << song.title << " by " << song.artist << "\n";
    }

        


    std::cout << "\nTesting playback history:\n";

    // Simulate playing songs
    history.playSong(s1);
    history.playSong(s2);
    history.playSong(s3);

    std::cout << "3 songs played.\n";

    // Undo last played song
    if (history.canUndo()) {
        Song undone = history.undoLastPlay();
        std::cout << "Undo last play: " << undone.title << " by " << undone.artist << "\n";
    }

    // Undo again
    if (history.canUndo()) {
        Song undone = history.undoLastPlay();
        std::cout << "Undo last play: " << undone.title << " by " << undone.artist << "\n";
    }

    // Try undoing again
    if (history.canUndo()) {
        Song undone = history.undoLastPlay();
        std::cout << "Undo last play: " << undone.title << " by " << undone.artist << "\n";
    }

    // Try undoing when stack is empty
    if (!history.canUndo()) {
        std::cout << "No more songs to undo.\n";
    }




    std::cout << "\nSorting playlist by title:\n";
    playlist.sortByTitle();
    for (int i = 0; i < playlist.getSize(); ++i) {
        Song song = playlist.getSongAt(i);
        std::cout << song.title << " by " << song.artist << "\n";
    }

    std::cout << "\nSorting playlist by duration:\n";
    playlist.sortByDuration();
    for (int i = 0; i < playlist.getSize(); ++i) {
        Song song = playlist.getSongAt(i);
        std::cout << song.title << " - " << song.duration << "s\n";
    }


        std::cout << "\nBlocking artist 'Dua Lipa'...\n";
        playlist.blockArtist("Dua Lipa");

        std::cout << "Trying to add song by Dua Lipa again:\n";
        playlist.addSong(Song("5", "New Rules", "Dua Lipa", 230));  // Should be blocked

        std::cout << "Trying to add song by Lata mangeshkar:\n";
        playlist.addSong(Song("6", "Tere Bina Zindagi", "Lata mangeshkar", 270));  // Should be added

        std::cout << "\nUpdated playlist after blocking:\n";
        playlist.display();


    return 0;
}
