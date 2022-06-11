#pragma once
#ifndef RESTAURANTTIME_H
#define RESTAURANTTIME_H
#include "RestaurantSeat.h"
class RestaurantTime {
	string time;
	RestaurantSeat* resSeat;
public:
	RestaurantTime();

	~RestaurantTime();

	void setTime(string time);

	string getTime();

	void setCapacity(int index, int capacity);

	int getCapacity(int index);

	void setName(int index, string name);

	string getName(int index);
};

#endif