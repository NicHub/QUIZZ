#!/bin/bash

INOFILE=`pwd -P`/TypeA_WithDIPSwitches_Lightweight.ino


/Applications/Arduino.app/Contents/MacOS/JavaApplicationStub \
	--board arduino:avr:uno                                  \
	--port /dev/tty.usbmodem1421                            \
	--verbose-build                                          \
	--upload $INOFILE


