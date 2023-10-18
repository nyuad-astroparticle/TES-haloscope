#ifndef DetectorConstruction_hh
#define DetectorConstruction_hh


#include "G4VUserDetectorConstruction.hh"
#include "G4LogicalVolume.hh"
#include "G4VPhysicalVolume.hh"
#include "G4Box.hh"
#include "G4SystemOfUnits.hh"
#include "G4NistManager.hh"
#include "G4PVPlacement.hh"
#include "G4GDMLParser.hh"
#include "G4VisAttributes.hh"
#include "SensitiveDetector.hh"

class DetectorConstruction : public G4VUserDetectorConstruction
{
    public:
        DetectorConstruction(G4String filename);
        ~DetectorConstruction();
        G4VPhysicalVolume * Construct() override;
        void ConstructSDandField() override;
        SensitiveDetector * SD;

    private:
        G4LogicalVolume * TES = nullptr;
        G4String filename = nullptr;
};

#endif