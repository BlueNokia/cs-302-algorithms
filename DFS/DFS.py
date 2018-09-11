from collections import defaultdict

color = defaultdict(str)
parent = defaultdict(str)
G = defaultdict(list)
discover = defaultdict(int)
finished = defaultdict(int)
time = 0

def DFS ():
	for u in G :
		color[u] = 'white'
		parent[u] = None
		
	
	for u in G :
		if color[u] == 'white':
			DFS_visit( u )
			
			
def DFS_visit ( u ):
	
	global time
	time += 1
	discover[u] = time
	color[u] = 'gray'
	for v in G[u] :
		if color[v] == 'white':
			parent[v] = u
			DFS_visit( v)
			
	color[u] = 'black'
	time += 1
	finished[u] = time
	
	
if __name__ == '__main__':
	
	with open("inputFile.txt", "r") as fp :
		data = fp.readlines()
		for line in data :
			word = line.split()
			G[word[0]].append(word[1])
		
	DFS()
	
	print 'Vertice'.ljust(15), 'Discovered'.ljust(15), 'Finished'.ljust(15)
	for u in sorted(G) :
		print u.ljust(15), str(discover[u]).ljust(15), str(finished[u]).ljust(15)
		
		
		
	
