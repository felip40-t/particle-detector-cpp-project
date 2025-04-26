#include "Hadron.h"

// Hadron class implementation

// Override print function
void Hadron::print_data() const
{
    Particle::print_data();
    std::cout << "Baryon number: " << baryon_number << "\n";
}