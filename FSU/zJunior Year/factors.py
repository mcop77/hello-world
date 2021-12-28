# Marshall Copeland
# Due Date: 9/7/2021
# The program in this file is the individual work of Marshall Copeland

factorDictionary = {}
factorSet = set([])

number = int(input('Enter a number: '))

for x in range(1,number+1):
	for y in range(1,x+1):
	    if x % y == 0:
	    	factorSet.add(y)
	factorDictionary[x] = factorSet
	factorSet = set([])

print(factorDictionary)
