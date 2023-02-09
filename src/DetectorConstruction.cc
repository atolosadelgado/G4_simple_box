////////////////////////////////////////////////////////////////////
//
//  Dec-2021 E. Nacher (after JL. Tain) --> DetectorConstruction.cc
//
////////////////////////////////////////////////////////////////////


#include "DetectorConstruction.hh"

#include "G4Material.hh"
#include "G4Tubs.hh"
#include "G4Box.hh"
#include "G4Cons.hh"
#include "G4Trd.hh"
#include "G4Polyhedra.hh"
#include "G4Element.hh"
#include "G4ElementTable.hh"
#include "G4LogicalVolume.hh"
#include "G4PVPlacement.hh"
#include "G4RotationMatrix.hh"
#include "G4Transform3D.hh"
#include "G4VisAttributes.hh"
#include "G4Colour.hh"

using namespace CLHEP;

DetectorConstruction::DetectorConstruction()
{ }

DetectorConstruction::~DetectorConstruction()
{ }

G4VPhysicalVolume* DetectorConstruction::Construct()
{   
    // Aluminum
    double density = 2.700*g/cm3;
    double a = 26.98*g/mole;
    G4Material* Alum = new G4Material("Aluminium", 13., a, density);

    G4double WorldSize= 200.*cm;
    
    G4Box*
    SolidWorld = new G4Box("World",                               //its name
                           WorldSize/2,WorldSize/2,WorldSize/2);  //its size
    
    G4LogicalVolume*
    LogicWorld = new G4LogicalVolume(SolidWorld,      //its solid
                                     Alum,	      //its material
                                     "World");        //its name
  
   
    G4VPhysicalVolume*
    PhysiWorld = new G4PVPlacement(0,               //no rotation
                                   G4ThreeVector(),	//at (0,0,0)
                                   "World",         //its name
                                   LogicWorld,		//its logical volume
                                   NULL,            //its mother  volume
                                   false,	       	//no boolean operation
                                   0);              //copy number
  return PhysiWorld;

}

