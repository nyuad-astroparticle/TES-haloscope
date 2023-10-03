#ifndef PrimaryGeneratorAction_hh
#define PrimaryGeneratorAction_hh
#endif

#include "G4Event.hh"
#include "G4ParticleGun.hh"
#include "G4Event.hh"
#include "G4VUserPrimaryGeneratorAction.hh"
#include "G4ParticleTable.hh"
#include "G4SystemOfUnits.hh"
#include "G4OpticalPhoton.hh"
#include "Randomize.hh"

#include <iostream>
#include <cmath>


// Use classes as they are
class G4ParticleGun;
class G4Event;

class PrimaryGeneratorAction : public G4VUserPrimaryGeneratorAction
{
    public:
		PrimaryGeneratorAction();
		~PrimaryGeneratorAction();
    virtual void GeneratePrimaries(G4Event*);

    private:
        G4ParticleGun * particleGun;
};
