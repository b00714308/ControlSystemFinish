/*
* Aircraft.cpp
* Version information v0.1
* Author: Matthew Webster b00714308
*/

#include <iostream>
#include <string>
#include "Aircraft.h"

Aircraft::~Aircraft()
{
}

Aircraft::Aircraft()
{
}

Aircraft::Aircraft(std::string flightNumber, std::string airline, std::string aircraftType, std::string gridReference, int groundspeed, int altitude, int heading) :
	flightNumber_{ flightNumber }, airline_{ airline }, aircraftType_{ aircraftType }, gridReference_{ gridReference }, groundspeed_{ groundspeed }, altitude_{ altitude },heading_{ heading } {
}
//declares the setters and getters for each variable
void Aircraft::SetFlightNumber(std::string flightNumber) {
	flightNumber_ = flightNumber;
}
std::string Aircraft::GetFlightNumber() const {
	return flightNumber_;
}
void Aircraft::SetAirline(std::string airline) {
	airline_ = airline;
}
std::string Aircraft::GetAirline() const {
	return airline_;
}
void Aircraft::SetAircraftType(std::string aircraftType) {
	aircraftType_ = aircraftType;
}
std::string Aircraft::GetAircraftType() const {
	return aircraftType_;
}
void Aircraft::SetGridReference(std::string gridReference) {
	gridReference_ = gridReference;
}
std::string Aircraft::GetGridReference() const {
	return gridReference_;
}
void Aircraft::SetGroundSpeed(int groundspeed) {
	groundspeed_ = groundspeed;
}
int Aircraft::GetGroundSpeed() const {
	return groundspeed_;
}
void Aircraft::SetAltitude(int altitude) {
	altitude_ = altitude;
}
int Aircraft::GetAltitude() const {
	return altitude_;
}
void Aircraft::SetHeading(int heading) {
	heading_ = heading;
}
int Aircraft::GetHeading() const {
	return heading_;
}