#pragma once

#include <cmath>
#include <iostream>
#include <vector>
#include <memory>
#include <array>
#include <random>

class FourMomentum
{
    private:
        std::array<double, 4> four_momentum; // 4-momentum vector with fixed size

    public:
        // Default constructor
        FourMomentum();

        // Destructor
        ~FourMomentum();

        // Parameterized constructor
        FourMomentum(double E, double px, double py, double pz);

        // Copy constructor
        FourMomentum(const FourMomentum& other);

        // Move constructor
        FourMomentum(FourMomentum&& other);

        // Copy assignment
        FourMomentum& operator=(const Particle& other);

        // Move assignment
        FourMomentum& operator=(Particle&& other)

        // Getters
        double get_energy() const { return four_momentum[0];}
        double get_px() const { return four_momentum[1];}
        double get_py() const { return four_momentum[2];}
        double get_pz() const { return four_momentum[3];}

        // Setters
        void set_energy(double E);
        void set_px(double px);
        void set_py(double py);
        void set_pz(double pz);

        // Overloaded sum operator
        FourMomentum operator+(const FourMomentum& other) const;

        // Dot product
        double dot_product(const FourMomentum& four_momentum1, const FourMomentum& four_momentum2) const;
}