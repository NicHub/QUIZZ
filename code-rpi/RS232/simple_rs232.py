#!/usr/bin/env python
# -*- coding: utf-8 -*-

import serial
from time import sleep

port = "/dev/ttyUSB0"
#port = "/dev/ttyACM0"

ser = serial.Serial(port, 9600, timeout=0)

while True:
    data = ser.read(9999)
    if len(data) > 0:
        print 'Got:', data
    else:
        print 'not blocked'
        sleep(0.5)

ser.close()