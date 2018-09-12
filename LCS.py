from collections import defaultdict

def LCS( str1, str2):
	
	str1 = 'T' + str1
	str2 = 'T' + str2
	x = [[0]*len(str2) for i in range(len(str1))]
	y = [[0]*len(str2) for i in range(len(str1))]
	
	for i in range(1, len(str1)):
		for j in range(1, len(str2)):
			if str1[i] == str2[j]:
				x[i][j] = x[i-1][j-1] + 1
				y[i][j] = 1
			elif x[i-1][j] >= x[i][j-1]:
				x[i][j] = x[i-1][j]
				y[i][j] = 2
			else:
				x[i][j] = x[i][j-1]
				
	i, j = len(str1)-1, len(str2)-1
	res = ''
	while i != 0 or j != 0:
		if y[i][j] == 0:
			j -= 1
		elif y[i][j] == 1:
			res += str1[i]
			i -= 1
			j -= 1
		else:
			i -= 1
	
	return res[::-1]
				

if __name__ == '__main__':
	
	str1 = raw_input("First string:\t")
	str2 = raw_input("Second string:\t")
	
	lcs = LCS( str1, str2)
	
	print "The length of the string is :", len(lcs)
	print "The LCS of the given strings is :", lcs
	
