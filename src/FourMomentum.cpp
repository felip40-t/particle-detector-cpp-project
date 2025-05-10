#include "FourMomentum.h"
#include "Utilities.h"

// Private constructor for use in operator overloading and reconstruction
FourMomentum::FourMomentum(double E, double px, double py, double pz, RawTag)
    // Initialize four_momentum with the given values
    : four_momentum{E, px, py, pz} {};


// Default constructor: give random momentum and make photon-like
FourMomentum::FourMomentum(double rest_mass)
{
    // Set maximum energy scale to randomise to
    const double ENERGY_SCALE {1000.0}; // MeV
    // Set up random number generator
    static std::random_device rand_dev;
    static std::mt19937 generator(rand_dev());
    std::uniform_real_distribution<double> distribution(-ENERGY_SCALE, ENERGY_SCALE);
    // Set momenta
    for (int i {0}; i < 3 ; i++)
    {
        four_momentum[i+1] = distribution(generator);
    }
    // Set energy
    four_momentum[0] = sqrt(MathUtils::momentum_squared(four_momentum[1], four_momentum[2], four_momentum[3]) + rest_mass * rest_mass);
}

// Parameterized constructor
FourMomentum::FourMomentum(double rest_mass, double px, double py, double pz)
{
    // Ensure rest mass is non-negative, real and finite
    if (std::isnan(rest_mass) || std::isinf(rest_mass) || rest_mass < 0.0)
    {
        std::cerr << "FourMomentum: Rest mass must be a positive, finite, real number." << std::endl;
        std::cerr << "Setting rest mass to zero." << std::endl;
        rest_mass = 0.0;
    }
    else if (std::isnan(px) || std::isinf(px) || std::isnan(py) || std::isinf(py) || std::isnan(pz) || std::isinf(pz))
    {
        std::cerr << "FourMomentum: Momentum components must be finite, real numbers." << std::endl;
        std::cerr << "Setting momentum components to zero." << std::endl;
        px = py = pz = 0.0;
    }
    four_momentum[0] = sqrt(MathUtils::momentum_squared(px, py, pz) + rest_mass * rest_mass);
    four_momentum[1] = px;
    four_momentum[2] = py;
    four_momentum[3] = pz;
}

// Copy constructor (deep copy)
FourMomentum::FourMomentum(const FourMomentum& other)
{
    four_momentum = other.four_momentum;
}

// Move constructor
FourMomentum::FourMomentum(FourMomentum&& other)
{
    four_momentum = std::move(other.four_momentum);
}

// Copy assignment operator
FourMomentum& FourMomentum::operator=(const FourMomentum& other)
{
    if (this != &other) // Avoid self-assignment
    {
        four_momentum = other.four_momentum;
    }
    return *this;
}

// Move assignment operator
FourMomentum& FourMomentum::operator=(FourMomentum&& other)
{
    if (this != &other) // Avoid self-assignment
    {
        four_momentum = std::move(other.four_momentum);
    }
    return *this;
}

// Getter for momentum components
double FourMomentum::get_component(int index) const
{
    if (index < 0 || index > 3)
    {
        std::cerr << "FourMomentum: Index out of bounds. Returning 0." << std::endl;
        return 0.0;
    }
    return four_momentum[index];
}

// Setter for momentum components
void FourMomentum::set_momentum_component(int index, double value) 
{
    // Ensure index is valid (1 for px, 2 for py, 3 for pz)
    if (index < 1 || index > 3)
    {
        std::cerr << "FourMomentum: Invalid momentum component index. Must be 1 (px), 2 (py), or 3 (pz)." << std::endl;
        return;
    }

    // Ensure value is finite and real
    if (std::isnan(value) || std::isinf(value))
    {
        std::cerr << "FourMomentum: Momentum component must be a finite, real number." << std::endl;
        std::cerr << "Leaving component unchanged." << std::endl;
        return;
    }

    double rest_mass_sqrd = MathUtils::invariant_mass_squared(four_momentum[0], four_momentum[1], four_momentum[2], four_momentum[3]);
    four_momentum[index] = value;
    // Calculate the energy based on the new momentum
    four_momentum[0] = sqrt(MathUtils::momentum_squared(four_momentum[1], four_momentum[2], four_momentum[3]) + rest_mass_sqrd);
}

// Print function
void FourMomentum::print() const
{
    std::cout << "[ ";
    for (int i = 0; i < 4; ++i)
    {
        std::cout << four_momentum[i];
        if (i < 3) std::cout << ", ";
    }
    std::cout << " ] MeV/c" << std::endl;
}

// Overloaded sum operator
FourMomentum FourMomentum::operator+(const FourMomentum& other) const
{
    return FourMomentum(
        four_momentum[0] + other.four_momentum[0],
        four_momentum[1] + other.four_momentum[1],
        four_momentum[2] + other.four_momentum[2],
        four_momentum[3] + other.four_momentum[3], 
        RawTag{} // Use the private constructor
    );
}

// Overloaded subtraction operator
FourMomentum FourMomentum::operator-(const FourMomentum& other) const
{
    return FourMomentum(
        four_momentum[0] - other.four_momentum[0],
        four_momentum[1] - other.four_momentum[1],
        four_momentum[2] - other.four_momentum[2],
        four_momentum[3] - other.four_momentum[3],
        RawTag{} // Use the private constructor
    );
}

// Overloaded multiplication operator
double FourMomentum::operator*(const FourMomentum& other) const
{
    return  four_momentum[0] * other.four_momentum[0] -
            four_momentum[1] * other.four_momentum[1] -
            four_momentum[2] * other.four_momentum[2] -
            four_momentum[3] * other.four_momentum[3];
}

// Reconstruct function
FourMomentum reconstruct(double E, double px, double py, double pz)
{
    // Ensure E is finite and real
    if (std::isnan(E) || std::isinf(E) || E < 0.0)
    {
        std::cerr << "FourMomentum: Energy must be a positive, finite, real number." << std::endl;
        std::cerr << "Setting energy to zero." << std::endl;
        E = 0.0;
    }
    // Ensure px, py, pz are finite and real
    if (std::isnan(px) || std::isinf(px) || std::isnan(py) || std::isinf(py) || std::isnan(pz) || std::isinf(pz))
    {
        std::cerr << "FourMomentum: Momentum components must be finite, real numbers." << std::endl;
        std::cerr << "Setting momentum components to zero." << std::endl;
        px = py = pz = 0.0;
    }
    return FourMomentum(
        E, px, py, pz, RawTag{} // Use the private constructor
    );
}
