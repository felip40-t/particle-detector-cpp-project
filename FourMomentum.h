#pragma once

#include <cmath>
#include <vector>
#include <memory>
#include <array>
#include <random>
#include <string>
#include <stdexcept>
#include <iostream>

class FourMomentum
{
    private:
        std::array<double, 4> four_momentum; // 4-momentum array with fixed size

    public:
        // Default constructor for random momentum
        FourMomentum(double rest_mass);

        // Destructor
        ~FourMomentum();

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

        // Overloaded sum operator
        FourMomentum operator+(const FourMomentum& other) const;

        // Overloaded subtraction operator
        FourMomentum operator-(const FourMomentum& other) const;

        // Dot product
        friend double dot_product(const FourMomentum& four_momentum1, const FourMomentum& four_momentum2);
};