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

// Main menu
String  MainMenuOptions[]           = {"RoofLights", "UnderGlow", "Beacon"};
int     MainMenuLength              = 2;
int     MainMenuPosition            = 0;
String  MainMenuOption              = MainMenuOptions[MainMenuPosition];
