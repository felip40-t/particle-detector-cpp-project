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

    while (true) 
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
    return 0;
}