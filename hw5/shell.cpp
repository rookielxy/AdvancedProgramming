#include "shell.h"


void Shell::parse() {
	string str;
	while (getline(cin, str)) {
		string move;
		stringstream ss;
		ss << str;
		ss >> move;
		if (move == "clear") {
			string opt;
			ss >> opt;
			if (opt == "face")
				entrance.clearFaceId();
			else if (opt == "card")
				entrance.clearCardId();
			else
				cout << "instruction unavailable" << endl;
		} else if (move == "add") {
			string opt, temp;
			ss >> opt >> temp;
			if (opt == "face") {
				int data;
				while (ss >> data) {
					if (not entrance.addFaceId(data))
						cout << "add face id " << data << " failed" << endl;
				}
				entrance.printFaceId();
			} else if (opt == "card") {
				int data;
				while (ss >> data) {
					if (not entrance.addCardId(data))
						cout << "add card id" << data << " failed" << endl;
				}
				entrance.printCardId();
			} else
				cout << "instruction unavailable" << endl;
		} else if (move == "delete") {
			string opt, temp;
			ss >> opt >> temp;
			if (opt == "face") {
				int data;
				while (ss >> data) {
					if (not entrance.deleteFaceId(data))
						cout << "delete face id " << data << " failed" << endl;
				}
				entrance.printFaceId();
			} else if (opt == "card") {
				int data;
				while (ss >> data) {
					if (not entrance.deleteCardId(data))
						cout << "delete card id" << data << " failed" << endl;
				}
				entrance.printCardId();
			} else
				cout << "instruction unavailable" << endl;
		} else if (move == "print") {
			string opt, temp;
			ss >> opt >> temp;
			if (opt == "face")
				entrance.printFaceId();
			else if (opt == "card")
				entrance.printCardId();
			else
				cout << "instruction unavailable" << endl;
		} else if (move == "input") {
			string info;
			int data;
			ss >> data;
			for (int i = 0; i < data; ++i) {
				getline(cin, info);
				entrance.parseInfo(info);
			}
			cout << "information input end" << endl;
		} else if (move == "simulate") {
			entrance.simulate();
		} else if (move == "help") {
			cout << "You can input following instructions: " << endl
				<< "clear (face|card) id" << endl
				<< "add (face|card) id" << endl
				<< "delete (face|card) id" << endl
				<< "print (face|card) id" << endl
				<< "input [n] information" << endl
				<< "simulate" << endl;
		} else if (move == "load") {
			string file;
			ss >> file;
			entrance.loadConfig(file);
			cout << "load configuration from " << file << endl;
		} else if (move == "save") {
			string file;
			ss >> file;
			entrance.saveConfig(file);
			cout << "save configuration to " << file << endl;
		} else {
			cout << "instruction unavailable" << endl;
		}
	}
}