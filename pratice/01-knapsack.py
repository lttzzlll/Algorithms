#!/usr/bin/env python

''' 0 1 knapasck '''

class Bag:

	def __init__(self, weight=0, value=0):
		self.weight = weight
		self.value = value

	def __str__(self):
		return u'%s : %s' % (self.weight, self.value)


def dp(l, n, w):
	pass

if __name__ == '__main__':
	'''test block '''

	n = 5
	w = 10
	l = []
	l.append(Bag(2, 6))
	l.append(Bag(2, 3))
	l.append(Bag(6, 5))
	l.append(Bag(5, 4))
	l.append(Bag(4, 6))

	print dp(l, n, w)


'''
if __name__ == '__main__':
	''' test block '''

	import random

	n = 3
	low = 3
	up = 10

	l = []

	for i in range(n):
		l.append(Knapasck(weight=random.randint(low, up), value=random.randint(low, up)))
	
	for i in l:
		print i
	
	w = int(input())

	print dp(l, w)
'''
