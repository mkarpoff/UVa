#! /usr/bin/env python
from random import *

for i in range(100):
  size = randint(10, 1000)
  print(randint(pow(10,size), pow(10,(size+1))-1))
