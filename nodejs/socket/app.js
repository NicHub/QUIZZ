

var http = require('http');
var fs = require('fs');
var osname = process.platform;

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
    var Arduinos = [];
    if( osname == "darwin" )
    {
        console.log( "On est sur le Mac" );
        for( var i in USBdevices )
        {
            if( USBdevices[ i ].substr( 0, 12 ) == "tty.usbmodem" )
            {
                Arduinos.push( '/dev/' + USBdevices[ i ] );
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
                Arduinos.push( '/dev/' + USBdevices[ i ] );
            }
        }
    }
    else
    {
        console.log( "On est foutu, l’OS n’est pas connu !" );
        process.exit( 1 );
    }




    for( var j in Arduinos )
    {
        console.log( Arduinos[ j ] );
    }
    toc();




    var MXs = [];

    /*

    MXs

    */
    var SerialPort = require( "serialport" ).SerialPort;
    for( var j in Arduinos )
    {
        console.log( "j = " + j );
        MXs[ j ] = new SerialPort( Arduinos[ j ], {
          baudrate: 115200
        }, true); // this is the openImmediately flag [default is true]

        MXs[ j ].open( function( error ) {
            if( error )
            {
                console.log( 'failed to open: ' + error );
            }
            else
            {
                console.log( 'open MX ' + j );
                MXs[ j ].on( 'data', function( data ) {
                    console.log( 'data received: ' + data );
                });
                MXs[ j ].write( "10\n", function( err, results ) {
                    // console.log('err ' + err);
                    console.log( 'results ' + results );
                });
            }
        });
    }

    MX0 = MXs[ 0 ];
    MX1 = MXs[ 1 ];
    MX2 = MXs[ 2 ];
    MX3 = MXs[ 3 ];
    MX4 = MXs[ 4 ];

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
server.listen( 8080 );
console.log( "C’est partit mon kiki !" );
toc();
