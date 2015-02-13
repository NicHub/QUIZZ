#!/bin/bash

# Pour une config visible d’internet et pas seulement de l’intranet, voir :
# http://www.tomdalling.com/blog/software-processes/how-to-set-up-a-secure-git-server-at-home-osx/

echo $OSTYPE

if [[ "$OSTYPE" == "linux-gnueabihf" ]]; then
    git pull ssh://nico@nicobook.local:22/Users/nico/Documents/projets/quizz/
elif [[ "$OSTYPE" == "darwin14" ]]; then
	git pull ssh://pi@$PIIP:22/home/pi/quizz
else
    echo "Y a un blême avec cet OS"
fi

