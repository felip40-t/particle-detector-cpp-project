#include "Muon.h"

// Antimuon class implementation
// Default constructor
Antimuon::Antimuon()
: Muon()
{
    // Get antimuon properties
    properties = ParticleInfo::get_particle_properties(ParticleInfo::ParticleType::ANTI_MUON);
    // Set lepton number
    lepton_number = -1;
}

// Parameterized constructor
Antimuon::Antimuon(double px, double py, double pz)
: Muon(px, py, pz)
{
    // Get antimuon properties
    properties = ParticleInfo::get_particle_properties(ParticleInfo::ParticleType::ANTI_MUON);
    // Set lepton number
    lepton_number = -1;
}
