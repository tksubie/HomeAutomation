/*

Thaine Koen
12/16/2022
cpp for SecuritySystem class
*/
#include "SecuritySystem.h"
#include <string>
using namespace std;

SecuritySystem::SecuritySystem(){}		//default constructor
SecuritySystem::SecuritySystem(int onoff, int usetype, int sensitivitySetting){
	Home::OnOff = onoff;
	if (OnOff != 0 && OnOff != 1) { OnOff = 1; }		//default turn off
	SecuritySystem::setting = usetype;
	if (setting != 0) { setting = 0; }		//error if usetype is not equal to 0 but this constructor is used, it is set to manual
	SecuritySystem::sSetting = sensitivitySetting;
	if (sSetting < 1 || sSetting >5) { sSetting = 5; }		//error if setting is not vaild default to most sensitive 5
}	//for maual operation use 0

SecuritySystem::SecuritySystem(int onoff, int usetype, int sensitivitySetting, int time1, int time2){
	Home::OnOff = onoff;
	if (OnOff != 0 && OnOff != 1) { OnOff = 1; }		//default turn off
	SecuritySystem::setting = usetype;
	if (setting != 1) { setting = 1; }		//error if usetype is not equal to 1 but this constructor is used, it is set to automatic
	SecuritySystem::Time1 = time1;
	SecuritySystem::Time2 = time2;
	SecuritySystem::sSetting = sensitivitySetting;
	if (sSetting < 1 || sSetting > 5) { sSetting = 5; }		//error if setting is not vaild default to most sensitive 5
}		//for automatic setting use 1

void SecuritySystem::setTime1(int time1){
	Time1 = time1;
}
int SecuritySystem::getTime1() {
	return Time1;
}

void SecuritySystem::setTime2(int time2) {
	Time2 = time2;
}
int SecuritySystem::getTime2() {
	return Time2;
}

void SecuritySystem::setOnOff(int onoff)
{
	Home::OnOff = onoff;
	if (OnOff != 0 && OnOff != 1) { OnOff = 1; }		//default turn off
}

int SecuritySystem::getOnOff()
{
	return Home::OnOff;
}

void SecuritySystem::setSensS(int sensitivitySetting)
{
	SecuritySystem::sSetting = sensitivitySetting;
	if (sSetting < 1 || sSetting >5) { sSetting = 5; }		//error if setting is not vaild default to most sensitive 5
}

int SecuritySystem::getSensS()
{
	return sSetting;
}

void SecuritySystem::setUseType(int usetype)
{
	SecuritySystem::setting = usetype;
	if (usetype != 0 && usetype != 1) { setting = 0; }		//error if usetype is not equal to 0 but this constructor is used, it is set to manual
}

int SecuritySystem::getUseType()
{
	return setting;
}


void SecuritySystem::printSecuritySystemReport(std::ostream& out) {//writing out to file
	if (OnOff == 1) {
		out << "Security System is Offline.";		//if it is set to off you wont see any other data

	}
	else {
		if (setting == 0) {
			out << "The Security system is set to *" << useType[setting] << "* and is set to be *" << Home::setOnOff[OnOff] << "* with a sensitivity of *" << to_string(sensitivityRating[sSetting]) << "*." << endl;		//manual setting
		}
		else
			out << "The Security system is set to *" << useType[1] << "* and is set to be *" << Home::setOnOff[OnOff] << "* during the times of *" << to_string(getTime1()) << " and " << to_string(getTime2()) << "* with a sensitivity of *" << to_string(sensitivityRating[sSetting]) << "*." << endl;	//auto setting

	}
}

void SecuritySystem::printSsuserinput(SecuritySystem& obj)
{
	//For Ss
	int control;
	int allonoff;
	int sensS;
	int time_1;
	int time_2;

	cout << "Would you like to control the Security System Manually(1) or Automatically(2)? ";
	cin >> control;
	switch (control) {

	case 1:
		cout << "Turn the Security System  ON(0) or OFF(1): ";
		cin >> allonoff;
		obj.setOnOff(allonoff);
		cout << "What would you like the sensitivity setting at, 1-5? ";
		cin >> sensS;
		obj.setSensS(sensS);
		obj.setUseType(0);
		break;

	case 2:
		obj.setUseType(1);
		cout << "Turn Security System  ON(0) or OFF(1): ";
		cin >> allonoff;
		obj.setOnOff(allonoff);
		cout << "What would you like the sensitivity setting at, 1-5? ";
		cin >> sensS;
		obj.setSensS(sensS);
		cout << "Now input the time range from HHMM to HHMM to be on or off automatically?" << endl;
		cout << "Time 1: ";
		cin >> time_1;
		obj.setTime1(time_1);
		cout << "Time 2: ";
		cin >> time_2;
		obj.setTime2(time_2);
		
		break;
	default:
		cout << "Security System is Offline no valid input." << endl;

		break;


	}	
	
}
