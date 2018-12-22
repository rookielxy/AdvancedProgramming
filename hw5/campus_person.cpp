#include "campus_person.h"

string Student::identification() {
	return "Student " + name + ", Card " + to_string(cardId);
}

string Teacher::identification() {
	return "Teacher " + name + ", Card " + to_string(cardId)
			+ ", Face " + to_string(faceId);
}

XMLElement* Student::saveXML(XMLDocument *doc) {
	XMLElement *person = doc->NewElement("Person");
	person->SetAttribute("type", "student");
	XMLElement *name = doc->NewElement("Name");
	name->SetText(this->name.c_str());
	person->InsertEndChild(name);
	XMLElement *card = doc->NewElement("Card");
	card->SetText(this->cardId);
	person->InsertEndChild(card);
	return person;
}

XMLElement* Teacher::saveXML(XMLDocument *doc) {
	XMLElement *person = doc->NewElement("Person");
	person->SetAttribute("type", "teacher");
	XMLElement *name = doc->NewElement("Name");
	name->SetText(this->name.c_str());
	person->InsertEndChild(name);
	XMLElement *card = doc->NewElement("Card");
	card->SetText(this->cardId);
	person->InsertEndChild(card);
	XMLElement *face = doc->NewElement("Face");
	face->SetText(this->faceId);
	person->InsertEndChild(face);
	return person;
}