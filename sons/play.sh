#!/bin/bash

# amixer cset numid=1 -- -20

# amixer cset numid=1 0

# omxplayer ~/Musique/roxanne.mp3
# omxplayer ~/Musique/Passenger\ -\ Holes\ \(Official\ Video\)\ \(mp4\ 1080p\).mp4

# mpg321 /home/pi/Musique/roxanne.mp3


# amixer cset numid=1 -- -20

# omxplayer ~/quizz/code-rpi/MP3/Frog.aiff


# Config carte son USB
# http://plugable.com/2014/11/06/how-to-switch-to-usb-audio-on-raspberry-pi
# http://alexpb.com/notes/articles/2012/11/14/error-when-playing-audio-on-raspbian-on-a-raspberry-pi/
# sudo nano /usr/share/alsa/alsa.conf


# mpg321 /home/pi/Musique/wah_wah_sound.mp3 -g 100


case "$1" in
winner_sound)           echo -e "\nWinner sound !!!\n"
                        paplay /home/pi/quizz/sons/That_s_All_Folks_WDJRfvbCdh8.aif --volume 15000 &
                        ;;

loser_sound)            echo -e "\nLoser sound\n"
                        paplay /home/pi/quizz/sons/wah_wah_sound.aif --volume 15000 &
                        ;;
shotgun_sound)          echo -e "\nShotgun sound\n"
                        paplay /home/pi/quizz/sons/Shotgun_Sound_Effect.aif --volume 15000 &
                        ;;
*)                      echo -e "\n !!! Usage: ./play.sh winner_sound|loser_sound !!!\n"
                        paplay /home/pi/quizz/sons/That_s_All_Folks_WDJRfvbCdh8.aif --volume 15000 &
                        exit 1
                        ;;
esac


exit 0


