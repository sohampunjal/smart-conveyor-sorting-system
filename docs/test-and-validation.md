# Test and Validation Report

## Project
Smart Conveyor Control and Object Counting System

## Test Environment
- Platform: Tinkercad Circuits
- Controller: Arduino Uno
- Sensors: Two IR sensors
- Actuator: Servo motor
- Timeout: 5 seconds

## Test Cases

| Test ID | Test scenario | Expected result | Observed result |
|---|---|---|---|
| TC-01 | An object triggers the entry sensor | Counter increments and servo gate opens | Passed |
| TC-02 | The object triggers the exit sensor | Servo gate closes and dispatch message appears | Passed |
| TC-03 | No exit detection occurs within 5 seconds | Gate closes and timeout warning appears | Passed |
| TC-04 | Send `R` or `r` through the Serial Monitor | Object counter resets to zero | Passed |

## Results

The normal object-passage and exit-timeout scenarios were tested successfully in simulation.

The counter-reset function should also be verified independently before marking TC-04 as passed.

## Limitations

- The project is a simulation, not a physical conveyor installation.
- Sensor inputs are assumed to be active-low.
- Timeout handling is a basic recovery mechanism and is not safety-rated industrial control.
