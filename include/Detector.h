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
        void clear_subdetectors();

        // Print function for the detector
        void print() const;

        // Detect function for the detector
        void detect(const Particle& particle) const;

        // Get sub-detectors
        const std::vector<std::unique_ptr<SubDetector>>& get_subdetectors() const { return subdetectors; }
};

namespace DetectorHelpers
{
    // Helper function to classify particle detection
    int classify_particle_via_mass(double mass);

    // Helper function to check if all types of subdetectors exist
    bool has_all_subdetector_types(const std::vector<std::unique_ptr<SubDetector>>& subdetectors);

    // Helpers to report the detection of each particle
    void report_electron(const SubDetectorInfo::Measurement& measurement);
    void report_charged_hadron(const SubDetectorInfo::Measurement& measurement);
    void report_neutral_hadron(const SubDetectorInfo::Measurement& measurement);
    void report_muon(const SubDetectorInfo::Measurement& measurement);
    void report_neutrino();
    void report_photon(const SubDetectorInfo::Measurement& measurement);
    void report_unknown(const SubDetectorInfo::Measurement& measurement);
}

