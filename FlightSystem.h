/*
* FlightSystem.h
* Version information v0.1
* Author: Matthew Webster b00714308
*/

#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Aircraft.h"

class FlightSystem {
	//declares the aircraft list vector that will store the aircraft in the system
private:
	std::vector<Aircraft> aircraftList_;
	//declares the methods to be used in flightsystem.cpp
public:
	void AddAircraft(std::string flightNumber, std::string airline, std::string aircraftType, std::string gridReference, int groundspeed, int altitude, int heading);
	std::vector<Aircraft> ListAllAircraft();
	std::vector<Aircraft> ListAllCruisingAircraft();
	int numAircraftInSector();	
	void RemoveAircraft(std::string flightNumber);
	void ChangeHeading(std::string flightNumber, int heading);
	int GetHeading(std::string flightNumber);
	void ChangeAltitude(std::string flightNumber, int altitude);
	int GetAltitude(std::string flightNumber);
	void CollisionDetection(std::string flightNumber,int altitude,std::string gridReference);

};