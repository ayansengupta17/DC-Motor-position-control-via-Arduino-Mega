# DC Motor position control via Arduino Mega
Design and implement PID feedback controller for position control using Arduino Mega. Rotation of DC motor by 180 degrees using this controller was done with very small rise time, fast settling time and an overshoot of less than 4%

## Documentaion
This project is a part of the control and computing lab project for IIT Bombay. I have attached the relevant Chapter from our lab report. All the harware details, the mathematical model and the codes are explained in details in that report, so I am not explaining anything in this readme anymore.

## Hardware Setup

The experiment setup consist of following equipments:
1. **Motor unit**
The DC motor used in the experiment is a permanent magnet DC geared motor.
* Operating Voltage: 12V D.C. • Full load Current: 1.2 Amp. • Rated Speed: 50 rpm
* Torque: 750gm-cm

2. **Arduino Mega**
The Mega 2560 is a microcontroller board based on the ATmega2560. It has 54 digital input/output pins. Out of this 54 pins, 15 can be used as PWM outputs. It has 16 analog inputs, 4 UARTs (hardware serial ports), a 16 MHz crystal oscillator, a USB connection and a power jack with a reset button. Its technical specificatons are as follows:
* **Microcontroller:** ATmega 2560
* **Operating Voltage:** 5V DC.
* **Digital I/O Pins:** 54 (of which 15 can give PWM output) • Analog Input Pins: 16
* **DC Current per I/O Pin:** 20 mA
* **DC Current for 3.3V Pin:** 50 mA
* **Flash Memory:** 256 KB
* **SRAM:** 8 KB
* **Clock Speed:** 16 MHz

3. **L293D IC**
L293D is an H-Bridge IC that can support sufficiently high current. It can provide bidi- rectional drive currents. It can to drive inductive loads such as relays solenoids, DC and bipolar stepping motors, as well as other high-current/high-voltage loads. It has wide supply-voltage range of 4.5 V to 36 V. It provides 600 mA output current per channel and can get peak current of 1.2 A per channel. A single L293D can drive two motors at a time.
The major applications of L293D is to drive stepper motors, DC motors and latching relays drivers.
