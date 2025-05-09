#pragma once

#include "Subdetector.h"
#include "Muon.h"

class Tracker : public SubDetector
{
    protected:
        int layers; // Number of layers in the tracker
        std::string material; // Material used in the tracker

    public:
        // Destructor
        ~Tracker() override = default;

        // Default constructor
        Tracker();

        // Parameterized constructor
        Tracker(double efficiency, double resolution, double uncertainty, int layers, string material);

        // Copy constructor
        Tracker(const Tracker& other) = default;

        // Move constructor
        Tracker(Tracker&& other) = default;
        
        // Copy assignment operator
        Tracker& operator=(const Tracker& other) = default;

        // Move assignment operator
        Tracker& operator=(Tracker&& other) = default;

        // Getters for tracker properties
        int get_layers() const { return layers; }
        string get_material() const { return material; }

        // Print function
        void print() const override;

        // Detect function
        void detect(const Particle& particle, SubDetectorInfo::Measurement& m) override;

};