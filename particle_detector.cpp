// Particle Detector Simulation
#include <iostream>
#include <iomanip>

#include "Detector.h"

#include "Electron.h"
#include "Muon.h"
#include "Photon.h"
#include "Hadron.h"
#include "Utilities.h"

int main() {

    // Create a detector object
    Detector CMS_detector;

    // Create particles vector
    std::vector<std::unique_ptr<Particle>> particles;

    while (true) 
    {
        std::string choice{};
        show_menu();
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        if (check_string_to_int(choice)) 
        {
            int option = std::stoi(choice);
            if (option == 0) 
                break; 
        } 
        else 
        {
            std::cout << "Invalid input. Please enter a number.\n";
            continue;
        }

        // Get user choice
        int option = std::stoi(choice);
        switch (option) 
        {
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
                particle_menu();
                std::cout << "Please enter the number of your chosen particle: ";
                std::string particle_choice;
                std::cin >> particle_choice;
                if (check_string_to_int(particle_choice))
                    {
                        int choice = std::stoi(particle_choice);
                        for (int i = 1 ; i < 8 ; i++)
                        {
                            if (choice == i)
                                particles.push_back(choose_particle(choice));
                        }
                        if (choice == 8)
                            particles.push_back(choose_random_particle());
                    }
                break;
            }
            case 6:
            {
                // Remove a particle
                if (particles.empty()) 
                {
                    std::cout << "No particles to remove.\n";
                    break;
                }
                std::cout << "================================\n";
                std::cout << "Remove a particle\n";
                std::cout << "================================\n";
                std::cout << "Enter index of particle to remove: ";
                std::string index_input;
                std::cin >> index_input;
                if (check_string_to_int(index_input)) 
                {
                    size_t index = std::stoi(index_input);
                    if (index < particles.size()) 
                    {
                        particles.erase(particles.begin() + index);
                        std::cout << "Particle removed successfully.\n";
                    } 
                    else 
                    {
                        std::cout << "Invalid index. No particle removed.\n";
                    }
                } 
                else 
                {
                    std::cout << "Invalid input. Please enter a number.\n";
                }
                break;
            }
            case 7:
            {
                // Clear all particles
                std::cout << "Clearing all particles...\n";
                particles.clear();
                std::cout << "All particles cleared.\n";
                break;
            }
            case 8:
            {
                // Print particles' information
                if (particles.empty()) 
                {
                    std::cout << "No particles available.\n";
                    break;
                }
                std::cout << "==================================\n";
                std::cout << "Particles' information:\n";
                std::cout << "==================================\n";
                for (const auto& particle : particles) 
                {
                    std::cout << "-------------------------------------------\n";
                    particle->print_data();
                    std::cout << "-------------------------------------------\n";
                }
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
                if (particles.empty()) 
                {
                    std::cout << "No particles available for detection.\n";
                    break;
                }
                std::cout << "==================================\n";
                std::cout << "Detect particles\n";
                std::cout << "==================================\n";
                for (const auto& particle : particles) 
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

    return 0;
}