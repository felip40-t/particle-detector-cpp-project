#include "Photon.h"

Photon::Photon()
{
    // Get photon properties
    properties = ParticleInfo::get_particle_properties(ParticleInfo::ParticleType::Photon);
    // Create a new FourMomentum object with random momentum
    four_momentum = std::make_unique<FourMomentum>(properties.get_mass());
}

// Parameterized constructor
Photon::Photon(double px, double py, double pz)
{
    // Get photon properties
    properties = ParticleInfo::get_particle_properties(ParticleInfo::ParticleType::Photon);
    // Create a new FourMomentum object
    four_momentum = std::make_unique<FourMomentum>(properties.get_mass(), px, py, pz);
}

// Copy assignment operator
Photon& Photon::operator=(const Photon& other)
{
    if (this != &other) 
    {
        Particle::operator=(other); // Call base class assignment operator
    }
    return *this;
}

// Move assignment operator
Photon& Photon::operator=(Photon&& other)
{
    if (this != &other) 
    {
        Particle::operator=(std::move(other)); // Call base class move assignment operator
    }
    return *this;
}

