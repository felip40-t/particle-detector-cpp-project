#pragma once

#include <string>
#include <array>
#include <map>
#include <memory>
#include <cmath>

namespace SubDetectorInfo
{
    // Enumerator class for sub-detector types
    enum class SubDetectorType
    {
        Tracker,
        MuonChamber,
        HadronCalorimeter,
        EMCalorimeter,
    };

    // Function to get sub-detector name based on type using static map
    const std::string& get_subdetector_names(SubDetectorType type);

    // Struct to hold measurement
    struct Measurement
    {
        double energy{0.0};
        std::array<double, 3> momentum {0.0, 0.0, 0.0};
        double charge {0.0};

        bool track = false; // Flag for tracker
        bool em_calorimeter = false; // Flag for EM calorimeter
        bool hadron_calorimeter = false; // Flag for hadron calorimeter
        bool muon_chamber = false; // Flag for muon chamber

        Measurement() = default; // Default constructor
    };

} // namespace SubDetectorInfo
