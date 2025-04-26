#include "Electron.h"

// Positron class implementation
// Default constructor
Positron::Positron()
: Electron()
{
    // Get positron properties
    properties = ParticleInfo::get_particle_properties(ParticleInfo::ParticleType::POSITRON);
    // Set lepton number
    lepton_number = -1;
}

// Parameterized constructor
Positron::Positron(double px, double py, double pz)
: Electron(px, py, pz)
{
    // Get positron properties
    properties = ParticleInfo::get_particle_properties(ParticleInfo::ParticleType::POSITRON);
    // Set lepton number
    lepton_number = -1;
}
