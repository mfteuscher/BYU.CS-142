#include "ItemToPurchase.h"
#include <iostream>
#include <string>


ItemToPurchase::ItemToPurchase() {
	itemName = "none";
	itemDescription = "none";
	itemPrice = 0.0;
	itemQuantity = 0;
}

ItemToPurchase::ItemToPurchase(std::string theName, std::string theDescription, double thePrice, int theQuantity) {
	itemName = theName;
	itemDescription = theDescription;
	itemPrice = thePrice;
	itemQuantity = theQuantity;
}

void ItemToPurchase::SetName(std::string theName) {
	itemName = theName;
}

void ItemToPurchase::SetDescription(std::string theDescription) {
	itemDescription = theDescription;
}

void ItemToPurchase::SetPrice(double thePrice) {
	itemPrice = thePrice;
}

void ItemToPurchase::SetQuantity(int theQuantity) {
	itemQuantity = theQuantity;
}

std::string ItemToPurchase::GetName() const {
	return itemName;
}

std::string ItemToPurchase::GetDescription() const {
	return itemDescription;
}

double ItemToPurchase::GetPrice() const {
	return itemPrice;
}

int ItemToPurchase::GetQuantity() const {
	return itemQuantity;
}

void ItemToPurchase::PrintCost() const{
	std::cout << GetName() << " " << GetQuantity() << " @ $" << GetPrice() 
		<< " = $" << GetQuantity() * GetPrice() << std::endl;
}

void ItemToPurchase::PrintDescription() const {
	std::cout << GetName() << ": " << GetDescription() << std::endl;
}


