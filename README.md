# ble-speaker-sd-card

## Introduction

![](https://www.etechnophiles.com/wp-content/uploads/2021/01/component.jpg?ezimgfmt=ng:webp/ngcb40)

The pin diagram is

![](https://www.etechnophiles.com/wp-content/uploads/2021/01/Nano-BLE-Sense-pinout.jpg?ezimgfmt=ng:webp/ngcb40)

Features:

1. **Vin:** This pin can be used to power the board with a DC voltage source. If the power is fed through this pin, the USB power source is disconnected. This pin is an INPUT. Respect the voltage limits to assure the proper functionality of the board

2. **5V:** This pin outputs 5V from the board when powered from the USB connector or from the VIN pin of the board.

_Note:_ for it to work, you need to short the VBUS jumper on the back of the board.

3. **3.3V:** This pin outputs 3.3V through the on-board voltage regulator. _Note:_ for ultra low-power functionality, you should cut the 3V3 jumper on the back of the board, and use an external battery at 3V3.
LED ON: This LED is connected to the 5V input from either USB or VIN.

## Hardware Requirements

1. Arduino nano ble sense
2. SD Card Module
3. Speaker
4. Audio Amplifier


## Project Milestones

- [ ] Study the raw microphone data on-board the BLE nano sense
- [ ] Obtain raw data from the proximity sensor or IMU for motion control
- [ ] Interface SD card with MCU
- [ ] Interface audio amplifier with DAC of MCU

## PCB Design

## Precautions

1.

## References:

1. [simple audio player](https://www.arduino.cc/en/Tutorial/SimpleAudioPlayer)
2. [DS-15580-Arduino_Nano_33_BLE_Sense.pdf](https://cdn.sparkfun.com/assets/0/d/8/4/9/DS-15580-Arduino_Nano_33_BLE_Sense.pdf)
3. [arduino-nano-33-ble](https://store.arduino.cc/products/arduino-nano-33-ble)
