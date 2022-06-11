#pragma once
#ifndef RESTAURANTSEAT_H
#define RESTAURANTSEAT_H
#include <iostream>
#include <string>
using namespace std;

class RestaurantSeat {
	int capacity;
	string name;
public:
	RestaurantSeat();
	void setCapacity(int capacity);

	int getCapacity();

	void setName(string name);

	string getName();
};

#endif
