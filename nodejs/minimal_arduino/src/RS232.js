
var SerialPort = require( "serialport" ).SerialPort;
var tools      = require("./tools.js");
var fs         = require( 'fs' );
var os         = require( 'os' );
var osname     = process.platform;

/**
 * Liste des Arduinos
 */
tools.tic();
var RS232PortList = fs.readdirSync( '/dev/' );
var RS232Ports = [];
if( osname == "darwin" ) {
    console.log( "On est sur le Mac" );
    for( var i in RS232PortList ) {
        if( RS232PortList[ i ].substr( 0, 11 ) == "cu.usbmodem" ||
            RS232PortList[ i ].substr( 0, 15 ) == "cu.wchusbserial" )
        { RS232Ports.push( '/dev/' + RS232PortList[ i ] ); }
    }
} else if( osname == "linux" ) {
    console.log( "On est sur le Rpi" );
    for( var i in RS232PortList ) {
        if( RS232PortList[ i ].substr( 0, 6 ) == "ttyACM" ||
            RS232PortList[ i ].substr( 0, 6 ) == "ttyUSB" )
        { RS232Ports.push( '/dev/' + RS232PortList[ i ] ); }
    }
} else {
    console.log( "On est foutu, l’OS n’est pas connu !" );
    process.exit( 1 );
}

for( var j in RS232Ports ) {
    console.log( "RS232Ports[ " + j + " ] = " + RS232Ports[ j ] );
}
tools.toc();




var RS232s = [];

/**
 * Ouverture des connexions des ports RS232 des Arduino.
 */

/* Arduino 0 */
try {
    RS232s[ 0 ] = new SerialPort( RS232Ports[ 0 ], { baudrate: 115200 }, true );
    RS232s[ 0 ].open( function( error ) { console.log( '# Ouverture de la connexion de MX0' ); });
    RS232s[ 0 ].write( "-1\n", function() {
       RS232s[ 0 ].drain( function() {
            RS232s[ 0 ].once( 'data', function( dataRead ) {
                annonceOuverture( 0, dataRead );
            });
        });
    });
}
catch( err ) {
    console.log( "Problème à l’ouverture de RS232Ports[ 0 ] = " + RS232Ports[ 0 ] )
}

/* Arduino 1 */
try {
    RS232s[ 1 ] = new SerialPort( RS232Ports[ 1 ], { baudrate: 115200 }, true );
    RS232s[ 1 ].open( function( error ) { console.log( '# Ouverture de la connexion de MX1' ); });
    RS232s[ 1 ].write( "-1\n", function() {
       RS232s[ 1 ].drain( function() {
            RS232s[ 1 ].once( 'data', function( dataRead ) {
                annonceOuverture( 1, dataRead );
            });
        });
    });
}
catch( err ) {
    console.log( "Problème à l’ouverture de RS232Ports[ 1 ] = " + RS232Ports[ 1 ] )
}

/* Arduino 2 */
try {
    RS232s[ 2 ] = new SerialPort( RS232Ports[ 2 ], { baudrate: 115200 }, true );
    RS232s[ 2 ].open( function( error ) { console.log( '# Ouverture de la connexion de MX2' ); });
    RS232s[ 2 ].write( "-1\n", function() {
       RS232s[ 2 ].drain( function() {
            RS232s[ 2 ].once( 'data', function( dataRead ) {
                annonceOuverture( 2, dataRead );
            });
        });
    });
}
catch( err ) {
    console.log( "Problème à l’ouverture de RS232Ports[ 2 ] = " + RS232Ports[ 2 ] )
}

/* Arduino 3 */
try {
    RS232s[ 3 ] = new SerialPort( RS232Ports[ 3 ], { baudrate: 115200 }, true );
    RS232s[ 3 ].open( function( error ) { console.log( '# Ouverture de la connexion de MX3' ); });
    RS232s[ 3 ].write( "-1\n", function() {
       RS232s[ 3 ].drain( function() {
            RS232s[ 3 ].once( 'data', function( dataRead ) {
                annonceOuverture( 3, dataRead );
            });
        });
    });
}
catch( err ) {
    console.log( "Problème à l’ouverture de RS232Ports[ 3 ] = " + RS232Ports[ 3 ] )
}

/* Arduino 4 */
try {
    RS232s[ 4 ] = new SerialPort( RS232Ports[ 4 ], { baudrate: 115200 }, true );
    RS232s[ 4 ].open( function( error ) { console.log( '# Ouverture de la connexion de MX4' ); });
    RS232s[ 4 ].write( "-1\n", function() {
       RS232s[ 4 ].drain( function() {
            RS232s[ 4 ].once( 'data', function( dataRead ) {
                annonceOuverture( 4, dataRead );
            });
        });
    });
}
catch( err ) {
    console.log( "Problème à l’ouverture de RS232Ports[ 4 ] = " + RS232Ports[ 4 ] )
}

/* Arduino 5 */
try {
    RS232s[ 5 ] = new SerialPort( RS232Ports[ 5 ], { baudrate: 115200 }, true );
    RS232s[ 5 ].open( function( error ) { console.log( '# Ouverture de la connexion de MX5' ); });
    RS232s[ 5 ].write( "-1\n", function() {
       RS232s[ 5 ].drain( function() {
            RS232s[ 5 ].once( 'data', function( dataRead ) {
                annonceOuverture( 5, dataRead );
            });
        });
    });
}
catch( err ) {
    console.log( "Problème à l’ouverture de RS232Ports[ 5 ] = " + RS232Ports[ 5 ] )
}

RS232Devices = [];
function annonceOuverture( MXnb, dataRead ) {
    MXname = String( dataRead ).slice( 0, -1 );
    console.log( MXname + " est ouvert et est dans RS232s[ " + MXnb + " ]" );
    RS232Devices[ MXname ] = RS232s[ MXnb ]; console.log( MXname + " set" );
}

module.exports.devices = RS232Devices;

