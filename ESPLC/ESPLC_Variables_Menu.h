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
int MenuIndex = 0;

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
String MainMenuOptions[] = {"RoofLights", "UnderGlow", "Extra", "Beacon"};
int MainMenuLength = 3;
int MainMenuPosition = 0;
String MainMenuSelection;

// 1 - Roof Lights
int RLMenuLength = 9;
int RLMenuPosition = 0;

String RLArray = "00000";
String RLDelay;
String RoofLights[][3] = {
    {"Static", "00000", "0"},
    {"Knight Rider", "10000,01000,00100,00010,00001,00010,00100,01000", "100"},
    {"Slow Rider", "10000,01000,00100,00010,00001,00010,00100,01000", "400"},
    {"Warning", "10101,01010", "200"},
    {"Slow Warning", "10101,01010", "500"},
    {"Inside Out", "00100,01010,10001", "200"},
    {"Outside In", "10001,01010,00100", "200"},
    {"Left", "00000", "0"},
    {"Right", "00000", "0"},
    {"BACK", "00000", "0"}};

// 11 - Roof Lights - Static
int RLStaticMenuLength = 5;
int RLStaticMenuPosition = 0;
String RLStatic[][3] = {
    {"1", "00100", "100"},
    {"2", "10001", "100"},
    {"3", "10101", "100"},
    {"4", "11011", "100"},
    {"5", "11111", "100"},
    {"BACK", "00000", "0"}};

// 12 - Roof Lights - Left
int RLLeftMenuLength = 3;
int RLLeftMenuPosition = 0;
String RLLeft[][3] = {
    {"1", "00001,00010,00100,01000,10000", "300"},
    {"2", "00011,00110,01100,11000,10001", "300"},
    {"Fill", "00000,00001,00011,00111,01111,11111", "300"},
    {"BACK", "00000", "0"}};

// 13 - Roof Lights - Right
int RLRightMenuLength = 3;
int RLRightMenuPosition = 0;
String RLRight[][3] = {
    {"1", "10000,01000,00100,00010,00001", "300"},
    {"2", "11000,01100,00110,00011,10001", "300"},
    {"Fill", "00000,10000,11000,11100,11110,11111", "300"},
    {"BACK", "00000", "0"}};

// 14 - Roof Lights - Inside Out
int RLIOMenuLength = 2;
int RLIOMenuPosition = 0;
String RLIO[][3] = {
    {"IO Single", "00100,01010,10001,00000", "200"},
    {"IO Fill", "00100,01110,11111,00000", "200"},
    {"BACK", "00000", "0"}};

// 15 - Roof Lights - Outside In
int RLOIMenuLength = 2;
int RLOIMenuPosition = 0;
String RLOI[][3] = {
    {"OI Single", "10001,01010,00100,00000", "200"},
    {"OI Fill", "10001,11011,11111,00000", "200"},
    {"BACK", "00000", "0"}};

// 2 - Under Glow
String UGMenuOptions[] = {"Smooth Cycle", "Harsh Cycle", "Police ", "American Police", "Red", "Apple Green", "Blue", "Panda Yellow", "Purple", "White", "BACK"};
int UGMenuLength = 10;
int UGMenuPosition = 0;
