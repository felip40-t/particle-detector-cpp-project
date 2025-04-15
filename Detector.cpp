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
        std::cout << "-------------------------------------------\n";
    }
}

// Detect function for the detector
void Detector::detect(const Particle& particle) const 
{
    SubDetectorInfo::Measurement measurement; // Create a measurement object
    for (const auto& subdetector : subdetectors) 
    {
        // Detect the particle in each sub-detector
        subdetector->detect(particle);
        // If detected, update the measurement
        if (subdetector->get_measurement().track) 
        {
            measurement.track = true;
            measurement.momentum = subdetector->get_measurement().momentum;
            measurement.charge = subdetector->get_measurement().charge;
        }
        if (subdetector->get_measurement().em_calorimeter) 
        {
            measurement.em_calorimeter = true;
            measurement.energy = subdetector->get_measurement().energy;
        }
        if (subdetector->get_measurement().hadron_calorimeter) 
        {
            measurement.hadron_calorimeter = true;
            measurement.energy = subdetector->get_measurement().energy;
        }
        if (subdetector->get_measurement().muon_chamber) 
        {
            measurement.muon_chamber = true;
            measurement.momentum = subdetector->get_measurement().momentum;
            measurement.charge = subdetector->get_measurement().charge;
        }
    }
    
    // Reconstruct 4-momentum and identify particle
    if (measurement.em_calorimeter && measurement.track)
    {
        FourMomentum four_momentum = reconstruct(measurement.energy, measurement.momentum[0], measurement.momentum[1], measurement.momentum[2]);
        if (measurement.charge < 0)
        {
            std::cout << "Electron detected with invariant mass: " << sqrt(four_momentum * four_momentum) << " MeV/c^2\n";
        }
        else
        {
            std::cout << "Positron detected with invariant mass: " << sqrt(four_momentum * four_momentum) << " MeV/c^2\n";
        }
    }
    else if (measurement.hadron_calorimeter && measurement.track)
    {
        FourMomentum four_momentum = reconstruct(measurement.energy, measurement.momentum[0], measurement.momentum[1], measurement.momentum[2]);
        if (measurement.charge > 0)
        {
            std::cout << "Positive charge Hadron detected with invariant mass: " << sqrt(four_momentum * four_momentum) << " MeV/c^2\n";
        }
        else if (measurement.charge < 0)
        {
            std::cout << "Negative charge Hadron detected with invariant mass: " << sqrt(four_momentum * four_momentum) << " MeV/c^2\n";
        }
    }
    else if (measurement.em_calorimeter && !measurement.track)
    {
        std::cout << "Photon detected with energy: " << measurement.energy << " MeV\n";
    }
    else if (measurement.hadron_calorimeter && !measurement.track)
    {
        std::cout << "Neutral hadron detected with energy: " << measurement.energy << " MeV\n";
    }
    else if (measurement.muon_chamber)
    {
        
    }
    else
    {
        std::cout << "Not enough information to reconstruct 4-momentum." << std::endl;
    }
}