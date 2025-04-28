#include "SubdetectorInfo.h"


namespace SubDetectorInfo
{
    // Define the static map to hold sub-detector names
    const std::string& get_subdetector_names(SubDetectorType type)
    {
        // Map to hold sub-detector names
        static const std::map<SubDetectorType, std::string> subdetector_names = {
            {SubDetectorType::Tracker, "Tracker"},
            {SubDetectorType::MuonChamber, "Muon Chamber"},
            {SubDetectorType::HadronCalorimeter, "Hadron Calorimeter"},
            {SubDetectorType::EMCalorimeter, "EM Calorimeter"},
        };
        auto it = subdetector_names.find(type);
        if (it == subdetector_names.end()) 
        {
            return subdetector_names.at(SubDetectorType::Tracker); // Return default name if not found
        }
        else 
        {
            return subdetector_names.at(type);
        }
    }

} // namespace SubDetectorInfo
