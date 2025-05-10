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

/**
 * @brief Base class for all particles in the detector simulation.
 * 
 * This class serves as the foundation for the particle hierarchy, implementing
 * the common interface and behavior for all particle types. The class is designed
 * to be abstract (non-instantiable) to enforce proper particle type creation
 * through derived classes.
 * 
 * Design Decisions:
 * 1. Protected constructors prevent direct instantiation of base Particle class
 * 2. Virtual destructor ensures proper cleanup of derived classes
 * 3. Smart pointer for four_momentum ensures automatic memory management
 * 4. Const member functions maintain object immutability where appropriate
 */
class Particle
{   
    // Make constructors and assignment operators protected to prevent direct instantiation    
    protected:
        // Stores fundamental particle properties (mass, charge, type)
        // Using a struct to group related properties and maintain data cohesion
        ParticleInfo::ParticleProperties properties;

        // Four-momentum is stored as a unique_ptr to:
        // 1. Ensure proper memory management
        // 2. Allow for polymorphic behavior if needed
        // 3. Make ownership semantics explicit
        std::unique_ptr<FourMomentum> four_momentum;

        // Protected constructors enforce proper inheritance hierarchy
        // and prevent direct instantiation of base class
        Particle(ParticleInfo::ParticleType type);

        // Parameterized constructor
        Particle(ParticleInfo::ParticleType type, double px, double py, double pz);

        // Rule of Five implementation for proper resource management
        // Copy operations are protected to prevent slicing
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
        // Const qualifier ensures the function doesn't modify particle state
        virtual void print_data() const;

        // Accessor methods are const to maintain object immutability
        // Return by value for four_momentum to prevent external modification
        FourMomentum get_four_momentum() const { return *four_momentum; }

        // Function to get the properties of the particle
        ParticleInfo::ParticleProperties get_properties() const { return properties; }
    };