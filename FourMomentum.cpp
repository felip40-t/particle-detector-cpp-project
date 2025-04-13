#include "FourMomentum.h"


// Default constructor: give random momentum and make photon-like
FourMomentum::FourMomentum(double rest_mass)
{
    // Set maximum energy scale to randomise to
    const double ENERGY_SCALE {1000.0}; // MeV
    // Set up random number generator
    std::random_device rand_dev;
    std::mt19937 generator(rand_dev());
    std::uniform_real_distribution<double> distribution(-ENERGY_SCALE, ENERGY_SCALE);

    double momentum_sqrd{};

    // Set momenta
    for (int i {0}; i < 3 ; i++)
    {
        four_momentum[i+1] = distribution(generator);
        momentum_sqrd += four_momentum[i+1] * four_momentum[i+1];
    }
    // Set energy
    four_momentum[0] = sqrt(momentum_sqrd + rest_mass * rest_mass);
}

// Destructor
FourMomentum::~FourMomentum(){}

// Parameterized constructor
FourMomentum::FourMomentum(double rest_mass, double px, double py, double pz)
{
    // Calculate square of the momentum
    double momentum_sqrd = px * px + py * py + pz * pz;
    // Ensure rest mass is non-negative, real and finite
    if (std::isnan(rest_mass) || std::isinf(rest_mass))
    {
        try 
        {
            throw std::invalid_argument("FourMomentum: Rest mass must be a finite, real number.");
        } 
        catch (const std::invalid_argument& e) 
        {
            std::cout << e.what() << std::endl;
            std::cout << "Setting rest mass to zero." << std::endl;
            rest_mass = 0.0;
        }
    }
    else if (rest_mass < 0)
    {
        try 
        {
            throw std::invalid_argument("FourMomentum: Rest mass must be non-negative.");
        } 
        catch (const std::invalid_argument& e) 
        {
            std::cout << e.what() << std::endl;
            std::cout << "Setting rest mass to zero." << std::endl;
            rest_mass = 0.0;
        }
    }
    else if (std::isnan(px) || std::isinf(px) || std::isnan(py) || std::isinf(py) || std::isnan(pz) || std::isinf(pz))
    {
        try 
        {
            throw std::invalid_argument("FourMomentum: Momentum components must be finite, real numbers.");
        } 
        catch (const std::invalid_argument& e) 
        {
            std::cout << e.what() << std::endl;
            std::cout << "Setting momentum components to zero." << std::endl;
            px = py = pz = 0.0;
        }
    }
    
    four_momentum[0] = sqrt(momentum_sqrd + rest_mass * rest_mass);
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
        try 
        {
            throw std::out_of_range("FourMomentum: Index out of range. Must be between 0 and 3.");
        } 
        catch (const std::out_of_range& e) 
        {
            std::cout << e.what() << std::endl;
            return 0.0; // Return zero for out-of-range index
        }
    }
    return four_momentum[index];
}

// Setters for momentum components
void FourMomentum::set_px(double px) 
{
    double rest_mass_sqrd = four_momentum[0] * four_momentum[0] - four_momentum[1] * four_momentum[1] - four_momentum[2] * four_momentum[2] - four_momentum[3] * four_momentum[3];
    // Ensure px is finite and real
    if (std::isnan(px) || std::isinf(px))
    {
        try 
        {
            throw std::invalid_argument("FourMomentum: px must be a finite, real number.");
        } 
        catch (const std::invalid_argument& e) 
        {
            std::cout << e.what() << std::endl;
            std::cout << "Setting px to zero." << std::endl;
            four_momentum[1] = 0.0;
            return;
        }
    }
    four_momentum[1] = px;
    // Calculate the energy based on the new momentum
    double momentum_sqrd = four_momentum[1] * four_momentum[1] + four_momentum[2] * four_momentum[2] + four_momentum[3] * four_momentum[3]; 
    four_momentum[0] = sqrt(momentum_sqrd + rest_mass_sqrd);
}

void FourMomentum::set_py(double py) 
{
    double rest_mass_sqrd = four_momentum[0] * four_momentum[0] - four_momentum[1] * four_momentum[1] - four_momentum[2] * four_momentum[2] - four_momentum[3] * four_momentum[3];
    // Ensure py is finite and real
    if (std::isnan(py) || std::isinf(py))
    {
        try 
        {
            throw std::invalid_argument("FourMomentum: py must be a finite, real number.");
        } 
        catch (const std::invalid_argument& e) 
        {
            std::cout << e.what() << std::endl;
            std::cout << "Setting py to zero." << std::endl;
            four_momentum[2] = 0.0;
            return;
        }
    }
    four_momentum[2] = py;
    // Calculate the energy based on the new momentum
    double momentum_sqrd = four_momentum[1] * four_momentum[1] + four_momentum[2] * four_momentum[2] + four_momentum[3] * four_momentum[3]; 
    four_momentum[0] = sqrt(momentum_sqrd + rest_mass_sqrd);
}

void FourMomentum::set_pz(double pz) 
{
    double rest_mass_sqrd = four_momentum[0] * four_momentum[0] - four_momentum[1] * four_momentum[1] - four_momentum[2] * four_momentum[2] - four_momentum[3] * four_momentum[3];
    // Ensure pz is finite and real
    if (std::isnan(pz) || std::isinf(pz))
    {
        try 
        {
            throw std::invalid_argument("FourMomentum: pz must be a finite, real number.");
        } 
        catch (const std::invalid_argument& e) 
        {
            std::cout << e.what() << std::endl;
            std::cout << "Setting pz to zero." << std::endl;
            four_momentum[3] = 0.0;
            return;
        }
    }
    four_momentum[3] = pz;
    // Calculate the energy based on the new momentum
    double momentum_sqrd = four_momentum[1] * four_momentum[1] + four_momentum[2] * four_momentum[2] + four_momentum[3] * four_momentum[3]; 
    four_momentum[0] = sqrt(momentum_sqrd + rest_mass_sqrd);
}



// Overloaded sum operator
FourMomentum FourMomentum::operator+(const FourMomentum& other) const
{
    return FourMomentum(
        four_momentum[0] + other.four_momentum[0],
        four_momentum[1] + other.four_momentum[1],
        four_momentum[2] + other.four_momentum[2],
        four_momentum[3] + other.four_momentum[3]
    );
}

// Overloaded subtraction operator
FourMomentum FourMomentum::operator-(const FourMomentum& other) const
{
    return FourMomentum(
        four_momentum[0] - other.four_momentum[0],
        four_momentum[1] - other.four_momentum[1],
        four_momentum[2] - other.four_momentum[2],
        four_momentum[3] - other.four_momentum[3]
    );
}

// Dot product function
double dot_product(const FourMomentum& four_momentum1, const FourMomentum& four_momentum2)
{
    return four_momentum1.four_momentum[0] * four_momentum2.four_momentum[0] -
           four_momentum1.four_momentum[1] * four_momentum2.four_momentum[1] -
           four_momentum1.four_momentum[2] * four_momentum2.four_momentum[2] -
           four_momentum1.four_momentum[3] * four_momentum2.four_momentum[3];
}