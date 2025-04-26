#pragma once
#include "Lepton.h"


class Electron : public Lepton
{
    public:
        // Destructor
        ~Electron() override = default;

        // Default constructor
        Electron() : Lepton(ParticleInfo::ParticleType::ELECTRON) {}

        // Parameterized constructor
        Electron(double px, double py, double pz)
        : Lepton(ParticleInfo::ParticleType::ELECTRON, px, py, pz) {}

        // Copy constructor
        Electron(const Electron& other) = default;

        // Move constructor
        Electron(Electron&& other) = default;

        // Copy assignment operator
        Electron& operator=(const Electron& other) = default;

        // Move assignment operator
        Electron& operator=(Electron&& other) = default;

};

class Positron : public Electron
{
    public:
        
        // Destructor
        ~Positron() override = default;

        // Default constructor
        Positron();

        // Parameterized constructor
        Positron(double px, double py, double pz);

        // Copy constructor
        Positron(const Positron& other) = default;

        // Move constructor
        Positron(Positron&& other) = default;

        // Copy assignment operator
        Positron& operator=(const Positron& other) = default;

        // Move assignment operator
        Positron& operator=(Positron&& other) = default;
};