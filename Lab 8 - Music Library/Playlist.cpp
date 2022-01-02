#include "Playlist.h"

#include <iostream>
#include <string>

Playlist::Playlist() {
	playlistName = "null";
}

Playlist::Playlist(std::string theName) {
	playlistName = theName;
}

std::string Playlist::GetPlaylistName() const {
	return playlistName;
}


void Playlist::ListAllPlaylistSongs() const {
	for (unsigned int i = 0; i < songsInPlaylist.size(); ++i) {
		std::cout << i << ": " << songsInPlaylist.at(i)->GetSongName() << std::endl;
	}
}

void Playlist::AddSong(Song* theSong) {
	songsInPlaylist.push_back(theSong);
}

void Playlist::PlayPlaylist() {
	for (unsigned int i = 0; i < songsInPlaylist.size(); ++i) {
		std::cout << songsInPlaylist.at(i)->GetSongLine() << std::endl;
		songsInPlaylist.at(i)->PlaySong();
	}
}

void Playlist::DeleteSong(int songNum) {
	songsInPlaylist.erase(songsInPlaylist.begin() + songNum);
}

void Playlist::CheckAndRemoveSong(std::string theSong) {
	for (unsigned int i = 0; i < songsInPlaylist.size(); ++i) {
		if (songsInPlaylist.at(i)->GetSongName() == theSong) {
			songsInPlaylist.erase(songsInPlaylist.begin() + i);
			break;
		}
	}
}