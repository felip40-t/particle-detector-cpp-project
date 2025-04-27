#include "Utilities.h"

void show_menu() 
{
    std::cout << "===================================================\n";
    std::cout << "Particle Detector Simulation Menu:\n";
    std::cout << "===================================================\n";
    std::cout << "Choose an option:\n";
    std::cout << "?. Help\n";
    std::cout << "1. Add a sub-detector\n";
    std::cout << "2. Remove a sub-detector\n";
    std::cout << "3. Clear all sub-detectors\n";
    std::cout << "4. Print detector information\n";
    std::cout << "5. Add a particle\n";
    std::cout << "6. Remove a particle\n";
    std::cout << "7. Clear all particles\n";
    std::cout << "8. Print particles' information\n";
    std::cout << "9. Detect particles\n";
    std::cout << "0. Exit\n";
}

// Help menu to explain the options
void help_menu()
{
    std::cout << "===================================================\n";
    std::cout << "Help\n";
    std::cout << "===================================================\n";
    std::cout << "This program simulates a particle detector.\n\n";
    std::cout << "You have a main detector composed of sub-detectors.\n";
    std::cout << "You can add or remove sub-detectors, and each sub-detector can detect different\nquantities and particles.\n";
    std::cout << "Each sub-detector has its own efficiency, resolution, and uncertainty.\n";
    std::cout << "You can set these parameters when adding a sub-detector.\n";
    std::cout << "Look through the README.md file for more information on the sub-detectors.\n\n";
    std::cout << "You also have a list of particles that can be detected.\n";
    std::cout << "You can add or remove particles from the list.\n";
    std::cout << "When adding a particle, you can choose a specific particle or a random one.\n\n";
    std::cout << "Then, by choosing to detect the particles, the program will simulate the detection process.\n";
    std::cout << "The program will attempt to reconstruct the four-momentum of the detected particles.\n";
    std::cout << "If the invariant mass is negative, it means the four-momentum is unphysical.\n";
    std::cout << "This usually happens when the resolution and uncertainty of the sub-detectors are too high\nfor the given particle.\n";
    
}

bool check_string_to_int(const std::string& str) 
{
    // Check if string is an integer
    for (char c : str) 
    {
        if (!isdigit(c)) 
        {
            return false;
        }
    }
    return true;
}

bool check_string_to_double(const std::string& str) 
{
    // Check if string is a valid double
    std::istringstream iss(str);
    double val;
    return !(iss >> val).fail() && iss.eof();  // Ensure a valid double and no extra characters exist
}

namespace DetectorUtils
{
    int check_layers()
    {
        while (true)
        {
            std::cout << "Enter number of layers: ";
            std::string input;
            std::cin >> input;
            if (check_string_to_int(input))
            {
                int layers = std::stoi(input);
                if (layers > 0)
                {
                    return layers;
                    break;
                }
                else
                    std::cout << "Invalid number of layers. Please enter a positive integer.\n";
            }
            else
            {
                std::cout << "Invalid input. Please enter a positive integer.\n";
            }
        }
    }

    double check_value_in_range(const std::string& prompt, double min, double max)
    {
        while (true)
        {
            std::cout << prompt;
            std::string input;
            std::cin >> input;
            if (check_string_to_double(input))
            {
                double value = std::stod(input);
                if (value >= min && value <= max)
                {
                    return value;
                }
                else
                    std::cout << "Invalid input. Please enter a value between " << min << " and " << max << ".\n";
            }
            else
            {
                std::cout << "Invalid input. Please enter a number.\n";
            }
        }
    }

    // Check efficiency between 0 and 1
    double check_efficiency()
    {
        return check_value_in_range("Enter efficiency (0-1): ", 0, 1);
    }

    // Check resolution is positive
    double check_resolution()
    {
        return check_value_in_range("Enter resolution: ", 0, std::numeric_limits<double>::infinity());
    }

    // Check uncertainty is positive
    double check_uncertainty()
    {
        return check_value_in_range("Enter uncertainty: ", 0, std::numeric_limits<double>::infinity());
    }

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

} // namespace DetectorUtils

namespace ParticleListUtils 
{
    void particle_menu()
    {
        std::cout << "=========================\n";
        std::cout << "Particle menu:\n";
        std::cout << "=========================\n";
        std::cout << "1. Photon\n";
        std::cout << "2. Electron\n";
        std::cout << "3. Positron\n";
        std::cout << "4. Muon\n";
        std::cout << "5. Anti-Muon\n";
        std::cout << "6. Proton\n";
        std::cout << "7. Neutron\n";
        std::cout << "8. Neutrino\n";
        std::cout << "9. Anti-Neutrino\n";
        std::cout << "10. Pion+\n";
        std::cout << "11. Pion-\n";
        std::cout << "12. Pion0\n";
        std::cout << "13. Kaon+\n";
        std::cout << "14. Kaon-\n";
        std::cout << "15. Kaon0\n";
        std::cout << "16. Random Particle\n";
        std::cout << "=========================\n";
    }

    std::unique_ptr<Particle> choose_particle(int choice)
    {
        switch (choice)
        {
            case 1: return std::make_unique<Photon>();
            case 2: return std::make_unique<Electron>();
            case 3: return std::make_unique<Positron>();
            case 4: return std::make_unique<Muon>();
            case 5: return std::make_unique<Antimuon>();
            case 6: return std::make_unique<Proton>();
            case 7: return std::make_unique<Neutron>();
            case 8: return std::make_unique<Neutrino>();
            case 9: return std::make_unique<Antineutrino>();
            case 10: return std::make_unique<PionPlus>();
            case 11: return std::make_unique<PionMinus>();
            case 12: return std::make_unique<PionZero>();
            case 13: return std::make_unique<KaonPlus>();
            case 14: return std::make_unique<KaonMinus>();
            case 15: return std::make_unique<KaonZero>();
            default: return std::make_unique<Photon>();
        }
    }

    std::unique_ptr<Particle> choose_random_particle()
    {
        static std::random_device rand_dev;
        static std::mt19937 generator(rand_dev());
        std::uniform_int_distribution<int> distribution (1, 15);
        int choice = distribution(generator);
        return choose_particle(choice);
    }

} // namespace ParticleUtils