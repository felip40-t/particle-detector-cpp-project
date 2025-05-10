#include "Utilities.h"

namespace DetectorUtils 
{
    void show_menu() noexcept
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

    void help_menu() noexcept
    {
        std::cout << "===================================================\n";
        std::cout << "Help\n";
        std::cout << "===================================================\n";
        std::cout << "This program simulates a particle detector.\n\n";
        std::cout << "You have a main detector composed of sub-detectors.\n";
        std::cout << "You can add or remove sub-detectors, and each sub-detector can detect different\nquantities and particles.\n";
        std::cout << "If you add a sub-detector that already exists in the detector, it will be replaced.\n";
        std::cout << "Each sub-detector has its own efficiency, resolution, and uncertainty.\n";
        std::cout << "You can set these parameters when adding a sub-detector.\n";
        std::cout << "Look through the README.md file for more information on the sub-detectors.\n\n";
        std::cout << "You also have a list of particles that will be detected.\n";
        std::cout << "You can add or remove particles from the list.\n";
        std::cout << "When adding a particle, you can choose a specific particle or a random one. It will be generated with a random momentum.\n\n";
        std::cout << "Then, by choosing to detect the particles, the program will simulate the detection process.\n";
        std::cout << "The program will attempt to reconstruct the four-momentum of the detected particles.\n";
        std::cout << "If the resolution and uncertainty of the sub-detectors are too high, the reconstructed four-momentum\n";
        std::cout << "may be incorrect. This means that the invariant mass of the particle may be incorrect, or \n";
        std::cout << "you may get an error message. Try changing the resolution and uncertainty of the sub-detectors.\n";
        std::cout << "Check the README.md file for more information on the particles.\n";
        std::cout << "===================================================\n";
    }

    void subdetector_menu() noexcept
    {
        std::cout << "===================================================\n";
        std::cout << "Sub-detector menu:\n";
        std::cout << "===================================================\n";
        std::cout << "1. Tracker\n";
        std::cout << "2. Muon Chamber\n";
        std::cout << "3. Hadron Calorimeter\n";
        std::cout << "4. EM Calorimeter\n";
    }

    int check_layers()
    {
        while (true)
        {
            std::cout << "Enter number of layers: ";
            std::string input;
            std::cin >> input;
            if (MathUtils::check_string_to_int(input))
            {
                int layers = std::stoi(input);
                if (layers > 0)
                {
                    return layers;
                }
                std::cout << "Invalid number of layers. Please enter a positive integer.\n";
            }
            else
            {
                std::cout << "Invalid input. Please enter a positive integer.\n";
            }
        }
    }

    std::string check_tracker_material()
    {
        while (true)
        {
            tracker_material_menu();
            std::cout << "Enter choice: ";
            std::string input;
            std::cin >> input;
            if (MathUtils::check_string_to_int(input))
            {
                int choice = std::stoi(input);
                switch (choice)
                {
                    case 1: return "Silicon pixels";
                    case 2: return "Silicon strips";
                    case 3: return "TPCs";
                    case 4: return "Scintillator";
                    default:
                        std::cout << "Invalid choice. Please enter a number between 1 and 4.\n";
                        break;
                }
            }
            else
            {
                std::cout << "Invalid input. Please enter a number.\n";
            }
        }
    }

    int check_number_of_technology(const std::string& technology)
    {
        while (true)
        {
            std::cout << "Enter number of " << technology << ": ";
            std::string input;
            std::cin >> input;
            if (MathUtils::check_string_to_int(input))
            {
                int num_of_technology = std::stoi(input);
                if (num_of_technology > 0)
                {
                    return num_of_technology;
                }
                std::cout << "Invalid number of " << technology << ". Please enter a positive integer.\n";
            }
            else
            {
                std::cout << "Invalid input. Please enter a positive integer.\n";
            }
        }
    }

    std::string check_muon_chamber_technology()
    {
        while (true)
        {
            muon_chamber_menu();
            std::cout << "Enter choice: ";
            std::string input;
            std::cin >> input;
            if (MathUtils::check_string_to_int(input))
            {
                int choice = std::stoi(input);
                switch (choice)
                {
                    case 1: return "DTs";
                    case 2: return "CSCs";
                    case 3: return "RPCs";
                    case 4: return "GEMs";
                    default:
                        std::cout << "Invalid choice. Please enter a number between 1 and 4.\n";
                        break;
                }
            }
            else
            {
                std::cout << "Invalid input. Please enter a number.\n";
            }
        }
    }

    void tracker_material_menu() noexcept
    {
        std::cout << "Choose tracker material:\n";
        std::cout << "1. Silicon pixels\n";
        std::cout << "2. Silicon strips\n";
        std::cout << "3. TPCs\n";
        std::cout << "4. Scintillator\n";
    }

    void muon_chamber_menu() noexcept
    {
        std::cout << "Choose muon chamber technology:\n";
        std::cout << "1. DTs\n";
        std::cout << "2. CSCs\n";
        std::cout << "3. RPCs\n";
        std::cout << "4. GEMs\n";
    }

    double check_input_in_range(const std::string& prompt, double min, double max)
    {
        while (true)
        {
            std::cout << prompt;
            std::string input;
            std::cin >> input;
            if (MathUtils::check_string_to_double(input))
            {
                double value = std::stod(input);
                if (value >= min && value <= max)
                {
                    return value;
                }
                std::cout << "Invalid input. Please enter a value within the correct limits.\n";
            }
            else
            {
                std::cout << "Invalid input. Please enter a number.\n";
            }
        }
    }

    double check_efficiency()
    {
        return check_input_in_range("Enter efficiency (0-1): ", 0, 1);
    }

    double check_resolution()
    {
        return check_input_in_range("Enter resolution (MeV): ", 0, std::numeric_limits<double>::infinity());
    }

    double check_uncertainty()
    {
        return check_input_in_range("Enter uncertainty (%): ", 0, 100);
    }

} // namespace DetectorUtils

namespace MathUtils 
{
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
        std::istringstream iss(str);
        double val;
        return !(iss >> val).fail() && iss.eof();  // Ensure a valid double and no extra characters exist
    }
} // namespace MathUtils

namespace ParticleListUtils 
{
    void particle_menu() noexcept
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
        std::uniform_int_distribution<int> distribution(1, 15);
        return choose_particle(distribution(generator));
    }

} // namespace ParticleListUtils