#pragma once
#include "BakedGood.h"
#include <string>
#include <iostream>
class Bread : public BakedGood {
public:
	Bread(std::string theType = "null");
	virtual std::string ToString();
	virtual double DiscountedPrice(int theQuantity);
private:
	std::string breadType;
	const double BASE_PRICE = 4.5;
	const int BREAD_DISCOUNT = 3;
};

