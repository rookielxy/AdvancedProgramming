#ifndef OJ6_LINEARLIST_H
#define OJ6_LINEARLIST_H

#include "MyException.h"

struct Node{
	Node *next; int value;
	explicit Node(int v) { value = v; next = nullptr;}
	~Node() { next = nullptr; }

};

struct List{
	Node* root;
	List() { root = nullptr; }
	~List() = default;
};

class LinearList{
public:
	static void Creation(List *&list) {
		//创建一个空的链表
		if(list != nullptr) throw MemoryLeak("MemoryLeak:Creation()");
		list = new List();
	}

	static void Insert(int index,List *list,int value) {
		//实现该方法，向list的第index个位置插入value
		//需要考虑的异常情况:list==NULL，越界
		if (list == nullptr)
			throw NullPointer("NullPointer:Insert()");
		if (index < 0)
			throw OutOfBound("OutOfBound:Insert(),index=" + to_string(index));
		int count = 0;
		Node *ptr = list->root;
		if (index == 0) {
			Node *nxt = list->root;
			list->root = new Node(value);
			list->root->next = nxt;
			return;
		}

		while (ptr != nullptr and count < index - 1) {
			++count;
			ptr = ptr->next;
		}

		if (ptr == nullptr)
			throw OutOfBound("OutOfBound:Insert(),index=" + to_string(index));

		Node *nxt = ptr->next;
		ptr->next = new Node(value);
		ptr->next->next = nxt;
	}

	static int Get(int index,List *list) {
		// 实现该方法，获取list的第index个位置的值并返回
		// 需要考虑的异常情况:list==NULL，越界
		if (list == nullptr)
			throw NullPointer("NullPointer:Get()");
		if (index < 0)
			throw OutOfBound("OutOfBound:Get(),index=" + to_string(index));
		int count = 0;
		Node *ptr = list->root;

		while (ptr != nullptr and count < index) {
			++count;
			ptr = ptr->next;
		}
		if (ptr == nullptr)
			throw OutOfBound("OutOfBound:Get(),index=" + to_string(index));
		return ptr->value;
	}

	static int Remove(int index,List *list) {
		// 实现该方法，移除list的第index个位置并返回对应的值
		// 需要考虑的异常情况:list==NULL，越界
		if (list == nullptr)
			throw NullPointer("NullPointer:Remove()");
		if (index < 0 or list->root == nullptr)
			throw OutOfBound("OutOfBound:Remove(),index=" + to_string(index));
		int count = 0;
		Node *ptr = list->root, *pre = ptr;
		if (index == 0) {
			int value = list->root->value;
			list->root = list->root->next;
			return value;
		}

		while (ptr != nullptr and count < index) {
			++count;
			pre = ptr;
			ptr = ptr->next;
		}
		if (ptr == nullptr)
			throw OutOfBound("OutOfBound:Remove(),index=" + to_string(index));
		pre->next = ptr->next;
		int value = ptr->value;
		delete ptr;
		return value;
	}

	static int Delete(List *&list) {
		// 实现该方法，删除list所有元素以及list，并将list置为NULL
		// 需要考虑的异常情况:list==NULL
		if (list == nullptr)
			throw NullPointer("NullPointer:Delete()");
		while (list->root != nullptr) {
			auto nxt = list->root->next;
			delete list->root;
			list->root = nxt;
		}
		list = nullptr;
		return 0;
	}

	static void Show(List *list) {
		// 实现该方法，输出list所有元素,若list不包含元素，则什么都不输出
		// 需要考虑的异常情况:list==NULL
		// 输出的每一个数字以一个空格隔开，最后的数字后面不包含空格
		if (list == nullptr)
			throw NullPointer("NullPointer:Show()");
		if (list->root == nullptr)
			return;
		cout << list->root->value;
		Node *ptr = list->root->next;
		while (ptr != nullptr) {
			cout << " " << ptr->value;
			ptr = ptr->next;
		}
		cout << endl;
	}

	static int Add(int index, List *list, int value) {
		// 实现该方法，向list的第index个元素加上value,并且返回结果
		// 需要考虑的异常情况:list==NULL，越界，溢出
		if (list == nullptr)
			throw NullPointer("NullPointer:Add()");
		if (index < 0)
			throw OutOfBound("OutOfBound:Add(),index=" + to_string(index));
		int count = 0;
		Node *ptr = list->root;
		while (ptr != nullptr and count < index) {
			++count;
			ptr = ptr->next;
		}
		if (ptr == nullptr)
			throw OutOfBound("OutOfBound:Add(),index=" + to_string(index));
		int ret = ptr->value + value;
		bool error1 = value > 0 and ret < ptr->value,
			error2 = value < 0 and ret > ptr->value;
		if (error1 or error2)
			throw Overflow("Overflow:Add(),index=" + to_string(index));
		ptr->value = ret;
		return ret;
	}

	static int Subtract(int index,List *list,int value) {
		// 实现该方法，向list的第index个元素减去value,并且返回结果
		// 需要考虑的异常情况:list==NULL，越界，溢出
		if (list == nullptr)
			throw NullPointer("NullPointer:Subtract()");
		if (index < 0)
			throw OutOfBound("OutOfBound:Subtract(),index=" + to_string(index));
		int count = 0;
		Node *ptr = list->root;
		while (ptr != nullptr and count < index) {
			++count;
			ptr = ptr->next;
		}
		if (ptr == nullptr)
			throw OutOfBound("OutOfBound:Subtract(),index=" + to_string(index));
		int ret = ptr->value - value;
		bool error1 = value < 0 and ret < ptr->value,
			error2 = value > 0 and ret > ptr->value;
		if (error1 or error2)
			throw Overflow("Overflow:Subtract(),index=" + to_string(index));
		ptr->value = ret;
		return ret;
	}

	static int Multiply(int index,List *list,int value) {
		// 实现该方法，向list的第index个元素乘以value,并且返回结果
		// 需要考虑的异常情况:list==NULL，越界，溢出
		if (list == NULL)
			throw NullPointer("NullPointer:Multiply()");
		if (index < 0)
			throw OutOfBound("OutOfBound:Multiply(),index=" + to_string(index));
		int count = 0;
		Node *ptr = list->root;
		while (ptr != nullptr and count < index) {
			++count;
			ptr = ptr->next;
		}
		if (ptr == nullptr)
			throw OutOfBound("OutOfBound:Multiply(),index=" + to_string(index));
		auto ret = ptr->value*value;
		if (ptr->value != 0 and ret/ptr->value != value)
			throw Overflow("Overflow:Multiply(),index=" + to_string(index));
		ptr->value = ret;
		return ret;
	}

	static int Divide(int index,List *list,int value) {
		//实现该方法，向list的第index个元素除以value,并且返回结果
		if (list == nullptr)
			throw NullPointer("NullPointer:Divide()");
		if (index < 0)
			throw OutOfBound("OutOfBound:Divide(),index=" + to_string(index));
		int count = 0;
		Node *ptr = list->root;
		while (ptr != nullptr and count < index) {
			++count;
			ptr = ptr->next;
		}
		if (ptr == nullptr)
			throw OutOfBound("OutOfBound:Divide(),index=" + to_string(index));
		if (value == 0)
			throw ArithmeticeError("ArithmeticeError:Divide(),index=" + to_string(index));
		ptr->value /= value;
		return ptr->value;
	}
};

#endif
