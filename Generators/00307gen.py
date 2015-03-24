#! /usr/bin/env python3

from random import *

for c in range(100):
  n = randint(1000, 10000);
  print(n);
  for i in range(n):
    print(randint(1,50), end=" ")
  print()
print(0)
