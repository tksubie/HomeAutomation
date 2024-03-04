/*

Thaine Koen
12/16/2022
cpp for Television class
*/
#include "Television.h"
#include <string>
using namespace std;

Television::Television() {
	Home::OnOff = 1;
}	//default constructor
Television::Television(int onoff, int Setting, int channel)		//for manual use usetype 1
{
	Home::OnOff = onoff;
	if (OnOff != 0 && OnOff != 1) { OnOff = 1; }		//default turn off
	Television::setting = Setting;
	if (setting != 0) { setting = 0; }		//error if usetype is not equal to 0 but this constructor is used, it is set to manual
	Television::Channel = channel;
}
	
Television::Television(int onoff, int Setting, int daySelection, int Time){		//for automatic use usetype 2 
	Home::OnOff = onoff;
	if (OnOff != 0 && OnOff != 1) { OnOff = 1; }		//default turn off
	Television::setting = Setting;
	if (setting != 1) { setting = 1; }		//error if usetype is not equal to 1 but this constructor is used, it is set to automatic
	Television::dayselection = daySelection;
	if (dayselection != 0 && dayselection != 1) { dayselection = 1; };		//if input is invalid default selection for auto is every other day
	Television::time = Time;
}

void Television::setOnOff(int onoff)
{
	Home::OnOff = onoff;
	if (OnOff != 0 && OnOff != 1) { OnOff = 1; }		//default turn off

}

int Television::getOnOff()
{
	return Home::OnOff;
}

void Television::setUseType(int usetype)
{
	Television::setting = usetype;
	if (setting != 0 && setting != 1) { setting = 0; }		//error if usetype is not equal to 0 but this constructor is used, it is set to manual
}

int Television::getUseType()
{
	return setting;
}

void Television::printdayselection() {
	cout << "**Day selection is as follows**" << endl;
	cout << "Selection #0 - " << day[0] << endl;
	cout << "Selection #1 - " << day[1] << endl;
}		// to display settings you can choose

void Television::setDaySelection(int ds)
{
	Television::dayselection = ds;
	if (dayselection != 0 && dayselection != 1) { dayselection = 1; };		//if input is invalid default selection for auto is every other day
}

int Television::getDaySelection()
{
	return dayselection;
}

void Television::setChannel(int channel) {
	Channel = channel;
}
int Television::getChannel() {
	return Channel;
}

void Television::setTime(int Time) {
	time = Time;
}
int Television::getTime() {
	return time;
}


void Television::printTelevisionReport(std::ostream& out)//writing out to file
{
	if (OnOff == 1) {
		out << "The Television is turned off.";
	}
	
	else {
		if (setting == 0) {
			out << "The Television is set to *" << useType[getUseType()] << "* and is set to be *" << Home::setOnOff[OnOff] << "* on channel *" << to_string(getChannel()) << "*." << endl;		//manual setting
		}
		else
			out << "The Television is set to *" << useType[getUseType()] << "* and is set to be *" << Home::setOnOff[OnOff] << "* " << day[getDaySelection()] << " at the time of *" << to_string(getTime()) << "* turning off 15 minutes later." << endl;	//auto setting
	}
}

void Television::printtvuserinput(Television& obj)
{

	//For TV
	int control;
	int allonoff;
	int channel;
	int dselection;
	int time_1;
	

	cout << "Would you like to control the TV Manually(1) or Automatically(2)? ";
	cin >> control;
	switch (control) {

	case 1:
		cout << "Turn the TV  ON(0) or OFF(1): ";
		cin >> allonoff;
		obj.setOnOff(allonoff);
		cout << "What channel do you want the TV set to? ";
		cin >> channel;
		obj.setChannel(channel);
		obj.setUseType(0);
		break;

	case 2:
		
		cout << "Turn the TV  ON(0) or OFF(1): ";
		cin >> allonoff;
		obj.setOnOff(allonoff);
		cout << "What channel do you want the TV set to? ";
		cin >> channel;
		obj.setChannel(channel);
		
		obj.printdayselection();
		cout << "What time input would you like auto set to? ";
		cin >> dselection;
		obj.setDaySelection(dselection);
		cout << "Now input the time HHMM to be on automatically?" << endl;
		cout << "Time: ";
		cin >> time_1;
		obj.setTime(time_1);

		obj.setUseType(1);

		break;
	default:
		cout << "TV is Off no valid input." << endl;
		obj.setOnOff(1);

		break;


	}
}
