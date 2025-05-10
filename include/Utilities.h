#pragma once

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <memory>
#include <algorithm>

#include "Electron.h"
#include "Muon.h"
#include "Photon.h"
#include "Proton.h"
#include "Neutron.h"
#include "Pions.h"
#include "Kaons.h"
#include "Neutrino.h"

namespace DetectorUtils 
{
    // Menu functions
    void show_menu() noexcept;
    void help_menu() noexcept;
    void subdetector_menu() noexcept;
    void tracker_material_menu() noexcept;
    void muon_chamber_menu() noexcept;
    
    // Check functions
    double check_uncertainty();
    double check_efficiency();
    double check_resolution();
    double check_input_in_range(const std::string& prompt, double min, double max);
    int check_layers();
    std::string check_tracker_material();
    std::string check_muon_chamber_technology();
    int check_number_of_technology(const std::string& technology);

} // namespace DetectorUtils

namespace ParticleListUtils 
{
    // Print the particle menu
    void particle_menu() noexcept;
    // function to choose a particle based on user input
    std::unique_ptr<Particle> choose_particle(int choice);
    // function to choose a random particle
    std::unique_ptr<Particle> choose_random_particle();
} // namespace ParticleListUtils


namespace MathUtils {
    bool check_string_to_int(const std::string& str);
    bool check_string_to_double(const std::string& str);

    // Lambda function to calculate invariant mass squared
    inline constexpr auto invariant_mass_squared = [](double E, double px, double py, double pz) noexcept -> double {
        return E * E - (px * px + py * py + pz * pz);
    };

    // Lambda function to calculate the momentum squared
    inline constexpr auto momentum_squared = [](double px, double py, double pz) noexcept -> double {
        return px * px + py * py + pz * pz;
    };

    // Lambda function to round to the nearest resolution
    inline constexpr auto roundToResolution = [](double value, double resolution) noexcept -> double {
        return std::round(value / resolution) * resolution;
    };

    // Template function to check if a value is within a range
    template <typename T>
    constexpr bool check_value_in_range(T value, T min, T max) noexcept
    {
        return value >= min && value <= max;
    }
} // namespace MathUtils