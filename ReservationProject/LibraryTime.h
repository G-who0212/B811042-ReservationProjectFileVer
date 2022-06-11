#pragma once
#ifndef LIBRARYTIME_H
#define LIBRARYTIME_H
#include "LibrarySeat.h"
class LibraryTime {
	string time;
	LibrarySeat seat[15][15];
public:
	void setTime(string time);

	string getTime();

	void setName(int indexX, int indexY, string name);

	string getName(int indexX, int indexY);

	void setSex(int indexX, int indexY, string sex);

	string getSex(int indexX, int indexY);
};

#endif