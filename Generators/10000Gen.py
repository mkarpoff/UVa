#!/usr/bin/env python

mn=100

print mn
print 1
for a in range(mn):
    i = a+1
    for n in range(mn-i):
        print "%d %d" %(i, mn-n)
print "0 0"
print "0"
