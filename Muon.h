#pragma once
#include "Lepton.h"

class Muon : public Lepton
{
    public:
        // Default constructor
        Muon();

        // Destructor
        ~Muon() override = default;

        // Parameterized constructor
        Muon(double px, double py, double pz);

        // Copy constructor
        Muon(const Muon& other) : Lepton(other) {}

        // Move constructor
        Muon(Muon&& other) : Lepton(std::move(other)) {}

        // Copy assignment operator
        Muon& operator=(const Muon& other);

        // Move assignment operator
        Muon& operator=(Muon&& other);
};

class Antimuon : public Muon
{
    public:
        // Default constructor
        Antimuon();

        // Destructor
        ~Antimuon() override = default;

        // Parameterized constructor
        Antimuon(double px, double py, double pz);

        // Copy constructor
        Antimuon(const Antimuon& other) : Muon(other) {}

        // Move constructor
        Antimuon(Antimuon&& other) : Muon(std::move(other)) {}

        // Copy assignment operator
        Antimuon& operator=(const Antimuon& other);

        // Move assignment operator
        Antimuon& operator=(Antimuon&& other);
};