#ifndef ActionInitialization_hh
#define ActionInitialization_hh


#include "G4VUserActionInitialization.hh"
#include "PrimaryGeneratorAction.hh"
#include "DetectorConstruction.hh"
#include "RunAction.hh"

class ActionInitialization : public G4VUserActionInitialization
{
    public:
        ActionInitialization(DetectorConstruction * detector);
        ~ActionInitialization();
        
        virtual void Build() const;

    private:
        DetectorConstruction * aDetector;
};

#endif