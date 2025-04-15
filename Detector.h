#pragma once

#include "Subdetector.h"

class Detector
{
    private:
        std::vector<std::unique_ptr<SubDetector>> subdetectors; 
        std::string name; // Name of the detector

    public:
        // Default constructor
        Detector() : name("Default Detector") {};

        // Parameterized constructor
        Detector(const std::string& name) : name(name) {};

        // Destructor
        ~Detector() = default;

        // Add a sub-detector to the detector
        void add_subdetector(std::unique_ptr<SubDetector> subdetector);

        // Print function for the detector
        void print() const;

        // Detect function for the detector
        void detect(const Particle& particle) const;
};
