# Automated Fertilization System: Adaptive NPK Dispenser

An Arduino-based automated system designed to create customized NPK (Nitrogen, Phosphorus, Potassium) liquid fertilizer ratios. This project aims to provide a cost-effective, precise alternative to universal fertilizers for home and small-scale gardening.

## Overview
Plants require different nutrient ratios depending on their species and environment. This system allows users to input a specific NPK ratio (e.g., 10-5-5) and a target volume. The microcontroller then calculates the required flow time for three solenoid valves to dispense the exact mixture.

## Key Features
* **Customizable Ratios:** Input any X-Y-Z ratio via Serial Monitor.
* **Automated Calculation:** Converts volume and percentage into valve timing based on calibrated flow rates.
* **Parallel Circuitry:** Uses a 4-channel relay module and 12V solenoid valves for independent operation.
* **Water Volume Indicator:** Calculates the amount of water needed to dilute the concentrate to the desired total volume.

## Hardware Components
* **Microcontroller:** Arduino Uno R3
* **Actuators:** 3x 12V Normally Closed Solenoid Valves
* **Control:** 4-Channel Relay Module
* **Power:** 12V DC Power Supply
* **Chassis:** 3D Printed CAD Model (Tinkercad)

## Circuit Logic
The system follows Kirchhoff’s Voltage Law ($V_{source} = V_1 = V_2 = V_3$) in a parallel configuration. The flow rate is determined experimentally using:
$$\text{Flow Rate} = \frac{\text{Volume (ml)}}{\text{Time (s)}}$$

## 3D Printing
The chassis and bottle mounts are 3D printable. You can find the design files in the `/hardware/stl` directory.
* **Infill:** 20%
* **Material:** PLA or PETG (PETG is better for chemical resistance with fertilizers)

## Installation & Usage
1.  **Hardware:** Wire the solenoids to the Relay Module as per the circuit diagram in `/docs`.
2.  **Software:** Upload `src/npk_dispenser.ino` to your Arduino Uno.
3.  **Operation:** * Open the Serial Monitor (9600 baud).
    * Enter ratio when prompted (Format: `10-10-10`).
    * Enter total desired volume in mL.
    * The system will dispense N, then P, then K sequentially.

## Authors
* **Alexis Cohen** - Vanier College (2025)
* **Presented to:** Dr. Jicai Pan
