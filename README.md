# Particle Detector Simulation

**Date:** 15/04/2025  
**Student ID:** 10826579

## Abstract

This program simulates a particle detector by composing multiple sub-detectors into a main detector object. A list of Standard Model particles is generated and passed through this detector system.

Each sub-detector attempts to detect the particle and measure its properties (energy, momentum, charge sign) based on its design. If enough measurements are gathered, the system reconstructs the particle's four-momentum and calculates its **invariant mass**.

### Features:
- Particle creation from a predefined list of Standard Model particles.
- Simulated sub-detectors with efficiency, resolution, and uncertainty models.
- Measurement aggregation and invariant mass calculation.
- Per-particle measurement logging by each detector component.
- User Interface to build a detector object and add particles to a list to be measured.

## Project Structure

The project is organized into two main directories:

- `include/`: Contains all header files (`.h`)
  - Core classes: `Particle.h`, `FourMomentum.h`, `Detector.h`
  - Particle types: `Electron.h`, `Muon.h`, `Photon.h`, etc.
  - Sub-detector types: `Tracker.h`, `EMCalorimeter.h`, etc.
  - Utility files: `Utilities.h`, `ParticleInfo.h`, `SubDetectorInfo.h`

- `src/`: Contains all implementation files (`.cpp`)
  - Core implementations: `Particle.cpp`, `FourMomentum.cpp`, `Detector.cpp`
  - Particle type implementations: `Electron.cpp`, `Muon.cpp`, `Photon.cpp`, etc.
  - Sub-detector implementations: `Tracker.cpp`, `EMCalorimeter.cpp`, etc.

The main program entry point is `particle_detector.cpp` in the root directory.

## Sub-Detectors

- **Tracker**: Measures momentum and charge of **charged particles**.
- **EMCalorimeter**: Measures energy of **electrons/positrons** and **photons**.
- **HadronCalorimeter**: Measures energy of **hadrons**.
- **MuonChamber**: Measures momentum of **muons/antimuons**.

## Particle Detection Logic

### Measurement Aggregation
When multiple sub-detectors of the same type are present, the system aggregates their measurements to improve accuracy:

1. **Energy Measurements** (EMCalorimeter and HadronCalorimeter):
   - Each calorimeter measures the particle's energy
   - If a previous measurement exists, the new measurement is averaged with the previous one
   - The final energy value is stored in the measurement object

2. **Momentum Measurements** (Tracker and MuonChamber):
   - Each detector measures the particle's momentum components (px, py, pz)
   - If a previous measurement exists, each momentum component is averaged with its corresponding previous measurement
   - The final momentum values are stored in the measurement object

This aggregation system ensures that multiple measurement of the same quantity are properly combined.

### Neutrino Detection
Neutrinos are detected through the absence of any signal in all sub-detectors. However, to confirm a neutrino detection, the system requires that all four types of sub-detectors (Tracker, EMCalorimeter, HadronCalorimeter, and MuonChamber) are present in the detector. This is because:

1. A neutrino could be misidentified if a sub-detector is missing
2. The absence of a signal in all present sub-detectors is only meaningful if we know all possible detection methods were available
3. This ensures we don't falsely identify a neutrino when we simply don't have the right detector to see the particle

The detection process follows this logic:
1. Each sub-detector attempts to detect the particle
2. If no sub-detector reports a detection
3. The system checks if all four types of sub-detectors are present
4. Only if all types are present, the particle is identified as a neutrino
5. Otherwise, the system reports that it cannot confirm the particle type

## Supported Particles

| Particle        | Type        | Charge | Mass (MeV/c²) |
|-----------------|-------------|--------|---------------|
| Photon          | Boson       | 0      | 0             |
| Electron        | Lepton      | -1     | 0.511         |
| Positron        | Lepton      | +1     | 0.511         |
| Muon            | Lepton      | -1     | 105.7         |
| Anti-Muon       | Lepton      | +1     | 105.7         |
| Proton          | Hadron      | +1     | 938.3         |
| Neutron         | Hadron      | 0      | 939.6         |
| Neutrino        | Lepton      | 0      | ~0            |
| Anti-Neutrino   | Lepton      | 0      | ~0            |
| Pion⁺           | Meson       | +1     | 139.6         |
| Pion⁻           | Meson       | -1     | 139.6         |
| Pion⁰           | Meson       | 0      | 135.0         |
| Kaon⁺           | Meson       | +1     | 493.7         |
| Kaon⁻           | Meson       | -1     | 493.7         |
| Kaon⁰           | Meson       | 0      | 497.6         |


## Class Hierarchy

### Particles
```
Particle
├─ Lepton
│  ├─ Electron
│  │  └─ Positron
│  ├─ Muon
│  │  └─ Antimuon
│  └─ Neutrino
│     └─ Antineutrino
├─ Hadron
│  ├─ Proton
│  ├─ Neutron
│  ├─ Pion
│  │  ├─ Pion+
│  │  ├─ Pion-
│  │  └─ Pion0
│  └─ Kaon
│     ├─ Kaon+
│     ├─ Kaon-
│     └─ Kaon0
└─ Photon
```

### Sub-detectors
```
SubDetector
├─ Tracker
├─ EMCalorimeter
├─ HadronCalorimeter
└─ MuonChamber
```
## Notes

- Detector measurements are subject to **efficiency**, **resolution**, and **uncertainty**.
- Detectors log their measurements for each particle.
- Invariant mass is calculated only if sufficient data is available.

## Potential Improvements

### Measurement Aggregation
- Implement weighted means for measurement aggregation, where weights are based on:
  - Sub-detector resolution
  - Sub-detector uncertainty
  - Energy/momentum of the particle

### Particle Physics
- Add more Standard Model particles:
  - Heavy quarks (charm, bottom, top)
  - W and Z bosons
  - Higgs boson
  - Tau leptons
- Simulate particle interactions:
  - Scattering processes
  - Particle production
  - Energy loss in detector material
- Implement particle decays:
  - Decay chains
  - Branching ratios

### Detector Simulation
- Implement magnetic field effects
- Simulate detector material effects:
  - Multiple scattering
  - Energy loss
  - Nuclear interactions

### User Interface
- Add a graphical user interface
- Implement real-time visualization