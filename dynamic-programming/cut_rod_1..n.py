''' dynamic programming : cur rod '''

MIN_INF = -999999999

count_times = 0
def cut_rod_n_1(p, n):
	
	if n == 0:
		return 0

	q = MIN_INF

	for i in range(1, n+1):
		q = max(q, p[i] + cut_rod_n_1(p, n-i))

	print ' n is %d, q is %d ' % (n, q)
	global count_times
	count_times += 1

	return q

'''
#  this is the sub qustions divide
def cut_rod_1_n(p, index, n):

	# out of border
	if index > n:
		return 0

	q = MIN_INF

	for i in range(index, n+1):
		print 'i is %d' % i,
		q = max(q, p[i] + cut_rod_1_n(p, index+i, n))
	
	global count_times
	count_times += 1
	print ' index is %d, q is %d' % (index, q)
'''	

# thinking about it, the [ n ] represent the population of the problems 
# so this is no saying: from left to right , or from right to left
# only from big problems to small problems and from small problems to big problems
def cut_rod(p, n):
	''' this is a re-version of the original version '''

	if n < 1:
		return 0

	q = MIN_INF

	for i in range(n, 0, -1):
		q = max(q, p[i] + cut_rod(p, n-i))
	
	global count_times
	count_times += 1
	print 'n is %d, q is %d' % (n, q)

	return q


if __name__ == '__main__':
	''' test block '''

	p = [0, 1, 5, 8, 9, 10, 17, 17, 20, 24, 30]	

	n = 10

	res = cut_rod(p, n)

	print res
	
	print ' total calculate times is %d ' % count_times
