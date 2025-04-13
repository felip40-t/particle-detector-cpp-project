#include <iostream>
#include "Detector.h"
#include "Electron.h"
#include "Tracker.h"


int main() {

    // Create a detector object
    Detector CMS_detector;
    // Create a sub-detector object
    Tracker silicon_tracker(0.9, 10, 5, "Silicon");
    // Add the sub-detector to the detector
    CMS_detector.add_subdetector(std::make_unique<Tracker>(silicon_tracker));
    CMS_detector.print(); // Print the detector information

    return 0;
}