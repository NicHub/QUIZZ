#!/usr/bin/env python
# -*- coding: utf-8 -*-





import serial
import time
import os.path
import os
import sys
import time
import threading
import thread





baudrate = 115200
MX_USBPorts = []
MX_USBPortsOrdered = []
matrix_SERIALs = []
filename = "arduinos_ports.js"




def list_USB_Devices():
    """Lists serial ports

    :returns:
        A list of available serial ports
    """
    global MX_USBPorts
    global matrix_SERIALs
    global MX_USBPortsOrdered

    import serial.tools.list_ports
    seriallist = list( serial.tools.list_ports.grep( '/dev/cu.(?!Bluetooth)' ) )

    for sl in seriallist:
        MX_USBPorts.append( sl[ 0 ] )

    print MX_USBPorts
    matrix_SERIALs = [ 0 for x in range( len( MX_USBPorts ) ) ]
    MX_USBPortsOrdered = [ 0 for x in range( len( MX_USBPorts ) ) ]





def MX_OpenSerial( Arduino_usb, Arduino_nb ):
    if not( os.path.exists( Arduino_usb ) ):
        sys.exit( "%s n’est pas connecté !" % ( Arduino_usb ) )
    try:
        port = serial.Serial( Arduino_usb, baudrate=baudrate, timeout=3.0 )
    except:
        sys.exit( "Arduino_usb est connecté, mais ne répond pas !" )

    print "%s est connecté" % ( Arduino_usb )

    tic = time.time()
    ans = port.readline()
    ans = ans[:-1]
    toc = time.time()

    nb = -1
    if   ans == "MX0":               nb = 0
    elif ans == "MX1":               nb = 1
    elif ans == "MX2":               nb = 2
    elif ans == "MX3":               nb = 3
    elif ans == "MX4":               nb = 4
    elif ans == "Controle Boutons":  nb = 5

    matrix_SERIALs[ nb ] = port
    MX_USBPortsOrdered[ nb ] = Arduino_usb
    print "Temps écoulé : %1.1f s" % ( toc-tic ) + " #### " + "%s" % ( ans ) + " #### " + "nb = %d" % nb + " #### " + Arduino_usb + "\n"
    time.sleep( 0.1 )






def MX_WriteNumber( matrix_SERIAL, x ):
    try:
        matrix_SERIAL.write( "%d\n" % ( x ) )
    except:
        print "Y a eu un blême à l’écriture !\n"





def MX_CloseSerial( matrix_SERIAL ):
    try:
        matrix_SERIAL.close()
    except:
        print "Y a eu un blême à la fermeture du port !\n"





def openRS232():
    # Ouverture de la connection RS232 des matrices en multithread
    try:
        tic = time.time()
        MX_threads = []
        i = 0
        print "###open"
        print MX_USBPorts
        print "####"
        for MX_USBPort in MX_USBPorts:
            MX_threads.append( threading.Thread( target=MX_OpenSerial, args=( MX_USBPort, i, ) ) )
            MX_threads[ i ].start()
            i += 1
        for MX_thread in MX_threads:
            MX_thread.join()
        print "C’est partit mon kiki"
        toc = time.time()
        print "Temps écoulé : %1.1f s" % ( toc-tic )
    except:
       print "Error: unable to start thread"





def afficheNombresAleatoires():
    # Affichage de nombres aléatoires
    import random
    try:
        while True:
            toc = 0
            tic = time.time()
            MX_threads = []
            x = random.randint( 1, 9999 )
            i = 0
            for matrix_SERIAL in matrix_SERIALs:
                MX_threads.append( threading.Thread( target=MX_WriteNumber, args=( matrix_SERIAL, x, ) ) )
                MX_threads[ i ].start()
                i += 1
            for MX_thread in MX_threads:
                MX_thread.join()
            toc = time.time()
            print "Temps écoulé (Affichage de nombres aléatoires) : %1.6f s" % ( toc-tic )
            while( toc - tic < 0.1 ):
                toc = time.time()
    except KeyboardInterrupt:
        pass





def afficheNombresConsecutifs():
    # Afichage de nombres consécutifs
    try:
        while True:
            for number in xrange( 1, 9999 ):
                toc = 0
                tic = time.time()
                MX_threads = []
                i = 0
                for matrix_SERIAL in matrix_SERIALs:
                    MX_threads.append( threading.Thread( target=MX_WriteNumber, args=( matrix_SERIAL, number, ) ) )
                    MX_threads[ i ].start()
                    i += 1
                for MX_thread in MX_threads:
                    MX_thread.join()
                toc = time.time()
                print "Temps écoulé (Affichage de nombres consécutifs) : %1.6f s" % ( toc-tic )
                while( toc - tic < 0.05 ):
                    toc = time.time()
    except KeyboardInterrupt:
        pass





def closeRS232():
    # Fermeture des connexions RS232
    tic = time.time()
    MX_threads = []
    i = 0
    for matrix_SERIAL in matrix_SERIALs:
        MX_threads.append( threading.Thread( target=MX_CloseSerial, args=( matrix_SERIAL, ) ) )
        MX_threads[ i ].start()
        i += 1
    for MX_thread in MX_threads:
        MX_thread.join()
    toc = time.time()
    print "Temps écoulé : %1.6f s" % ( toc-tic )





def writeUSBPortsToFile():
    with open( filename, "w" ) as f:
        for port in MX_USBPortsOrdered:
            f.write( "%s\n" % port )





if __name__ == '__main__':

    list_USB_Devices()
    openRS232()
    writeUSBPortsToFile()
    afficheNombresAleatoires()
    afficheNombresConsecutifs()
    closeRS232()


