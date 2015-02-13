#!/bin/bash


case "$1" in
1)      echo "1) Pull de rPi vers Mac"
        git pull ssh://pi@$PIIP:22/home/pi/quizz
        ;;

2)      echo "2) Pull de Mac vers rPi"
        git pull ssh://nico@nicobook.local:22/Users/nico/Documents/projets/quizz/
        ;;

3)      echo "3) Pull de Mac vers USB"
        git pull /Users/nico/Documents/projets/quizz/
        ;;

4)      echo "4) Pull de USB vers Mac"
        git pull /Volumes/NICUSB/quizz/
        ;;

*)      echo "Usage:"
        echo "1) Pull de rPi vers Mac"
        echo "2) Pull de Mac vers rPi"
        echo "3) Pull de Mac vers USB"
        echo "4) Pull de USB vers Mac"
        exit 1
        ;;
esac
exit 0
