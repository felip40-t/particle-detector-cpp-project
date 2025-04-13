#pragma once

#include <cmath>
#include <iostream>
#include <vector>
#include <memory>
#include <array>
#include <random>
#include <string>

using std::string;

#include "FourMomentum.h"
#include "ParticleInfo.h"

class Particle
{
    protected:
        ParticleInfo::ParticleProperties properties; // Particle properties
        std::unique_ptr<FourMomentum> four_momentum; // Particle 4-momentum

    public:
        // Virtual destructor
        virtual ~Particle() = default;

        // Default constructor
        Particle();

        // Parameterized constructor
        Particle(double px, double py, double pz);

        // Copy constructor
        Particle(const Particle& other);

        // Move constructor
        Particle(Particle&& other); 

        // Copy assignment operator
        Particle& operator=(const Particle& other);

        // Move assignment operator
        Particle& operator=(Particle&& other);

        // Virtual print function
        virtual void print_data() const;

        // Function to get the 4-momentum of the particle
        FourMomentum get_four_momentum() const { return *four_momentum; }

        // Function to get the properties of the particle
        ParticleInfo::ParticleProperties get_properties() const { return properties; }
    };