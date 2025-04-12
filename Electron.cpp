#include "Electron.h"


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

// Positron class implementation
// Default constructor
Positron::Positron()
{
    // Get positron properties
    ParticleProperties properties = get_particle_properties(ParticleType::Positron);
    // Create a new FourMomentum object with random momentum
    four_momentum = std::make_unique<FourMomentum>(properties.mass);
}

// Parameterized constructor
Positron::Positron(double px, double py, double pz)
{
    // Get positron properties
    ParticleProperties properties = get_particle_properties(ParticleType::Positron);
    // Create a new FourMomentum object
    four_momentum = std::make_unique<FourMomentum>(properties.mass, px, py, pz);
}

// Copy assignment operator
Positron& Positron::operator=(const Positron& other)
{
    if (this != &other) 
    {
        Electron::operator=(other); // Call base class assignment operator
    }
    return *this;
}

// Move assignment operator
Positron& Positron::operator=(Positron&& other)
{
    if (this != &other) 
    {
        Electron::operator=(std::move(other)); // Call base class move assignment operator
    }
    return *this;
}