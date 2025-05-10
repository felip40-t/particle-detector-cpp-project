#include "ParticleList.h"

void ParticleList::add_particle()
{
    ParticleListUtils::particle_menu();
    std::cout << "Please enter the number of your chosen particle: ";
    std::string particle_choice;
    std::cin >> particle_choice;
    if (MathUtils::check_string_to_int(particle_choice))
        {
            int choice = std::stoi(particle_choice);
            for (int i = 1 ; i < 15 ; i++)
            {
                if (choice == i)
                    particles.push_back(ParticleListUtils::choose_particle(choice));
            }
            if (choice == 16)
                particles.push_back(ParticleListUtils::choose_random_particle());
        }
}

// Add a custom particle to the list
void ParticleList::add_custom_particle(std::unique_ptr<Particle>&& particle)
{
    particles.push_back(std::move(particle));
}

void ParticleList::remove_particle()
{
    if (particles.empty()) 
    {
        std::cout << "No particles to remove.\n";
        return;
    }
    std::cout << "================================\n";
    std::cout << "Remove a particle\n";
    std::cout << "================================\n";
    std::cout << "Enter index of particle to remove: ";
    std::string index_input;
    std::cin >> index_input;
    if (MathUtils::check_string_to_int(index_input)) 
    {
        size_t index = std::stoi(index_input);
        if (index < particles.size()) 
        {
            particles.erase(particles.begin() + index);
            std::cout << "Particle removed successfully.\n";
        } 
        else 
        {
            std::cout << "Invalid index. No particle removed.\n";
        }
    } 
    else 
    {
        std::cout << "Invalid input. Please enter a number.\n";
    }
}

void ParticleList::clear_particles()
{
    if (particles.empty()) 
    {
        std::cout << "No particles to clear.\n";
        return;
    }
    particles.clear();
    std::cout << "All particles cleared.\n";
}

void ParticleList::print_particles() const
{
    if (particles.empty()) 
    {
        std::cout << "No particles in the list.\n";
        return;
    }
    std::cout << "================================\n";
    std::cout << "Particles' information\n";
    std::cout << "================================\n";
    for (size_t i = 0; i < particles.size(); ++i) 
    {
        std::cout << "Particle " << i << ": ";
        particles[i]->print_data();
        std::cout << "-------------------------------------------------------\n";
    }
    std::cout << "Total number of particles: " << particles.size() << "\n";
    std::cout << "================================\n";
}
