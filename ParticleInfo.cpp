#include "ParticleInfo.h"

namespace ParticleInfo
{

    // Default constructor for ParticleProperties
    ParticleProperties::ParticleProperties()
        : type(ParticleType::PHOTON), mass(0.0), charge(0.0), name("Photon") {}

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
        : type(other.type), mass(other.mass), charge(other.charge), name(std::move(other.name)) {}

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
        }
        return *this;
    }


    // Define the static map to hold particle properties
    const ParticleProperties& get_particle_properties(ParticleType type)
    {
        // Map to hold particle properties
        static const std::map<ParticleType, ParticleProperties> particle_map = {
            {ParticleType::NEUTRINO, ParticleProperties(ParticleType::NEUTRINO, 0.0, 0.0, "Neutrino")},
            {ParticleType::ANTI_NEUTRINO, ParticleProperties(ParticleType::ANTI_NEUTRINO, 0.0, 0.0, "Antineutrino")},
            {ParticleType::ELECTRON, ParticleProperties(ParticleType::ELECTRON, 0.511, -1.0, "Electron")},
            {ParticleType::POSITRON, ParticleProperties(ParticleType::POSITRON, 0.511, +1.0, "Positron")},
            {ParticleType::MUON, ParticleProperties(ParticleType::MUON, 105.7, -1.0, "Muon")},
            {ParticleType::ANTI_MUON, ParticleProperties(ParticleType::ANTI_MUON, 105.7, +1.0, "Antimuon")},
            {ParticleType::PROTON, ParticleProperties(ParticleType::PROTON, 938.3, +1.0, "Proton")},
            {ParticleType::NEUTRON, ParticleProperties(ParticleType::NEUTRON, 939.6, 0.0, "Neutron")},
            {ParticleType::PION_PLUS, ParticleProperties(ParticleType::PION_PLUS, 139.6, +1.0, "Pion+")},
            {ParticleType::PION_MINUS, ParticleProperties(ParticleType::PION_MINUS, 139.6, -1.0, "Pion-")},
            {ParticleType::PION_0, ParticleProperties(ParticleType::PION_0, 134.9, 0.0, "Pion0")},
            {ParticleType::KAON_PLUS, ParticleProperties(ParticleType::KAON_PLUS, 493.7, +1.0, "Kaon+")},
            {ParticleType::KAON_MINUS, ParticleProperties(ParticleType::KAON_MINUS, 493.7, -1.0, "Kaon-")},
            {ParticleType::KAON_0, ParticleProperties(ParticleType::KAON_0, 497.6, 0.0, "Kaon0")},
            {ParticleType::PHOTON, ParticleProperties(ParticleType::PHOTON, 0.0, 0.0, "Photon")}
        };
        auto it = particle_map.find(type);
        if (it == particle_map.end())
        {
            return particle_map.at(ParticleType::PHOTON); // Return default particle properties if type not found
        }
        else
        {
            return particle_map.at(type);
        }
    }

}