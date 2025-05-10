#pragma once

#include "Subdetector.h"
#include "Muon.h"

class MuonChamber : public SubDetector
{
    protected:
        // Technology used in the Muon Chamber
        std::string technology; 
        // Number of said technology in the Muon Chamber
        int num_of_technology {1};

    public:
        // Destructor
        ~MuonChamber() override = default;

        // Default constructor
        MuonChamber();

        // Parameterized constructor
        MuonChamber(double efficiency, double resolution, double uncertainty, int num_of_technology, std::string technology);
        
        // Copy constructor
        MuonChamber(const MuonChamber& other) = default;

        // Move constructor
        MuonChamber(MuonChamber&& other) = default;

        // Copy assignment operator
        MuonChamber& operator=(const MuonChamber& other) = default;

        // Move assignment operator
        MuonChamber& operator=(MuonChamber&& other) = default;

        // Getters for MuonChamber properties
        int get_num_of_technology() const { return num_of_technology; }
        std::string get_technology() const { return technology; }

        // Detect function
        void detect(const Particle& particle, SubDetectorInfo::Measurement& m) override;

        // Print function
        void print() const override;
};