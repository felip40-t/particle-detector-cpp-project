#include "Detector.h"
#include "Utilities.h"


// Add a sub-detector to the detector
void Detector::add_subdetector(std::unique_ptr<SubDetector> subdetector) 
{
    subdetectors.push_back(std::move(subdetector));
}

// Get user to add subdetector
void Detector::add_subdetector()
{
    std::string name;
    std::cout << "==================================\n";
    std::cout << "Add a sub-detector\n";
    std::cout << "==================================\n";
    std::cout << "Choose sub-detector type:\n";
    std::cout << "1. Tracker\n";
    std::cout << "2. Muon Chamber\n";
    std::cout << "3. Hadron Calorimeter\n";
    std::cout << "4. EM Calorimeter\n";
    int choice;
    // Check choice
    while (true)
    {
        std::cout << "Enter choice: ";
        std::string input;
        std::cin >> input;
        if (check_string_to_int(input))
        {
            choice = std::stoi(input);
            if (choice >= 1 && choice <= 4)
                break;
            else
                std::cout << "Invalid choice. Please enter a number between 1 and 4.\n";
        }
        else
        {
            std::cout << "Invalid input. Please enter a number.\n";
        }
    }
    
    // Check efficiency
    double efficiency;
    efficiency = check_efficiency();
    // Check resolution
    double resolution;
    resolution = check_resolution();
    // Check uncertainty
    double uncertainty;
    uncertainty = check_uncertainty();
    // Add sub-detector based on choice
    if (choice == 1)
    {
        // Add more materials
        add_subdetector(std::make_unique<Tracker>(efficiency, resolution, uncertainty, check_layers(), "Silicon"));
    }
    else if (choice == 2)
    {
        add_subdetector(std::make_unique<MuonChamber>(efficiency, resolution, uncertainty));
    }
    else if (choice == 3)
    {
        add_subdetector(std::make_unique<HadronCalorimeter>(efficiency, resolution, uncertainty));
    }
    else if (choice == 4)
    {
        add_subdetector(std::make_unique<EMCalorimeter>(efficiency, resolution, uncertainty));
    }
}

// Remove a sub-detector from the detector at index i
void Detector::remove_subdetector(size_t i) 
{
    if (i < subdetectors.size()) 
    {
        subdetectors.erase(subdetectors.begin() + i);
    } 
    else 
    {
        std::cerr << "Invalid index for sub-detector removal." << std::endl;
    }
}

// Get user to remove subdetector
void Detector::remove_subdetector() 
{
    if (subdetectors.empty()) {
        std::cout << "No sub-detectors to remove.\n";
        return;
    }

    std::cout << "==================================\n";
    std::cout << "Remove a sub-detector\n";
    std::cout << "==================================\n";
    std::cout << "Enter index of sub-detector to remove: ";
    std::string index_input;
    std::cin >> index_input;

    if (check_string_to_int(index_input)) 
    {
        size_t index = std::stoi(index_input);
        remove_subdetector(index);
    } 
    else 
    {
        std::cout << "Invalid input. Please enter a number.\n";
    }
}

// Clear all sub-detectors
void Detector::clear_subdetectors() 
{
    if (subdetectors.empty()) 
    {
        std::cout << "No sub-detectors to clear.\n";
        return;
    }
    subdetectors.clear();
    std::cout << "All sub-detectors cleared.\n";
}


// Print function for the detector
void Detector::print() const 
{
    if (subdetectors.empty()) 
    {
        std::cout << "No sub-detectors in the detector." << std::endl;
        return;
    }
    std::cout << "Detector contains the following sub-detectors:" << std::endl;
    for (const auto& subdetector : subdetectors) 
    {
        std::cout << "-------------------------------------------\n";
        subdetector->print();
        std::cout << "-------------------------------------------\n";
    }
}

// Detect function for the detector
void Detector::detect(const Particle& particle) const 
{
    std::cout << "--------------------------------------------\n";
    std::cout << "Detecting...\n";
    std::cout << "--------------------------------------------\n";
    // Create a measurement object for the particle's measurements
    SubDetectorInfo::Measurement measurement; 
    for (const auto& subdetector : subdetectors) 
    {
        // Detect the particle in each sub-detector
        subdetector->detect(particle, measurement);
    }

    // Reconstruct 4-momentum and identify particle
    // If both EM calorimeter and tracker detect a particle, then it is an electron or positron
    if (measurement.em_calorimeter && measurement.track)
    {
        // Reconstruct 4-momentum using energy and momentum 
        FourMomentum four_momentum = reconstruct(measurement.energy, measurement.momentum[0], measurement.momentum[1], measurement.momentum[2]);
        // Check charge to see if it is an electron or positron
        if (measurement.charge < 0)
        {
            std::cout << "Electron detected with invariant mass: " << sqrt(four_momentum * four_momentum) << " MeV/c^2\n";
        }
        else
        {
            std::cout << "Positron detected with invariant mass: " << sqrt(four_momentum * four_momentum) << " MeV/c^2\n";
        }
        std::cout << "Four momentum measured:\n";
        four_momentum.print();
        std::cout << "True four momentum:\n";
        particle.get_four_momentum().print();
    }
    // If both hadron calorimeter and tracker detect a particle, then it is a charged hadron
    else if (measurement.hadron_calorimeter && measurement.track)
    {
        FourMomentum four_momentum = reconstruct(measurement.energy, measurement.momentum[0], measurement.momentum[1], measurement.momentum[2]);
        // Check charge to see if it is a positive or negative hadron
        if (measurement.charge > 0)
        {
            std::cout << "Positive electric charge Hadron detected with invariant mass: " << sqrt(four_momentum * four_momentum) << " MeV/c^2\n";
        }
        else if (measurement.charge < 0)
        {
            std::cout << "Negative electric charge Hadron detected with invariant mass: " << sqrt(four_momentum * four_momentum) << " MeV/c^2\n";
        }
        std::cout << "Four momentum measured:\n";
        four_momentum.print();
        std::cout << "True four momentum:\n";
        particle.get_four_momentum().print();
    }
    // If only EM calorimeter detects a particle, then it is a photon
    else if (measurement.em_calorimeter && !measurement.track)
    {
        std::cout << "Photon detected with energy: " << measurement.energy << " MeV\n";
        std::cout << "True four momentum:\n";
        particle.get_four_momentum().print();
    }
    // If only hadron calorimeter detects a particle, then it is a neutral hadron
    else if (measurement.hadron_calorimeter && !measurement.track)
    {
        std::cout << "Neutral hadron detected with energy: " << measurement.energy << " MeV\n";
        std::cout << "True four momentum:\n";
        particle.get_four_momentum().print();
    }
    // If only muon chamber detects a particle, then it is a muon or antimuon
    else if (measurement.muon_chamber)
    {
        // Reconstruct 4-momentum using mass and momentum,
        // since muon mass is known
        FourMomentum four_momentum(105.7, measurement.momentum[0], measurement.momentum[1], measurement.momentum[2]);
        // Check charge to see if it is a muon or antimuon
        if (measurement.charge < 0)
        {
            std::cout << "Muon detected with energy: " << four_momentum.get_component(0) << "\n";
        }
        else
        {
            std::cout << "Antimuon detected with energy: " << four_momentum.get_component(0) << "\n";
        }
        std::cout << "Four momentum measured:\n";
        four_momentum.print();
        std::cout << "True four momentum:\n";
        particle.get_four_momentum().print();
    }
    else
    {
        std::cout << "Not enough information to reconstruct 4-momentum." << std::endl;
    }
}