#include "DetectorConstruction.hh"

DetectorConstruction :: DetectorConstruction()
{}

DetectorConstruction :: ~DetectorConstruction()
{}

G4VPhysicalVolume * DetectorConstruction::Construct()
{   
    G4VisAttributes* invisible  = new G4VisAttributes(G4Colour(1.0, 1.0, 1.0));
    invisible->SetVisibility(false);

    G4GDMLParser GDMLParser;
    GDMLParser.Read("./geometry/world.gdml");
    GDMLParser.GetVolume("logicStack")  ->SetVisAttributes(invisible);
    GDMLParser.GetVolume("logicTES")    ->SetVisAttributes(G4Color(1,0,0));
    GDMLParser.GetVolume("logicMirrorBottom") ->SetVisAttributes(G4Color(0,1,0,0.5));
    GDMLParser.GetVolume("logicMirrorTop") ->SetVisAttributes(G4Color(0,1,0,0.5));

    return GDMLParser.GetWorldVolume();

}

void DetectorConstruction :: ConstructSDandField()
{}

