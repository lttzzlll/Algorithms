#!usr/bin/env python
''' hanoi '''


def move(plate, a, b
def hanoi(plates, int n, int a, int b, int c):
	''' n plents move a to b  c is tmo plant '''

	if n > 0:
		return

	hanoi(plates, n-1, a, c, b);
	move(plates[n-1], a, b);
	



if __name__ == '__main__':
	n = 10
	input_data = [ 'this is %d plate' % ( for i in xrange(n) ) ]
	hanoi(input_data, n, a, b, c);
