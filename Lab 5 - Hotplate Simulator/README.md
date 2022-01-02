# Lab 5 - Hotplate Simulator

## Synopsis

This program simulates the heating of a metal plate. A metal plate will heat up, and the temperature will be constantly
changing for separate parts of the plate. When the plate finally stabilizes in temperature, the loops end, and the
results are output to a file. There is also an input file feature that is for testing purposes, to make sure the program
works for different situations This lab is mostly for the purpose of understanding loops.

### Background

In this lab you will compute the steady state temperature distribution over a piece of metal. This steady state analysis
is used in solving many physics problems. Similar matrix algorithms are also used in analyzing airplane wing and
automobile surface pressure. These types of calculations are intended to ensure that everything works correctly in such
applications. Though the full analysis may be complicated, pieces of it are quite simple, such as the problem described
below.

### Part 1 - Initialize and Print 2D Array

In this lab you will write a program to determine the temperature distribution for a two-dimensional plate with constant
boundary conditions. Use a 10 X 10 two-dimensional array of numbers to represent the temperature at different places on
a (square) plate. The elements on the boundaries have fixed temperatures. The elements on the top and bottom row have a
fixed temperature of 100 degrees. The elements on the leftmost and rightmost columns have a temperature of 0 degrees. (
The corner elements have a temperature of 0 degrees.) Also assume that all interior elements start at 0 degrees. This
obviously does not represent a typical hot plate, but this is a good exercise to simulate how temperature would
dynamically distribute across a surface.

For part one you must initialize the 2D array and print it to the screen. Print the numbers in the array with a fixed
precision of 3 and width 9. The first auto-grade tests all whitespace to make sure you have exact spacing, etc. on this
first test. Note that there is one comma (just a comma) after each number, except the last number in the row. For
example, an initialized 5 X 5 matrix (note: yours will be 10x10) would look like this.

    0.000,  100.000,  100.000,  100.000,    0.000
    0.000,    0.000,    0.000,    0.000,    0.000
    0.000,    0.000,    0.000,    0.000,    0.000
    0.000,    0.000,    0.000,    0.000,    0.000
    0.000,  100.000,  100.000,  100.000,    0.000

You must initialize the plate programmatically using loops. You may not use a large number of assignment statements. You
must also use a 2-d array, not a vector nor a large number of independent variables.

### Before Part 2

To calculate the new temperature value of an array element, take the average of the temperatures of the four neighbors
of that cell from the previous iteration. The next section describes in more detail how the update process should work.

### Part 2 - Update Elements Once

The task of the algorithm is to find the steady-state temperature distribution of the interior elements which are
constantly changing to become the average of the temperature of their neighbors. Steady state means that the temperature
of any cell is virtually unchanging and approximately equal to the average of the temperatures of its four neighbors on
the north, south, east, and west directions (do not worry about the diagonal neighbors). Note that the steady state
temperatures will be the same regardless of what the beginning temperatures are for the interior elements.

To calculate the new temperature value of an array element, take the average of the temperatures of the four neighbors
of that cell from the previous iteration. This value will be placed in the output array. For example, suppose the
current state of the plate is (it won't be like this to start out with, but suppose it were):

    0.000,  100.000,  100.000,  100.000,    0.000
    0.000,   40.625,   50.000,   40.625,    0.000
    0.000,   25.000,   31.250,   25.000,    0.000
    0.000,   40.625,   50.000,   40.625,    0.000
    0.000,  100.000,  100.000,  100.000,    0.000

In this example, the cell at position array[1][3] currently has a value of 40.625 degrees. At the current iteration,
this element in the output array will be set to the average of the current value of its four neighbors, that is, (
array[0][3] + array[1][4] + array[2][3] + array[1][2])/4 or (100.000 + 0.000 + 25.000 + 50.000)/4 which is 43.750.

For Part 2, just print the first iteration. (Note that the first iteration is NOT the initialized matrix, it is the
matrix obtained after one update to each cell in the array).

If you think about it, you will realize that the value at array[2][3] depends upon the value at array[1][3]. One could
ask, should the computation of array[2][3] use the value of array[1][3] as it was at the start of the current iteration,
or the already updated value. This is an interesting theoretical question, but for our purposes you need to use the
value as it was at the start of the iteration. Thus, you will need two 2D arrays, one of which should contain the values
as they were before the computations (an "old values" array), and one where the new values are being placed (a "new
values" array).

### Part 3 - Repeat Update until Stable

After printing the results from the first iteration, continue to iterate (calculating the temperature for all interior
cells) until no cell in the array changes by more than 0.1 degrees. Your program should monitor the largest change for
any cell in the array in order to determine when to stop iterating. At the end of each iteration you will copy the
values from the "new values" array into the "old values" array, to be ready for the next iteration.

Once all of the values in the plate have ceased to change by more than 0.1 degrees, print the final stable plate, in the
same comma separated form used above. Do not print all the intermediate arrays, just the final one after it becomes
stable.

### Part 4 - Output Data to a File

Output the values of the stable plate, with the same comma separated format, to a file named "Hotplate.csv". Your
program should create/open the file, write to it, and then close it. In your IDE , the file will appear in your default
directory which is the same directory where your source code resides. Thus, you just need to open "Hotplate.csv" with no
preceding directory path. In your IDE you can open the file with notepad to make sure it is correct. Thus, you will not
have access to it.

### Part 5 - Input Plate

Input into your plate array from the file "Inputplate.txt" which you should have in the same directory as "Hotplate.csv"
in your IDE. Fill ALL elements of your array from this file including the borders, (though the borders will continue to
have the same static values as before). After inputting the initial array, iterate just 3 times with your plate update
loop, and then output the current plate values to the screen. These will be the array values after exactly 3 update
iterations. You may assume that the input file has only doubles and correctly matches the 10x10 array, thus you will not
need to error check your file input. Note that regardless of initial temperatures in the interior, if you have the same
steady edge temperatures, and if you run until stable, this plate would have the same stable values (within .1 degrees)
as the stable plate above.

### Notes

* Use 2 dimensional arrays of doubles (not vectors nor any other mechanism) to manage the plate values.
* You must initialize the array using loops.
* You must monitor the stopping criteria in the loop structure and stop when no cell in the array changes by more than
  0.1 degrees.
* You must use all of the values in the array to determine if it is time to stop iterating in part 3 (for example, you
  may not just check one value).

#### Sample Output

Your output should look like the output shown below; but of course your output will be for a 10 X 10 array not just the
5 X 5 shown here. The last set of numbers for the updated input plate are just made up values.
<pre>
Hotplate simulator

Printing initial plate...
0.000,  100.000,  100.000,  100.000,    0.000
0.000,    0.000,    0.000,    0.000,    0.000
0.000,    0.000,    0.000,    0.000,    0.000
0.000,    0.000,    0.000,    0.000,    0.000
0.000,  100.000,  100.000,  100.000,    0.000

Printing plate after one iteration...
0.000,  100.000,  100.000,  100.000,    0.000
0.000,   25.000,   25.000,   25.000,    0.000
0.000,    0.000,    0.000,    0.000,    0.000
0.000,   25.000,   25.000,   25.000,    0.000
0.000,  100.000,  100.000,  100.000,    0.000

Printing final plate...
0.000,  100.000,  100.000,  100.000,    0.000
0.000,   49.854,   62.305,   49.854,    0.000
0.000,   37.305,   49.707,   37.305,    0.000
0.000,   49.854,   62.305,   49.854,    0.000
0.000,  100.000,  100.000,  100.000,    0.000

Outputting final plate to file "Hotplate.csv"...

Printing input plate after 3 updates...
0.000,  100.000,  100.000,  100.000,    0.000
0.000,   -2.853,   62.304,  -49.853,    0.000
0.000,   37.304,   49.707,   37.304,    0.000
0.000,   49.853,   -2.304,    1.853,    0.000
0.000,  100.000,  100.000,  100.000,    0.000
</pre>