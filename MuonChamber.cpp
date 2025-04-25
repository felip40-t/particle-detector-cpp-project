#include "MuonChamber.h"

// Default constructor
MuonChamber::MuonChamber()
{
    type = SubDetectorInfo::SubDetectorType::MuonChamber;
    name = SubDetectorInfo::get_subdetector_names(SubDetectorInfo::SubDetectorType::MuonChamber);
    efficiency = 1.0;
    resolution = 0.0;
    uncertainty = 0.0;
}

// Parameterized constructor
MuonChamber::MuonChamber(double efficiency, double resolution, double uncertainty)
    : SubDetector(efficiency, resolution, uncertainty)
{
    type = SubDetectorInfo::SubDetectorType::MuonChamber;
    name = SubDetectorInfo::get_subdetector_names(SubDetectorInfo::SubDetectorType::MuonChamber);
}


// Detect function
void MuonChamber::detect(const Particle& particle, SubDetectorInfo::Measurement& measurement)
{
    // Simulate detection
    // Check if particle is Muon
    if (dynamic_cast<const Muon*>(&particle))
    {
        // Simulate detection with efficiency
        static std::random_device random_device;
        static std::mt19937 generator(random_device());
        std::uniform_real_distribution<double> distribution(0.0, 1.0);
        double random_value = distribution(generator);
        if (random_value < efficiency)
        {
            measurement.muon_chamber = true; // Set the measurement flag for MuonChamber
            measurement.charge = particle.get_properties().get_charge();
            std::cout << "Particle detected in " << name << std::endl;
            // Simulate resolution smearing effect for each component of the particle's momentum
            for (int i = 1; i <= 3; ++i)
            {
                // generate normal distribution with mean = 0 and stddev = uncertainty
                std::normal_distribution<double> normal_distribution(0.0, uncertainty);
                double smeared_value = particle.get_four_momentum().get_component(i) + normal_distribution(generator);
                measurement.momentum[i - 1] = utils::roundToResolution(smeared_value, resolution); // Store the smeared momentum value
            }
        }
    }
}