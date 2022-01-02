#include <iostream>
#include <cmath>
#include <math.h>
using namespace std;

int main ()  {

    const double PI = 3.14159265;
    int numGuests;
    int numLarge;
    int numMedium;
    int numSmall;
    const int numLargeFed = 9;
    const int numMediumFed = 5;
    const int numSmallFed = 2;
    const int radiusLarge = 12;
    const int radiusMedium = 9;
    const int radiusSmall = 7;
    double totalArea;
    double areaPerGuest;
    int tipPercent;
    const double priceLarge = 15.78;
    const double priceMedium = 13.25;
    const double priceSmall = 8.39;
    double subtotalCost;
    double totalCost;

    cout << "Please enter the number of guests: ";
    cin  >> numGuests;
    cout << endl;

    numLarge = numGuests / numLargeFed;
    numMedium = (numGuests % numLargeFed) / numMediumFed;
    numSmall = ((numGuests % numLargeFed) % numMediumFed) / numSmallFed;

    cout << numLarge << " large pizzas, " << numMedium << " medium pizzas, and " << numSmall << " small pizzas will be needed." << endl << endl;

    totalArea = ( numLarge * (PI * pow( radiusLarge, 2 ))) + ( numMedium * (PI * pow( radiusMedium, 2 ))) + ( numSmall * (PI * pow( radiusSmall, 2 )));
    areaPerGuest = totalArea / numGuests;

    cout << "A total of " << totalArea << " square inches of pizza will be purchased (" << areaPerGuest << " per guest)." << endl << endl;

    cout << "Please enter the tip as a percentage (i.e. 10 means 10%): ";
    cin  >> tipPercent;
    cout << endl;

    subtotalCost = (numLarge * priceLarge) + (numMedium * priceMedium) + (numSmall * priceSmall);
    totalCost = subtotalCost + (subtotalCost * (static_cast<double>(tipPercent) / 100));

    cout << "The total cost of the event will be: $" << round(totalCost) << endl;


    return 0;
}