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

bool check_string_to_int(const std::string& str);
bool check_string_to_double(const std::string& str);

namespace DetectorUtils 
{
    // CHECKS
    int check_layers();
    double check_uncertainty();
    double check_efficiency();
    double check_resolution();
    double check_value_in_range(const std::string& prompt, double min, double max);
    int classify_particle_via_mass(double mass);
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
} // namespace MathUtils