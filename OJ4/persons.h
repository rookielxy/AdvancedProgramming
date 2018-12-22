#ifndef OJ4_PERSON_H
#define OJ4_PERSON_H

#include "cards.h"

class Campus_Person {
private:
	string campus_id;
	Bank_Card* b_card;
public:
	string get_campus_id() { return campus_id; }
	Bank_Card* get_b_card() { return b_card; }
	Campus_Person(string campus_id, Bank_Card *b_card): campus_id(campus_id), b_card(b_card) {}
	~Campus_Person() {
		delete b_card;
		b_card = nullptr;
	}
};

class Student : public Campus_Person {
private:
	Student_Card *s_card;
public:
	Student_Card* get_s_card() { return s_card; }
	Student(string campus_id, Bank_Card *b_card, Student_Card *s_card):
			Campus_Person(campus_id, b_card), s_card(s_card) {}
	~Student() {
		delete s_card;
		s_card = nullptr;
	}
	int bind_card(Bank_Card *b_card) { return s_card->bind(b_card); }
};

class Teacher : public Campus_Person {
private:
	Teacher_Card* t_card;
	vector<Student*> stus;
public:
	Teacher_Card* get_t_card() { return t_card; };

	vector<Student*>* get_students() { return &stus; };

	Teacher(string campus_id, Bank_Card* b_card, Teacher_Card* t_card):
			Campus_Person(campus_id, b_card), t_card(t_card) {}

	~Teacher() {
		delete t_card;
		t_card = nullptr;
	}

	int add_bind_card(Bank_Card* b_card) {
		bool find = false;
		for (auto stu : stus) {
			if (b_card == stu->get_b_card()) {
				find = true;
				break;
			}
		}
		if (not find)
			return -1;
		else
			return t_card->addBankCard(b_card);
	}
	int delete_bind_card(Bank_Card* b_card) { return t_card->deleteBankCard(b_card); }
	int add_student(Student* stu) {
		for (auto ele : stus) {
			if (ele == stu)
				return -1;
		}
		stus.emplace_back(stu);
		return 0;
	}
	int delete_student(Student* stu) {
		auto it = stus.begin();
		for (; it != stus.end(); ++it) {
			if (*it == stu)
				break;
		}
		if (it == stus.end())
			return -1;
		stus.erase(it);
		return 0;
	}

};

#endif //OJ4_PERSON_H
