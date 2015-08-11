/*


     ██████  ██    ██ ██ ███████ ███████     ██
    ██    ██ ██    ██ ██    ███     ███      ██
    ██    ██ ██    ██ ██   ███     ███       ██
    ██    ██ ██    ██ ██  ███     ███
     ██████   ██████  ██ ███████ ███████     ██
        ██


    RS232.JS

    Nicolas Jeanmonod, David Le Neillon, 2015

 */



"use strict";



var serialPort = require( "serialport" );



/**
 *
 */
var SerialPort = serialPort.SerialPort;
var stringToQueryDeviceID = "-1\n";
var RS232Devices = [];
var RS232DevicesIgnored = [
    // '/dev/cu.Bluetooth-Incoming-Port',
    // '/dev/cu.Bluetooth-Modem'
];

function openRS232( callback ) {
    serialPort.list( function( err, ports ) {
        var nbPorts = ports.length - RS232DevicesIgnored.length;
        ports.forEach( function( port ) {
            if( RS232DevicesIgnored.indexOf( port.comName ) >= 0 ){ return; }
            console.log( port.comName );
            ( function( port ) {
                try {
                    var RS232Device = new SerialPort( port.comName, { baudrate: 115200 }, true );
                    RS232Device.open( function( error ) {
                        console.log( '# Opening port ' + port.comName );
                        RS232Device.write( stringToQueryDeviceID, function() {
                           RS232Device.drain( function() {
                                RS232Device.once( 'data', function( dataRead ) {
                                    var MXname = String( dataRead ).slice( 0, -1 );
                                    RS232Devices[ MXname ] = RS232Device;
                                    console.log( MXname + " is connected to port " + RS232Devices[ MXname ].path );
                                    if( --nbPorts == 0 ) { callback( 'ready' ); }
                                });
                            });
                        });
                    });
                }
                catch( err ) {
                    console.log( "Problem opening port  " + port.comName )
                }
            })( port );
        });
    });
};

var EventEmitter = require( 'events' ).EventEmitter;

module.exports = new EventEmitter();

openRS232( function( res ) {
    module.exports.devices = RS232Devices;
    module.exports.emit( res );
});

// openRS232( function( res ) {
//     setTimeout( function() {
//         module.exports.devices = RS232Devices;
//         module.exports.emit( res );
//     }, 0 )
// });
