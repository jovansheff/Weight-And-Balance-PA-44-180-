/*******************************************************************************
/ MODULE:  cessnaAircraft.h
/ AUTHOR:  Jovan Rayhaga
/ PURPOSE: Declaration of the CessnaAircraft class. Inheriting from the Aircraft class,
           and providing a default constructor for initializing Cessna aircraft details.
/
/          (c) 2023 CCCOnline
*******************************************************************************/

#pragma once
#ifndef CESSNAAIRCRAFT_H
#define CESSNAAIRCRAFT_H

#include "aircraft.h"

class CessnaAircraft : public Aircraft // inherit from the aircraft.h
{
public:

    CessnaAircraft();  // constructor with no parameter
};

#endif // CESSNAAIRCRAFT_H