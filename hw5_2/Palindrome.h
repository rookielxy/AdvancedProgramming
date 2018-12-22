#ifndef HW5_2_PALINDROME_H
#define HW5_2_PALINDROME_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstring>
#include <cassert>

using namespace std;

class Palindrome {
	int number;
public:
	Palindrome() { number = 0; }
	int GetOddNumber(string filename);
	bool IsOddNumberPalindrome();
	static int reverseInt(int n);
};

int Palindrome::GetOddNumber(string filename) {
	ifstream inFile(filename, ios::in|ios::binary);
	if (inFile.fail())
		assert(false);
	inFile.seekg(0, ios::end);
	long length = inFile.tellg();
	inFile.seekg(0, ios::beg);
	char sign;
	inFile.read(&sign, 1);
	int *buffer;
	int buflen;
	if (sign == '+' or sign == '-') {
		buflen = (int)(length - 1)/4;
		buffer = new int[buflen];
		inFile.read((char*)buffer, buflen*sizeof(int));
	} else {
		sign = '+';
		buflen = (int)length/4;
		buffer = new int[buflen];
		inFile.seekg(0, ios::beg);
		inFile.read((char*)buffer, buflen*sizeof(int));
	}

	string temp;
	temp += sign;
	int idx = 0;
	while (idx < buflen) {
		temp += to_string(buffer[idx]);
		idx += 2;
	}
	stringstream ss;
	ss << temp;
	ss >> number;

	return number;
}

bool Palindrome::IsOddNumberPalindrome() {
	if (number < 0)
		return false;
	return number == reverseInt(number);
}

int Palindrome::reverseInt(int n) {
	int rn = 0;
	while (n > 0) {
		rn = rn*10 + n%10;
		n /= 10;
	}
	return rn;
}

#endif
