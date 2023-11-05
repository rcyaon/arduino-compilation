# SPDX-FileCopyrightText: 2021 ladyada for Adafruit Industries
# SPDX-License-Identifier: MIT

# bracelet utilizing circuit playground & vibration motors to mediate parkinson's tremors

"""This example flashes the little red LED when the Circuit Playground is shaken."""
import time
import board
import pwmio
from adafruit_motor import servo
from adafruit_circuitplayground import cp

# create a PWMOut object on Pin A2.
pwm = pwmio.PWMOut(board.A2, frequency=50)

# Create a servo object, my_servo.
my_motor = motor.ContinuousMotor(pwm)

while True:
    if cp.shake(shake_threshold=20):
    print("activated")
    my_motor.throttle = 1.0
    time.sleep(2.0)
    print("stop")
    my_servo.throttle = 0.0
    time.sleep(2.0)
