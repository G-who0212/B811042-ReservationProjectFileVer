#pragma once
#ifndef RESTAURANT_H
#define RESTAURANT_H
#include "RestaurantDate.h"
#include "RestaurantInfo.h"
#include "RestaurantWalkInSeat.h"
#include <fstream>
class Restaurant {
	RestaurantDate* date;
	int seatResNum[8] = { 0 };
public:
	Restaurant();

	~Restaurant();

	void setDate(int index, string date);

	string getDate(int index);

	void setTime(int index1, int index2, string time);

	string getTime(int index1, int index2);

	void setCapacity(int index1, int index2, int index3, int capacity);

	int getCapacity(int index1, int index2, int index3);

	void setName(int index1, int index2, int index3, string name);

	string getName(int index1, int index2, int index3);

	void setSeatResNum(int index, int seatResNum);

	int getSeatResNum(int index);

	void showStatistics(RestaurantInfo rMember);

	void RestaurantReservation(RestaurantInfo &rMember, RestaurantWalkInSeat &walkin);
};

#endif