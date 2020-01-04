#pragma once

#include <string>

// Only for class code, OK to use namespace
using namespace std;

// Playlist holds songs - can add, remove and list songs
class Playlist {
    // display all songs in playlist
    friend ostream& operator<<(ostream& Out, const Playlist& playlist);

public:
    // constructor with default name
    explicit Playlist(const string& playlistName);

    // destructor
    virtual ~Playlist();

    // add a new song
    // return true if successful, false if song already in playlist
    bool addSong(const string& songName);

    // remove a song
    // return true if successfully removed, false if song not in playlist
    bool removeSong(const string& songName);

    // list all songs
    void listAllSongs() const;

    // list songs in shuffled order until count number song have been output
    void listShuffledSongs(int count) const;

    // true if song found in playlist
    bool isInPlaylist(const string& songName) const;

private:

};
