



**NODE.JS**
===========



<http://elinux.org/Node.js_on_RPi>
<https://github.com/joyent/node/wiki/installing-node.js-via-package-manager>


# Installation
<http://nodejs.org/dist/latest/>


	NODEVERSION=v0.11.7
	wget http://nodejs.org/dist/$NODEVERSION/node-$NODEVERSION-linux-arm-pi.tar.gz
	tar -xvzf node-$NODEVERSION-linux-arm-pi.tar.gz
	node-$NODEVERSION-linux-arm-pi/bin/node --version
	/home/pi/node-$NODEVERSION-linux-arm-pi/bin/node     /home/pi/quizz/nodejs/public_html/index.js



# Compilation

NODEVERSION=0.11.7
wget http://nodejs.org/dist/$NODEVERSION/node-$NODEVERSION.tar.gz
tar -xzf node-$NODEVERSION.tar.gz
cd node-$NODEVERSION
./configure
make; sudo make install
TIMEFORMAT='Temps de compilation : %3R s'; time( make; sudo make install )



# Exemple température

<http://alexandre.alapetite.fr/doc-alex/raspberrypi-nodejs-arduino/>



# heimcontrol
<https://ni-c.github.io/heimcontrol.js/get-started.html#hc-inst>




# Install 0.12.0

<http://www.bitpi.co/2015/02/12/install-nodejs-on-raspberry-pi/>



# Arduino Experimenter's Guide for NodeJS

<http://node-ardx.org>


# Johnny five

<https://github.com/rwaldron/johnny-five>

