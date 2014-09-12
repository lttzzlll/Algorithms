#!usr/bin/env python

''' this file is find maximum subarray O(n**2)
	use two loop'''

'''input data'''
input_data = [
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

def find_maximum_subarray(arr):
	''' find maximum subarray , return the subarray if exist 
		'''

	max_sum = -99999999999999999
	for i in range(0, len(arr)):
		total_sum = 0
		for j in range(i, len(arr)):
			total_sum += arr[j]
			if total_sum > max_sum:
				max_sum = total_sum
				l = i
				r = j
		#		print 'l==%d, r==%d' %(l, r)

	return (l, r, max_sum)
						

if __name__== '__main__':
	# each item in input_data is positive 
	res = (l, r, max_value) = find_maximum_subarray(input_data)
	print res
	for i in range(l, r+1):
		print input_data[i],
	print

	# each item in input_data is negative
	input_data_negative = [ item * -1 for item in input_data if item > 0 ]
	res = (l, r, max_value) = find_maximum_subarray(input_data_negative)
	print res
	for i in range(l, r+1):
		print input_data_negative[i],
	print

