''' optimal binary search tree '''

MAX_INF = 9999999

def optimal_bst(p, q, n):
	''' optimal binary search tree '''

	e = [ [ 0 for i in range(n+2) ] for i in range(n+2) ] 
	w = [ [ 0 for i in range(n+2) ] for i in range(n+2) ]
	root = [ [ 0 for i in range(n+2) ] for i in range(n+1) ] 

	for i in range(1, n+2):
	#	print 'i is %d q[%d] is %.2lf'  % (i, i, q[i-1])
		w[i][i-1] = e[i][i-1] = q[i-1]

	for l in range(1, n+1):
		for i in range(1, n-l+1 + 1):
			j = i + l - 1
			e[i][j] = MAX_INF
			w[i][j] = w[i][j-1] + p[j] + q[j]
			for r in range(i, j+1):
				t = e[i][r-1] + e[r+1][j] + w[i][j]
				if t < e[i][j]:
					e[i][j] = t
					root[i][j] = r

	return e, root, w

def construct_optimal_bst(root):
	''' construct the optiaml binary search tree '''

	# this is the differ between note and doc string 
	# how to represent left child and right child???
	# the root node: from the recoginse of the table
	if i == 1 and j == n:
		print 'k%d is the root' % root[i][j],
		return 
	if i <= j:
		print 'k%d is the left child of %d' % root[i-1][j],
		print 'k%d is the right child of %d' % root[i][j],
	else:
		print 'd%d is the left child of %d' % root[i-1][j],
		print 'd%d is the right child of %d' % root[i][j],

# a global varible to fix a bug
mark = [ [ 0 for i in range(11) ] for i in range(11) ] 

countTimes = 0

def mid_visit_tree(root, i, j):
	''' middle visit a binary search tree '''

	if i <= j:
		if mark[i][j] == 0:
			global countTimes
			countTimes += 1
			print 'tree[%d]' % root[i][j]
			mark[i][j] = 1
		else:
			pass
		# left sub tree
		mid_visit_tree(root, i, j-1)
		# right sub tree
		mid_visit_tree(root, i+1, j)
		

if __name__ == '__main__':
	''' test block '''

	#    0  1     2     3     4     5
	p = [0, 0.15, 0.10, 0.05, 0.10, 0.20]
	q = [0.05, 0.10, 0.05, 0.05, 0.05, 0.10]

	n = 5

	e, r, w= optimal_bst(p, q, n)

	print '%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%'
	for i in range(1, n+1):
		for j in range(1, n+1):
			print '%.2lf' % e[i][j],
		print


	for i in range(1, n+1):
		for j in range(1, n+1):
			print '%2d' % r[i][j],
		print
	
	print '**********************************'

	for i in range(1, n+2):
		for j in range(1, n+1):
			print '%.2lf' % w[i][j],
		print
	print '^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^'
	print e[1][n]
	print '^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^'

	print '================constructing the bst==========='
	#construct_optimal_bst(r)
	mid_visit_tree(r, 1, 5)
	print '================end constructing =============='

	print 'countTime is %d' % countTimes
