#pragma once
#include "Lepton.h"

class Muon : public Lepton
{
    public:

        // Destructor
        ~Muon() override = default;

        // Default constructor
        Muon() : Lepton(ParticleInfo::ParticleType::MUON) {}

        // Parameterized constructor
        Muon(double px, double py, double pz)
        : Lepton(ParticleInfo::ParticleType::MUON, px, py, pz) {}

        // Copy constructor
        Muon(const Muon& other) = default;

        // Move constructor
        Muon(Muon&& other) = default;

        // Copy assignment operator
        Muon& operator=(const Muon& other) = default;

        // Move assignment operator
        Muon& operator=(Muon&& other) = default;
};

class Antimuon : public Muon
{
    public:
        // Destructor
        ~Antimuon() override = default;

        // Default constructor
        Antimuon();

        // Parameterized constructor
        Antimuon(double px, double py, double pz);

        // Copy constructor
        Antimuon(const Antimuon& other) = default;

        // Move constructor
        Antimuon(Antimuon&& other) = default;

        // Copy assignment operator
        Antimuon& operator=(const Antimuon& other) = default;

        // Move assignment operator
        Antimuon& operator=(Antimuon&& other) = default;
};