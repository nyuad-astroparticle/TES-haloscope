#include "DetectorConstruction.hh"

DetectorConstruction :: DetectorConstruction(G4String aFilename) : filename(aFilename)
{}

DetectorConstruction :: ~DetectorConstruction()
{}

G4VPhysicalVolume * DetectorConstruction::Construct()
{   
    G4VisAttributes* invisible  = new G4VisAttributes(G4Colour(1.0, 1.0, 1.0));
    invisible->SetVisibility(false);

    G4GDMLParser GDMLParser;
    GDMLParser.Read(filename);
    GDMLParser.GetVolume("logicStack")              ->SetVisAttributes(invisible);
    GDMLParser.GetVolume("logicMirrorTop")          ->SetVisAttributes(G4Color(0,1,0,0.5));
    
    TES = GDMLParser.GetVolume("logicTES");    
    TES ->SetVisAttributes(G4Color(1,0,0));
    
    if (GDMLParser.IsValid("parabolic"))
    {
        GDMLParser.GetVolume("logicMirrorMotherVolume") ->SetVisAttributes(invisible);
        GDMLParser.GetVolume("logicMirror")             ->SetVisAttributes(G4Color(0,0,1,0.7));
        GDMLParser.GetVolume("logicLens")               ->SetVisAttributes(G4Color(1,0,0,0.2));
    }

    if (GDMLParser.IsValid("flat"))
    {
        GDMLParser.GetVolume("logicMirrorBottom")       ->SetVisAttributes(G4Color(0,1,0,0.5));
    }

    return GDMLParser.GetWorldVolume();

}

void DetectorConstruction :: ConstructSDandField()
{
    SD = new SensitiveDetector("TES");
    TES -> SetSensitiveDetector(SD);
}

