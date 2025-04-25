#include "EMCalorimeter.h"


// Default constructor
EMCalorimeter::EMCalorimeter()
{
    type = SubDetectorInfo::SubDetectorType::EMCalorimeter;
    name = SubDetectorInfo::get_subdetector_names(SubDetectorInfo::SubDetectorType::EMCalorimeter);
    efficiency = 1.0;
    resolution = 0.0;
    uncertainty = 0.0;
}

// Parameterized constructor
EMCalorimeter::EMCalorimeter(double efficiency, double resolution, double uncertainty)
    : SubDetector(efficiency, resolution, uncertainty)
{
    type = SubDetectorInfo::SubDetectorType::EMCalorimeter;
    name = SubDetectorInfo::get_subdetector_names(SubDetectorInfo::SubDetectorType::EMCalorimeter);
}


// Detect function
void EMCalorimeter::detect(const Particle& particle)
{
    // Simulate detection
    // Check if particle is Electron/Positron or Photon
    measurement = SubDetectorInfo::Measurement(); // Reset measurement
    if (dynamic_cast<const Electron*>(&particle) || dynamic_cast<const Photon*>(&particle))
    {
        // Simulate detection with efficiency
        static std::random_device random_device;
        static std::mt19937 generator(random_device());
        std::uniform_real_distribution<double> distribution(0.0, 1.0);
        double random_value = distribution(generator);
        if (random_value < efficiency)
        {
            measurement.em_calorimeter = true; // Set the measurement flag for EMCalorimeter
            std::cout << "Particle detected in " << name << std::endl;
            // Simulate the smearing of energy
            std::normal_distribution<double> energy_distribution(0.0, uncertainty);
            double smeared_energy = particle.get_four_momentum().get_component(0) + energy_distribution(generator);
            measurement.energy = roundToResolution(smeared_energy, resolution);
        }
    }
}