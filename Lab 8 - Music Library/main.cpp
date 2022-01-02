#include <iostream>
#include <string>
#include <vector>
#include "Playlist.h"
#include "Song.h"
using namespace std;


void ShowOptions() {
	cout << "add      Adds a list of songs to the library" << endl;
	cout << "list     Lists all the songs in the library" << endl;
	cout << "addp     Adds a new playlist" << endl;
	cout << "addsp    Adds a song to a playlist" << endl;
	cout << "listp    Lists all the playlists" << endl;
	cout << "play     Plays a playlist" << endl;
	cout << "remp     Removes a playlist" << endl;
	cout << "remsp    Removes a song from a playlist" << endl;
	cout << "remsl    Removes a song from the library (and all playlists)" << endl;
	cout << "options  Prints this options menu" << endl;
	cout << "quit     Quits the program" << endl;
}


void ListAllPlaylists(vector<Playlist> thePlaylists) {
	for (unsigned int i = 0; i < thePlaylists.size(); ++i) {
		cout << i << ": " << thePlaylists.at(i).GetPlaylistName() << endl;
	}
}

void ListAllSongs(vector<Song*> theSongs) {
	for (unsigned int i = 0; i < theSongs.size(); ++i) {
		cout << i << ": " << theSongs.at(i)->GetSongName() << endl;
	}
}



int main() {
	vector<Song*> theSongs;
	vector<Playlist> thePlaylists;
	string optionSelect;
	int pIndexSelect;
	int sIndexSelect;
	string songName;
	string songLine;
	string playlistName;

	cout << "Welcome to the Firstline Player!  Enter options to see menu options." << endl << endl;

	cout << "Enter your selection now: ";
	cin >> optionSelect;
	cin.ignore();


	do {
		if (optionSelect == "add") {
			cout << "Read in Song names and first lines (type \"STOP\" when done):" << endl;
			do {
				cout << "Song Name: ";
				getline(cin, songName);
				if (songName == "STOP") {
					break;
				}
				cout << "Song's first line: ";
				getline(cin, songLine);
				theSongs.push_back(new Song(songName, songLine));
			} while (songName != "STOP");
		}
		else if (optionSelect == "list") {
			for (unsigned int i = 0; i < theSongs.size(); ++i) {
				cout << theSongs.at(i)->GetSongName() << ": \"" << theSongs.at(i)->GetSongLine() << "\", " << theSongs.at(i)->GetTimesPlayed() << " play(s)." << endl;
			}
		}
		else if (optionSelect == "addp") {
			cout << "Playlist name: ";
			getline(cin, playlistName);
			thePlaylists.push_back(Playlist(playlistName));
		}
		else if (optionSelect == "addsp") {
			ListAllPlaylists(thePlaylists);
			cout << "Pick a playlist index number: ";
			cin >> pIndexSelect;
			cin.ignore();
			ListAllSongs(theSongs);
			cout << "Pick a song index number: ";
			cin >> sIndexSelect;
			cin.ignore();
			thePlaylists.at(pIndexSelect).AddSong(theSongs.at(sIndexSelect));
		}
		else if (optionSelect == "listp") {
			ListAllPlaylists(thePlaylists);
		}
		else if (optionSelect == "play") {
			ListAllPlaylists(thePlaylists);
			cout << "Pick a playlist index number: ";
			cin >> pIndexSelect;
			cin.ignore();
			cout << endl << endl << "Playing first lines of playlist: " << thePlaylists.at(pIndexSelect).GetPlaylistName() << endl;
			thePlaylists.at(pIndexSelect).PlayPlaylist();
		}
		else if (optionSelect == "remp") {
			ListAllPlaylists(thePlaylists);
			cout << "Pick a playlist index number to remove: ";
			cin >> pIndexSelect;
			cin.ignore();
			thePlaylists.erase(thePlaylists.begin() + pIndexSelect);
		}
		else if (optionSelect == "remsp") {
			ListAllPlaylists(thePlaylists);
			cout << "Pick a playlist index number: ";
			cin >> pIndexSelect;
			cin.ignore();
			thePlaylists.at(pIndexSelect).ListAllPlaylistSongs();
			cout << "Pick a song index number to remove: ";
			cin >> sIndexSelect;
			cin.ignore();
			thePlaylists.at(pIndexSelect).DeleteSong(sIndexSelect);
		}
		else if (optionSelect == "remsl") {
			ListAllSongs(theSongs);
			cout << "Pick a song index number to remove: ";
			cin >> sIndexSelect;
			cin.ignore();
			for (unsigned int i = 0; i < thePlaylists.size(); ++i) {
				thePlaylists.at(i).CheckAndRemoveSong(theSongs.at(sIndexSelect)->GetSongName());
			}
			delete theSongs.at(sIndexSelect);
			theSongs.erase(theSongs.begin() + sIndexSelect);
		}
		else if (optionSelect == "options") {
			ShowOptions();
		}
		else {
			ShowOptions();
		}

		cout << "Enter your selection now: ";
		cin >> optionSelect;
		cin.ignore();


	} while (optionSelect != "quit");


	for (unsigned int i = 0; i < theSongs.size(); ++i) {       //This is the code to clear the memory
		delete theSongs.at(i);
	}
	theSongs.clear();

	cout << "Goodbye!" << endl;

	return 0;
}