/////////////////////////////////////////////////////////
//                                                     //
//  Nov/2021  E. Nacher  -->  main.cc                  //
//                                                     //
/////////////////////////////////////////////////////////


#include "globals.hh"
#include "G4UnitsTable.hh"

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
    G4ThreeVector v(1,0,0);


    std::cout << "First call: " <<  solidTwistedTube->DistanceToIn(p,v) << std::endl;
    std::cout << "Second call: " <<  solidTwistedTube->DistanceToIn(p,v) << std::endl;
    std::cout << "Third call: " << solidTwistedTube->DistanceToIn(p,v) << std::endl;

    G4ThreeVector p2( 2*twistedTubeOuterRadius,0,0);
    G4ThreeVector v2(-1,0,0);

    double d2in = solidTwistedTube->DistanceToIn(p2,v2);
    std::cout << d2in << std::endl;

    G4ThreeVector p3( 2*twistedTubeLength,0,0);
    G4ThreeVector v3(0,0,-1);
    d2in = solidTwistedTube->DistanceToIn(p3,v3);
    std::cout << d2in << std::endl;
  return 0;
}


