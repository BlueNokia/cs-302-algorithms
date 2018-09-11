from DFS import *

if __name__ == '__main__':
	
	with open("inputFile.txt", "r") as fp :
		data = fp.readlines()
		for line in data :
			word = line.split()
			G[word[0]].append(word[1])
		
	DFS()
	
	x_sorted = sorted( finished.items(), key = lambda y : y[1], reverse = True)
	answer = ''
	for i in x_sorted :
		answer += i[0]
	print 'The topological sort of the given graph is: \t', answer
	
	
	
