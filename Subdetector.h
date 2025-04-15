#pragma once

#include "Particle.h"
#include "SubdetectorInfo.h"

class SubDetector
{
    protected:
        SubDetectorInfo::SubDetectorType type; // Sub-detector type
        SubDetectorInfo::Measurement measurement; // Measurement data
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
        SubDetectorInfo::Measurement get_measurement() const { return measurement; }

        // Virtual print function
        virtual void print() const;

        // Virtual detector function
        virtual void detect(const Particle& particle) = 0;

};

// Helper function to round a value to the nearest resolution
double roundToResolution(double value, double resolution);

