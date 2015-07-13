#!/bin/bash

# amixer cset numid=1 -- -20

# omxplayer ~/quizz/code-rpi/MP3/Frog.aiff


# Config carte son USB
# http://plugable.com/2014/11/06/how-to-switch-to-usb-audio-on-raspberry-pi
# http://alexpb.com/notes/articles/2012/11/14/error-when-playing-audio-on-raspbian-on-a-raspberry-pi/
# sudo nano /usr/share/alsa/alsa.conf
# sudo nano /usr/share/alsa/alsa.conf

mpg321 /home/pi/Musique/wah_wah_sound.mp3 -g 100
