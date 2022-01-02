#pragma once
#include "BakedGood.h"
#include <string>
class Cake : public BakedGood {
public:
	Cake(std::string theFlavor, std::string theFrosting, double thePrice);
protected:
	std::string cakeFlavor;
	std::string frostingType;
private:
	
};

