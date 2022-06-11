#pragma once
#ifndef MEMBERDATA_H
#define MEMBERDATA_H
#include "AirplaneInfo.h"
#include "RestaurantInfo.h"
#include "LibraryInfo.h"
#include <vector>

class MemberData {
	vector<AirplaneInfo> AI;
	vector<RestaurantInfo> RI;
	vector<LibraryInfo> LI;

public:
	void addAirplaneInfo(string id, string pw, string name, int budget);

	AirplaneInfo& getAirplaneInfo(int index);

	int getAirplaneInfoSize();

	void addRestaurantInfo(string id, string pw, string name, int age, int peopleNum);

	RestaurantInfo& getRestaurantInfo(int index);

	int getRestaurantInfoSize();

	void addLibraryInfo(string id, string pw, string name, int age, Family family, int unit, int LID, string sex);

	LibraryInfo& getLibraryInfo(int index);

	int getLibraryInfoSize();
};

#endif