#include "Subdetector.h"


// Default constructor - used for derived classes
// Doesn't initialise the type or name since the derived class will do that
SubDetector::SubDetector()
    : efficiency(1.0),
      resolution(1e-10),
      uncertainty(0.0) {}

// Parameterized constructor - used for derived classes
SubDetector::SubDetector(double efficiency, double resolution, double uncertainty)
{
    // Set efficiency, resolution, and uncertainty
    set_efficiency(efficiency);
    set_resolution(resolution);
    set_uncertainty(uncertainty);
}

// Copy constructor
SubDetector::SubDetector(const SubDetector& other)
    : type(other.type),
      name(other.name),
      efficiency(other.efficiency),
      resolution(other.resolution),
      uncertainty(other.uncertainty) {}

// Move constructor
SubDetector::SubDetector(SubDetector&& other)
    : type(other.type),
      name(std::move(other.name)),
      efficiency(other.efficiency),
      resolution(other.resolution),
      uncertainty(other.uncertainty) {}

// Copy assignment operator
SubDetector& SubDetector::operator=(const SubDetector& other)
{
    if (this != &other) {
        type = other.type;
        name = other.name;
        efficiency = other.efficiency;
        resolution = other.resolution;
        uncertainty = other.uncertainty;
    }
    return *this;
}

// Move assignment operator
SubDetector& SubDetector::operator=(SubDetector&& other)
{
    if (this != &other) {
        type = other.type;
        name = std::move(other.name);
        efficiency = other.efficiency;
        resolution = other.resolution;
        uncertainty = other.uncertainty;
    }
    return *this;
}
 
// Print function
void SubDetector::print() const
{
    std::cout << "Sub-detector: " << name << std::endl;
    std::cout << "Efficiency: " << efficiency << std::endl;
    std::cout << "Resolution: " << resolution << " MeV" << std::endl;
    std::cout << "Uncertainty: " << uncertainty << "%" << std::endl;
}

// Setters for efficiency, resolution, and uncertainty
void SubDetector::set_efficiency(double efficiency)
{
    if (MathUtils::check_value_in_range(efficiency, 0.0, 1.0)) 
    {
        this->efficiency = efficiency;
    } 
    else 
    {
        std::cerr << "SubDetector : Efficiency must be between 0 and 1.\nSetting to 1.0" << std::endl;
        this->efficiency = 1.0; // Default value
    }
}

void SubDetector::set_resolution(double resolution)
{
    if (MathUtils::check_value_in_range(resolution, 0.0, std::numeric_limits<double>::infinity())) 
    {
        this->resolution = resolution;
    } 
    else 
    {
        std::cerr << "SubDetector : Resolution must be positive.\nSetting to 10^-10" << std::endl;
        this->resolution = 1e-10; // Default value
    }
}

void SubDetector::set_uncertainty(double uncertainty)
{
    if (MathUtils::check_value_in_range(uncertainty, 0.0, std::numeric_limits<double>::infinity())) 
    {
        this->uncertainty = uncertainty;
    } 
    else 
    {
        std::cerr << "SubDetector : Uncertainty must be positive.\nSetting to 0.0" << std::endl;
        this->uncertainty = 0.0; // Default value
    }
}



