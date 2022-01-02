#pragma once
#include <string>
class BakedGood {
public:
	BakedGood(double thePrice);
	virtual std::string ToString() = 0;
	virtual double DiscountedPrice(int theQuantity) = 0;
protected:
	double goodPrice;
};