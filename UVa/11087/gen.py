#! /usr/bin/env python3

print (100)
for z in range(100):
  print ("%d %d" %(100000, 501-z))
  l = []
  for i in range(100000):
    l.append(str(i*(501%(501-z)+1)))
  print(" ".join(l))
