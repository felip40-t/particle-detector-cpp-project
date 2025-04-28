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
        double energy{0.0}; // Energy of the particle
        std::array<double, 3> momentum {0.0, 0.0, 0.0}; // 3D momentum vector
        double charge {0.0}; // Charge of the particle

        bool track = false; // Flag to indicate if the measurement is from a tracker
        bool em_calorimeter = false; // Flag to indicate if the measurement is from an EM calorimeter
        bool hadron_calorimeter = false; // Flag to indicate if the measurement is from a hadron calorimeter
        bool muon_chamber = false; // Flag to indicate if the measurement is from a muon chamber

        Measurement() = default; // Default constructor
    };

} // namespace SubDetectorInfo
