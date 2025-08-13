#include "DFRobot_DF2301Q.h"
#include <SoftwareSerial.h>

// === LED pin constants ===
const int BLUE_PIN  = 4;
const int RED_PIN   = 3;
const int GREEN_PIN = 2;

// === Software serial for UNO (change pins if needed) ===
SoftwareSerial softSerial(0, 1); // RX, TX
DFRobot_DF2301Q_UART asr(&softSerial);

void setup() {
  Serial.begin(115200);
  softSerial.begin(115200);

  // Init LEDs
  pinMode(BLUE_PIN, OUTPUT);
  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);

  // Init voice module
  while (!asr.begin()) {
    Serial.println("Trying to connect to DF2301Q...");
    delay(300);
  }
  Serial.println("Voice module connected!");

  // Settings
  asr.settingCMD(DF2301Q_UART_MSG_CMD_SET_MUTE, 0);       // Unmute
  asr.settingCMD(DF2301Q_UART_MSG_CMD_SET_VOLUME, 4);     // Volume level (0–7)
  asr.settingCMD(DF2301Q_UART_MSG_CMD_SET_WAKE_TIME, 60); // Wake time 60s

  // Optional: Play a startup phrase (change 23 to your desired CMDID)
  asr.playByCMDID(23);
}

void loop() {
  uint8_t CMDID = asr.getCMDID();

  switch (CMDID) {
    case 103: // Turn on all LEDs
      digitalWrite(BLUE_PIN, HIGH);
      digitalWrite(RED_PIN, HIGH);
      digitalWrite(GREEN_PIN, HIGH);
      Serial.println("all LED on");
      break;

    case 104: // Turn off all LEDs
      digitalWrite(BLUE_PIN, LOW);
      digitalWrite(RED_PIN, LOW);
      digitalWrite(GREEN_PIN, LOW);
      Serial.println("all LEDs off");
      break;

    case 5: // Sequential LED on
      digitalWrite(BLUE_PIN, LOW);
      digitalWrite(RED_PIN, LOW);
      digitalWrite(GREEN_PIN, LOW);
      delay(250);
      digitalWrite(BLUE_PIN, HIGH);
      delay(250);
      digitalWrite(RED_PIN, HIGH);
      delay(250);
      digitalWrite(GREEN_PIN, HIGH);
      delay(250);
      break;

    case 6: // Sequential LED off
      digitalWrite(BLUE_PIN, HIGH);
      digitalWrite(RED_PIN, HIGH);
      digitalWrite(GREEN_PIN, HIGH);
      delay(250);
      digitalWrite(BLUE_PIN, LOW);
      delay(250);
      digitalWrite(RED_PIN, LOW);
      delay(250);
      digitalWrite(GREEN_PIN, LOW);
      delay(250);
      break;

    case 7: // Blue ON
      digitalWrite(BLUE_PIN, HIGH);
      break;

    case 8: // Blue OFF
      digitalWrite(BLUE_PIN, LOW);
      break;

    case 9: // Red ON
      digitalWrite(RED_PIN, HIGH);
      break;

    case 10: // Red OFF
      digitalWrite(RED_PIN, LOW);
      break;

    case 11: // Green ON
      digitalWrite(GREEN_PIN, HIGH);
      break;

    case 12: // Green OFF
      digitalWrite(GREEN_PIN, LOW);
      break;

    case 13: // Gradual flashing sequence
      for (int i = 0; i < 10; i++) { 
        int delay_time = 25 * i;
        digitalWrite(BLUE_PIN, LOW);
        digitalWrite(RED_PIN, LOW);
        digitalWrite(GREEN_PIN, LOW);
        delay(delay_time);
        digitalWrite(BLUE_PIN, HIGH);
        delay(delay_time);
        digitalWrite(RED_PIN, HIGH);
        delay(delay_time);
        digitalWrite(GREEN_PIN, HIGH);
        delay(delay_time);
      }
      break;

    default:
      if (CMDID != 0) {
        Serial.print("Unknown CMDID = ");
        Serial.println(CMDID);
      }
  }

  delay(300);
}

