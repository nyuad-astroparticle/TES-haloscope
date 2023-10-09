#ifndef SensitiveDetector_hh
#define SensitiveDetector_hh
#endif

#include "G4VSensitiveDetector.hh"
#include "G4UserSteppingAction.hh"

class SensitiveDetector : public G4VSensitiveDetector
{
    public:
        SensitiveDetector(const G4String & name);
        ~SensitiveDetector();
        G4int photonCount;
        G4bool ProcessHits(G4Step *, G4TouchableHistory *);

    private:
};