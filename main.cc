/////////////////////////////////////////////////////////
//                                                     //
//  Nov/2021  E. Nacher  -->  main.cc                  //
//                                                     //
/////////////////////////////////////////////////////////


#include "G4RunManager.hh"
#include "globals.hh"



#include "G4UnitsTable.hh"

#include "G4VisExecutive.hh"
#include "G4UIExecutive.hh"

#include "G4ios.hh"
#include "fstream"
#include "iomanip"
#include "G4TwistedTubs.hh"

using namespace CLHEP;

int main()
{
// Define the twisted tube
    G4double twistedTubeInnerRadius = 10.0*mm;
    G4double twistedTubeOuterRadius = 30.0*mm;
    G4double twistedTubeLength = 100.0*mm;
    G4double twistedTubeTwistAngle = 45.0*degree;
    G4double twistedTubeTwistPhi = 90.0*degree;
    

    G4TwistedTubs* solidTwistedTube = new G4TwistedTubs("TwistedTube", twistedTubeTwistAngle, twistedTubeInnerRadius, twistedTubeOuterRadius, twistedTubeLength,twistedTubeTwistPhi);
    G4ThreeVector p(0,0,0);
    G4ThreeVector v(0,0,1);

    double d2in = solidTwistedTube->DistanceToIn(p,v);
    std::cout << d2in << std::endl;
  
  return 0;
}


