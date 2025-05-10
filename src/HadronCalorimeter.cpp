#include "HadronCalorimeter.h"

// Default constructor
HadronCalorimeter::HadronCalorimeter()
: SubDetector()
{
    type = SubDetectorInfo::SubDetectorType::HadronCalorimeter;
    name = SubDetectorInfo::get_subdetector_names(SubDetectorInfo::SubDetectorType::HadronCalorimeter);
}

// Parameterized constructor
HadronCalorimeter::HadronCalorimeter(double efficiency, double resolution, double uncertainty)
    : SubDetector(efficiency, resolution, uncertainty)
{
    type = SubDetectorInfo::SubDetectorType::HadronCalorimeter;
    name = SubDetectorInfo::get_subdetector_names(SubDetectorInfo::SubDetectorType::HadronCalorimeter);
}


void HadronCalorimeter::detect(const Particle& particle, SubDetectorInfo::Measurement& measurement)
{
    if (dynamic_cast<const Hadron*>(&particle))
    {
        static std::random_device random_device;
        static std::mt19937 generator(random_device());
        std::uniform_real_distribution<double> distribution(0.0, 1.0);
        double random_value = distribution(generator);
        if (random_value < efficiency)
        {
            std::cout << "Particle detected in " << name << std::endl;
            double uncertainty_value = std::abs(particle.get_four_momentum().get_component(0)) * (uncertainty / 100.0);
            std::normal_distribution<double> energy_distribution(0.0, uncertainty_value);
            double smeared_energy = particle.get_four_momentum().get_component(0) + energy_distribution(generator);
            double new_measurement = MathUtils::roundToResolution(smeared_energy, resolution);
            std::cout << "Energy measurement: " << new_measurement << " MeV" << std::endl;
            if (measurement.hadron_calorimeter == false) // no previous measurement
            {
                measurement.energy = new_measurement;
            }
            else // previous measurement exists, so average the two measurements
            {
                double previous_measurement = measurement.energy;
                double average_measurement = (previous_measurement + new_measurement) / 2.0;
                measurement.energy = average_measurement;
            }
            measurement.hadron_calorimeter = true;
        }
    }
}