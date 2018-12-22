#include "entrance.h"

bool Entrance::addId(set<int> &toadd, int id) {
	auto it = toadd.find(id);
	if (it == toadd.end()) {
		toadd.insert(id);
		return true;
	}
	return false;
}

bool Entrance::addCardId(int id) {
	return addId(cards, id);
}

bool Entrance::addFaceId(int id) {
	return addId(faces, id);
}

bool Entrance::deleteId(set<int> &todel, int id) {
	auto it = todel.find(id);
	if (it == todel.end())
		return false;
	todel.erase(id);
	return true;
}

bool Entrance::deleteCardId(int id) {
	return deleteId(cards, id);
}

bool Entrance::deleteFaceId(int id) {
	return deleteId(faces, id);
}

void Entrance::clearCardId() {
	cards.clear();
}

void Entrance::clearFaceId() {
	faces.clear();
}

void Entrance::printId(const set<int> &toPrint, string str) {
	if (toPrint.empty()) {
		cout << str << " is empty" << endl;
		return;
	}
	cout << str << ": ";
	for (auto ele : toPrint)
		cout << ele << " ";
	cout << endl;
}

void Entrance::printCardId() {
	printId(cards, "Card ID");
}

void Entrance::printFaceId() {
	printId(faces, "Face ID");
}

bool Entrance::isValid(const set<int> &dataset, int id) {
	auto it = dataset.find(id);
	return it != dataset.end();
}

bool Entrance::isCardValid(int id) {
	return isValid(cards, id);
}

bool Entrance::isFaceValid(int id) {
	return isValid(faces, id);
}

void Entrance::parseInfo(const string &info) {
	Log newLog;
	stringstream ss;
	ss << info;

	string name;
	string temp;
	string identity;

	ss >> name >> identity;
	if (identity == "student") {
		int card;
		ss >> temp >> card;
		person.emplace_back(new Student(name, card));
		newLog.idx = (int)person.size() - 1;
		newLog.card = isCardValid(card);
	} else {
		assert(identity == "teacher");      // identity can only be student or teacher
		int card, face;
		ss >> temp >> face >> temp >> card;
		person.emplace_back(new Teacher(name, card, face));
		newLog.idx = (int)person.size() - 1;
		newLog.card = isCardValid(card);
		newLog.face = isFaceValid(face);
	}



	string time;
	ss >> time;
	sscanf(time.c_str(), "%d:%d", &newLog.time.hour, &newLog.time.minute);

	string direction;
	ss >> direction;
	if (direction == "in")
		newLog.comeIn = true;
	else if (direction == "out")
		newLog.comeIn = false;
	else
		assert(false);
	logs.emplace_back(newLog);
}

void Entrance::simulate() {
	sort(logs.begin(), logs.end());
	for (auto &log: logs)
		cout << log.convertString(person) << endl;
}

void Entrance::loadConfig(const string &filename) {
	XMLDocument doc;
	if (doc.LoadFile(filename.c_str())) {
		doc.PrintError();
		assert(false);
	}

	XMLElement *ent = doc.RootElement();
	XMLElement *ids = ent->FirstChildElement("IDs");
	XMLElement *id = ids->FirstChildElement("ID");
	while (id != nullptr) {
		const XMLAttribute *attr = id->FirstAttribute();
		int value;
		sscanf(id->GetText(), "%d", &value);
		if (strcmp(attr->Value(), "face") == 0)
			faces.emplace(value);
		else if (strcmp(attr->Value(), "card") == 0)
			cards.emplace(value);
		else
			assert(false);
		id = id->NextSiblingElement();
	}

	XMLElement *persons = ent->FirstChildElement("Persons");
	XMLElement *person = persons->FirstChildElement();
	while (person != nullptr) {
		const XMLAttribute *attr = person->FirstAttribute();
		XMLElement *name = person->FirstChildElement("Name");
		XMLElement *card = person->FirstChildElement("Card");
		int cardValue;
		sscanf(card->GetText(), "%d", &cardValue);
		if (strcmp(attr->Value(), "teacher") == 0) {
			XMLElement *face = person->FirstChildElement("Face");
			int faceValue;
			sscanf(face->GetText(), "%d", &faceValue);
			this->person.emplace_back(new Teacher(name->GetText(), cardValue, faceValue));
		} else if (strcmp(attr->Value(), "student") == 0) {
			this->person.emplace_back(new Student(name->GetText(), cardValue));
		} else {
			assert(false);
		}

		person = person->NextSiblingElement();
	}

	XMLElement *logs = ent->FirstChildElement("Logs");
	XMLElement *log = logs->FirstChildElement();
	while (log != nullptr) {
		this->logs.emplace_back(Log(log));
		log = log->NextSiblingElement();
	}
}

void Entrance::saveConfig(const string &filename) {
	XMLDocument doc;
	XMLElement *ent = doc.NewElement("Entrance");
	doc.InsertEndChild(ent);

	XMLElement *ids = doc.NewElement("IDs");
	ent->InsertEndChild(ids);

	for (auto &ele : this->cards) {
		XMLElement *id = doc.NewElement("ID");
		id->SetAttribute("type", "card");
		id->SetText(ele);
		ids->InsertEndChild(id);
	}

	for (auto &ele : this->faces) {
		XMLElement *id = doc.NewElement("ID");
		id->SetAttribute("type", "face");
		id->SetText(ele);
		ids->InsertEndChild(id);
	}

	XMLElement *persons = doc.NewElement("Persons");
	ent->InsertEndChild(persons);
	for (auto ptr : this->person)
		persons->InsertEndChild(ptr->saveXML(&doc));

	XMLElement *logs = doc.NewElement("Logs");
	ent->InsertEndChild(logs);
	for (auto &ele : this->logs)
		logs->InsertEndChild(ele.saveXML(&doc));

	doc.SaveFile(filename.c_str());
}