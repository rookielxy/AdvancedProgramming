#include "Set.h"

Set *Set::p_free = nullptr;

void sort(int array[], int length) {
	for (int i = 0; i < length; ++i) {
		for (int j = 0; j < length - 1 - i; ++j) {
			if (array[j] > array[j + 1]) {
				int temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
		}
	}
}


Set::Set() {
    array = new int[DEFAULT_LENGTH];
    length = 0;
}

Set::Set(int elements[], int length): Set() {
	auto temp = new int[length];
	for (int i = 0; i < length; ++i)
		temp[i] = elements[i];
	sort(temp, length);
	int idx = 0;
	while (idx < length) {
		array[this->length] = temp[idx];
		++this->length;
		int duplicate = idx;
		while(temp[idx] == temp[duplicate] and duplicate < length)
			++duplicate;
		idx = duplicate;
	}
}

Set::Set(const Set &set): Set() {
	for (; length < set.length; ++length)
		array[length] = set.array[length];
}

Set::~Set() {
	length = 0;
	delete array;
	array = nullptr;
}

void Set::add(int element) {
	if (not contains(element)) {
		array[length] = element;
		++length;
		sort(array, length);
	}
}

bool Set::erase(int element) {
	int idx = 0;
	for(; idx < length; ++idx) {
		if (array[idx] == element)
			break;
	}

	if (idx == length)
		return false;

	--length;
	for(int i = idx; i < length; ++i)
		array[i] = array[i + 1];
	return true;
}

bool Set::contains(int element) const {
	for (int i = 0; i < length; ++i) {
		if (array[i] == element)
			return true;
	}
	return false;
}

ostream& operator<<(ostream &os, Set rset) {
	if (rset.length == 0) {
		os << "Empty";
		return os;
	}
	for (int i = 0; i < rset.length; ++i)
		os << rset.array[i] << " ";
	return os;
}

Set operator+(const Set &set1, const Set &set2) {
	auto temp = new int[set1.length + set2.length];
	int idx = 0;
	for (int i = 0; i < set1.length; ++i)
		temp[idx++] = set1.array[i];
	for (int i = 0; i < set2.length; ++i)
		temp[idx++] = set2.array[i];
	return Set(temp, set1.length + set2.length);
}

Set& Set::operator+=(Set &set) {
	for (int i = 0; i < set.length; ++i)
		add(set.array[i]);
	return *this;
}

Set operator-(const Set &set1, const Set &set2) {
	Set set(set1);
	for (int i = 0; i < set2.length; ++i)
		set.erase(set2.array[i]);
	return set;
}

Set& Set::operator-=(Set &set) {
	for (int i = 0; i < set.length; ++i)
		erase(set.array[i]);
	return *this;
}

Set operator&(const Set &set1, const Set &set2) {
	Set set;
	for (int i = 0; i < set1.length; ++i) {
		if (set2.contains(set1.array[i]))
			set.add(set1.array[i]);
	}
	return set;
}

Set operator|(const Set &set1, const Set &set2) {
	return set1 + set2;
}

bool operator==(const Set &set1, const Set &set2) {
	if (set1.length != set2.length)
		return false;
	for (int i = 0; i < set1.length; ++i) {
		if (set1.array[i] != set2.array[i])
			return false;
	}
	return true;
}

bool operator!=(const Set &set1, const Set &set2) {
	return not (set1 == set2);
}

bool operator>=(const Set &set1, const Set &set2) {
	for (int i = 0; i < set2.length; ++i) {
		if (not set1.contains(set2.array[i]))
			return false;
	}
	return true;
}

bool operator<=(const Set &set1, const Set &set2) {
	return set2 >= set1;
}

bool operator>(const Set &set1, const Set &set2) {
	return set1 >= set2 and set1 != set2;
}

bool operator<(const Set &set1, const Set &set2) {
	return set2 > set1;
}


/*
	重载操作符new，
	new和delete都是属于类而不是属于某个特定对象的操作，
	因此在类中作为静态成员函数重载。
	其参数size表示对象所需空间大小，由程序自动计算。
	在此实现中，重载操作符new目的为提高分配空间的效率，
	实现方法为申请一片较大的内存区域，
	以静态链表的方式组织起来，
	并从链表中取出空闲内存区域为对象分配空间。
 */
void *Set::operator new(size_t size) {
	Set *p;
	if (p_free == nullptr) {                            // 申请较大的内存空间
		p_free = (Set *)malloc(size*NUM);               // 并组织为静态链表的形式
		for (p = p_free; p != p_free + NUM - 1; ++p)
			p->next = p + 1;
		p->next = nullptr;
	}
	p = p_free;                                         // 占用部分内存空间，更新p_free
	p_free = p_free->next;
	memset(p, 0, size);
	return p;
}

/*
	与重载操作符new相对应地，
	重载操作符delete以管理new中申请的内存区域，
	该类对象消亡时，将其内存空间放回链表节点中而不是堆区，
	同时更新链表中空闲内存区域。
 */
void Set::operator delete(void *p) {
	((Set *)p)->next = p_free;                          // 归还内存空间，更新p_free
	p_free = (Set *)p;
}
