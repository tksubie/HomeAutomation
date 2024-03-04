/*

Thaine Koen
12/16/2022
Header for Home base class
*/
#ifndef Home_H
#define Home_H
#include <iostream>
#include <vector>


using namespace std;

class Home {

private:

	string FullName = "Nothing";		//users name
	string Address = "Nothing";			//users address

protected:

	string Month;
	string	Day;
	string	Year;
	string time;		//use time in whole numbers from 24 hour format
	
	int Temperature = 70;		//default temperature


public:
	string setOnOff[2]={"On","Off"}; // all classes will use onoff so declaring it now for use in derived classes
	int OnOff = 0;

	Home();		//default constructor
	Home(string name, string address, string month, string day, string year, string currentTime);		//setup the program for user to run

	//setters and getters for my values I want to use in the private and protected members



	void setFullName(string fullname);
	string getFullName();

	void setAddress(string address);
	string getAddress();

	void setMonth(string month);
	string getMonth();

	void setDay(string day);
	string getDay();

	void setYear(string Year);
	string getYear();

	void setTime(string currentTime);
	string getTime();

	void setTemp(int temp);
	int getTemp();

	void printHomeReport(std::ostream& out);		//print report of information

	void userHomeinput(Home& obj);
};
#endif