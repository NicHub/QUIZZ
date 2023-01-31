#!/usr/bin/python
# -*- coding: utf-8 -*-

# http://www.tutorialspoint.com/python/python_multithreading.htm

import threading
import time

class myThread (threading.Thread):
    def __init__(self, threadID, name, counter):
        threading.Thread.__init__(self)
        self.threadID = threadID
        self.name = name
        self.counter = counter
    def run(self):
        print "Starting " + self.name
        # Get lock to synchronize threads
        threadLock.acquire()
        print_time(self.name, self.counter, 3)
        # Free lock to release next thread
        threadLock.release()

def print_time(threadName, delay, counter):
    while counter:
        time.sleep(delay)
        print "%s: %s" % (threadName, time.ctime(time.time()))
        counter -= 1

def checkAlive():
    print "\nthreading.activeCount() : %s" % ( threading.activeCount() )
    for t in threads:
        print "thread%d.isAlive() : %s" % ( t.counter, t.isAlive() )




def main():
    threadLock = threading.Lock()
    threads = []
    checkAlive()
    for x in xrange( 0, 2 ):
        threads.append( myThread( x, "Thread-%d" % x, x ) )
        threads[ x ].start()


    checkAlive()

    # Wait for all threads to complete
    for t in threads:
        t.join()
        print "##"
        checkAlive()
    print "Exiting Main Thread"

    checkAlive()



if __name__ == '__main__':

    try:
        while True:
            threadLock = threading.Lock()
            threads = []
            main()
    except KeyboardInterrupt:
        pass

