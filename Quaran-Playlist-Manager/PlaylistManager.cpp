#include "PlaylistManager.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include<vector>


PlaylistManager::PlaylistManager() {}

void PlaylistManager::newPlaylist(Playlist playlist) {
    playlists.append(playlist);
}

void PlaylistManager::addAudioToPlaylist(string playlistName, Audio audio) {
    Node<Playlist>* current = playlists.getHead();
    while (current != nullptr) {
        if (current->data.getName() == playlistName) {
            current->data.addAudioDirectly(audio);
            cout << "Audio has been added to playlist: " << playlistName << endl;
            return;
        }
        current = current->next;
    }

    cout << "Playlist with name :" << playlistName << "not found." << endl;
}

void PlaylistManager::removeAudioFromPlaylist(string playlistName, string audioName) {
    Node<Playlist>* current = playlists.getHead();
    while (current != nullptr) {
        if (current->data.getName() == playlistName) {
            bool success = current->data.removeAudioByName(audioName);
            if (success) {
                cout << "Audio :" << audioName << " has been removed from playlist: " << playlistName << endl;
            }
            else {
                cout << "Audio with name :" << audioName << "\" not found in playlist: " << playlistName << endl;
            }
            return;
        }
        current = current->next;
    }

    cout << "Playlist with name \"" << playlistName << "\" not found." << endl;
}

void PlaylistManager::reversePlaylists() {
    Node<Playlist>* current = playlists.getHead();
    Node<Playlist>* prev = nullptr;
    Node<Playlist>* next = nullptr;

    while (current != nullptr) {
        next = current->next;
        current->next = prev;
        current->prev = next;
        prev = current;
        current = next;
    }

    playlists.setHead(prev);
}

void PlaylistManager::displayPlaylistAudios(string playlistName) const {
    Node<Playlist>* current = playlists.getHead();
    while (current != nullptr) {
        if (current->data.getName() == playlistName) {
            cout << "Audios in playlist \"" << playlistName << "\":" << endl;
            current->data.displayAudios();
            return;
        }
        current = current->next;
    }

    cout << "Playlist with name \"" << playlistName << "\" not found." << endl;
}

void PlaylistManager::displayAudioDetailsInPlaylist(string playlistName, string audioName) const {
    Node<Playlist>* current = playlists.getHead();
    while (current != nullptr) {
        if (current->data.getName() == playlistName) {
            cout << "Displaying details for audio \"" << audioName << "\" in playlist \"" << playlistName << "\":" << endl;
            current->data.printAudiosDetails();
            return;
        }
        current = current->next;
    }

    cout << "Playlist with name \"" << playlistName << "\" not found." << endl;
}


void PlaylistManager::playAllAudiosFromPlaylist(const string& playlistName) {
    ISoundEngine* engine = createIrrKlangDevice();
    if (!engine) {
        std::cerr << "Error initializing IrrKlang!" << std::endl;
        return;
    }

    Node<Playlist>* current = playlists.getHead();
    Playlist* selectedPlaylist = nullptr;

    while (current != nullptr) {
        if (current->data.getName() == playlistName) {
            selectedPlaylist = &current->data;
            break;
        }
        current = current->next;
    }

    if (selectedPlaylist == nullptr) {
        cout << "Playlist not found." << endl;
        return;
    }

    vector<Audio*> audios = selectedPlaylist->getAudios();
    if (audios.empty()) {
        cout << "No audios in this playlist." << endl;
        return;
    }

    int currentIndex = 0;
    ISound* currentSound = engine->play2D(audios[currentIndex]->getPath().c_str(), false, true, true);
    if (!currentSound) {
        cout << "Failed to play audio!" << endl;
        return;
    }

    cout << "Press 'b' to start playing." << endl;

    while (true) {
        if (_kbhit()) {
            char ch = _getch();
            if (ch == 27) {
                system("cls");
                break;  
            }

            if (ch == 'b') {
                currentSound->setIsPaused(false);
                cout << "\r\033[K+-------------------------+" << endl;
                cout << "\r\033[K|  " << audios[currentIndex]->getName() << " \033[32m(Playing)\033[0m |" << endl;
                cout << "\r\033[K+-------------------------+" << endl;

                break;
            }
        }
    }

    while (true) {
        if (_kbhit()) {
            char ch = _getch();
            if (ch == 27) {
                system("cls");
                break;  
            }

            switch (ch) {
                // Left arrow key (Previous audio)
            case 75: 
                system("cls"); 
                if (currentIndex > 0) {
                    currentIndex--;
                    currentSound->stop();
                    currentSound = engine->play2D(audios[currentIndex]->getPath().c_str(), false, true, true);
                    cout << "\r\033[K" << audios[currentIndex]->getName() << " \033[32m(Playing)\033[0m" << endl; // Green text
                }
                break;
                // Right arrow key (Next audio)

            case 77:
                system("cls"); 
                if (currentIndex < audios.size() - 1) {
                    currentIndex++;
                    currentSound->stop();
                    currentSound = engine->play2D(audios[currentIndex]->getPath().c_str(), false, true, true);
                   
                   
                    cout << "\r\033[K+-------------------------+" << endl;
                    cout << "\r\033[K|  " << audios[currentIndex]->getName() << " \033[32m(Playing)\033[0m |" << endl;
                    cout << "\r\033[K--------------------------+" << endl;
                }
                break;

                // Up arrow key (Pause)

            case 72:
                system("cls");
                currentSound->setIsPaused(true);
               
                cout << "\r\033[K+-------------------------+" << endl;
                cout << "\r\033[K|" << audios[currentIndex]->getName() << " \033[31m(Paused)\033[0m |" << endl;
                cout << "\r\033[K+-------------------------+" << endl;
                break;

                // Down arrow key (Resume)

            case 80:  
                system("cls");
                currentSound->setIsPaused(false);
                
                cout << "\r\033[K+-------------------------+" << endl;
                cout << "\r\033[K|" << audios[currentIndex]->getName() << " \033[32m(Resumed)\033[0m |" << endl;
                cout << "\r\033[K+-------------------------+" << endl;
                break;

                // Stop the audio

            case 'q': 
                system("cls");
                currentSound->stop();
                cout << "\r\033[K+-------------------------+" << endl;
                cout << "\r\033[K|" << audios[currentIndex]->getName() << " \033[90m(Stopped)\033[0m |" << endl;
                cout << "\r\033[K+-------------------------+" << endl;
                break;
            default:
                break;
            }
        }
    }

    engine->drop();  
}


void PlaylistManager::displayPlaylists() const {
    Node<Playlist>* current = playlists.getHead();
    if (!current) {
        cout << "No playlists available." << endl;
        return;
    }

    while (current) {

        cout << "Playlist: " << current->data.getName() << endl;

        current->data.printAudiosDetails();

        cout << endl;
        current = current->next;
    }
}

void PlaylistManager::saveToFile(const string& fileName) {
    ofstream outFile(fileName);

    if (!outFile.is_open()) {
        cerr << "Error opening file for saving!" << endl;
        return;
    }

    Node<Playlist>* current = playlists.getHead();

    while (current != nullptr) {
        Playlist& playlist = current->data;

        outFile << "Playlist: " << playlist.getName() << endl;
        outFile << "----------------------------------" << endl;

        vector<Audio*> audios = playlist.getAudios();
        for (size_t i = 0; i < audios.size(); i++) {
            outFile << "Audio Name: " << audios[i]->getName() << endl;
            outFile << "Audio Path: " << audios[i]->getPath() << endl;
            outFile << "Audio Type: " << audios[i]->getType() << endl;
            outFile << "----------------------------------" << endl;
        }

        outFile << "==================================" << endl;
        current = current->next;
    }

    outFile.close();
    cout << "Playlists saved to file successfully!" << endl;
}

void PlaylistManager::loadFromFile(const string& fileName) {
    ifstream inFile(fileName);

    if (!inFile.is_open()) {
        cerr << "Error opening file for loading!" << endl;
        return;
    }

    string line;
    Playlist* currentPlaylist = nullptr;

    while (getline(inFile, line)) {
        if (line.find("Playlist:") == 0) {
            string playlistName = line.substr(10);
            Playlist newPlaylist(playlistName);
            playlists.append(newPlaylist); 
            currentPlaylist = &playlists.getTail()->data;
        }
        else if (line.find("Audio Name:") == 0 && currentPlaylist) {
            string audioName = line.substr(12);

            getline(inFile, line);
            string audioPath = line.substr(12);

            getline(inFile, line);
            string audioType = line.substr(12);

            Audio newAudio(audioName, audioPath, audioType);
            currentPlaylist->addAudioDirectly(newAudio);
        }
    }

    inFile.close();
    cout << "Playlists loaded from file successfully!" << endl;
}

void PlaylistManager::clearPlaylists(string name) {
    if (playlists.size() == 0) return;

    Node<Playlist>* current = playlists.getHead();
    int counter = -1;
    while (current != nullptr) {
        counter++;
        if (current->data.getName() == name) {
            current->data.clearPlaylist();
            break;
        }
        current = current->next;
    }
    playlists.removeAtIndex(counter);
    cout << "playlists deleted" << endl;
}



