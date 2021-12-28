# Marshall Copeland
# Due Date: 9/7/2021
# The program in this file is the individual work of Marshall Copeland

palindromeList = []
palindromeDictionary = {}

print('Enter in strings:')
word = input()

while word != 'Done':
    palindromeList.append(word)
    word = word.lower()
    word = word.replace(" ","")
    if word != word[::-1]:
	    palindromeList.pop()
    word = input()

count = 1
for i in palindromeList:
	palindromeDictionary[count] = i
	count = count + 1
print('The palindromes are:')
print(palindromeDictionary)
