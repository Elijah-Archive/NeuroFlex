# NeuroFlex Hand (Archive)

**Originally built:** ~2025 • **Status:** Archived • **Stack:** Arduino (C++), Flex Sensors, Servo Motors

## What it does
**NeuroFlex Hand** is a wearable glove + servo rig that mirrors finger motion.  
Flex sensors on each finger feed analog values into an Arduino, which drives  
servo motors that replicate the motion in a robotic hand.  

All that’s required is an **Arduino**, **five flex sensors**, and **five servos**.  
This setup was built to be easily extended into prosthetics, gesture interfaces,  
and robotics research.  

## Quickstart
1. Connect flex sensors to analog pins **A1–A5**.  
2. Connect servos to digital pins **2–6**.  
3. Upload `FlexSenseArmServo.cpp` to Arduino.  
4. Open Serial Monitor @ 9600 baud to view readings.  

## Features
- **One-to-one finger mapping** from glove to robotic hand.  
- **Serial debug output** (raw flex values or mapped servo angles).  
- **Simple mapping functions** for calibration.  
- **Expandable** for more sensors or advanced control logic.  

## File overview
- `FlexSenseArmServo.cpp` – Arduino sketch for flex sensor → servo control.  
- `ServoFlexCircuit.png` – circuit diagram of sensor/servo wiring.  
