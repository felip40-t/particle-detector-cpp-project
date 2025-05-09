#pragma once

#include "Particle.h"
#include "SubdetectorInfo.h"
#include "Utilities.h"

class SubDetector
{
    // Make constructors and assignment operators protected to prevent direct instantiation
    protected:
        SubDetectorInfo::SubDetectorType type; // Sub-detector type
        string name; // Sub-detector name
        double efficiency; // Efficiency of the sub-detector
        double resolution; // Resolution of the sub-detector
        double uncertainty; // Uncertainty in measurements as a percentage (0 for perfect detector)

        // Default constructor
        SubDetector();

        // Parameterized constructor
        SubDetector(double efficiency, double resolution, double uncertainty);

        // Copy constructor
        SubDetector(const SubDetector& other);

        // Move constructor
        SubDetector(SubDetector&& other);

        // Copy assignment operator
        SubDetector& operator=(const SubDetector& other);

        // Move assignment operator
        SubDetector& operator=(SubDetector&& other);

    public:
        // Virtual destructor
        virtual ~SubDetector() = default;

        // Getters for sub-detector properties
        SubDetectorInfo::SubDetectorType get_type() const { return type; }
        string get_name() const { return name; }
        double get_efficiency() const { return efficiency; }
        double get_resolution() const { return resolution; }
        double get_uncertainty() const { return uncertainty; }

        // Setters for efficiency, resolution, and uncertainty
        void set_efficiency(double efficiency);
        void set_resolution(double resolution);
        void set_uncertainty(double uncertainty);

        // Virtual print function
        virtual void print() const;

        // Pure virtual detector function - updates measurement
        virtual void detect(const Particle& particle, SubDetectorInfo::Measurement& m) = 0;
};

