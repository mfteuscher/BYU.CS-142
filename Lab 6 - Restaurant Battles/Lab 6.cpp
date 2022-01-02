#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

void DisplayAllResturaunts(vector<string>& allResturants) {
	for (int i = 0; i < allResturants.size(); ++i) {
		cout << "\t" << allResturants.at(i) << endl;;
	}
	cout << endl;

	return;
}





bool FindRestaurant(vector<string>& allResturants, string toFind) {
	bool inVector = false;

	for (int i = 0; i < allResturants.size(); ++i) {
		if (allResturants.at(i) == toFind) {
			inVector = true;
			break;
		}
	}
	return inVector;
}





vector<string> AddNewResturaunt(vector<string>& allResturants) {
	string newRestaurant;
	bool inVector;

	cout << "What is the name of the restaurant you want to add?" << endl;
	getline(cin, newRestaurant);

	inVector = FindRestaurant(allResturants, newRestaurant);
	if (inVector == true) {
		cout << "That restaurant is already in the list, you can not add it again." << endl << endl;
	}
	else {
		allResturants.push_back(newRestaurant);
		cout << newRestaurant << " has been added." << endl << endl;
	}

	return allResturants;
}





vector<string> RemoveResturaunt(vector<string>& allResturants) {
	string restaurantToRemove;
	bool inVector;

	cout << "What is the name of the restaurant you want to remove?" << endl;
	getline(cin, restaurantToRemove);

	inVector = FindRestaurant(allResturants, restaurantToRemove);
	if (inVector == true) {
		for (int i = 0; i < allResturants.size(); ++i) {
			if (allResturants.at(i) == restaurantToRemove) {
				allResturants.erase(allResturants.begin() + i);
				break;
			}
		}
		cout << restaurantToRemove << " has been removed," << endl << endl;
	}

	else {
		cout << "That restaurant is not in the list, you can not remove it." << endl << endl;
	}

	return allResturants;
}





vector<string> CutRestaurants(vector<string>& allRestaurants) {
	int cutNum;
	const vector<string> allRestaurantsOld = allRestaurants;

	do {
		cout << "How many restaurants should be taken from the top and put on the bottom? ";
		cin >> cutNum;

		if (cutNum <= 0 || cutNum > allRestaurants.size()) {
			cout << "The cut number must be between 0 and " << allRestaurants.size() << endl;
		}
	} while (cutNum <= 0 || cutNum > allRestaurants.size());

	cout << endl << endl;

	for (int i = 0; i < allRestaurants.size(); ++i) {
		allRestaurants.at(i) = allRestaurantsOld.at((i + cutNum) % allRestaurants.size());
	}

	return allRestaurants;
}






bool PowerOfTwo(int numberToCheck) {
	bool powerOf2 = false;

	for (int i = 0; i < numberToCheck; ++i) {
		if (numberToCheck == pow(2, i)) {
			powerOf2 = true;
			break;
		}
	}

	return powerOf2;
}


vector<string> ShuffleRestaurants(vector<string>& allRestaurants) {
	vector<string> firstHalf = allRestaurants;
	vector<string> secondHalf = allRestaurants;
	bool powerOf2;
	int numOfRestaurants = static_cast<int>(allRestaurants.size());
	int j = 0;

	powerOf2 = PowerOfTwo(numOfRestaurants);


	if (powerOf2 == true) {
		for (int i = 0; i < (numOfRestaurants / 2); ++i) {
			firstHalf.pop_back();
		}
		for (int i = 0; i < (numOfRestaurants / 2); ++i) {
			secondHalf.erase(secondHalf.begin());
		}

		for (int i = 0; i < firstHalf.size(); ++i) {
			cout << firstHalf.at(i) << " ";
		}
		cout << endl;
		for (int i = 0; i < secondHalf.size(); ++i) {
			cout << secondHalf.at(i) << " ";
		}
		cout << endl;

		for (int i = 0; i < (numOfRestaurants / 2); ++i) {
			allRestaurants.at(j) = secondHalf.at(i);
			allRestaurants.at(j + 1) = firstHalf.at(i);
			j += 2;
		}
	}
	else {
		cout << "The current tournament size (" << allRestaurants.size() << ") is not a power of two (2, 4, 8...)." << endl;
		cout << "A shuffle is not possible. Please add or remove restaurants." << endl;
	}

	return allRestaurants;
}


void RestaurantBattle(vector<string> allRestaurants) {
	bool powerOf2;
	int victorSelect;
	vector<string> tournyRestaurants = allRestaurants;
	vector<int> theLosers;
	int roundNum = 0;
	int numRestaurants = static_cast<int>(allRestaurants.size());
	int i;
	int k = 0;

	powerOf2 = PowerOfTwo(static_cast<int>(allRestaurants.size()));

	if (powerOf2 == true) {
		while (numRestaurants != 1) {
			cout << numRestaurants << endl;
			roundNum += 1;
			cout << "Round: " << roundNum << endl;
			i = 0;
			for (i = 0; i < numRestaurants; i += 2) {
				do {
					cout << "Type \"1\" if you prefer " << tournyRestaurants.at(i) << " or" << endl;
					cout << "type \"2\" if you prefer " << tournyRestaurants.at(i + 1) << endl;
					cout << "Choice: ";
					cin >> victorSelect;

					if (victorSelect == 1 || victorSelect == 2) {
						break;
					}
					else {
						cout << "Invalid selection" << endl;
					}
				} while (victorSelect != 1 || victorSelect != 2);

				if (victorSelect == 1) {
					cout << i << endl;
					theLosers.push_back(i + 1);
					cout << "Delete position 1: " << theLosers.at(k) << endl;
				}
				else {
					theLosers.push_back(i);
					cout << "Delete position 2: " << theLosers.at(k) << endl;
				}
				++k;
			}
			for (int j = 0; j < (numRestaurants / 2); ++j) {
				tournyRestaurants.erase(tournyRestaurants.begin() + theLosers.at(0));
				theLosers.erase(theLosers.begin());
			}
			numRestaurants /= 2;
		}
		//cout << "The winning restaurant is " << tournyRestaurants.at(0) << endl;
	}
	else {
		cout << "The current tournament size (" << allRestaurants.size() << ") is not a power of two (2, 4, 8...)" << endl;
		cout << "A battle is not possible. Please add or remove restaurants." << endl;
	}
	cout << numRestaurants << endl;
	for (int m = 0; m < theLosers.size(); ++m) {
		cout << theLosers.at(m) << " ";
	}
	cout << endl;
	for (int m = 0; m < tournyRestaurants.size(); ++m) {
		cout << tournyRestaurants.at(m) << " ";
	}
	cout << endl;
}



int main() {
	vector<string> allResturants;
	string optionSelect;

	cout << "Welcome to the restauraunt battle! Enter \"options\" to see options." << endl << endl;
	cout << "Enter your selection: ";
	cin >> optionSelect;
	cin.ignore();
	cout << endl;

	while (optionSelect != "quit") {
		if (optionSelect == "options") {
			cout << "quit - Quit the program" << endl;
			cout << "display - Display all restaurants" << endl;
			cout << "add - Add a restauraunt" << endl;
			cout << "remove - Remove a restauraunt" << endl;
			cout << "cut - \"Cut\" the list of restaurants" << endl;
			cout << "shuffle - \"Shuffle\" the list of restauraunts" << endl;
			cout << "battle - Begin the tournament" << endl;
			cout << "options - Print the options menu" << endl << endl;
		}
		else if (optionSelect == "display") {
			DisplayAllResturaunts(allResturants);
		}
		else if (optionSelect == "add") {
			AddNewResturaunt(allResturants);
		}
		else if (optionSelect == "remove") {
			RemoveResturaunt(allResturants);
		}
		else if (optionSelect == "cut") {
			CutRestaurants(allResturants);
		}
		else if (optionSelect == "shuffle") {
			ShuffleRestaurants(allResturants);
		}
		else if (optionSelect == "battle") {
			RestaurantBattle(allResturants);
		}
		else {
			cout << "Invalid Selection" << endl << endl;;
		}


		cout << "Enter your selection: ";
		cin >> optionSelect;
		cin.ignore();
		cout << endl;
	}


	return 0;
}
