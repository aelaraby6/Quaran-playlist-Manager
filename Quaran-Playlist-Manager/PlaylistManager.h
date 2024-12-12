#ifndef PLAYLISTMANAGER_H
#define PLAYLISTMANAGER_H

#include <string>
#include <irrKlang.h>
#include <conio.h> 
#include "Playlist.h"
#include "DoubleLinkedList.h"

using namespace std;
using namespace irrklang;

class PlaylistManager {
private:
    DoubleLinkedList<Playlist> playlists;

public:
    PlaylistManager();
    void newPlaylist(Playlist playlist);
    void addAudioToPlaylist(string playlistName, Audio audio);
    void removeAudioFromPlaylist(string playlistName, string audioName);
    void reversePlaylists();
    void displayPlaylistAudios(string playlistName) const;
    void displayAudioDetailsInPlaylist(string playlistName, string audioName) const;
    void playAllAudiosFromPlaylist(const string& playlistName);
    void displayPlaylists() const;
    void saveToFile(const string& fileName);
    void loadFromFile(const string& fileName);
    void clearPlaylists(string);

};

#endif
