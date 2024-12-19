/*******************************************************************************
/ MODULE:  main.cpp
/ AUTHOR:  Jovan Rayhaga
/ PURPOSE: To calculate Weight and Balance from different Aircraft.
           It allows users to add aircraft, remove aircraft, search specific aircraft and the ooption to edit or calculate the selected aircraft. Also, list all availabe aircraft and choose which aircraft to calculate.
           This tool will provide a simple report showing whether the aircraft is safe for flight or if adjustments need to be made.
           This tool is for pre-flight planning purposes only.
/
/          (c) 2023 CCCOnline
*******************************************************************************/

#include <iostream>
#include <string>

#include "aircraft.h"
#include "piperAircraft.h"
#include "cessnaAircraft.h"

#include <iomanip>

using namespace std;

double validInput(string s) // Exception handling for non-integers and negative numbers
{
    bool valid = true;
    double value;

    while (valid)
    {
        try
        {
            std::cout << s;
            if (!(std::cin >> value)) // Check if input error for non-integers
            {
                throw string("Please Enter Integer Numbers\n");
            }
            else if (value < 0) // Check if input error for negative numbers
            {
                throw std::string("Please Enter Positive numbers\n");
            }
        }

        catch (string error)
        {
            cout << "\nError. " << error << endl;
            std::cin.clear();
            std::cin.ignore(50, '\n');
            continue;
        }
        valid = false;
    }
    return value;
}

void calculate(const Aircraft& selectedAircraft, double basicEmptyWeight, double BasicemptyMoment, double frontArm, double passengersArm, double baggageArm, double fuelArm, double w1, double w2, double w3, double w4, double w5, double w6) // Function to calculate the values
{
    double m1 = w1 * frontArm; // Pilot/Front Passengers Moment

    double m2 = w2 * passengersArm; // Passengers - Aft Seats Moment

    double m3 = w3 * baggageArm; // Baggage Area Moment

    double m4 = w4 * fuelArm; // Fuel (6lbs/gal) Moment

    double m5 = w5 * fuelArm; // Start, Taxi & Run-Up Fuel Burn Momemt

    double m6 = w6 * fuelArm; // Estimated Fuel Burn Moment

    double rampWeight = basicEmptyWeight + w1 + w2 + w3 + w4;  // Ramp Total Weight
    double rampMoment = BasicemptyMoment + m1 + m2 + m3 + m4; // Ramp Total Moment
    double rampCg = rampMoment / rampWeight; // Ramp CG

    double cgMidpoint = (selectedAircraft.cgRangeFwd + selectedAircraft.cgRangeAft) / 2.0; // determining if the CG is Foward or Aft by the midpoint

    std::cout << "Ramp Moment: " << fixed << setw(10) << setprecision(2) << rampMoment << endl;
    std::cout << "Ramp CG: " << fixed << setw(10) << setprecision(2) << rampCg << endl;

    double takeoffWeight = rampWeight - w5; // Takeoff Total Weight
    double takeoffMoment = rampMoment - m5; // Takeoff Total Moment
    double takeoffCg = takeoffMoment / takeoffWeight; // Takeoff CG

    std::cout << "\nTake-off Weight: " << fixed << setw(10) << setprecision(2) << takeoffWeight;
    if (takeoffWeight < selectedAircraft.maximumTakeoffWeight)
    {
        std::cout << " (OK)" << endl;
    }
    else if (takeoffWeight < 0)
    {
        std::cout << "Error" << endl;
    }
    else {
        std::cout << " (Too Heavy)" << endl;
    }

    std::cout << "Take-off Moment: " << fixed << setw(10) << setprecision(2) << takeoffMoment << endl;


    std::cout << "Take-off CG: " << fixed << setw(10) << setprecision(2) << takeoffCg; // Check if take-off CG is within the specified range
    if (takeoffCg >= cgMidpoint) {
        std::cout << " - (Aft CG)";
    }
    else {
        std::cout << " - (Forward CG)";
    }

    if (takeoffCg <= selectedAircraft.cgRangeFwd && takeoffCg >= selectedAircraft.cgRangeAft)
    {
        std::cout << " within the CG Range" << endl;
    }
    else {
        std::cout << " Not within the CG Range" << endl;
    }

    // Landing Weight/CG
    double landingWeight = takeoffWeight - w6; // Laanding Total Weight
    double landingMoment = takeoffMoment - m6; // Laanding Total Moment
    double landingCg = landingMoment / landingWeight; // Laanding CG

    std::cout << "\nLanding Weight: " << fixed << setw(10) << setprecision(2) << landingWeight;
    if (takeoffWeight < selectedAircraft.maximumLandingWeight)
    {
        std::cout << " (OK)" << endl;
    }
    else {
        std::cout << " (Too Heavy)" << endl;
    }
    std::cout << "Landing Moment: " << fixed << setw(10) << setprecision(2) << landingMoment << endl;

    std::cout << "Landing CG: " << fixed << setw(10) << setprecision(2) << landingCg;
    if (landingCg >= cgMidpoint) {
        std::cout << " - (Aft CG)";
    }
    else {
        std::cout << " - (Forward CG)";
    }

    if (landingCg <= selectedAircraft.cgRangeFwd && landingCg >= selectedAircraft.cgRangeAft)
    {
        std::cout << " within the CG Range" << endl;
    }
    else {
        std::cout << " Not within the CG Range" << endl;
    }

    if (takeoffWeight > selectedAircraft.maximumTakeoffWeight || landingWeight > selectedAircraft.maximumLandingWeight || takeoffCg > selectedAircraft.cgRangeFwd || takeoffCg < selectedAircraft.cgRangeAft) // Check if the aircraft is too heavy or not within the CG Range
    {
        std::cout << "\n*Not Safe for Flight\n" << endl;
    }
    else {
        std::cout << "\n*Safe for Flight\n" << endl;
    }

}

void editAircraftDetails(Aircraft& aircraft) // Function to edit aircraft details
{
    std::cout << "Editing Aircraft Details for Registration Number: " << aircraft.regNumber << "\n" << std::endl;

    std::cout << "Select the property to update:" << std::endl;
    std::cout << "1. Basic Empty Weight (lbs)" << std::endl;
    std::cout << "2. Basic Arm Aft Datum (inches)" << std::endl;
    std::cout << "3. Basic Empty Moment (lbs)" << std::endl;
    std::cout << "4. Pilot/Front Passengers Arm (inches)" << std::endl;
    std::cout << "5. Passengers - Aft Seats Arm (inches)" << std::endl;
    std::cout << "6. Baggage Area Arm (inches)" << std::endl;
    std::cout << "7. Fuel Arm (inches)" << std::endl;
    std::cout << "8. Maximum Ramp Weight (lbs)" << std::endl;
    std::cout << "9. Maximum Takeoff Weight (lbs)" << std::endl;
    std::cout << "10. Maximum Landing Weight (lbs)" << std::endl;
    std::cout << "11. Maximum CG Forward (inches)" << std::endl;
    std::cout << "12. Maximum CG Aft (inches)" << std::endl;

    int choice = validInput("Enter your choice: ");

    double newValue = validInput("Enter the new value for the selected property: ");


    switch (choice) 
    {
    case 1:
        aircraft.basicEmptyWeight = newValue;
        break;
    case 2:
        aircraft.ArmAftDatum = newValue;
        break;
    case 3:
        aircraft.BasicemptyMoment = newValue;
        break;
    case 4:
        aircraft.frontArm = newValue;
        break;
    case 5:
        aircraft.passengersArm = newValue;
        break;
    case 6:
        aircraft.baggageArm = newValue;
        break;
    case 7:
        aircraft.fuelArm = newValue;
        break;
    case 8:
        *aircraft.maximumRampWeight = newValue;
        break;
    case 9:
        aircraft.maximumTakeoffWeight = newValue;
        break;
    case 10:
        aircraft.maximumLandingWeight = newValue;
        break;
    case 11:
        aircraft.cgRangeFwd = newValue;
        break;
    case 12:
        aircraft.cgRangeAft = newValue;
        break;
    default:
        std::cout << "Not in the Option" << std::endl;
    }

    std::cout << "Aircraft details is updated." << std::endl;
}

void selectionSort(Aircraft arr[], int n) // Function to perform Selection Sort
{
    for (int i = 0; i < n - 1; ++i) 
    {
        int minIndex = i;
        for (int j = i + 1; j < n; ++j) 
        {
            if (arr[j] < arr[minIndex]) 
            {
                minIndex = j;
            }
        }
        if (minIndex != i) 
        {
            Aircraft temp = arr[i]; // Swap the aircraft at minIndex with the aircraft at i
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }
}

int option;

int main()
{
    const int CAPACITY = 10; // Maximum number of aircraft
    Aircraft aircraftList[CAPACITY]; // Array to store aircraft details
    int numAircraft = 0; // Number of aircraft currently in the list

    CessnaAircraft newCessnaAircraft; // default Cessna Aircraft
    newCessnaAircraft.regNumber = "N6315D";
    newCessnaAircraft.basicEmptyWeight = 1515.0;
    newCessnaAircraft.ArmAftDatum = 38.51;
    newCessnaAircraft.BasicemptyMoment = 58353;

    aircraftList[numAircraft] = newCessnaAircraft;
    numAircraft++;

    PiperAircraft defaultPiper; // default Piper Aircraft
    defaultPiper.regNumber = "N8569Q";
    defaultPiper.basicEmptyWeight = 1562.63;
    defaultPiper.ArmAftDatum = 86.81;
    defaultPiper.BasicemptyMoment = 135661.77;

    aircraftList[numAircraft] = defaultPiper;
    numAircraft++;

    bool menu = true;
    int option;

    while (menu)
    {
        
        std::cout << "*THIS TOOL IS FOR PRE - FLIGHT PLANNING PURPOSES ONLY\n" << endl;
        std::cout << "1. Add Aircraft" << endl;
        std::cout << "2. Remove Aircraft" << endl;
        std::cout << "3. Search Specific Aircraft" << endl;
        std::cout << "4. List Aircraft" << endl;
        std::cout << "5. Exit" << endl;

        try // Exception handling for non-integer input
        {
            std::cout << "\nChoose Option: ";
            std::cin >> option;
            if (!option)
            {
                throw string("Please Enter Integer Numbers Greater than 1\n");
            }
        }
        catch (string error)
        {
            std::cout << "Error. " << error << endl;
            std::cin.clear();
            std::cin.ignore(100, '\n'); // ignore 100 lines
            continue;
        }

        switch (option)
        {
        case 1:// Add  Aircraft
            if (numAircraft < CAPACITY)
            {
                Aircraft newAircraft; // Add new Aircraft

                std::cout << "Enter Aircraft Details:\n" << std::endl;

                std::cout << "Registration Number: ";
                std::cin >> newAircraft.regNumber;

                std::cout << "Aircraft Manufacturer: ";
                std::cin >> newAircraft.manufacturer;

                // Use validInput function for non-integers input
                newAircraft.basicEmptyWeight = validInput("Basic Empty Weight (lbs): ");
                newAircraft.ArmAftDatum = validInput("Basic Arm Aft Datum (inches): ");
                newAircraft.BasicemptyMoment = validInput("Basic Empty Moment (lbs): ");
                newAircraft.frontArm = validInput("Pilot/Front Passengers Arm (inches): ");
                newAircraft.passengersArm = validInput("Passengers - Aft Seats Arm (inches): ");
                newAircraft.baggageArm = validInput("Baggage Area Arm (inches): ");
                newAircraft.fuelArm = validInput("Fuel Arm (inches): ");
                *newAircraft.maximumRampWeight = validInput("Maximum Ramp Weight (lbs): ");
                newAircraft.maximumTakeoffWeight = validInput("Maximum Takeoff Weight (lbs): ");
                newAircraft.maximumLandingWeight = validInput("Maximum Landing Weight (lbs): ");
                newAircraft.cgRangeFwd = validInput("Maximum CG Foward (inches): ");
                newAircraft.cgRangeAft = validInput("Maximum CG Aft (inches): ");

                aircraftList[numAircraft] = newAircraft; // Add the new aircraft to the list
                numAircraft++;

                std::cout << newAircraft.regNumber << " is added.\n" << std::endl;
            }
            else {
                std::cout << "Aircraft list is full. Cannot add more aircraft." << std::endl;
            }
            break;
        case 2: // Remove Aircraft
            if (numAircraft > 0)
            {
                std::string regNumber;
                bool found = false;

                std::cout << "Enter the Registration Number of the aircraft to remove: ";
                std::cin >> regNumber;

                for (int i = 0; i < numAircraft; i++)
                {
                    if (aircraftList[i].regNumber == regNumber)
                    {
                        for (int j = i; j < numAircraft - 1; j++) // Remove the aircraft by shifting all elements after it in the array
                        {
                            aircraftList[j] = aircraftList[j + 1];
                        }
                        numAircraft--;

                        found = true;
                        std::cout << regNumber << " is removed.\n" << std::endl;
                        break;
                    }
                }

                if (!found)
                {
                    std::cout << regNumber << " is not found." << std::endl;
                }
            }
            else {
                std::cout << "No aircraft in the list to remove." << std::endl; // if there is no aircraft in the list
            }

            break;


        case 3: // Search Specific Aircraft
            if (numAircraft > 0)
            {
                std::string regNumber;
                bool found = false;

                std::cout << "Enter the Registration Number of the aircraft to search: ";
                std::cin >> regNumber;

                for (int i = 0; i < numAircraft; i++)
                {
                    if (aircraftList[i].regNumber == regNumber) // Aircraft is found
                    {
                        std::cout << "Aircraft Registration Number " << regNumber << " is found" << std::endl;
                        found = true;

                        int option2 = validInput("1. Edit Aircraft Details\n2. Calculate Weight & Balance\nEnter your choice: ");

                        if (option2 == 1)
                        {
                            editAircraftDetails(aircraftList[i]); // Call the editAircraftDetails function to update the aircraft details
                        }
                        else if (option2 == 2)
                        {
                            const Aircraft& selectedAircraft = aircraftList[i]; // Calculate Weight & Balance calculation for the selected aircraft

                            double basicEmptyWeight = selectedAircraft.basicEmptyWeight;
                            double BasicemptyMoment = selectedAircraft.BasicemptyMoment;
                            double frontArm = selectedAircraft.frontArm;
                            double passengersArm = selectedAircraft.passengersArm;
                            double baggageArm = selectedAircraft.baggageArm;
                            double fuelArm = selectedAircraft.fuelArm;


                            double w1 = validInput("Enter Pilot/Front Passengers Weight (lbs):");
                            double w2 = validInput("Enter Passengers - Aft Seats Weight (lbs): ");
                            double w3 = validInput("Enter Baggage Area Weight (lbs):");
                            double w4 = validInput("Enter Fuel (6lbs/gal) Weight (lbs):");
                            double w5 = validInput("Enter Start, Taxi & Run - Up Fuel Burn(lbs) :");
                            double w6 = validInput("Enter Estimated Fuel Burn Weight (lbs): ");

                            calculate(selectedAircraft, basicEmptyWeight, BasicemptyMoment, frontArm, passengersArm, baggageArm, fuelArm, w1, w2, w3, w4, w5, w6);
                        }
                        else
                        {
                            std::cout << "Invalid choice." << std::endl;
                        }
                        break; // Exit the loop since the aircraft is found.
                    }
                }

                if (!found)
                {
                    std::cout << "Aircraft with Registration Number " << regNumber << " not found." << std::endl;
                }
            }
            break;

        case 4: // List All Aircraft

            if (numAircraft > 0)
            {
                std::cout << "List of All Aircraft:" << std::endl;
                selectionSort(aircraftList, numAircraft); // Sort the array using selection sort alphabetically for manufactuer name

                for (int i = 0; i < numAircraft; i++)
                {
                    std::cout << (i + 1) << ". " << aircraftList[i].regNumber << " - " << aircraftList[i].manufacturer << std::endl;
                }

                int selection = validInput("Enter the aircraft option to calculate Weight & Balance: ");
                
                if (selection >= 1 && selection <= numAircraft) 
                {
                    const Aircraft& selectedAircraft = aircraftList[selection - 1]; // Perform Weight & Balance calculation for the selected aircraft

                    double basicEmptyWeight = selectedAircraft.basicEmptyWeight;
                    double BasicemptyMoment = selectedAircraft.BasicemptyMoment;
                    double frontArm = selectedAircraft.frontArm;
                    double passengersArm = selectedAircraft.passengersArm;
                    double baggageArm = selectedAircraft.baggageArm;
                    double fuelArm = selectedAircraft.fuelArm;


                    double w1 = validInput("Enter Pilot/Front Passengers Weight (lbs):");
                    double w2 = validInput("Enter Passengers - Aft Seats Weight (lbs): ");
                    double w3 = validInput("Enter Baggage Area Weight (lbs):");
                    double w4 = validInput("Enter Fuel (6lbs/gal) Weight (lbs):");
                    double w5 = validInput("Enter Start, Taxi & Run - Up Fuel Burn(lbs) :");
                    double w6 = validInput("Enter Estimated Fuel Burn Weight (lbs): ");

                    calculate(selectedAircraft, basicEmptyWeight, BasicemptyMoment, frontArm, passengersArm, baggageArm, fuelArm, w1, w2, w3, w4, w5, w6);
                }
                else {
                    std::cout << "\nNot in the option" << std::endl;
                }
            }
            else {
                std::cout << "No available aircraft in the list " << std::endl; // if there is no aircraft in the list
            }
            break;

        case 5:
            std::cout << "\nGoodbye" << std::endl;
            return 0;
        default:
            std::cout << "\nNot in the option\n" << std::endl;
        }
    }
    return 0;
};