#pragma once

#include "Subdetector.h"
#include "Hadron.h"

class HadronCalorimeter : public SubDetector
{
    public:
        // Default constructor
        HadronCalorimeter();

        // Parameterized constructor
        HadronCalorimeter(double efficiency, double resolution, double uncertainty);

        // Destructor 
        ~HadronCalorimeter() override = default;

        // Copy constructor
        HadronCalorimeter(const HadronCalorimeter& other) = default;

        // Move constructor
        HadronCalorimeter(HadronCalorimeter&& other) = default;

        // Copy assignment
        HadronCalorimeter& operator=(const HadronCalorimeter& other) = default;

        // Move assignment
        HadronCalorimeter& operator=(HadronCalorimeter&& other) = default;

        // Detect function
        void detect(const Particle& particle) override;
};