#pragma once

#include "Hadron.h"


class Neutron : public Hadron
{
    public:

        // Destructor
        ~Neutron() override = default;

        // Default constructor
        Neutron() : Hadron(ParticleInfo::ParticleType::NEUTRON) {}

        // Parameterized constructor
        Neutron(double px, double py, double pz)
        : Hadron(ParticleInfo::ParticleType::NEUTRON, px, py, pz) {}

        // Copy constructor
        Neutron(const Neutron& other) = default;
        
        // Move constructor
        Neutron(Neutron&& other) = default;

        // Copy assignment operator
        Neutron& operator=(const Neutron& other) = default;

        // Move assignment operator
        Neutron& operator=(Neutron&& other) = default;
};