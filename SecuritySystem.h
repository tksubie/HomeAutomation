#pragma once
/*

Thaine Koen
12/16/2022
Header for SecuritySystem class
*/
#ifndef SecuritySystem_H
#define SecuritySystem_H
#include "Home.h"
#include <iostream>
#include <vector>

using namespace std;

class SecuritySystem : virtual public Home {

protected:

	string useType[2]{ "Manual","Automatic" };		//holds the setting for use type in array
	int setting = 0;		//setting for usetype

	int Time1 = 0;		//for first time selection on security system
	int Time2 = 0;		//for second time selection on security system

	int sensitivityRating[6] = { 0,1,2,3,4,5 };		//holds the setting for the sensitivity user wants
	int sSetting = 0;		//sensitivity setting
public:

	SecuritySystem();		//default constructor
	SecuritySystem(int onoff, int usetype, int sensitivitySetting);		//for maual operation use 1
	SecuritySystem(int onoff, int usetype, int sensitivitySetting, int time1, int time2);		//for automatic setting use 2

	void setTime1(int time1);
	int getTime1();

	void setTime2(int time2);
	int getTime2();

	void setOnOff(int onoff);
	int getOnOff();

	void setSensS(int sensitivitySetting);
	int getSensS();

	void setUseType(int usetype);
	int getUseType();


	void printSecuritySystemReport(std::ostream& out);		//print report of information from home base class will be a friend function

	void printSsuserinput(SecuritySystem& obj);
};
#endif