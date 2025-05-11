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
        // Stores fundamental particle properties (mass, charge, type, name)
        ParticleInfo::ParticleProperties properties;

        std::unique_ptr<FourMomentum> four_momentum;

        // Default constructor
        Particle(ParticleInfo::ParticleType type);

        // Parameterized constructor
        Particle(ParticleInfo::ParticleType type, double px, double py, double pz);

        // Rule of Five implementation for proper resource management
        Particle(const Particle& other);

        // Move constructor
        Particle(Particle&& other); 

        // Copy assignment operator
        Particle& operator=(const Particle& other);

        // Move assignment operator
        Particle& operator=(Particle&& other);

    public:

        // Virtual destructor is required for proper cleanup of derived classes
        // Default implementation is sufficient as we use smart pointers
        virtual ~Particle() = default;

        // Virtual function allows derived classes to customize particle data display
        virtual void print_data() const;

        // Return by value to prevent external modification
        FourMomentum get_four_momentum() const { return *four_momentum; }

        // Set the four-momentum components
        void set_four_momentum(int index, double value);

        // Function to get the properties of the particle
        ParticleInfo::ParticleProperties get_properties() const { return properties; }
    };