////////////////////////////////////////////////////////////////
//
//     Dec-2021 E. Nacher --> SteppinAction.cc
//
//     Collects the energy deposited in sensitive volumes
//
////////////////////////////////////////////////////////////////

#include "SteppingAction.hh"
#include "EventAction.hh"
#include "G4SteppingManager.hh"
#include "G4ios.hh"

#include <iostream>

using namespace std;
using namespace CLHEP;

SteppingAction::SteppingAction(EventAction* EvAct)
:eventAction(EvAct)
{ }

SteppingAction::~SteppingAction()
{ }

void SteppingAction::UserSteppingAction(const G4Step* aStep)
{
    // collect the energy deposited in the sensitive volume
    
    const G4String currentPhysicalName
    = aStep->GetPreStepPoint()->GetPhysicalVolume()->GetName();
    
    G4double EdepStep = aStep->GetTotalEnergyDeposit() / MeV;
    
    if(currentPhysicalName == "World"){
        eventAction->energy += EdepStep;

        std::ofstream ofile("output.txt", std::ios::app);
        ofile << "\t step: " << EdepStep << " MeV" << std::endl;
        ofile.close();
    }
    return;    
}


