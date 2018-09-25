
preTree = []
postTree = []

def preOrder( tree, k ):
	if k > len(tree)-1:
		return
	preTree.append(tree[k])
	preOrder( tree, 2*k+1)
	preOrder( tree, 2*k+2)
	
def postOrder( tree, k ):
	if k > len(tree)-1:
		return
	postOrder( tree, 2*k+1)
	postOrder( tree, 2*k+2)
	postTree.append(tree[k])

if __name__ == '__main__':
	
	tempInp = raw_input('Fill the tree:\n')
	tree = tempInp.split()
	
	preOrder( tree, 0 )
	postOrder( tree, 0 )
	
	print 'Pre-order traversal:\t', preTree
	print 'Post-order traversal:\t', postTree
