#include "Neutrino.h"
#include "Utilities.h"

// Neutrino class implementation

// Override print function
void Neutrino::print_data() const
{
    std::cout << properties.get_name() << ":\n";
    std::cout << "Mass limit < " << mass_limit << " MeV/c^2\n";
    std::cout << "Charge: " << properties.get_charge() << " e\n";
    std::cout << "Four momentum: [";
    for (int i = 0; i < 4; ++i) {
        std::cout << four_momentum->get_component(i);
        if (i < 3) std::cout << ", ";
    }
    std::cout << "]\n";
}

// Antineutrino class implementation
// Default constructor
Antineutrino::Antineutrino() : Neutrino()
{
    // Get antineutrino properties
    properties = ParticleInfo::get_particle_properties(ParticleInfo::ParticleType::ANTI_NEUTRINO);
    // Set lepton number
    lepton_number = -1;
}

// Parameterized constructor
Antineutrino::Antineutrino(double px, double py, double pz)
: Neutrino(px, py, pz)
{
    // Get antineutrino properties
    properties = ParticleInfo::get_particle_properties(ParticleInfo::ParticleType::ANTI_NEUTRINO);
    // Set lepton number
    lepton_number = -1;
}