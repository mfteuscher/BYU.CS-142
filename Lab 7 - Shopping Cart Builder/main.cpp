#include "ItemToPurchase.h"
#include "ShoppingCart.h"
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

int main() {
	string userName;
	string dateToday;
	string nameItem;
	string descriptionItem;
	double priceItem;
	int quantityItem;
	string optionSelect;

	cout << "Enter Customer's Name: ";
	getline(cin, userName);
	cout << "Enter Today's Date: ";
	getline(cin, dateToday);
	
	ShoppingCart shoppingCart(userName, dateToday);

	cout << endl;

	cout << "Enter option: ";
	cin >> optionSelect;
	cin.ignore();

	do {
		if (optionSelect == "add") {
			cout << "Enter the item name: ";
			getline(cin, nameItem);
			cout << "Enter the item description: ";
			getline(cin, descriptionItem);
			cout << "Enter the item price: ";
			cin >> priceItem;
			cin.ignore();
			cout << "Enter the item quantity: ";
			cin >> quantityItem;
			cin.ignore();
			shoppingCart.AddItem(ItemToPurchase(nameItem, descriptionItem, priceItem, quantityItem));
		}
		else if (optionSelect == "remove") {
			cout << "Enter name of the item to remove: ";
			getline(cin, nameItem);
			shoppingCart.RemoveItem(nameItem);
		}
		else if (optionSelect == "change") {
			cout << "Enter the item name: ";
			getline(cin, nameItem);
			cout << "Enter the new quantity: ";
			cin >> quantityItem;
			cin.ignore();
			shoppingCart.ChangeQuantity(nameItem, quantityItem);
		}
		else if (optionSelect == "descriptions") {
			shoppingCart.ShowDescriptions();
		}
		else if (optionSelect == "cart") {
			shoppingCart.ShowCart();
		}
		else if (optionSelect == "options") {
			shoppingCart.ShowOptions();
		}
		else {
			shoppingCart.ShowOptions();
		}

		cout << "Enter option: ";
		cin >> optionSelect;
		cin.ignore();

	} while (optionSelect != "quit");

	cout << "Goodbye.";

	return 0;
}