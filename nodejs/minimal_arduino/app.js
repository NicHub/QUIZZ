/*


     ██████  ██    ██ ██ ███████ ███████     ██
    ██    ██ ██    ██ ██    ███     ███      ██
    ██    ██ ██    ██ ██   ███     ███       ██
    ██    ██ ██    ██ ██  ███     ███
     ██████   ██████  ██ ███████ ███████     ██
        ██


    SERVEUR NODE.JS

    Nicolas Jeanmonod, David Le Neillon, 2015

 */

var express       = require( 'express' );
var os            = require( 'os' );
var socketIO      = require( 'socket.io' );
var RS232         = require( './src/RS232.js' );
var child_process = require( 'child_process' );

var nodePort  = 8080;
var app       = express();
app.use( express.static( 'public' ) );

var server = app.listen( nodePort, function () {
    console.log( 'Serveur Node démarré à\nhttp://%s:%s', os.hostname(), nodePort );
});

var io = socketIO.listen( server );
io.sockets.on( 'connection', function( socket ) {

    var msg = "Un client s’est connecté.";
    console.log( msg );
    socket.emit( 'connectionStart', msg );

    // child_process.execFile( '/home/pi/quizz/sons/play.sh', [ 'winner_sound' ], function( err, result ) {
    //     console.log( 'winner_sound' )
    // });


    // MX0
    socket.on( 'butMX_VAL_0', function( cmd ) {
        RS232.devices[ 'MX0' ].write( cmd + "\n", function( err, results ) {
            console.log( 'Write to MX0 results ' + results );
        });
    });
    // MX1
    socket.on( 'butMX_VAL_1', function( cmd ) {
        RS232.devices[ 'MX1' ].write( cmd + "\n", function( err, results ) {
            console.log( 'Write to MX1 results ' + results );
        });
    });
    // MX2
    socket.on( 'butMX_VAL_2', function( cmd ) {
        RS232.devices[ 'MX2' ].write( cmd + "\n", function( err, results ) {
            console.log( 'Write to MX2 results ' + results );
        });
    });
    // MX3
    socket.on( 'butMX_VAL_3', function( cmd ) {
        RS232.devices[ 'MX3' ].write( cmd + "\n", function( err, results ) {
            console.log( 'Write to MX3 results ' + results );
        });
    });
    // MX4
    socket.on( 'butMX_VAL_4', function( cmd ) {
        RS232.devices[ 'MX4' ].write( cmd + "\n", function( err, results ) {
            console.log( 'Write to MX4 results ' + results );
        });
    });
    // Envoyer à toutes les matrices
    socket.on( 'sendToAll', function( cmd ) {
        RS232.devices[ 'MX0' ].write( cmd, function( err, results ) {
            console.log( 'Write to MX0 results ' + results );
        });
        RS232.devices[ 'MX1' ].write( cmd, function( err, results ) {
            console.log( 'Write to MX1 results ' + results );
        });
        RS232.devices[ 'MX2' ].write( cmd, function( err, results ) {
            console.log( 'Write to MX2 results ' + results );
        });
        RS232.devices[ 'MX3' ].write( cmd, function( err, results ) {
            console.log( 'Write to MX3 results ' + results );
        });
        RS232.devices[ 'MX4' ].write( cmd, function( err, results ) {
            console.log( 'Write to MX4 results ' + results );
        });
    });





    socket.on( 'inputButtonClicked', function( message ) {
        var msg = "Le serveur a reçu " + message;
        console.log( msg );
        socket.emit( 'serverAcknowledge', msg );
    });

    socket.on( 'disconnect', function( socket ) {
        console.log( 'Client déconnecté!' );
    });


    // Données retournées par l’Arduino
    RS232.devices[ 'CB0' ].on( 'data', function( data ) {
        switch( data[ 0 ] ) {
            case 49: var msg = 1; break;
            case 50: var msg = 2; break;
            case 52: var msg = 3; break;
            case 56: var msg = 4; break;
        };
        console.log( 'arduinoButtonPressed: ' + msg );
        socket.emit( 'arduinoButtonPressed', msg );
    });

});

