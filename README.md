# Remote-Control-Arduino Car
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

## Libraries: 
https://github.com/nRF24/RF24

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

## Joystick Remote Controller on Breadboard
![viber_image_2024-07-16_13-36-25-386](https://github.com/user-attachments/assets/0007425b-7f91-4de2-a9e7-56f8799bc230)

## Arduino Car Prototype
![viber_image_2024-07-16_13-36-25-439](https://github.com/user-attachments/assets/0cf4a7f4-6c04-4f82-a708-6524077ae677)
