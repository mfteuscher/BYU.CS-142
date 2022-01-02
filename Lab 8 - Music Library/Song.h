#pragma once

#include <string>
#include <vector>

class Song {
public:
	Song();
	Song(std::string theName, std::string theLine);
	std::string GetSongName() const;
	std::string GetSongLine() const;
	int GetTimesPlayed() const;
	void PlaySong();
private:
	std::string songName;
	std::string songLine;
	int timesPlayed;

};

