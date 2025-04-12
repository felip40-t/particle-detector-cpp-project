#include "Particle.h"

// Default constructor
Particle::Particle()
{
    // Get particle properties
    ParticleProperties properties = get_particle_properties(ParticleType::Particle);
    // Create a new FourMomentum object with random momentum
    four_momentum = std::make_unique<FourMomentum>(properties.mass);
}

// Parameterized constructor
Particle::Particle(double px, double py, double pz)
{
    // Get particle properties
    ParticleProperties properties = get_particle_properties(ParticleType::Particle);
    // Create a new FourMomentum object
    four_momentum = std::make_unique<FourMomentum>(properties.mass, px, py, pz);
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
    if (this != &other) {
        properties = other.properties;
        four_momentum = std::make_unique<FourMomentum>(*other.four_momentum);
    }
    return *this;
}

// Move assignment operator
Particle& Particle::operator=(Particle&& other)
{
    if (this != &other) {
        properties = std::move(other.properties);
        four_momentum = std::move(other.four_momentum);
    }
    return *this;
}

// Virtual print function
void Particle::print_data() const
{
    std::cout << "Particle: " << properties.name << "\n";
    std::cout << "Particle mass: " << properties.mass << " MeV/c^2\n";
    std::cout << "Particle charge: " << properties.charge << " e\n";
    std::cout << "Four momentum: ("
              << four_momentum->get_energy() << ", "
              << four_momentum->get_px() << ", "
              << four_momentum->get_py() << ", "
              << four_momentum->get_pz() << ")\n";
}