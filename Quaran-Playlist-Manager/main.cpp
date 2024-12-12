#include <iostream>
#include "PlaylistManager.h"


using namespace std;

void Menu() {
    cout << "+======================================================+" << endl;
    cout << "|                 Playlist Manager                     |" << endl;
    cout << "+======================================================+" << endl;
    cout << "| 1. Add a new playlist                                |" << endl;
    cout << "| 2. Add Audio to an existing playlist                 |" << endl;
    cout << "| 3. Remove Audio from an existing playlist            |" << endl;
    cout << "| 4. Reverse the existing playlist                     |" << endl;
    cout << "| 5. Display All Current Playlists                     |" << endl;
    cout << "| 6. Display all Playlist audios                       |" << endl;
    cout << "| 7. Display Audio details in a specific playlist      |" << endl;
    cout << "| 8. Play Audio from specific playlist                 |" << endl;
    cout << "| 9. Save an existing playlist to a file               |" << endl;
    cout << "| 10. Load an existing playlist from a file            |" << endl;
    cout << "| 11. Remove an existing playlist                      |" << endl;
    cout << "| 12. Exit                                             |" << endl;
    cout << "+======================================================+" << endl;
}

int main()
{

      bool running = true;
      int choice;
      PlaylistManager Project;

        while (running) {
            Menu();
            cout << "Enter Your Choice : ";
            cin >> choice;
            cout << endl;

            switch (choice) {

                // Add new Playlist
            case 1:
            {
                cout << "Enter the name of the new playlist: ";
                string playlistName;
                cin >> playlistName;
                Playlist newplaylist(playlistName);
                Project.newPlaylist(newplaylist);
                cout << "New playlist :" << playlistName << " has been added." << endl;
                system("cls");
                break;
            }

            // Add Audio to Playlist
            case 2:
            {
                cout << "Enter the name of the playlist you want to add audio to: ";
                string playlistNameForAudio;
                cin >> playlistNameForAudio;

                cout << "Enter the name of the audio: ";
                string audioName;
                cin >> audioName;

                cout << "Enter the path to the audio file: ";
                string audioPath;
                cin >> audioPath;

                cout << "Enter the Type of the audio: ";
                string audioType;
                cin >> audioType;

                Audio newAudio(audioName, audioPath, audioType);
                Project.addAudioToPlaylist(playlistNameForAudio, newAudio);
                system("cls");
                break;
            }

            // Remove Audio from playlist
            case 3:
            {
                cout << "Enter the name of the playlist: ";
                string playlistNameToRemoveAudio;
                cin >> playlistNameToRemoveAudio;

                cout << "Enter the name of the audio to remove: ";
                string audioNameToRemove;
                cin >> audioNameToRemove;

                Project.removeAudioFromPlaylist(playlistNameToRemoveAudio, audioNameToRemove);
                system("cls");
                break;
            }
            // Reverse Playlists order
            case 4:
            {
                Project.reversePlaylists();
                system("cls");
                cout << "Playlists have been reversed." << endl;
                break;

            }

            // display all playlists
            case 5:
            {
                Project.displayPlaylists();
                break;
            }

            // display all playlist Audios
            case 6:
            {
                cout << "Enter the name of the playlist: ";
                string playlistName;
                cin >> playlistName;

                Project.displayPlaylistAudios(playlistName);
                break;
            }



            case 7:
            {
                cout << "Enter the name of the playlist: ";
                string playlistName;
                cin >> playlistName;

                cout << "Enter the name of the audio: ";
                string audioName;
                cin >> audioName;

                Project.displayAudioDetailsInPlaylist(playlistName, audioName);
                break;
            }

            case 8: {
                system("cls");
                cout << "Enter playlist name: ";
                string s; cin >> s;
                Project.playAllAudiosFromPlaylist(s);
                break;
            }


            case 9:
                Project.saveToFile("playlists.txt");
                system("cls");
                break;

            case 10:
                Project.loadFromFile("playlists.txt");
                system("cls");
                break;

            case 11:
            { cout << "Enter playlist name: ";
                string name;
                cin >> name;
                Project.clearPlaylists(name);
                system("cls");
                break; 
            }
               

            case 12:
            {
                running = false;
                break;

            }

            default:
                cout << "Invalid choice, please try again." << endl;
                break;
            }


        }


}


