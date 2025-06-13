#include "SkyboardKeyMap.h"

// Media key constants (structs, not macros)
const MediaKeyReport MEDIA_KEY_VOLUME_UP   = {0xE9, 0x00};
const MediaKeyReport MEDIA_KEY_VOLUME_DOWN = {0xEA, 0x00};
const MediaKeyReport MEDIA_KEY_MUTE        = {0xE2, 0x00};

// Key mappings (letters, digits, basic controls)
const std::map<uint32_t, uint8_t> keyMap = {
  {0xC000A6, 'q'}, {0xC000AC, 'w'}, {0xC0009A, 'e'}, {0xC000A7, 'r'},
  {0xC000A9, 't'}, {0xC000AE, 'y'}, {0xC000AA, 'u'}, {0xC0009E, 'i'},
  {0xC000A4, 'o'}, {0xC000A5, 'p'}, {0xC00096, 'a'}, {0xC000A8, 's'},
  {0xC00099, 'd'}, {0xC0009B, 'f'}, {0xC0009C, 'g'}, {0xC0009D, 'h'},
  {0xC0009F, 'j'}, {0xC000A0, 'k'}, {0xC000A1, 'l'}, {0xC000AF, 'z'},
  {0xC000AD, 'x'}, {0xC00098, 'c'}, {0xC000AB, 'v'}, {0xC00097, 'b'},
  {0xC000A3, 'n'}, {0xC000A2, 'm'},

  {0xC000F7, '1'}, {0xC000F8, '2'}, {0xC000F9, '3'}, {0xC000FA, '4'},
  {0xC000FB, '5'}, {0xC000FC, '6'}, {0xC000FD, '7'}, {0xC000FE, '8'},
  {0xC000FF, '9'}, {0xC000F6, '0'},

    // Uppercase letters
  {0xC000B0, 'A'}, {0xC000B1, 'B'}, {0xC000B2, 'C'}, {0xC000B3, 'D'},
  {0xC000B4, 'E'}, {0xC000B5, 'F'}, {0xC000B6, 'G'}, {0xC000B7, 'H'},
  {0xC000B8, 'I'}, {0xC000B9, 'J'}, {0xC000BA, 'K'}, {0xC000BB, 'L'},
  {0xC000BC, 'M'}, {0xC000BD, 'N'}, {0xC000BE, 'O'}, {0xC000BF, 'P'},
  {0xC000C0, 'Q'}, {0xC000C1, 'R'}, {0xC000C2, 'S'}, {0xC000C3, 'T'},
  {0xC000C4, 'U'}, {0xC000C5, 'V'}, {0xC000C6, 'W'}, {0xC000C7, 'X'},
  {0xC000C8, 'Y'}, {0xC000C9, 'Z'},


    //Symbols
   {0xC000D2, '!'}, {0xC000D1, '"'}, {0xC000D4, '#'}, {0xC000D5, '$'},
  {0xC000D6, '%'}, {0xC000D7, '^'}, {0xC000D9, '*'}, {0xC000DB, ')'},
  {0xC000DD, '-'}, {0xC000DC, '_'}, {0x300037, '='}, {0xC000DE, '+'},
  {0xC000E6, '@'}, {0xC000E0, '{'}, {0xC000E, ']'}, {0x90FEAFA6, '}'},
  {0xC000E1, '|'}, {0xC000E5, ';'}, {0xC000E7, '\''}, {0x18001A, '"'},
  {0xC000EC, ','}, {0xC000ED, '.'}, {0xC000EE, '?'}, {0xC000EA, '<'},
  {0x8C46B680, '>'}, {0xF726166A, '~'}, {0x5F15D21D, '/'}, {0xC000F0, '\\'},
  {0xC000E9, '#'},



  //F KEYS
    // F keys
  {0xC00062, KEY_F1}, {0x600032, KEY_F2}, {0xC0006, KEY_F3}, {0xC000CC, KEY_F4},
  {0x6DA4B451, KEY_F5}, {0xC0007E, KEY_F6}, {0xC00080, KEY_F7}, {0xC0002, KEY_F8},
  {0xC00021, KEY_F9}, {0xC00084, KEY_F10}, {0xA90, KEY_F11}, {0x290, KEY_F12},

  {0xC00091, ' '}, {0xC0008F, KEY_RETURN}, {0xC00090, KEY_BACKSPACE}
};

// Shifted function keys (F2–F8)
const std::map<uint32_t, uint8_t> fnKeyMap = {
  {0xC00066, KEY_F2},  // RED
  {0xC00067, KEY_F3},  // GREEN
  {0xC00068, KEY_F7},  // YELLOW
  {0xC00069, KEY_F8},  // BLUE
};

// Mouse movement and clicks  -- Two versions as the normal remote uses different codes for some f'kin reason?!
const std::map<uint32_t, String> mouseActions = {
  {0xC00061, "click"}, {0xC0005C, "click"},
  {0xC00060, "down"},  {0xC00059, "down"},
  {0xC0005F, "up"},    {0xC00058, "up"},
  {0xC0005D, "left"},  {0xC0005A, "left"},
  {0xC0005E, "right"}, {0xC0005B, "right"}
};


const std::map<uint32_t, std::array<uint8_t,2>> mediaActions = {
  {0x33875D01, {0xE9, 0x00}},  // Volume Up
  {0xC2AFA5CF, {0xEA, 0x00}},  // Volume Down
  {0x96DEDE27, {0xE2, 0x00}}   // Mute
};