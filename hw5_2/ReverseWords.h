#ifndef HW5_2_REVERSEWORDS_H
#define HW5_2_REVERSEWORDS_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <string>
#include <cassert>

using namespace std;


class ReverseWords {
	string str;
public:
	string getSentence(string filename);
	string reverseString();
};


string ReverseWords::getSentence(string filename) {
	ifstream inFile(filename, ios::in);
	if (inFile.fail())
		assert(false);
	getline(inFile, str);
	inFile.close();
	return str;
}

string ReverseWords::reverseString() {
	string ret, temp;
	stringstream ss;
	ss << str;
	while (ss >> temp) {
		reverse(temp.begin(), temp.end());
		ret += temp + " ";
	}
	return ret;
}

#endif
