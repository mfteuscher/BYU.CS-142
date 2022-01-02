#pragma once

#include <string>
#include <vector>
#include "Song.h"

class Playlist {
public:
	Playlist();
	Playlist(std::string theName);
	std::string GetPlaylistName() const;
	void ListAllPlaylistSongs() const;
	void AddSong(Song* theSong);
	void PlayPlaylist();
	void DeleteSong(int songNum);
	void CheckAndRemoveSong(std::string theSong);
private:
	std::string playlistName;
	std::vector<Song*> songsInPlaylist;
};

