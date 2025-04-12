#pragma once
#include "Lepton.h"


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

};

class Positron : public Electron
{
    public:
        // Default constructor
        Positron();

        // Destructor
        ~Positron() override = default;

        // Parameterized constructor
        Positron(double px, double py, double pz);

        // Copy constructor
        Positron(const Positron& other) : Electron(other) {}

        // Move constructor
        Positron(Positron&& other) : Electron(std::move(other)) {}

        // Copy assignment operator
        Positron& operator=(const Positron& other);

        // Move assignment operator
        Positron& operator=(Positron&& other);
};