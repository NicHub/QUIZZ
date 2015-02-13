#!/usr/bin/env python
# -*- coding: utf-8 -*-


import RPi.GPIO as GPIO
import time

bouttons = [ 4, 6, 19, 26 ]

GPIO.setmode( GPIO.BCM )

for boutton in bouttons:
    GPIO.setup( boutton, GPIO.IN, pull_up_down=GPIO.PUD_UP )

try:
    while True:
        for boutton in bouttons:
            input_state = GPIO.input( boutton )
            if input_state == False:
                print( "Boutton %d pressé" % ( boutton ) )
                time.sleep( 0.2 )
except KeyboardInterrupt:
    pass

GPIO.cleanup()
