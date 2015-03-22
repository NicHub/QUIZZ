osname = process.platform;

if( osname == "darwin" )
{
	console.log( "On est sur le Mac" );
}
else if( osname == "linux" )
{
	console.log( "On est sur le Rpi" );
}
else 
{
        console.log( "On est foutu, l’OS n’est pas connu !" );
}
