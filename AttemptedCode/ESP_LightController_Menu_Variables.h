/* Menu options edit guide.
 * 
 * MenuX[]:                         Enter all options here.
 * MenuXLenght:                     The length of the array.
 * MenuXPosition:                   The index of the value of the array. Currently is 0, so the default value is the first one in the array.
 * MenuX:                           The selected value.
 *  
 * NOTE:                            Remember to start counting length from 0.
 * 
 */

// Indicator of previous and next option in menu
int     SelectionPrevious           = 0;
int     SelectionNext               = 0;

// Main menu
String  MainMenuOptions[]           = {"RoofLights", "UnderGlow", "Beacon"};
int     MainMenuLength              = 2;
int     MainMenuPosition            = 0;
float   MainMenuOption              = MainMenuOptions[MainMenuPosition];


// TODO: change this junk
String  FilamentMaterials[]         = {"PLA", "PET-G", "Facilan C8", "ABS", "ASA", "DSM NY Cabrbon","DSM TPU", "Facilan HT", "MetalFil(Bronze/Copper)"};
float   FilamentMaterialDensities[] = {1.25, 1.27, 1.40, 1.07, 1.04, 1.17, 1.10, 1.30, 3.50};
int     FilamentMaterialLength      = 8;
int     FilamentMaterialPosition    = 0;
float   FilamentMaterialDensity     = FilamentMaterialDensities[FilamentMaterialPosition];
String  FilamentMaterial            = FilamentMaterials[FilamentMaterialPosition];

float   FilamentDiameters[]         = {2.85, 1.75};
int     FilamentDiameterLength      = 1;
int     FilamentDiameterPosition    = 0;
float   FilamentDiameter            = FilamentDiameters[FilamentDiameterPosition];
