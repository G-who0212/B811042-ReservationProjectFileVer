#pragma once
#ifndef RESTAURANTDATE_H
#define RESTAURANTDATE_H
#include "RestaurantTIme.h"
class RestaurantDate {
	string date;
	RestaurantTime* time;
public:
	RestaurantDate();

	~RestaurantDate();

	void setDate(string date);

	string getDate();

	void setTime(int index, string time);

	string getTime(int index);

	void setCapacity(int index1, int index2, int capacity);

	int getCapacity(int index1, int index2);

	void setName(int index1, int index2, string name);

	string getName(int index1, int index2);
};

#endif