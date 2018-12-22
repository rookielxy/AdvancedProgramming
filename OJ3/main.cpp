#include<iostream>
#include"RecurveList.h"

using namespace std;

int main() {
	List test;
	int finished;

	cin >> finished;			//输入建表结束标志数据 
	test.NewList(finished);		//建立链表
	cout << "The List is :" << endl;
	test.PrintList();			//打印链表
	cout << endl;
	cout << "The Max is : " << test.GetMax() << endl;
	cout << "The Num is : " << test.GetNum() << endl;
	cout << "The Ave is : " << test.GetAvg() << endl;

	return 0;
}