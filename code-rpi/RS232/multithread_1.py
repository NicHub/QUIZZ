#!/usr/bin/python

# http://www.tutorialspoint.com/python/python_multithreading.htm

import thread
import time

# Define a function for the thread
def print_time( threadName, delay):
   count = 0
   while count < 5:
      time.sleep(delay)
      count += 1
      print "%s: %s" % ( threadName, time.ctime(time.time()) )
      # return "%s : OK" % ( threadName )

# Create two threads as follows
try:
   thread.start_new_thread( print_time, ("Thread-1", 1, ) )
   thread.start_new_thread( print_time, ("Thread-2", 2, ) )
except:
   print "Error: unable to start thread"

print "done"

try:
    while True:
        pass
except KeyboardInterrupt:
    pass