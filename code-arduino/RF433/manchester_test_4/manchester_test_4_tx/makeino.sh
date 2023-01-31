#!/bin/bash

INOFILE=`pwd -P`/manchester_test_3_tx.ino


/Applications/Arduino.app/Contents/MacOS/JavaApplicationStub \
	--board arduino:avr:uno                                  \
	--port /dev/tty.usbmodem1421                             \
	--verbose-build                                          \
	--upload $INOFILE


