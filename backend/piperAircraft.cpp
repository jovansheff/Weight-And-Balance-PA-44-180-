/*******************************************************************************
/ MODULE:  piperAircraft.cpp
/ AUTHOR:  Jovan Rayhaga
/ PURPOSE: Implementations for the PiperAircraft class. Providing a default constructor
           that sets default values for Piper aircraft parameters.
/
/          (c) 2023 CCCOnline
*******************************************************************************/

#include "piperAircraft.h"
#include "aircraft.h"

PiperAircraft::PiperAircraft() : Aircraft()
{
    regNumber = "";
    manufacturer = "Piper";
    basicEmptyWeight = 0.0;
    ArmAftDatum = 0.0;
    BasicemptyMoment = 0.0;
    frontArm = 85.0;
    passengersArm = 120.0;
    baggageArm = 145.0;
    fuelArm = 100.0;
    *maximumRampWeight = 2500.0;
    maximumTakeoffWeight = 2450.0;
    maximumLandingWeight = 2450.0;
    cgRangeFwd = 94.0;
    cgRangeAft = 84.0;
}