#include "Subdetector.h"


// Default constructor
SubDetector::SubDetector()
    : type(SubDetectorInfo::SubDetectorType::Default), 
      name(SubDetectorInfo::get_subdetector_names(SubDetectorInfo::SubDetectorType::Default)),
      efficiency(1.0),
      resolution(0.0) {}

// Parameterized constructor
SubDetector::SubDetector(double efficiency, double resolution)
    : type(SubDetectorInfo::SubDetectorType::Default), 
      name(SubDetectorInfo::get_subdetector_names(SubDetectorInfo::SubDetectorType::Default))
{
    if (efficiency < 0.0 || efficiency > 1.0 || std::isnan(efficiency))
    {
        try
        {
            throw std::invalid_argument("SubDetector: Efficiency must be between 0 and 1 and real.");
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

}

// Copy constructor
SubDetector::SubDetector(const SubDetector& other)
    : type(other.type),
      name(other.name),
      efficiency(other.efficiency),
      resolution(other.resolution) {}

// Move constructor
SubDetector::SubDetector(SubDetector&& other)
    : type(other.type),
      name(std::move(other.name)),
      efficiency(other.efficiency),
      resolution(other.resolution) 
{
    other.type = SubDetectorInfo::SubDetectorType::Default;
    other.name = SubDetectorInfo::get_subdetector_names(SubDetectorInfo::SubDetectorType::Default);
    other.efficiency = 1.0;
    other.resolution = 0.0;
}

// Copy assignment operator
SubDetector& SubDetector::operator=(const SubDetector& other)
{
    if (this != &other) {
        type = other.type;
        name = other.name;
        efficiency = other.efficiency;
        resolution = other.resolution;
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

        other.type = SubDetectorInfo::SubDetectorType::Default;
        other.name = SubDetectorInfo::get_subdetector_names(SubDetectorInfo::SubDetectorType::Default);
        other.efficiency = 1.0;
        other.resolution = 0.0;
    }
    return *this;
}

namespace SubDetectorInfo
{

    // Define the static map to hold sub-detector names
    const std::string& get_subdetector_names(SubDetectorType type)
    {
        // Map to hold sub-detector names
        static std::map<SubDetectorType, string> subdetector_names = {
            {SubDetectorType::Default, "Default"},
            {SubDetectorType::Tracker, "Tracker"},
            {SubDetectorType::MuonChamber, "Muon Chamber"},
            {SubDetectorType::HadronCalorimeter, "Hadron Calorimeter"},
            {SubDetectorType::EMCalorimeter, "EM Calorimeter"},
        };
        auto it = subdetector_names.find(type);
        if (it == subdetector_names.end()) 
        {
            return subdetector_names[SubDetectorType::Default]; // Return default name if not found
        }
        else 
        {
            return subdetector_names[type];
        }
    }

} // namespace SubDetectorInfo