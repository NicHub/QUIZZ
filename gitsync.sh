#!/bin/bash

# Pour une config visible d’internet et pas seulement de l’intranet, voir :
# http://www.tomdalling.com/blog/software-processes/how-to-set-up-a-secure-git-server-at-home-osx/

echo $OSTYPE

# RPi
if [[ "$OSTYPE" == "linux-gnueabihf" ]]; then
    git pull ssh://nico@nicobook.local:22/Users/nico/Documents/projets/quizz/

# Mac
elif [[ "$OSTYPE" == "darwin14" ]]; then

	# Clé USB
	if [[ "${PWD}" == "/Volumes/NICUSB/quizz" ]]; then
		echo "USB"
		git pull /Users/nico/Documents/projets/quizz/

	# Macbook
	elif [[ "${PWD}" == "/Users/nico/Documents/projets/quizz" ]]; then
		echo "Mac"
		git pull ssh://pi@$PIIP:22/home/pi/quizz

	# Problème
	else
	    echo "Je suis perdu"
	fi

# Problème
else
    echo "Y a un blême avec cet OS"
fi

