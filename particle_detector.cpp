#include <iostream>
#include <iomanip>

#include "Detector.h"
#include "Tracker.h"
#include "EMCalorimeter.h"
#include "HadronCalorimeter.h"
#include "MuonChamber.h"

#include "Electron.h"
#include "Muon.h"
#include "Photon.h"
#include "Hadron.h"


int main() {

    // Create a detector object
    Detector CMS_detector("CMS style detector");
    // Create a sub-detector object
    // And add the sub-detector to the detector
    CMS_detector.add_subdetector(std::make_unique<Tracker>(0.99, 0.0001, 0.0001, 5, "Silicon"));
    CMS_detector.add_subdetector(std::make_unique<EMCalorimeter>(0.99, 0.0001, 0.0001));
    CMS_detector.add_subdetector(std::make_unique<HadronCalorimeter>(0.99, 1, 0.5));
    CMS_detector.add_subdetector(std::make_unique<MuonChamber>(0.99, 0.2, 0.1));


    CMS_detector.print(); // Print the detector information

    // Create a vector of particles
    std::vector<std::unique_ptr<Particle>> particles;
    particles.push_back(std::make_unique<Electron>());
    particles.push_back(std::make_unique<Positron>());
    particles.push_back(std::make_unique<Photon>());
    particles.push_back(std::make_unique<Proton>());
    particles.push_back(std::make_unique<Neutron>());
    particles.push_back(std::make_unique<Muon>());
    particles.push_back(std::make_unique<AntiMuon>());

    // Loop through particles
    for (const auto& particle : particles) 
    {
        // particle->print_data();
        // // Check invariant mass of particle
        // double inv_mass {sqrt(particle->get_four_momentum() * particle->get_four_momentum())};
        // std::cout << "Invariant mass of " << particle->get_properties().get_name() << ": " << inv_mass << " MeV/c^2\n";
        CMS_detector.detect(*particle); 
    }

    return 0;
}