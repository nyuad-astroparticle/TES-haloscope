#include "PhysicsList.hh"


// Constructor
PhysicsList :: PhysicsList()
{   
    RegisterPhysics(new G4EmStandardPhysics());
    RegisterPhysics(new G4OpticalPhysics());
}

// Destructor
PhysicsList :: ~PhysicsList()
{}

