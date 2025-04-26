#pragma once
#include "Particle.h"

class Lepton : public Particle
{   
    protected:
        // +1 for leptons and -1 for antileptons
        int lepton_number {1};

        // Default constructor
        Lepton(ParticleInfo::ParticleType type) : Particle(type) {}

        // Parameterized constructor
        Lepton(ParticleInfo::ParticleType type, double px, double py, double pz)
            : Particle(type, px, py, pz) {}

        // Copy constructor
        Lepton(const Lepton& other) = default;

        // Move constructor
        Lepton(Lepton&& other) = default;

        // Copy assignment operator
        Lepton& operator=(const Lepton& other) = default;

        // Move assignment operator
        Lepton& operator=(Lepton&& other) = default;

    public:
        // Destructor
        virtual ~Lepton() = default;

        // Override print function
        void print_data() const override;
};
