#pragma once

#include "Subdetector.h"
#include "Electron.h"
#include "Photon.h"

class EMCalorimeter : public SubDetector
{
    public:
        // Default constructor
        EMCalorimeter();

        // Parameterized constructor
        EMCalorimeter(double efficiency, double resolution, double uncertainty);

        // Destructor
        ~EMCalorimeter() override = default;

        // Copy constructor
        EMCalorimeter(const EMCalorimeter& other) = default;

        // Move constructor
        EMCalorimeter(EMCalorimeter&& other) = default;

        // Copy assignment operator
        EMCalorimeter& operator=(const EMCalorimeter& other) = default;

        // Move assignment operator
        EMCalorimeter& operator=(EMCalorimeter&& other) = default;

        // Detect function
        void detect(const Particle& particle) override;
};