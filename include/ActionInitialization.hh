#ifndef ActionInitialization_hh
#define ActionInitialization_hh
#endif

#include "G4VUserActionInitialization.hh"
#include "PrimaryGeneratorAction.hh"
#include "G4UserRunAction.hh"

class ActionInitialization : public G4VUserActionInitialization
{
    public:
        ActionInitialization();
        ~ActionInitialization();
        
        virtual void Build() const;
};