#include "LibraryInfo.h"

LibraryInfo::LibraryInfo() {
	age = -1;
	unit = -1;
	LID = -1;
	sex = "¹ÌÁ¤";
}

void LibraryInfo::setInfoAge(int age) {
	this->age = age;
}

int LibraryInfo::getInfoAge() {
	return age;
}
void LibraryInfo::setInfoUnit(int unit) {
	this->unit = unit;
}
int LibraryInfo::getInfoUnit() {
	return unit;
}
void LibraryInfo::setInfoLID(int LID) {
	this->LID = LID;
}
int LibraryInfo::getInfoLID() {
	return LID;
}
void LibraryInfo::setInfoFamily(Family family) {
	this->family = family;
}
Family LibraryInfo::getInfoFamily() {
	return family;
}
void LibraryInfo::setInfoSex(string sex) {
	this->sex = sex;
}
string LibraryInfo::getInfoSex() {
	return sex;
}