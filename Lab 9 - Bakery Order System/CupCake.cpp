#include "CupCake.h"
#include <iostream>
#include <iomanip>

CupCake::CupCake(std::string theFlavor, std::string theFrosting, std::string theSprinkles) : Cake(theFlavor, theFrosting, 0) {
	cakeFlavor = theFlavor;
	frostingType = theFrosting;
	sprinkleColor = theSprinkles;
}

std::string CupCake::ToString() {
	goodPrice = BASE_PRICE;
	if (frostingType == "cream-cheese") {
		goodPrice += CREAM_CHEESE_FROSTING;
	}
	std::string theString = cakeFlavor + " cupcake with " + frostingType + " frosting and " + sprinkleColor + " sprinkles ($" + std::to_string(goodPrice) + ")";
	return theString;
}

double CupCake::DiscountedPrice(int theQuantity){
	double cupcakePrice = goodPrice * theQuantity;
	if (theQuantity >= 4) {
		cupcakePrice -= (theQuantity * DISCOUNT_FOR_4);
	}
	else if (theQuantity >= 2) {
		cupcakePrice -= (theQuantity * DISCOUNT_FOR_2);
	}
	return cupcakePrice;
}
