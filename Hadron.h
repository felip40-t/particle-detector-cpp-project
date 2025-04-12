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
};

class Proton : public Hadron
{
    public:
        // Default constructor
        Proton();

        // Destructor
        ~Proton() override = default;

        // Parameterized constructor
        Proton(double px, double py, double pz);

        // Copy constructor
        Proton(const Proton& other) : Hadron(other) {}

        // Move constructor
        Proton(Proton&& other) : Hadron(std::move(other)) {}

        // Copy assignment operator
        Proton& operator=(const Proton& other);

        // Move assignment operator
        Proton& operator=(Proton&& other);
};

class Neutron : public Hadron
{
    public:
        // Default constructor
        Neutron();

        // Destructor
        ~Neutron() override = default;

        // Parameterized constructor
        Neutron(double px, double py, double pz);

        // Copy constructor
        Neutron(const Neutron& other) : Hadron(other) {}

        // Move constructor
        Neutron(Neutron&& other) : Hadron(std::move(other)) {}

        // Copy assignment operator
        Neutron& operator=(const Neutron& other);

        // Move assignment operator
        Neutron& operator=(Neutron&& other);
};