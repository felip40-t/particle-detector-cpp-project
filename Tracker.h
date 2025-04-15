#pragma once

#include "Subdetector.h"

class Tracker : public SubDetector
{
    protected:
        int layers; // Number of layers in the tracker
        string material; // Material used in the tracker

    public:
        // Default constructor
        Tracker();

        // Parameterized constructor
        Tracker(double efficiency, double resolution, double uncertainty, int layers, string material);

        // Destructor
        ~Tracker() override = default;

        // Copy constructor
        Tracker(const Tracker& other);

        // Move constructor
        Tracker(Tracker&& other);
        
        // Copy assignment operator
        Tracker& operator=(const Tracker& other);

        // Move assignment operator
        Tracker& operator=(Tracker&& other);

        // Getters for tracker properties
        int get_layers() const { return layers; }
        string get_material() const { return material; }

        // Print function
        void print() const override;

        // Detect function
        void detect(const Particle& particle) override;
};