/////////////////////////////////////////////////////////
//                                                     //
//  Nov/2021  E. Nacher  -->  main.cc                  //
//                                                     //
/////////////////////////////////////////////////////////


#include "G4RunManager.hh"
#include "globals.hh"

#include "DetectorConstruction.hh"
#include "PhysicsList.hh"
#include "PrimaryGeneratorAction.hh"
#include "RunAction.hh"
#include "EventAction.hh"
#include "SteppingAction.hh"

#include "G4UnitsTable.hh"

#include "G4VisExecutive.hh"
#include "G4UIExecutive.hh"

#include "G4ios.hh"
#include "fstream"
#include "iomanip"

#include "G4UImanager.hh"
#include "G4UIterminal.hh"

int main(int argc, char** argv)
{
  
    // Detect interactive mode (if no arguments) and define UI session
    //
    G4UIExecutive* ui = 0;
    if ( argc == 1 ) {
        ui = new G4UIExecutive(argc, argv);
    }
    
    // Choose the Random engine
    G4Random::setTheEngine(new CLHEP::RanecuEngine);
    
    // Construct the default run manager
    //

    // Initialize visualization
    //
    G4VisManager* visManager = new G4VisExecutive;
    visManager->Initialize();
    
  
  // Construct the default run manager
  G4RunManager* runManager = new G4RunManager;

  // set mandatory initialization classes
  runManager->SetUserInitialization(new DetectorConstruction);
  runManager->SetUserInitialization(new PhysicsList);

   // set aditional user action classes
  RunAction* run = new RunAction;
  runManager->SetUserAction(run);
  EventAction* event = new EventAction(run);
  runManager->SetUserAction(event);
  runManager->SetUserAction(new SteppingAction(event));

  // Initialize G4 kernel
    runManager->Initialize();
    runManager->SetUserAction(new PrimaryGeneratorAction);

  //get the pointer to the User Interface manager 
  G4UImanager* UImanager = G4UImanager::GetUIpointer();

    // Process macro or start UI session
    //
    if ( ! ui ) {
        // batch mode
        G4String command = "/control/execute ";
        G4String fileName = argv[1];
        UImanager->ApplyCommand(command+fileName);
    }
    else {
        // interactive mode
        UImanager->ApplyCommand("/control/execute vis.mac");
        ui->SessionStart();
        delete ui;
    }

  // job termination
#ifdef G4VIS_USE
  delete visManager;
#endif

 // job termination
  delete runManager;
  
  return 0;
}


