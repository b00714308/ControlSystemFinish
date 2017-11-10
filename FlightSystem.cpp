/*
* FlightSystem.cpp
* Version information v0.1
* Author: Matthew Webster b00714308
*/
#include <iostream>
#include <string>
#include <vector>
#include "Aircraft.h"
#include "FlightSystem.h"

//method for adding an aircraft to the system
void FlightSystem::AddAircraft(std::string flightNumber, std::string airline, std::string aircraftType, std::string gridReference, int groundspeed, int altitude, int heading) {
	
	bool isThere = false;
	
	aircraftList_;
	Aircraft aircraft1(flightNumber, airline, aircraftType, gridReference, groundspeed, altitude, heading);		

	for (int i = 0; i < aircraftList_.size(); i++) {
		if (flightNumber == aircraftList_.at(i).GetFlightNumber())
		{
			isThere = true;
		}
	}
	if (isThere == false) 
	{
		aircraftList_.push_back(aircraft1);		
		CollisionDetection(flightNumber,altitude,gridReference);
		std::cout << "You have successfully added an aircraft!" << std::endl;		
	}
	else 
	{
		std::cout << "Flight " << flightNumber << " already in the system";		
	}
	}
//method for listing all aircraft on the system
std::vector<Aircraft> FlightSystem::ListAllAircraft()
{	
	return aircraftList_;
}
std::vector<Aircraft> FlightSystem::ListAllCruisingAircraft() {
	aircraftList_;

	for (int i = 0; i < aircraftList_.size(); i++)
	{
		if (aircraftList_.at(i).GetAltitude() >= 30000)
		{
			std::cout << aircraftList_.at(i).GetFlightNumber() << "\t\t" 
				<< aircraftList_.at(i).GetAirline() << "\t\t" 
				<< aircraftList_.at(i).GetAltitude() << "\t\t"
				<< aircraftList_.at(i).GetGroundSpeed() << "\t\t" 
				<< aircraftList_.at(i).GetGridReference() << "\t\t" 
				<< aircraftList_.at(i).GetHeading() << std::endl;
		}
	}

	return aircraftList_;
}
//method for removing an aircraft from the system
void FlightSystem::RemoveAircraft(std::string flightNumber) {
	
	bool isThere = false;
	
	aircraftList_;

	std::cout << "Please enter flightnumber" << std::endl;
	std::cin >> flightNumber;
	for (int i = 0; i < aircraftList_.size(); i++) {
		if (aircraftList_.at(i).GetFlightNumber() == flightNumber)
		{
			isThere = true;
			aircraftList_.erase(aircraftList_.begin() + i);
			std::cout << "Flight " << flightNumber << " has been removed from the system\n" << std::endl;			
		}
		if (isThere == false)
		{
			std::cout << "Flight " << flightNumber << " is not in the system\n" << std::endl;			
		}
	}

}
//method for changing the heading of an aircraft in the system
void FlightSystem::ChangeHeading(std::string flightNumber, int heading) {
	bool exist = false;

	for (int i = 0; i < aircraftList_.size(); i++)
	{
		if (aircraftList_.at(i).GetFlightNumber() == flightNumber) {
			exist = true;
			aircraftList_.at(i).SetHeading(heading);
			std::cout << "Heading of flight " << flightNumber << " changed to " << heading << std::endl;
			break;
		}
	}
	if (exist == false)
	{
		std::cout << "Flight " << flightNumber << " is not in the system" << std::endl;
	}
}
//method for getting the heading of an aircraft in the system to allow the change to happen
int FlightSystem::GetHeading(std::string flightNumber) {
	bool exist = false;

	for (int i = 0; i < aircraftList_.size(); i++)
	{
		if (aircraftList_.at(i).GetFlightNumber() == flightNumber) {
			exist = true;
			return aircraftList_.at(i).GetHeading();
		}
	}	
}
//method for changing the altitude of an aircraft in the system
void FlightSystem::ChangeAltitude(std::string flightNumber, int altitude) {
	bool exist = false;	

	for (int i = 0; i < aircraftList_.size(); i++) {
		if (aircraftList_.at(i).GetFlightNumber() == flightNumber) {
			bool exist = true;
			aircraftList_.at(i).SetAltitude(altitude);			
		}
	}
	if (exist == false) {
		std::cout << "Flight " << flightNumber << " is not in the system" << std::endl;
	}

}
//method for getting the altitude of an aircraft in the system to allow the change to happen
int FlightSystem::GetAltitude(std::string flightNumber) {
	bool exist = false;

	for (int i = 0; i < aircraftList_.size(); i++) {
		if (aircraftList_.at(i).GetFlightNumber() == flightNumber) {
			exist = true;
			return aircraftList_.at(i).GetAltitude();			
		}
	}
	std::cout << "Flight " << flightNumber << " is not in the system" << std::endl;
}
//method for showing the number of aircraft in the sector
int FlightSystem::numAircraftInSector() {
	{
		return aircraftList_.size();
	}
}
//method for detecting possible collisions for aircraft within the system
void FlightSystem::CollisionDetection(std::string flightNumber, int altitude, std::string gridReference)
{
	Aircraft tempplane;

	for (int i = 0; i < aircraftList_.size(); i++) {
		if ((aircraftList_.at(i).GetGridReference() == gridReference) &&
			(altitude >= aircraftList_.at(i).GetAltitude() - 3000 && altitude <= aircraftList_.at(i).GetAltitude() + 3000))
			
			if (aircraftList_.at(i).GetFlightNumber() != flightNumber) {
				tempplane = ListAllAircraft().at(i);
				std::cout << "Warning - Aircraft collision possible between " << flightNumber << " and " << tempplane.GetFlightNumber() << std::endl;
			}
	}
	
}
