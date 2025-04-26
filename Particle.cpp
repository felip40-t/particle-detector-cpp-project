#include "Particle.h"

// Default constructor
Particle::Particle(ParticleInfo::ParticleType type)
{
    // Get particle properties
    properties = ParticleInfo::get_particle_properties(type);
    // Create a new FourMomentum object with random momentum
    four_momentum = std::make_unique<FourMomentum>(properties.get_mass());
}

// Parameterized constructor
Particle::Particle(ParticleInfo::ParticleType type, double px, double py, double pz)
{
    // Get particle properties
    properties = ParticleInfo::get_particle_properties(type);
    // Create a new FourMomentum object
    four_momentum = std::make_unique<FourMomentum>(properties.get_mass(), px, py, pz);
}

// Copy constructor
Particle::Particle(const Particle& other)
    : properties(other.properties), four_momentum(std::make_unique<FourMomentum>(*other.four_momentum)) {}

// Move constructor
Particle::Particle(Particle&& other)
    : properties(std::move(other.properties)), four_momentum(std::move(other.four_momentum)) {}

// Copy assignment operator
Particle& Particle::operator=(const Particle& other)
{
    if (this != &other) 
    {
        properties = other.properties;
        four_momentum = std::make_unique<FourMomentum>(*other.four_momentum);
    }
    return *this;
}

// Move assignment operator
Particle& Particle::operator=(Particle&& other)
{
    if (this != &other) 
    {
        properties = std::move(other.properties);
        four_momentum = std::move(other.four_momentum);
    }
    return *this;
}

// Virtual print function
void Particle::print_data() const
{
    std::cout << properties.get_name() << "\n";
    std::cout << "Particle mass: " << properties.get_mass() << " MeV/c^2\n";
    std::cout << "Particle charge: " << properties.get_charge() << " e\n";
    std::cout << "Four momentum: [";
    for (int i = 0; i < 4; ++i) {
        std::cout << four_momentum->get_component(i);
        if (i < 3) std::cout << ", ";
    }
    std::cout << "]\n";
}