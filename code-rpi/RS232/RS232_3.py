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
MX_USBPorts = [
    "/dev/ttyACM0",
    "/dev/ttyACM1",
    "/dev/ttyACM2",
    "/dev/ttyACM3",
    "/dev/ttyACM4"
    ]





# Ouverture de la connection RS232 des matrices en multithread
try:
    tic = time.time()
    MX_threads = []
    matrix_SERIALs = [ 0 for x in range( len( MX_USBPorts ) ) ]
    i = 0
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
        while( toc - tic < 1 ):
            toc = time.time()
        print "Temps écoulé (Affichage de nombres aléatoires) : %1.6f s" % ( toc-tic )
except KeyboardInterrupt:
    pass





# Afichage de nombres consécutifs
try:
    while True:
        for x in xrange( 1, 9999 ):
            toc = 0
            tic = time.time()
            MX_threads = []
            i = 0
            for matrix_SERIAL in matrix_SERIALs:
                MX_threads.append( threading.Thread( target=MX_WriteNumber, args=( matrix_SERIAL, x, ) ) )
                MX_threads[ i ].start()
                i += 1
            for MX_thread in MX_threads:
                MX_thread.join()
            toc = time.time()
            print "Temps écoulé (Affichage de nombres consécutifs) : %1.6f s" % ( toc-tic )
            while( toc - tic < 1 ):
                toc = time.time()
            print "Temps écoulé (Affichage de nombres consécutifs) : %1.6f s" % ( toc-tic )
except KeyboardInterrupt:
    pass





# Afichage de nombres consécutifs
try:
    x = 7531
    MX_threads = []
    i = 0
    for matrix_SERIAL in matrix_SERIALs:
        MX_threads.append( threading.Thread( target=MX_WriteNumber, args=( matrix_SERIAL, x, ) ) )
        MX_threads[ i ].start()
        i += 1
    for MX_thread in MX_threads:
        MX_thread.join()
except KeyboardInterrupt:
    pass





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


