# Flysky PPM Parser Library

A lightweight Arduino library for parsing PPM (Pulse Position Modulation) signals commonly used in remote control systems.

## Table of Contents
- [Introduction](#introduction)
- [Features](#features)
- [Installation](#installation)
- [API Reference](#api-reference)
- [License](#license)

## Introduction
This library provides a platform-independent solution for parsing PPM signals from remote controllers. It efficiently captures and processes pulse lengths for multiple channels, making it suitable for robotics, drones, and other RC applications.

## Features
- Supports up to 20 channels
- Automatic pulse detection and storage
- Interrupt-driven signal processing
- Platform independent (works with any Arduino-compatible board)

## Installation

1.  **Download**: Download this repository as a `.zip` file from GitHub.
2.  **Install in Arduino IDE**:
    - Open the Arduino IDE.
    - Go to `Sketch` -> `Include Library` -> `Add .ZIP Library...`.
    - Select the downloaded `.zip` file.
3.  **Include**: Add `#include <Flysky.h>` to the top of your sketch.

## API Reference

### Class FLYSKY

#### Constructor
```cpp
FLYSKY(uint8_t ppm_pin, uint8_t no_of_channels);
```
- **Parameters**
  - `ppm_pin`: The digital pin where the PPM signal is connected.
  - `no_of_channels`: Number of channels in the PPM signal.

#### Methods

##### attachInterrupt()
```cpp
void attachInterrupt();
```
- Sets up the hardware interrupt for PPM signal processing.

##### ppmInterrupt()
```cpp
static void ppmInterrupt();
```
- **Description**: Interrupt service routine for processing PPM signals.
- **Details**:
  - Measures pulse lengths
  - Detects sync pulses (>=3000µs)
  - Stores channel values in `_ppmValues`

##### getPpmValue()
```cpp
uint16_t getPpmValue(uint8_t channel);
```
- **Description**: Returns the PPM value for a specific channel.
- **Parameters**:
  - `channel`: Channel number (1-based index).
- **Return**:
  - PPM pulse length in microseconds if valid channel, otherwise 0.

## License
This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.
