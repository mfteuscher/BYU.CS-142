#include "Song.h"
#include <iostream>
#include <string>
#include <vector>

Song::Song(std::string theName, std::string theLine) {
	songName = theName;
	songLine = theLine;
	timesPlayed = 0;
}

std::string Song::GetSongName() const {
	return songName;
}

std::string Song::GetSongLine() const {
	return songLine;
}

int Song::GetTimesPlayed() const {
	return timesPlayed;
}

void Song::PlaySong() {
	++timesPlayed;
}