#include "Lepton.h"


// Lepton class implementation
// Default constructor
Lepton::Lepton()
{
    // Get lepton properties
    ParticleProperties properties = get_particle_properties(ParticleType::Lepton);
    // Create a new FourMomentum object with random momentum
    four_momentum = std::make_unique<FourMomentum>(properties.mass);
}

// Parameterized constructor
Lepton::Lepton(double px, double py, double pz)
{
    // Get lepton properties
    ParticleProperties properties = get_particle_properties(ParticleType::Lepton);
    // Create a new FourMomentum object
    four_momentum = std::make_unique<FourMomentum>(properties.mass, px, py, pz);
}

// Copy assignment operator
Lepton& Lepton::operator=(const Lepton& other)
{
    if (this != &other) 
    {
        Particle::operator=(other); // Call base class assignment operator
    }
    return *this;
}

// Move assignment operator
Lepton& Lepton::operator=(Lepton&& other)
{
    if (this != &other) 
    {
        Particle::operator=(std::move(other)); // Call base class move assignment operator
    }
    return *this;
}


// Electron class implementation
// Default constructor
Electron::Electron()
{
    // Get electron properties
    ParticleProperties properties = get_particle_properties(ParticleType::Electron);
    // Create a new FourMomentum object with random momentum
    four_momentum = std::make_unique<FourMomentum>(properties.mass);
}

// Parameterized constructor
Electron::Electron(double px, double py, double pz)
{
    // Get electron properties
    ParticleProperties properties = get_particle_properties(ParticleType::Electron);
    // Create a new FourMomentum object
    four_momentum = std::make_unique<FourMomentum>(properties.mass, px, py, pz);
}

// Copy assignment operator
Electron& Electron::operator=(const Electron& other)
{
    if (this != &other) 
    {
        Lepton::operator=(other); // Call base class assignment operator
    }
    return *this;
}

// Move assignment operator
Electron& Electron::operator=(Electron&& other)
{
    if (this != &other) 
    {
        Lepton::operator=(std::move(other)); // Call base class move assignment operator
    }
    return *this;
}