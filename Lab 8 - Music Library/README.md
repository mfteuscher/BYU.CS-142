# Lab 8 - Music Library

## Synopsis

This programs creates a music library that has songs in it. The library also contains playlists, which are a collection
of songs. The program can list out the songs in the library, and in a playlist. It can list out all the playlists, and
then "play" playlists. You can also delete songs and playlists. This lab is to understand pointers, so you don't have to
create tons of copies, which is space inefficient.

### Background

I have a music player on my phone. I can buy songs, add them to playlists and play them. Obviously it would be redundant
to store each song in each playlist; each playlist is just a list of pointers to the songs.

For this lab you will simulate this behavior. Your program will need to have options to:

* Add songs to the system library (you will store the text of the first line of the song, rather than the audio)
* Add playlists
* Add songs to a playlist
* List playlists
* Play a playlist
* List all of the songs in the library with a count of how many times each song has been played
* Remove a song from a playlist
* Remove a playlist
* Remove a song from the library (and thus from all playlists that contain it)

Note that we will not be checking many error cases. In real programming this would be bad, you should usually try to
recognize and respond to as many types of errors as you can. In the context of class we are trying to acquaint you with
as many concepts as possible, so for the sake of educational efficiency we will not be checking most errors in this lab,
you may assume that your user provides correct input. You may add all appropriate error testing if you wish, but we will
not be testing for it.

### Part 1 - The Menu

Prompt the user to select one of several operations:
<pre>
add      Adds a list of songs to the library
list     Lists all the songs in the library
addp     Adds a new playlist
addsp    Adds a song to a playlist
listp    Lists all the playlists
play     Plays a playlist
remp     Removes a playlist
remsp    Removes a song from a playlist
remsl    Removes a song from the library (and all playlists)
options  Prints this options menu
quit     Quits the program
</pre>

After any operation is complete (except for quitting), re-prompt the user to select another operation. If the user
enters an unknown option, just print the menu. For part 1, only the quit and options option need work.

### Part 2 - Add and display songs

* For this part you will need to create a song class. You will also need to create a vector of pointers to songs in your
  main file - this will be your library of songs.
    * As songs are added use "new".
    * At the end of your program free the space for each song using "delete".
* Add songs
    * Prompt the user for the name of the song (you do not need to check for duplicate names).
    * Prompt the user for the first line of the song.
    * Initialize the count of how many times this song has been played to 0.
    * Continue to prompt for songs until the user responds with "STOP".
* List all songs - display a list of all of the songs currently in the system and the number of times each song has been
  played.

### Part 3 - Playlists

* For this part you will need to create a playlist class and a vector of playlists.
* Add a playlist
    * Prompt the user for the name of the playlist (you do not need to check for duplicate names).
    * Add the new playlist to the vector of playlists.
* List a playlist
* Add a song to a playlist
    * List all of the playlists currently in the system and let the user select one of them.
    * List all of the songs currently in the system and let the user select one of them.
    * Add a pointer to the selected song into the selected playlist.
* Play playlist
    * List all of the playlist names and let the user select one of them.
    * "Play" the songs in the play list by printing their first lines.
    * Whenever a song is played from any playlist, add to the count of how many times it has been played. Note that this
      is the number of times it has been played, not the number of playlists it is on.
    * Verify that when you use the "list all songs" operation that the correct count is displayed.

### Part 4 - Remove songs and playlists

* Remove a playlist
* Remove a song from a playlist
    * Note that this does not remove the song from the library
* Remove a song from the library. Think about this one!
    * You will need to first remove the song from any playlist which contains it
    * You must free the memory that the song object was allocated to (c++ delete)
    * Then erase it from the library
* When the user hits quit, free memory for all songs in the library that were created.

### Notes

* You must create and use a Song class and a Playlist class.
* You must create and use a vector of Song pointers as the music library.
* Your Playlist class must contain and use a vector Song pointers.
* Each class must be created and submitted in separate cpp and header files.
    * All class member functions should be declared in the header file and defined in the cpp. In common practice, there
      may be some exceptions to this, but to keep grading simpler we require you to not define any functions in the
      header file.
* Create your own default constructor for each class. You may fulfill this default constructor requirement and support a
  parameterized constructor by creating multiple constructors, or one constructor with default parameters.
* You must use new to create your songs and free memory (delete) for any song which you remove from the library. Delete
  all songs before your code terminates. If you use pointers for playlists you must also free memory (delete) when
  playlists are removed and before your code terminates. To help the TAs, place a comment about freeing memory next to
  the lines in your code which free memory, and in the Canvas submission quiz give the file and line numbers of those
  lines.

#### Sample Input

<pre>
options
add
Paradise
When she was just a girl
Come come ye saints
Come come ye saints, no toil nor labor fear
Yellow
Look at the stars
Superheroes
All her life she has seen
When he comes again
I wonder when he comes again, will herald angels sing
Time
Ticking away the moments that make up a dull day
STOP
list
addp
Coding Music
addp
Sunday Favorites
addp
Game Day
listp
addsp
0
2
addsp
0
1
addsp
0
3
addsp
1
1
addsp
1
4
play
0
play
1
list
remp
2
listp
remsp
0
0
play
0
remsl
1
play
0
play
1
list
quit
</pre>

### Sample Output

<pre>
Welcome to the Firstline Player!  Enter options to see menu options.

Enter your selection now: options

add      Adds a list of songs to the library
list     Lists all the songs in the library
addp     Adds a new playlist
addsp    Adds a song to a playlist
listp    Lists all the playlists
play     Plays a playlist
remp     Removes a playlist
remsp    Removes a song from a playlist
remsl    Removes a song from the library (and all playlists)
options  Prints this options menu
quit     Quits the program

Enter your selection now: add
Read in Song names and first lines (type "STOP" when done):
Song Name: Paradise
Song's first line: When she was just a girl
Song Name: Come come ye saints
Song's first line: Come come ye saints, no toil nor labor fear
Song Name: Yellow
Song's first line: Look at the stars
Song Name: Superheroes
Song's first line: All her life she has seen
Song Name: When he comes again
Song's first line: I wonder when he comes again, will herald angels sing
Song Name: Time
Song's first line: Ticking away the moments that make up a dull day
Song Name: STOP

Enter your selection now: list
Paradise: "When she was just a girl", 0 play(s).
Come come ye saints: "Come come ye saints, no toil nor labor fear", 0 play(s).
Yellow: "Look at the stars", 0 play(s).
Superheroes: "All her life she has seen", 0 play(s).
When he comes again: "I wonder when he comes again, will herald angels sing", 0 play(s).
Time: "Ticking away the moments that make up a dull day", 0 play(s).

Enter your selection now: addp
Playlist name: Coding Music

Enter your selection now: addp
Playlist name: Sunday Favorites

Enter your selection now: addp
Playlist name: Game Day

Enter your selection now: listp
0: Coding Music
1: Sunday Favorites
2: Game Day

Enter your selection now: addsp
0: Coding Music
1: Sunday Favorites
2: Game Day
Pick a playlist index number: 0
0: Paradise
1: Come come ye saints
2: Yellow
3: Superheroes
4: When he comes again
5: Time
Pick a song index number: 2

Enter your selection now: addsp
0: Coding Music
1: Sunday Favorites
2: Game Day
Pick a playlist index number: 0
0: Paradise
1: Come come ye saints
2: Yellow
3: Superheroes
4: When he comes again
5: Time
Pick a song index number: 1

Enter your selection now: addsp
0: Coding Music
1: Sunday Favorites
2: Game Day
Pick a playlist index number: 0
0: Paradise
1: Come come ye saints
2: Yellow
3: Superheroes
4: When he comes again
5: Time
Pick a song index number: 3

Enter your selection now: addsp
0: Coding Music
1: Sunday Favorites
2: Game Day
Pick a playlist index number: 1
0: Paradise
1: Come come ye saints
2: Yellow
3: Superheroes
4: When he comes again
5: Time
Pick a song index number: 1

Enter your selection now: addsp
0: Coding Music
1: Sunday Favorites
2: Game Day
Pick a playlist index number: 1
0: Paradise
1: Come come ye saints
2: Yellow
3: Superheroes
4: When he comes again
5: Time
Pick a song index number: 4

Enter your selection now: play
0: Coding Music
1: Sunday Favorites
2: Game Day
Pick a playlist index number: 0

Playing first lines of playlist: Coding Music
Look at the stars
Come come ye saints, no toil nor labor fear
All her life she has seen

Enter your selection now: play
0: Coding Music
1: Sunday Favorites
2: Game Day
Pick a playlist index number: 1

Playing first lines of playlist: Sunday Favorites
Come come ye saints, no toil nor labor fear
I wonder when he comes again, will herald angels sing

Enter your selection now: list
Paradise: "When she was just a girl", 0 play(s).
Come come ye saints: "Come come ye saints, no toil nor labor fear", 2 play(s).
Yellow: "Look at the stars", 1 play(s).
Superheroes: "All her life she has seen", 1 play(s).
When he comes again: "I wonder when he comes again, will herald angels sing", 1 play(s).
Time: "Ticking away the moments that make up a dull day", 0 play(s).

Enter your selection now: remp
0: Coding Music
1: Sunday Favorites
2: Game Day
Pick a playlist index number to remove: 2

Enter your selection now: listp
0: Coding Music
1: Sunday Favorites

Enter your selection now: remsp
0: Coding Music
1: Sunday Favorites
Pick a playlist index number: 0
0: Yellow
1: Come come ye saints
2: Superheroes
Pick a song index number to remove: 0

Enter your selection now: play
0: Coding Music
1: Sunday Favorites
Pick a playlist index number: 0

Playing first lines of playlist: Coding Music
Come come ye saints, no toil nor labor fear
All her life she has seen

Enter your selection now: remsl
0: Paradise
1: Come come ye saints
2: Yellow
3: Superheroes
4: When he comes again
5: Time
Pick a song index number to remove: 1

Enter your selection now: play
0: Coding Music
1: Sunday Favorites
Pick a playlist index number: 0

Playing first lines of playlist: Coding Music
All her life she has seen

Enter your selection now: play
0: Coding Music
1: Sunday Favorites
Pick a playlist index number: 1

Playing first lines of playlist: Sunday Favorites
I wonder when he comes again, will herald angels sing

Enter your selection now: list
Paradise: "When she was just a girl", 0 play(s).
Yellow: "Look at the stars", 1 play(s).
Superheroes: "All her life she has seen", 3 play(s).
When he comes again: "I wonder when he comes again, will herald angels sing", 2 play(s).
Time: "Ticking away the moments that make up a dull day", 0 play(s).

Enter your selection now: quit
Goodbye!
</pre>