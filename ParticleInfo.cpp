#include "ParticleInfo.h"

// Default constructor for ParticleProperties
ParticleProperties::ParticleProperties()
{
    *this = ParticleInfo::get_particle_properties(ParticleType::Particle); // Initialize with default particle properties
}

// Constructor for ParticleProperties
ParticleProperties::ParticleProperties(ParticleType type, double mass, double charge, const string& name)
    : type(type), mass(mass), charge(charge), name(name) {}

// Destructor for ParticleProperties
ParticleProperties::~ParticleProperties() {}

// Copy constructor for ParticleProperties
ParticleProperties::ParticleProperties(const ParticleProperties& other)
    : type(other.type), mass(other.mass), charge(other.charge), name(other.name) {}

// Move constructor for ParticleProperties
ParticleProperties::ParticleProperties(ParticleProperties&& other)
    : type(other.type), mass(other.mass), charge(other.charge), name(std::move(other.name))
{
    other = ParticleProperties(); // Reset the moved-from object
}

// Copy assignment operator for ParticleProperties
ParticleProperties& ParticleProperties::operator=(const ParticleProperties& other)
{
    if (this != &other) // Avoid self-assignment
    {
        type = other.type;
        mass = other.mass;
        charge = other.charge;
        name = other.name;
    }
    return *this;
}

// Move assignment operator for ParticleProperties
ParticleProperties& ParticleProperties::operator=(ParticleProperties&& other)
{
    if (this != &other) // Avoid self-assignment
    {
        type = other.type;
        mass = other.mass;
        charge = other.charge;
        name = std::move(other.name);
        other = ParticleProperties(); // Reset the moved-from object
    }
    return *this;
}




// Define the static map to hold particle properties
static ParticleProperties get_particle_properties(ParticleType type)
{
    // Map to hold particle properties
    static std::map<ParticleType, ParticleProperties> particle_map = {
        {ParticleType::Particle, ParticleProperties(ParticleType::Particle, 0.0, 0.0, "Unknown")},
        {ParticleType::Lepton, ParticleProperties(ParticleType::Lepton, 0.0, 0.0, "Lepton")},
        {ParticleType::Hadron, ParticleProperties(ParticleType::Hadron, 0.0, 0.0, "Hadron")},
        {ParticleType::Electron, ParticleProperties(ParticleType::Electron, 0.511, -1.0, "Electron")},
        {ParticleType::Positron, ParticleProperties(ParticleType::Positron, 0.511, +1.0, "Positron")},
        {ParticleType::Muon, ParticleProperties(ParticleType::Muon, 105.7, -1.0, "Muon")},
        {ParticleType::Antimuon, ParticleProperties(ParticleType::Antimuon, 105.7, +1.0, "Antimuon")},
        {ParticleType::Proton, ParticleProperties(ParticleType::Proton, 938.3, +1.0, "Proton")},
        {ParticleType::Neutron, ParticleProperties(ParticleType::Neutron, 939.6, 0.0, "Neutron")},
        {ParticleType::Photon, ParticleProperties(ParticleType::Photon, 0.0, 0.0, "Photon")}
    };
    auto it = particle_map.find(type);
    if (it == particle_map.end())
    {
        return particle_map[ParticleType::Particle]; // Return default particle properties if type not found
    }
    else
    {
        return particle_map[type];
    }
}