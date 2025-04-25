#pragma once

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

#include "Electron.h"
#include "Muon.h"
#include "Photon.h"
#include "Hadron.h"

void show_menu();

bool check_string_to_int(const std::string& str);

bool check_string_to_double(const std::string& str);

void particle_menu();

std::unique_ptr<Particle> choose_particle(int choice);

std::unique_ptr<Particle> choose_random_particle();

int check_layers();

double check_uncertainty();
double check_efficiency();
double check_resolution();

namespace utils {
    // Lambda function to calculate invariant mass squared
    inline auto invariant_mass_squared = [](double E, double px, double py, double pz) -> double {
        return E * E - (px * px + py * py + pz * pz);
    };

    // Lambda function to calculate the momentum squared
    inline auto momentum_squared = [](double px, double py, double pz) -> double {
        return px * px + py * py + pz * pz;
    };
}