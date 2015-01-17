from random import *

def genPair():
	r1 = randint(1, 300000)
	r2 = randint(1, 300000)
	print("%d %d" %(r1, r2))
        
def makeData(t):
	print(t)
	for a in range(t):
		print("%d %d" %(300000, 500000))
		for i in range(500000):
	                genPair()

if __name__ == "__main__":
	makeData(5)
