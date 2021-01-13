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
bool MenuIndex = 0;

// Indicator of previous and next option in a menu
int SelectionPrevious = 0;
int SelectionNext = 0;

// Used for centering text on screen
int StartPosition = 0;

// These are used to scroll through strings that are longer than the screen itself
int CountCurrent = 0;
int CountPrevious = 0;
int CountNext = 0;

// 0 - Main menu
String MainMenuOptions[] = {"RoofLights", "UnderGlow", "Beacon"};
int MainMenuLength = 2;
int MainMenuPosition = 0;

// 1 - Roof Lights
int RLMenuLength = 7;
int RLMenuPosition = 0;
bool RLInitialized = false;
String RoofLights[][3] = {
    {"Static", "00000", "0"},
    {"Left", "00000", "0"},
    {"Right", "00000", "0"},
    {"Knight Rider", "10000,01000,00100,00010,00001,00010,00100,01000", "100"},
    {"Warning", "10101,01010", "200"},
    {"Inside Out", "00100,01010,10001", "200"},
    {"Outside In", "10001,01010,00100", "200"},
    {"BACK", "00000", "0"}};

// 11 - Roof Lights - Static
int RLStaticMenuLength = 5;
int RLStaticMenuPosition = 0;
bool RLStaticInitialized = false;
String RLStatic[][3] = {
    {"ON 1", "11111", "1000"},
    {"ON 2", "11011", "1000"},
    {"ON 3", "10101", "1000"},
    {"ON 4", "10001", "1000"},
    {"ON 5", "00100", "1000"},
    {"BACK", "00000", "0"}};

// 12 - Roof Lights - Left
int RLLeftMenuLength = 3;
int RLLeftMenuPosition = 0;
bool RLLeftInitialized = false;
String RLLeft[][3] = {
    {"Left 1", "00001,00010,00100,01000,10000", "300"},
    {"Left 2", "00001,00011,00110,01100,11000,10000", "300"},
    {"Left 3", "00000,00001,00011,00111,01110,11111", "300"},
    {"BACK", "00000", "0"}};

// 13 - Roof Lights - Right
int RLRightMenuLength = 3;
int RLRightMenuPosition = 0;
bool RLRightInitialized = false;
String RLRight[][3] = {
    {"Right 1", "10000,01000,00100,00010,00001", "300"},
    {"Right 2", "10000,11000,01100,00110,00011,00001", "300"},
    {"Right 3", "00000,10000,11000,11100,11110,11111", "300"},
    {"BACK", "00000", "0"}};

// 2 - Under Glow
String UGMenuOptions[] = {"Smooth Cycle", "Harsh Cycle", "Police ", "American Police", "Red", "Apple Green", "Blue", "Panda Yellow", "Purple", "White", "BACK"};
int UGMenuLength = 10;
int UGMenuPosition = 0;
bool UGInitialized = false;

// 3 - Beacon
String BeaconMenuOptions[] = {"ON", "OFF", "BACK"};
int BeaconMenuLength = 2;
int BeaconMenuPosition = 0;
