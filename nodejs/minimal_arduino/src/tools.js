
var ticTime;
var tocTime;

var tic = function() {
    var timestamp = new Date();
    ticTime = timestamp.getTime();
}

var toc = function() {
    var timestamp = new Date();
    tocTime = timestamp.getTime();
    console.log( "ticTime = " + ticTime );
    console.log( "tocTime = " + tocTime );
    console.log( "Temps écoulé = " + ( tocTime - ticTime ) );
}

module.exports.tic = tic;
module.exports.toc = toc;
