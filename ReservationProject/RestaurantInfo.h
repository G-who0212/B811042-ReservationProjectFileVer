#pragma once
#ifndef RESTAURANTINFO_H
#define RESTAURANTINFO_H
#include "Info.h"
class RestaurantInfo:public Info {
	int age;
	int peopleNum;
public:
	RestaurantInfo();

	void setInfoAge(int age);

	int getInfoAge();

	void SetInfoPeopleNum(int peopleNum);

	int getInfoPeopleNum();
};

#endif