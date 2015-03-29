#!/usr/bin/env python
# _*_ coding: utf-8 _*_

class Solution:

	# @return an integer
	def KMP_Matcher(self, s):
		pass



def compute_prefix_function(p):
	length = len(p)
	table = [ 0 for i in range(length) ] 
	# abababca 7
	# a L: None R: None | longest-repeat: None length = 0
	# ab L: a R: b | longest-repeat: None length = 0
	# aba L: a, ab R: ba, a | longest-repeat: a length = 1
	# abab L: a, ab, aba R: bab, ab, b | longest-repeat: ab length = 2
	# ababa L: a, ab, aba, abab R: baba, aba, ba, a | longest-repeat: aba length = 3
	# ababab L: a, ab, aba, abab, ababa R: babab, abab, bab, ab, b | longest-repeat: abab lenght = 4
	# abababc L: a, ab, aba, abab, ababa, ababab R: bababc, ababc, babc, abc, bc, c | longest-repeat: None length = 0
	# abababca L: a, ab, aba, abab, ababa, ababaa, abababc R: bababca, ababca, babca, abca, bca, ca, a | longest-repeat: None length = 1 
	# a ab aba abab ababa ababab abababc abababca
	# 0 00 001 0012 00123 001234 0012340 00123401

	# abcdabd 7
	# a ab abc abcd abcda abcdab abcdabd
	# 0 00 000 0000 00001 000012 0000120
	
	k = -1 
	for q in range(1, length):
		while k > 0 and p[k+1] != p[q]:
			k = table[k]
		if p[k+1] == p[q]:
			k += 1
		table[q] = k 

	for i in range(1, length):
		table[i] += 1
	return table


if __name__ == '__main__':
	''' test block '''
	s = "abababca"
	#s = "abcdabd"
	res = compute_prefix_function(s)
	l = []
	for i in range(len(s)):
		l.append((s[i], res[i]))
	for item in l:
		print item
	print
