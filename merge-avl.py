
class Node:

	def __init__( self, val):
		self.data = val
		self.left = None
		self.right = None	
	
def avlForm( root ):
	if len(root.data) >= 1:
		medIdx = len(root.data)/2
		root.left = Node(root.data[:medIdx])
		root.right = Node(root.data[medIdx+1:])
		root.data = [root.data[medIdx]]
		
		avlForm( root.left )
		avlForm( root.right )
		return
		
	else:
		return
		
def preOrder( root ):
	if len(root.data) == 0:
		return
	else:
		print root.data[0]
		preOrder( root.left)
		preOrder( root.right)
	
def inOrder( root ):
	if len(root.data) == 0:
		return
	else:
		inOrder( root.left)
		print root.data[0]
		inOrder( root.right)
		
def postOrder( root ):
	if len(root.data) == 0:
		return
	else:
		postOrder( root.left)
		postOrder( root.right)
		print root.data[0]

def Join( l1, l2):
	l0 = l1 + l2
	l0.sort()
	x = Node(l0)
	avlForm( x)
	print "The pre-order traversal of the merged-tree is:\n"
	preOrder( x)
	print "The in-order traversal of the merged-tree is:\n"
	inOrder( x)
	print "The post-order traversal of the merged-tree is:\n"
	postOrder( x)
	

if __name__ == '__main__':
	
	l1 = map( int, raw_input("Enter the elements of the first-tree :\n").split())
	l2 = map( int, raw_input("Enter the elements of the second-tree :\n").split())
	
	Join( l1, l2)
	
	
