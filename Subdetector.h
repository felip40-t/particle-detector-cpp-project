#pragma once

#include "Particle.h"
#include "SubdetectorInfo.h"
#include "Utilities.h"

class SubDetector
{
    protected:
        SubDetectorInfo::SubDetectorType type; // Sub-detector type
        string name; // Sub-detector name
        double efficiency; // Efficiency of the sub-detector
        double resolution; // Resolution of the sub-detector
        double uncertainty; // Uncertainty in measurements (0 for perfect detector)

    public:
        // Default constructor
        SubDetector();

        // Parameterized constructor
        SubDetector(double efficiency, double resolution, double uncertainty);

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
        double get_uncertainty() const { return uncertainty; }

        // Virtual print function
        virtual void print() const;

        // Virtual detector function - updates measurement
        virtual void detect(const Particle& particle, SubDetectorInfo::Measurement& m) = 0;

};

