#pragma once
#ifndef FAMILY_H
#define FAMILY_H
#include <iostream>
using namespace std;

class Family {
	int unit;
	int LID;
public:
	void setUnit(int unit);

	int getUnit();

	void setLID(int LID);

	int getLID();
};

#endif