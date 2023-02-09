/////////////////////////////////////////////////////////////////////////////
//
//     Dec-2021 E. Nacher -->  PrimaryGeneratorAction.cc
//
//     To be used with the general particle source (gps) method from an
//     external macro.
//
/////////////////////////////////////////////////////////////////////////////

#include "PrimaryGeneratorAction.hh"

#include "G4Event.hh"
#include "G4ParticleGun.hh"
#include "G4ParticleTable.hh"
#include "G4ParticleDefinition.hh"

#include "G4ThreeVector.hh"
#include "globals.hh"

#include "G4ios.hh"
#include "G4GeneralParticleSource.hh" 

PrimaryGeneratorAction::PrimaryGeneratorAction()
{

  // Default values  

  particleGun = new G4GeneralParticleSource();
  particleGun->SetCurrentSourceIntensity (1);
  particleGun->SetParticlePosition(G4ThreeVector());
  
   }

PrimaryGeneratorAction::~PrimaryGeneratorAction()
{
  delete particleGun;
}

void PrimaryGeneratorAction::GeneratePrimaries(G4Event* anEvent)
{
		//create vertex
		
		particleGun->GeneratePrimaryVertex(anEvent);
}
	
