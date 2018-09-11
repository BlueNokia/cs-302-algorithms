
from collections import defaultdict
from sys import maxint
from Queue import PriorityQueue

Graph = defaultdict(list)
key = defaultdict(int)
parent = defaultdict(str)

def prim( root ):
	for u in Graph:
		key[u] = maxint
		parent[u] = None
	
	key[root] = 0
	Q = PriorityQueue()
	for u in key :
		Q.put((key[u], u))
		
	while not Q.empty():
		u = Q.get()
		for v in Graph[u]:
			if (v[0], key[v[0]]) in Q:
				if v[1] < key[v[0]]:
					parent[v[0]] = u
					key[v[0]] = v[1]
	

if __name__ == '__main__' :
	
	with open("inputPrim.txt", "r") as fp:
		lines = fp.readlines()
		lines = lines[1:]
		for line in lines:
			words = line.split()
			Graph[words[0]].append((words[1], int(words[2])))
			
		if words[1] not in Graph:
			Graph[words[1]]
			
	prim('0')
	spanningTree = []
	for u in parent:		
		spanningTree.append(( u, parent[u]))
		
	print sorted(spanningTree)
