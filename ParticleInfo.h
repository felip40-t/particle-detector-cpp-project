#pragma once

#include <string>
#include <map>
using std::string;

namespace ParticleInfo
{

    // Enumerator class for particle types
    enum class ParticleType
    {
        Particle,
        Lepton,
        Hadron,
        Electron,
        Positron,
        Muon,
        Antimuon,
        Proton,
        Neutron,
        Photon,
    };

    // Class for particle properties
    class ParticleProperties
    {
        private:
            ParticleType type; // Type of the particle
            double mass; // Mass in MeV/c^2
            double charge; // Charge in e

        public:
            // Default constructor
            ParticleProperties();

            // Constructor for ParticleProperties
            ParticleProperties(ParticleType type, double mass, double charge, const string& name);

            // Destructor
            ~ParticleProperties();

            // Copy constructor
            ParticleProperties(const ParticleProperties& other);

            // Move constructor
            ParticleProperties(ParticleProperties&& other);

            // Copy assignment operator
            ParticleProperties& operator=(const ParticleProperties& other);

            // Move assignment operator
            ParticleProperties& operator=(ParticleProperties&& other);

            // Getters for particle properties
            ParticleType get_type() const { return type; }
            double get_mass() const { return mass; }
            double get_charge() const { return charge; }
            string get_name() const { return name; }
    };


    // Function to get particle properties by type using static map
    const ParticleProperties& get_particle_properties(ParticleType type);

} // namespace ParticleInfo