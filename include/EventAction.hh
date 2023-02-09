
#ifndef EventAction_h
#define EventAction_h 1

#include "G4UserEventAction.hh"
#include "G4UserRunAction.hh"
#include "globals.hh"

class G4Event;
class RunAction;

using namespace std;

class EventAction : public G4UserEventAction
{
  public:
    EventAction(RunAction*);
    ~EventAction();

  public:
    void BeginOfEventAction(const G4Event*);
    void EndOfEventAction(const G4Event*);
    
	G4double energy;

  private:
    RunAction*                runAction;

};

#endif
