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
    G4RunManager * runManager = new G4RunManager();
    
    runManager->SetUserInitialization(new DetectorConstruction());
    runManager->SetUserInitialization(new PhysicsList());
    runManager->SetUserInitialization(new ActionInitialization());
    runManager->Initialize();
    runManager->SetUserAction(new G4UserRunAction());    

    G4UIExecutive *ui = new G4UIExecutive(argc, argv);
    G4VisManager *visManager = new G4VisExecutive();
    visManager->Initialize();
    G4UImanager *uiManager = G4UImanager::GetUIpointer();
    uiManager->ApplyCommand("/vis/open OGL");
    uiManager->ApplyCommand("/vis/drawVolume");
    uiManager->ApplyCommand("/vis/viewer/set/autoRefresh true");
    uiManager->ApplyCommand("/vis/scene/add/trajectories smooth");
    uiManager->ApplyCommand("/vis/scene/endOfEventAction accumulate -1");
    // uiManager->ApplyCommand("/vis/modeling/trajectories/create/drawByParticleID");
    // uiManager->ApplyCommand("/vis/scene/add/axes");

    ui -> SessionStart();
    delete ui;
    delete visManager;
    delete runManager;

    return 0;
}