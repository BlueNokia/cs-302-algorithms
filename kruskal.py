
from collections import defaultdict

Graph = defaultdict(list)
parent = defaultdict(str)
rank = defaultdict(int)

def makeSet( vertice ):
	parent[vertice] = vertice
	rank[vertice] = 0

def findP( v ):
	if parent[v] != v :
		parent[v] = findP(parent[v])
		
	return parent[v]

def union( edge ):
	x1 = findP(edge[0])
	x2 = findP(edge[1])
	
	if x1 != x2 :
		if rank[x1] > rank[x2]:
			parent[x2] = x1
		elif rank[x2] > rank[x1]:
			parent[x1] = x2
		else:
			parent[x1] = x2
			rank[x2] += 1
			
def kruskal() :
	
	spanningTree = []
	for v in Graph['vertices']:
		makeSet(v)
	edges = Graph['edges']
	edges.sort( key = lambda y : y[2] )
	
	for edge in edges:
		if findP(edge[0]) != findP(edge[1]):
			spanningTree.append(edge)
			union(edge)	

	return sorted(spanningTree)

if __name__ == '__main__':
	
	with open("inputKrus.txt", "r") as fp :
		lines = fp.readlines()
		lines = lines[1:]
		for line in lines:
			words = line.split()
			Graph['edges'].append((words[0], words[1], int(words[2])))
			if words[0] not in Graph['vertices']:
				Graph['vertices'].append(words[0])
			if words[1] not in Graph['vertices']:
				Graph['vertices'].append(words[1])
				
	print kruskal()
