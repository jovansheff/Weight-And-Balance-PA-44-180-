/*******************************************************************************
/ MODULE:  aircraft.h
/ AUTHOR:  Jovan Rayhaga
/ PURPOSE: Declaration of the Aircraft class. Abstract data type
           for aircraft details. Includes properties for aircraft details parameters.
/
/          (c) 2023 CCCOnline
*******************************************************************************/
#pragma once
#ifndef AIRCRAFT_H
#define AIRCRAFT_H

#include <iostream>
#include <string>

class Aircraft 
{
public:
    std::string regNumber;
    std::string manufacturer;
    double basicEmptyWeight;
    double ArmAftDatum;
    double BasicemptyMoment;
    double frontArm;
    double passengersArm;
    double baggageArm;
    double fuelArm;
    double* maximumRampWeight;  // Dynamic allocation
    double maximumTakeoffWeight;
    double maximumLandingWeight;
    double cgRangeFwd;
    double cgRangeAft;

    Aircraft(); // constructor with no parameter
    Aircraft(const std::string& regNumber, const std::string& manufacturer, double basicEmptyWeight, double ArmAftDatum, double BasicemptyMoment, double frontArm, double passengersArm, double baggageArm, double fuelArm, double maximumTakeoffWeight, double maximumLandingWeight, double cgRangeFwd, double cgRangeAft);

    bool operator < (const Aircraft& n)
    {
        return manufacturer < n.manufacturer; // compare manufacturer name by alphabet

    }

    ~Aircraft(); // destructor
};

#endif // AIRCRAFT_H