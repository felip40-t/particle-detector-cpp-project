#include "Lepton.h"

// Override print function
void Lepton::print_data() const
{
    Particle::print_data();
    std::cout << "Lepton number: " << lepton_number << "\n";
}
