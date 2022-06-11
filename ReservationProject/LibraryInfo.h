#pragma once
#ifndef LIBRARYINFO_H
#define LIBRARYINFO_H
#include "Family.h"
#include "Info.h"
class LibraryInfo : public Info {
	int age;
	Family family;
	int unit;
	int LID;
	string sex;
public:
	LibraryInfo();

	void setInfoAge(int age);

	int getInfoAge();

	void setInfoUnit(int unit);

	int getInfoUnit();

	void setInfoLID(int LID);

	int getInfoLID();

	void setInfoFamily(Family family);

	Family getInfoFamily();

	void setInfoSex(string sex);

	string getInfoSex();
};

#endif