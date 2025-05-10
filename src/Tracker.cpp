#include "Tracker.h"

// Default constructor
Tracker::Tracker() 
: SubDetector()
{
    type = SubDetectorInfo::SubDetectorType::Tracker;
    name = SubDetectorInfo::get_subdetector_names(SubDetectorInfo::SubDetectorType::Tracker);
    layers = 1; // Default number of layers
    material = "Silicon pixels"; // Default material
}

// Parameterized constructor
Tracker::Tracker(double efficiency, double resolution, double uncertainty, int layers, string material)
    : SubDetector(efficiency, resolution, uncertainty)
{
    type = SubDetectorInfo::SubDetectorType::Tracker;
    name = SubDetectorInfo::get_subdetector_names(SubDetectorInfo::SubDetectorType::Tracker);

    if (MathUtils::check_value_in_range(layers, 1, std::numeric_limits<int>::max()))
    {
        this->layers = layers;
    }
    else
    {
        this->layers = 1;
        std::cout << "Tracker: Invalid number of layers. Setting to 1." << std::endl;
    }
    if (material == "Silicon pixels" || material == "Silicon strips" || material == "TPCs" || material == "Scintillator")
        this->material = material;
    else
    {
        this->material = "Silicon pixels";
        std::cout << "Tracker: Material not recognized. Setting to Silicon pixels." << std::endl;
    }
}

// Print function
void Tracker::print() const 
{
    std::cout << "Sub-detector: " << name << std::endl;
    std::cout << "Efficiency: " << efficiency << std::endl;
    std::cout << "Resolution: " << resolution << " MeV" << std::endl;
    std::cout << "Uncertainty: " << uncertainty << " MeV" << std::endl;
    std::cout << "Material: " << material << std::endl;
    std::cout << "Layers: " << layers << std::endl;
}

// Detect function 
void Tracker::detect(const Particle& particle, SubDetectorInfo::Measurement& measurement)
{
    // Simulate detection
    // Check if particle is charged and not a muon
    if (particle.get_properties().get_charge() != 0 && !dynamic_cast<const Muon*>(&particle))
    {
        // Simulate detection with efficiency
        static std::random_device random_device;
        static std::mt19937 generator(random_device());
        std::uniform_real_distribution<double> distribution(0.0, 1.0);
        double random_value = distribution(generator);
        if (random_value < efficiency)
        {
            std::cout << "Particle detected in " << name << std::endl;
            // Simulate uncertainty effect for each component of the particle's momentum
            std::array<double, 3> new_measurement;
            for (int i = 1; i <= 3; ++i)
            {   
                // generate normal distribution with mean = 0 and stddev = uncertainty% of the absolute momentum
                double uncertainty_value = std::abs(particle.get_four_momentum().get_component(i)) * (uncertainty / 100.0);
                std::normal_distribution<double> normal_distribution(0.0, uncertainty_value);
                double smeared_value = particle.get_four_momentum().get_component(i) + normal_distribution(generator);
                new_measurement[i - 1] = MathUtils::roundToResolution(smeared_value, resolution);
                
                if (measurement.track == false) // no previous measurement by another tracker
                {
                    measurement.momentum[i - 1] = new_measurement[i - 1]; // Store the smeared momentum value
                }
                else // previous measurement exists, so average the two measurements
                {
                    double previous_measurement = measurement.momentum[i - 1];
                    double average_measurement = (previous_measurement + new_measurement[i - 1]) / 2.0;
                    measurement.momentum[i - 1] = average_measurement; // Store the averaged momentum value
                }
            }
            std::cout << "Momentum measurement: (";
            for (int i = 0; i < 3; ++i) {
                std::cout << new_measurement[i];
                if (i < 2) std::cout << ", ";
            }
            std::cout << ")" << std::endl;
            measurement.track = true; // Set the track flag to true
            measurement.charge = particle.get_properties().get_charge(); // Set the charge of the particle
        }
    }
}

