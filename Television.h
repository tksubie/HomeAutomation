#pragma once
/*

Thaine Koen
12/16/2022
Header for Television class
*/
#ifndef Television_H
#define Television_H
#include "Home.h"
#include <iostream>
#include <vector>

using namespace std;
class Television : virtual public Home {

protected:

	int Channel = 0;		//for selecting channel

	string useType[2] = { "Manual","Automatic" };		//1 for manual, 2 for automatic
	int setting =0;		//setting from array

	int time1 =0;		//for time range for automatic functioning
	int time2 = 0;		//for time range for automatic functioning


	string day[2]{ "everyday","every-other-day"};	//holds settings for automatic functionality
	int dayselection = 0;
	int time = 0;		//in 24 hour format

public:

	Television();		//default constructor
	Television(int onoff, int Setting, int channel);		//for manual use usetype 1
	Television(int onoff, int Setting, int daySelection, int Time);		//for automatic use usetype 2 

	void setOnOff(int onoff);
	int getOnOff();

	void setUseType(int usetype);
	int getUseType();

	void printdayselection();		// to display settings you can choose

	void setDaySelection(int ds);
	int getDaySelection();

	void setChannel(int channel);
	int getChannel();

	void setTime(int Time);
	int getTime();

	


	void printTelevisionReport(std::ostream& out);		//print report of information from home base class will be a friend function

	void printtvuserinput(Television& obj);
};
#endif