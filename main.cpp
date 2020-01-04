#include "playlist.h"
#include <cassert>
#include <iostream>

using namespace std;

void test1() {
    Playlist playlist("Deep Focus");
    playlist.addSong("Under The Wind");
    playlist.addSong("Safe And Sound");
    playlist.addSong("alpha waves");
    playlist.addSong("Dawning");
    playlist.listAllSongs();
    playlist.listShuffledSongs(10);

    // should generate already in playlist message and return true
    bool result = playlist.isInPlaylist("Dawning");
    assert(result);

    // cannot add book twice, result should be false
    result = playlist.addSong("Dawning");
    assert(!result);

    // test remove, result should be true
    result = playlist.removeSong("Dawning");
    assert(result);

    // not in library, result should be false
    result = playlist.isInPlaylist("Dawning");
    assert(!result);

    // cannot remove twice, result should be false
    result = playlist.removeSong("Dawning");
    assert(!result);
}

void testAll() {
    test1();
    cout << "Successfully completed all tests." << endl;
}

int main() {
    testAll();
    return 0;
}