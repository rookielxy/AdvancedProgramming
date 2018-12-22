#ifndef OJ6_MYEXCEPTION_H
#define OJ6_MYEXCEPTION_H

#include <string>
#include <iostream>
#include <cstdlib>
#include <climits>

using namespace std;

class MyException{

public:
	explicit MyException(string s) { emeg = s;}
	string myMeg() { return emeg; }
private:
	string emeg;
};

class OutOfBound : public MyException {//越界异常
public:
	explicit OutOfBound(string s) : MyException(s) {}
};

class NullPointer : public MyException {//空指针异常
public:
	explicit NullPointer(string s) : MyException(s) {}
};

class ArithmeticeError : public MyException {//算术运算异常
public:
	explicit ArithmeticeError(string s) : MyException(s) {}
};

class MemoryLeak : public MyException {//内存泄漏异常
public:
	explicit MemoryLeak(string s):MyException(s) {}
};

class Overflow : public MyException{//溢出异常
public:
	explicit Overflow(string s):MyException(s) {}
};

#endif
