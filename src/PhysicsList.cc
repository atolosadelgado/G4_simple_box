////////////////////////////////////////////////////
//
//  Dec-2021 E. Nacher --> PhysicsList.cc
//
//  Very simple Physics List including
//  electromagnetic processes, radioactivity
//  and hadronic physics, if needed.
//
////////////////////////////////////////////////////

#include "globals.hh"
#include "PhysicsList.hh"

#include "G4EmStandardPhysics_option3.hh"
#include "G4EmLivermorePhysics.hh"
#include "G4RadioactiveDecayPhysics.hh"
#include "G4DecayPhysics.hh"

#include "G4LossTableManager.hh"

#include "G4ProcessManager.hh"
#include "G4ParticleTypes.hh"


using namespace CLHEP;

PhysicsList::PhysicsList():  G4VUserPhysicsList()
{
	defaultCutValue = 1.*um;
	SetVerboseLevel(0);
	
	//electromagnetic physics
	emPhysicsList = new G4EmStandardPhysics_option3();
    
    //decay physics
    decayParticleList = new G4DecayPhysics();
    decayPhysicsList =  new G4RadioactiveDecayPhysics();
    
    //hadronic physics
//    hadPhysicsList = new HadronPhysicsQGSP_BERT();
    
}

PhysicsList::~PhysicsList()
{}

void PhysicsList::ConstructParticle()
{
    
    // pseudo-particles
    G4Geantino::GeantinoDefinition();
    G4ChargedGeantino::ChargedGeantinoDefinition();

	// gamma, e+, e- ...
	emPhysicsList -> ConstructParticle();
    decayParticleList ->ConstructParticle();
//    hadPhysicsList    ->ConstructParticle();
    
}

void PhysicsList::ConstructProcess()
{
    
  	AddTransportation();
	
    emPhysicsList -> ConstructProcess();
    return;

    decayParticleList->ConstructProcess();
    decayPhysicsList->ConstructProcess();
//    hadPhysicsList->ConstructProcess();
    
    
}

void PhysicsList::SetCuts()
{
    // default cut value for all particle types 
	SetCutsWithDefault();
	
	if (verboseLevel>0) DumpCutValuesTable();

}


