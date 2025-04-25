#pragma once

#include "Tracker.h"
#include "EMCalorimeter.h"
#include "HadronCalorimeter.h"
#include "MuonChamber.h"

class Detector
{
    private:
        std::vector<std::unique_ptr<SubDetector>> subdetectors;

    public:
        // Parameterized constructor
        Detector() = default;

        // Destructor
        ~Detector() = default;

        // Add a sub-detector to the detector
        void add_subdetector(std::unique_ptr<SubDetector> subdetector);

        // Get user to add subdetector
        void add_subdetector();

        // Remove a sub-detector from the detector at index i
        void remove_subdetector(size_t i);

        // Get user to remove subdetector
        void remove_subdetector();

        // Clear all sub-detectors
        void clear_subdetectors() { subdetectors.clear(); }

        // Print function for the detector
        void print() const;

        // Detect function for the detector
        void detect(const Particle& particle) const;
};
