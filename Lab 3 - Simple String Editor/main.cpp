#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main() {
	string userInput;
	char makeSentence;
	string firstLetter;
	char insertText;
	string addedText;
	int textPosition;


	string copyFind;
	string findSub;
	string findOptions;
	string replaceText;
	int copyLength;
	int copyPosition;
	int pastePosition;


	cout << "Welcome to the Simple Editor. Enter a string to be edited:" << endl;				//Part 1
	getline(cin, userInput);
	cout << userInput << endl << endl;

	cout << "Do you want to make this string a sentence (y/n)?" << endl;							//Part 2
	cin >> makeSentence;
	cin.ignore();
	if (makeSentence == 'y') {
		firstLetter = toupper(userInput.at(0));
		userInput.replace(0, 1, firstLetter);
		if (userInput.find('.') == string::npos && userInput.find('?') == string::npos && userInput.find('!') == string::npos) {
			userInput.append(".");
		}
		cout << userInput << endl;
	}

	cout << "Do you want to insert more text into your current text (y/n)?" << endl;				//Part 3
	cin >> insertText;
	cin.ignore();
	if (insertText == 'y') {
		cout << "Enter text to be inserted: " << endl;
		getline(cin, addedText);
		cout << "Enter position where text is to be inserted: " << endl;
		cin >> textPosition;
		cin.ignore();
		if (textPosition <= userInput.size()) {
			userInput.insert(textPosition, addedText);
			cout << userInput << endl;
		}
		else {
			cout << "No change made. Position must be non-negative and not exceed " << userInput.size() << ", the length of the current text." << endl;
		}
	}


	cout << "If you would like to find/replace or copy/paste, enter find or copy: " << endl;				//Part 4
	cin >> copyFind;
	cin.ignore();
	if (copyFind == "copy" || copyFind == "find") {
		if (copyFind == "find") {																//Find function starts here
			cout << "Enter substring to find: " << endl;
			cin >> findSub;
			cin.ignore();
			cout << "Do you want to find if/where the substring occurs, delete it, or replace it (find, delete, replace)? " << endl;
			cin >> findOptions;
			cin.ignore();
			if (findOptions == "find") {													//Find word
				if (userInput.find(findSub) >= 0 && userInput.find(findSub) < 100) {
					cout << findSub << " was found at position " << userInput.find(findSub) << "." << endl;
				}
				else if (userInput.find(findSub) == string::npos) {
					cout << findSub << " was not found." << endl;
				}
			}
			else if (findOptions == "delete") {												//Delete word
				if (userInput.find(findSub) >= 0 && userInput.find(findSub) < 100) {
					userInput.replace(userInput.find(findSub), findSub.size(), "");
				}
				else if (userInput.find(findSub) == string::npos) {
					cout << findSub << " was not found. No change made." << endl;
				}
			}
			else if (findOptions == "replace") {											//Replace word
				if (userInput.find(findSub) == string::npos) {
					cout << findSub << " was not found. No change made." << endl;
				}
				else if (userInput.find(findSub) >= 0 && userInput.find(findSub) < 100) {
					cout << "Enter replacement string: " << endl;
					getline(cin, replaceText);
					userInput.replace(userInput.find(findSub), findSub.size(), replaceText);
				}
			}
		}
		else if (copyFind == "copy") {															//Copy function starts here
			cout << "Enter position and length of text to be copied, and position for paste: " << endl;
			cin >> copyPosition;
			cin >> copyLength;
			cin >> pastePosition;
			if ((copyLength + copyPosition) > userInput.size() || copyPosition > userInput.size() || pastePosition > userInput.size()) {
				cout << "Values entered do not support copy/paste." << endl;
			}
			else {
				userInput.insert(pastePosition, userInput.substr(copyPosition, copyLength));
			}
		}
	}


	cout << "Final text is " << userInput << endl;



	return 0;
}