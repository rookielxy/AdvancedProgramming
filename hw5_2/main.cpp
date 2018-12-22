#include <iostream>
#include <fstream>
#include "Palindrome.h"

using namespace std;

int main() {
	Palindrome pa;
	cout << pa.GetOddNumber("../4.txt") << endl;
	cout << pa.IsOddNumberPalindrome() << endl;
	return 0;
}