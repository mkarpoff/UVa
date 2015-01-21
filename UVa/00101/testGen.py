#! /usr/bin/python

import random

size = random.randint(1,24)
print(size)
nummoves = random.randint(0, 25)
for e in range(nummoves):
    mov = random.randint(0, 3)
    a = random.randint(0,size-1)
    b = random.randint(0,size-1)
    if mov == 0:
        print("move %d over %d" %(a, b))
    elif mov == 1:
        print("move %d onto %d" %(a, b))
    elif mov == 2:
        print("pile %d over %d" %(a, b))
    else:
        print("pile %d onto %d" %(a, b))
print("quit")
