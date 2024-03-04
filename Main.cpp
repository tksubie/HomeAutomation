/*

Thaine Koen
12/16/2022
cpp MAIN for Final project execution
*/
// include all the class header files in the MAIN
 #include <iostream>
#include <fstream>	//for file input and output
#include <string>
#include <iomanip>
#include <stdlib.h> //to clear console screen
//include all of the class headers for different objects
#include "Home.h"
#include "Lights.h"
#include "RobotVaccum.h"
#include "SmartThermostats.h"
#include "Television.h"
#include "SecuritySystem.h"
#include "UDTclass.h"

using namespace std;

int main() {

////My interface

	cout << "Home Automation program!" << endl <<endl;
	cout << "------------------------------" << endl;
	cout << "First you will Input HomeInformation" << endl;
	cout << "Second you can Control the Lights" << endl;
	cout << "Third you will Control the Robot Vaccum" << endl;
	cout << "Fourth you will Control the Security System" << endl;
	cout << "Fifth you will Control the Smart Thermostat" << endl;
	cout << "Sixth you will Control the Television" << endl << endl;
	cout << "------------------------------" << endl;

//declare default home object
Home userinput1;
Lights userinput2;	
RobotVaccum userinput3;
SecuritySystem userinput4;
SmartThermostat userinput5;
Television userinput6;

//pointers for my different objects
Home* tst1 = new Home;
Lights* tst2 = new Lights;
RobotVaccum* tst3 = new RobotVaccum;
SecuritySystem* tst4 = new SecuritySystem;
SmartThermostat* tst5 = new SmartThermostat;
Television* tst6 = new Television;

ofstream H_A_Report;			//write to txt file
H_A_Report.open("HomeAutomationReport.txt", ios::out);		//open file and make the name declared

bool valid;
ifstream H_A_Report_Data;
string mydata;		//to hold the contents of the txt file

do {
	int input;
	cout << "What would you like to do? " << endl;
	cout << "1 - Start an input into the home system. (This creates a text file as well)" << endl;
	cout << "2 - Print the results to console." << endl;
	cout << "0 - End the program." << endl;
	
	cout << endl << "Input here --> ";
	cin >> input;

	switch (input) {

	case 1:

		cout << "------------------------------" << endl;
		cout << "Inputing Home Information" << endl;
		cout << "------------------------------" << endl;
		tst1->userHomeinput(userinput1);


		//Lights
		cout << "------------------------------" << endl;
		cout << "Controling the Lights" << endl;
		cout << "------------------------------" << endl;
		tst2->printLightuserinput(userinput2);


		//Robot Vaccuum
		cout << "------------------------------" << endl;
		cout << "Controling the Robot Vaccum" << endl;
		cout << "------------------------------" << endl;
		tst3->printRVuserinput(userinput3);


		//Security System
		cout << "------------------------------" << endl;
		cout << "Controling the Security System" << endl;
		cout << "------------------------------" << endl;
		tst4->printSsuserinput(userinput4);


		//Smart Thermostat
		cout << "------------------------------" << endl;
		cout << "Controling the Smart Thermostat" << endl;
		cout << "------------------------------" << endl;
		tst5->printSmartthermuserinput(userinput5);


		//Television
		cout << "------------------------------" << endl;
		cout << "Controling the Television" << endl;
		cout << "------------------------------" << endl;
		tst6->printtvuserinput(userinput6);

		//system("CLS");	//clear the screen for visibility

		//create text file
		H_A_Report << "------------------------------" << endl;
		userinput1.printHomeReport(H_A_Report);
		H_A_Report << "------------------------------" << endl;
		userinput2.printLightsReport(H_A_Report);
		H_A_Report << "------------------------------" << endl;
		userinput3.printRVReport(H_A_Report);
		H_A_Report << "------------------------------" << endl;
		userinput4.printSecuritySystemReport(H_A_Report);
		H_A_Report << "------------------------------" << endl;
		userinput5.printSmartThermostatReport(H_A_Report);
		H_A_Report << "------------------------------" << endl;
		userinput6.printTelevisionReport(H_A_Report);
		H_A_Report << "------------------------------" << endl;

		cout << "------------------------------" << endl;
		cout << endl << "Writing information to a file being created called 'HomeAutomatitionReport.txt'..." << endl;
		H_A_Report << endl;	//end the write
		cout << "Closing 'HomeAutomatitionReport.txt'..." << endl;
		cout << "------------------------------" << endl;
		H_A_Report.close();		//close text file
		valid = false;
		
		break;
	case 2:
		H_A_Report_Data.open("HomeAutomationReport.txt");		//open the text file

		if (H_A_Report_Data.is_open()) {		//open my file I just previously made

			while (H_A_Report_Data) { // if I can open it we get the contents 

				getline(H_A_Report_Data, mydata);
				cout << mydata << endl;		//display the contents
			}
		}
		else {		//if the file didn't exists

			cout << "**ERROR File name wrong, or file does not exist**";
		}
		
		valid = false;
		break;
	case 0:
		cout << "Program ended.";
		//delete pointers info with UDT and set to 0
		deletePointers<Home>(tst1);
		deletePointers<Lights>(tst2);
		deletePointers<RobotVaccum>(tst3);
		deletePointers<SecuritySystem>(tst4);
		deletePointers<SmartThermostat>(tst5);
		deletePointers<Television>(tst6);

		valid = true;
		break;
	default:
		//system("CLS");	//clear the screen for visibility
		cout << "Program Ended invalid input";
		//delete pointers info with UDT and set to 0
		deletePointers<Home>(tst1);
		deletePointers<Lights>(tst2);
		deletePointers<RobotVaccum>(tst3);
		deletePointers<SecuritySystem>(tst4);
		deletePointers<SmartThermostat>(tst5);
		deletePointers<Television>(tst6);
		valid = true;
		break;
	}
} while (!valid);







	
	return 0;

	}

