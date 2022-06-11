#pragma once
#ifndef WALKINCUSTOMER_H
#define WALKINCUSTOMER_H
#include <iostream>
#include <string>
using namespace std;

class WalkInCustomer {
	string name;
	int waitNum;
public:
	WalkInCustomer(string name, int Vsize);

	void setName(string name);

	string getName();

	void setWaitNum(int waitNum);

	int getWaitNum();
};

#endif