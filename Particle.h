#pragma once

#include <cmath>
#include <iostream>
#include <vector>
#include <memory>
#include <array>
#include <random>
#include <string>

#include "Four_momentum.h"

class Particle
{
    private:
        std::string name; // Particle name
        double rest_mass; // Particle rest mass in MeV
        std::unique_ptr<FourMomentum> four_momentum; // Particle 4-momentum
        double charge; // Particle charge in e

    public:
        // Virtual destructor
        virtual ~Particle();

        // Parameterized constructor
        Particle(const std::string& name, double rest_mass, double charge, double px, double py, double pz);

        // Copy constructor
        Particle(const Particle& other);

        // Move constructor
        Particle(Particle&& other); 

        // Copy assignment operator
        Particle& operator=(const Particle& other);

        // Move assignment operator
        Particle& operator=(Particle&& other);

        // Virtual print function
        virtual void print() const;
}