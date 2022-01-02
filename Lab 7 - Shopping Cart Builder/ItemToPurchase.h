#pragma once
#ifndef ITEMTOPURCHASE_H
#define ITEMTOPURCHASE_H
#include <string>

class ItemToPurchase {
public:
	ItemToPurchase();
	ItemToPurchase(std::string theName, std::string theDescription, double thePrice, int theQuantity);
	void SetName(std::string theName);
	void SetDescription(std::string theDescription);
	void SetPrice(double thePrice);
	void SetQuantity(int theQuantity);
	std::string GetName() const;
	std::string GetDescription() const;
	double GetPrice() const;
	int GetQuantity() const;
	void PrintCost() const;
	void PrintDescription() const;
private:
	std::string itemName;
	std::string itemDescription;
	double itemPrice;
	int itemQuantity;
};


#endif