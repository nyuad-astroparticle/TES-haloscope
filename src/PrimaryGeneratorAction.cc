#include "PrimaryGeneratorAction.hh"

PrimaryGeneratorAction :: PrimaryGeneratorAction()
{
    // Find predefined proton
    G4ParticleDefinition * photon = G4ParticleTable::GetParticleTable()->FindParticle("opticalphoton");

    // Choose a photon direction randomly

    
    // Create the photon and yeet it
    particleGun = new G4ParticleGun();
    particleGun->SetParticleDefinition(photon);
    particleGun->SetParticleEnergy(1.53 * eV);
}

PrimaryGeneratorAction :: ~PrimaryGeneratorAction()
{}