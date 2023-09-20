#ifndef PrimaryGeneratorAction_hh
#define PrimaryGeneratorAction_hh
#endif

#include "G4Event.hh"
#include "G4ParticleGun.hh"
#include "G4Event.hh"
#include "G4VUserPrimaryGeneratorAction.hh"
#include "G4ParticleTable.hh"
#include "G4SystemOfUnits.hh"
#include "Randomize.hh"


// Use classes as they are
class G4ParticleGun;
class G4Event;

class PrimaryGeneratorAction : public G4VUserPrimaryGeneratorAction
{
    public:
		PrimaryGeneratorAction();
		~PrimaryGeneratorAction();

    private:
        G4ParticleGun * particleGun;
};
