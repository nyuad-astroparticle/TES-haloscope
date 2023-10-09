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
        G4double theta  = std::sin(G4UniformRand()*pi)*std::sin(G4UniformRand()*pi);
        theta *= theta*pi;
        // G4double theta  = 110*deg;

    G4ThreeVector direction(std::sin(theta) * std::cos(phi), std::cos(theta), std::sin(theta)*std::sin(phi));


    // Choose photon direction

        // Temporarily set to origin
        G4double R      = G4UniformRand()*5.08*cm/2;
        G4double alpha  = G4UniformRand()*2*pi;
        G4double numberOfLayers = 23;
        
        G4double lambda = 1*mm;
        // Silicon Nitride height
        G4double nSi3N4 = 2.0053;
        G4double dSi3N4 = lambda/2/nSi3N4;
        
        G4double nSiO2  = 1.4607;
        G4double dSiO2  = lambda/2/nSiO2;



        G4int layer     = CLHEP::RandFlat::shootInt(1,numberOfLayers);
        G4int biLayer   = CLHEP::RandFlat::shootInt(2);
        G4double height = (-numberOfLayers/2 + layer)*(dSi3N4+dSiO2) + biLayer*dSiO2;  

        G4ThreeVector position(R*std::cos(alpha),height,R*std::sin(alpha));

    // Choose photon polarization

        G4ThreeVector polarization(1,1,1);
    
    // Create the photon and yeet it
    particleGun->SetParticlePosition(position);
    particleGun->SetParticleMomentumDirection(direction);
    particleGun->SetParticleMomentum(1.53 * eV);
    if(photon) particleGun->SetParticleDefinition(photon);
    particleGun->SetParticlePolarization(polarization);
    // particleGun->GeneratePrimaryVertex(anEvent);
    particleGun->GeneratePrimaryVertex(anEvent);

}

