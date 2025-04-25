#include "Utilities.h"

void show_menu() 
{
    std::cout << "===================================================\n";
    std::cout << "Particle Detector Simulation Menu:\n";
    std::cout << "===================================================\n";
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
    std::cout << "8. Random\n";
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
        default: return std::make_unique<Photon>();
    }
}

std::unique_ptr<Particle> choose_random_particle()
{
    static std::random_device rand_dev;
    static std::mt19937 generator(rand_dev());
    std::uniform_int_distribution<int> distribution (1, 7);
    int choice = distribution(generator);
    return choose_particle(choice);
}

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
