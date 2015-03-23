#! /usr/bin/env python3

from random import *

for i in range(randint(0, 100)):
  a = randint(2, 15)
  print(a);
  for s in range(a):
    x = randint(-1000, 1000)
    y = randint(-1000, 1000)
    v = randint(0, 10000)
    l = randint(0, 10000)
    print(" %d %d %d %d" %(x,y,v,l))

print(0);
