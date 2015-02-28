
var http = require('http');
var fs = require('fs');


var USBdevices = fs.readdirSync( '/dev/' );
var Arduinos = [];
for( var i in USBdevices )
{
    if( USBdevices[ i ].substr( 0, 12 ) == "tty.usbmodem" )
    {
        Arduinos.push( USBdevices[ i ] );
    }
}

for( var j in Arduinos )
{
    console.log( Arduinos[ j ] );
}

