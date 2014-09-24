#!usr/bin/env python
''' merge sort  '''

def merge(l, left, middle, right):
	''' merge 'two array' into 'one array' '''

	#print 'left is %d  middle is %d  right is %d' %(left, middle, right)

	t = []
	i = left 
	j = middle + 1 

	if middle - left + 1 > right - middle:
		while i <= middle:
			if j <= right and  l[j] < l[i]:
				t.append(l[j])
				j+=1
				continue
			t.append(l[i])
			i+=1
		while j <= right:
			t.append(l[j])
			j+=1
	else:
		while j <= right:
			if i <= middle and l[i] < l[j]:
				t.append(l[i])
				i+=1
				continue
			t.append(l[j])
			j+=1
		while i <= middle:
			t.append(l[i])
			i+=1

	#print ' t is %d numbers  l is %d numbers ' % (len(t), right + 1 - left)
	#show(t, msg = ' show list t')
	#show(l, msg = ' show list l')
	i = left
	for item in t:
		l[i] = item
		i+=1


def merge_sort(l, left, right):
	''' merge sort '''

	if left == right:
		return 
	middle = (left + right) / 2;
	merge_sort(l, left, middle);
	merge_sort(l, middle+1, right);
	merge(l, left, middle, right);

def show(l, msg = ''):
	''' show a array or a list in 0 ... lenght '''

	for item in l:
		print item,
	print


if __name__ == '__main__':
	import random
	l = random.sample(xrange(100), 100)
	show(l)
	merge_sort(l, 0, 99)
	show(l)

