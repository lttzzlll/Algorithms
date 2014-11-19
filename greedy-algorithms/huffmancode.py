''' huffman code '''

#!/usr/bin/env python

class Node:
	''' binary tree '''

	def __init__(self, name='', frequency=0, code=''):
		self.name = name
		self.frequency = frequency
		self.code = code
		self.parent = None
		self.leftChild = None
		self.rightChild = None


	# why __unicode__ is unUsed !
	#def __unicode__(self):
		#return unicode(self.name)

	def __str__(self):
		return str('node [%s] frequency is [%d] code is [%s]' % (self.name, self.frequency, self.code))

	def __unicode__(self):
		return self.name

	def __eq__(self, x):
		return self.frequency == x.frequency

	def __lt__(self, x):
		return self.frequency < x.frequency

	def __le__(self, x):
		return self.frequency <= x.frequency

	def __gt__(self, x):
		return self.frequency > x.frequency
	
	def __ge__(self, x):
		return self.frequency >= x.frequency


class Queue:
	''' queue '''

	def __init__(self):
		self.content = []
			

	def __len__(self):
		return len(self.content)


	def __iter__(self):
		# will be compeleted later
		pass

	def insert(self, element):
		return self.content.append(element)

	def findMinIndex(self):
		pos = 0
		for i in range(1, self.__len__()):
			if self.content[i] < self.content[pos]:
				pos = i
		return pos

	def findMinElement(self):
		return self.content[self.findMinIndex()]

	def deleteElement(self, element):
		self.content.remove(element)

	def deleteByIndex(self, index):
		return self.content.remove(self.content[index])

	def extractMin(self):
		minElement = self.findMinElement()	
		self.deleteElement(minElement)
		return minElement


def huffmanCode(q):
	for i in range(0, len(q)-1):
		node1 = q.extractMin()
		node2 = q.extractMin()
		newNode = Node()
		newNode.name = node1.name + node2.name
		newNode.frequency = node1.frequency + node2.frequency
		newNode.leftChild = node1
		newNode.rightChild = node2
		node1.parent = newNode
		node2.parent = newNode

		q.insert(newNode)

	return q.extractMin()


def codeDisplay(node):
	print 'node [%s] code [%s] ' % (node.name, node.code)

def visitTree(Ntree):
	''' inorder visit '''
	
	if Ntree.leftChild is None or Ntree.rightChild is None:
		codeDisplay(Ntree)
		return 
	
	Ntree.leftChild.code += Ntree.code
	Ntree.leftChild.code += '0'

	visitTree(Ntree.leftChild)

	Ntree.rightChild.code += Ntree.code
	Ntree.rightChild.code += '1'

	visitTree(Ntree.rightChild)



if __name__ == '__main__':
	''' test and drive block '''
	
	import random

	n = 10

	charSet = []
	beginChar = 'A'
	beginPos = ord('A')
	for i in range(n):
		charSet.append(chr(i+beginPos))


	nList = []
	for item in charSet:
		nList.append(Node(name=item))

	# randomly generate a unique integer list
	Sum = 100
	sourceL = range(Sum/(n-1))
	iL = random.sample(sourceL, n-1)
	for i in range(n-1):
		while iL[i] == 0:
			iL[i] = random.randint(1, 10)
	iL.append(Sum - sum(iL))

	for i in range(n):
		nList[i].frequency = iL[i]

	q = Queue()
	for node in nList:
		q.insert(node)
		
	# greedy algorithms start here 
	#end
	#Ntree = huffmanCode(q)

	#visitTree(Ntree)
	qq = Queue()
	qq.insert(Node('A', 45))
	qq.insert(Node('B', 13))
	qq.insert(Node('C', 12))
	qq.insert(Node('D', 16))
	qq.insert(Node('E', 9))
	qq.insert(Node('F', 5))
	

	Ntree = huffmanCode(qq)

	visitTree(Ntree)

