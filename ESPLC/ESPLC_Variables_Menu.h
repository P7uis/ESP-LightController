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

// Use this number to indicate the current menu to interact with
bool     MenuIndex                  = 0;

// Indicator of previous and next option in a menu
int     SelectionPrevious           = 0;
int     SelectionNext               = 0;

// Used for centering text on screen
int     StartPosition               = 0;

// These are used to scroll through strings that are longer than the screen itself 
int     CountCurrent                = 0;
int     CountPrevious               = 0;
int     CountNext                   = 0;

// 0 - Main menu
String  MainMenuOptions[]           = {"RoofLights", "UnderGlow", "Beacon"};
int     MainMenuLength              = 2;
int     MainMenuPosition            = 0;

// 1 - Roof Lights
String  RLMenuOptions[]             = {"Pattern 1", "Pattern 2", "Pattern 3", "Pattern 4", "Pattern 5", "Pattern 6", "Pattern 7", "BACK"};
int     RLMenuLength                = 7;
int     RLMenuPosition              = 0;

// 2 - Under Glow
String  UGMenuOptions[]             = {"Preset 1", "Preset 2", "Preset 3", "Preset 4", "Preset 5", "Preset 6", "BACK"};
int     UGMenuLength                = 6;
int     UGMenuPosition              = 0;

// 3 - Beacon
String  BeaconMenuOptions[]         = {"ON", "OFF", "BACK"};
int     BeaconMenuLength            = 2;
int     BeaconMenuPosition          = 0;