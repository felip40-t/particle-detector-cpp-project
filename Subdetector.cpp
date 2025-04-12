#include "Subdetector.h"

// Default constructor
SubDetector::SubDetector()
    : type(SubDetectorType::Default), 
      name(get_subdetector_names(SubDetectorType::Default)),
      efficiency(1.0),
      resolution(0.0) {}

// Copy constructor
SubDetector::SubDetector(const SubDetector& other)
    : type(other.type),
      name(other.name),
      efficiency(other.efficiency),
      resolution(other.resolution) {}

// Move constructor
SubDetector::SubDetector(SubDetector&& other)
    : type(other.type),
      name(std::move(other.name)),
      efficiency(other.efficiency),
      resolution(other.resolution) 
{
    other.type = SubDetectorType::Default;
    other.name = get_subdetector_names(SubDetectorType::Default);
    other.efficiency = 1.0;
    other.resolution = 0.0;
}

// Copy assignment operator
SubDetector& SubDetector::operator=(const SubDetector& other)
{
    if (this != &other) {
        type = other.type;
        name = other.name;
        efficiency = other.efficiency;
        resolution = other.resolution;
    }
    return *this;
}

// Move assignment operator
SubDetector& SubDetector::operator=(SubDetector&& other)
{
    if (this != &other) {
        type = other.type;
        name = std::move(other.name);
        efficiency = other.efficiency;
        resolution = other.resolution;

        other.type = SubDetectorType::Default;
        other.name = get_subdetector_names(SubDetectorType::Default);
        other.efficiency = 1.0;
        other.resolution = 0.0;
    }
    return *this;
}


// Define the static map to hold sub-detector names
string get_subdetector_names(SubDetectorType type)
{
    // Map to hold sub-detector names
    static std::map<SubDetectorType, string> subdetector_names = {
        {SubDetectorType::Default, "Default"},
        {SubDetectorType::Calorimeter, "Calorimeter"},
        {SubDetectorType::Tracker, "Tracker"},
        {SubDetectorType::MuonChamber, "Muon Chamber"},
        {SubDetectorType::HadronCalorimeter, "Hadron Calorimeter"},
        {SubDetectorType::EMCalorimeter, "EM Calorimeter"},
        {SubDetectorType::SiliconTracker, "Silicon Tracker"},
        {SubDetectorType::TPCTracker, "TPC Tracker"},
        {SubDetectorType::DTMuonChamber, "DT Muon Chamber"},
        {SubDetectorType::CSCMuonChamber, "CSC Muon Chamber"}
    };
}