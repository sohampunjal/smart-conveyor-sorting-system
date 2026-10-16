# Smart Conveyor Control and Object Counting System

An Arduino-based conveyor automation simulation that uses IR sensors to detect product entry and exit, a servo motor to control a gate, and a counter to track processed objects.

## Project Overview

This project demonstrates the fundamentals of sensor-based industrial automation using Arduino. The system detects an arriving object, opens a servo-controlled gate, detects the object's departure, and updates the object count.

A timeout mechanism closes the gate if an object does not reach the exit sensor within the configured time.

## Features

- IR-based object entry detection
- Servo-controlled gate operation
- Exit sensor for object dispatch detection
- Real-time object counting through the Serial Monitor
- 5-second timeout to handle missing exit detection
- Serial command (`R` or `r`) to reset the object count
- Non-blocking timeout logic using `millis()`

## Components Used

- Arduino Uno
- 2 IR sensors
- Servo motor
- Connecting wires
- Tinkercad Circuits for simulation

## Pin Mapping

| Component | Arduino Pin |
|---|---|
| Entry IR sensor | D2 |
| Exit IR sensor | D4 |
| Servo signal | D3 |

## Working Principle

1. The entry sensor detects an arriving object.
2. The object counter increments and the servo gate opens.
3. When the exit sensor detects the object, the gate closes and the object is marked as dispatched.
4. If exit detection does not occur within 5 seconds, the gate closes and a timeout warning is printed.
5. Send `R` or `r` through the Serial Monitor to reset the counter.

**Sensor assumption:** Both IR sensors are treated as active-low, meaning detection produces a LOW signal.

## Simulation

[Open the project in Tinkercad Circuits](https://www.tinkercad.com/things/8pyqZ70zPWr-smart-conveyor-sorting-ir-sensor-servo-motor)

## Testing and Validation

| Test | Expected behaviour | Result |
|---|---|---|
| Normal object passage | Entry detected, gate opens, exit detected, gate closes | Passed |
| Exit timeout | Gate closes after 5 seconds without exit detection and prints a warning | Passed |

## Skills Demonstrated

- Arduino programming in C++
- Digital sensor interfacing
- Servo motor control
- State tracking using Boolean variables
- Time-based logic using `millis()`
- Serial communication and debugging
- Simulation-based testing

## Limitations and Future Improvements

- The current simulation models a gate and object counter, not physical conveyor-belt movement.
- The system does not classify or sort objects by type.
- Future improvements could include a DC conveyor motor, additional sensors, a display, and fault-status indicators.

## Author

**Soham Bharat Punjal**  
B.Tech Electrical and Electronics Engineering, NIT Warangal

Interested in embedded systems, robotics, and industrial automation.
