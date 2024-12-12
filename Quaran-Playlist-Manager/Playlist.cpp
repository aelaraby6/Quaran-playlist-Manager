#include "Playlist.h"
#include <iostream>

using namespace std;

Playlist::Playlist() : name("abdelrahman") {}

Playlist::Playlist(const string& name) : name(name) {}

void Playlist::addAudioDirectly(const Audio& audio) {
    audios.append(audio);
}

void Playlist::addAudio() {
    string audioName, audioPath, audioType;
    cout << "Enter audio name: ";
    cin >> audioName;
    cout << "Enter audio path: ";
    cin >> audioPath;
    cout << "Enter audio type: ";
    cin >> audioType;

    Audio newAudio(audioName, audioPath, audioType);
    audios.append(newAudio);
    cout << "Audio added to playlist: " << name << endl;
}

void Playlist::deleteAudio(int index) {
    audios.removeAtIndex(index);
}

void Playlist::startPlaylist() const {
    Node<Audio>* current = audios.getHead();
    while (current) {
        cout << "Now playing: " << current->data.getName() << endl;
        current = current->next;
    }
}

bool Playlist::removeAudioByName(string audioName) {
    Node<Audio>* current = audios.getHead();
    while (current != nullptr) {
        if (current->data.getName() == audioName) {
            audios.remove(current);
            return true;
        }
        current = current->next;
    }
    return false;
}

string Playlist::getName() const {
    return name;
}

void Playlist::displayAudios() const {
    Node<Audio>* current = audios.getHead();
    if (current == nullptr) {
        cout << "No audios in this playlist." << endl;
        return;
    }

    while (current != nullptr) {
        cout << current->data.getName() << endl;
        current = current->next;
    }
}


void Playlist::printAudiosDetails() const {
    Node<Audio>* current = audios.getHead();
    while (current) {
        current->data.print();
        cout << endl;
        current = current->next;
    }
}
vector<Audio*>  Playlist::getAudios() {
    vector<Audio*> audioList;
    Node<Audio>* current = audios.getHead();
    while (current != nullptr) {
        audioList.push_back(&current->data);
        current = current->next;
    }
    return audioList;
}

void Playlist::clearPlaylist() {
    audios.clear();
}