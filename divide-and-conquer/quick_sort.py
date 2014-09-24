#!usr/bin/env python
''' quick sort '''

import random

def partition(l, left, right):
	''' select a pivot '''

	pos =  random.choice(range(left, right))

	i = left
	j = right

	while i != j:

		while i!=j and l[i] <= l[pos]:
			i+=1

		if i!=j:
			l[i], l[pos] = l[pos], l[i]
			pos = i

		while i!=j and l[j] >= l[pos]:
			j-=1

		if i!=j:
			l[j], l[pos] = l[pos], l[j]
			pos = j


def quick_sort(l, left, right):
	''' quick sort define '''

	if left == right:
		return 
	
	pivot = partition(l, left, right);
	quick_sort(l, left, pivot);
	quick_sort(l, pivot+1, right);


def show(l, msg=''):
	for item in l:
		print item,
	print


if __name__ == '__main__':

	input_data = random.sample(xrange(100), 100)
	show(input_data)
	quick_sort(input_data, 0, 99);
	show(input_data)


