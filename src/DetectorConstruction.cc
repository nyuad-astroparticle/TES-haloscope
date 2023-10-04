#include "DetectorConstruction.hh"

DetectorConstruction :: DetectorConstruction()
{}

DetectorConstruction :: ~DetectorConstruction()
{}

G4VPhysicalVolume * DetectorConstruction::Construct()
{   
    // G4NistManager * nist = G4NistManager::Instance();
    // G4Material *worldMaterial = nist -> FindOrBuildMaterial("G4_Galactic");
    // G4Box * solidWorld = new G4Box("solidWorld", 10*cm, 10*cm, 10*cm);
    // G4LogicalVolume * logicWorld = new G4LogicalVolume(solidWorld, worldMaterial, "logicWorld");
    // G4VPhysicalVolume * physWorld = new G4PVPlacement(0,G4ThreeVector(0,0,0), logicWorld, "physWorld", 0,false,0,true);
    // return physWorld;
    G4GDMLParser GDMLParser;
    GDMLParser.Read("./geometry/world.gdml");
    return GDMLParser.GetWorldVolume();
}

void DetectorConstruction :: ConstructSDandField()
{}

