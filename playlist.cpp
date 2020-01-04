// Playlist class demonstrating partially filled arrays
// Can add/remove songs from playlist
// find songs in playlist

#include "playlist.h"
#include <iostream>

// constructor with default name
Playlist::Playlist(const string& name) {

}

// destructor
// nothing on heap
Playlist::~Playlist() {
    // destructor
}

// true if song found in playlist
bool Playlist::isInPlaylist(const string& song) const {
    return true;
}

// add a new song
// return true if successful, false if song already in playlist
bool Playlist::addSong(const string &song) {
    return false;
}

// remove a song
// return true if successfully removed, false if song not in playlist
bool Playlist::removeSong(const string &song) {
    return false;
}

// list all songs
void Playlist::listAllSongs() const {
}

// list shuffled songs with count
void Playlist::listShuffledSongs(unsigned int count) const {
}

ostream& operator<<(ostream& Out, const Playlist& playlist) {
    return Out;
}