#ifndef OJ4_CARD_H
#define OJ4_CARD_H

#include <string>
#include <vector>
#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

class Card {
protected:
	string card_id;
	int account_balance;
public:
	string get_card_it() { return card_id; }
	int get_accunt_balance() { return account_balance; }
	Card(string card_id, int account_balance): card_id(card_id), account_balance(account_balance) {}
	~Card() = default;
};


class Bank_Card : public Card {
public:
	Bank_Card(string card_id, int account_balance): Card(card_id, account_balance) {}
	~Bank_Card() = default;
	int recharge(int num) { account_balance += num; return 0; }
	int consume(int num) {
		if (account_balance < num)
			return -1;
		account_balance -= num;
		return 0;
	}
};

class Student_Card : public Card {
private:
	Bank_Card *b_card;
public:
	Bank_Card *get_b_card() { return b_card; }
	Student_Card(string card_id, int account_balance, Bank_Card *b_card):
				Card(card_id, account_balance), b_card(b_card) {}

	~Student_Card() {
		delete b_card;
		b_card = nullptr;
	}

	int consume(int num) {
		if (account_balance < num)
			return -1;
		account_balance -= num;
		return 0;
	}

	int recharge(Bank_Card *b_card, int num) {
		if (this->b_card != b_card)
			return -1;
		if (b_card->consume(num) == -1)
			return -1;
		account_balance += num;
		return 0;
	}

	int bind(Bank_Card *b_card) { this->b_card = b_card; return 0; }
};


class Teacher;
class Teacher_Card : public Card {
private:
	double discount;
	vector<Bank_Card*> b_cards;
public:
	friend class Teacher;
	double get_discount() { return discount; };
	vector<Bank_Card *>* get_b_cards() { return &b_cards; }

	Teacher_Card(string card_id, int account_balance, double discount, Bank_Card *b_card):
				Card(card_id, account_balance), discount(discount) {
		b_cards.emplace_back(b_card);
	}

	~Teacher_Card() {
		for (auto b_card : b_cards) {
			delete b_card;
			b_card = nullptr;
		}
	}

	int consume(int num) {
		num = floor(num*discount);
		if (account_balance < num)
			return -1;
		account_balance -= num;
		return 0;
	}

	int recharge(Bank_Card *b_card, int num) {
		Bank_Card *temp = nullptr;
		for (auto ele : b_cards) {
			if (ele == b_card) {
				temp = ele;
				break;
			}
		}
		if (temp == nullptr)
			return -1;
		if (temp->consume(num) == -1)
			return -1;
		account_balance += num;
		return 0;
	}

	int addBankCard(Bank_Card *b_card) {
		for (auto ele : b_cards) {
			if (ele == b_card)
				return -1;
		}
		b_cards.emplace_back(b_card);
		return 0;
	}

	int deleteBankCard(Bank_Card *b_card) {
		auto it = b_cards.begin();
		for (; it != b_cards.end(); ++it) {
			if (*it == b_card)
				break;
		}
		if (it == b_cards.end())
			return -1;
		b_cards.erase(it);
		return 0;
	}

};


#endif //OJ4_CARD_H
