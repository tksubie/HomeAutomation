/*

Thaine Koen
12/16/2022
cpp for Home base class
*/
#include "Home.h"
#include <iostream>
#include <string>
using namespace std;


Home::Home(){

}		//default constructor

Home::Home(string name, string address, string month, string day, string year, string currentTime) {		//constructor with user information

	Home::FullName = name;
	Home::Address = address;
	Home::Month = month;
	Home::Day = day;
	Home::Year = year;
	Home::time = currentTime;

}

void Home::setFullName(string fullname) {		// get full name
	FullName = (fullname);
}
string Home::getFullName() {
	return FullName;
}

void Home::setAddress(string address) {		//get address
	Address = address;
}
string Home::getAddress() {
	return Address;
}

void Home::setMonth(string month) {		// get month
	Month = month;
	
}

string Home::getMonth() {
	return Month;
}

void Home::setDay(string day) {		//get day
	Day = day;
}
string Home::getDay() {
	return Day;
}

void Home::setYear(string year) {		//set year
	Year = year;
}
string Home::getYear() {
	return Year;
}

void Home::setTime(string currentTime) {	//set time in 24 hour format for example 1300, 1330
	time = currentTime;
}
string Home::getTime() {
	return time;
}

void Home::setTemp(int temp) {		//set a default temp
	Temperature = temp;
}
int Home::getTemp() {
	return Temperature;
}

void Home::printHomeReport(std::ostream& out) { //writing out to file
	out << "Home information as follows:" << endl << endl;
	out << "Name: " << getFullName() << endl;
	out << "Address: " << getAddress() << endl;
	out << "Date: " << getMonth() << "/" << getDay() << "/" << getYear() << endl;
	out << "Time: " << getTime() << endl;

}		//print report of information

void Home::userHomeinput(Home& obj)
{
	string fullname;
	string address;
	string month;
	string day;
	string year;
	string currenttime;

	cout << "Enter your full name: ";
	getline(cin >> ws, fullname);
	obj.setFullName(fullname);
	cout << "Enter your address, street, city, state, ZipCode: ";
	getline(cin >> ws, address);
	obj.setAddress(address);
	cout << "Enter the current month as a number: ";
	cin >> month;
	obj.setMonth(month);
	cout << "Enter the current day as a number: ";
	cin >> day;
	obj.setDay(day);
	cout << "Enter the current year: ";
	cin >> year;
	obj.setYear(year);
	cout << "Enter the current time in 24 hour format HHMM: ";
	cin >> currenttime;
	obj.setTime(currenttime);

}
