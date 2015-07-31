

var http = require('http');
var fs = require('fs');
var osname = process.platform;
var os = require( 'os' );

var ticTime;
var tocTime;
function tic()
{
    var timestamp = new Date();
    ticTime = timestamp.getTime();
}
function toc()
{
    var timestamp = new Date();
    tocTime = timestamp.getTime();
    console.log( "ticTime = " + ticTime );
    console.log( "tocTime = " + tocTime );
    console.log( "Temps écoulé = " + ( tocTime - ticTime ) );
}






// Chargement du fichier index.html affiché au client
var server = http.createServer(function(req, res) {
    fs.readFile('./index.html', 'utf-8', function(error, content) {
        res.writeHead(200, {"Content-Type": "text/html"});
        res.end(content);
    });

});

// Chargement de socket.io
var io = require('socket.io').listen(server);

io.sockets.on('connection', function (socket, pseudo)
{
    // Quand on client se connecte, on lui envoie un message
    socket.emit('message', 'Vous êtes bien connecté ! Votre pseudo est ' + pseudo );
    // On signale aux autres clients qu'il y a un nouveau venu
    socket.broadcast.emit('message', 'Un autre client vient de se connecter ! ');

    // Dès qu'on nous donne un pseudo, on le stocke en variable de session
    socket.on('petit_nouveau', function(pseudo) {
        socket.pseudo = pseudo;
        socket.emit('message', 'Votre pseudo est ' + pseudo );
    });

    // Dès qu'on reçoit un "message" (clic sur le bouton), on le note dans la console
    socket.on('message', function (message) {
        // On récupère le pseudo de celui qui a cliqué dans les variables de session
        console.log(socket.pseudo + ' me parle ! Il me dit : ' + message);
        socket.emit('message', socket.pseudo + ' me parle ! Il me dit : ' + message );
    });



    // MX0
    socket.on('butMX_VAL_0', function (message) {
        socket.emit('message', 'MX 0 = ' + message );

        MX0.write( message + "\n", function(err, results) {
            // console.log('err ' + err);
            console.log('results ' + results);
        });

    });

    // MX1
    socket.on('butMX_VAL_1', function (message) {
        socket.emit('message', 'MX 1 = ' + message );

        MX1.write( message + "\n", function(err, results) {
            // console.log('err ' + err);
            console.log('results ' + results);
        });

    });

    // MX2
    socket.on('butMX_VAL_2', function (message) {
        socket.emit('message', 'MX 2 = ' + message );

        MX2.write( message + "\n", function(err, results) {
            // console.log('err ' + err);
            console.log('results ' + results);
        });

    });

    // MX3
    socket.on('butMX_VAL_3', function (message) {
        socket.emit('message', 'MX 3 = ' + message );

        MX3.write( message + "\n", function(err, results) {
            // console.log('err ' + err);
            console.log('results ' + results);
        });

    });

    // MX4
    socket.on('butMX_VAL_4', function (message) {
        socket.emit('message', 'MX 4 = ' + message );

        MX4.write( message + "\n", function(err, results) {
            // console.log('err ' + err);
            console.log('results ' + results);
        });

    });








    /*

    Liste des Arduinos

    */

    tic();
    var USBdevices = fs.readdirSync( '/dev/' );
    var ArduinoPorts = [];
    if( osname == "darwin" )
    {
        console.log( "On est sur le Mac" );
        for( var i in USBdevices )
        {
            if( USBdevices[ i ].substr( 0, 12 ) == "tty.usbmodem" )
            {
                ArduinoPorts.push( '/dev/' + USBdevices[ i ] );
            }
        }
    }
    else if( osname == "linux" )
    {
        console.log( "On est sur le Rpi" );
        for( var i in USBdevices )
        {
            if( USBdevices[ i ].substr( 0, 6 ) == "ttyACM" )
            {
                ArduinoPorts.push( '/dev/' + USBdevices[ i ] );
            }
        }
    }
    else
    {
        console.log( "On est foutu, l’OS n’est pas connu !" );
        process.exit( 1 );
    }




    for( var j in ArduinoPorts )
    {
        console.log( "ArduinoPorts[ " + j + " ] = " + ArduinoPorts[ j ] );
    }
    toc();




    var MXs = [];

    /*

    MXs

    */
    var SerialPort = require( "serialport" ).SerialPort;

    MXs[ 0 ] = new SerialPort( ArduinoPorts[ 0 ], { baudrate: 115200 }, true );
    MXs[ 0 ].open( function( error ) { console.log( '# Ouverture de la connexion de MX0' ); });
    MXs[ 0 ].write( "-1\n", function() {
       MXs[ 0 ].drain( function() {
            MXs[ 0 ].once( 'data', function( dataRead ) {
                annonceOuverture( 0, dataRead );
            });
        });
    });

    MXs[ 1 ] = new SerialPort( ArduinoPorts[ 1 ], { baudrate: 115200 }, true );
    MXs[ 1 ].open( function( error ) { console.log( '# Ouverture de la connexion de MX1' ); });
    MXs[ 1 ].write( "-1\n", function() {
       MXs[ 1 ].drain( function() {
            MXs[ 1 ].once( 'data', function( dataRead ) {
                annonceOuverture( 1, dataRead );
            });
        });
    });

    MXs[ 2 ] = new SerialPort( ArduinoPorts[ 2 ], { baudrate: 115200 }, true );
    MXs[ 2 ].open( function( error ) { console.log( '# Ouverture de la connexion de MX2' ); });
    MXs[ 2 ].write( "-1\n", function() {
       MXs[ 2 ].drain( function() {
            MXs[ 2 ].once( 'data', function( dataRead ) {
                annonceOuverture( 2, dataRead );
            });
        });
    });

    MXs[ 3 ] = new SerialPort( ArduinoPorts[ 3 ], { baudrate: 115200 }, true );
    MXs[ 3 ].open( function( error ) { console.log( '# Ouverture de la connexion de MX3' ); });
    MXs[ 3 ].write( "-1\n", function() {
       MXs[ 3 ].drain( function() {
            MXs[ 3 ].once( 'data', function( dataRead ) {
                annonceOuverture( 3, dataRead );
            });
        });
    });

    MXs[ 4 ] = new SerialPort( ArduinoPorts[ 4 ], { baudrate: 115200 }, true );
    MXs[ 4 ].open( function( error ) { console.log( '# Ouverture de la connexion de MX4' ); });
    MXs[ 4 ].write( "-1\n", function() {
       MXs[ 4 ].drain( function() {
            MXs[ 4 ].once( 'data', function( dataRead ) {
                annonceOuverture( 4, dataRead );
            });
        });
    });

    namedMX = [];
    function annonceOuverture( MXnb, dataRead ) {
        MXname = String( dataRead ).substr( 0, 3 );
        console.log( MXname + " est ouvert et est dans MX[ " + MXnb + " ]" );
        switch( MXname ) {
            case 'MX0': namedMX[ 'MX0' ] = MXs[ MXnb ]; MX0 = namedMX[ 'MX0' ]; console.log( "MX0 set" ); break;
            case 'MX1': namedMX[ 'MX1' ] = MXs[ MXnb ]; MX1 = namedMX[ 'MX1' ]; console.log( "MX1 set" ); break;
            case 'MX2': namedMX[ 'MX2' ] = MXs[ MXnb ]; MX2 = namedMX[ 'MX2' ]; console.log( "MX2 set" ); break;
            case 'MX3': namedMX[ 'MX3' ] = MXs[ MXnb ]; MX3 = namedMX[ 'MX3' ]; console.log( "MX3 set" ); break;
            case 'MX4': namedMX[ 'MX4' ] = MXs[ MXnb ]; MX4 = namedMX[ 'MX4' ]; console.log( "MX4 set" ); break;
        }
    }



    // MX0 = MXs[ 0 ];
    // MX1 = MXs[ 1 ];
    // MX2 = MXs[ 2 ];
    // MX3 = MXs[ 3 ];
    // MX4 = MXs[ 4 ];









/*
    for( var j in MXs )
    {
        MXs[ j ].write( "-1\n", function( err, results ) {
            // console.log('err ' + err);
            console.log('-1 : ' + results);
        });
    }
*/

    // SerialPort.list(function (err, ports) {
    //   ports.forEach(function(port) {
    //     console.log(port.comName);
    //     console.log(port.pnpId);
    //     console.log(port.manufacturer);
    //   });
    // });


    // SerialPort.on("data", function (data) {
    //     sys.puts("here: "+data);
    // });

});

tic();
nodePort = 8080;
baseURL = 'http://' + os.hostname() + ':' + nodePort;
server.listen( nodePort );
console.log( "Serveur node démarré et visible à l’adresse : \n" + baseURL + "\n" );
toc();

