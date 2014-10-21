''' counting sort '''

def counting_sort(a, l, r, limits):
	''' counting sort '''

	b = [0 for i in range(limits+1)]
	c = [0 for i in range(limits+1)]

	for i in range(l, r+1):
		c[a[i]] += 1

	for i in range(1, limits+1):
		c[i] += c[i-1]

	for i in range(r, 0, -1):
		b[c[a[i]]] = a[i]
		c[a[i]] -= 1
	
	return b

def display(l, down, up):
	for i in range(down, up+1):
		print l[i],
	print 


if __name__ == '__main__':
	''' test block '''

	import random

	DUMB = 0
	limits = 100
	n = 20
	l = [DUMB]

	l += random.sample(range(limits), n)

	display(l, 1, n)

	s = counting_sort(l, 1, n, limits)

	display(s, 1, n)
