/*
* Aircraft.h
* Version information v0.1
* Author: Matthew Webster b00714308
*/

#pragma once

#include <iostream>
#include <string>

class Aircraft {
	//declares the private variables for the aircraft to be used 
private:
	std::string flightNumber_;
	std::string airline_;
	std::string aircraftType_;
	std::string gridReference_;
	int groundspeed_;
	int altitude_;
	int heading_;

	//declares the setters and getters for the aircraft to be used
public:
	Aircraft();
	
	Aircraft(std::string flightNumber, std::string airline, std::string aircraftType, std::string gridReference, int groundspeed, int altitude, int heading);
	~Aircraft();
	
	void SetFlightNumber(std::string flightNumber);
	std::string GetFlightNumber() const;

	void SetAirline(std::string airline);
	std::string GetAirline() const;

	void SetAircraftType(std::string aircraftType);
	std::string GetAircraftType() const;

	void SetGridReference(std::string gridReference);
	std::string GetGridReference() const;

	void SetGroundSpeed(int groundspeed);
	int GetGroundSpeed() const;

	void SetAltitude(int altitude);
	int GetAltitude() const;

	void SetHeading(int heading);
	int GetHeading() const;
};