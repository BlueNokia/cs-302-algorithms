
from tree-recursion import *

class avl(Node):
	
	def __init__(self, data):
		Node.__init__(self, data)
		self.height = 1
		
	def insert(self, value):
		Node.insert(self, value)
		
		self.height = 1 + max( self.left.getHeight(), self.right.getHeight())
		balance = self.getBalance()
		
		## LL-case
		if balance >1 and value < self.left.data:
			self.rightRotate()
			
		## RR-case
		elif balance <-1 and value > self.right.data:
			self.leftRotate()
		## LR-case
		elif balance >1 and value > self.left.data:
			self.left.leftRotate()
			self.rightRotate()
		## RL-case
		elif balance <-1 and value < self.right.data:
			self.right.rightRotate()
			self.leftRotate()
			
			
	def leftRotate(self):
		Y = self.right
		Y2 = Y.left
		
		Y.left = self
			
		
