

var http = require('http');
var fs = require('fs');
var osname = process.platform;

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
    }




    for( var j in Arduinos )
    {
        console.log( Arduinos[ j ] );
    }




    /*

    MX 0

    */
    var SerialPort = require("serialport").SerialPort
    var MX0 = new SerialPort( Arduinos[ 0 ], {
      baudrate: 115200
    }, false); // this is the openImmediately flag [default is true]

    MX0.open(function (error) {
        if ( error )
        {
            console.log('failed to open: '+error);
        }
        else
        {
            console.log('open');
            MX0.on('data', function(data) {
                console.log('data received: ' + data);
            });
            MX0.write("10\n", function(err, results) {
                // console.log('err ' + err);
                console.log('results ' + results);
            });
        }
    });


    /*

    MX 1

    */
    var SerialPort = require("serialport").SerialPort
    var MX1 = new SerialPort( Arduinos[ 1 ], {
      baudrate: 115200
    }, false); // this is the openImmediately flag [default is true]

    MX1.open(function (error) {
        if ( error )
        {
            console.log('failed to open: '+error);
        }
        else
        {
            console.log('open');
            MX1.on('data', function(data) {
                console.log('data received: ' + data);
            });
            MX1.write("11\n", function(err, results) {
                // console.log('err ' + err);
                console.log('results ' + results);
            });
        }
    });


    /*

    MX 2

    */
    var SerialPort = require("serialport").SerialPort
    var MX2 = new SerialPort( Arduinos[ 2 ], {
      baudrate: 115200
    }, false); // this is the openImmediately flag [default is true]

    MX2.open(function (error) {
        if ( error )
        {
            console.log('failed to open: '+error);
        }
        else
        {
            console.log('open');
            MX2.on('data', function(data) {
                console.log('data received: ' + data);
            });
            MX2.write("12\n", function(err, results) {
                // console.log('err ' + err);
                console.log('results ' + results);
            });
        }
    });



    /*

    MX 3

    */
    var SerialPort = require("serialport").SerialPort
    var MX3 = new SerialPort( Arduinos[ 3 ], {
      baudrate: 115200
    }, false); // this is the openImmediately flag [default is true]

    MX3.open(function (error) {
        if ( error )
        {
            console.log('failed to open: '+error);
        }
        else
        {
            console.log('open');
            MX3.on('data', function(data) {
                console.log('data received: ' + data);
            });
            MX3.write("13\n", function(err, results) {
                // console.log('err ' + err);
                console.log('results ' + results);
            });
        }
    });


    /*

    MX 4

    */
    var SerialPort = require("serialport").SerialPort
    var MX4 = new SerialPort( Arduinos[ 4 ], {
      baudrate: 115200
    }, false); // this is the openImmediately flag [default is true]

    MX4.open(function (error) {
        if ( error )
        {
            console.log('failed to open: '+error);
        }
        else
        {
            console.log('open');
            MX4.on('data', function(data) {
                console.log('data received: ' + data);
            });
            MX4.write("14\n", function(err, results) {
                // console.log('err ' + err);
                console.log('results ' + results);
            });
        }
    });

});


server.listen( 8080 );
console.log( "C’est partit mon kiki !" );


