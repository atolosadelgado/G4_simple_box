
#ifndef TASDetectorConstruction_h
#define TASDetectorConstruction_h 1

#include "G4VUserDetectorConstruction.hh"
#include "G4VPhysicalVolume.hh"


class G4VPhysicalVolume;

class DetectorConstruction : public G4VUserDetectorConstruction
{
  public:
    DetectorConstruction();
    ~DetectorConstruction();
    
    
  public:
    G4VPhysicalVolume* Construct();

};

#endif

