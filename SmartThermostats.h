#pragma once
/*

Thaine Koen
12/16/2022
Header for SmartThermostat class
*/

#ifndef SmartThermostat_H
#define SmartThermostat_H
#include "Home.h"
#include <iostream>
#include <vector>

using namespace std;
class SmartThermostat : virtual public Home {

protected:
	

	int Temp1 = 0;		//set first temperature
	string day = "Day temperature";


	int Temp2 = 0;		//set second temperature
	string evening = "Evening temperature";

public:

	SmartThermostat();		//default constructor
	SmartThermostat(int Temp1, int Temp2);		// for setting temperature based on day or evening

	void printSettings();		//print what the thermostat is set at

	void setTemp1(int firsttemp);
	int getTemp1();

	void setTemp2(int secondtemp);
	int getTemp2();

	void printSmartThermostatReport(std::ostream& out);		//print report of information from home base class will be a friend function

	void printSmartthermuserinput(SmartThermostat& obj);
};
#endif