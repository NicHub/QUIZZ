/*
 *
 * QUIZZ !
 *
 */

var express   = require( 'express' );
var os        = require( 'os' );
var socketIO  = require( 'socket.io' );
var RS232     = require( './src/RS232.js' );

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

    socket.on( 'inputButtonClicked', function( message ) {
        var msg = "Le serveur a reçu " + message;
        console.log( msg );
        socket.emit( 'serverAcknowledge', msg );
    });

    socket.on( 'disconnect', function( socket ) {
        console.log( 'Client déconnecté!' );
    });

    socket.on( 'sendMinusOneToCB1', function( message ) {
        RS232.devices[ 'CB1' ].write( "-1\n", function( err, results ) {
            console.log( ' --- results ' + results );
        });
    });

    // Données retournées par l’Arduino
    RS232.devices[ 'CB1' ].on( 'data', function( data ) {
        var msg = String( data );
        console.log( 'data received socket: ' + msg );
        socket.emit( 'serverAcknowledge', msg );
    });

});

