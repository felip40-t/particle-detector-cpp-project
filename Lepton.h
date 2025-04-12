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


class Electron : public Lepton
{
    public:
        // Default constructor
        Electron();

        // Destructor
        ~Electron() override = default;

        // Parameterized constructor
        Electron(double px, double py, double pz);

        // Copy constructor
        Electron(const Electron& other) : Lepton(other) {}

        // Move constructor
        Electron(Electron&& other) : Lepton(std::move(other)) {}

        // Copy assignment operator
        Electron& operator=(const Electron& other);

        // Move assignment operator
        Electron& operator=(Electron&& other);

        // Override print function
        void print_data() const override;
};