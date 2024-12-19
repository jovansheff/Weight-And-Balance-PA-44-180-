/*******************************************************************************
/ MODULE:  cessnaAircraft.cpp
/ AUTHOR:  Jovan Rayhaga
/ PURPOSE: Implementations for the CessnaAircraft class. Providing a default constructor
           that sets default values for Cessna aircraft parameters.
/
/
/          (c) 2023 CCCOnline
*******************************************************************************/

#include "cessnaAircraft.h"
#include "aircraft.h"

CessnaAircraft::CessnaAircraft() : Aircraft()
{
    regNumber = "";
    manufacturer = "Cessna";
    basicEmptyWeight = 0.0;
    ArmAftDatum = 0.0;
    BasicemptyMoment = 0.0;
    frontArm = 40.0;
    passengersArm = 73.0;
    baggageArm = 95.0;
    fuelArm = 48.0;
    *maximumRampWeight = 2307.0;
    maximumTakeoffWeight = 2300.0;
    maximumLandingWeight = 2300.0;
    cgRangeFwd = 35.0;
    cgRangeAft = 47.3;
}