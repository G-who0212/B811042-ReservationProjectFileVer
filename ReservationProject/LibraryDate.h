#pragma once
#ifndef LIBRARYDATE_H
#define LIBRARYDATE_H
#include "LibraryTime.h"

class LibraryDate {
	string date;
	LibraryTime* time;
public:
	LibraryDate();

	~LibraryDate();

	void setDate(string date);

	string getDate();

	void setTime(int index, string time);

	string getTime(int index);

	void setName(int index, int indexX, int indexY, string name);

	string getName(int index, int indexX, int indexY);

	void setSex(int index, int indexX, int indexY, string sex);

	string getSex(int index, int indexX, int indexY);
};

#endif