// Date: 15/04/2025
/*
Title: Particle Detector Simulation
Student ID: 10826579

Abstract:
This program simulates a particle detector, by adding sub-detectors to a main detector object.
It creates a vector of particles, which can be chosen from a list of Standard Model particles.
The detector then 'detects' them, by using each sub-detector to check if the particle is detected.
If the sub-detector is suited to detect the specific particle, then it can measure it's energy or momentum.
Tracking sub-detectors can also measure the sign of the particle's charge.
The detectors then combine the measurements made into a single Measurement object, and if there is sufficient
information then it can reconstruct the particle's four-momentum, and hence calculate the invariant mass of 
the particle.

The sub-detectors are also modeled to be imperfect; they have a certain efficiency, as well as a resolution
and uncertainty on each measurement of the energy/momentum. 
After each particle is passed through the detector, each sub-detector will print out the information it has measured.
The invariant mass of the particle is then calculated if enough information is available.

The list of sub-detectors is as follows:
Tracker: A tracking detector that measures the momentum of charged particles.
EMCalorimeter: An electromagnetic calorimeter that measures the energy of photons and electrons/positrons.
HadronCalorimeter: A hadronic calorimeter that measures the energy of hadrons.
MuonChamber: A muon chamber that measures the momentum of muons/antimuons.

The list of particles is as follows:
Electron: A negatively charged lepton with a mass of 0.511 MeV/c^2.
Positron: A positively charged lepton with a mass of 0.511 MeV/c^2.
Photon: A neutral boson with a mass of 0 MeV/c^2.
Muon: A negatively charged lepton with a mass of 105.7 MeV/c^2.
Antimuon: A positively charged lepton with a mass of 105.7 MeV/c^2.
Proton: A positively charged Hadron with a mass of 938.3 MeV/c^2.
Neutron: A neutral Hadron with a mass of 939.6 MeV/c^2.

Class hierarchy is as follows:
Particle -> Lepton -> Electron -> Positron
Particle -> Lepton -> Muon -> Antimuon
Particle -> Hadron -> Proton
Particle -> Hadron -> Neutron
Particle -> Boson -> Photon

SubDetector -> Tracker
SubDetector -> EMCalorimeter
SubDetector -> HadronCalorimeter
SubDetector -> MuonChamber


*/





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