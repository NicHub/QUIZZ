#!/bin/bash

# Arduino CLI man page
# https://github.com/arduino/Arduino/blob/master/build/shared/manpage.adoc
# Il faut indiquer le chemin complet vers le croquis pour que ça fonctionne !


SCRIPT_PATH=`pwd`


TIMEFORMAT='time : %3R s'
shopt -s expand_aliases
ARDUINO_VERSION=2
case "$ARDUINO_VERSION" in
1)  alias arduino='/Applications/Arduino_1.6.1.app/Contents/MacOS/JavaApplicationStub' ;;
*)  alias arduino='/Applications/Arduino.app/Contents/MacOS/Arduino' ;;
esac





function UPLOAD_LOGIC_ANALYSER
{
    ARDUINO_PORT=$1
    INOFILE_IN=$HOME/Documents/programmation/Arduino/logic_analyzer/logic_analyzer/logic_analyzer.ino
    time( arduino                                   \
        --upload                                    \
        --board arduino:avr:uno                     \
        --port $ARDUINO_PORT                        \
        --verbose                                   \
        $INOFILE_IN )
    echo -e "\n\n"
    echo $INOFILE_IN
    echo -e "\n\n*******************************\n\n"
}


function UPLOAD_TX
{
    ARDUINO_PORT=$1
    ARDUINO_NB=$2
    INOFILE_IN=$SCRIPT_PATH/very_simple_rf433_TX/very_simple_rf433_TX.ino
    BASENAME="`basename $INOFILE_IN .ino`_$ARDUINO_NB"
    rm -rf $BASENAME
    mkdir $BASENAME
    INOFILE_OUT=$SCRIPT_PATH/$BASENAME/$BASENAME.ino
    sed "s/#define BTN_ID 1/#define BTN_ID $ARDUINO_NB/g" < $INOFILE_IN > $INOFILE_OUT
    time( arduino                                   \
        --upload                                    \
        --board arduino:avr:uno                     \
        --port $ARDUINO_PORT                        \
        --verbose                                   \
        $INOFILE_OUT )
    rm -rf $BASENAME
    echo -e "\n\n"
    echo $INOFILE_OUT
    echo $INOFILE_IN
    echo "ARDUINO_NB = $ARDUINO_NB"
    echo -e "\n\n*******************************\n\n"
}

function UPLOAD_TX_MANCHESTER
{
    ARDUINO_PORT=$1
    ARDUINO_NB=$2
    INOFILE_IN=$SCRIPT_PATH/very_simple_rf433_manchester_TX/very_simple_rf433_manchester_TX.ino
    BASENAME="`basename $INOFILE_IN .ino`_$ARDUINO_NB"
    rm -rf $BASENAME
    mkdir $BASENAME
    INOFILE_OUT=$SCRIPT_PATH/$BASENAME/$BASENAME.ino
    sed "s/#define TX_ID 1/#define TX_ID $ARDUINO_NB/g" < $INOFILE_IN > $INOFILE_OUT
    time( arduino                                   \
        --upload                                    \
        --board arduino:avr:uno                     \
        --port $ARDUINO_PORT                        \
        --verbose                                   \
        $INOFILE_OUT )
    rm -rf $BASENAME
    echo -e "\n\n"
    echo $INOFILE_OUT
    echo $INOFILE_IN
    echo "ARDUINO_NB = $ARDUINO_NB"
    echo -e "\n\n*******************************\n\n"
}

function UPLOAD_RX
{
    ARDUINO_PORT=$1
    INOFILE_IN=$SCRIPT_PATH/very_simple_rf433_RX/very_simple_rf433_RX.ino
    time( arduino                                   \
        --upload                                    \
        --board arduino:avr:uno                     \
        --port $ARDUINO_PORT                        \
        --verbose                                   \
        $INOFILE_IN )
    echo -e "\n\n"
    echo $INOFILE_IN
    echo -e "\n\n*******************************\n\n"
}

function UPLOAD_RX_MANCHESTER
{
    ARDUINO_PORT=$1
    INOFILE_IN=$SCRIPT_PATH/very_simple_rf433_manchester_RX/very_simple_rf433_manchester_RX.ino
    time( arduino                                   \
        --upload                                    \
        --board arduino:avr:uno                     \
        --port $ARDUINO_PORT                        \
        --verbose                                   \
        $INOFILE_IN )
    echo -e "\n\n"
    echo $INOFILE_IN
    echo -e "\n\n*******************************\n\n"
}

function UPLOAD_BUTTON_SIMULATOR
{
    ARDUINO_PORT=$1
    INOFILE_IN=$SCRIPT_PATH/very_simple_rf433_button_simulator/very_simple_rf433_button_simulator.ino
    time( arduino                                   \
        --upload                                    \
        --board arduino:avr:uno                     \
        --port $ARDUINO_PORT                        \
        --verbose                                   \
        $INOFILE_IN )
    echo -e "\n\n"
    echo $INOFILE_IN
    echo -e "\n\n*******************************\n\n"
}

function UPLOAD_BUTTON_SIMULATOR_MANCHESTER
{
    ARDUINO_PORT=$1
    INOFILE_IN=$SCRIPT_PATH/very_simple_rf433_button_simulator_manchester/very_simple_rf433_button_simulator_manchester.ino
    time( arduino                                   \
        --upload                                    \
        --board arduino:avr:uno                     \
        --port $ARDUINO_PORT                        \
        --verbose                                   \
        $INOFILE_IN )
    echo -e "\n\n"
    echo $INOFILE_IN
    echo -e "\n\n*******************************\n\n"
}


time(

# ##########
# AVEC MANCHESTER
# ##########

# ARDUINO_PORT="/dev/tty.usbmodem14221"
# UPLOAD_RX_MANCHESTER $ARDUINO_PORT &

# ARDUINO_PORT="/dev/tty.usbmodem142111"
# ARDUINO_NB=1
# UPLOAD_TX_MANCHESTER $ARDUINO_PORT $ARDUINO_NB &

# ARDUINO_PORT="/dev/tty.usbmodem142121"
# ARDUINO_NB=2
# UPLOAD_TX_MANCHESTER $ARDUINO_PORT $ARDUINO_NB &

# ARDUINO_PORT="/dev/tty.usbmodem142131"
# ARDUINO_NB=3
# UPLOAD_TX_MANCHESTER $ARDUINO_PORT $ARDUINO_NB &

# ARDUINO_PORT="/dev/tty.usbmodem142141"
# ARDUINO_NB=4
# UPLOAD_TX_MANCHESTER $ARDUINO_PORT $ARDUINO_NB &

# ARDUINO_PORT="/dev/tty.usbmodem14241"
# UPLOAD_BUTTON_SIMULATOR_MANCHESTER $ARDUINO_PORT &

# ARDUINO_PORT="/dev/tty.usbmodem14231"
# UPLOAD_LOGIC_ANALYSER $ARDUINO_PORT &





# ##########
# SANS MANCHESTER
# ##########

ARDUINO_PORT="/dev/tty.usbmodem142111"
ARDUINO_NB=1
UPLOAD_TX $ARDUINO_PORT $ARDUINO_NB &

ARDUINO_PORT="/dev/tty.usbmodem142121"
ARDUINO_NB=2
UPLOAD_TX $ARDUINO_PORT $ARDUINO_NB &

ARDUINO_PORT="/dev/tty.usbmodem142131"
ARDUINO_NB=3
UPLOAD_TX $ARDUINO_PORT $ARDUINO_NB &

ARDUINO_PORT="/dev/tty.usbmodem142141"
ARDUINO_NB=4
UPLOAD_TX $ARDUINO_PORT $ARDUINO_NB &

ARDUINO_PORT="/dev/tty.usbmodem14221"
UPLOAD_RX $ARDUINO_PORT &

# ARDUINO_PORT="/dev/tty.usbmodem14231"
# UPLOAD_LOGIC_ANALYSER $ARDUINO_PORT &

# ARDUINO_PORT="/dev/tty.usbmodem14241"
# UPLOAD_BUTTON_SIMULATOR $ARDUINO_PORT &

wait

)

