#pragma once

#include <string>
#include <map>
using std::string;


// Enumerator class for particle types
enum class ParticleType
{
    Particle,
    Lepton,
    Hadron,
    Electron,
    Positron,
    Muon,
    Antimuon,
    Proton,
    Neutron,
    Photon,
};

// Struct for particle properties
struct ParticleProperties
{
    ParticleType type; // Type of the particle
    double mass; // Mass in MeV/c^2
    double charge; // Charge in e
    string name; // Name of the particle

    // Default constructor
    ParticleProperties();

    // Constructor for ParticleProperties
    ParticleProperties(ParticleType type, double mass, double charge, const string& name);

    // Destructor
    ~ParticleProperties();

    // Copy constructor
    ParticleProperties(const ParticleProperties& other);

    // Move constructor
    ParticleProperties(ParticleProperties&& other);

    // Copy assignment operator
    ParticleProperties& operator=(const ParticleProperties& other);

    // Move assignment operator
    ParticleProperties& operator=(ParticleProperties&& other);
};


// Function to get particle properties by type using static map
static ParticleProperties get_particle_properties(ParticleType type);