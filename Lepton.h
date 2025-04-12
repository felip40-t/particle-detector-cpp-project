#pragma once
#include "Particle.h"

class Lepton : public Particle
{   
    public:
        // Default constructor
        Lepton();

        // Destructor
        ~Lepton() override = default;

        // Parameterized constructor
        Lepton(double px, double py, double pz);

        // Copy constructor
        Lepton(const Lepton& other) : Particle(other) {}

        // Move constructor
        Lepton(Lepton&& other) : Particle(std::move(other)) {}

        // Copy assignment operator
        Lepton& operator=(const Lepton& other);

        // Move assignment operator
        Lepton& operator=(Lepton&& other);

};
