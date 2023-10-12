#ifndef ActionInitialization_hh
#define ActionInitialization_hh
#endif

#include "G4VUserActionInitialization.hh"
#include "PrimaryGeneratorAction.hh"
#include "G4UserRunAction.hh"
// #include "DetectorConstruction.hh"
#include "RunAction.hh"

class ActionInitialization : public G4VUserActionInitialization
{
    public:
        ActionInitialization(G4VUserDetectorConstruction * detector);
        ~ActionInitialization();
        
        virtual void Build() const;

    private:
        G4VUserDetectorConstruction * detector;
};