/*
* Main.cpp
* Version information v0.1
* Author: Matthew Webster b00714308
*/

#include <iostream>
#include <string>
#include <vector>
#include "regex"
#include "FlightSystem.h"

using namespace std;

int main() {

	FlightSystem aircraft1;	
	int answer;
	
	//the menu for the user	
	do {
		std::cout << "\n--------------------------------------------------\n" << endl;
		std::cout << "Please Choose what you would like to do" << endl;
		std::cout << "1: Add an aircraft to the system" << endl;
		std::cout << "2. List all aircraft on the system" << endl;
		std::cout << "3. List all cruising aircraft in the system" << endl;
		std::cout << "4. Change heading of an aircraft in the system" << endl;
		std::cout << "5. Change altitude of an aircraft in the system" << endl;	
		std::cout << "6. Remove an aircraft from the system" << endl;
		std::cout << "7. Number of aircraft in sector" << endl;
		std::cout << "8. Close the application" << endl;
		
		std::string flightNumber_;
		std::string airline_;
		std::string aircraftType_;
		std::string gridReference_;
		int groundspeed_;
		int altitude_;
		int heading_;
		
		bool menu = true;
		
		if (menu)
		{
						
			std::cin >> answer;
			switch (answer) {
			case 1:
			{
				std::cout << "Add an aircraft to the system\n" << endl;
				std::cout << "Please Enter Flight Number" << endl;
				std::cin >> flightNumber_;
				std::cout << "Please enter Airline" << endl;
				std::cin >> airline_;
				std::cout << "Please enter Aircraft Type" << endl;
				std::cin >> aircraftType_;
				std::cout << "Please enter Grid Reference" << endl;
				std::cin >> gridReference_;
				std::cout << "Please enter Groundspeed" << endl;
				std::cin >> groundspeed_;
				std::cout << "Please enter Altitude" << endl;
				std::cin >> altitude_;
				std::cout << "Please enter Heading" << endl;
				std::cin >> heading_;

				//add object to vector

				aircraft1.AddAircraft(flightNumber_, airline_, aircraftType_ ,gridReference_, groundspeed_, altitude_, heading_);
			}
			break;

			//prints out the aircraft on the system
			case 2:
			{
				std::cout << "Flight Number:\tAirline:\tAircraft Type:\tGrid Reference:\tGround Speed:\tAltitude:\tHeading:" << endl;
				std::vector<Aircraft>temporary;
				temporary = aircraft1.ListAllAircraft();
				for (int i = 0; i < temporary.size(); i++) {
					std::cout << temporary[i].GetFlightNumber()
						<< "\t\t" << temporary[i].GetAirline()
						<< "\t\t" << temporary[i].GetAircraftType()
						<< "\t\t" << temporary[i].GetGridReference()
						<< "\t\t" << temporary[i].GetGroundSpeed()
						<< "\t\t" << temporary[i].GetAltitude()
						<< "\t\t" << temporary[i].GetHeading();
				} 
			}
			break;
			//priints the aircraft above 30000ft 
			{
			case 3: std:cout << "Cruising aircraft in the system\n" << endl;
				std::cout << "Flight Number:\tAirline:\tAircraft Type:\tGrid Reference:\tGround Speed:\tAltitude:\tHeading:" << endl;
				std::vector<Aircraft>temporary;
				temporary = aircraft1.ListAllCruisingAircraft();
			}
			break;
			//allows the user to remove an aircraft from the system
			{
			case 4: std::cout << "Enter a flight number to change the heading of an aircraft in the system\n" << endl;
				std::cin >> flightNumber_;					
				aircraft1.GetHeading(flightNumber_);
				std::cout << "Enter the new heading for this aircraft" << endl;		
				std::cin >> heading_;
				aircraft1.ChangeHeading(flightNumber_,heading_);			 				
			}
			break;
			//allows the user to change altitude of an aircraft in the system and calls the collision detection method
			{
			case 5: std::cout << "Enter a flight number to change the altitude of an aircraft in the system\n" << endl;
				std::cin >> flightNumber_;
				aircraft1.GetAltitude(flightNumber_);											
				std::cout << "Enter the new altitude for this aircraft" << endl;
				std::cin >> altitude_;
				aircraft1.ChangeAltitude(flightNumber_, altitude_);	 				
			}
			break;
			//allows the user to remove an aircraft from the system
			{
			case 6: std::cout << "Remove an aircraft from the system\n" << endl;
				aircraft1.RemoveAircraft(flightNumber_);				
			}
			break;
			//prints out the number of aircraft in the system
			{
			case 7: std::cout << "Number of aircraft in sector" << endl;
				std::cout << aircraft1.numAircraftInSector() << endl; 				
			}
			break;
			//application closes when the number '8' is input
			{
			case 8: std::cout << "Closing Application" << endl; 
			}
			}
		}
	} while (answer != 8);
	return 0;
}