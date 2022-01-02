#include <iostream>
#include <vector>
#include <iomanip>
#include <fstream>
using namespace std;

int main() {
	const int PLATE_LENGTH = 5;
	const int PLATE_WIDTH = 5;
	double PlateTemperature[PLATE_LENGTH][PLATE_WIDTH];
	double PlateTemperature2[PLATE_LENGTH][PLATE_WIDTH];
	bool isStable = false;
	ofstream outFS;
	ifstream inFS;
	int i;
	int j;

	cout << "Hotplate simulator" << endl << endl;

	
	//Part 1
	for (i = 0; i < PLATE_LENGTH; ++i) {
		for (j = 0; j < PLATE_WIDTH; ++j) {
			if (i == 0 || i == (PLATE_LENGTH - 1)) {
				if (j == 0 || j == (PLATE_WIDTH - 1)) {
					PlateTemperature[i][j] = 0.000;
				}
				else {
					PlateTemperature[i][j] = 100.000;
				}
			}
			else {
				PlateTemperature[i][j] = 0.000;
			}
		}
	}

	cout << "Printing initial plate..." << endl;
	for (i = 0; i < PLATE_LENGTH; ++i) {
		cout << "    ";
		for (j = 0; j < (PLATE_WIDTH - 1); ++j) {
			cout << fixed << setprecision(3) << PlateTemperature[i][j];
			if (PlateTemperature[i][j + 1] > 99.999) {
				cout << ",  ";
			}
			else if (PlateTemperature[i][j + 1] > 9.999) {
				cout << ",   ";
			}
			else {
				cout << ",    ";
			}
		}
		cout << fixed << setprecision(3) << PlateTemperature[i][PLATE_WIDTH - 1] << endl;
	}

	cout << endl << endl;

	//Part 2

	for (i = 0; i < PLATE_LENGTH; ++i) {
		for (j = 0; j < PLATE_WIDTH; ++j) {
			PlateTemperature2[i][j] = PlateTemperature[i][j];
		}
	}

	for (i = 1; i < (PLATE_LENGTH - 1); ++i) {
		for (j = 1; j < (PLATE_WIDTH - 1); ++j) {
			PlateTemperature[i][j] = (PlateTemperature2[i + 1][j] + PlateTemperature2[i][j + 1] + PlateTemperature2[i - 1][j] + PlateTemperature2[i][j - 1]) / 4;
		}
	}

	cout << "Printing plate after one iteration..." << endl;
	for (i = 0; i < PLATE_LENGTH; ++i) {
		cout << "    ";
		for (j = 0; j < (PLATE_WIDTH - 1); ++j) {
			cout << fixed << setprecision(3) << PlateTemperature[i][j];
			if (PlateTemperature[i][j + 1] > 99.999) {
				cout << ",  ";
			}
			else if (PlateTemperature[i][j + 1] > 9.999) {
				cout << ",   ";
			}
			else {
				cout << ",    ";
			}
		}
		cout << fixed << setprecision(3) << PlateTemperature[i][PLATE_WIDTH - 1] << endl;
	}
	cout << endl << endl;

	//Part 3

	while (isStable == false) {
		for (i = 1; i < (PLATE_LENGTH - 1); ++i) {
			for (j = 1; j < (PLATE_WIDTH - 1); ++j) {
				if (PlateTemperature2[i][j] > (PlateTemperature[i][j] + .1) || PlateTemperature2[i][j] < (PlateTemperature[i][j] - .1)) {
					isStable = false;
					break;
				}
				else {
					isStable = true;
				}
			}
			if (isStable == false) {
				break;
			}

		}
		if (isStable == false) {
			//Save Array
			for (i = 0; i < PLATE_LENGTH; ++i) {
				for (j = 0; j < PLATE_WIDTH; ++j) {
					PlateTemperature2[i][j] = PlateTemperature[i][j];
				}
			}
			//Iterate New Array
			for (i = 1; i < (PLATE_LENGTH - 1); ++i) {
				for (j = 1; j < (PLATE_WIDTH - 1); ++j) {
					PlateTemperature[i][j] = (PlateTemperature2[i + 1][j] + PlateTemperature2[i][j + 1] + PlateTemperature2[i - 1][j] + PlateTemperature2[i][j - 1]) / 4;
				}
			}
		}
	}

	cout << "Printing final plate..." << endl;
	
	for (i = 0; i < PLATE_LENGTH; ++i) {
		cout << "    ";
		for (j = 0; j < (PLATE_WIDTH - 1); ++j) {
			cout << fixed << setprecision(3) << PlateTemperature[i][j];
			if (PlateTemperature[i][j + 1] > 99.999) {
				cout << ",  ";
			}
			else if (PlateTemperature[i][j + 1] > 9.999) {
				cout << ",   ";
			}
			else {
				cout << ",    ";
			}
		}
		cout << fixed << setprecision(3) << PlateTemperature[i][PLATE_WIDTH - 1] << endl;
	}
	
	cout << endl;

	//Part 4
	outFS.open("Hotplate.csv");

	if (!outFS.is_open()) {
		cout << "Could not open file Hotplate.csv." << endl;
		return 1;
	}

	cout << "Outputting final plate to file \"Hotplate.csv\"..." << endl;

	for (i = 0; i < PLATE_LENGTH; ++i) {
		outFS << "    ";
		for (j = 0; j < (PLATE_WIDTH - 1); ++j) {
			outFS << fixed << setprecision(3) << PlateTemperature[i][j];
			if (PlateTemperature[i][j + 1] > 99.999) {
				outFS << ",  ";
			}
			else if (PlateTemperature[i][j + 1] > 9.999) {
				outFS << ",   ";
			}
			else {
				outFS << ",    ";
			}
		}
		outFS << fixed << setprecision(3) << PlateTemperature[i][PLATE_WIDTH - 1] << endl;
	}

	cout << endl;

	//Part 5
	inFS.open("Inputplate.txt");

	if (!inFS.is_open()) {
		cout << "Could not open file Inputplate.txt." << endl;
		return 1; 
	}

	for (i = 0; i < PLATE_LENGTH; ++i) {
		for (j = 0; j < PLATE_WIDTH; ++j) {
			inFS >> PlateTemperature[i][j];
		}
	}

	inFS.close();

	for (int k = 0; k < 3; ++k) {
		for (i = 1; i < (PLATE_LENGTH - 1); ++i) {
			for (j = 1; j < (PLATE_WIDTH - 1); ++j) {
				if (PlateTemperature2[i][j] > (PlateTemperature[i][j] + .1) || PlateTemperature2[i][j] < (PlateTemperature[i][j] - .1)) {
					isStable = false;
					break;
				}
				else {
					isStable = true;
				}
			}
			if (isStable == false) {
				break;
			}

		}
		if (isStable == false) {
			//Save Array
			for (i = 0; i < PLATE_LENGTH; ++i) {
				for (j = 0; j < PLATE_WIDTH; ++j) {
					PlateTemperature2[i][j] = PlateTemperature[i][j];
				}
			}
			//Iterate New Array
			for (i = 1; i < (PLATE_LENGTH - 1); ++i) {
				for (j = 1; j < (PLATE_WIDTH - 1); ++j) {
					PlateTemperature[i][j] = (PlateTemperature2[i + 1][j] + PlateTemperature2[i][j + 1] + PlateTemperature2[i - 1][j] + PlateTemperature2[i][j - 1]) / 4;
				}
			}
		}
	}

	cout << "Printing input plate after 3 updates..." << endl;

	for (i = 0; i < PLATE_LENGTH; ++i) {
		cout << "    ";
		for (j = 0; j < (PLATE_WIDTH - 1); ++j) {
			cout << fixed << setprecision(3) << PlateTemperature[i][j];
			if (PlateTemperature[i][j + 1] > 99.999) {
				cout << ",  ";
			}
			else if (PlateTemperature[i][j + 1] > 9.999) {
				cout << ",   ";
			}
			else {
				cout << ",    ";
			}
		}
		cout << fixed << setprecision(3) << PlateTemperature[i][PLATE_WIDTH - 1] << endl;
	}



	return 0;
}
