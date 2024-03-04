/*

Thaine Koen
12/16/2022
cpp for SmartThermostat class
*/
#include "SmartThermostats.h"
#include <string>
using namespace std;

SmartThermostat::SmartThermostat() {
}		//default constructor
SmartThermostat::SmartThermostat(int temp1, int temp2){
	SmartThermostat::Temp1 = temp1;
	SmartThermostat::Temp2 = temp2;
}		// for setting temperature based on day or evening

void SmartThermostat::printSettings(){}	//print what the thermostat is set at

void SmartThermostat::setTemp1(int firsttemp) {
	Temp1 = firsttemp;
}
int SmartThermostat::getTemp1() {
	return Temp1;
}

void SmartThermostat::setTemp2(int secondtemp) {
	Temp2 = secondtemp;
}
int SmartThermostat::getTemp2() {
	return Temp2;
}

void SmartThermostat::printSmartThermostatReport(std::ostream& out)//writing out to file
{
	out << "The temperature set for the smart thermostat is, Daytime: *" << to_string(getTemp1()) << " Degrees* and Evening: *" << to_string(getTemp2()) << " Degrees*." << endl;
}

void SmartThermostat::printSmartthermuserinput(SmartThermostat& obj)
{
	int daytime, night;

	cout << "You are setting up the smart thermostat!" << endl;
	cout << "You need two temperatures, one for daytime and one for evening." << endl;

	cout << "Input the daytime setting: ";
	cin >> daytime;
	obj.setTemp1(daytime);
	cout << "Input the evening setting: ";
	cin >> night;
	obj.setTemp2(night);
}
