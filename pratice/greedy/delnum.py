#!/usr/bin/env python2


def generateANonZeroNumber():
	import random
	while True:
		b  = random.randint(1, 1000000000)
		a = b	
		flag = False
		while a >= 10:
			res = a % 10
			if res == 0:
				break
			a /= 10
		if a != 0 and a < 10:
			return b

if __name__ == '__main__':
	''' test block '''

	import random
	t =  generateANonZeroNumber()
	res = t
	length = 0
	while res != 0:
		res /= 10
		length += 1

	print t, length/2
