#pragma once
/*

Thaine Koen
12/16/2022
Header for RobotVaccum class
*/
#ifndef RobotVaccum_H
#define RobotVaccum_H
#include "Home.h"
#include <iostream>
#include <vector>
#include <set>

using namespace std;

class RobotVaccum : virtual public Home {		//inheritence to virtual base class

protected:

	string useType[2] = {"Manual","Automatic"};		//1 for manual, 2 for automatic
	int setting = 0;		//setting from array

	int time1 = 0;		//for time range for automatic functioning
	int time2 = 0;		//for time range for automatic functioning

	int Systemhealth = 100; //will start at 100 for 100 percent

public:

	RobotVaccum();		//default constructor
	RobotVaccum(int onOff, int usetype);		//constructor for manual
	RobotVaccum(int onOff,  int usetype, int firsttime, int secondtime);		//constructor for automatic function

	// setters and getters for protected values

	void setTime1(int firsttime);
	int getTime1();

	void setTime2(int secondtime);
	int getTime2();

	void setOnOff(int onoff);
	int getOnOff();

	void setUseType(int usetype);
	int getUseType();

	void printRVReport(std::ostream& out);		//print report of information from home base class will be a friend function

	void printRVuserinput(RobotVaccum& obj);
};
#endif