#pragma once

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

#include "Electron.h"
#include "Muon.h"
#include "Photon.h"
#include "Proton.h"
#include "Neutron.h"
#include "Pions.h"
#include "Kaons.h"
#include "Neutrino.h"

void show_menu();
void help_menu();
void subdetector_menu();
bool check_string_to_int(const std::string& str);
bool check_string_to_double(const std::string& str);


namespace DetectorUtils 
{
    // CHECKS
    //Check for tracker layers from user input
    int check_layers();
    // Check for tracker material from user input
    std::string check_tracker_material();
    // Check for muon chamber technology from user input
    std::string check_muon_chamber_technology();
    int check_number_of_technology(std::string technology);
    // Show the tracker material menu
    void tracker_material_menu();
    // Show the muon chamber menu
    void muon_chamber_menu();
    // Check
    double check_uncertainty();
    double check_efficiency();
    double check_resolution();
    double check_input_in_range(const std::string& prompt, double min, double max);
    
} // namespace DetectorUtils


namespace ParticleListUtils 
{
    // Print the particle menu
    void particle_menu();
    // function to choose a particle based on user input
    std::unique_ptr<Particle> choose_particle(int choice);
    // function to choose a random particle
    std::unique_ptr<Particle> choose_random_particle();
} // namespace ParticleListUtils


namespace MathUtils {
    // Lambda function to calculate invariant mass squared
    inline auto invariant_mass_squared = [](double E, double px, double py, double pz) -> double {
        return E * E - (px * px + py * py + pz * pz);
    };

    // Lambda function to calculate the momentum squared
    inline auto momentum_squared = [](double px, double py, double pz) -> double {
        return px * px + py * py + pz * pz;
    };

    // Lambda function to round to the nearest resolution
    inline auto roundToResolution = [](double value, double resolution) -> double {
        return std::round(value / resolution) * resolution;
    };

    // Template function to check if a value is within a range
    // Must be implemented in header file
    template <typename T>
    bool check_value_in_range(T value, T min, T max)
    {
        return value >= min && value <= max;
    }
} // namespace MathUtils