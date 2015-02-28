#!/bin/bash

APPPATH="/home/pi/quizz/nodejs/socket"
LOGFILE="$APPPATH/startApp.log"


until /bin/nc -vzw 2 davberrypi.local 22; do sleep 2; done
echo "davberrypi.local 22 -> OK" >> $LOGFILE
#/usr/bin/uptime >> $LOGFILE
/usr/bin/uptime | grep -ohe 'up .*' | sed 's/,//g' | awk '{ print $2" "$3 }' >> $LOGFILE


cd $APPPATH
/usr/local/bin/node app.js

# until netcat -vzw 2 davberrypi.local 8080; do sleep 2; done

