// var spawn = require('child_process').spawn,
//     grep  = spawn('grep', ['ssh']);

// console.log('Spawned child pid: ' + grep.pid);
// grep.stdin.end();


// /home/pi/quizz/code-rpi/MP3/play.sh

// sudo apt-get install alsa-utils
// sudo apt-get install mpg321

// https://learn.adafruit.com/playing-sounds-and-using-buttons-with-raspberry-pi?view=all

// sudo apt-get update; sudo apt-get install python-dev; sudo apt-get install python-rpi.gpio

// http://wiki.linuxaudio.org/wiki/raspberrypi

// https://blog.liftsecurity.io/2014/08/19/Avoid-Command-Injection-Node.js?utm_source=ourjs.com



var child_process = require( 'child_process' );

child_process.execFile( '/home/pi/quizz/sons/play.sh', [ 'winner_sound' ], function( err, result ) {
    console.log( result )
});

child_process.execFile( '/home/pi/quizz/sons/play.sh', [ 'looser_sound' ], function( err, result ) {
    console.log( result )
});

