#include<iostream>
#include<cmath>
#include<cstdlib>
#include<ios>
#include<iomanip>
using namespace std;

int main() {

	const double SLOT_ZERO = 100;
	const double SLOT_ONE = 500;
	const double SLOT_TWO = 1000;
	const double SLOT_THREE = 0;
	const double SLOT_FOUR = 10000;
	int menuSelect;
	double slotValue;
	double dropValue;
	int startingSlot;
	int numChips;
	double totalWinnings = 0.0;
	const int RANDOM_SEED = 42;
	srand(RANDOM_SEED);

	//Part 1
	cout << "Welcome to the Plinko simulator! Enter 3 to see options." << endl << endl << "Enter your selection now: ";
	cin >> menuSelect;

	while (menuSelect != 4) {
		//Part 2
		if (menuSelect == 1) {
			cout << endl << "*** Drop a single chip ***" << endl << endl;
			cout << "Which slot do you want to drop the chip in (0-8)? ";
			cin >> slotValue;

			if ((slotValue >= 0) && (slotValue <= 8)) {
				cout << fixed << endl << "*** Dropping chip into slot " << static_cast<int>(slotValue) << " ***" << endl;
				cout << "Path: [" << setprecision(1) << slotValue << ", ";
				for (int i = 0; i < 11; ++i) {
					if (slotValue == 0) {
						slotValue = slotValue + 0.5;
						cout << setprecision(1) << slotValue << ", ";
					}
					else if (slotValue == 8) {
						slotValue = slotValue - 0.5;
						cout << setprecision(1) << slotValue << ", ";
					}
					else {
						dropValue = rand() % 2;
						if (dropValue == 0) {
							slotValue = slotValue - 0.5;
							cout << setprecision(1) << slotValue << ", ";
						}
						else if (dropValue == 1) {
							slotValue = slotValue + 0.5;
							cout << setprecision(1) << slotValue << ", ";
						}
					}
				}
				if (slotValue == 0) {
					slotValue = slotValue + 0.5;
					cout << setprecision(1) << slotValue << "]" << endl;
				}
				else if (slotValue == 8) {
					slotValue = slotValue - 0.5;
					cout << setprecision(1) << slotValue << "]" << endl;
				}
				else {
					dropValue = rand() % 2;
					if (dropValue == 0) {
						slotValue = slotValue - 0.5;
						cout << setprecision(1) << slotValue << "]" << endl;
					}
					else if (dropValue == 1) {
						slotValue = slotValue + 0.5;
						cout << setprecision(1) << slotValue << "]" << endl;
					}
				}
				cout << "Winnings: $";

				if ((slotValue == 0) || (slotValue == 8)) {
					cout << setprecision(2) << SLOT_ZERO << endl;
				}
				else if ((slotValue == 1) || (slotValue == 7)) {
					cout << setprecision(2) << SLOT_ONE << endl;
				}
				else if ((slotValue == 2) || (slotValue == 6)) {
					cout << setprecision(2) << SLOT_TWO << endl;
				}
				else if ((slotValue == 3) || (slotValue == 5)) {
					cout << setprecision(2) << SLOT_THREE << endl;
				}
				else {
					cout << setprecision(2) << SLOT_FOUR << endl;
				}
			}
			else {
				cout << endl << "Invalid slot." << endl;
			}
		}

		//Part 3
		else if (menuSelect == 2) {
			cout << endl << "*** Drop multiple chips ***" << endl << endl;
			cout << "How many chips do you want to drop(> 0) ? ";
			cin >> numChips;
			if (numChips > 0) {
				cout << endl << "Which slot do you want to drop the chip in (0-8)? ";
				cin >> startingSlot;
				slotValue = startingSlot;
				totalWinnings = 0;

				if ((startingSlot >= 0) && (startingSlot <= 8)) {
					for (int i = 0; i < numChips; ++i) {
						slotValue = startingSlot;
						for (int j = 0; j < 12; ++j) {
							if (slotValue == 0) {
								slotValue = slotValue + 0.5;
							}
							else if (slotValue == 8) {
								slotValue = slotValue - 0.5;
							}
							else {
								dropValue = rand() % 2;
								if (dropValue == 0) {
									slotValue = slotValue - 0.5;
								}
								else if (dropValue == 1) {
									slotValue = slotValue + 0.5;
								}
							}
						}
						if ((slotValue == 0) || (slotValue == 8)) {
							totalWinnings = totalWinnings + SLOT_ZERO;
						}
						else if ((slotValue == 1) || (slotValue == 7)) {
							totalWinnings = totalWinnings + SLOT_ONE;
						}
						else if ((slotValue == 2) || (slotValue == 6)) {
							totalWinnings = totalWinnings + SLOT_TWO;
						}
						else if ((slotValue == 3) || (slotValue == 5)) {
							totalWinnings = totalWinnings + SLOT_THREE;
						}
						else {
							totalWinnings = totalWinnings + SLOT_FOUR;
						}
					}
					cout << endl << "Total winnings on " << numChips << " chips: $" << fixed << setprecision(2) << totalWinnings << endl;
					cout << "Average winnings per chip: $" << setprecision(2) << (totalWinnings / numChips) << endl;
				}
				else {
					cout << endl << "Invalid slot." << endl;
				}
			}
			else {
				cout << endl << "Invalid number of chips." << endl;
			}
		}
		else if (menuSelect == 3) {
			cout << endl << "Menu: Please select one of the following options:" << endl << endl;
			cout << "1 - Drop a single chip into one slot" << endl;
			cout << "2 - Drop multiple chips into one slot" << endl;
			cout << "3 - Show the options menu" << endl;
			cout << "4 - Quit the program" << endl << endl;
		}
		else if ((menuSelect < 1) || (menuSelect > 4)) {
			cout << endl << "Invalid selection.  Enter 3 to see options." << endl;
		}

		cout << endl << "Enter your selection now: ";
		cin >> menuSelect;
	}

	cout << endl << "Goodbye!";

	return 0;
}