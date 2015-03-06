#!/usr/bin/env python

from random import *

#P = randint(1, 100)
P = 100
#R = randint(0, min(4950,P*P))
R = 4950
BH = randint(1, P)
OF = randint(1, P)
YH = randint(1, P)
M = randint(1, P)

print("%d %d %d %d %d %d" %(P,R,BH,OF,YH,M))
for i in range(R):
  print("%d %d %d" %(randint( 0, P), randint( 0,P), randint(0, 100)))
