# Lab 7 - Shopping Cart Builder

## Synopsis

In this program, I create a ShoppingCart object that holds various Item objects that I will purchase. Each item can have
names, values and descriptions, and the shopping cart has a name of the customer using it, the date it was created, and
a vector of Item objects. This lab is about understanding objects and how they're used.

### Background

This lab will have you build a class to represent an item which one could be buying as part of an online shopping cart.
Then you will create an online shopping cart like you might use for your online purchases. This shopping cart will be
able to hold item objects that you initially create. The goal is to become comfortable with setting up classes and using
objects.

### Requirements

(1) Create three files. You must implement the class with these separate files:

* ItemToPurchase.h - Class declaration
* ItemToPurchase.cpp - Class definition
* main.cpp - main function

Build the ItemToPurchase class with the following specifications:

* Default constructor
* Public class functions (mutators & accessors) - Name all members (functions and data) exactly as we show here and read
  the note below about unit tests to see why.
    * SetName & GetName
    * SetPrice & GetPrice
    * SetQuantity & GetQuantity
* Private data members
    * string itemName - Initialized in default constructor to "none"
    * double itemPrice - Initialized in default constructor to 0.0
    * int itemQuantity - Initialized in default constructor to 0

(2) In main, prompt the user for two items and create two objects of the ItemToPurchase class. Ex:
<pre>
Item 1
Enter the item name: Chocolate Chips
Enter the item price: 3.50
Enter the item quantity: 1

Item 2
Enter the item name: Bottled Water
Enter the item price: 1.00
Enter the item quantity: 10
</pre>
(3) Add the costs of the two items together and output the total cost. Ex:
<pre>
TOTAL COST Chocolate Chips 1 @ $3.50 = $3.50 Bottled Water 10 @ $1.00 = $10.00

Total: $13.50
</pre>

### Expanded ItemToPurchase Class

Extend the ItemToPurchase class as follows. We will not do unit testing in this lab, so we will not be giving you the
names of the member functions. Create good ones on your own.

* Create a parameterized constructor to assign item name, item description, item price, and item quantity (default
  values of "none" for name and description, and 0 for price and quantity).
* Additional public member functions
    * Set an item description
    * Get an item description
    * Print the cost of an item - Outputs the item name followed by the quantity, price, and subtotal (see example)
    * Print the description of an item - Outputs the item name and description (see example)
* Additional Private data members a string for the description of the item.

Example output of the function which prints the cost of an item:
<pre>Bottled Water 10 @ $1.50 = $15.00</pre>

Example output of the function which prints the item description:
<pre>Bottled Water: Deer Park, 12 oz. </pre>

### ShoppingCart Class

Create three new files:

* ShoppingCart.h - Class declaration
* ShoppingCart.cpp - Class definition
* main.cpp - main function (main's functionality will differ significantly from that of the prep lab)

Build the ShoppingCart class with the following specifications. Note: Some functions can be function stubs (empty
functions) initially, to be completed in later steps. Also, we usually declare all variable at the top of the code
block. Note that you could be declaring some class objects after receiving user input, so that is a case where it would
be all right to declare a variable later in your code.

* Parameterized constructor which takes the customer name and date as parameters
* Private data members
    * Name of the customer - Initialized in constructor to "none" if no parameter included
    * Date the cart was created - Initialized in constructor to "January 1, 2016" if no parameter included
    * Vector of items objects
* Must have the following public member functions
    * Get the name of the customer
    * Get the date the cart was created
    * Add an item object to the cart vector. Accepts a new item object as a parameter.
        * If item name is already in the cart, output this message: "Item is already in cart. Nothing added."
    * Remove an item object from the cart. Accepts an item name as a parameter.
        * If item name cannot be found, output this message: "Item not found in cart. Nothing removed."
    * Update the quantity of an item object in the cart
        * If item name cannot be found, output this message: "Item not found in cart. Nothing modified." If the quantity
          is set to 0, still leave the item in the cart, but treat it as a 0 in all counts, etc.
    * Return the quantity of items in the cart
    * Return the total cost of all items in the cart
    * Print the total number and cost of items in the cart
        * If cart is empty, output this message: "Shopping cart is empty"
    * Print the description of each item in the cart
        * If cart is empty, output this message: "Shopping cart is empty"

Example output of the function which prints the number and costs of items in the cart:
<pre>
John Doe's Shopping Cart - February 1, 2016 Number of Items: 8

Nike Romaleos 2 @ $189.00 = $378.00
Chocolate Chips 5 @ $3.50 = $17.50
Powerbeats 2 Headphones 1 @ $128.00 = $128.00

Total: $523.50 
</pre>

Example output of the function which prints the item descriptions:
<pre>
John Doe's Shopping Cart - February 1, 2016

Item Descriptions
Nike Romaleos: Volt color, Weightlifting shoes 
Chocolate Chips: Semi-sweet 
Powerbeats 2 Headphones: Bluetooth headphones 
</pre>

You may also create private helper functions in the ShoppingCart class if you'd like. Hint: A function to find if and
where an item name resides in the cart could be helpful in multiple places.

### Main Function Options Menu

See the full input/output example below to know the expected format. In main, first prompt the user for a customer's
name and today's date. Create an object of type ShoppingCart. Note that you have to declare (and thus create) your cart
after you have input the name and date, since you have to set those with the parameterized constructor since you do not
have setter functions for name and date.

In main, create a loop and allow the user to enter options to manipulate the cart. First implement the options and quit
options. If the user enters an incorrect option, just print the options menu.

<pre>
add - Add item to cart
remove - Remove item from cart
change - Change item quantity
descriptions - Output items' descriptions
cart - Output shopping cart
options - Print the options menu
quit - Quit 
</pre>

In this lab you may assume that when you prompt the user for an input, that they will input an appropriate value (e.g.
an int would not be negative, or a string, etc.). Thus, you are not required to do error checking (you may if you want
but we will not test for it). Note that in any "real-world" program, you would ALWAYS check for all possible input
errors. However, we have done that sufficiently in previous labs for you to understand the concept, so in this lab you
may assume legal inputs and focus on other programming aspects. The one exception is if the user enters an unknown
option you will print the options menu. Note that you will still have a mix of >> and getline, so make sure you deal
with that properly (See section 2.16 if necessary).

### Implement the remaining user options

Think about what parameters need to be passed to class member functions, etc.

* cart: Output shopping cart. Note that to do this, all you should need to do is call the appropriate member function on
  the shopping cart object. Note that by implementing printing options first, it is easy to test and verify later
  options as you implement them.
* descriptions: Output description of item's in the cart.
* add: Add an item to the cart.
* change:  Update the quantity of a current item in the cart to a new value.
* remove: Remove an item from the cart.

### Notes

* Create your own default constructor for each class. For this lab you're also required to create a parameterized
  constructor for each class. If you wish you may fulfill both at once by creating one constructor with default
  parameters. Hint: One way to test if you cover both cases is to declare a default and a fully parameterized object at
  the top of your code for each class and make sure that works by printing what they contain. Remember to delete the
  object declarations after testing.
* Each class must be created and submitted in separate cpp and header files.
    * All class member functions should be declared in the header file and defined in the cpp. In common practice, there
      may be some exceptions to this, but to keep grading simpler we require you to not define any functions in the
      header file.
* You must solve this problem using classes and members as specified. You must not submit a solution that solves the
  lab, while not using classes.
* You must have a vector of ItemToPurchase objects in the ShoppingCart class.

#### Sample Input

<pre>
Mary Jane Lewis
September 1, 2017
options
descriptions
cart
add
BYU game shirt
Perfect shirt to wear with the ROC
5.00
2
add
Sunscreen 50 SPF
Perfect to avoid the fourth quarter burn
4.50
3
add
Sunscreen 50 SPF
Perfect to avoid the fourth quarter burn
4.50
1
descriptions
cart
change
buffalo wings
4
change
BYU game shirt
4
cart
remove
Sunscreen 50 SPF
descriptions
cart
quit
</pre>

#### Sample Output

<pre>
Enter Customer's Name: Mary Jane Lewis
Enter Today's Date: September 1, 2017

Enter option: options
MENU
add - Add item to cart
remove - Remove item from cart
change - Change item quantity
descriptions - Output items' descriptions
cart - Output shopping cart
options - Print the options menu
quit - Quit

Enter option: descriptions
Mary Jane Lewis's Shopping Cart - September 1, 2017
Shopping cart is empty.

Enter option: cart
Mary Jane Lewis's Shopping Cart - September 1, 2017
Shopping cart is empty.

Enter option: add
Enter the item name: BYU game shirt
Enter the item description: Perfect shirt to wear with the ROC
Enter the item price: 5.00
Enter the item quantity: 2

Enter option: add
Enter the item name: Sunscreen 50 SPF
Enter the item description: Perfect to avoid the fourth quarter burn
Enter the item price: 4.50
Enter the item quantity: 3

Enter option: add
Enter the item name: Sunscreen 50 SPF
Enter the item description: Perfect to avoid the fourth quarter burn
Enter the item price: 4.50
Enter the item quantity: 1
Item is already in cart. Nothing added.

Enter option: descriptions
Mary Jane Lewis's Shopping Cart - September 1, 2017
Item Descriptions
BYU game shirt: Perfect shirt to wear with the ROC
Sunscreen 50 SPF: Perfect to avoid the fourth quarter burn

Enter option: cart
Mary Jane Lewis's Shopping Cart - September 1, 2017
Number of Items: 5

BYU game shirt 2 @ $5.00 = $10.00
Sunscreen 50 SPF 3 @ $4.50 = $13.50

Total: $23.50

Enter option: change
Enter the item name: buffalo wings
Enter the new quantity: 4
Item not found in cart. Nothing modified.

Enter option: change
Enter the item name: BYU game shirt
Enter the new quantity: 4

Enter option: cart
Mary Jane Lewis's Shopping Cart - September 1, 2017
Number of Items: 7

BYU game shirt 4 @ $5.00 = $20.00
Sunscreen 50 SPF 3 @ $4.50 = $13.50

Total: $33.50

Enter option: remove
Enter name of the item to remove: Sunscreen 50 SPF

Enter option: descriptions
Mary Jane Lewis's Shopping Cart - September 1, 2017
Item Descriptions
BYU game shirt: Perfect shirt to wear with the ROC

Enter option: cart
Mary Jane Lewis's Shopping Cart - September 1, 2017
Number of Items: 4

BYU game shirt 4 @ $5.00 = $20.00

Total: $20.00

Enter option: quit
Goodbye.
</pre>