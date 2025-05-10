#pragma once

#include <cmath>
#include <vector>
#include <memory>
#include <array>
#include <random>
#include <string>
#include <stdexcept>
#include <iostream>

/**
 * @brief Tag struct for private constructor access
 * 
 * This struct is used as a tag to enable private constructor access
 * for specific operations like reconstruction and operator overloading.
 * This pattern helps maintain encapsulation while allowing controlled
 * access to private construction.
 */
struct RawTag {};

/**
 * @brief Represents the four-momentum of a particle in special relativity
 * 
 * This class encapsulates the four-momentum (E, px, py, pz) of particles,
 * providing a type-safe interface for relativistic calculations. The class
 * is designed to be immutable after construction to maintain physical
 * consistency.
 * 
 * Design Decisions:
 * 1. Using std::array for fixed-size, contiguous storage of components
 * 2. Immutable design after construction to maintain physical consistency
 * 3. Friend functions for specific operations that need private access
 * 4. Operator overloading for intuitive mathematical operations
 */
class FourMomentum
{
    private:
        // Using std::array for fixed-size
        std::array<double, 4> four_momentum; // (E, px, py, pz)

        // Private constructor with RawTag to control object creation
        // Used internally for reconstruction and operator overloading
        // Ensures proper initialization of four-momentum components
        FourMomentum(double E, double px, double py, double pz, RawTag);

    public:
        // Default constructor creates a zero four-momentum
        // Useful for initialization and temporary objects
        FourMomentum() = default;
        
        // Constructor for random momentum generation
        // Takes rest mass to ensure physical consistency
        // Useful for Monte Carlo simulations
        FourMomentum(double rest_mass);

        // Default destructor is sufficient as we use std::array
        ~FourMomentum() = default;

        // Main constructor that enforces physical constraints
        // Takes rest mass and momentum components
        // Calculates energy using E² = p² + m²
        FourMomentum(double rest_mass, double px, double py, double pz);

        // Rule of Five implementation for proper resource management
        // Copy and move operations maintain physical consistency
        FourMomentum(const FourMomentum& other);
        FourMomentum(FourMomentum&& other);
        FourMomentum& operator=(const FourMomentum& other);
        FourMomentum& operator=(FourMomentum&& other);

        // Const accessor for component retrieval
        // Index-based access for flexibility in calculations
        double get_component(int index) const;

        // Setter for momentum components
        // Note: Energy is not directly settable to maintain
        // physical consistency with momentum
        // Index: 1 for px, 2 for py, 3 for pz
        void set_momentum_component(int index, double value);

        // Debug and display function
        // Const to maintain immutability
        void print() const;

        // Mathematical operations that maintain physical consistency
        // All operations are const to maintain immutability
        FourMomentum operator+(const FourMomentum& other) const;
        FourMomentum operator-(const FourMomentum& other) const;
        double operator*(const FourMomentum& other) const;

        // Friend function for reconstruction
        // Needs access to private constructor
        friend FourMomentum reconstruct(double E, double px, double py, double pz);
};


// External reconstruction function
FourMomentum reconstruct(double E, double px, double py, double pz);
