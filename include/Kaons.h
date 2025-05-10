#pragma once

#include "Hadron.h"

class Kaon : public Hadron
{
    protected:
        // Default constructor
        Kaon(ParticleInfo::ParticleType type) : Hadron(type) { baryon_number = 0; }

        // Parameterized constructor
        Kaon(ParticleInfo::ParticleType type, double px, double py, double pz)
        : Hadron(type, px, py, pz) { baryon_number = 0; }

        // Copy constructor
        Kaon(const Kaon& other) = default;

        // Move constructor
        Kaon(Kaon&& other) = default;

        // Copy assignment operator
        Kaon& operator=(const Kaon& other) = default;

        // Move assignment operator
        Kaon& operator=(Kaon&& other) = default;
    
    public:
        // Destructor
        virtual ~Kaon() = default;
};

// Class for positive kaon
class KaonPlus : public Kaon
{
    public:
        // Destructor
        ~KaonPlus() override = default;

        // Default constructor
        KaonPlus() : Kaon(ParticleInfo::ParticleType::KAON_PLUS) {}

        // Parameterized constructor
        KaonPlus(double px, double py, double pz)
        : Kaon(ParticleInfo::ParticleType::KAON_PLUS, px, py, pz) {}

        // Copy constructor
        KaonPlus(const KaonPlus& other) = default;

        // Move constructor
        KaonPlus(KaonPlus&& other) = default;

        // Copy assignment operator
        KaonPlus& operator=(const KaonPlus& other) = default;

        // Move assignment operator
        KaonPlus& operator=(KaonPlus&& other) = default;
        
};

// Class for negative kaon
class KaonMinus : public Kaon
{
    public:
        // Destructor
        ~KaonMinus() override = default;

        // Default constructor
        KaonMinus() : Kaon(ParticleInfo::ParticleType::KAON_MINUS) {}

        // Parameterized constructor
        KaonMinus(double px, double py, double pz)
        : Kaon(ParticleInfo::ParticleType::KAON_MINUS, px, py, pz) {}

        // Copy constructor
        KaonMinus(const KaonMinus& other) = default;

        // Move constructor
        KaonMinus(KaonMinus&& other) = default;

        // Copy assignment operator
        KaonMinus& operator=(const KaonMinus& other) = default;

        // Move assignment operator
        KaonMinus& operator=(KaonMinus&& other) = default;
};

// Class for neutral kaon
class KaonZero : public Kaon
{
    public:
        // Destructor
        ~KaonZero() override = default;

        // Default constructor
        KaonZero() : Kaon(ParticleInfo::ParticleType::KAON_0) {}

        // Parameterized constructor
        KaonZero(double px, double py, double pz)
        : Kaon(ParticleInfo::ParticleType::KAON_0, px, py, pz) {}

        // Copy constructor
        KaonZero(const KaonZero& other) = default;

        // Move constructor
        KaonZero(KaonZero&& other) = default;

        // Copy assignment operator
        KaonZero& operator=(const KaonZero& other) = default;

        // Move assignment operator
        KaonZero& operator=(KaonZero&& other) = default;
};