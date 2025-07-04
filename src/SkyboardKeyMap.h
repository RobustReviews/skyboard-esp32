#pragma once
#include <unordered_map>
#include <Arduino.h>
#include <BleComboKeyboard.h>  // For MediaKeyReport

// Declare mappings
extern const std::unordered_map<uint8_t, uint8_t> keyMap;
extern const std::unordered_map<uint8_t, uint8_t> fnKeyMap;
extern const std::unordered_map<uint32_t, String> mouseActions;
extern const std::unordered_map<uint32_t, std::array<uint8_t,2>> mediaActions;
