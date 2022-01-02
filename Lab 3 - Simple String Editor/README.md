# Lab 3 - Simple String Editor

## Synopsis

This is a simple text editor. You give it an initial string, and it can add punctuation to it or insert additional text
to the string. It can also find text in string, and delete or replace that text. It also can copy text in the string and
paste that text somewhere else in the string. The main focus of this lab is using if else statements.

### Background

Editing text is something we do all the time. In this lab you will create the beginnings of a simple editor.

### Part 1 - Initial Text Input (15 points)

Prompt the user to input the initial text to be edited. See the examples below for exact I/O format. You will enter just
one line of text. Use getline to put the text into a string variable. Strings can be any characters, numbers,
punctuation, etc. Then print out the string.

### Part 2 - Make the string a sentence (20 points)

Output "Do you want to make this string a sentence (y/n)? ". If yes:

* Capitalize the first letter of the string
* If there is not a period, question mark, or exclamation point already at the end of the string, add a period
* Print out the string

Critical Note: getline and cin, don't mix real well in C++. For this lab, you can make everything work fine by doing the
following. After every use of cin, add the line ```cin.ignore();```. For example

<pre>
cin >> newValue;
cin.ignore();
</pre>

If you don't do this you will have some bugs which will befuddle you. If you are curious to know why, see sec. 2.16.

### Part 3 - Insert More Text (20 points)

Output "Do you want to insert more text into your current text (y/n)? " If yes,

* Output "Enter text to be inserted: ". Use getline to get text.
* Output "Enter position where text is to be inserted: ". Get position using cin.
* Insert the text and print out the updated string.

Note: Everywhere in this lab where a string position is considered, we assume that the first character is at position 0,
second at position 1, etc. If a user enters 0 then the new text will be inserted at the beginning. If they enter an
integer which is the length of the initial text, the new text is appended to the end. If they enter a value between
those, then the text is inserted at that position. For example if the initial text is "Jelly donut" and the user asks to
insert " filled" at position 5, then the updated string would be "Jelly filled donut". The space at the beginning of "
filled" is on purpose in this case.

Error Checking: In general when we ask for input, we like to verify that the user enters correct input. In this lab you
may assume that the user enters an integer whenever a position/length is asked for. However, you must check to see if
the value is appropriate. For the case of entering a position for inserting text, if the user enters a negative integer
or an integer larger than the size of the string, output "No change made. Position must be non-negative and not exceed
24, the length of the current text." Of course, rather than 24, use whatever the length of the current text is. Note
that normally we would then ask the user to try again, but since we don't have loops we cannot do that yet. But we will
on the next lab!

### Part 4 - Find/Replace or Copy/Paste (45 points)

Output "If you would like to find/replace or copy/paste, enter find or copy: ". If they enter anything other than "find"
or "copy", just continue to the end of the program. If they enter "find":

* Output "Enter substring to find: " (For this example, assume the entered string is taco)
* Output "Do you want to find if/where the substring occurs, delete it, or replace it (find, delete, replace)? "
* If "find":
    * Output "taco was found at position 12.", if the first occurrence of taco is at position 12
    * Output "taco was not found.", if taco does not occur in the text.
* if "delete":
    * Delete from the current text the first occurrence of taco
    * Output "taco was not found. No change made.", if taco does not occur in the text.
* if "replace",
    * Output "taco was not found. No change made.", if taco does not occur in the text.
    * Otherwise, output "Enter replacement string: " (For this example, assume chile relleno was entered). Replace the
      first occurrence of taco with chile relleno.

If they enter "copy" rather than "find" at the initial prompt:

* Output "Enter position and length of text to be copied, and position for paste: "
* If positions (of both the text to be copied and to be pasted) and length are valid, insert the copied text at the
  position. Don't delete the original copied text.
* If positions (of both the text to be copied and to be pasted) or length are invalid, output "Values entered do not
  support copy/paste."
    * Although you may use multiple ifs to determine whether to find, replace, or delete, you must test for positions
      and length validity using just one if-else statement (see below)

Finally output "Final text is" followed by the text on a new line.

#### Sample Input 1

<pre>
hello friend
y
y
my
5
find
lo
find
</pre>

#### Sample Output 1

<pre>
Welcome to the Simple Editor. Enter a string to be edited:
hello friend

Do you want to make this string a sentence (y/n)?
Hello friend.

Do you want to insert more text into your current text (y/n)?
Enter text to be inserted:
Enter position where text is to be inserted:
Hello my friend.

If you would like to find/replace or copy/paste, enter find or copy:
Enter substring to find:
Do you want to find if/where the substring occurs, delete it, or replace it (find, delete, replace)?
lo was found at position 3.
Final text is
Hello my friend.
</pre>

#### Sample Input 2

<pre>
another string
n
y
exciting
25
find
friend
delete
</pre>

#### Sample Output 2

<pre>
Welcome to the Simple Editor. Enter a string to be edited:
another string

Do you want to make this string a sentence (y/n)?
Do you want to insert more text into your current text (y/n)?
Enter text to be inserted:
Enter position where text is to be inserted:
No change made. Position must be non-negative and not exceed 14, the length of the current text.
If you would like to find/replace or copy/paste, enter find or copy:
Enter substring to find:
Do you want to find if/where the substring occurs, delete it, or replace it (find, delete, replace)?
friend was not found. No change made.
Final text is
another string
</pre>

#### Sample Input 3

<pre>
my good friend!
y
n
find
good
replace
best
</pre>

#### Sample Output 3

<pre>
Welcome to the Simple Editor. Enter a string to be edited:
my good friend!

Do you want to make this string a sentence (y/n)?
My good friend!

Do you want to insert more text into your current text (y/n)?
If you would like to find/replace or copy/paste, enter find or copy:
Enter substring to find:
Do you want to find if/where the substring occurs, delete it, or replace it (find, delete, replace)?
Enter replacement string: Final text is
My best friend!
</pre>

#### Sample Input 4

<pre>
I love ice cream good!
n
n
copy
6
10
21
</pre>

#### Sample Output 4

<pre>
Welcome to the Simple Editor. Enter a string to be edited:
I love ice cream good!

Do you want to make this string a sentence (y/n)?
Do you want to insert more text into your current text (y/n)?
If you would like to find/replace or copy/paste, enter find or copy:
Enter position and length of text to be copied, and position for paste:
Final text is
I love ice cream good ice cream!
</pre>