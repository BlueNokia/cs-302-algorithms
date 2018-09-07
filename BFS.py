
from collections import deque

def BFS( graph, source):
	
	visited = []
	queue = deque( [source] )
	visited.append( source )
	
	while queue :
		k = queue.popleft()
		for i in graph[k] :
			if i not in visited:
				visited.append(i)
				queue.append(i)
			
	return visited
	
	
if __name__ == '__main__' :
	
	graph = { 'a': ['b', 'c'], 'b': ['c', 'j', 'g'], 'c': ['d', 'e'], 'd': ['j'], 'e':['d', 'j'], 'f': ['b', 'h', 'i'], 'g':['f', 'h'], 'h':['a'], 'i':['k'], 'j':['f', 'k'], 'k': ['f']}
	res = BFS( graph, 'a')
	print res
