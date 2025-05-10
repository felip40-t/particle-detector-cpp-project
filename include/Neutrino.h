#pragma once
#include "Lepton.h"

class Neutrino : public Lepton
{
    protected:
        // Neutrino mass upper limit
        static constexpr double mass_limit = 8e-7; // MeV/c^2

    public:
        // Destructor
        ~Neutrino() override = default;

        // Default constructor
        Neutrino() : Lepton(ParticleInfo::ParticleType::NEUTRINO) {}

        // Parameterized constructor
        Neutrino(double px, double py, double pz)
        : Lepton(ParticleInfo::ParticleType::NEUTRINO, px, py, pz) {}

        // Copy constructor
        Neutrino(const Neutrino& other) = default;

        // Move constructor
        Neutrino(Neutrino&& other) = default;

        // Copy assignment operator
        Neutrino& operator=(const Neutrino& other) = default;

        // Move assignment operator
        Neutrino& operator=(Neutrino&& other) = default;

        // Override print function
        void print_data() const override;
};

// Class for anti-neutrinos
class Antineutrino : public Neutrino
{
    public:
        // Destructor
        ~Antineutrino() override = default;

        // Default constructor
        Antineutrino();

        // Parameterized constructor
        Antineutrino(double px, double py, double pz);

        // Copy constructor
        Antineutrino(const Antineutrino& other) = default;

        // Move constructor
        Antineutrino(Antineutrino&& other) = default;

        // Copy assignment operator
        Antineutrino& operator=(const Antineutrino& other) = default;

        // Move assignment operator
        Antineutrino& operator=(Antineutrino&& other) = default;
};