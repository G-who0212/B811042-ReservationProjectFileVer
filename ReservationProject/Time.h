#pragma once
#ifndef TIME_H
#define TIME_H

#include "Seat.h"

class Time {
	Seat* seat;
	string time;
public:
	Time();

	~Time();

	void setTime(string time);

	string getTime();

	void setName(int index, string name);

	string getName(int index);

	void setSeatClass(int index, string seatClass);

	string getSeatClass(int index);

	void setCost(int index, int cost);

	int getCost(int index);
};

#endif