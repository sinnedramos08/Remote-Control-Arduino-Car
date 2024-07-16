# Remote-Control-Arduino Car

This project features codes used for the remote-controlled Arduino 2WD Car, utilizing NRF24L01 as the wireless transceiver module and the L298N for the motor control driver. 

- **Receiver**: contains the code for the Joystick Remote Controller
- **Transmitter**: contains code uploaded for the Arduino Car.

Both the controller and the Arduino car utilized the NRF24L01 wireless module for wireless communication. The L298N motor driver controls the two DC motors, allowing for forward, backward, left, and right movements. 

## Hardware Components used for Joystick Remote Controller
1. Arduino Nano
2. NRF24L01 for transmitting joystick control signals
3. Dual Axis Joystick Module
4. Battery or Powerbank (5 VDC)

## Hardware Components used for Arduino Car
1. Arduino Nano
2. NRF24L01 for receiving joystick control signals
3. L298N Motor Driver
4. 2WD Robot Car Chassis
5. 2 18650 Lithium-ion 3.7V battery

## Software Setup
- Arduino IDE: Download and install from [Arduino's official website](https://www.arduino.cc/en/software).
- Libraries: Ensure you have the necessary libraries installed, such as RF24 for the NRF24L01 module. You can install using this [link](https://github.com/nRF24/RF24)

## Wiring Diagram for Joystick Remote Controller
![Joystick Schematic](https://github.com/user-attachments/assets/66091d25-dc25-4db1-84fe-d9929f72de23)

Joystick to Arduino Nano Interface:
1. VRx -> A4
2. VRy -> A1

NRF24L01 to Arduino Nano Interface:
1. SCK -> D13
2. CE -> D7
3. CSN -> D8
4. MOSI -> D11
5. MISO -> D12

## Wiring Diagram for L298N Motor Driver
![L298N Schematic](https://github.com/user-attachments/assets/43abd3d0-466a-4b76-b3ff-d04c952eee42)

1. ENA -> D9
2. ENB -> D6
3. IN1 -> D2
4. IN2 -> D3
5. IN3 -> D4
6. IN4 -> D5

## Code Explanation

### Joystick Remote Controller (Receiver)

### Arduino Car (Transmitter)

## Joystick Remote Controller on Breadboard
![viber_image_2024-07-16_13-36-25-386](https://github.com/user-attachments/assets/0007425b-7f91-4de2-a9e7-56f8799bc230)

## Arduino Car Prototype
![viber_image_2024-07-16_13-36-25-439](https://github.com/user-attachments/assets/0cf4a7f4-6c04-4f82-a708-6524077ae677)

## Demonstration


## References and Resources
- [In-Depth Interface L298N DC Motor Driver Module to Arduino](https://lastminuteengineers.com/l298n-dc-stepper-driver-arduino-tutorial/)
- [nRF24L01 Library Documentation](https://nrf24.github.io/RF24/)
