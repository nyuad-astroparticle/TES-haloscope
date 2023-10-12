#ifndef RunAction_hh
#define RunAction_hh
#endif

#include "G4UserRunAction.hh"
#include "DetectorConstruction.hh"


class RunAction : public G4UserRunAction
{
    public:
        RunAction(G4VUserDetectorConstruction * detector);
        ~RunAction();

        void BeginOfRunAction(const G4Run*) override;
        void EndOfRunAction(const G4Run*)   override;

};