#pragma once
#ifndef WHERE_H
#define WHERE_H
#include "Date.h"
class Where {
	Date* date;
	string depart;
	string dest;
public:
	Where();

	~Where();

	void setDepart(string depart);

	string getDepart();

	void setDest(string dest);

	string getDest();

	void setDate(int index, string date);

	string getDate(int index);

	void setTime(int index1, int index2, string time);

	string getTime(int index1, int index2);

	void setName(int index1, int index2, int index3, string name);

	string getName(int index1, int index2, int index3);

	void setSeatClass(int index1, int index2, int index3, string seatClass);

	string getSeatClass(int index1, int index2, int index3);

	void setCost(int index1, int index2, int index3, int cost);

	int getCost(int index1, int index2, int index3);
};

#endif