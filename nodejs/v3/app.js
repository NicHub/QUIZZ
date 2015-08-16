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



"use strict";



var express       = require( 'express' );
var os            = require( 'os' );
var socketIO      = require( 'socket.io' );
var RS232         = require( './src/RS232.js' );
var child_process = require( 'child_process' );
var Stopwatch     = require( 'timer-stopwatch' ); // https://github.com/MickCrozier/timer-stopwatch
var util          = require( 'util' );



/**
 * express
 */
var nodePort  = 8080;
var app       = express();
app.use( express.static( 'public' ) );
var server = app.listen( nodePort, function () {
    console.log( 'Serveur Node démarré à\nhttp://%s:%s', os.hostname(), nodePort );
});



/**
 * Initialisation du timer de compte à rebours
 */
var options = {
    refreshRateMS: 1000,
    almostDoneMS:  5000,
}






/**
 * socket.io
 */
var io = socketIO.listen( server );
RS232.on( 'ready', function() {
    console.log( '### RS232 READY ###' );
    io.sockets.on( 'connection', function( socket ) {



        var timer = new Stopwatch( 60000, options );



        /**
         * Musique de démarrage
         */
        playSound( 'winner_sound' );



        /**
         * Initialisation de socket.io
         */
        var msg = "Un client s’est connecté.";
        console.log( msg );
        socket.emit( 'connectionStart', msg );



        /**
         * Initialisation des matrices
         */
        MX0Write( '-5' );
        MX1Write( '-5' );
        MX2Write( '-5' );
        MX3Write( '-5' );
        MX4Write( '-5' );

        MX0Write( '60' );
        MX1Write(  '0' );
        MX2Write(  '0' );
        MX3Write(  '0' );
        MX4Write(  '0' );



        /**
         * Gestion du son
         */
        function playSound( Sound ) {
            switch( Sound )
            {
                case 'loser_sound':   Sound = '/home/pi/quizz/sons/wah_wah_sound.aif';                break;
                case 'shotgun_sound': Sound = '/home/pi/quizz/sons/DivingSynthEffects04.aif';         break;
                case 'winner_sound':  Sound = '/home/pi/quizz/sons/That_s_All_Folks_WDJRfvbCdh8.aif'; break;
            }
            if( process.platform == 'linux' ) {
                child_process.execFile( 'paplay', [ Sound ], function( err, result ) {
                    console.log( Sound )
                });
            }
        };

        socket.on( 'playSound', function( Sound ) {
            playSound( Sound );
        });



        /**
         * Gestion de l’affichage
         */
        // MX0
        socket.on( 'butMX_VAL_0', function( cmd ) {
            MX0Write( cmd );
        });
        // MX1
        socket.on( 'butMX_VAL_1', function( cmd ) {
            MX1Write( cmd );
        });
        // MX2
        socket.on( 'butMX_VAL_2', function( cmd ) {
            MX2Write( cmd );
        });
        // MX3
        socket.on( 'butMX_VAL_3', function( cmd ) {
            MX3Write( cmd );
        });
        // MX4
        socket.on( 'butMX_VAL_4', function( cmd ) {
            MX4Write( cmd );
        });
        // Envoyer à toutes les matrices
        socket.on( 'sendToAll', function( cmd ) {
            MX0Write( cmd );
            MX1Write( cmd );
            MX2Write( cmd );
            MX3Write( cmd );
            MX4Write( cmd );
        });

        function MX0Write( cmd ) {
            cmd = String( cmd ) + "\n";
            RS232.devices[ 'MX0' ].write( cmd, function( err, results ) {
                console.log( 'Write ' + cmd + ' to MX0 | results ' + results );
            });
        };

        function MX1Write( cmd ) {
            cmd = String( cmd ) + "\n";
            RS232.devices[ 'MX1' ].write( cmd, function( err, results ) {
                console.log( 'Write ' + cmd + ' to MX1 | results ' + results );
            });
        };

        function MX2Write( cmd ) {
            cmd = String( cmd ) + "\n";
            RS232.devices[ 'MX2' ].write( cmd, function( err, results ) {
                console.log( 'Write ' + cmd + ' to MX2 | results ' + results );
            });
        };

        function MX3Write( cmd ) {
            cmd = String( cmd ) + "\n";
            RS232.devices[ 'MX3' ].write( cmd, function( err, results ) {
                console.log( 'Write ' + cmd + ' to MX3 | results ' + results );
            });
        };

        function MX4Write( cmd ) {
            cmd = String( cmd ) + "\n";
            RS232.devices[ 'MX4' ].write( cmd, function( err, results ) {
                console.log( 'Write ' + cmd + ' to MX4 | results ' + results );
            });
        };


        /**
         * Gestion du timer de compte à rebours
         */
        socket.on( 'setCountdownTime', function( countdownTime ) {
            console.log( 'countdownTime = ' + countdownTime );
            timer.countDownMS = countdownTime;
            MX0Write( String( countdownTime ) );
        });

        socket.on( 'startResetTimer', function( message ) {
            console.log( 'timer.ms = ' + timer.ms );
            console.log( 'timer.hasBeenStopped = ' + timer.hasBeenStopped );
            console.log( 'timer.runTimer = ' + timer.runTimer );
            if( timer.runTimer ) {
                timer.stop();
                console.log( 'timer stopped | timer.ms =' + timer.ms );
                timer.reset();
                console.log( 'timer reset | timer.ms =' + timer.ms );
                socket.emit( 'timerDone', Math.round( timer.countDownMS / 1000  ) );
            } else {
                timer.start();
                MX0Write( String( "-5" ) );
                console.log( 'timer started | timer.ms =' + timer.ms );
                socket.emit( 'timerStart', Math.round( timer.countDownMS / 1000  ) );
            }
        });

        timer.on( 'time', function( time ) {

            console.log( "timer.ms = " + timer.ms );
            var timerMS = Math.round( timer.ms / 1000 );

            // Essai de triche en attribuant à timer.ms sa valeur arrondie pour
            // supprimer les erreurs du timer. Si on ne le fait pas, les
            // erreurs s’accumulent et le timer affiche deux fois les mêmes
            // valeurs à cause des erreurs d’arrondi. L’exactitude est
            // évidement déplorable, mais il s’agit d’un quizz et pas d’une
            // horloge atomique.
            // Mais ce truc ne fonctionne pas...
            // timer.ms = timerMS * 1000;

            var curTime = String( timerMS );
            console.log( "timer.ms = " + timer.ms );
            socket.emit( 'timeRemaining', curTime );
            MX0Write( curTime );
            console.log( "timerMS = " + timerMS );
            console.log( "curTime = " + curTime );
        });

        timer.on( 'done', function() {
            timer.reset();
            MX0Write( String( "-5" ) );
            console.log( 'Timer is complete' );
            socket.emit( 'timerDone', Math.round( timer.countDownMS / 1000  ) );
            playSound( 'loser_sound' );
        });

        timer.on( 'almostdone', function() {
            console.log( 'Timer is almost complete' );
            MX0Write( String( "-4" ) );
            socket.emit( 'timerAlmostdone', Math.round( timer.ms / 1000  ) );
        });



        /**
         * Gestion des boutons physiques
         */
        RS232.devices[ 'CB0' ].on( 'data', function( data ) {
            switch( data[ 0 ] ) {
                case 56: var buttonID = 1; var RS232port = 'MX1'; break;
                case 52: var buttonID = 2; var RS232port = 'MX2'; break;
                case 50: var buttonID = 3; var RS232port = 'MX3'; break;
                case 49: var buttonID = 4; var RS232port = 'MX4'; break;
            };
            if( timer.runTimer ) {
                timer.stop();
                RS232.devices[ 'CB0' ].write( "1\n" );
                playSound( 'shotgun_sound' );
                console.log( 'arduinoButtonPressed: ' + buttonID );
                io.sockets.emit( 'arduinoButtonPressed', buttonID );
                RS232.devices[ RS232port ].write( "-4\n", function( err, results ) {
                    console.log( 'Write to -- results ' + results );
                });
            }
        });

        socket.on( 'resumeTimer', function( message ) {
            var msg = "On reprend le décompte " + message;
            console.log( msg );
            if( ! timer.runTimer ) {
                timer.start();
            }
            videoNormalePourTous();
        });

        socket.on( 'stopTimer', function( message ) {
            var msg = "Réponse juste, on arrête le timer " + message;
            console.log( msg );
            timer.stop();
            console.log( 'timer stopped | timer.ms =' + timer.ms );
            timer.reset();
            console.log( 'timer reset | timer.ms =' + timer.ms );
            socket.emit( 'timerDone', Math.round( timer.countDownMS / 1000  ) );
            videoNormalePourTous();
        });


        /**
         *
         */
        socket.on( 'inputButtonClicked', function( message ) {
            var msg = "Le serveur a reçu " + message;
            console.log( msg );
            socket.emit( 'serverAcknowledge', msg );
        });

        socket.on( 'disconnect', function( socket ) {
            console.log( 'Client déconnecté!' );
        });

        function videoNormalePourTous() {
            RS232.devices[ 'MX1' ].write( "-5\n", function( err, results ) {
                console.log( 'Write -5 to MX1 results ' + results );
            });
            RS232.devices[ 'MX2' ].write( "-5\n", function( err, results ) {
                console.log( 'Write -5 to MX2 results ' + results );
            });
            RS232.devices[ 'MX3' ].write( "-5\n", function( err, results ) {
                console.log( 'Write -5 to MX3 results ' + results );
            });
            RS232.devices[ 'MX4' ].write( "-5\n", function( err, results ) {
                console.log( 'Write -5 to MX4 results ' + results );
            });
        };

    });
});
