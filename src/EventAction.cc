///////////////////////////////////////////////
//
//  Dec-2021 E. Nacher --> EventAction.cc
//
///////////////////////////////////////////////

#include "EventAction.hh"
#include "RunAction.hh"

#include "G4Event.hh"
#include "G4EventManager.hh"
#include "G4UnitsTable.hh"

#include "globals.hh"
#include "G4ios.hh"
#include "fstream"
#include "iomanip"
#include <iostream>


using namespace std;
using namespace CLHEP;

EventAction::EventAction(RunAction* RunAct)
:runAction(RunAct)
{}

EventAction::~EventAction()
{}

void EventAction::BeginOfEventAction(const G4Event*)
{
    energy = 0.;
}

void EventAction::EndOfEventAction(const G4Event* evt)
{
    std::ofstream ofile("output.txt", std::ios::app);
    ofile << "Total energy: " << energy << " MeV" << std::endl;
    ofile.close();


}



