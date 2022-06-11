#pragma once
#ifndef RESTAURANTWALKINSEAT_H
#define RESTAURANTWALKINSEAT_H
#include "WalkInCustomer.h"
#include "RestaurantSeat.h"
#include "MemberData.h"
#include <vector>
#include <algorithm>
class RestaurantWalkInSeat : public RestaurantSeat {
	vector<WalkInCustomer> wc2;
	vector<WalkInCustomer> wc4;
	vector<WalkInCustomer> wc6;
	int point = 0;
public:
	int addWaiter(RestaurantInfo rMember);

	void callWaiter(int whatTable);
};

#endif