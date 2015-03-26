#! /usr/bin/env python3

from random import *

print (1)
for z in range(1):
  a = randint(1, 100000)
  print("%d %d" %(a, randint(1,500)))
  l = []
  for i in range(a):
    l.append(str(randint(-10000000, 10000000)))
  print(" ".join(l))
