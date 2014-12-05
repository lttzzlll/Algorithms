#!/usr/bin/env python

''' matrix chain multiply '''


MAX_INF = 9999999999


class Matrix:

	def __init__(self, order=0, row=0, col=0):
		self.order = order
		self.row = row
		self.col = col

	def __unicode__(self):
		return u'%d %d %d' % (self.order, self.row, self.col)

	def __str__(self):
		return u'%d %d %d' % (self.order, self.row, self.col)


# will not be used in this example
def matrix_multiply(a, b):
	''' multiply two martix : check if can be multiply fisrtly '''

	if a.col != b.row:
		return 

	c = [ [ 0 for i in range(b.col+1) ] for i in range(a.row+1) ]

	for i in range(1, a.row+1):
		for j in range(1, b.col+1):
			c[i][j] = 0
			for k in range(1, a.col+1):
				c[i][j] += a[i][k] * b[k][j]

	return c


# --------------------<p> is the matrix chain n is the size 
def matrix_chain_order(p, n):

	# table [m] is the solve-spae and table [s] is just a table to record each steps 
	# so the table [m] and table [s] will change in programming !
	m = [ [ 0 for i in range(n+1) ] for i in range(n+1) ] 
	s = [ [ 0 for i in range(n+1) ] for i in range(n+1) ]

	for i in range(n+1):
		m[i][i] = 0
		

	# <l> is the step size
	for l in range(2, n+1):
		# <i> index each step-size matrix chain 
		for i in range(1, (n-l+1)+1):
			# <i> is the start-index
			# <j> is the end-index
			# j increment with i for each time
			# so if i is fixed , then j is fixed
			# this is the func j = f (i+l-1) just a mapping
			# to discuss each matrix chain length
			j = i + l - 1
			m[i][j] = MAX_INF
			# k is the split point : also pivot it divide the matrix chain into two part 
			# and evaluate the pivot mutiply cost  COST
			for k in range(i, (j-1)+1):
				# bug occured here
				each_multiply_times = p[i].col
				each_add_times = each_multiply_times - 1
				multiply_times = p[i].row * p[j].col
				total_times = (each_multiply_times + each_add_times)*multiply_times
				q = m[i][k] + m[k+1][j] + total_times
				if q < m[i][j]:
					m[i][j] = q 
					s[i][j] = k
					#print 's[%d][%d] is %d' %(i, j, s[i][j])

	return m, s


def print_optimal_parens(p, s, i, j):
	
	# if this condition will happen
	if i > j:
		return 
	if i == j:
		print 'A%d' % p[i].order,
	else:
		print '(',
		print print_optimal_parens(p, s, i, s[i][j]),
		print print_optimal_parens(p, s, s[i][j]+1, j),
		print ')',


def get_optimal_parens(p, s, i, j):

	# bad state, should not hapapen
	if i == j:
		return 'A' + str(p[i].order)
	else:
		return '(' + get_optimal_parens(p, s, i, s[i][j]) + get_optimal_parens(p, s, s[i][j]+1, j) + ')'


    
'''
	a0 = Matrix(0, 0, 0)
	a1 = Matrix(1, 30, 35)
	a2 = Matrix(2, 35, 15)
	a3 = Matrix(3, 15, 5)
	a4 = Matrix(4, 5, 10)
	a5 = Matrix(5, 10, 20)
	a6 = Matrix(6, 20, 25)
	p = [a0, a1, a2, a3, a4, a5, a6]

	n = 6
'''
	
if __name__ == '__main__':
	''' test block '''

	import random

	n = 10
	low = 10
	up = 100
	p = []

	uniqueNumbers = random.sample(xrange(low, up), n+1)
		
	print uniqueNumbers, len(uniqueNumbers)

	# dumb
	p.append(Matrix())
	for i in range(1, n+1):
		p.append(Matrix(i, uniqueNumbers[i-1], uniqueNumbers[i]))

        
	for item in p:
		print item


	table, solution = matrix_chain_order(p, n)

	#for row in table:
	#	for item in row:
	#		print '%8d' % item,
	#	print 
	
	print table[1][n]
	
    #print_optimal_parens(p, solution, 1, n)

    #optimal_parens = get_optimal_parens(p, solution, 1, n)
	
	#print optimal_parens

	print_optimal_parens(p, solution, 1, n)

