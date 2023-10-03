#include "PrimaryGeneratorAction.hh"

PrimaryGeneratorAction :: PrimaryGeneratorAction()
{
    particleGun = new G4ParticleGun(1);
}

PrimaryGeneratorAction :: ~PrimaryGeneratorAction()
{  
    delete particleGun;
}

void PrimaryGeneratorAction :: GeneratePrimaries(G4Event *anEvent)
{
    // Find predefined photon
    G4ParticleDefinition * photon = G4OpticalPhoton::Definition();
    // Choose photon direction randomly

        // Chose phi at random
        G4double pi     = CLHEP::pi;
        G4double phi    = G4UniformRand()*2*pi;

        // Chose theta accoring to cos^2 as Isaac suggested
        G4double theta  = std::cos(G4UniformRand()*pi);
        theta *= theta*pi;

    G4ThreeVector direction(std::sin(theta) * std::cos(phi), std::cos(theta), std::sin(theta)*std::sin(phi));


    // Choose photon direction

        // Temporarily set to origin
        G4double R      = G4UniformRand()*5.08*cm;
        G4double alpha  = G4UniformRand()*2*pi;
        
        G4double lambda = 810*nm;
        // Silicon Nitride height
        G4double nSi3N4 = 2.0458;
        G4double dSi3N4 = lambda/2/nSi3N4;
        
        G4double nSiO2  = 1.4585;
        G4double dSiO2  = lambda/2/nSiO2;



        G4int layer     = CLHEP::RandFlat::shootInt(23);
        G4int biLayer   = CLHEP::RandFlat::shootInt(1);
        G4double height = layer*(dSi3N4+dSiO2) + biLayer*dSiO2;  

        G4ThreeVector position(R*std::cos(alpha),height,R*std::sin(alpha));

    // Choose phtoon polarization

        G4ThreeVector polarization(0,1,0);
    
    // Create the photon and yeet it
    particleGun->SetParticlePosition(position);
    particleGun->SetParticleMomentumDirection(direction);
    particleGun->SetParticleMomentum(1.53 * eV);
    if(photon) particleGun->SetParticleDefinition(photon);
    particleGun->SetParticlePolarization(polarization);
    // particleGun->GeneratePrimaryVertex(anEvent);
    particleGun->GeneratePrimaryVertex(anEvent);

}

