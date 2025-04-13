#include "Tracker.h"

// Default constructor
Tracker::Tracker()
{
    type = SubDetectorInfo::SubDetectorType::Tracker;
    name = SubDetectorInfo::get_subdetector_names(SubDetectorType::Tracker);
    efficiency = 1.0;
    resolution = 0.0;
    layers = 1;
    material = "Default Material";
}

// Parameterized constructor
Tracker::Tracker(double efficiency, double resolution, int layers, string material)
    : SubDetector(efficiency, resolution)
{
    type = SubDetectorInfo::SubDetectorType::Tracker;
    name = SubDetectorInfo::get_subdetector_names(SubDetectorType::Tracker);

    if (layers < 0 || std::isnan(layers) || std::isinf(layers)) 
    {
        try 
        {
            throw std::invalid_argument("Tracker: Number of layers must be non-negative, finite and real.");
        } 
        catch (const std::invalid_argument& e) 
        {
            std::cout << e.what() << std::endl;
            std::cout << "Setting layers to 1." << std::endl;
            layers = 1;
        }
    }
    this->layers = layers;
    switch (material)
    {
        case "Silicon":
            this->material = "Silicon";
            break;
        default:
            this->material = "Silicon";
            std::cout << "Tracker: Material not recognized. Setting to Silicon." << std::endl;
            break;
    }
}

// Copy constructor
Tracker::Tracker(const Tracker& other)
    : SubDetector(other), layers(other.layers), material(other.material) {}

// Move constructor
Tracker::Tracker(Tracker&& other)
    : SubDetector(std::move(other)), layers(other.layers), material(std::move(other.material)) 
{
    other.layers = 1;
    other.material = "Default Material";
}

// Copy assignment operator
Tracker& Tracker::operator=(const Tracker& other) 
{
    if (this != &other) 
    {
        SubDetector::operator=(other);
        layers = other.layers;
        material = other.material;
    }
    return *this;
}

// Move assignment operator
Tracker& Tracker::operator=(Tracker&& other) 
{
    if (this != &other) 
    {
        SubDetector::operator=(std::move(other));
        layers = other.layers;
        material = std::move(other.material);
        other.layers = 1;
        other.material = "Default Material";
    }
    return *this;
}

// Print function
void Tracker::print() const 
{
    std::cout << "Tracker: " << name << std::endl;
    std::cout << "Efficiency: " << efficiency << std::endl;
    std::cout << "Resolution: " << resolution << std::endl;
    std::cout << "Layers: " << layers << std::endl;
    std::cout << "Material: " << material << std::endl;
}

// Detect function - prints momentum vector if detected
void Tracker::detect(const Particle& particle)
{
    // Simulate detection
    // Check if particle is charged
    if (particle.get_properties().get_charge() != 0)
    {
        // Simulate detection with efficiency
        std::random_device random_device;
        std::mt19937 generator(random_device());
        std::uniform_real_distribution<double> distribution(0.0, 1.0);
        double random_value = distribution(generator);
        if (random_value < efficiency)
        {
            std::cout << "Particle detected in " << name << " with momentum: \n";
            std::cout << "[";
            // Simulate resolution smearing effect for each component of the particle's momentum
            for (int i = 1; i <= 3; ++i)
            {
                // generate normal distribution with mean = 0 and stddev = resolution
                std::normal_distribution<double> normal_distribution(0.0, resolution);
                double smeared_value = particle.get_four_momentum().get_component(i) + normal_distribution(generator);
                std::cout << smeared_value;
                if (i < 3) std::cout << ", ";
            }
            std::cout << "]" << std::endl;
        }
    }
}