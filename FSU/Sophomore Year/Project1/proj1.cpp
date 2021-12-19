/* Name: Marshall Copeland
Date: 01/15/21
Section: #07
Assignment: Project #1
Due Date: 01/28/21
About this project: Implement a program that collects the statistics of word, number, and character usage in a file (redirected as the standard input). 

All work below was performed by Marshall Copeland */

#include <iostream>
#include <cctype>
#include <iomanip>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

int main()
{
	vector<string> Words; //Words Vector
	vector<int> numWords; //Words Count Vector
	int WordsCount = 0;   //Number of Unique Words
	int WordMax;		  //temp maxixmum word variable
	int WordIndexMax;     //temp index of maxixmum word
	int tempWordSize;	  //temp size of the word
	
	vector<string> Numbers; //Numbers Vector 
	vector<int> numNumbers; //Numbers Count Vector
	int NumbersCount = 0;   //Number of Unique Numbers
	int NumMax;				//temp maximum number variable
	int NumIndexMax;		//temp index of maximum word
	int tempNumSize;        //temp size of the word
	
	vector<char> Characters;   //Characters Vector
	vector<int> numCharacters; //Characters Count Vector
	int CharactersCount = 0;   //Number of Unique Characters
	int CharMax;			   //temp maximum characters variable
	int CharIndexMax;		   //temp index if maximum characters
	int tempCharSize;		   //temp size of the word
	
	vector<string> TopWords;   //Top Words Vector
	vector<int> TopWordsIndex; //Top Words Index Vector
	vector<int> TopWordsCount; //Top Words Count Vector
	
	
	vector<string> TopNumbers;   //Top Numbers Vector
	vector<int> TopNumbersIndex; //Top Numbers Index Vector
	vector<int> TopNumbersCount; //Top Numbers Count Vector
	
	
	vector<char> TopCharacters;     //Top Characters Vector
	vector<int> TopCharactersIndex; //Top Characters Index Vector
	vector<int> TopCharactersCount; //Top Characters Count Vector
	
	
	char stringChar;   //temp string character
	char peekChar;     //check the next character in the stream
	string tempString; //temp string to make the words
	
	bool charCheck = false;   //makes sure there is a character
	bool phraseCheck = false; //makes sure there is a character
	
	int MaxLength; //max length of a string

	
	while(cin.eof() != true) //while the program has not reached the end of the file
	{		
		cin.get(stringChar); //gets new character from the stream
		
		for(int x = 0; x < Characters.size(); x++) //checks if the same character has already been read in
		{
			if(stringChar == Characters[x]) //if it has
			{
				numCharacters[x] = numCharacters[x] + 1; //the character count for that specific 
				charCheck = true;                        //character increases by one and char check is set to true
			}
		}
	
		if(charCheck == false) //if the character is new
		{
			Characters.push_back(stringChar); //add the character to the charactes vector
			numCharacters.push_back(1);       //add a one to the character count vector
			CharactersCount++;                //increases the character count by one
		}
			
		else //otherwise the char check is reset to false
		{
			charCheck = false;
		}
		
		
		if(isalpha(stringChar)) //same thing as the characters but combining them to make words
		{
			tempString += tolower(stringChar); //if the character is in the alphabet, it is added to the temp string
			
			peekChar = cin.peek(); //checks the next character
			
			if(isalpha(peekChar) == false) //if the next character isnt in the alphabet
			{
				for(int x = 0; x < Words.size(); x++) //the string is compared to other words in the vector
				{
					if(tempString == Words[x]) //if the word is already in the vector
					{
						numWords[x] = numWords[x] + 1; //adds to the count
						phraseCheck = true; //phrase check is set to true
					}
				}
			
				if(phraseCheck == false) //if the word isn tin the vector
				{
					Words.push_back(tempString); //adds the word to the vector
					numWords.push_back(1); //adds the count (1)
					tempString.erase(); //erases the temo string to use later
					WordsCount++; //word count is increased by 1
				}
			
				else 
				{	
					tempString.erase(); //otherwise the temp string is erased
					phraseCheck = false; //and phrase check is set to false to use again
				}
			}
		}
		
		else if(isdigit(stringChar)) //exact same thing as the words but for numbers
		{
			tempString += stringChar; //adds character is a number
			
			peekChar = cin.peek(); //checks next character
			
			if(isdigit(peekChar) == false)
			{
				for(int x = 0; x < Numbers.size(); x++)
				{
					if(tempString == Numbers[x]) //checks the numbers vector
					{
						numNumbers[x] = numNumbers[x] + 1;
						phraseCheck = true;
					}
				}
			
				if(phraseCheck == false) //adds to numbers vector
				{
					Numbers.push_back(tempString);
					numNumbers.push_back(1);
					tempString.erase();
					NumbersCount++;
				}
			
				else 
				{
					tempString.erase();
					phraseCheck = false;
				}
			}
		}
	} 

//finding max string length to get the buffer
	MaxLength = Words[0].length();
	
	for(int x = 1; x < Words.size(); x++)
	{
		if(Words[x].length() > MaxLength)
		{
			MaxLength = Words[x].length();
		}
	}

	for(int x = 0; x < Numbers.size(); x++)
	{
		if(Numbers[x].length() > MaxLength)
		{
			MaxLength = Numbers[x].length();
		}
	}

	MaxLength = MaxLength + 6; //ignore the +6 even though it should be +5, it fixes a spacing issue



//Character Output When Size is Less Than 10
	tempCharSize = Characters.size();

	if(Characters.size() < 10)
	{
		cout << "Total " << Characters.size() << " different characters, " << Characters.size() << " most used characters:" << endl;
		
		for(int x = 0; x < tempCharSize; x++) //finds the max character
		{
			CharMax = numCharacters[0]; //sets max to first value
			CharIndexMax = 0; //index is set to the first element (0)
			
			for(int y = 0; y < numCharacters.size(); y++) //checks the numcharacters vector
			{
				if(numCharacters[y] > CharMax) //if there is a bigger number
				{
					CharMax = numCharacters[y]; //the max is set to that number
					CharIndexMax = y; //the index is set to that numbers index
				}
				
				else if(numCharacters[y] == CharMax) //or if the count is the same as another
				{
					if(int(Characters[y]) < int(Characters[CharIndexMax])) //the ascii values are compared
					{
						CharMax = numCharacters[y];
						CharIndexMax = y;
					}
				}
			}
			
			TopCharactersCount.push_back(CharMax); //top counts are addedd to the new vector
			TopCharactersIndex.push_back(CharIndexMax); //top indexes are addedd to the new vector
			TopCharacters.push_back(Characters[CharIndexMax]); //top characters are addedd to the new vector
				
			if(TopCharacters[x] == '\n') //checks if the character is a new line character or a tab character
			{
				cout << "No. " << x << ": \\n";
				cout << setw(MaxLength - 2) << TopCharactersCount[x] << endl;
			}
			
			else if(TopCharacters[x] == '\t')
			{
				cout << "No. " << x << ": \\t";
				cout << setw(MaxLength - 2) << TopCharactersCount[x] << endl;
			}
			
			else //otherwise the output is formatted normally
			{
				cout << "No. " << x << ": " << TopCharacters[x];
				cout << setw(MaxLength - 1) << TopCharactersCount[x] << endl;
			}
			
			Characters.erase(Characters.begin() + CharIndexMax); //deletes the character so it cant be compared again
			numCharacters.erase(numCharacters.begin() + CharIndexMax); //deletes the max number so it cant be compared again
		}
	}
//Character Output When Size is 10 or Greater
	else if(Characters.size() >= 10) //exact same thing but for vectors with more than 10 values
	{
		cout << "Total " << Characters.size() << " different characters, 10 most used characters:" << endl;
		
		for(int x = 0; x < 10; x++)
		{
			CharMax = numCharacters[0];
			CharIndexMax = 0;
			
			for(int y = 0; y < numCharacters.size(); y++)
			{
				if(numCharacters[y] > CharMax)
				{
					CharMax = numCharacters[y];
					CharIndexMax = y;
				}
				
				else if(numCharacters[y] == CharMax)
				{
					if(int(Characters[y]) < int(Characters[CharIndexMax]))
					{
						CharMax = numCharacters[y];
						CharIndexMax = y;
					}
				}
			}
			
			TopCharactersCount.push_back(CharMax);
			TopCharactersIndex.push_back(CharIndexMax);
			TopCharacters.push_back(Characters[CharIndexMax]);
				
			if(TopCharacters[x] == '\n')
			{
				cout << "No. " << x << ": \\n";
				cout << setw(MaxLength - 2) << TopCharactersCount[x] << endl;
			}
			
			else if(TopCharacters[x] == '\t')
			{
				cout << "No. " << x << ": \\t";
				cout << setw(MaxLength - 2) << TopCharactersCount[x] << endl;
			}
			
			else
			{
				cout << "No. " << x << ": " << TopCharacters[x];
				cout << setw(MaxLength - 1) << TopCharactersCount[x] << endl;
			}
			
			Characters.erase(Characters.begin() + CharIndexMax);
			numCharacters.erase(numCharacters.begin() + CharIndexMax);
		}
	}

//Word Output When Size is Less Than 10
	tempWordSize = Words.size();

	if(Words.size() < 10) //same thing as characters but for the words
	{
		cout << "\nTotal " << Words.size() << " different words, " << Words.size() << " most used words:" << endl;
		
		for(int x = 0; x < tempWordSize; x++)
		{
			WordMax = numWords[0];
			WordIndexMax = 0;
			
			for(int y = 0; y < numWords.size(); y++)
			{
				if(numWords[y] > WordMax)
				{
					WordMax = numWords[y];
					WordIndexMax = y;
				}
				
				else if(numWords[y] == WordMax) //if the word counts are the same then the the indexs are compared
				{
					if(y < WordIndexMax)
					{
						WordMax = numWords[y];
						WordIndexMax = y;
					}
				}
			}
			
			TopWordsCount.push_back(WordMax); //adds to new vectors
			TopWordsIndex.push_back(WordIndexMax);
			TopWords.push_back(Words[WordIndexMax]);
				
			if(TopWords[x] == "\n") //formats the output correctly
			{
				cout << "No. " << x << ": \\n";
				cout << setw(MaxLength - 2) << TopWordsCount[x] << endl;
			}
			
			else if(TopWords[x] == "\t")
			{
				cout << "No. " << x << ": \\t";
				cout << setw(MaxLength - 2) << TopWordsCount[x] << endl;
			}
			
			else
			{
				cout << "No. " << x << ": " << TopWords[x];
				cout << setw(MaxLength - TopWords[x].length()) << TopWordsCount[x] << endl;
			}
			
			Words.erase(Words.begin() + WordIndexMax); //erases the words
			numWords.erase(numWords.begin() + WordIndexMax);
		}
	}
//Word Output When Size is 10 or Greater
	if(Words.size() >= 10) //same as above but for word vectors of sizes greater than or equal to 10
	{
		cout << "\nTotal " << Words.size() << " different words, 10 most used words:" << endl;
		
		for(int x = 0; x < 10; x++)
		{
			WordMax = numWords[0];
			WordIndexMax = 0;
			
			for(int y = 0; y < numWords.size(); y++)
			{
				if(numWords[y] > WordMax)
				{
					WordMax = numWords[y];
					WordIndexMax = y;
				}
				
				else if(numWords[y] == WordMax)
				{
					if(y < WordIndexMax)
					{
						WordMax = numWords[y];
						WordIndexMax = y;
					}
				}
			}
			
			TopWordsCount.push_back(WordMax);
			TopWordsIndex.push_back(WordIndexMax);
			TopWords.push_back(Words[WordIndexMax]);
				
			if(TopWords[x] == "\n")
			{
				cout << "No. " << x << ": \\n";
				cout << setw(MaxLength - 2) << TopWordsCount[x] << endl;
			}
			
			else if(TopWords[x] == "\t")
			{
				cout << "No. " << x << ": \\t";
				cout << setw(MaxLength - 2) << TopWordsCount[x] << endl;
			}
			
			else
			{
				cout << "No. " << x << ": " << TopWords[x];
				cout << setw(MaxLength - TopWords[x].length()) << TopWordsCount[x] << endl;
			}
			
			Words.erase(Words.begin() + WordIndexMax);
			numWords.erase(numWords.begin() + WordIndexMax);
		}
	}

//Number Output When Size is Less Than 10
	tempNumSize = Numbers.size();

	if(Numbers.size() < 10) //same as words but for the numbers
	{
		cout << "\nTotal " << Numbers.size() << " different numbers, " << Numbers.size() << " most used numbers:" << endl;
		
		for(int x = 0; x < tempNumSize; x++)
		{
			NumMax = numNumbers[0];
			NumIndexMax = 0;
			
			for(int y = 0; y < numNumbers.size(); y++)
			{
				if(numNumbers[y] > NumMax)
				{
					NumMax = numNumbers[y];
					NumIndexMax = y;
				}
				
				else if(numNumbers[y] == NumMax)
				{
					if(y < NumIndexMax)
					{
						NumMax = numNumbers[y];
						NumIndexMax = y;
					}
				}
			}
			
			TopNumbersCount.push_back(NumMax);
			TopNumbersIndex.push_back(NumIndexMax);
			TopNumbers.push_back(Numbers[NumIndexMax]);
				
			cout << "No. " << x << ": " << TopNumbers[x];
			cout << setw(MaxLength - TopNumbers[x].length()) << right << TopNumbersCount[x] << endl;
			
			Numbers.erase(Numbers.begin() + NumIndexMax);
			numNumbers.erase(numNumbers.begin() + NumIndexMax);
		}
	}
//Number Output When Size is 10 or Greater
	if(Numbers.size() >= 10)
	{
		cout << "\nTotal " << Numbers.size() << " different numbers, 10 most used numbers:" << endl;
		
		for(int x = 0; x < 10; x++)
		{
			NumMax = numNumbers[0];
			NumIndexMax = 0;
			
			for(int y = 0; y < numNumbers.size(); y++)
			{
				if(numNumbers[y] > NumMax)
				{
					NumMax = numNumbers[y];
					NumIndexMax = y;
				}
				
				else if(numNumbers[y] == NumMax)
				{
					if(y < NumIndexMax)
					{
						NumMax = numNumbers[y];
						NumIndexMax = y;
					}
				}
			}
			
			TopNumbersCount.push_back(NumMax);
			TopNumbersIndex.push_back(NumIndexMax);
			TopNumbers.push_back(Numbers[NumIndexMax]);
				
			cout << "No. " << x << ": " << TopNumbers[x];
			cout << setw(MaxLength - TopNumbers[x].length()) << right << TopNumbersCount[x] << endl;
			
			Numbers.erase(Numbers.begin() + NumIndexMax);
			numNumbers.erase(numNumbers.begin() + NumIndexMax);
		}
	}

	return 0;
}




