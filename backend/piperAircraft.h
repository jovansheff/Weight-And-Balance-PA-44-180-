/*******************************************************************************
/ MODULE:  piperAircraft.h
/ AUTHOR:  Jovan Rayhaga
/ PURPOSE: Declaration of the PiperAircraft class. Inheriting from the Aircraft class,
           and providing a default constructor for initializing Piper aircraft details.
/
/          (c) 2023 CCCOnline
*******************************************************************************/

#pragma once
#ifndef PIPERAIRCRAFT_H
#define PIPERAIRCRAFT_H

#include "aircraft.h"

class PiperAircraft : public Aircraft // inherit from the aircraft.h
{
public:

    PiperAircraft();  // constructor with no parameter
};

#endif // PIPERAIRCRAFT_H