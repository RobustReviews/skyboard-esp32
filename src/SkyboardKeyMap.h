#pragma once
#include <map>
#include <Arduino.h>
#include <BleComboKeyboard.h>  // For MediaKeyReport

// Declare mappings
extern const std::map<uint32_t, uint8_t> keyMap;
extern const std::map<uint32_t, uint8_t> fnKeyMap;
extern const std::map<uint32_t, String> mouseActions;
extern const std::map<uint32_t, std::array<uint8_t,2>> mediaActions;