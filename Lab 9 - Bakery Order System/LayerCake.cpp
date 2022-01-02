#include "LayerCake.h"
#include <iostream>
#include <iomanip>

LayerCake::LayerCake(std::string theFlavor, std::string theFrosting, int layerNum) : Cake (theFlavor, theFrosting, 0) {
	cakeFlavor = theFlavor;
	frostingType = theFrosting;
	numLayers = layerNum;
}

std::string LayerCake::ToString() {
	goodPrice = BASE_PRICE;
	if (numLayers > 1) {
		for (int i = 0; i < numLayers - 1; ++i) {
			goodPrice += EXTRA_LAYERS;
		}
	}
	if (frostingType == "cream-cheese") {
		goodPrice += (numLayers * CREAM_CHEESE_FROSTING);
	}
	std::string theString = std::to_string(numLayers) + "-layer " + cakeFlavor + " cake with " + frostingType + " frosting ($" + std::to_string(goodPrice) + ")";
	return theString;
}

double LayerCake::DiscountedPrice(int theQuantity) {
	double layercakePrice = goodPrice * theQuantity;
	if (theQuantity >= 3) {
		layercakePrice -= (theQuantity * LAYER_CAKE_DISCOUNT);
	}
	return layercakePrice;
}
