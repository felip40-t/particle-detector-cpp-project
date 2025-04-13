#pragma once

#include <cmath>
#include <iostream>
#include <vector>
#include <memory>
#include <array>
#include <random>
#include <string>

using std::string;

#include "Particle.h"


namespace SubDetectorInfo
{
    // Enumerator class for sub-detector types
    enum class SubDetectorType
    {
        Default,
        Tracker,
        MuonChamber,
        HadronCalorimeter,
        EMCalorimeter,
    };


    // Function to get sub-detector name based on type using static map
    const std::string& get_subdetector_names(SubDetectorType type);

} // namespace SubDetectorInfo

class SubDetector
{
    protected:
        SubDetectorInfo::SubDetectorType type; // Sub-detector type
        string name; // Sub-detector name
        double efficiency; // Efficiency of the sub-detector
        double resolution; // Resolution of the sub-detector

    public:
        // Default constructor
        SubDetector();

        // Parameterized constructor
        SubDetector(double efficiency, double resolution);

        // Virtual destructor
        virtual ~SubDetector() = default;

        // Copy constructor
        SubDetector(const SubDetector& other);

        // Move constructor
        SubDetector(SubDetector&& other);

        // Copy assignment operator
        SubDetector& operator=(const SubDetector& other);

        // Move assignment operator
        SubDetector& operator=(SubDetector&& other);

        // Getters for sub-detector properties
        SubDetectorInfo::SubDetectorType get_type() const { return type; }
        string get_name() const { return name; }
        double get_efficiency() const { return efficiency; }
        double get_resolution() const { return resolution; }

        // Pure virtual print function
        virtual void print() const = 0;

        // Virtual detector function
        virtual void detect(const Particle& particle) = 0;

};
