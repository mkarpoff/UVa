#! /usr/bin/env python3

from random import *

def makeData():
  print(100)
  for n in range(100):
    for k in range(1000):
      let = randint(1, 4)
      if 1 == let:
        print("A", end="")
      elif 2 == let:
        print("C", end="")
      elif 3 == let:
        print("G", end="")
      else:
        print("T", end="")
    print()


if __name__ == "__main__":
	makeData()
