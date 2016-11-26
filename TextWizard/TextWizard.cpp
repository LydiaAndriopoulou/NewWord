#include "stdafx.h"
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

const char SPACE = ' ';

string remove_extra_spaces(string document) {
	string new_document;
	for (int i = 0; i < document.size(); i++) {
		char character = document[i];
		if (character == SPACE) {
			new_document.push_back(character);
			while (character == SPACE) {
				i++;
				character = document[i];
			}
		}
		new_document.push_back(character);
	}
	return new_document;
}


int main() {
	string document;
	getline(cin, document);
	cout << remove_extra_spaces(document);
}