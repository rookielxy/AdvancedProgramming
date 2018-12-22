#ifndef HW5_ENTRANCE_H
#define HW5_ENTRANCE_H

#include "common.h"
#include "campus_person.h"

struct Log {
	int idx;
	struct {
		int hour;
		int minute;
	} time;
	bool card;
	bool face;
	bool comeIn;

	Log() = default;
	explicit Log(XMLElement *ele) {
		XMLElement *idx = ele->FirstChildElement("Idx");
		sscanf(idx->GetText(), "%d", &this->idx);
		XMLElement *time = ele->FirstChildElement("Time");
		sscanf(time->GetText(), "%d:%d", &this->time.hour, &this->time.minute);
		XMLElement *card = ele->FirstChildElement("Card");
		this->card = strcmp(card->GetText(), "true") == 0;
		XMLElement *face = ele->FirstChildElement("Face");
		this->face = strcmp(face->GetText(), "true") == 0;
		XMLElement *direction = ele->FirstChildElement("Direction");
		this->comeIn = strcmp(direction->GetText(), "in") == 0;
	}

	bool operator<(const Log &log) const {
		return (time.hour < log.time.hour) or
			(time.hour == log.time.hour and time.minute < log.time.minute);
	}

	string convertString(vector<CampusPerson*> person) {
		string info;
		info += person[idx]->identification();
		if (not comeIn) {
			info += ", " + to_string(time.hour) + ":";
			if (time.minute < 10)
				info += "0";
			info += to_string(time.minute);
			info += ", get out of the building";
			return info;
		}
		bool valid;
		if (person[idx]->isTeacher()) {
			valid = face or card;
			if (face) {
				info += ", face recognized";
			} else {
				info += ", face unrecognized";
				info += ", card ";
				info +=	card? "valid" : "invalid";
			}
		} else {
			valid = card;
			info += ", card ";
			info +=	card? "valid" : "invalid";
		}
		info += ", " + to_string(time.hour) + ":";
		if (time.minute < 10)
			info += "0";
		info += to_string(time.minute);
		info += valid? ", get in the building" : ", fail to get in the building";
		return info;
	}
.xm
	XMLElement *saveXML(XMLDocument *doc) {
		XMLElement *log = doc->NewElement("Log");

		XMLElement *idx = doc->NewElement("Idx");
		idx->SetText(this->idx);
		log->InsertEndChild(idx);

		XMLElement *time = doc->NewElement("Time");
		string str = to_string(this->time.hour) + ":";
		if (this->time.minute < 10)
			str += "0";
		str += to_string(this->time.minute);
		time->SetText(str.c_str());
		log->InsertEndChild(time);

		str = card? "true" : "false";
		XMLElement *card = doc->NewElement("Card");
		card->SetText(str.c_str());
		log->InsertEndChild(card);

		str = face? "true" : "false";
		XMLElement *face = doc->NewElement("Face");
		face->SetText(str.c_str());
		log->InsertEndChild(face);

		str = comeIn? "in" : "out";
		XMLElement *direction = doc->NewElement("Direction");
		direction->SetText(str.c_str());
		log->InsertEndChild(direction);
		return log;
	}
};


class Entrance {
	set<int> cards;
	set<int> faces;
	vector<Log> logs;
	vector<CampusPerson*> person;

	static bool addId(set<int> &toadd, int id);
	static bool deleteId(set<int> &todel, int id);
	static void printId(const set<int> &toPrint, string str);
	static bool isValid(const set<int> &dataset, int id);
	bool isCardValid(int id);
	bool isFaceValid(int id);
public:
	bool addCardId(int id);
	bool addFaceId(int id);
	bool deleteCardId(int id);
	bool deleteFaceId(int id);
	void clearCardId();
	void clearFaceId();
	void printCardId();
	void printFaceId();
	void parseInfo(const string &info);
	void simulate();
	void loadConfig(const string &filename);
	void saveConfig(const string &filename);
};


#endif //HW5_ENTRANCE_H
