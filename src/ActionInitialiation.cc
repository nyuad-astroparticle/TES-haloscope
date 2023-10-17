#include "ActionInitialization.hh"

ActionInitialization :: ActionInitialization(DetectorConstruction * detector) : aDetector(detector)
{}
ActionInitialization :: ~ActionInitialization()
{}

void ActionInitialization :: Build() const 
{
    SetUserAction(new RunAction(aDetector));

    PrimaryGeneratorAction *generator = new PrimaryGeneratorAction();
    SetUserAction(generator);
};