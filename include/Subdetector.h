#pragma once

#include "Particle.h"
#include "SubdetectorInfo.h"
#include "Utilities.h"

/**
 * @brief Abstract base class for all sub-detector components
 * 
 * This class defines the interface and common functionality for all detector
 * components in the particle detector system. Each sub-detector is responsible
 * for detecting specific types of particles and measuring their properties
 * with realistic efficiency and resolution models.
 * 
 * Design Decisions:
 * 1. Abstract class to enforce implementation of specific detection logic
 * 2. Protected constructors to prevent direct instantiation
 * 3. Virtual destructor for proper cleanup of derived classes
 * 4. Pure virtual detect() function to ensure specific implementation
 * 5. Efficiency and resolution models to simulate real detector behavior
 */
class SubDetector
{
    // Make constructors and assignment operators protected to prevent direct instantiation
    protected:
        // Type identifier for the sub-detector
        // Used for type checking and detector-specific behavior
        SubDetectorInfo::SubDetectorType type;

        std::string name;

        // Probability of detecting a particle when it passes through
        double efficiency;

        // Minimum detectable signal strength
        // Models the detector's ability to distinguish signals
        // from noise
        double resolution;

        // Random uncertainty in measurements
        // Expressed as a percentage of the true value
        // Models systematic and statistical uncertainties
        double uncertainty;

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

