#!/usr/bin/env python
# -*- coding: utf-8 -*-


import serial
import time
import os.path
import os
import sys
import time
import thread



baudrate = 115200



def MX_OpenSerial( Arduino_usb, Arduino_nb ):
    if not( os.path.exists( Arduino_usb ) ):
        sys.exit( "%s n’est pas connecté !" % ( Arduino_usb ) )
    try:
        port = serial.Serial( Arduino_usb, baudrate=baudrate, timeout=3.0 )
        matrix_SERIALs[ Arduino_nb ] = port
    except:
        sys.exit( "Arduino_usb est connecté, mais ne répond pas !" )

    print "%s est connecté" % ( Arduino_usb )

    tic = time.time()
    ans = port.readline()
    toc = time.time()
    print "Temps écoulé : %1.1f s" % ( toc-tic )
    print "%s\n" % ( ans[:-1] )
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



def list_USB_Devices():
    print '### Liste des devices USB ###'
    cmd = 'ls /dev/ | grep ACM'
    os.system( cmd )
    print '###'



#
list_USB_Devices()



# PORTS USB des matrices
matrix_USBPorts = [
    "/dev/ttyACM0",
    "/dev/ttyACM1",
    "/dev/ttyACM2",
    "/dev/ttyACM3",
    "/dev/ttyACM4"
    ]



# Ouverture de la connection RS232 des matrices en multithread
try:
    matrix_SERIALs = [ 0 for x in range( len( matrix_USBPorts ) ) ]
    i = 0
    for USBPort in matrix_USBPorts:
        thread.start_new_thread( MX_OpenSerial, ( USBPort, i, ) )
        i += 1
except:
   print "Error: unable to start thread"

time.sleep( 2 )



# Affichage de nombres aléatoires
import random
try:
    while True:
        x = random.randint( 1, 9999 )
        for matrix_SERIAL in matrix_SERIALs:
            thread.start_new_thread( MX_WriteNumber, ( matrix_SERIAL, x, ) )
        time.sleep( 1 )
except KeyboardInterrupt:
    pass



# Afichage de nombres consécutifs
import random
try:
    while True:
        for x in xrange( 1, 9999 ):
            for matrix_SERIAL in matrix_SERIALs:
                thread.start_new_thread( MX_WriteNumber, ( matrix_SERIAL, x, ) )
            time.sleep( 1 )
except KeyboardInterrupt:
    pass



# Affichage d’une constante
x = 7531
for matrix_SERIAL in matrix_SERIALs:
    thread.start_new_thread( MX_WriteNumber, ( matrix_SERIAL, x, ) )


time.sleep( 2 )

# Fermeture des connexions RS232
for matrix_SERIAL in matrix_SERIALs:
    thread.start_new_thread( MX_CloseSerial, ( matrix_SERIAL, ) )

time.sleep( 2 )


