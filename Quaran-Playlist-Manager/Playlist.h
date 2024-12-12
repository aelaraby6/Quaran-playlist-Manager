#ifndef PLAYLIST_H
#define PLAYLIST_H

#include "Audio.h"
#include "DoubleLinkedList.h"
#include <string>
#include <iostream>
#include<vector>

using namespace std;

class Playlist {
private:
    string name;
    DoubleLinkedList<Audio> audios;

public:
    Playlist();
    Playlist(const string& name);

    void addAudioDirectly(const Audio& audio);
    void addAudio();
    void deleteAudio(int);
    void startPlaylist() const;
    void printAudiosDetails() const;
    bool removeAudioByName(string audioName);
    void displayAudios() const;
    vector<Audio*> getAudios();
    string getName() const;
    void clearPlaylist();

};

#endif
