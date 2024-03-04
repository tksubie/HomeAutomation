#pragma once
/*

Thaine Koen
12/16/2022
Header for Lights class
*/
#ifndef Lights_H
#define Lights_H
#include "Home.h"
#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Lights : virtual public Home {

protected:

	string roomChoice = "Home";		//default
	int allOnOff = 0;		//flag for all  on or off

public:

	Lights();		//default constructor
	Lights(int onOff);		// turn all lights on or off
	Lights(int onOff, string roomchoice);		//declare number of room in the house and choose a room to turn on or off
	
	void setRoomChoice(string roomchoice);
	string getRoomChoice();

	void setOnOff(int onoff);
	int getOnOff();

	void printLightsReport(std::ostream& out);		//print report of information from home base class will be a friend function

	void printLightuserinput(Lights& obj);


};
#endif