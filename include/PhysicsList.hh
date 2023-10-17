#ifndef PhysicsList_hh
#define PhysicsList_hh


#include "G4VModularPhysicsList.hh"
#include "G4OpticalPhysics.hh"
#include "G4EmStandardPhysics.hh"

class PhysicsList : public G4VModularPhysicsList
{
    public:
        PhysicsList();
        ~PhysicsList();
};

#endif