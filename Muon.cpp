#include "Muon.h"

// Muon class implementation
// Default constructor
Muon::Muon()
{
    // Get muon properties
    properties = ParticleInfo::get_particle_properties(ParticleInfo::ParticleType::Muon);
    // Create a new FourMomentum object with random momentum
    four_momentum = std::make_unique<FourMomentum>(properties.get_mass());
}

// Parameterized constructor
Muon::Muon(double px, double py, double pz)
{
    // Get muon properties
    properties = ParticleInfo::get_particle_properties(ParticleInfo::ParticleType::Muon);
    // Create a new FourMomentum object
    four_momentum = std::make_unique<FourMomentum>(properties.get_mass(), px, py, pz);
}

// Copy assignment operator
Muon& Muon::operator=(const Muon& other)
{
    if (this != &other) 
    {
        Lepton::operator=(other); // Call base class assignment operator
    }
    return *this;
}

// Move assignment operator
Muon& Muon::operator=(Muon&& other)
{
    if (this != &other) 
    {
        Lepton::operator=(std::move(other)); // Call base class move assignment operator
    }
    return *this;
}

// Antimuon class implementation
// Default constructor
Antimuon::Antimuon()
{
    // Get antimuon properties
    properties = ParticleInfo::get_particle_properties(ParticleInfo::ParticleType::Antimuon);
    // Create a new FourMomentum object with random momentum
    four_momentum = std::make_unique<FourMomentum>(properties.get_mass());
}

// Parameterized constructor
Antimuon::Antimuon(double px, double py, double pz)
{
    // Get antimuon properties
    properties = ParticleInfo::get_particle_properties(ParticleInfo::ParticleType::Antimuon);
    // Create a new FourMomentum object
    four_momentum = std::make_unique<FourMomentum>(properties.get_mass(), px, py, pz);
}

// Copy assignment operator
Antimuon& Antimuon::operator=(const Antimuon& other)
{
    if (this != &other) 
    {
        Muon::operator=(other); // Call base class assignment operator
    }
    return *this;
}

// Move assignment operator
Antimuon& Antimuon::operator=(Antimuon&& other)
{
    if (this != &other) 
    {
        Muon::operator=(std::move(other)); // Call base class move assignment operator
    }
    return *this;
}