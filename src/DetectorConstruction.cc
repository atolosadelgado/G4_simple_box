
#include "DetectorConstruction.hh"
#include "G4Material.hh"
#include "G4NistManager.hh"
#include "G4Box.hh"
#include "G4TwistedTubs.hh"
#include "G4LogicalVolume.hh"
#include "G4PVPlacement.hh"
#include "G4SystemOfUnits.hh"
#include "G4VisAttributes.hh"

DetectorConstruction::DetectorConstruction() : G4VUserDetectorConstruction() {}

DetectorConstruction::~DetectorConstruction() {}


G4VPhysicalVolume* DetectorConstruction::Construct() {

    G4NistManager* nist = G4NistManager::Instance();
    G4Material* air = nist->FindOrBuildMaterial("G4_AIR");

    // Define the universe box
    G4double worldSizeXY = 1.0*m;
    G4double worldSizeZ = 1.0*m;

    G4Box* solidWorld = new G4Box("World", worldSizeXY, worldSizeXY, worldSizeZ);
    G4LogicalVolume* logicWorld = new G4LogicalVolume(solidWorld, air, "World");
    G4VPhysicalVolume* physWorld = new G4PVPlacement(0, G4ThreeVector(), logicWorld, "World", 0, false, 0, true);

    // Define the twisted tube
    G4double twistedTubeInnerRadius = 10.0*mm;
    G4double twistedTubeOuterRadius = 30.0*mm;
    G4double twistedTubeLength = 100.0*mm;
    G4double twistedTubeTwistAngle = 45.0*degree;
    G4double twistedTubeTwistPhi = 90.0*degree;
    

    G4TwistedTubs* solidTwistedTube = new G4TwistedTubs("TwistedTube", twistedTubeTwistAngle, twistedTubeInnerRadius, twistedTubeOuterRadius, twistedTubeLength,twistedTubeTwistPhi);
    G4LogicalVolume* logicTwistedTube = new G4LogicalVolume(solidTwistedTube, air, "TwistedTube");

    // Place the twisted tube inside the world
    G4ThreeVector twistedTubePosition = G4ThreeVector(0, 0, 0);
    new G4PVPlacement(0, twistedTubePosition, logicTwistedTube, "TwistedTube", logicWorld, false, 0, true);

    // Visualization attributes (optional)
    G4VisAttributes* worldVisAttr = new G4VisAttributes(G4Colour(1.0, 1.0, 1.0, 0.1)); // Transparent white
    logicWorld->SetVisAttributes(worldVisAttr);

    G4VisAttributes* twistedTubeVisAttr = new G4VisAttributes(G4Colour(0.0, 0.0, 1.0)); // Blue
    logicTwistedTube->SetVisAttributes(twistedTubeVisAttr);

    return physWorld;
}


