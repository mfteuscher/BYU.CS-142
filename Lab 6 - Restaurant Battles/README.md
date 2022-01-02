# Lab 6 - Restaurants

## Synopsis

This lab is mostly about building functions to do repetitive tasks. Can add and remove restaurants from a bracket of
sorts, and then they can be randomly run through a tournament to determine a winner. They can also be shuffled in
various ways.

### Background

You find yourself wondering how your family can have such difficulty arranging a night out. Every Friday night, your
family goes out to eat. The discussion of where to eat, unfortunately, is often drawn out and sometimes becomes a little
heated. Thinking about the NCAA Tournament, you get a brilliant idea of how to more efficiently make a selection.

Instead of fighting over several restaurants at once, you decide to write a program that eliminates one restaurant at a
time by pitting two restaurants against each other until a single restaurant remains. Your family can now decide where
to eat based on answering a series of yes/no questions. While this does not eliminate all of the arguing, it does
simplify the decisions to be made.

### Part 1 - The Menu

A detailed example of all your operations is shown at the end of the specification. Begin your program with the output;
<pre>
Welcome to the restaurant battle!  Enter "options" to see options.

Enter your selection:
</pre>

If the user enters "options" then output the options menu:

<pre>
Please select one of the following options:

quit - Quit the program
display - Display all restaurants
add - Add a restaurant
remove - Remove a restaurant
cut - "Cut" the list of restaurants
shuffle - "Shuffle" the list of restaurants
battle - Begin the tournament
options - Print the options menu
</pre>

After completing any option (except for quitting), re-prompt the user with "Enter your selection: ". If an incorrect
option is entered, print "Invalid Selection" and then print the menu as if they had selected options. For Part 1, only
the quit and options operations need to work, along with handling an invalid selection.

### Part 2 - The Contenders

Add functionality to display, add, and remove restaurants. Each of these should be implemented using a function, and you
must use a vector to hold the list of restaurants. For this lab we will use a STRING CONTAINING THE NAME of the
restaurant to represent the restaurant. The restaurant name may contain multiple words.

* Display all restaurants
    * Display the restaurant names in their current order, on separate lines, prefaced with one tab ("
      \t").
* Add a restaurant
    * Prompt the user for a restaurant name
    * If the restaurant name is not already in the vector, add it to the vector and print the restaurant name followed
      by "has been added."
    * If the restaurant name is already in the vector, do nothing to the vector but say "That restaurant is already in
      the list, you can not add it again."
* Remove a restaurant
    * Prompt the user for a restaurant name
    * If the restaurant name is in the vector, remove it from the vector and say the restaurant name followed by "has
      been removed."
    * If the restaurant name is not in the vector, do nothing to the vector but say "That restaurant is not in the list,
      you can not remove it."
* Both add and remove need to know (for different purposes) if the name given by the user is already in the list. This
  code should be in your own find restaurant function; not repeated in both places.

### Part 3 - Mixing It Up

Add functionality for cut and shuffle, as if the restaurant list was a deck of cards. Each of these should be
implemented using a function.

* "Cut" the vector of restaurant names.
    * Prompt the user for a number.
    * If the cut number is out of range say "The cut number must be between 0 and current-number-of-restaurants'", and
      re-prompt for the number.
    * In this program, "cut" is like the cut operation used in card games. Take the specified number of Restaurant names
      off of the top of the vector of restaurant names, and put them in the same order at the bottom. If the restaurant
      name list contains a, b, c, and d and the cut point is 3, then after the cut the list should be: d, a, b, and c.
      Note that a cut number of 0 or n (where n is the number of restaurants)
      leaves the list unchanged.
    * Cut can be done by moving things around in the existing vector, but you might find that difficult. It is easier to
      build a new vector as described and then return the newly assembled vector from your cut function.

* "Shuffle" restaurant names in the restaurant name vector.
    * In this program, "shuffle" is like the shuffle operation used in card games to mix up the cards. Split the "deck"
      in half, and rearrange the restaurants, alternating between the two halves, starting with the first restaurant in
      the second half. For instance, if the restaurant name vector contained the restaurant names: a, b, c, d, e, f, g
      and h, then after the shuffle, the vector would have the order e, a, f, b, g, c, h and d.
    * Implement this function from scratch. Do not use arcane #includes that have not been discussed in class yet.
    * Do not allow the shuffle unless the number of restaurant names is a power of 2 (equal to 2^n for some value of n>
      =0). This must NOT be hard coded (i.e. do NOT use something like "if (n == 1 || n == 2 || n == 4 || n == 8…)").
      You must have an algorithm for solving this part. if the length is not a power of two, then say "The current
      tournament size ("current-list-length") is not a power of two (2, 4, 8…)." and on the next line "A shuffle is not
      possible. Please add or remove restaurants." Then return to the options prompt. We test your function with unit
      testing, so you must declare your function exactly as bool PowerOfTwo(int numberToCheck) which returns true if
      numberToCheck is a power of two, and false otherwise.
    * Like Cut, Shuffle can be done by moving things around in the existing vector. Again, it is easier to build a new
      vector as described and then return the newly assembled vector from your shuffle function.

### Part 4 - The Battle

Now create at least one function and allow the user to run a tournament among the restaurants currently in the vector
and report the winning restaurant name

* Each match of the tournament involves displaying two restaurant names to the user, prompting her to choose her
  favorite, and retaining only the winning restaurant name for the next round. As noted above, you might find it easier
  to construct a new vector of candidates and replace the old one rather than moving things around in place.
* For each round, take restaurant names in pairs and in order from the list, and output them as shown in the Sample
  output below. Restaurant names should appear in exactly one match in a round.
* The user should input either 1 or 2, signifying they prefer either the first or second restaurant, respectively.
* If the user provides a response other than 1 or 2, re-prompt the user as shown in the example, until either 1 or 2 is
  entered.
* Do not allow the tournament to begin unless the number of restaurant names is a power of 2, Use the same check you
  used for the shuffle function in Part 3 and say "The current tournament size (" current-list-length ") is not a power
  of two (2, 4, 8…)." and on the next line "A battle is not possible. Please add or remove restaurants."

### Additional Requirements

* You must use a correct algorithm to implement the power of two part, as described in part 3. Do not hardcode it.

### Notes

* Each major feature of the program must be implemented as a separate function. (Display, Add, Remove, Cut, Shuffle, and
  Battle).
* You must have your own find restaurant function as described above in Part 2.
* You must use a vector to keep track of the restaurant names.
* Vector of restaurants must not be global.
* Implement the shuffle function from scratch. Do not use arcane #includes or functions that have not been discussed in
  class yet.

#### Sample Input

<pre>
options
cheese
add
Super Taqueria
add
Epicure, Paris
add
Cannon Center
add
Cannon Center
remove
Cannon Center
add
Burger Supreme
add
Costa Vida
display
cut
34
2
display
shuffle
display
add
McDonalds
shuffle
battle
remove
McDonalds
battle
3
2
1
1
quit
</pre>

#### Sample Output

<pre>
Welcome to the restaurant battle!  Enter "options" to see options.

Enter your selection: options

Please select one of the following options:

quit - Quit the program
display - Display all restaurants
add - Add a restaurant
remove - Remove a restaurant
cut - "Cut" the list of restaurants
shuffle - "Shuffle" the list of restaurants
battle - Begin the tournament
options - Print the options menu

Enter your selection: cheese

Invalid Selection
Please select one of the following options:

quit - Quit the program
display - Display all restaurants
add - Add a restaurant
remove - Remove a restaurant
cut - "Cut" the list of restaurants
shuffle - "Shuffle" the list of restaurants
battle - Begin the tournament
options - Print the options menu

Enter your selection: add

What is the name of the restaurant you want to add?
Super Taqueria
Super Taqueria has been added.

Enter your selection: add

What is the name of the restaurant you want to add?
Epicure, Paris
Epicure, Paris has been added.

Enter your selection: add

What is the name of the restaurant you want to add?
Cannon Center
Cannon Center has been added.

Enter your selection: add

What is the name of the restaurant you want to add?
Cannon Center
That restaurant is already in the list, you can not add it again.

Enter your selection: remove

What is the name of the restaurant you want to remove?
Cannon Center
Cannon Center has been removed.

Enter your selection: add

What is the name of the restaurant you want to add?
Burger Supreme
Burger Supreme has been added.

Enter your selection: add

What is the name of the restaurant you want to add?
Costa Vida
Costa Vida has been added.

Enter your selection: display

Here are the current restaurants:

        "Super Taqueria"
        "Epicure, Paris"
        "Burger Supreme"
        "Costa Vida"

Enter your selection: cut

How many restaurants should be taken from the top and put on the bottom? 34

The cut number must be between 0 and 4
How many restaurants should be taken from the top and put on the bottom? 2

Enter your selection: display

Here are the current restaurants:

        "Burger Supreme"
        "Costa Vida"
        "Super Taqueria"
        "Epicure, Paris"

Enter your selection: shuffle

Enter your selection: display

Here are the current restaurants:

        "Super Taqueria"
        "Burger Supreme"
        "Epicure, Paris"
        "Costa Vida"

Enter your selection: add

What is the name of the restaurant you want to add?
McDonalds
McDonalds has been added.

Enter your selection: shuffle

The current tournament size (5) is not a power of two (2, 4, 8...).
A shuffle is not possible. Please add or remove restaurants.
Enter your selection: battle

The current tournament size (5) is not a power of two (2, 4, 8...).
A battle is not possible. Please add or remove restaurants.

Enter your selection: remove

What is the name of the restaurant you want to remove?
McDonalds
McDonalds has been removed.

Enter your selection: battle

Round: 1

Type "1" if you prefer Super Taqueria or
type "2" if you prefer Burger Supreme
Choice: 3

Invalid choice
Type "1" if you prefer Super Taqueria or
type "2" if you prefer Burger Supreme
Choice: 2

Type "1" if you prefer Epicure, Paris or
type "2" if you prefer Costa Vida
Choice: 1

Round: 2

Type "1" if you prefer Burger Supreme or
type "2" if you prefer Epicure, Paris
Choice: 1

The winning restaurant is Burger Supreme.

Enter your selection: quit

Goodbye!
</pre>