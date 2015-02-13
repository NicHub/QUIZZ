#!/bin/bash

INOFILE=`pwd -P`/ReceiveDemo_Simple.pde


/Applications/Arduino.app/Contents/MacOS/JavaApplicationStub \
	--board arduino:avr:uno                                  \
	--port /dev/tty.usbmodem14131                            \
	--verbose-build                                          \
	--upload $INOFILE


