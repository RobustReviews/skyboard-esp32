#include <Arduino.h>
#include <BleComboKeyboard.h>
#include <BleComboMouse.h>
#include <IRremoteESP8266.h>
#include <IRrecv.h>
#include <IRutils.h>
#include "SkyboardKeyMap.h"  // <-- All IR codes and mappings

#define IR_RECEIVE_PIN 15

BleComboKeyboard bleKeyboard("SkyBoard", "Robust Reviews", 100);
BleComboMouse bleMouse(&bleKeyboard);

IRrecv irrecv(IR_RECEIVE_PIN);
decode_results results;

// Acceleration state
uint32_t lastDirectionCode = 0;
unsigned long lastMoveTime = 0;
int moveSpeed = 3;
const int moveSpeedMin = 3;
const int moveSpeedMax = 1000;
const unsigned long accelInterval = 200;

void sendShiftedFunction(uint8_t fnKey) {
  bleKeyboard.press(KEY_LEFT_SHIFT);
  bleKeyboard.press(fnKey);
  delay(10);
  bleKeyboard.release(fnKey);
  bleKeyboard.release(KEY_LEFT_SHIFT);
}

void resetAcceleration() {
  moveSpeed = moveSpeedMin;
  lastDirectionCode = 0;
}

void handleAcceleratedMove(const String& direction) {
  unsigned long now = millis();

  if (now - lastMoveTime > accelInterval) {
    if (moveSpeed < moveSpeedMax) {
      moveSpeed += 15;  // Accelerate
    }

    if (direction == "up") bleMouse.move(0, -moveSpeed);
    else if (direction == "down") bleMouse.move(0, moveSpeed);
    else if (direction == "left") bleMouse.move(-moveSpeed, 0);
    else if (direction == "right") bleMouse.move(moveSpeed, 0);

    lastMoveTime = now;
  }
}

void setup() {
  Serial.begin(115200);
  bleKeyboard.begin();
  bleMouse.begin();
  irrecv.enableIRIn();
  Serial.println("SkyBoard BLE Keyboard+Mouse ready.");
}

void loop() {
  if (irrecv.decode(&results)) {
    uint32_t code = results.value;
    irrecv.resume();

    if (!bleKeyboard.isConnected()) {
      Serial.println("Waiting for BLE connection...");
      return;
    }

    // New key? Reset acceleration if direction changed
    if (code != lastDirectionCode && mouseActions.count(lastDirectionCode)) {
      resetAcceleration();
    }

    // Function keys (shift+Fn)
    if (fnKeyMap.count(code)) {
      sendShiftedFunction(fnKeyMap.at(code));
      resetAcceleration();
      return;
    }

    // Standard keys
    if (keyMap.count(code)) {
      uint8_t key = keyMap.at(code);
      bleKeyboard.press(key);
      delay(20);
      bleKeyboard.release(key);
      resetAcceleration();
      return;
    }

    // Mouse actions
    if (mouseActions.count(code)) {
      const auto& action = mouseActions.at(code);

      if (action == "click") {
        bleMouse.click(MOUSE_LEFT);
        resetAcceleration();
      } else {
        handleAcceleratedMove(action);
        lastDirectionCode = code;
      }

      return;
    }
if (mediaActions.count(code)) {
  auto rptArr = mediaActions.at(code);
  MediaKeyReport rpt;                   // This is uint8_t[2]
  rpt[0] = rptArr[0];
  rpt[1] = rptArr[1];
  bleKeyboard.write(rpt);              // Write accepts MediaKeyReport
  resetAcceleration();
  return;
}


    // Unknown code
    Serial.printf("Unknown IR code: 0x%08X\n", code);
    resetAcceleration();
  }
}
