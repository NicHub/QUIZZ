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

var serialPort = require( "serialport" );

/**
 *
 */
var SerialPort = serialPort.SerialPort;
var stringToQueryDeviceID = "-1\n";
var RS232Devices = [];

serialPort.list( function( err, ports ) {
    ports.forEach( function( port ) {
        console.log( port.comName );
        ( function( port ) {
            try {
                var RS232Device = new SerialPort( port.comName, { baudrate: 115200 }, true );
                RS232Device.open( function( error ) {
                    console.log( '# Opening port ' + port.comName );
                    RS232Device.write( stringToQueryDeviceID, function() {
                       RS232Device.drain( function() {
                            RS232Device.once( 'data', function( dataRead ) {
                                MXname = String( dataRead ).slice( 0, -1 );
                                RS232Devices[ MXname ] = RS232Device;
                                console.log( MXname + " is connected to port " + RS232Devices[ MXname ].path );
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

module.exports.devices = RS232Devices;

