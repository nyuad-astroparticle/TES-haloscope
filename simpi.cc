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
    
    mpiManager  ->SetVerbose(0);
    runManager  ->SetUserInitialization(new DetectorConstruction());
    runManager  ->SetUserInitialization(new PhysicsList());
    runManager  ->SetUserInitialization(new ActionInitialization());
    runManager  ->Initialize();
    
    session     ->SetPrompt("MPI running \n");

    // Flags
    G4String runNumber = "1000";
    for (G4int i = 1; i < argc; i = i+2)
    {
        G4String flagValue = argv[i];
        if (flagValue == "-r") runNumber = argv[i+1];
    }

    // Run beamOn
    mpiManager  ->BeamOn(runNumber);

    // Cleaning up
    delete mpiManager;
    delete runManager;

    return EXIT_SUCCESS;
}