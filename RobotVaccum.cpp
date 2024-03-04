/*

Thaine Koen
12/16/2022
cpp for RobotVaccum class
*/

#include "RobotVaccum.h"
#include <string>

using namespace std;


RobotVaccum::RobotVaccum(){};		//default constructor
RobotVaccum::RobotVaccum(int onOff, int usetype){		//constructor for manual
	Home::OnOff = onOff;
	if (OnOff != 0 && OnOff != 1) { OnOff = 1; }		//default turn off
	RobotVaccum::setting = usetype;
	if (setting != 0) { setting = 0; }		//error if usetype is not equal to 1 but this constructor is used, it is set to manual
}	
RobotVaccum::RobotVaccum(int onOff, int usetype, int firsttime, int secondtime){		//constructor for automatic function
	Home::OnOff = onOff;
	if (OnOff != 0 && OnOff != 1) { OnOff = 1; }		//default turn off
	RobotVaccum::setting = usetype;
	if (setting != 1) { setting = 1; }		//error if usetype is not equal to 2 but this constructor is used, it is set to automatic
	RobotVaccum::time1 = firsttime;
	RobotVaccum::time2 = secondtime;
}		

// setters and getters for protected values

void RobotVaccum::setTime1(int firsttime){
	time1 = firsttime;
}
int RobotVaccum::getTime1(){
	return time1;
}

void RobotVaccum::setTime2(int secondtime){
	time2 = secondtime;
}
int RobotVaccum::getTime2(){
	return time2;
}
void RobotVaccum::setOnOff(int onoff)
{
	Home::OnOff = onoff;
}

int RobotVaccum::getOnOff()
{
	return Home::OnOff;
}

void RobotVaccum::setUseType(int usetype)
{
	RobotVaccum::setting = usetype;
	if (setting != 1) { setting = 1; }		//error if usetype is not equal to 2 but this constructor is used, it is set to automatic
}

int RobotVaccum::getUseType()
{
	return setting;
}

void RobotVaccum::printRVReport(std::ostream& out)//writing out to file
{
	if (OnOff == 1) {
		out << "Robot Vaccum is Offline.";		//if it is selected to be off it is ofline no matter the constructor
	}
	else {
		if (setting == 0) {
			out << "The Robot Vaccum is set to *" << useType[setting] << "* and is set to be *" << Home::setOnOff[OnOff] << "*." << endl;		//manual setting
		}
		else
			out << "The Robot Vaccum is set to *" << useType[setting] << "* and is set to be *" << Home::setOnOff[OnOff] << "* during the times of *" << to_string(getTime1()) << " and " << to_string(getTime2()) << "*." << endl;	//auto setting
	}
}

void RobotVaccum::printRVuserinput(RobotVaccum& obj)
{
	//For RV
	int control;
	int allonoff;
	int time_1;
	int time_2;

	cout << "Would you like to control the Robot vaccum Manually(1) or Automatically(2)? ";
	cin >> control;
	switch (control) {

	case 1:
		cout << "Turn Robot Vaccum  ON(0) or OFF(1): ";
		cin >> allonoff;
		obj.setOnOff(allonoff);
		obj.setUseType(0);
		break;

	case 2:
		cout << "Turn Robot Vaccum  ON(0) or OFF(1): ";
		cin >> allonoff;
		obj.setOnOff(allonoff);
		obj.setUseType(1);
		cout << "Now input the time range from HHMM to HHMM to be on or off automatically?" << endl;
		cout << "Time 1: ";
		cin >> time_1;
		cout << "Time 2: ";
		cin >> time_2;
		obj.setTime1(time_1);
		obj.setTime2(time_2);
		break;
	default:
		cout << "Vaccum is Offline no valid input." << endl;

		break;


	}
}

