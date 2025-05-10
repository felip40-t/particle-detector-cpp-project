#pragma once
#include "Particle.h"

class Photon : public Particle
{
    public:

        // Destructor
        ~Photon() override = default;

        // Default constructor
        Photon() : Particle(ParticleInfo::ParticleType::PHOTON) {}
        
        // Parameterized constructor
        Photon(double px, double py, double pz) 
        : Particle(ParticleInfo::ParticleType::PHOTON, px, py, pz) {}
        
        // Copy constructor
        Photon(const Photon& other) = default;
        
        // Move constructor
        Photon(Photon&& other) = default;
        
        // Copy assignment operator
        Photon& operator=(const Photon& other) = default;
        
        // Move assignment operator
        Photon& operator=(Photon&& other) = default;
};