#pragma once
#include "ItemToPurchase.h"
#include <string>
#include <vector>

class ShoppingCart {
public:
	ShoppingCart();
	ShoppingCart(std::string userName, std::string theDate);
	std::string GetCustomerName(std::string userName) const;
	std::string GetDate(std::string theDate) const;
	void AddItem(ItemToPurchase newItem);
	void RemoveItem(std::string removeItem);
	void ChangeQuantity(std::string theName, int newQuantity);
	void ShowDescriptions();
	void ShowCart();
	void ShowOptions();
private:
	std::string customerName;
	std::string dateCartCreated;
	std::vector<ItemToPurchase> itemsShoppingCart;
	void FindItem(std::string theItem);
	bool itemPresent = false;
	int modLocation;

};

