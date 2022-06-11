#pragma once
#ifndef LIBRARYSEAT_H
#define LIBRARYSEAT_H
#include <iostream>
#include <string>
using namespace std;
class LibrarySeat {
	string name;
	string sex;
public:
	LibrarySeat();

	void setName(string name);

	string getName();

	void setSex(string sex);

	string getSex();
};

#endif