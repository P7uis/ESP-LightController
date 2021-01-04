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
String  RLMenuOptions[]             = {"Knight Rider", "Warning", "Inside Out", "Outside In", "Right 1", "Right 2", "Right 3", "Left 1", "Left 2", "Left 3", "BACK"};
int     RLMenuLength                = 10;
int     RLMenuPosition              = 0;
/*
// List of all roof light options
int RLOptions[] = {
    {10000, 01000, 00100, 00010, 00001, 00010, 00100, 01000},   // Knight Rider
    {10101, 01010},                                             // Warning
    {00100, 01010, 10001},                                      // Inside Out
    {10001, 01010, 00100},                                      // Outside In
    {10000, 01000, 00100, 00010, 00001},                        // Right 1
    {10000, 11000, 01100, 00110, 00011, 00001},                 // Right 2
    {00000, 10000, 11000, 11100, 11110, 11111},                 // Right 3
    {00001, 00010, 00100, 01000, 10000},                        //
    {00001, 00011, 00110, 01100, 11000, 10000},                 //
    {00000, 00001, 00011, 00111, 01111, 11111}                  //
};
// List of all delays in order
int RLDelay[] = {
    100,
    100,
    100,
    100,
    100,
    100,
    100,
    100,
    100,
    100
};
*/

// 2 - Under Glow
String  UGMenuOptions[]             = {"Smooth Cycle", "Harsh Cycle", "Police ", "American Police", "Red", "Apple Green", "Blue", "Panda Yellow", "Purple", "White", "BACK"};
int     UGMenuLength                = 10;
int     UGMenuPosition              = 0;

// 3 - Beacon
String  BeaconMenuOptions[]         = {"ON", "OFF", "BACK"};
int     BeaconMenuLength            = 2;
int     BeaconMenuPosition          = 0;