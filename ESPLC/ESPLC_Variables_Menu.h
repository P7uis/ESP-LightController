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

// List of menu options
bool MainMenu = true;

// Indicator of previous and next option in a menu
int     SelectionPrevious           = 0;
int     SelectionNext               = 0;

// Used for centering text on screen
int StartPosition = 0;

// These are used to scroll through strings that are longer than the screen itself 
int CountCurrent = 0;
int CountNext = 0;
int CountPrevious = 0;

// Main menu
String  MainMenuOptions[]           = {"RoofLights", "UnderGlow", "Beacon", "ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
int     MainMenuLength              = 3;
int     MainMenuPosition            = 0;
