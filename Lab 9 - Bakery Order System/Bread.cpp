#include "Bread.h"


Bread::Bread(std::string theType) : BakedGood(BASE_PRICE){
	breadType = theType;
}

std::string Bread::ToString() {
	goodPrice = BASE_PRICE;
	std::string theString = breadType + " bread ($" + std::to_string(goodPrice) + ")";
	return theString;
}

double Bread::DiscountedPrice(int theQuantity) {
	int freeLoaves = theQuantity / BREAD_DISCOUNT;
	double breadPrice = (BASE_PRICE * theQuantity) - (BASE_PRICE * freeLoaves);
	return breadPrice;
}
