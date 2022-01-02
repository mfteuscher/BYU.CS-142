#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include "BakedGood.h"
#include "Bread.h"
#include "Cake.h"
#include "CupCake.h"
#include "LayerCake.h"
using namespace std;

bool Find(vector<string> myInvoice, string toFind) {
	bool isPresent = false;
	for (unsigned int i = 0; i < myInvoice.size(); ++i) {
		if (myInvoice.at(i) == toFind) {
			isPresent = true;
			break;
		}
	}
	return isPresent;
} 

int Count(vector<BakedGood*> myOrder, string toFind) {
	int quantityCount = 0; 
	for (unsigned int i = 0; i < myOrder.size(); ++i) {
		if (myOrder.at(i)->ToString() == toFind) {
			quantityCount += 1;
		}
	}
	return quantityCount;
}

int main() {
	vector<BakedGood*> myOrder;
	vector<string> myInvoice;
	vector<int> myQuantities;
	vector<int> invoicePositions;
	string goodType;
	string breadType;
	string cakeFlavor;
	string cakeFrosting;
	int numLayers;
	string colorSprinkles;
	int goodQuantity;
	int totalQuantity = 0;
	double totalPrice = 0.00;

	cout << "**Bread and Cakes Bakery**" << endl << endl;

	cout << "Enter sub-order (enter \"done\" to finish)" << endl;

	cout << "Sub-order: ";
	cin >> goodType;

	do {
		if (goodType == "Bread") {
			cin >> breadType;
			cin >> goodQuantity;
			for (int i = 0; i < goodQuantity; ++i) {
				myOrder.push_back(new Bread(breadType));
			}
		}
		else {
			cin >> cakeFlavor;
			cin >> cakeFrosting;
			if (goodType == "Cupcake") {
				cin >> colorSprinkles;
				cin >> goodQuantity;
				for (int i = 0; i < goodQuantity; ++i) {
					myOrder.push_back(new CupCake(cakeFlavor, cakeFrosting, colorSprinkles));
				}

			}
			else if (goodType == "Layer-cake") {
				cin >> numLayers;
				cin >> goodQuantity;
				for (int i = 0; i < goodQuantity; ++i) {
					myOrder.push_back(new LayerCake(cakeFlavor, cakeFrosting, numLayers));
				}
			}
		}
		cout << "Sub-order: ";
		cin >> goodType;
	} while (goodType != "done");

	cout << endl << "Order Confirmations:" << endl;

	for (unsigned int i = 0; i < myOrder.size(); ++i) {
		cout << myOrder.at(i)->ToString() << endl;
	}

	cout << endl << "Invoice:" << endl;
	cout << "Baked Good" << setw(75) << "Quantity" << setw(9) << "Total" << fixed << setprecision(2) << endl;


	for (unsigned int i = 0; i < myOrder.size(); ++i) {
		if (Find(myInvoice, myOrder.at(i)->ToString()) != true) {
			myInvoice.push_back(myOrder.at(i)->ToString());
			myQuantities.push_back(Count(myOrder, myOrder.at(i)->ToString()));
			invoicePositions.push_back(i);
		}
	}

	for (unsigned int i = 0; i < myInvoice.size(); ++i) {
		cout << myInvoice.at(i) << setw(85 - myInvoice.at(i).size()) << myQuantities.at(i)
			<< setw(9) << myOrder.at(invoicePositions.at(i))->DiscountedPrice(myQuantities.at(i)) << endl;
		totalQuantity += myQuantities.at(i);
		totalPrice += myOrder.at(invoicePositions.at(i))->DiscountedPrice(myQuantities.at(i));
	}

	cout << "Totals" << setw(78) << totalQuantity << setw(9) << totalPrice << endl;

	cout << "Good Bye" << endl;

	return 0;
}

