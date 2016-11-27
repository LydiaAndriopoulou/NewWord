#include "stdafx.h"
#include <iostream>
#include <string>
#include <sstream>
#include <ctype.h>

using namespace std;

const char SPACE = ' ';
const char DOT = '.';
const char BANG = '!';

string capitilise_words_after_stopping_points(string document) {
	string new_document;
	for (int i = 0; i < document.size(); i++) {
		char character = document[i];
		new_document.push_back(character);
		if (character == DOT || character == BANG) {
			i++;
			character = document[i];
			if (character == SPACE) {
				new_document.push_back(character);
				i++;
				character = document[i];
				new_document.push_back(toupper(character));
			}
		}
	}
	return new_document;
}

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
	document = remove_extra_spaces(document);
	document = capitilise_words_after_stopping_points(document);
	cout << document << endl;
}