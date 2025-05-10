#pragma once

#include "Hadron.h"

class Pion : public Hadron
{
    protected:
        // Default constructor
        Pion(ParticleInfo::ParticleType type) : Hadron(type) { baryon_number = 0; }

        // Parameterized constructor
        Pion(ParticleInfo::ParticleType type, double px, double py, double pz)
        : Hadron(type, px, py, pz) { baryon_number = 0; }

        // Copy constructor
        Pion(const Pion& other) = default;

        // Move constructor
        Pion(Pion&& other) = default;

        // Copy assignment operator
        Pion& operator=(const Pion& other) = default;

        // Move assignment operator
        Pion& operator=(Pion&& other) = default;
    
    public:
        // Destructor
        virtual ~Pion() = default;

};

// Class for positive pion
class PionPlus : public Pion
{
    public:
        // Destructor
        ~PionPlus() override = default;

        // Default constructor
        PionPlus() : Pion(ParticleInfo::ParticleType::PION_PLUS) {}

        // Parameterized constructor
        PionPlus(double px, double py, double pz)
        : Pion(ParticleInfo::ParticleType::PION_PLUS, px, py, pz) {}

        // Copy constructor
        PionPlus(const PionPlus& other) = default;

        // Move constructor
        PionPlus(PionPlus&& other) = default;

        // Copy assignment operator
        PionPlus& operator=(const PionPlus& other) = default;

        // Move assignment operator
        PionPlus& operator=(PionPlus&& other) = default;
};

// Class for negative pion
class PionMinus : public Pion
{
    public:
        // Destructor
        ~PionMinus() override = default;

        // Default constructor
        PionMinus() : Pion(ParticleInfo::ParticleType::PION_MINUS) {}

        // Parameterized constructor
        PionMinus(double px, double py, double pz)
        : Pion(ParticleInfo::ParticleType::PION_MINUS, px, py, pz) {}

        // Copy constructor
        PionMinus(const PionMinus& other) = default;

        // Move constructor
        PionMinus(PionMinus&& other) = default;

        // Copy assignment operator
        PionMinus& operator=(const PionMinus& other) = default;

        // Move assignment operator
        PionMinus& operator=(PionMinus&& other) = default;
};

// Class for neutral pion
class PionZero : public Pion
{
    public:
        // Destructor
        ~PionZero() override = default;

        // Default constructor
        PionZero() : Pion(ParticleInfo::ParticleType::PION_0) {}

        // Parameterized constructor
        PionZero(double px, double py, double pz)
        : Pion(ParticleInfo::ParticleType::PION_0, px, py, pz) {}

        // Copy constructor
        PionZero(const PionZero& other) = default;

        // Move constructor
        PionZero(PionZero&& other) = default;

        // Copy assignment operator
        PionZero& operator=(const PionZero& other) = default;

        // Move assignment operator
        PionZero& operator=(PionZero&& other) = default;
};
