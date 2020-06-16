// Libraries
#include <CapacitiveSensor.h>
#include <ADCTouch.h>

// Sound File
#include "pitches.h"

// Fields
// Capactive Sensor Logic (Send Pin, Recieve Pin)
// Used pin 2 as the send pin so I could stop the recieve pin at 9
//  This was done on purpose to create a gap between pins 9 and 11
//    allowing me to distinguish them apart easily
CapacitiveSensor cs_2_3 = CapacitiveSensor(2, 3);
CapacitiveSensor cs_2_4 = CapacitiveSensor(2, 4);
CapacitiveSensor cs_2_5 = CapacitiveSensor(2, 5);
CapacitiveSensor cs_2_6 = CapacitiveSensor(2, 6);
CapacitiveSensor cs_2_7 = CapacitiveSensor(2, 7);
CapacitiveSensor cs_2_8 = CapacitiveSensor(2, 8);
CapacitiveSensor cs_2_9 = CapacitiveSensor(2, 9);
// I/O Pin Definitions
#define speaker 11

void setup() {
  // put your setup code here, to run once:
  pinMode(speaker, OUTPUT);
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:

  // Sensitivity of the sensors!
  long cs_value0 = cs_2_3.capacitiveSensor(30);
  long cs_value1 = cs_2_4.capacitiveSensor(30);
  long cs_value2 = cs_2_5.capacitiveSensor(30);
  long cs_value3 = cs_2_6.capacitiveSensor(30);
  long cs_value4 = cs_2_7.capacitiveSensor(30);
  long cs_value5 = cs_2_8.capacitiveSensor(30);
  long cs_value6 = cs_2_9.capacitiveSensor(30);

  // Output of values for each sensor
  // Used this intially to figure out when to make the notes play
  Serial.print("Output 1: ");
  Serial.println(cs_value0);
  Serial.print("Output 2: ");
  Serial.println(cs_value1);
  Serial.print("Output 3: ");
  Serial.println(cs_value2);
  Serial.print("Output 4: ");
  Serial.println(cs_value3);
  Serial.print("Output 5: ");
  Serial.println(cs_value4);
  Serial.print("Output 6: ");
  Serial.println(cs_value5);
  Serial.print("Output 7: ");
  Serial.println(cs_value6);

  // Main Notes: 440 - A, 392 - G, 349 - F, 330 - E, 294 - D, 262 - C, 494 - B, May need to be adjusted
  // Look for Same Letter with different numbers...
  // Usual order of Notes: C, D, E, F, G, A, B

  // C
  if (cs_value0 > 45) {
    tone(speaker, NOTE_C4);
  }

  // C#
  if (cs_value0 > 45 && cs_value1 > 45) {
    tone(speaker, NOTE_CS4);
  }

  // D
  if (cs_value1 > 45) {
    tone(speaker, NOTE_D4);
  }

  // D#
  if (cs_value1 > 45 && cs_value2 > 45) {
    tone(speaker, NOTE_DS4);
  }

  // F
  if (cs_value2 > 45) {
    tone(speaker, NOTE_E4);
  }

  if (cs_value3 > 45) {
    tone(speaker, NOTE_F4);
  }

  // F#
  if (cs_value3 > 45 && cs_value4 > 45) {
    tone(speaker, NOTE_FS4);
  }

  // G
  if (cs_value4 > 45) {
    tone(speaker, NOTE_G4);
  }

  // G#
  if (cs_value4 > 45 && cs_value5 > 45) {
    tone(speaker, NOTE_GS4);
  }

  // A
  if (cs_value5 > 45) {
    tone(speaker, NOTE_A4);
  }

  // A#
  if (cs_value5 > 45 && cs_value6 > 45) {
    tone(speaker, NOTE_AS4);
  }

  // B
  if (cs_value6 > 45) {
    tone(speaker, NOTE_B4);
  }

  // If coins are not being touched, no sound should come out.
  if(cs_value0 == 0 && cs_value1 == 0 &&
    cs_value2 == 0 && cs_value3 == 0 &&
    cs_value4 == 0 && cs_value5 == 0 &&
    cs_value6 == 0) {
    noTone(speaker);
  }

  // Delays
  delayMicroseconds(1000);
}
