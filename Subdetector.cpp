#include "Subdetector.h"


// Default constructor
SubDetector::SubDetector()
    : type(SubDetectorInfo::SubDetectorType::Default), 
      name(SubDetectorInfo::get_subdetector_names(SubDetectorInfo::SubDetectorType::Default)),
      efficiency(1.0),
      resolution(0.0),
      uncertainty(0.0) {}

// Parameterized constructor
SubDetector::SubDetector(double efficiency, double resolution, double uncertainty)
    : type(SubDetectorInfo::SubDetectorType::Default), 
      name(SubDetectorInfo::get_subdetector_names(SubDetectorInfo::SubDetectorType::Default))
{
    if (efficiency < 0.0 || efficiency > 1.0 || std::isnan(efficiency))
    {
        try
        {
            throw std::invalid_argument("SubDetector: Efficiency must be between 0 and 1.");
        } 
        catch (const std::invalid_argument& e) 
        {
            std::cout << e.what() << std::endl;
            std::cout << "Setting efficiency to 1.0." << std::endl;
            efficiency = 1.0;
        }
    }
    this->efficiency = efficiency;
    if (resolution < 0.0 || std::isnan(resolution) || std::isinf(resolution))
    {
        try
        {
            throw std::invalid_argument("SubDetector: Resolution must be non-negative, finite and real.");
        } 
        catch (const std::invalid_argument& e) 
        {
            std::cout << e.what() << std::endl;
            std::cout << "Setting resolution to 0.0." << std::endl;
            resolution = 0.0;
        }
    }
    this->resolution = resolution;
    if (uncertainty < 0.0 || std::isnan(uncertainty) || std::isinf(uncertainty))
    {
        try
        {
            throw std::invalid_argument("SubDetector: Uncertainty must be non-negative, finite and real.");
        } 
        catch (const std::invalid_argument& e) 
        {
            std::cout << e.what() << std::endl;
            std::cout << "Setting uncertainty to 0.0." << std::endl;
            uncertainty = 0.0;
        }
    }
    this->uncertainty = uncertainty;
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
    std::cout << "Resolution: " << resolution << std::endl;
    std::cout << "Uncertainty: " << uncertainty << std::endl;
}

