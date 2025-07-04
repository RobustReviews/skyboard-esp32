#include "SkyboardKeyMap.h"

// Skyboard key map minified to 8-bit key codes (last byte only)
const std::unordered_map<uint8_t, uint8_t> keyMap = {

  // Upper Case Letters
  {0xB0, 'A'},
  {0xB1, 'B'},
  {0xB2, 'C'},
  {0xB3, 'D'},
  {0xB4, 'E'},
  {0xB5, 'F'},
  {0xB6, 'G'},
  {0xB7, 'H'},
  {0xB8, 'I'},
  {0xB9, 'J'},
  {0xBA, 'K'},
  {0xBB, 'L'},
  {0xBC, 'M'},
  {0xBD, 'N'},
  {0xBE, 'O'},
  {0xBF, 'P'},
  {0xC0, 'Q'},
  {0xC1, 'R'},
  {0xC2, 'S'},
  {0xC3, 'T'},
  {0xC4, 'U'},
  {0xC5, 'V'},
  {0xC6, 'W'},
  {0xC7, 'X'},
  {0xC8, 'Y'},
  {0xC9, 'Z'},

  // Lower Case Letters
  {0x96, 'a'},
  {0x97, 'b'},
  {0x98, 'c'},
  {0x99, 'd'},
  {0x9A, 'e'},
  {0x9B, 'f'},
  {0x9C, 'g'},
  {0x9D, 'h'},
  {0x9E, 'i'},
  {0x9F, 'j'},
  {0xA0, 'k'},
  {0xA1, 'l'},
  {0xA2, 'm'},
  {0xA3, 'n'},
  {0xA4, 'o'},
  {0xA5, 'p'},
  {0xA6, 'q'},
  {0xA7, 'r'},
  {0xA8, 's'},
  {0xA9, 't'},
  {0xAA, 'u'},
  {0xAB, 'v'},
  {0xAC, 'w'},
  {0xAD, 'x'},
  {0xAE, 'y'},
  {0xAF, 'z'},

  // Digits
  {0xF6, '0'},
  {0xF7, '1'},
  {0xF8, '2'},
  {0xF9, '3'},
  {0xFA, '4'},
  {0xFB, '5'},
  {0xFC, '6'},
  {0xFD, '7'},
  {0xFE, '8'},
  {0xFF, '9'},

  // Symbols
  {0x0E, ']'},
  {0x1A, '"'},
  {0x1D, '/'},
  {0x37, '='},
  {0x3E, ']'},
  {0x6A, '~'},
  {0x80, '>'},
  {0x91, ' '},
  {0xD1, '"'},
  {0xD2, '!'},
  {0xD4, '#'},
  {0xD5, '$'},
  {0xD6, '%'},
  {0xD7, '^'},
  {0xD8, '&'},
  {0xD9, '*'},
  {0xDB, ')'},
  {0xDC, '_'},
  {0xDD, '-'},
  {0xDE, '+'},
  {0xE0, '{'},
  {0xE1, '|'},
  {0xE2, '['},
  {0xE3, ']'},
  {0xE5, ';'},
  {0xE6, '@'},
  {0xE9, '#'},
  {0xEA, '<'},
  {0xEC, ','},
  {0xED, '.'},
  {0xEE, '?'},

  // Control Keys
  
  {0x06, KEY_F3},
  {0x21, KEY_F9},  
  {0x51, KEY_F5},
  {0x5D, KEY_LEFT_ARROW},
  {0x5E, KEY_RIGHT_ARROW},
  {0x5F, KEY_UP_ARROW},
  {0x60, KEY_DOWN_ARROW},
  {0x61, KEY_RETURN},
  {0x62, KEY_F1},
  {0x7E, KEY_F6},
  {0x84, KEY_F10},
  {0x8F, KEY_RETURN},
  {0x90, KEY_BACKSPACE},
  {0xCC, KEY_F4},


  // Whitespace/Other
  {0xE7, '\''},
  {0xF0, '\\'},

};

  const std::unordered_map<uint8_t, uint8_t> fnKeyMap = {
    {0x66, KEY_F2},   //Red 
    {0x67, KEY_F3},   //Green
    {0x68, KEY_F7},   //Yellow
    {0x69, KEY_F8},   //Blue
};


  // Media keys etc (24bit)
  const std::unordered_map<uint32_t, String> mouseActions = {
  {0xC00061, "click"}, {0xC0005C, "click"},
  {0xC00060, "down"},  {0xC00059, "down"},
  {0xC0005F, "up"},    {0xC00058, "up"},
  {0xC0005D, "left"},  {0xC0005A, "left"},
  {0xC0005E, "right"}, {0xC0005B, "right"}
};


const std::unordered_map<uint32_t, std::array<uint8_t,2>> mediaActions = {
  {0x33875D01, {0xE9, 0x00}},  // Volume Up
  {0xC2AFA5CF, {0xEA, 0x00}},  // Volume Down
  {0x96DEDE27, {0xE2, 0x00}}   // Mute
};
