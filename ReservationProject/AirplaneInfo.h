#pragma once//¿Ï·á
#ifndef AIRPLANEINFO_H
#define AIRPLANEINFO_H
#include "Info.h"

class AirplaneInfo :public Info {
	int budget;
	int mileage;
public:
	AirplaneInfo();
	void setInfoBudget(int budget);

	int getInfoBudget();

	void setInfoMileage(int mileage);

	int getInfoMileage();
};

#endif