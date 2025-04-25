#pragma once

#include "Subdetector.h"
#include "Muon.h"

class MuonChamber : public SubDetector
{
    public:
        // Default constructor
        MuonChamber();

        // Parameterized constructor
        MuonChamber(double efficiency, double resolution, double uncertainty);
        
        // Destructor
        ~MuonChamber() override = default;
        
        // Copy constructor
        MuonChamber(const MuonChamber& other) = default;

        // Move constructor
        MuonChamber(MuonChamber&& other) = default;

        // Copy assignment operator
        MuonChamber& operator=(const MuonChamber& other) = default;

        // Move assignment operator
        MuonChamber& operator=(MuonChamber&& other) = default;

        // Detect function
        void detect(const Particle& particle, SubDetectorInfo::Measurement& m) override;
};