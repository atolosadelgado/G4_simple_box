
#ifndef PhysicsList_h
#define PhysicsList_h 1

#include "G4VUserPhysicsList.hh"
#include "globals.hh"

class G4VPhysicsConstructor;
class G4StepLimiterBuilder;
class PhysicsList: public G4VUserPhysicsList
{
  public:
    PhysicsList();
   ~PhysicsList();

  protected:
    // Construct particle and physics
    void ConstructParticle();
    void ConstructProcess();
    void SetCuts();
 
  private:
	
	G4VPhysicsConstructor*  emPhysicsList;
//    G4VPhysicsConstructor*  hadPhysicsList;
    G4VPhysicsConstructor*  decayPhysicsList;
    G4VPhysicsConstructor*  decayParticleList;


};


#endif

 
