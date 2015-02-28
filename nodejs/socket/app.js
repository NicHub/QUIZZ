

var http = require('http');
var fs = require('fs');

// Chargement du fichier index.html affiché au client
var server = http.createServer(function(req, res) {
    fs.readFile('./index.html', 'utf-8', function(error, content) {
        res.writeHead(200, {"Content-Type": "text/html"});
        res.end(content);
    });

});

// Chargement de socket.io
var io = require('socket.io').listen(server);

io.sockets.on('connection', function (socket, pseudo) {
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


    // butMX_VAL_1
    socket.on('butMX_VAL_1', function (message) {
        socket.emit('message', 'MX 1 = ' + message );
    });

    // butMX_VAL_2
    socket.on('butMX_VAL_2', function (message) {
        socket.emit('message', 'MX 2 = ' + message );
    });


});


server.listen(8080);


console.log( "C’est partit mon kiki !" );


