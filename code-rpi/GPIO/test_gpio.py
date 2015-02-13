#!/usr/bin/env python
# -*- coding: utf-8 -*-

import RPi.GPIO as GPIO
import time

LedPin = 12

def blink( pin ):
    GPIO.output( pin, GPIO.HIGH )
    time.sleep( 0.1 )
    GPIO.output( pin, GPIO.LOW )
    time.sleep( 0.1 )
    return

GPIO.setmode( GPIO.BOARD )
GPIO.setup( LedPin, GPIO.OUT )

try:
    while True:
        blink( LedPin )
except KeyboardInterrupt:
    pass

GPIO.cleanup()


