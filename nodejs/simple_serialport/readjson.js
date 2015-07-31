
// ~/quizz/code-rpi/RS232/arduino_ports.py
// /home/pi/quizz/nodejs/simple_serialport

var fs = require( 'fs' );
var obj = JSON.parse( fs.readFileSync( 'arduino_ports.json', 'utf8' ) );

console.log( obj );
console.log( obj[ "MX1" ] );


for( var prop in obj )
{
  if (obj.hasOwnProperty(prop)) {
  // or if (Object.prototype.hasOwnProperty.call(obj,prop)) for safety...
    console.log("prop: " + prop + " value: " + obj[prop])
  }
}