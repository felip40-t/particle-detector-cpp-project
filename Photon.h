#pragma once
#include "Particle.h"

class Photon : public Particle
{
    public:
        // Default constructor
        Photon();
        
        // Destructor
        ~Photon() override = default;
        
        // Parameterized constructor
        Photon(double px, double py, double pz);
        
        // Copy constructor
        Photon(const Photon& other) : Particle(other) {}
        
        // Move constructor
        Photon(Photon&& other) : Particle(std::move(other)) {}
        
        // Copy assignment operator
        Photon& operator=(const Photon& other);
        
        // Move assignment operator
        Photon& operator=(Photon&& other);
};