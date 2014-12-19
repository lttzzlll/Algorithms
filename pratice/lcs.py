#!/usr/bin/env python

''' longest common subsequence '''


def lcs_length(x, y, m, n):
	''' evaluate longest common subsequnce '''

	b = [ [ '' for i in range(m+2) ] for i in range(n+2) ]
	c = [ [ 0 for i in range(m+2) ] for i in range(n+2) ]
#	print len(x), len(y)
	#print 'm is %d, n is %d' %(m, n)

	for i in range(0, m+1):
		for j in range(0, n+1):
			#print ' i is %d, j is %d' % (i, j)
			if x[i] == y[j]:
				c[i][j] = c[i-1][j-1] + 1
				b[i][j] = '&'
			elif c[i-1][j] >= c[i][j-1]:
				c[i][j] = c[i-1][j]
				b[i][j] = '^'
			else:
				c[i][j] = c[i][j-1]
				b[i][j] = '<'

	return c, b


def print_lcs(b, x, i, j):
	''' display the longset common subsequence '''

	#print len(b)
	#print ' i is %d, j is %d' % (i, j)

	if i == 0 or j == 0:
		return 
	if b[i][j] == '&':
		print_lcs(b, x, i-1, j-1)
		print x[i],
	elif b[i][j] =='^':
		print_lcs(b, x, i-1, j)
	else:
		print_lcs(b, x, i, j-1)


if __name__ == '__main__':
	''' test block '''

	import random

	n1 = 20
	n2 = 20

	l1 = random.sample(xrange(26), n1)
	l2 = random.sample(xrange(26), n2)

	s1 = ''
	for i in l1:
		s1 += chr(i + ord('A'))

	s2 = ''
	for i in l2:
		s2 += chr(i + ord('A'))
	
	for char in s1:
		print char,
	print 

	for char in s2:
		print char,
	print

	c, b = lcs_length(s1, s2, len(s1)-1, len(s2)-1)

	print c[len(s1)-1][len(s2)-1]

