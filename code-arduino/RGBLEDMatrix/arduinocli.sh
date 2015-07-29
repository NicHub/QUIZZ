#!/bin/bash

# Arduino CLI man page
# https://github.com/arduino/Arduino/blob/master/build/shared/manpage.adoc
# Il faut indiquer le chemin complet vers le croquis pour que ça fonctionne !
# Ce script doit être appelé depuis son propre répertoire !


SCRIPT_PATH=`pwd`


TIMEFORMAT='time : %3R s'
shopt -s expand_aliases
ARDUINO_VERSION=2
case "$ARDUINO_VERSION" in
1)  alias arduino='/Applications/Arduino_1.6.1.app/Contents/MacOS/JavaApplicationStub' ;;
*)  alias arduino='/Applications/Arduino.app/Contents/MacOS/Arduino' ;;
esac


function MX_16x32
{
    ARDUINO_NB=$1
    ARDUINO_PORT=$2
    INOFILE_IN=$SCRIPT_PATH/quiztest_16x32/quiztest_16x32.ino
    hFILE_IN=$SCRIPT_PATH/quiztest_16x32/chiffres.h
    BASENAME="`basename $INOFILE_IN .ino`_$ARDUINO_NB"
    rm -rf $BASENAME
    mkdir $BASENAME
    INOFILE_OUT=$SCRIPT_PATH/$BASENAME/$BASENAME.ino
    sed "s/#define MX 1/#define MX $ARDUINO_NB/g" < $INOFILE_IN > $INOFILE_OUT
    cp $hFILE_IN $BASENAME
    time( arduino                                   \
        --upload                                    \
        --board arduino:avr:uno                     \
        --port $ARDUINO_PORT                        \
        --verbose                                   \
        $INOFILE_OUT )
    rm -rf $BASENAME
    echo -e "\n\n"
    echo $INOFILE_OUT
    echo -e "\n\n*******************************\n\n"
}


function MX_32x32
{
    ARDUINO_NB=$1
    ARDUINO_PORT=$2
    INOFILE_IN=$SCRIPT_PATH/quiztest_32x32/quiztest_32x32.ino
    hFILE_IN=$SCRIPT_PATH/quiztest_32x32/chiffres.h
    BASENAME="`basename $INOFILE_IN .ino`_$ARDUINO_NB"
    rm -rf $BASENAME
    mkdir $BASENAME
    INOFILE_OUT=$SCRIPT_PATH/$BASENAME/$BASENAME.ino
    cp $INOFILE_IN $INOFILE_OUT
    cp $hFILE_IN $BASENAME
    time( arduino                                   \
        --upload                                    \
        --board arduino:avr:uno                     \
        --port $ARDUINO_PORT                        \
        --verbose                                   \
        $INOFILE_OUT )
    rm -rf $BASENAME
    echo -e "\n\n"
    echo $INOFILE_OUT
    echo -e "\n\n*******************************\n\n"
}

time(

ARDUINO_NB=0
ARDUINO_PORT="/dev/cu.usbmodem26221"
MX_32x32 $ARDUINO_NB $ARDUINO_PORT &

ARDUINO_NB=1
ARDUINO_PORT="/dev/cu.usbmodem262111"
MX_16x32 $ARDUINO_NB $ARDUINO_PORT &

ARDUINO_NB=2
ARDUINO_PORT="/dev/cu.usbmodem262121"
MX_16x32 $ARDUINO_NB $ARDUINO_PORT &

ARDUINO_NB=3
ARDUINO_PORT="/dev/cu.usbmodem262131"
MX_16x32 $ARDUINO_NB $ARDUINO_PORT &

ARDUINO_NB=4
ARDUINO_PORT="/dev/cu.usbmodem262141"
MX_16x32 $ARDUINO_NB $ARDUINO_PORT &

wait

)

