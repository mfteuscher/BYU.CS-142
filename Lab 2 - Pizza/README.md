# Lab 2 - Pizza

## Synopsis

This is a relatively simple program that given an input of a party size (in number of guests) tells you how many pizzas
you need in what sizes to feed everyone there. It also calculates how much pizza you have in square inches. Finally, it
gives you the prices of all these pizzas, including a tip percentage that you input. The values of prices and are of
various pizza sizes are constants that can be easily change for different scenarios.

### Background

You have been elected as President of the Pizza Council of BYUSA. Your primary responsibility is determining how many
pizzas should be ordered for each BYUSA event. To make things easier, you decide to write a C++ program to help you do
the calculations.

### Part 1 - Count your Many Pizzas

Prompt the user for the number of guests attending the event. Determine and report the number of large, medium, and
small pizzas you need to order. For every 7 guests, order one large pizza. For every 3 guests left over, order one
medium pizza. For every 1 guest left over, order one small pizza.

### Part 2 - Serving Size

Compute and report the total area of pizza (in square inches) you need to purchase. Do not round these values. Compute
and report the total area of pizza (in square inches) each guest can eat. Do not round these values.

### Part 3 - Supplementing the Budget

Prompt the user for the percent of the total price to be paid as a tip. The tip percentage will be input as a whole
integer from 0 to 100. Compute and report the total cost (including tip) of all the pizzas, rounding to the nearest
dollar. Note: Changing the value type into an int alone will not round to the nearest dollar. See the end of the "Notes"
section below.

### Part 4 - The "Magic" of Avoiding Magic Numbers

Sometimes it may feel like a nuisance to make sure to properly use constants for magic numbers, so here we give you the
opportunity to see how useful it can be. By changing just some of the constants, your program can simulate any pizza
sizes and prices, without having to touch any other part of your code. Those constants are how many people each pizza
feeds, the dimensions of each pizza, and the cost of each pizza. Make sure that you have written your code so that by
changing only those nine values, and re-compiling, you can simulate any arbitrary pizza values.