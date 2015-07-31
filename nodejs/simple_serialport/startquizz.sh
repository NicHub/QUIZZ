#!/bin/bash

rm arduino_ports.json
~/quizz/code-rpi/RS232/arduino_ports.py
node readjson.js
