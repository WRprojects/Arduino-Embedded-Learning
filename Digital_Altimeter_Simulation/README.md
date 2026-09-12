# Digital Altimeter Simulator

## Overview

This project is a prototype digital aircraft altimeter simulator built using an Arduino UNO R4 WiFi. It uses a potentiometer to simulate an aircraft's altitude input and then the system converts the potentiometer's analog reading into a simulated altitude and displays altitude, vertical speed, and warning information on a 16x2 LCD.

## Features

- Simulated altitude from 0–10,000 ft
- Analog input using a potentiometer
- Altitude displayed on a 16x2 LCD
- Vertical speed calculated in feet per minute (ft/min)
- High-altitude warning
- Low-altitude warning
- Selected altitude warning
- Serial output for testing and debugging
- LED warning indicator

## Hardware

- Arduino UNO R4 WiFi
- Potentiometer
- 16x2 LCD
- LED
- Resistor
- Breadboard
- Jumper wires

## System Operation

The potentiometer provides an analog input to the Arduino qne converts it into a simulated altitude from 0 to 10,000 ft.

The system then compares the current altitude with the previous altitude over a measured time interval. This change in altitude is converted into vertical speed in feet per minute.

## Altitude Conversion

The Arduino analog input produces a value from approximately 0–1023.

The simulator maps this range to:

**0–1023 ADC → 0–10,000 ft**

## Vertical Speed

Vertical speed is calculated from the change in altitude divided by the elapsed time.

The result is converted to feet per minute (ft/min).

## Warning Logic

### High Altitude Warning

A high-altitude warning is triggered at approximately:

**8,200 ft**

A hysteresis region between approximately 7,800 and 8,200 ft prevents rapid switching near the threshold.

### Selected Altitude Warning

The selected altitude is:

**1,000 ft**

A 50 ft buffer is used around the selected altitude to reduce warning chatter.

## Testing

The system was tested by manually adjusting the potentiometer and observing the calculated altitude, vertical speed, LCD output, LED warning indicator, and serial monitor output.

One observed hardware limitation was that the potentiometer did not reach an ADC reading of exactly zero at its minimum position. An ADC reading of 1 corresponds to approximately 9.8 ft using the simulator's scaling.

## Limitations

This is a simulator and does not measure actual aircraft altitude.

The potentiometer is being used as a substitute for an altitude-related sensor input. The project does not currently account for real atmospheric pressure, temperature, barometric setting, sensor noise, or aircraft dynamics.

The 16x2 LCD also limits the amount of information that can be displayed simultaneously.

## Future Development

Possible future improvements include:

- Real pressure-sensor input
- Improved signal filtering
- More advanced warning logic
- A graphical interface
- Sensor calibration
- Integration with future flight-computer projects

## Project Context

This is Project 1 in an embedded/electrical engineering project series focused on developing systems relevant to aerospace applications.