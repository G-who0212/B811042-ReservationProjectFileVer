#pragma once
#ifndef SEAT_H
#define SEAT_H
#include <iostream>
#include <string>
using namespace std;
class Seat {
	string name;
	string seatClass;
	int cost;
public:
	Seat();

	void setName(string name);

	string getName();

	void setSeatClass(string seatClass);

	string getSeatClass();

	void setCost(int cost);

	int getCost();

};

#endif