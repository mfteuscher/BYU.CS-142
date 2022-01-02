#pragma once
#include "Cake.h"
#include <string>

class CupCake : public Cake {
public:
	CupCake(std::string theFlavor, std::string theFrosting, std::string theSprinkles);
	virtual std::string ToString();
	virtual double DiscountedPrice(int theQuantity);
private:
	std::string sprinkleColor;
	const double BASE_PRICE = 1.95;
	const double CREAM_CHEESE_FROSTING = 0.20;
	const double DISCOUNT_FOR_2 = 0.30;
	const double DISCOUNT_FOR_4 = 0.40;
};

