
class Node:
	
	def __init__( self, data):
		self.left = None
		self.right = None
		self.data = data
		
	def insert(self, value):
		
		if self.data:
			if value < self.data:
				if self.left:
					self.left.insert(value)
				else:
					self.left = Node(value)
					
			else:
				if self.right:
					self.right.insert(value)
				else:
					self.right = Node(value)
			
		else:
			self.data = value
			
	def printTree(self):			# In-Order Traversal
		
		if self.left:
			self.left.printTree()
			
		print self.data
		
		if self.right:
			self.right.printTree()
			
			
if __name__ == '__main__':
	
	root = Node(23)
	root.insert(45)
	root.insert(12)
	root.insert(12)
	root.insert(10)
	root.insert(50)
	root.insert(30)
	
	root.printTree()
	
		
