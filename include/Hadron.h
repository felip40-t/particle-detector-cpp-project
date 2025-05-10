#pragma once
#include "Particle.h"

class Hadron : public Particle
{
    // Protected to prevent direct instantiation
    protected:
        // Baryon number: +1 for baryons, -1 for antibaryons, 0 for mesons
        int baryon_number {1};

        // Default constructor
        Hadron(ParticleInfo::ParticleType type) : Particle(type) {}

        // Parameterized constructor
        Hadron(ParticleInfo::ParticleType type, double px, double py, double pz)
        : Particle(type, px, py, pz) {}

        // Copy constructor
        Hadron(const Hadron& other) = default;

        // Move constructor
        Hadron(Hadron&& other) = default;

        // Copy assignment operator
        Hadron& operator=(const Hadron& other) = default;

        // Move assignment operator
        Hadron& operator=(Hadron&& other) = default;

    public:
        // Destructor
        virtual ~Hadron() = default;

        // Override print function
        void print_data() const override;

        // Get baryon number
        int get_baryon_number() const { return baryon_number; }
};
