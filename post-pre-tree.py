pre = []
post = []


def mainFunc(root):
	if len(root.data) == 0:
		return
	elif len(root.data) == 1:
		post.remove(post.index(pre[0]))
		pre = pre[1:]
		return
	else:
		cog = pre[0]
		postIdx = 
		
		
