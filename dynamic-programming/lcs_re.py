

def lcs_length(x, y, l1, r1, l2, r2):
	''' calculate the common sub sequence length '''

	# out of border 
	if l1 > r1 or l2 > r2:
		return 0
	
	if x[l1] == y[l2]:
		return lcs_length(x, y, l1+1, r1, l2+1, r2) + 1
	else:
		return max(lcs_length(x, y, l1+1, r1, l2, r2), lcs_length(x, y, l1, r1, l2+1, r2))



if __name__ == '__main__':
	''' test block '''

	a1 = 'Saccggtcgagtgcgcggaagccggccgaa'
	a2 = 'Sgtcgttcggaatgccgttgctctgtaaa'
	s1 = a1.upper()[:5]
	s2 = a2.upper()[:6]

	# for test
	print s1, s2

	length = lcs_length(s1, s2, 0, len(s1)-1, 0, len(s2)-1)

	print length
