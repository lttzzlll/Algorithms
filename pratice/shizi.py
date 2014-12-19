#!/usr/bin/env python

SIZE = 1000

# states transfer function
# f(i, j) = max{ f(i, k) + f(k+1, j) + s[i][k] + s[k+1][j] }
def fmax(l, i, j):
	if i == j: # just one element
		return l[i]
		

if __name__ == '__main__':
	''' test block '''

	#    0  1  2  3  4
	l = [0, 4, 4, 5, 9]

	s = [ [ 0 for i in range(SIZE) ] for i in range(SIZE) ]
	n = 4

	print fmax(l, s, 1, n)
