// Particle Detector Simulation
#include <iostream>
#include <iomanip>

#include "Detector.h"
#include "ParticleList.h"
#include "Utilities.h"

int main() {

    Detector CMS_detector;
    ParticleList particles;
    bool manual_testing = false;

    while (!manual_testing)
    {
        // Display menu options
        DetectorUtils::show_menu();
        std::string choice{};
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        if (!MathUtils::check_string_to_int(choice)) 
        {
            if (choice == "?")
            {
                DetectorUtils::help_menu();
                continue;
            }
            std::cout << "Invalid input. Please enter a number.\n";
            continue;
        }
        // Get user choice
        int option = std::stoi(choice);
        switch (option) 
        {
            case 0:
            {
                // Exit the program
                std::cout << "Exiting the program.\n";
                return 0;
            }
            case 1:
            {
                // Add a sub-detector
                CMS_detector.add_subdetector();
                break;
            }
            case 2:
            {
                // Remove a sub-detector
                CMS_detector.remove_subdetector();
                break;
            }
            case 3:
            {
                // Clear all sub-detectors
                CMS_detector.clear_subdetectors();
                break;
            }
            case 4:
            {
                // Print detector information
                CMS_detector.print();
                break;
            }
            case 5:
            {
                // Add a particle
                particles.add_particle();
                break;
            }
            case 6:
            {
                // Remove a particle
                particles.remove_particle();
                break;
            }
            case 7:
            {
                // Clear all particles
                particles.clear_particles();
                break;
            }
            case 8:
            {
                // Print particles' information
                particles.print_particles();
                break;
            }
            case 9:
            {
                // Detect particles
                if (CMS_detector.get_subdetectors().empty()) 
                {
                    std::cout << "No sub-detectors available for detection.\n";
                    break;
                }
                if (particles.get_particles().empty()) 
                {
                    std::cout << "No particles available for detection.\n";
                    break;
                }
                std::cout << "==================================\n";
                std::cout << "Detect particles\n";
                std::cout << "==================================\n";
                for (const auto& particle : particles.get_particles()) 
                {
                    CMS_detector.detect(*particle);
                }
                std::cout << "Detection complete.\n";
                break;
            }
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    }

    // ==========================================================
    // MANUAL TESTING
    // ==========================================================
    
    std::cout << "\n=== Setting up CMS-like detector ===\n";
    Detector detector;
    // Input parameters: efficiency, resolution, uncertainty, (layers), (material) for tracker and muon chamber
    detector.add_subdetector(std::make_unique<Tracker>(1, 0.01, 0.05, 10, "TPCs"));
    detector.add_subdetector(std::make_unique<EMCalorimeter>(1, 0.01, 0.05));
    detector.add_subdetector(std::make_unique<HadronCalorimeter>(1, 0.01, 0.05));
    detector.add_subdetector(std::make_unique<MuonChamber>(1, 0.01, 0.05, 256, "GEMs"));
    detector.print();

    std::cout << "\n=== Creating particle list ===\n";
    ParticleList particle_list;

    // Demonstrate particle-antiparticle pairs
    Electron electron(0.0, 0.0, 100.0);
    Positron positron(0.0, 0.0, -100.0);
    std::cout << "Electron properties:\n";
    electron.print_data();
    std::cout << "\nPositron properties:\n";
    positron.print_data();
    particle_list.add_custom_particle(std::make_unique<Electron>(electron));
    particle_list.add_custom_particle(std::make_unique<Positron>(positron));

    // Demonstrate muon-antimuon pair with different momenta
    Muon muon(2341.0, 42.0, -12343.0);
    Antimuon antimuon(-2341.0, -42.0, 12343.0);
    std::cout << "Muon properties:\n";
    muon.print_data();
    std::cout << "\nAntimuon properties:\n";
    antimuon.print_data();
    particle_list.add_custom_particle(std::make_unique<Muon>(muon));
    particle_list.add_custom_particle(std::make_unique<Antimuon>(antimuon));

    // Demonstrate hadrons with different charges
    std::cout << "\n--- Hadrons ---\n";
    Proton proton(230.0, 0.0, -230.0);
    KaonMinus kaon_minus;
    PionPlus pion_plus;
    std::cout << "Proton properties:\n";
    proton.print_data();
    std::cout << "\nKaon- properties:\n";
    kaon_minus.print_data();
    std::cout << "\nPion+ properties:\n";
    pion_plus.print_data();
    particle_list.add_custom_particle(std::make_unique<Proton>(proton));
    particle_list.add_custom_particle(std::make_unique<KaonMinus>(kaon_minus));
    particle_list.add_custom_particle(std::make_unique<PionPlus>(pion_plus));

    // Demonstrate neutral particles
    std::cout << "\n--- Neutral Particles ---\n";
    Photon photon;
    Neutron neutron;
    Neutrino neutrino;
    std::cout << "Photon properties:\n";
    photon.print_data();
    std::cout << "\nNeutron properties:\n";
    neutron.print_data();
    std::cout << "\nNeutrino properties:\n";
    neutrino.print_data();
    particle_list.add_custom_particle(std::make_unique<Photon>(photon));
    particle_list.add_custom_particle(std::make_unique<Neutron>(neutron));
    particle_list.add_custom_particle(std::make_unique<Neutrino>(neutrino));

    // Demonstrate four-momentum operations
    std::cout << "\n=== Four-Momentum Operations Example ===\n";
    std::cout << "Positron four-momentum:\n";
    positron.get_four_momentum().print();
    std::cout << "Invariant mass of positron: " << sqrt(positron.get_four_momentum() * positron.get_four_momentum()) << " MeV/c^2\n";
    // Set the x and y momentum
    positron.set_four_momentum(1, 238.0);
    positron.set_four_momentum(2, 964.0);
    std::cout << "Positron four-momentum after changing x and y components:\n";
    positron.get_four_momentum().print();
    std::cout << "Invariant mass of positron: " << sqrt(positron.get_four_momentum() * positron.get_four_momentum()) << " MeV/c^2\n";

    // Detect all particles
    std::cout << "\n=== Particle Detection ===\n";
    for (const auto& particle : particle_list.get_particles()) 
    {
        std::cout << "\nDetecting particle:\n";
        particle->print_data();
        detector.detect(*particle);
    }
    
    return 0;
}