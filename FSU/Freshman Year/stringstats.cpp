/* Name: Marshall Copeland
Date: 03/30/2020
Section: #4
Assignment: Homework #6
Due Date: 04/07/2020
About this project: This assignment will involve practice with either C-style strings or string objects, as well as some of the libraries that involve manipulations on characters (like cctype) and strings (cstring/string)
Assumptions: None
All work below was performed by Marshall Copeland */

#include <iostream>
#include <cstring>
#include <string>
#include <cctype>

using namespace std;

int punctuation(char sentence[100]); //calls punctuation function that counts punctuation characters
int vowels(char sentence[100]); //calls punctuation function that counts vowels
int space(char sentence[100]); //calls punctuation function that counts the amount of words
void wordLengths(char sentence[100]); //calls lengths function that gives word lengths and their number of occurences in the sentence
bool isWord(char sentence[100], char word[20]); //calls word function that checks if the word is a part of the sentence

int main()
{
	int numPunct; //im pretty sure i didnt use half of these, not going to mess with them though
	int numChar;
	int numVow;
	int charLen;
	int numWord;
	
	char sentence[100]; //max sentence length is 100
	char word[20]; //max word length is 20
	string answer; //takes in whether user wants to enter another sentence or not
	
	do { //starts the loop off
		
	cout << "Enter a sentence: ";
	cin.getline(sentence, 100, '\n'); //takes in the user entry and assigns it to sentence
	
	cout << "Enter a word: ";
	cin >> word; //user types in a word
	
	cout << "\nSENTENCE ANALYSIS:" << endl;
	
	cout << "\nPunctuation Characters: ";
	numPunct = punctuation(sentence); //calls punctuation function and assigns it to variable for easy c-outage
	cout << numPunct;
	
	cout << "\nVowels: ";
	numVow = vowels(sentence); //same as punct func, but for vowels
	cout << numVow;
	
	cout << "\nWords: ";
	numWord = space(sentence); //counts the numebr of words
	cout << numWord;
	
	cout << "\n\nWord Lengths:" << endl;
	wordLengths(sentence); //calls wordlengths func
	
	if(isWord(sentence, word) == true) //if the word is a part of the sentence
	{
		cout << "\nThe word \"" << word << "\" IS part of the sentence you entered. " << endl;
	}
	
	else cout << "\nThe word \"" << word << "\" IS NOT part of the sentence you entered. " << endl;
	
		
	cout << "\nEnter another sentence/word for analysis (yes/no): ";
	cin >> answer;
	
	while(answer != "yes" && answer != "Yes" && answer != "YEs" && answer != "YES" && answer != "yEs" && answer != "yES" && answer != "yeS" && answer != "YeS" && answer != "NO" && answer != "No" && answer != "nO" && answer != "no") //checks if it is all forms of yes or no
	{
		cout << "Enter yes or no: ";
		cin >> answer;
		
	}
	
	cin.ignore(); //ignores the weird line after
	
} while(answer == "yes" || answer == "Yes" || answer == "YEs" || answer == "YES" || answer == "yEs" || answer == "yES" || answer == "yeS" || answer == "YeS"); //all happens while answer is yes
	
	
	return 0;
}

int punctuation(char sentence[100]) //punctuation counter function
{	
	int punct = sentence[100];
	int count = 0;
	
	for(int x = 0; x < strlen(sentence); x++)
	{
		if(ispunct(sentence[x])) //if there are punctution chracters, they are counted
		{
			count++;
		}
	}
	return count; //returns the number of punctuation characters
}

int vowels(char sentence[100]) //vowel counter function
{
	int count = 0;
	
	for(int x = 0; x < strlen(sentence); x++) //counts all the uppercase and lowercase vowels
	{
		if(sentence[x] == 'a' || sentence[x] == 'e' || sentence[x] == 'i' || sentence[x] == 'o' || sentence[x] == 'u' || sentence[x] == 'A' || sentence[x] == 'E' || sentence[x] == 'I' || sentence[x] == 'O' || sentence[x] == 'U')
		{
			count++;
		}
	}
	return count; //returns the number of vowels
	
}

int space(char sentence[100]) //word counter function
{
	int count = 1; //starts at one because there is always at least one word
	
	for(int x = 0; x < strlen(sentence); x++)
	{
		if(isspace(sentence[x])) //counts the amount of spaces
		{
			count++;
		}
	}
	return count; //returns the number of spaces + 1, which equals the words
}

void wordLengths(char sentence[100]) //keeps track of the word lengths
{
	int charLen = 0; //char length
	
	int one = 0; //keeps track of individual word lengths
	int two = 0;
	int three = 0;
	int four = 0;
	int five = 0;
	int six = 0;
	int seven = 0;
	int eight = 0;
	int nine = 0;
	int ten = 0;
	int eleven = 0;
	int twelve = 0;
	int thirteen = 0;
	int fourteen = 0;
	int fifteen = 0;
	int sixteen = 0;
	int seventeen = 0;
	int eighteen = 0;
	int nineteen = 0;
	int twenty = 0;
	
	int count = strlen(sentence);
	
	bool check = false;
	
	for(int x = 0; x < strlen(sentence); x++) //cycles though the sentences
	{
		if(isspace(sentence[x]) == 0)
		{
			if(x == strlen(sentence) - 1)
			{
				charLen++;
				
				if(charLen == 1) //counts when the cahracter length is that certain length
				{
					one++;
				}
	
				if(charLen == 2)
				{
					two++;
				}
	
				if(charLen == 3)
				{
					three++;
				}
	
				if(charLen == 4)
				{
					four++;
				}
			
				if(charLen == 5)
				{
					five++;
				}
	
				if(charLen == 6)
				{
					six++;
				}
			
				if(charLen == 7)
				{
					seven++;
				}
	
				if(charLen == 8)
				{
					eight++;
				}
	
				if(charLen == 9)
				{
					nine++;
				}
	
				if(charLen == 10)
				{
					ten++;
				}
	
				if(charLen == 11)
				{
					eleven++;
				}
	
				if(charLen == 12)
				{
					twelve++;
				}
		
				if(charLen == 13)
				{
					thirteen++;
				}
	
				if(charLen == 14)
				{
					fourteen++;
				}
					
				if(charLen == 15)
				{
					fifteen++;
				}
		
				if(charLen == 16)
				{
					sixteen++;
				}
	
				if(charLen == 17)
				{
					seventeen++;
				}
	
				if(charLen == 18)
				{
					eighteen++;
				}
	
				if(charLen == 19)
				{
					nineteen++;
				}
			
				if(charLen == 20)
				{
					twenty++;
				}
		
				x++; //keeps the loop going 
			}
			
			else charLen++;
		}
		
		else 
		{
			if(charLen == 1) //if the prior if statement was not fulfilled
			{
				one++;
			}
	
			if(charLen == 2)
			{
				two++;
			}
	
			if(charLen == 3)
			{
				three++;
			}
	
			if(charLen == 4)
			{
				four++;
			}
			
			if(charLen == 5)
			{
				five++;
			}
	
			if(charLen == 6)
			{
				six++;
			}
			
			if(charLen == 7)
			{
				seven++;
			}
	
			if(charLen == 8)
			{
				eight++;
			}
	
			if(charLen == 9)
			{
				nine++;
			}
	
			if(charLen == 10)
			{
				ten++;
			}
	
			if(charLen == 11)
			{
				eleven++;
			}
	
			if(charLen == 12)
			{
				twelve++;
			}
		
			if(charLen == 13)
			{
				thirteen++;
			}
	
			if(charLen == 14)
			{
				fourteen++;
			}
					
			if(charLen == 15)
			{
				fifteen++;
			}
		
			if(charLen == 16)
			{
				sixteen++;
			}
	
			if(charLen == 17)
			{
				seventeen++;
			}
	
			if(charLen == 18)
			{
				eighteen++;
			}
	
			if(charLen == 19)
			{
				nineteen++;
			}
			
			if(charLen == 20)
			{
				twenty++;
			}
		
			charLen = 0; //resets the word count
		}
	}
	
	if(one > 0) //retieves values from up top and delegates accordingly, accounting for word plurality
	{
		if(one > 1)
		{
			cout << "1 character long: " << one << " words." << endl;
		}
		
		else cout << "1 character long: " << one << " word." << endl;
	}
	
	if(two > 0)
	{
		if(two > 1)
		{
			cout << "2 characters long: " << two << " words." << endl;
		}
		
		else cout << "2 characters long: " << two << " word." << endl;
	}
	
	if(three > 0)
	{
		if(three > 1)
		{
			cout << "3 characters long: " << three << " words." << endl;
		}
		
		else cout << "3 characters long: " << three << " word." << endl;
	}
	
	if(four > 0)
	{
		if(four > 1)
		{
			cout << "4 characters long: " << four << " words." << endl;
		}
		
		else cout << "4 characters long: " << four << " word." << endl;
	}
	
	if(five > 0)
	{
		if(five > 1)
		{
			cout << "5 characters long: " << five << " words." << endl;
		}
		
		else cout << "5 characters long: " << five << " word." << endl;
	}
	
	if(six > 0)
	{
		if(six > 1)
		{
			cout << "6 characters long: " << six << " words." << endl;
		}
		
		else cout << "6 characters long: " << six << " word." << endl;
	}
	
	if(seven > 0)
	{
		if(seven > 1)
		{
			cout << "7 characters long: " << seven << " words." << endl;
		}
		
		else cout << "7 characters long: " << seven << " word." << endl;
	}
	
	if(eight > 0)
	{
		if(eight > 1)
		{
			cout << "8 characters long: " << eight << " words." << endl;
		}
		
		else cout << "8 characters long: " << eight << " word." << endl;
	}
	
	if(nine > 0)
	{
		if(nine > 1)
		{
			cout << "9 characters long: " << nine << " words." << endl;
		}
		
		else cout << "9 characters long: " << nine << " word." << endl;
	}
	
	if(ten > 0)
	{
		if(ten > 1)
		{
			cout << "10 characters long: " << ten << " words." << endl;
		}
		
		else cout << "10 characters long: " << ten << " word." << endl;
	}
	
	if(eleven > 0)
	{
		if(eleven > 1)
		{
			cout << "11 characters long: " << eleven << " words." << endl;
		}
		
		else cout << "11 characters long: " << eleven << " word." << endl;
	}
	
	if(twelve > 0)
	{
		if(twelve > 1)
		{
			cout << "12 characters long: " << twelve << " words." << endl;
		}
		
		else cout << "12 characters long: " << twelve << " word." << endl;
	}
	
	if(thirteen > 0)
	{
		if(thirteen > 1)
		{
			cout << "13 characters long: " << thirteen << " words." << endl;
		}
		
		else cout << "13 characters long: " << thirteen << " word." << endl;
	}
	
	if(fourteen > 0)
	{
		if(fourteen > 1)
		{
			cout << "14 characters long: " << fourteen << " words." << endl;
		}
		
		else cout << "14 characters long: " << fourteen << " word." << endl;
	}
	
	if(fifteen > 0)
	{
		if(fifteen > 1)
		{
			cout << "15 characters long: " << fifteen << " words." << endl;
		}
		
		else cout << "15 characters long: " << fifteen << " word." << endl;
	}
	
	if(sixteen > 0)
	{
		if(sixteen > 1)
		{
			cout << "16 characters long: " << sixteen << " words." << endl;
		}
		
		else cout << "16 characters long: " << sixteen << " word." << endl;
	}
	
	if(seventeen > 0)
	{
		if(seventeen > 1)
		{
			cout << "17 characters long: " << seventeen << " words." << endl;
		}
		
		else cout << "17 characters long: " << seventeen << " word." << endl;
	}
	
	if(eighteen > 0)
	{
		if(eighteen > 1)
		{
			cout << "18 characters long: " << eighteen << " words." << endl;
		}
		
		else cout << "18 characters long: " << eighteen << " word." << endl;
	}
	
	if(nineteen > 0)
	{
		if(nineteen > 1)
		{
			cout << "19 characters long: " << nineteen << " words." << endl;
		}
		
		else cout << "19 characters long: " << nineteen << " word." << endl;
	}
	
	if(twenty > 0)
	{
		if(twenty > 1)
		{
			cout << "20 characters long: " << twenty << " words." << endl;
		}
		
		else cout << "20 characters long: " << twenty << " word." << endl;
	}
}

bool isWord(char sentence[100], char word[20]) //here comes the big boy function, took me three whole days ~20 hours to finally get a version of it to work
{
	char helper[20]; //old code im pretty sure
	bool wordCheck = false; //sets default to false
	int count = 0;
	
	int wordLength = strlen(word); //word length
	int sentenceLength = strlen(sentence); //sentence length
	
	if(wordLength == 1) //the following lines go like this: if there is a character in the sentence that matches the first character of the word, keep going until you hit the end of the word length and see if they are the same
	{
	 for(int x = 0; x < 1; x++) //first for loop that cycles once for the first letter of the word
	 {
	  for(int z = 0; z < sentenceLength; z++) //cycles through the sentence
	  {
	   if(word[x] == sentence[z]) //if theyre equal and the words only one character long
	   {
		wordCheck = true; //bam, return true, done
	    break;
	   }
	  }
	 }
	}
		
	else if(wordLength == 2) //keep going for all possible word lengths, up to twenty
	{
	 for(int x = 0; x < 1; x++)
	 {
	  for(int z = 0; z < sentenceLength; z++)
	  {
	   if(word[x] == sentence[z])
	   {
		if(word[x + 1] == sentence[z + 1]) //if loops keep getting nested, with variables adding one to keep track of next character
		{
		 wordCheck = true;
	     break;
		}
	   }
	  }
	 }
	}
	
	else if(wordLength == 3)
	{
	 for(int x = 0; x < 1; x++)
	 {
	  for(int z = 0; z < sentenceLength; z++)
	  {
	   if(word[x] == sentence[z])
	   {
		if(word[x + 1] == sentence[z + 1])
		{
		 if(word[x + 2] == sentence[z + 2])
		 {
		  wordCheck = true;
		  break;
		 }
	    }
	   }
      }
     }
	}
	
	else if(wordLength == 4)
	{
	 for(int x = 0; x < 1; x++)
	 {
	  for(int z = 0; z < sentenceLength; z++)
	  {
	   if(word[x] == sentence[z])
	   {
		if(word[x + 1] == sentence[z + 1])
		{
		 if(word[x + 2] == sentence[z + 2])
		 {
		  if(word[x + 3] == sentence[z + 3])
		  {
		   wordCheck = true;
		   break;
		  }
		 }
	    }
	   }
      }
     }
	}
	
	else if(wordLength == 5)
	{
	 for(int x = 0; x < 1; x++)
	 {
	  for(int z = 0; z < sentenceLength; z++)
	  {
	   if(word[x] == sentence[z])
	   {
		if(word[x + 1] == sentence[z + 1])
		{
		 if(word[x + 2] == sentence[z + 2])
		 {
		  if(word[x + 3] == sentence[z + 3])
		  {
		   if(word[x + 4] == sentence[z + 4])
		   {
			wordCheck = true;
			break; 
		   }
		  }
		 }
	    }
	   }
      }
     }
	}
	
	else if(wordLength == 6)
	{
	 for(int x = 0; x < 1; x++)
	 {
	  for(int z = 0; z < sentenceLength; z++)
	  {
	   if(word[x] == sentence[z])
	   {
		if(word[x + 1] == sentence[z + 1])
		{
		 if(word[x + 2] == sentence[z + 2])
		 {
		  if(word[x + 3] == sentence[z + 3])
		  {
		   if(word[x + 4] == sentence[z + 4])
		   {
			if(word[x + 5] == sentence[z + 5])
			{
			 wordCheck = true;
			 break;
			}
		   }
		  }
		 }
		}
	   }
	  }
     }
    }
	
	else if(wordLength == 7)
	{
	 for(int x = 0; x < 1; x++)
	 {
	  for(int z = 0; z < sentenceLength; z++)
	  {
	   if(word[x] == sentence[z])
	   {
		if(word[x + 1] == sentence[z + 1])
		{
		 if(word[x + 2] == sentence[z + 2])
		 {
		  if(word[x + 3] == sentence[z + 3])
		  {
		   if(word[x + 4] == sentence[z + 4])
		   {
			if(word[x + 5] == sentence[z + 5])
			{
			 if(word[x + 6] == sentence[z + 6])
			 {
			  wordCheck = true;
			  break;
			 }
			}
		   }
		  }
		 }
	    }
	   }
      }
     }
	}
	
	else if(wordLength == 8)
	{
	 for(int x = 0; x < 1; x++)
	 {
	  for(int z = 0; z < sentenceLength; z++)
	  {
	   if(word[x] == sentence[z])
	   {
		if(word[x + 1] == sentence[z + 1])
		{
		 if(word[x + 2] == sentence[z + 2])
		 {
		  if(word[x + 3] == sentence[z + 3])
		  {
		   if(word[x + 4] == sentence[z + 4])
		   {
			if(word[x + 5] == sentence[z + 5])
			{
			 if(word[x + 6] == sentence[z + 6])
			 {
			  if(word[x + 7] == sentence[z + 7])
			  {
			   wordCheck = true;
			   break;
			  }
			 }
			}
		   }
		  }
		 }
	    }
	   }
      }
     }
	}
	
	else if(wordLength == 9)
	{
	 for(int x = 0; x < 1; x++)
	 {
	  for(int z = 0; z < sentenceLength; z++)
	  {
	   if(word[x] == sentence[z])
	   {
		if(word[x + 1] == sentence[z + 1])
		{
		 if(word[x + 2] == sentence[z + 2])
		 {
		  if(word[x + 3] == sentence[z + 3])
		  {
		   if(word[x + 4] == sentence[z + 4])
		   {
			if(word[x + 5] == sentence[z + 5])
			{
			 if(word[x + 6] == sentence[z + 6])
			 {
			  if(word[x + 7] == sentence[z + 7])
			  {
			   if(word[x + 8] == sentence[z + 8])
			   {
			    wordCheck = true;
			    break;
			   }
			  }
			 }
			}
		   }
		  }
		 }
	    }
	   }
      }
     }
	}
	
	else if(wordLength == 10)
	{
	 for(int x = 0; x < 1; x++)
	 {
	  for(int z = 0; z < sentenceLength; z++)
	  {
	   if(word[x] == sentence[z])
	   {
		if(word[x + 1] == sentence[z + 1])
		{
		 if(word[x + 2] == sentence[z + 2])
		 {
		  if(word[x + 3] == sentence[z + 3])
		  {
		   if(word[x + 4] == sentence[z + 4])
		   {
			if(word[x + 5] == sentence[z + 5])
			{
			 if(word[x + 6] == sentence[z + 6])
			 {
			  if(word[x + 7] == sentence[z + 7])
			  {
			   if(word[x + 8] == sentence[z + 8])
			   {
				if(word[x + 9] == sentence[z + 9])
				{
			     wordCheck = true;
			     break;
			    }
			   }
			  }
			 }
			}
		   }
		  }
		 }
	    }
	   }
      }
     }
	}
	
	else if(wordLength == 11)
	{
	 for(int x = 0; x < 1; x++)
	 {
	  for(int z = 0; z < sentenceLength; z++)
	  {
	   if(word[x] == sentence[z])
	   {
		if(word[x + 1] == sentence[z + 1])
		{
		 if(word[x + 2] == sentence[z + 2])
		 {
		  if(word[x + 3] == sentence[z + 3])
		  {
		   if(word[x + 4] == sentence[z + 4])
		   {
			if(word[x + 5] == sentence[z + 5])
			{
			 if(word[x + 6] == sentence[z + 6])
			 {
			  if(word[x + 7] == sentence[z + 7])
			  {
			   if(word[x + 8] == sentence[z + 8])
			   {
				if(word[x + 9] == sentence[z + 9])
				{
			     if(word[x + 10] == sentence[z + 10])
				 {
			      wordCheck = true;
			      break;
				 }
			    }
			   }
			  }
			 }
			}
		   }
		  }
		 }
	    }
	   }
      }
     }
	}
	
	else if(wordLength == 12)
	{
	 for(int x = 0; x < 1; x++)
	 {
	  for(int z = 0; z < sentenceLength; z++)
	  {
	   if(word[x] == sentence[z])
	   {
		if(word[x + 1] == sentence[z + 1])
		{
		 if(word[x + 2] == sentence[z + 2])
		 {
		  if(word[x + 3] == sentence[z + 3])
		  {
		   if(word[x + 4] == sentence[z + 4])
		   {
			if(word[x + 5] == sentence[z + 5])
			{
			 if(word[x + 6] == sentence[z + 6])
			 {
			  if(word[x + 7] == sentence[z + 7])
			  {
			   if(word[x + 8] == sentence[z + 8])
			   {
				if(word[x + 9] == sentence[z + 9])
				{
			     if(word[x + 10] == sentence[z + 10])
				 {
				  if(word[x + 11] == sentence[z + 11])
				  {
			       wordCheck = true;
			       break;
				  }
				 }
			    }
			   }
			  }
			 }
			}
		   }
		  }
		 }
	    }
	   }
      }
     }
	}
	
	else if(wordLength == 13)
	{
	 for(int x = 0; x < 1; x++)
	 {
	  for(int z = 0; z < sentenceLength; z++)
	  {
	   if(word[x] == sentence[z])
	   {
		if(word[x + 1] == sentence[z + 1])
		{
		 if(word[x + 2] == sentence[z + 2])
		 {
		  if(word[x + 3] == sentence[z + 3])
		  {
		   if(word[x + 4] == sentence[z + 4])
		   {
			if(word[x + 5] == sentence[z + 5])
			{
			 if(word[x + 6] == sentence[z + 6])
			 {
			  if(word[x + 7] == sentence[z + 7])
			  {
			   if(word[x + 8] == sentence[z + 8])
			   {
				if(word[x + 9] == sentence[z + 9])
				{
			     if(word[x + 10] == sentence[z + 10])
				 {
				  if(word[x + 11] == sentence[z + 11])
				  {
				   if(word[x + 12] == sentence[z + 12])
				   {
			        wordCheck = true;
			        break;
				   }
				  }
				 }
			    }
			   }
			  }
			 }
			}
		   }
		  }
		 }
	    }
	   }
      }
     }
	}
	
	else if(wordLength == 14)
	{
	 for(int x = 0; x < 1; x++)
	 {
	  for(int z = 0; z < sentenceLength; z++)
	  {
	   if(word[x] == sentence[z])
	   {
		if(word[x + 1] == sentence[z + 1])
		{
		 if(word[x + 2] == sentence[z + 2])
		 {
		  if(word[x + 3] == sentence[z + 3])
		  {
		   if(word[x + 4] == sentence[z + 4])
		   {
			if(word[x + 5] == sentence[z + 5])
			{
			 if(word[x + 6] == sentence[z + 6])
			 {
			  if(word[x + 7] == sentence[z + 7])
			  {
			   if(word[x + 8] == sentence[z + 8])
			   {
				if(word[x + 9] == sentence[z + 9])
				{
			     if(word[x + 10] == sentence[z + 10])
				 {
				  if(word[x + 11] == sentence[z + 11])
				  {
				   if(word[x + 12] == sentence[z + 12])
				   {
					if(word[x + 13] == sentence[z + 13])
					{
			         wordCheck = true;
			         break;
					}
				   }
				  }
				 }
			    }
			   }
			  }
			 }
			}
		   }
		  }
		 }
	    }
	   }
      }
     }
	}
	
	else if(wordLength == 15)
	{
	 for(int x = 0; x < 1; x++)
	 {
	  for(int z = 0; z < sentenceLength; z++)
	  {
	   if(word[x] == sentence[z])
	   {
		if(word[x + 1] == sentence[z + 1])
		{
		 if(word[x + 2] == sentence[z + 2])
		 {
		  if(word[x + 3] == sentence[z + 3])
		  {
		   if(word[x + 4] == sentence[z + 4])
		   {
			if(word[x + 5] == sentence[z + 5])
			{
			 if(word[x + 6] == sentence[z + 6])
			 {
			  if(word[x + 7] == sentence[z + 7])
			  {
			   if(word[x + 8] == sentence[z + 8])
			   {
				if(word[x + 9] == sentence[z + 9])
				{
			     if(word[x + 10] == sentence[z + 10])
				 {
				  if(word[x + 11] == sentence[z + 11])
				  {
				   if(word[x + 12] == sentence[z + 12])
				   {
					if(word[x + 13] == sentence[z + 13])
					{
					 if(word[x + 14] == sentence[z + 14])
					 {
			          wordCheck = true;
			          break;
					 }
					}
				   }
				  }
				 }
			    }
			   }
			  }
			 }
			}
		   }
		  }
		 }
	    }
	   }
      }
     }
	}
	
	else if(wordLength == 16)
	{
	 for(int x = 0; x < 1; x++)
	 {
	  for(int z = 0; z < sentenceLength; z++)
	  {
	   if(word[x] == sentence[z])
	   {
		if(word[x + 1] == sentence[z + 1])
		{
		 if(word[x + 2] == sentence[z + 2])
		 {
		  if(word[x + 3] == sentence[z + 3])
		  {
		   if(word[x + 4] == sentence[z + 4])
		   {
			if(word[x + 5] == sentence[z + 5])
			{
			 if(word[x + 6] == sentence[z + 6])
			 {
			  if(word[x + 7] == sentence[z + 7])
			  {
			   if(word[x + 8] == sentence[z + 8])
			   {
				if(word[x + 9] == sentence[z + 9])
				{
			     if(word[x + 10] == sentence[z + 10])
				 {
				  if(word[x + 11] == sentence[z + 11])
				  {
				   if(word[x + 12] == sentence[z + 12])
				   {
					if(word[x + 13] == sentence[z + 13])
					{
					 if(word[x + 14] == sentence[z + 14])
					 {
					  if(word[x + 15] == sentence[z + 15])
					  {
			           wordCheck = true;
			           break;
					  }
					 }
					}
				   }
				  }
				 }
			    }
			   }
			  }
			 }
			}
		   }
		  }
		 }
	    }
	   }
      }
     }
	}
	
	else if(wordLength == 17)
	{
	 for(int x = 0; x < 1; x++)
	 {
	  for(int z = 0; z < sentenceLength; z++)
	  {
	   if(word[x] == sentence[z])
	   {
		if(word[x + 1] == sentence[z + 1])
		{
		 if(word[x + 2] == sentence[z + 2])
		 {
		  if(word[x + 3] == sentence[z + 3])
		  {
		   if(word[x + 4] == sentence[z + 4])
		   {
			if(word[x + 5] == sentence[z + 5])
			{
			 if(word[x + 6] == sentence[z + 6])
			 {
			  if(word[x + 7] == sentence[z + 7])
			  {
			   if(word[x + 8] == sentence[z + 8])
			   {
				if(word[x + 9] == sentence[z + 9])
				{
			     if(word[x + 10] == sentence[z + 10])
				 {
				  if(word[x + 11] == sentence[z + 11])
				  {
				   if(word[x + 12] == sentence[z + 12])
				   {
					if(word[x + 13] == sentence[z + 13])
					{
					 if(word[x + 14] == sentence[z + 14])
					 {
					  if(word[x + 15] == sentence[z + 15])
					  {
					   if(word[x + 16] == sentence[z + 16])
					   {
			            wordCheck = true;
			            break;
					   }
					  }
					 }
					}
				   }
				  }
				 }
			    }
			   }
			  }
			 }
			}
		   }
		  }
		 }
	    }
	   }
      }
     }
	}
	
	else if(wordLength == 18)
	{
	 for(int x = 0; x < 1; x++)
	 {
	  for(int z = 0; z < sentenceLength; z++)
	  {
	   if(word[x] == sentence[z])
	   {
		if(word[x + 1] == sentence[z + 1])
		{
		 if(word[x + 2] == sentence[z + 2])
		 {
		  if(word[x + 3] == sentence[z + 3])
		  {
		   if(word[x + 4] == sentence[z + 4])
		   {
			if(word[x + 5] == sentence[z + 5])
			{
			 if(word[x + 6] == sentence[z + 6])
			 {
			  if(word[x + 7] == sentence[z + 7])
			  {
			   if(word[x + 8] == sentence[z + 8])
			   {
				if(word[x + 9] == sentence[z + 9])
				{
			     if(word[x + 10] == sentence[z + 10])
				 {
				  if(word[x + 11] == sentence[z + 11])
				  {
				   if(word[x + 12] == sentence[z + 12])
				   {
					if(word[x + 13] == sentence[z + 13])
					{
					 if(word[x + 14] == sentence[z + 14])
					 {
					  if(word[x + 15] == sentence[z + 15])
					  {
					   if(word[x + 16] == sentence[z + 16])
					   {
						if(word[x + 17] == sentence[z + 17])
					    {
			             wordCheck = true;
			             break;
					    }
					   }
					  }
					 }
					}
				   }
				  }
				 }
			    }
			   }
			  }
			 }
			}
		   }
		  }
		 }
	    }
	   }
      }
     }
	}
	
	else if(wordLength == 19)
	{
	 for(int x = 0; x < 1; x++)
	 {
	  for(int z = 0; z < sentenceLength; z++)
	  {
	   if(word[x] == sentence[z])
	   {
		if(word[x + 1] == sentence[z + 1])
		{
		 if(word[x + 2] == sentence[z + 2])
		 {
		  if(word[x + 3] == sentence[z + 3])
		  {
		   if(word[x + 4] == sentence[z + 4])
		   {
			if(word[x + 5] == sentence[z + 5])
			{
			 if(word[x + 6] == sentence[z + 6])
			 {
			  if(word[x + 7] == sentence[z + 7])
			  {
			   if(word[x + 8] == sentence[z + 8])
			   {
				if(word[x + 9] == sentence[z + 9])
				{
			     if(word[x + 10] == sentence[z + 10])
				 {
				  if(word[x + 11] == sentence[z + 11])
				  {
				   if(word[x + 12] == sentence[z + 12])
				   {
					if(word[x + 13] == sentence[z + 13])
					{
					 if(word[x + 14] == sentence[z + 14])
					 {
					  if(word[x + 15] == sentence[z + 15])
					  {
					   if(word[x + 16] == sentence[z + 16])
					   {
						if(word[x + 17] == sentence[z + 17])
					    {
						 if(word[x + 18] == sentence[z + 18])
					     {
			              wordCheck = true;
			              break;
						 }
					    }
					   }
					  }
					 }
					}
				   }
				  }
				 }
			    }
			   }
			  }
			 }
			}
		   }
		  }
		 }
	    }
	   }
      }
     }
	}
	
	else if(wordLength == 20)
	{
	 for(int x = 0; x < 1; x++)
	 {
	  for(int z = 0; z < sentenceLength; z++)
	  {
	   if(word[x] == sentence[z])
	   {
		if(word[x + 1] == sentence[z + 1])
		{
		 if(word[x + 2] == sentence[z + 2])
		 {
		  if(word[x + 3] == sentence[z + 3])
		  {
		   if(word[x + 4] == sentence[z + 4])
		   {
			if(word[x + 5] == sentence[z + 5])
			{
			 if(word[x + 6] == sentence[z + 6])
			 {
			  if(word[x + 7] == sentence[z + 7])
			  {
			   if(word[x + 8] == sentence[z + 8])
			   {
				if(word[x + 9] == sentence[z + 9])
				{
			     if(word[x + 10] == sentence[z + 10])
				 {
				  if(word[x + 11] == sentence[z + 11])
				  {
				   if(word[x + 12] == sentence[z + 12])
				   {
					if(word[x + 13] == sentence[z + 13])
					{
					 if(word[x + 14] == sentence[z + 14])
					 {
					  if(word[x + 15] == sentence[z + 15])
					  {
					   if(word[x + 16] == sentence[z + 16])
					   {
						if(word[x + 17] == sentence[z + 17])
					    {
						 if(word[x + 18] == sentence[z + 18])
					     {
						  if(word[x + 19] == sentence[z + 19])
					      {
			               wordCheck = true;
			               break;
						  }
						 }
					    }
					   }
					  }
					 }
					}
				   }
				  }
				 }
			    }
			   }
			  }
			 }
			}
		   }
		  }
		 }
	    }
	   }
      }
     }
	}
	
	//god i f-ing hate coding
	return wordCheck; 
}
