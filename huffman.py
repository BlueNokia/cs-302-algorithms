from collections import defaultdict
import heapq
from math import ceil, log, floor

def huffman( frequency ):
	graph = [[val, [symbol, '']] for symbol, val in frequency.items()]
	
	heapq.heapify( graph )
	
	while len(graph) > 1:
		a = heapq.heappop( graph )
		b = heapq.heappop( graph )
		
		for i in a[1:]:
			i[1] += '0'
		for i in b[1:]:
			i[1] += '1'
			
		heapq.heappush(graph, [ a[0] + b[0] ] + a[1:] + b[1:] )
		
	return sorted( heapq.heappop(graph)[1:], key = lambda y : len(y[1]))
			
	

if __name__ == '__main__':
	data = 'Samsung, Dell, Lenovo, any of them works for me'
	frequency = defaultdict(int)
	
	for word in data:
		frequency[word] += 1
		
	encoded = huffman(frequency)
	
	print 'Symbol'.ljust(15) + 'Frequency'.ljust(15) + 'Huffman codes'.ljust(15)
	
	for sym in encoded:
		print sym[0].ljust(15) + str(frequency[sym[0]]).ljust(15) + sym[1].ljust(15)
	
	bit_size = 0
	k = len(frequency.keys())
	if ceil(log(k, 2.0)) == floor(log(k, 2.0)):
		bit_size = int(log(k, 2.0)) + 1
	else:
		bit_size = int(ceil(log(k, 2.0)))
		
	sum_huff = 0
	sum_standard = 0
	for sym in encoded:
		sum_huff += frequency[sym[0]] * len(sym[1])
		sum_standard += frequency[sym[0]] * bit_size
		
	bits_saved = sum_standard - sum_huff
	
	print 'The number of bits saved by Huffman coding are: \t', bits_saved
