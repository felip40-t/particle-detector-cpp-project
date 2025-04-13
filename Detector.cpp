#include "Detector.h"

// Add a sub-detector to the detector
void Detector::add_subdetector(std::unique_ptr<SubDetector> subdetector) 
{
    subdetectors.push_back(std::move(subdetector));
}

// Print function for the detector
void Detector::print() const 
{
    std::cout << "Detector contains the following sub-detectors:" << std::endl;
    for (const auto& subdetector : subdetectors) 
    {
        subdetector->print();
    }
}

// Detect function for the detector
void Detector::detect(const Particle& particle) const 
{
    for (const auto& subdetector : subdetectors) 
    {
        subdetector->detect(particle);
    }
}