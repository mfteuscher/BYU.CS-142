#include "ShoppingCart.h"
#include "ItemToPurchase.h"
#include <iostream>
#include <iomanip>
using namespace std;



ShoppingCart::ShoppingCart() {
	customerName = "none";
	dateCartCreated = "January 1, 2016";
}

ShoppingCart::ShoppingCart(string userName, string theDate) {
	customerName = userName;
	dateCartCreated = theDate;
}

string ShoppingCart::GetCustomerName(string userName) const {
	return customerName;
}

string ShoppingCart::GetDate(string theDate) const {
	return dateCartCreated;
}

void ShoppingCart::ShowOptions(){
	cout << "MENU" << endl;
	cout << "add - Add item to cart" << endl;
	cout << "remove - Remove item from cart" << endl;
	cout << "change - Change item quantity" << endl;
	cout << "descriptions - Output items' descriptions" << endl;
	cout << "cart - Output shopping cart" << endl;
	cout << "options - Print the options menu" << endl;
	cout << "quit - Quit" << endl << endl;
}

void ShoppingCart::FindItem(string theItem) {
	itemPresent = false;
	for (unsigned int i = 0; i < itemsShoppingCart.size(); ++i) {
		if (itemsShoppingCart.at(i).GetName() == theItem) {
			itemPresent = true;
			modLocation = i;
			break;
		}
	}
}

void ShoppingCart::AddItem(ItemToPurchase newItem) {
	FindItem(newItem.GetName());
	if (itemPresent == true) {
		cout << "Item is already in cart. Nothing added." << endl;
	}
	else {
		itemsShoppingCart.push_back(newItem);
	}
	cout << endl;
}

void ShoppingCart::RemoveItem(string removeItem) {
	FindItem(removeItem);
	if (itemPresent == false) {
		cout << "Item not found in cart. Nothing removed." << endl;
	}
	else {
		itemsShoppingCart.erase(itemsShoppingCart.begin() + modLocation);
	}
	cout << endl;
}

void ShoppingCart::ChangeQuantity(string theName, int newQuantity) {
	FindItem(theName);
	if (itemPresent == false) {
		cout << "Item not found in cart. Nothing modified." << endl;
	}
	else {
		itemsShoppingCart.at(modLocation).SetQuantity(newQuantity);
	}
	cout << endl;
}

void ShoppingCart::ShowDescriptions() {
	cout << customerName << "\'s Shopping Cart - " << dateCartCreated << endl;
	if (itemsShoppingCart.empty() == true) {
		cout << "Shopping cart is empty." << endl;
	}
	else {
		cout << "Item Descriptions" << endl;
		for (unsigned int i = 0; i < itemsShoppingCart.size(); ++i) {
			itemsShoppingCart.at(i).PrintDescription();
		}
	}
	cout << endl;
}

void ShoppingCart::ShowCart() {
	cout << customerName << "\'s Shopping Cart - " << dateCartCreated << endl;
	if (itemsShoppingCart.empty() == true) {
		cout << "Shopping cart is empty." << endl;
	}
	else {
		cout << "Number of items: ";
		int totalItems = 0;
		double totalCost = 0.00;
		for (unsigned int i = 0; i < itemsShoppingCart.size(); ++i) {
			totalItems += itemsShoppingCart.at(i).GetQuantity();
			totalCost += (itemsShoppingCart.at(i).GetPrice() * itemsShoppingCart.at(i).GetQuantity());
		}
		cout << totalItems << endl << endl;
		cout << fixed << showpoint << setprecision(2);
		for (unsigned int i = 0; i < itemsShoppingCart.size(); ++i) {
			itemsShoppingCart.at(i).PrintCost();
		}
		cout << endl << "Total: $" << totalCost << endl;
	}
	cout << endl;
}