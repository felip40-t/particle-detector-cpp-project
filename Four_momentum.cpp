#include "Four_momentum.h"


// Default constructor: give random momentum and make photon-like
// If particle has mass then change energy later (particle constructor)
FourMomentum::FourMomentum()
{
    // Set maximum energy scale to randomise to
    double ENERGY_SCALE {1000.0}; // MeV
    // Set up random number generator
    std::random_device rand_dev;
    std::mt19937 generator(rand_dev());
    std::uniform_real_distribution<double> distribution(-ENERGY_SCALE, ENERGY_SCALE);

    double energy_sqrd{};

    // Set momenta
    for (int i ; i < 3 ; i++)
    {
        four_momentum[i+1] = distribution(generator);
        energy_sqrd += four_momentum[i+1];
    }
    // Set energy
    four_momentum[0] = sqrt(energy_sqrd);
}