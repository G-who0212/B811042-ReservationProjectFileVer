#pragma once
#ifndef LIBRARY_H
#define LIBRARY_H
#include "LibraryDate.h"
#include "MemberData.h"
#include <fstream>
class Library {
	LibraryDate* date;
	int seatResNum[15][15];
	int male;
	int female;
public:
	Library();

	~Library();

	void setDate(int index, string date);

	string getDate(int index);

	void setTime(int index1, int index2, string time);

	string getTime(int index1, int index2);

	void setName(int index1, int index2, int indexX, int indexY, string name);

	string getName(int index1, int index2, int indexX, int indexY);

	void setSex(int index1, int index2, int indexX, int indexY, string sex);

	string getSex(int index1, int index2, int indexX, int indexY);

	void addMale();

	int getMale();

	void addFemale();

	int getFemale();

	void showStatistics(LibraryInfo lMember);

	void sameGender(int& newSeatNum, int newDate, int newTime[], int i);

	void differentGender(int newDate, int newTime[], int newSeatNum, int i, LibraryInfo &lMember);

	void LibraryReservation(LibraryInfo &lMember);

};

#endif