#include "Hadron.h"

// Hadron class implementation
// Default constructor
Hadron::Hadron()
{
    // Get particle properties
    ParticleInfo::ParticleProperties properties = ParticleInfo::get_particle_properties(ParticleInfo::ParticleType::Hadron);
    // Create a new FourMomentum object with random momentum
    four_momentum = std::make_unique<FourMomentum>(properties.get_mass());
}

// Parameterized constructor
Hadron::Hadron(double px, double py, double pz)
{
    // Get particle properties
    ParticleInfo::ParticleProperties properties = ParticleInfo::get_particle_properties(ParticleInfo::ParticleType::Hadron);
    // Create a new FourMomentum object
    four_momentum = std::make_unique<FourMomentum>(properties.get_mass(), px, py, pz);
}

// Copy assignment operator
Hadron& Hadron::operator=(const Hadron& other)
{
    if (this != &other) {
        Particle::operator=(other); // Call base class assignment operator
    }
    return *this;
}

// Move assignment operator
Hadron& Hadron::operator=(Hadron&& other)
{
    if (this != &other) {
        Particle::operator=(std::move(other)); // Call base class move assignment operator
    }
    return *this;
}


// Proton class implementation
// Default constructor
Proton::Proton()
{
    // Get particle properties
    ParticleInfo::ParticleProperties properties = ParticleInfo::get_particle_properties(ParticleInfo::ParticleType::Proton);
    // Create a new FourMomentum object with random momentum
    four_momentum = std::make_unique<FourMomentum>(properties.get_mass());
}

// Parameterized constructor
Proton::Proton(double px, double py, double pz)
{
    // Get particle properties
    ParticleInfo::ParticleProperties properties = ParticleInfo::get_particle_properties(ParticleInfo::ParticleType::Proton);
    // Create a new FourMomentum object
    four_momentum = std::make_unique<FourMomentum>(properties.get_mass(), px, py, pz);
}

// Copy assignment operator
Proton& Proton::operator=(const Proton& other)
{
    if (this != &other) {
        Hadron::operator=(other); // Call base class assignment operator
    }
    return *this;
}

// Move assignment operator
Proton& Proton::operator=(Proton&& other)
{
    if (this != &other) {
        Hadron::operator=(std::move(other)); // Call base class move assignment operator
    }
    return *this;
}


// Neutron class implementation
// Default constructor
Neutron::Neutron()
{
    // Get particle properties
    ParticleInfo::ParticleProperties properties = ParticleInfo::get_particle_properties(ParticleInfo::ParticleType::Neutron);
    // Create a new FourMomentum object with random momentum
    four_momentum = std::make_unique<FourMomentum>(properties.get_mass());
}

// Parameterized constructor
Neutron::Neutron(double px, double py, double pz)
{
    // Get particle properties
    ParticleInfo::ParticleProperties properties = ParticleInfo::get_particle_properties(ParticleInfo::ParticleType::Neutron);
    // Create a new FourMomentum object
    four_momentum = std::make_unique<FourMomentum>(properties.get_mass(), px, py, pz);
}

// Copy assignment operator
Neutron& Neutron::operator=(const Neutron& other)
{
    if (this != &other) {
        Hadron::operator=(other); // Call base class assignment operator
    }
    return *this;
}

// Move assignment operator
Neutron& Neutron::operator=(Neutron&& other)
{
    if (this != &other) {
        Hadron::operator=(std::move(other)); // Call base class move assignment operator
    }
    return *this;
}