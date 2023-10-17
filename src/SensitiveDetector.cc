#include "SensitiveDetector.hh"

SensitiveDetector :: SensitiveDetector(const G4String & name) : G4VSensitiveDetector(name)
{
    photonCount = 0;
}

SensitiveDetector :: ~SensitiveDetector()
{}

G4bool SensitiveDetector :: ProcessHits(G4Step *aStep, G4TouchableHistory * aHistory)
{
    G4Track *aTrack = aStep -> GetTrack();
    G4String volume = aStep -> GetPreStepPoint()->GetPhysicalVolume()->GetName();
    if (volume == "logicTES_PV")
    {
        if(!aTrack->GetUserInformation()) photonCount ++;
        // G4cout << "Photon Count: " << photonCount << G4endl;
    }
    return 0;
}