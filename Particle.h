#pragma once

#include <cmath>
#include <iomanip>
#include <iostream>
#include <vector>
#include <memory>
#include <array>
#include <random>
#include <string>
#include <stdexcept>

using std::string;

#include "FourMomentum.h"
#include "ParticleInfo.h"

class Particle
{   
    // Make constructors and assignment operators protected to prevent direct instantiation    
    protected:
        // Particle properties
        ParticleInfo::ParticleProperties properties;
        // Particle 4-momentum
        std::unique_ptr<FourMomentum> four_momentum;

        // Default constructor
        Particle(ParticleInfo::ParticleType type);

        // Parameterized constructor
        Particle(ParticleInfo::ParticleType type, double px, double py, double pz);

        // Copy constructor
        Particle(const Particle& other);

        // Move constructor
        Particle(Particle&& other); 

        // Copy assignment operator
        Particle& operator=(const Particle& other);

        // Move assignment operator
        Particle& operator=(Particle&& other);

    public:

        // Virtual destructor
        virtual ~Particle() = default;

        // Virtual print function
        virtual void print_data() const;

        // Function to get the 4-momentum of the particle
        FourMomentum get_four_momentum() const { return *four_momentum; }

        // Function to get the properties of the particle
        ParticleInfo::ParticleProperties get_properties() const { return properties; }
    };