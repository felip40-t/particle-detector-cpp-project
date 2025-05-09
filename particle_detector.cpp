// Particle Detector Simulation
#include <iostream>
#include <iomanip>

#include "Detector.h"
#include "ParticleList.h"

#include "Electron.h"
#include "Muon.h"
#include "Photon.h"
#include "Hadron.h"
#include "Utilities.h"

int main() {

    // Create a Detector object
    Detector CMS_detector;

    // Create a ParticleList object
    ParticleList particles;

    // Create a Boolean variable to switch on and off the manual testing
    // Set to true to run the manual testing
    bool manual_testing = false;

    while (!manual_testing)
    {
        // Display menu options
        show_menu();
        std::string choice{};
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        if (!check_string_to_int(choice)) 
        {
            if (choice == "?")
            {
                help_menu();
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
            
            // Default case for invalid input
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    }

    // ==========================================================
    // MANUAL TESTING
    // ==========================================================
    
    std::cout << "\n=== Setting up CMS-like detector ===\n";
    Detector detector;
    detector.add_subdetector(std::make_unique<Tracker>());
    detector.add_subdetector(std::make_unique<EMCalorimeter>());
    detector.add_subdetector(std::make_unique<HadronCalorimeter>());
    detector.add_subdetector(std::make_unique<MuonChamber>());
    detector.print();

    std::cout << "\n=== Creating particle list ===\n";
    ParticleList particle_list;

    // Demonstrate particle-antiparticle pairs
    std::cout << "\n--- Electron-Positron Pair ---\n";
    Electron electron(0.0, 0.0, 10000.0);
    Positron positron(0.0, 0.0, -10000.0);
    std::cout << "Electron properties:\n";
    electron.print_data();
    std::cout << "\nPositron properties:\n";
    positron.print_data();
    particle_list.add_custom_particle(std::make_unique<Electron>(electron));
    particle_list.add_custom_particle(std::make_unique<Positron>(positron));

    // Demonstrate muon-antimuon pair with different momenta
    std::cout << "\n--- Muon-Antimuon Pair ---\n";
    Muon muon(2341.0, 42.0, -123434.0);
    Antimuon antimuon(-2341.0, -42.0, 123434.0);
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
    std::cout << "\n=== Four-Momentum Operations ===\n";
    FourMomentum p1 = electron.get_four_momentum();
    FourMomentum p2 = positron.get_four_momentum();
    std::cout << "Electron four-momentum:\n";
    p1.print();
    std::cout << "Invariant mass of electron: " << sqrt(p1 * p1) << " MeV/c^2\n";
    std::cout << "Positron four-momentum:\n";
    p2.print();
    std::cout << "Invariant mass of positron: " << sqrt(p2 * p2) << " MeV/c^2\n";
    std::cout << "Sum of four-momenta:\n";
    (p1 + p2).print();
    // Set the x and y momentum of the positron to another value to show that the z component 
    // and energy are conserved -- the mass of the positron doesn't change
    p2.set_px(1238.0);
    p2.set_py(964.0);
    std::cout << "Positron four-momentum after changing x and y components:\n";
    p2.print();
    std::cout << "Invariant mass of positron: " << sqrt(p2 * p2) << " MeV/c^2\n";

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