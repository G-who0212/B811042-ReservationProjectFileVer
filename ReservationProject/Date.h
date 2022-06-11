#pragma once
#ifndef DATE_H
#define DATE_H
#include "Time.h"
class Date {
	Time* time;
	string date;
public:
	Date();

	~Date();

	void setDate(string date);

	string getDate();

	void setTime(int index, string time);

	string getTime(int index);

	void setName(int index1, int index2, string name);

	string getName(int index1, int index2);

	void setSeatClass(int index1, int index2, string seatClass);

	string getSeatClass(int index1, int index2);

	void setCost(int index1, int index2, int cost);

	int getCost(int index1, int index2);
};

#endif