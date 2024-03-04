/*

Thaine Koen
12/16/2022
cpp for Lights class
*/
#include "Lights.h"
#include <iostream>
#include <string>

using namespace std;


Lights::Lights(){		//default constructor
}			
Lights::Lights(int onOff){			// turn all lights on or off
	Home::OnOff = onOff;
	if (OnOff != 0 && OnOff != 1) { OnOff = 1; }		//default turn off
	allOnOff = 1;
}		
Lights::Lights( int onOff, string roomchoice){		// turn lights on or off in certain room
	Lights::Home::OnOff = onOff;
	if (OnOff != 0 && OnOff != 1) { OnOff = 1; }		//default turn off
	Lights::roomChoice = roomchoice;

}

void Lights::setRoomChoice(string roomchoice){
	roomChoice = roomchoice;

}
string Lights::getRoomChoice(){
	return roomChoice;
}

void Lights::setOnOff(int onoff)
{
	Home::OnOff = onoff;
}

int Lights::getOnOff()
{	
	return Home::OnOff;
}

void Lights::printLightsReport(std::ostream& out)//writing out to file
{
	//exception handling
	try {
		if (allOnOff == 1) {
			out << "You have turned all the lights in the home *" << Home::setOnOff[OnOff] << "*." << endl;
		}
		else {
			throw (allOnOff);
			
		}
	}
	catch (int allOnOff) {
		out << "You have turned the lights *" << Home::setOnOff[OnOff] << "* " << "in the " << getRoomChoice() << "." << endl;
	}
}

void Lights::printLightuserinput(Lights& obj)
{
	//For Lights
	int control;
	int allonoff;
	string roomcontrol;

	cout << "Would you like to control all of the lights (1) or pick a room and control the lights (2)? ";
	cin >> control;
	switch (control) {

	case 1:
		cout << "Turn all the lights 0 - ON, 1 - OFF: ";
		cin >> allonoff;
		obj.setOnOff(allonoff);
		break;

	case 2:
		cout << "What room would you like to control the lights in? ";
		getline(cin >> ws, roomcontrol);
		obj.setRoomChoice(roomcontrol);
		cout << "Control the lights in " << roomcontrol << " 0 - ON, 1 - OFF? ";
		cin >> allonoff;
		obj.setOnOff(allonoff);

		break;
	default:
		cout << "You did not input 1 or 2! " << endl;

		break;


	}
}
