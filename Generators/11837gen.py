#! /usr/bin/env python

from random import *

def random_note():
  n = randint(65, 71)
  m = randint(0, 2)
  msg = ""
  msg += chr(n)
  if (m == 0):
    return msg +'#'
  elif (m == 1):
    return msg + 'b'
  else:
    return msg

msg = ""
msg2 = ""
for i in range(100000-10000):
  msg+=random_note()
  msg+=" "
for i in range(10000):
  c =random_note()
  msg+=c
  msg+=" "
  msg2+=c
  msg2+=" "
print("100000 10000")
print(msg)
print(msg2)
print("0 0")
