#ifndef HW5_CAMPUS_PERSON_H
#define HW5_CAMPUS_PERSON_H

#include "common.h"

class CampusPerson {
protected:
	string name;
	int cardId;
public:
	CampusPerson(string name, int cardId): name(move(name)), cardId(cardId) {}
	virtual string identification() = 0;
	virtual bool isTeacher() = 0;
	virtual XMLElement* saveXML(XMLDocument *doc) = 0;
};


class Student : public CampusPerson {
public:
	Student(string name, int cardId): CampusPerson(move(name), cardId) {}
	string identification() override;
	bool isTeacher() override { return false; }
	XMLElement* saveXML(XMLDocument *doc) override;
};


class Teacher : public CampusPerson {
	int faceId;
public:
	Teacher(string name, int cardId, int faceId): CampusPerson(move(name), cardId), faceId(faceId) {}
	string identification() override;
	bool isTeacher() override { return true; }
	XMLElement* saveXML(XMLDocument *doc) override;
};

#endif //HW5_CAMPUS_PERSON_H
