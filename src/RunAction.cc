#include "RunAction.hh"

RunAction::RunAction(DetectorConstruction * detector) : aDetector(detector)
{}

RunAction::~RunAction()
{}

void RunAction::BeginOfRunAction(const G4Run * run)
{}

void RunAction::EndOfRunAction(const G4Run * run)
{
    G4cout << "Total photon count: " << aDetector->SD->GetPhotonCount();
}