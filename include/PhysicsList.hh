#ifndef PhysicsList_hh
#define PhysicsList_hh
#endif

#include "G4VModularPhysicsList.hh"
#include "G4OpticalPhysics.hh"

class PhysicsList : public G4VModularPhysicsList
{
    public:
        PhysicsList();
        ~PhysicsList();
};
