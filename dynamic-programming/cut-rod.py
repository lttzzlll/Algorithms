''' dynamic programming cut rod '''
# note that the local optimizeal is not the whole optimazieal
# so ckeckout each item is needed!!!

MIN_INF = -999999999


# the original solve method 
# the recurse method 
# is the most powerful method
# cause this is a common method to do it
# the [states-transfer-expression]
# in fact, this is a math function []
def cut_rod(p, n):
	''' a recurse func '''

	# n == 0 is the border
	if n == 0:
		return 0

	q = MIN_INF

	# 1 is the left range border , n is the right range border
	for i in range(1, n+1):
		q = max(q, p[i] + cut_rod(p, n-i))

	return q


def memoized_cut_rod_aux(p, n, r):
	''' algorithms in a table '''

	# r[n] has a value , so return it
	if r[n] >= 0:
		return r[n]

	if n == 0:
		q = 0
	else:
		q = MIN_INF
		for i in range(1, n+1):
			q = max(q, p[i] + memoized_cut_rod_aux(p, n-i, r))

	# need the result!!!
	# record this value
	r[n] = q	

	return q 

# the table hiden a large amount informations 
# the orginal table is the problem-space
# the table is a sovle-space
# so we have a map from problem-space to sovle-place
def bottom_up_cut_rod(p, n):
	''' from bottom to up  more expilict'''

	# r is an empty table to record the data
	r = [ 0 for i in range(n+1) ]

	# the  size of the table is steadly increment
	for i in range(1, n+1):
		# the part is evaluate the limitation of i
		q = MIN_INF
		# if the best value is not in the table then evaluate, else take it
		for j in range(1, i+1):
			q = max(q, p[j] + r[i-j])
		# record the largest value
		r[i] = q

	return r




def memoized_cut_rod(p, n):
	''' using a table to record the value which had evalued '''

	# alloc memory and initialized
	r = [ MIN_INF for i in range(n+1) ]
	
	return memoized_cut_rod_aux(p, n, r)

def display_solution(s, r, n):

	print 'before display ===> %dth number is %d largest value is %d' % (n, n, r[n])
	while n > 0:
		print s[n],
		n -= s[n]
	print '\nend display '

def extended_bottom_up_cut_rod(p, n):
	r = [ 0 for i in range(n+1) ]
	s = [ 0 for i in range(n+1) ]

	for i in range(1, n+1):
		q = MIN_INF
		for j in range(1, i+1):
			res = p[j] + r[i-j]
			if q < res:
				q = res
				s[i] = j
		r[i] = q
		display_solution(s, r, i)

	return r, s

def print_cut_rod_solution(p, n):
	''' print the solution about it ''' 

	r, s = extended_bottom_up_cut_rod(p, n)

	# not zero
	# the most interesting thing is that the problem-space and the solve-space is describe below:
	# the problem-space [ the solve-space ] [ the problem space ] [ the solve-space ]
	while n > 0:
		print s[n],
		n -= s[n]



if __name__ == '__main__':
	''' test blcok '''

	# the price of rod table
	#    0  1  2  3  4  5   6   7   8   9   10
	p = [0, 1, 5, 8, 9, 10, 17, 17, 20, 24, 30]

	n = 10

	#print_cut_rod_solution(p, n)


	table, record = extended_bottom_up_cut_rod(p, n)

	'''
	# how to record the cut off steps???

	# show table
	for i in range(0, n+1):
		print '%4d' % i,
	print
	for i in range(n*4+1):
		print '=',
	print
	
	for item in p:
		print '%4d' % int(item),
	print
	for i in range(n*4+1):
		print '-',
	print
	for item in table:
		print '%4d' % int(item),
	print	
	'''
