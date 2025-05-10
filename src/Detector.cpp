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
    DetectorUtils::subdetector_menu();
    // Check choice
    int choice;
    while (true)
    {
        std::cout << "Enter choice: ";
        std::string input;
        std::cin >> input;
        if (MathUtils::check_string_to_int(input))
        {
            choice = std::stoi(input);
            if (choice >= 1 && choice <= 4)
                break;
            else
                std::cout << "Invalid choice. Please enter a number between 1 and 4.\n";
        }
        else
            std::cout << "Invalid input. Please enter a number.\n";
    }
    
    // Check if sub-detector already exists
    // and replace it with the new one
    SubDetectorInfo::SubDetectorType new_type;
    switch (choice)
    {
        case 1: new_type = SubDetectorInfo::SubDetectorType::Tracker; break;
        case 2: new_type = SubDetectorInfo::SubDetectorType::MuonChamber; break;
        case 3: new_type = SubDetectorInfo::SubDetectorType::HadronCalorimeter; break;
        case 4: new_type = SubDetectorInfo::SubDetectorType::EMCalorimeter; break;
    }

    for (size_t i = 0; i < subdetectors.size(); ++i)
    {
        if (subdetectors[i]->get_type() == new_type)
        {
            std::cout << "Chosen sub-detector already exists. Replacing it...\n";
            remove_subdetector(i);
        }
    }

    // Check efficiency
    double efficiency;
    efficiency = DetectorUtils::check_efficiency();
    // Check resolution
    double resolution;
    resolution = DetectorUtils::check_resolution();
    // Check uncertainty
    double uncertainty;
    uncertainty = DetectorUtils::check_uncertainty();
    // Add sub-detector based on choice
    if (choice == 1)
        add_subdetector(std::make_unique<Tracker>(efficiency, resolution, uncertainty, DetectorUtils::check_layers(), DetectorUtils::check_tracker_material()));
    else if (choice == 2)
    {
        std::string technology = DetectorUtils::check_muon_chamber_technology();
        add_subdetector(std::make_unique<MuonChamber>(efficiency, resolution, uncertainty, DetectorUtils::check_number_of_technology(technology), technology));
    }
    else if (choice == 3)
        add_subdetector(std::make_unique<HadronCalorimeter>(efficiency, resolution, uncertainty));
    else if (choice == 4)
        add_subdetector(std::make_unique<EMCalorimeter>(efficiency, resolution, uncertainty));
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

    if (MathUtils::check_string_to_int(index_input)) 
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
    std::cout << "===========================================\n";
    std::cout << "Sub-detectors in the detector:\n";
    std::cout << "===========================================\n";
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

    // If both EM calorimeter and tracker detect a particle, then it is an electron or positron
    if (measurement.em_calorimeter && measurement.track)
        DetectorHelpers::report_electron(measurement);
    // If both hadron calorimeter and tracker detect a particle, then it is a charged hadron
    else if (measurement.track && measurement.hadron_calorimeter)
        DetectorHelpers::report_charged_hadron(measurement);
    // If both only hadron calorimeter detects a particle, then it is a neutral hadron
    else if (measurement.hadron_calorimeter)
        DetectorHelpers::report_neutral_hadron(measurement);
    // If only muon chamber detects a particle, then it is a muon or antimuon
    else if (measurement.muon_chamber)
        DetectorHelpers::report_muon(measurement);
    // If only EM calorimeter detects a particle, then it is a photon
    else if (measurement.em_calorimeter)
        DetectorHelpers::report_photon(measurement);
    // If only detected in tracker
    else if (measurement.track)
        DetectorHelpers::report_unknown(measurement);
    // Check if nothing was detected - neutrino
    else if (!measurement.track && !measurement.em_calorimeter && !measurement.hadron_calorimeter && !measurement.muon_chamber)
    {
        // Only report neutrino if all types of subdetectors exist
        if (DetectorHelpers::has_all_subdetector_types(subdetectors))
        {
            DetectorHelpers::report_neutrino();
        }
        else
        {
            std::cout << "No sub-detectors detected the particle, but not all types of sub-detectors are present.\n";
            std::cout << "Cannot confirm this particle.\n";
        }
    }
    
    // Print true particle properties once at the end
    std::cout << "\nTrue particle properties:\n";
    particle.print_data();
}


namespace DetectorHelpers
{
    // Classify particle based on mass and using ParticleInfo map
    // Only used for charged hadrons, other particles can be inferred by track
    // check if within 10% of mass
    int classify_particle_via_mass(double mass)
    {
        // Lambda function to check if mass is within 10% of target mass
        auto is_within_10_percent = [](double mass, double target_mass) {
            return (mass > target_mass * 0.9 && mass < target_mass * 1.1);
        };

        // List of particle types to check against
        std::vector<ParticleInfo::ParticleType> candidates = {
            ParticleInfo::ParticleType::PROTON,
            ParticleInfo::ParticleType::PION_PLUS,
            ParticleInfo::ParticleType::KAON_PLUS,
        };

        // Loop through all candidate particles
        for (const auto& type : candidates)
        {
            double target_mass = ParticleInfo::get_particle_properties(type).get_mass();
            if (is_within_10_percent(mass, target_mass))
            {
                if (type == ParticleInfo::ParticleType::PROTON)
                {
                    return 1; // Proton
                }
                else if (type == ParticleInfo::ParticleType::PION_PLUS)
                {
                    return 2; // Pion+
                }
                else if (type == ParticleInfo::ParticleType::KAON_PLUS)
                {
                    return 3; // Kaon+
                }
            }
        }

        // If no match is found, return 0
        return 0;
    }

    // Helpers to report the detection of each particle
    void report_electron(const SubDetectorInfo::Measurement& measurement)
    {
        // Reconstruct 4-momentum using energy and momentum 
        FourMomentum four_momentum = reconstruct(measurement.energy, measurement.momentum[0], measurement.momentum[1], measurement.momentum[2]);
        // Check mass
        double inv_mass_sqr = four_momentum * four_momentum;
        if (inv_mass_sqr < 0)
        {
            std::cout << "Reconstructed four-momentum yields unphysical invariant mass.\n";
            std::cout << "Try changing the resolution and uncertainty of the sub-detectors.\n";
            return;
        }
        // Check charge to see if it is an electron or positron
        if (measurement.charge < 0)
        {
            std::cout << "Electron detected with invariant mass: " << sqrt(inv_mass_sqr) << " MeV/c^2\n";
        }
        else
        {
            std::cout << "Positron detected with invariant mass: " << sqrt(inv_mass_sqr) << " MeV/c^2\n";
        }
        std::cout << "Four momentum measured:\n";
        four_momentum.print();
    }

    void report_charged_hadron(const SubDetectorInfo::Measurement& measurement)
    {
        FourMomentum four_momentum = reconstruct(measurement.energy, measurement.momentum[0], measurement.momentum[1], measurement.momentum[2]);
        double inv_mass_sqr = four_momentum * four_momentum;
        if (inv_mass_sqr < 0)
        {
            std::cout << "Reconstructed four-momentum yields unphysical invariant mass.\n";
            std::cout << "Try changing the resolution and uncertainty of the sub-detectors.\n";
            return;
        }
        double invariant_mass = sqrt(inv_mass_sqr);
        // Classify the particle using invariant mass
        int particle_type = DetectorHelpers::classify_particle_via_mass(invariant_mass);
        // Check charge to see if it is a positive or negative hadron
        if (measurement.charge > 0)
        {
            // Check mass to classify
            if (particle_type == 1)
            {
                std::cout << "Proton detected with invariant mass: " << invariant_mass << " MeV/c^2\n";
            }
            else if (particle_type == 2)
            {
                std::cout << "Pion+ detected with invariant mass: " << invariant_mass << " MeV/c^2\n";
            }
            else if (particle_type == 3)
            {
                std::cout << "Kaon+ detected with invariant mass: " << invariant_mass << " MeV/c^2\n";
            }
            else
            {
                std::cout << "Positively charged hadron detected with invariant mass: " << invariant_mass << " MeV/c^2\n";
            }
        }
        else if (measurement.charge < 0)
        {
            if (particle_type == 1)
            {
                std::cout << "Antiproton detected with invariant mass: " << invariant_mass << " MeV/c^2\n";
            }
            else if (particle_type == 2)
            {
                std::cout << "Pion- detected with invariant mass: " << invariant_mass << " MeV/c^2\n";
            }
            else if (particle_type == 3)
            {
                std::cout << "Kaon- detected with invariant mass: " << invariant_mass << " MeV/c^2\n";
            }
            else
            {
                std::cout << "Negatively charged hadron detected with invariant mass: " << invariant_mass << " MeV/c^2\n";
            }
        }
        std::cout << "Four momentum measured:\n";
        four_momentum.print();
    }

    void report_neutral_hadron(const SubDetectorInfo::Measurement& measurement)
    {
        std::cout << "Neutral hadron detected with energy: " << measurement.energy << " MeV\n";
    }

    void report_muon(const SubDetectorInfo::Measurement& measurement)
    {
        // Reconstruct 4-momentum using mass and momentum,
        // since muon mass is known
        FourMomentum four_momentum(105.7, measurement.momentum[0], measurement.momentum[1], measurement.momentum[2]);
        // Check charge to see if it is a muon or antimuon
        if (measurement.charge < 0)
        {
            std::cout << "Muon detected with energy: " << four_momentum.get_component(0) << " MeV\n";
        }
        else
        {
            std::cout << "Antimuon detected with energy: " << four_momentum.get_component(0) << " MeV\n";
        }
        std::cout << "Four momentum measured:\n";
        four_momentum.print();
    }

    void report_photon(const SubDetectorInfo::Measurement& measurement)
    {
        // Reconstruct 4-momentum using only energy
        std::cout << "Photon detected with energy: " << measurement.energy << " MeV\n";
    }

    void report_neutrino()
    {
        std::cout << "No sub-detectors detected the particle. Neutrino passed through" << std::endl;
    }

    void report_unknown(const SubDetectorInfo::Measurement& measurement)
    {
        std::cout << "Particle detected in Tracker but not classified.\n";
        std::cout << "Measured momentum:\n";
        std::cout << "(" << measurement.momentum[0] << ", " << measurement.momentum[1] << ", " << measurement.momentum[2] << ")\n";
    }

    // Helper function to check if all types of subdetectors exist
    bool has_all_subdetector_types(const std::vector<std::unique_ptr<SubDetector>>& subdetectors)
    {
        bool has_tracker = false;
        bool has_muon_chamber = false;
        bool has_hadron_calorimeter = false;
        bool has_em_calorimeter = false;

        for (const auto& subdetector : subdetectors)
        {
            switch (subdetector->get_type())
            {
                case SubDetectorInfo::SubDetectorType::Tracker:
                    has_tracker = true;
                    break;
                case SubDetectorInfo::SubDetectorType::MuonChamber:
                    has_muon_chamber = true;
                    break;
                case SubDetectorInfo::SubDetectorType::HadronCalorimeter:
                    has_hadron_calorimeter = true;
                    break;
                case SubDetectorInfo::SubDetectorType::EMCalorimeter:
                    has_em_calorimeter = true;
                    break;
            }
        }

        return has_tracker && has_muon_chamber && has_hadron_calorimeter && has_em_calorimeter;
    }

} // namespace DetectorHelpers

