/*******************************************************************************
/ MODULE:  aircraft.cpp
/ AUTHOR:  Jovan Rayhaga
/ PURPOSE: Implementations for the Aircraft class. Providing constructors, destructor,
           and member functions for managing and calculating aircraft details.
/
/          (c) 2023 CCCOnline
*******************************************************************************/

#include "aircraft.h"
#include "piperAircraft.h"
#include "cessnaAircraft.h"

using namespace std;

Aircraft::Aircraft() // default constructor
{
    regNumber = "";
    manufacturer = "";
    basicEmptyWeight = 0.0;
    ArmAftDatum = 0.0;
    BasicemptyMoment = 0.0;
    frontArm = 0.0;
    passengersArm = 0.0;
    baggageArm = 0.0;
    fuelArm = 0.0;
    maximumRampWeight = new double(0.0);  // Dynamic allocation
    maximumTakeoffWeight = 0.0;
    maximumLandingWeight = 0.0;
    cgRangeFwd = 0.0;
    cgRangeAft = 0.0;
}

Aircraft::Aircraft(const std::string& regNumber, const std::string& manufacturer, double basicEmptyWeight, double ArmAftDatum, double BasicemptyMoment, double frontArm, double passengersArm, double baggageArm, double fuelArm, double maximumTakeoffWeight, double maximumLandingWeight, double cgRangeFwd, double cgRangeAft) // overloaded constructor
{
    this->regNumber = regNumber;
    this->manufacturer = manufacturer;
    this->basicEmptyWeight = basicEmptyWeight;
    this->ArmAftDatum = ArmAftDatum;
    this->BasicemptyMoment = BasicemptyMoment;
    this->frontArm = frontArm;
    this->passengersArm = passengersArm;
    this->baggageArm = baggageArm;
    this->fuelArm = fuelArm;
    this->maximumRampWeight = new double(0.0);  // Dynamic allocation
    this->maximumTakeoffWeight = maximumTakeoffWeight;
    this->maximumLandingWeight = maximumLandingWeight;
    this->cgRangeFwd = cgRangeFwd;
    this->cgRangeAft = cgRangeAft;
}

Aircraft::~Aircraft()
{
    delete maximumRampWeight; // Deallocate
}