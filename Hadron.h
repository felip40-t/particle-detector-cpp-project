#pragma once
#include "Particle.h"

class Hadron : public Particle
{
    public:
        // Default constructor
        Hadron();

        // Destructor
        ~Hadron() override = default;

        // Parameterized constructor
        Hadron(double px, double py, double pz);

        // Copy constructor
        Hadron(const Hadron& other) : Particle(other) {}

        // Move constructor
        Hadron(Hadron&& other) : Particle(std::move(other)) {}

        // Copy assignment operator
        Hadron& operator=(const Hadron& other);

        // Move assignment operator
        Hadron& operator=(Hadron&& other);
}