#!/usr/bin/env python

'''  maximum subarray 
	'''


'''input data'''
l = [ 
	13,
	-3,
	-25,
	20,
	-3,
	-16,
	-23,
	18,
	20,
	-7,
	12,
	-5,
	-22,
	15,
	-4,
	7
]


def find_max_crossing_subarray(a, low, mid, high):
	''' find max cossing subarray 
		'''

	# init values 
	left_sum =  right_sum = -9999999999999999999999999999999
	max_left = max_right = mid

	total_sum = 0
	i = mid
	while i >= low:
#	print ' in find max crossing ... in loop i==%d' %i
		total_sum += a[i]
		if total_sum > left_sum:
			left_sum = total_sum
			max_left = i
		i -= 1

	total_sum = 0
	j = mid + 1
	while j <= high:
		total_sum += a[j]
		if total_sum > right_sum:
			right_sum = total_sum
			max_right = j
		j += 1
	
	return (max_left, max_right, left_sum + right_sum)

cnt = 0

def find_maximum_subarray(a, low, high):
	''' find maximum subarray
		'''
	global cnt
	cnt += 1
#	print " in find maximum subarray low is cnt== %d low==%d high== %d" %(cnt, low, high)
	if high == low:
		return (low, high, a[low])
	else:
		mid = ((low + high)/2)
		(right_low, right_high, right_sum) = find_maximum_subarray(a, mid+1, high)
		(left_low, left_high, left_sum) = find_maximum_subarray(a, low, mid)
		(cross_low, cross_high, cross_sum) = find_max_crossing_subarray(a, low, mid, high)
		
		if left_sum >= right_sum and left_sum >= cross_sum:
			return (left_low, left_high, left_sum)
		elif right_sum >= left_sum and right_sum >= cross_sum:
			return (right_low, right_high, right_sum)
		else:
			return (cross_low, cross_high, cross_sum)

''' main '''
if __name__ == '__main__':
	print find_maximum_subarray(l, 0, len(l)-1)

