#pragma once

#include "Hadron.h"

class Proton : public Hadron
{
    public:

        // Destructor
        ~Proton() override = default;

        // Default constructor
        Proton() : Hadron(ParticleInfo::ParticleType::PROTON) {};

        // Parameterized constructor
        Proton(double px, double py, double pz)
        : Hadron(ParticleInfo::ParticleType::PROTON, px, py, pz) {}

        // Copy constructor
        Proton(const Proton& other) = default;
        
        // Move constructor
        Proton(Proton&& other) = default;

        // Copy assignment operator
        Proton& operator=(const Proton& other) = default;

        // Move assignment operator
        Proton& operator=(Proton&& other) = default;
};