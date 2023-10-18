#include "PhysicsList.hh"
#include "ActionInitialization.hh"
#include "DetectorConstruction.hh"

#include "G4UImanager.hh"
#include "G4VisManager.hh"
#include "G4VisExecutive.hh"
#include "G4UIExecutive.hh"
#include "G4RunManager.hh"

int main(int argc, char ** argv)
{
    // Flags
    G4String world = "./geometry/worldPM.gdml";
    for (G4int i = 1; i < argc; i = i+2)
    {
        G4String flagValue = argv[i];
        if (flagValue == "-g") world = argv[i+1];
    }

    G4RunManager * runManager = new G4RunManager();
    
    DetectorConstruction * detector = new DetectorConstruction(world);

    runManager  ->SetUserInitialization(detector);
    runManager  ->SetUserInitialization(new PhysicsList());
    runManager  ->SetUserInitialization(new ActionInitialization(detector));
    runManager  ->Initialize();
    // runManager->SetUserAction(new G4UserRunAction());    

    G4UIExecutive *ui = new G4UIExecutive(argc, argv);
    G4VisManager *visManager = new G4VisExecutive();
    visManager->Initialize();
    G4UImanager *uiManager = G4UImanager::GetUIpointer();
    uiManager->ApplyCommand("/vis/open OGL");
    uiManager->ApplyCommand("/vis/drawVolume");
    uiManager->ApplyCommand("/vis/viewer/set/autoRefresh true");
    uiManager->ApplyCommand("/vis/scene/add/trajectories smooth");
    uiManager->ApplyCommand("/vis/scene/endOfEventAction accumulate -1");
    uiManager->ApplyCommand("/vis/verbose 0");
    uiManager->ApplyCommand("/run/verbose 0");


    ui -> SessionStart();
    delete ui;
    delete visManager;
    delete runManager;

    return 0;
}