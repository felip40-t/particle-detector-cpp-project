#pragma once

#include <cmath>
#include <vector>
#include <memory>
#include <array>
#include <random>
#include <string>
#include <stdexcept>
#include <iostream>

// Raw tag for FourMomentum private constructor which 
// allows for reconstruction of FourMomentum from E, px, py, pz
// and used in operator overloading
struct RawTag {};

class FourMomentum
{
    private:
        // 4-momentum array
        std::array<double, 4> four_momentum;

        // Private constructor for use in operator overloading and reconstruction
        FourMomentum(double E, double px, double py, double pz, RawTag);

    public:
        // Default constructor 
        FourMomentum() = default;
        
        // Constructor for random momentum
        FourMomentum(double rest_mass);

        // Default destructor
        ~FourMomentum() = default;

        // Parameterized constructor
        FourMomentum(double rest_mass, double px, double py, double pz);

        // Copy constructor
        FourMomentum(const FourMomentum& other);

        // Move constructor
        FourMomentum(FourMomentum&& other);

        // Copy assignment
        FourMomentum& operator=(const FourMomentum& other);

        // Move assignment
        FourMomentum& operator=(FourMomentum&& other);

        // Getter
        double get_component(int index) const;

        // Setters
        void set_px(double px);
        void set_py(double py);
        void set_pz(double pz);

        // Print function
        void print() const;

        // Overloaded sum operator
        FourMomentum operator+(const FourMomentum& other) const;

        // Overloaded subtraction operator
        FourMomentum operator-(const FourMomentum& other) const;

        // Overloaded multiplication operator (scalar product)
        double operator*(const FourMomentum& other) const;

        // Reconstruct function
        friend FourMomentum reconstruct(double E, double px, double py, double pz);
};

FourMomentum reconstruct(double E, double px, double py, double pz);
