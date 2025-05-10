#include "MuonChamber.h"

// Default constructor
MuonChamber::MuonChamber()
: SubDetector()
{
    type = SubDetectorInfo::SubDetectorType::MuonChamber;
    name = SubDetectorInfo::get_subdetector_names(SubDetectorInfo::SubDetectorType::MuonChamber);

    technology = "DTs"; // Default technology
    num_of_technology = 1; // Default number of technology
}

// Parameterized constructor
MuonChamber::MuonChamber(double efficiency, double resolution, double uncertainty, int num_of_technology, std::string technology)
    : SubDetector(efficiency, resolution, uncertainty)
{
    type = SubDetectorInfo::SubDetectorType::MuonChamber;
    name = SubDetectorInfo::get_subdetector_names(SubDetectorInfo::SubDetectorType::MuonChamber);

    if (technology == "DTs" || technology == "CSCs" || technology == "RPCs" || technology == "GEMs")
        this->technology = technology;
    else
    {
        this->technology = "DTs";
        std::cout << "MuonChamber: Technology not recognized. Setting to DTs." << std::endl;
    }

    if (MathUtils::check_value_in_range(num_of_technology, 1, std::numeric_limits<int>::max()))
    {
        this->num_of_technology = num_of_technology;
    }
    else
    {
        this->num_of_technology = 1;
        std::cout << "MuonChamber: Invalid number of " << technology << ". Setting to 1." << std::endl;
    }
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
                // generate normal distribution with mean = 0 and stddev = uncertainty% of the absolute momentum
                double uncertainty_value = std::abs(particle.get_four_momentum().get_component(i)) * (uncertainty / 100.0);
                std::normal_distribution<double> normal_distribution(0.0, uncertainty_value);
                double smeared_value = particle.get_four_momentum().get_component(i) + normal_distribution(generator);
                measurement.momentum[i - 1] = MathUtils::roundToResolution(smeared_value, resolution); // Store the smeared momentum value
            }
        }
    }
}

// Print function
void MuonChamber::print() const
{
    std::cout << "Sub-detector: " << name << std::endl;
    std::cout << "Efficiency: " << efficiency << std::endl;
    std::cout << "Resolution: " << resolution << " MeV" << std::endl;
    std::cout << "Uncertainty: " << uncertainty << " MeV" << std::endl;
    std::cout << "Technology: " << technology << std::endl;
    std::cout << "Number of " << technology << ": " << num_of_technology << std::endl;
}