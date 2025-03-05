# IR-Based Line Follower Robot (PID & PWM) - Arduino Uno

## Overview
This project is an **IR-based Line Follower Robot** that uses **Proportional-Integral-Derivative (PID) control** and **Pulse Width Modulation (PWM)** for precise and smooth line tracking. The robot follows a **black line** on a white surface using an array of IR sensors and adjusts its speed dynamically for efficient navigation.

## Features
- **PID Control**: Ensures smooth and accurate line following with minimal oscillations.
- **PWM-Based Motor Control**: Adjusts motor speed for precise movement.
- **IR Sensor Array**: Detects the position of the black line relative to the robot.
- **Arduino Uno**: Serves as the brain of the system.
- **Motor Driver (L298N/L293D)**: Controls motor speed and direction.
- **Tunable PID Parameters**: Allows fine-tuning for different environments.

## Components Used
- **Arduino Uno**
- **IR Sensor Array** (e.g., QTR-8A, TCRT5000 modules)
- **Motor Driver Module** (L298N or L293D)
- **DC Motors with Wheels**
- **Chassis**
- **Battery Pack (2x 18650 Li-ion)**

## Working Principle
1. The IR sensors detect the position of the black line.
2. The sensor readings are processed to determine the error (deviation from the center).
3. The PID algorithm calculates the correction needed to align the robot.
4. PWM signals are sent to the motor driver to adjust the speed of each motor.
5. The robot continuously corrects its path to stay on the line.

## PID Control Algorithm
The PID controller helps minimize the deviation from the line by calculating:
- **Proportional (P)**: Reacts to the current error.
- **Integral (I)**: Accounts for past errors to reduce steady-state error.
- **Derivative (D)**: Predicts future errors for smoother corrections.

Formula:
```
Correction = (Kp * Error) + (Ki * Integral) + (Kd * Derivative)
```
Where:
- `Kp`, `Ki`, and `Kd` are tunable constants.
- `Error` is the deviation from the center.
- `Integral` accumulates past errors.
- `Derivative` predicts the rate of error change.

## Code Implementation
The main code consists of:
- **Reading IR sensor values**
- **Calculating the PID correction**
- **Adjusting motor speeds using PWM**

## Tuning the PID Values
- **Increase `Kp`** if the robot is slow to correct.
- **Increase `Ki`** if the robot has steady-state errors.
- **Increase `Kd`** if the robot overshoots and oscillates too much.

## Assembly & Calibration
1. Assemble the robot chassis and mount components.
2. Wire the circuit as per the diagram.
3. Upload the Arduino code.
4. Start with low `Ki` and `Kd` values, then increase gradually.
5. Test and adjust until smooth line following is achieved.

## Future Improvements
- **Obstacle Avoidance**: Integrate ultrasonic sensors.
- **Speed Optimization**: Implement dynamic speed control.
- **Wireless Control**: Add Bluetooth/Wi-Fi for remote tuning.

## License
This project is open-source under the **MIT License**.

## Author
[Hiran Geeth] *(Hiran Geeth)*

Feel free to contribute or suggest improvements!

