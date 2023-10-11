#include "PhysicsList.hh"
#include "ActionInitialization.hh"
#include "DetectorConstruction.hh"

#include "G4UImanager.hh"
#include "G4VisManager.hh"
#include "G4VisExecutive.hh"
#include "G4UIExecutive.hh"
#include "G4RunManager.hh"
#include "G4MPIsession.hh"
#include "G4MPImanager.hh"

int main(int argc, char ** argv)
{
    G4MPImanager * mpiManager   = new G4MPImanager();
    G4RunManager * runManager   = new G4RunManager();
    G4MPIsession * session      = mpiManager->GetMPIsession();
    // G4VisManager *visManager    = new G4VisExecutive();
    
    mpiManager  ->SetVerbose(0);
    session     ->SetPrompt("MPI running");
    // visManager  ->Initialize();
    runManager  ->SetUserInitialization(new DetectorConstruction());
    runManager  ->SetUserInitialization(new PhysicsList());
    runManager  ->SetUserInitialization(new ActionInitialization());
    runManager  ->Initialize();
    
    session->SessionStart();
    
    // delete visManager;
    delete mpiManager;
    delete runManager;

    return 0;
}