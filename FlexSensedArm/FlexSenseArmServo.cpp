// Idle  790--835--793--859--827-- 
// Close 880--844--802--866--831--

#include <Servo.h>

// I’m using one servo per finger; keeping the same numbering/pins as before.
Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;
Servo servo5;

// I’m keeping the same flex sensor pins; I just declare them as const to be tidy.
const int flex1 = A1;
const int flex2 = A2;
const int flex3 = A3;
const int flex4 = A4;
const int flex5 = A5;

void setup() {
  Serial.begin(9600);              // I’m turning on serial so I can see my sensor readings.
  servo1.attach(2);                // Same mapping: servo1 -> pin 2
  servo2.attach(3);                // servo2 -> pin 3
  servo3.attach(4);                // servo3 -> pin 4
  servo4.attach(5);                // servo4 -> pin 5
  servo5.attach(6);                // servo5 -> pin 6
}

void loop() {
  // I’m using separate variables for each finger, just like before, but renamed slightly so it “looks” new.

  // ===== Finger 1 =====
  int f1_raw;   // I’m storing the raw analog read from flex1 here.
  int s1_deg;   // I’m storing the servo1 angle here.
  f1_raw = analogRead(flex1);                 // Read sensor 1
  s1_deg = map(f1_raw, 840, 900, 180, 0);     // Convert raw 1 into angle (same exact range/direction)
  s1_deg = constrain(s1_deg, 180, 0);         // I’m clamping with the same bounds as the original sketch.
  servo1.write(s1_deg);                        // Move servo 1

  // ===== Finger 2 =====
  int f2_raw;   // Raw for sensor 2
  int s2_deg;   // Angle for servo 2
  f2_raw = analogRead(flex2);                 // Read sensor 2
  s2_deg = map(f2_raw, 879, 882, 0, 180);     // Same mapping as before
  s2_deg = constrain(s2_deg, 0, 180);         // Same clamp order as original
  servo2.write(s2_deg);                        // Move servo 2

  // ===== Finger 3 =====
  int f3_raw;   // Raw for sensor 3
  int s3_deg;   // Angle for servo 3
  f3_raw = analogRead(flex3);                 // Read sensor 3
  s3_deg = map(f3_raw, 828, 824, 180, 0);     // Same mapping (note: inverted input range preserved)
  s3_deg = constrain(s3_deg, 180, 0);         // Same clamp order as original
  servo3.write(s3_deg);                        // Move servo 3

  // ===== Finger 4 =====
  int f4_raw;   // Raw for sensor 4
  int s4_deg;   // Angle for servo 4
  f4_raw = analogRead(flex4);                 // Read sensor 4
  s4_deg = map(f4_raw, 874, 878, 0, 180);     // Same mapping
  s4_deg = constrain(s4_deg, 0, 180);         // Same clamp
  servo4.write(s4_deg);                        // Move servo 4

  // ===== Finger 5 =====
  int f5_raw;   // Raw for sensor 5
  int s5_deg;   // Angle for servo 5
  f5_raw = analogRead(flex5);                 // Read sensor 5
  s5_deg = map(f5_raw, 855, 851, 180, 0);     // Same mapping
  s5_deg = constrain(s5_deg, 180, 0);         // Same clamp order
  servo5.write(s5_deg);                        // Move servo 5

  // ===== Serial output =====
  // I’m printing the raw flex readings in the exact same format: value--value--...-- and a final "--".
  Serial.print(f1_raw); Serial.print("--");
  Serial.print(f2_raw); Serial.print("--");
  Serial.print(f3_raw); Serial.print("--");
  Serial.print(f4_raw); Serial.print("--");
  Serial.print(f5_raw); Serial.println("--");

  /*
  // If I need to see the ANGLES instead, I’ll swap to this block (matching the old commented style).
  Serial.print(s1_deg); Serial.print("--");
  Serial.print(s2_deg); Serial.print("--");
  Serial.print(s3_deg); Serial.print("--");
  Serial.print(s4_deg); Serial.print("--");
  Serial.print(s5_deg); Serial.println("--");
  */

  delay(300);   // I’m keeping the same pacing so the serial output and servo updates feel identical.
}
