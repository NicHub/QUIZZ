#!/bin/bash

shopt -s expand_aliases
alias avr-objdump='/Applications/Arduino.app/Contents/Resources/Java/hardware/tools/avr/bin/avr-objdump'

# SKETCH=manchester_test_3_rx
# SKETCH=blink_minimal
# SKETCH=test_define
# ELF="/Users/nico/Documents/Arduino_Build/$SKETCH/$SKETCH.elf"

ELF=/var/folders/3l/c6_nv3414rb_sxjkb8z9z1fr0000gn/T/build2496477641271170334.tmp/manchester_test_5_tx.cpp.elf

OUT="$SKETCH"_elf32-avr_007.c

OUT=empty.c

avr-objdump -S -Tdata $ELF > $OUT

if which open >/dev/null; then
    open $OUT
fi

