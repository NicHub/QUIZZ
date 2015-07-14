
// simple_serialport

var http   = require( 'http' );
var fs     = require( 'fs' );
var osname = process.platform;
var os     = require( 'os' );



// Liste les ports séries disponibles sans tenir compte des ports Bluetooth.
function getRS232devices( callback ) {
    var RS232devices = [];
    var comPortsToIgnore = [ '/dev/cu.Bluetooth-Incoming-Port', '/dev/cu.Bluetooth-Modem' ];
    serialport.list( function( err, ports ) {
        ports.forEach( function( port ) {
            if( comPortsToIgnore.indexOf( port.comName ) < 0 ) {
                RS232devices.push( port.comName );
            };
        });
        callback( RS232devices );
    });
};



// Chargement du fichier index.html affiché au client
var server = http.createServer( function( req, res ) {
    fs.readFile( './index.html', 'utf-8', function( error, content ) {
        res.writeHead( 200, { "Content-Type": "text/html" } );
        res.end( content );
        console.log( "Fichier index.html créé" );
    });
});



// Démarrage du serveur
var HTTPPort = 8080;
server.listen( HTTPPort );
console.log( "Serveur démarré à http://" + os.hostname() + ":" + HTTPPort );



// Chargement de socket.io
var io = require( 'socket.io' ).listen( server );
io.sockets.on( 'connection', function( socket, pseudo ) {



    // Initialisation de socket.io
    console.log( '###\nInitialisation de socket.io' );
    // Quand on client se connecte, on lui envoie un message
    socket.emit( 'message', 'Vous êtes bien connecté !' );
    getRS232devices( function( RS232devices ) {
        socket.emit( 'RS232devices', RS232devices )
    });
    console.log( 'Fin de l’initialisation de socket.io\n###' );



    // Message de la page HTML vers l’Arduino
    socket.on( 'msg_to_arduino', function( message ) {
        console.log( 'Send to Arduino: ' + message );
        sp.write( message + "\n", function( err, results ) {
            console.log( 'results ' + results );
        });
    });



    // Données retournées par l’Arduino
    sp.on( 'data', function( data ) {
        // console.log( 'data received: ' + data );
        socket.emit( 'ArduinoSocket', data );
    });



});



// Initialisation de la connexion série
switch( osname )
{
    case 'darwin':
        var ArduinoPort = '/dev/cu.wchusbserial1420';
        break;
    case 'linux':
        var ArduinoPort = '/dev/ttyUSB0';
        break;
}
var serialport = require( "serialport" );
var SerialPort = serialport.SerialPort; // localize object constructor
getRS232devices( function( RS232devices ){ console.log(RS232devices); });
var sp = new SerialPort( ArduinoPort, {
    parser:   serialport.parsers.readline( "\n" ),
    baudrate: 115200
}, true );
sp.open( function( error ) {
    if( error ) {
        console.log( 'failed to open: ' + error );
    }
    else {
        console.log( 'open connection to Arduino ' );
        sp.write( "0\n", function( err, results ) {
            console.log( 'results ' + results );
        });
    }
});


