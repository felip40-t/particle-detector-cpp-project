#pragma once

#include "Particle.h"
#include "Utilities.h"

class ParticleList
{
    private:
        std::vector<std::unique_ptr<Particle>> particles;

    public:
        // Default constructor
        ParticleList() = default;

        // Destructor
        ~ParticleList() = default;

        // Add a particle to the list
        void add_particle();

        // Add a custom particle to the list
        void add_custom_particle(std::unique_ptr<Particle>&& particle);

        // Remove a particle from the list
        void remove_particle();

        // Clear all particles from the list
        void clear_particles();

        // Print all particles in the list
        void print_particles() const;

        // Get particles
        const std::vector<std::unique_ptr<Particle>>& get_particles() const { return particles; }
};