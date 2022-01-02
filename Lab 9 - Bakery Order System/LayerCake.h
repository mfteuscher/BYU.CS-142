#pragma once
#include "Cake.h"
#include <string>
class LayerCake : public Cake {
public:
	LayerCake(std::string theFlavor, std::string theFrosting, int layerNum);
	virtual std::string ToString();
	virtual double DiscountedPrice(int theQuantity);
private:
	int numLayers;
	const double BASE_PRICE = 9;
	const double CREAM_CHEESE_FROSTING = 1.00;
	const double EXTRA_LAYERS = 3.00;
	const double LAYER_CAKE_DISCOUNT = 2.00;
};

