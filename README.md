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

## Sub-Detectors

- **Tracker**: Measures momentum and charge of **charged particles**.
- **EMCalorimeter**: Measures energy of **electrons/positrons** and **photons**.
- **HadronCalorimeter**: Measures energy of **hadrons**.
- **MuonChamber**: Measures momentum of **muons/antimuons**.

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