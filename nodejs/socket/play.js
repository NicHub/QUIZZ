var spawn = require('child_process').spawn,
    grep  = spawn('grep', ['ssh']);

console.log('Spawned child pid: ' + grep.pid);
grep.stdin.end();

/*
/home/pi/quizz/code-rpi/MP3/play.sh

sudo apt-get install alsa-utils
sudo apt-get install mpg321

https://learn.adafruit.com/playing-sounds-and-using-buttons-with-raspberry-pi?view=all


sudo apt-get update; sudo apt-get install python-dev; sudo apt-get install python-rpi.gpio


http://wiki.linuxaudio.org/wiki/raspberrypi


*/