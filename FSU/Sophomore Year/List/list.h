/* Name: Marshall Copeland
Date: 11/20/20
Section: #10
Assignment: HW #7
Due Date: 12/04/20
About this project: Write a program that uses a stack object to determine if a string is a palindrome (i.e. the string is spelled identically backward and forward). The program should ignore spaces and punctuation.

All work below was performed by Marshall Copeland */



// Fig. 21.4: list.h
// Template List class definition.
#ifndef LIST_H
#define LIST_H

#include <iostream>

using std::cout;

#include <new>
#include "listnode.h"  // ListNode class definition

template< class NODETYPE >
class List {

public:
   List();      // constructor
   ~List();     // destructor
   void insertAtFront( const NODETYPE & L);
   void insertAtBack( const NODETYPE & L);
   bool removeFromFront( NODETYPE & L);
   bool removeFromBack( NODETYPE & L);
   bool isEmpty() const;
   void print() const;
   
   void insertMiddle( const NODETYPE & L,  const int N);
   bool removeMiddle( NODETYPE & value,  const int N);
   
   List(const List& L);
   List& operator = (const List< NODETYPE > &L);

private:
   ListNode< NODETYPE > *firstPtr;  // pointer to first node
   ListNode< NODETYPE > *lastPtr;   // pointer to last node

   // utility function to allocate new node
   ListNode< NODETYPE > *getNewNode( const NODETYPE & L);

}; // end class List

// default constructor
template< class NODETYPE >
List< NODETYPE >::List() 
   : firstPtr( 0 ), 
     lastPtr( 0 ) 
{ 
   // empty body

} // end List constructor

// destructor
template< class NODETYPE >
List< NODETYPE >::~List()
{
   if ( !isEmpty() ) {    // List is not empty
//      cout << "Destroying nodes ...\n";

      ListNode< NODETYPE > *currentPtr = firstPtr;
      ListNode< NODETYPE > *tempPtr;

      while ( currentPtr != 0 )         // delete remaining nodes
      {  
         tempPtr = currentPtr;

// commented out the output -- no need to print what we are deallocating
//         cout << tempPtr->data << '\n';  

         currentPtr = currentPtr->nextPtr;
         delete tempPtr;

      }

   }

//   cout << "All nodes destroyed\n\n";

} // end List destructor

// insert node at front of list
template< class NODETYPE >
void List< NODETYPE >::insertAtFront( const NODETYPE &value )
{
   ListNode< NODETYPE > *newPtr = getNewNode( value );

   if ( isEmpty() )  // List is empty
      firstPtr = lastPtr = newPtr;

   else {  // List is not empty
      newPtr->nextPtr = firstPtr;
      firstPtr = newPtr;

   } // end else

} // end function insertAtFront

// insert node at back of list
template< class NODETYPE >
void List< NODETYPE >::insertAtBack( const NODETYPE &value )
{
   ListNode< NODETYPE > *newPtr = getNewNode( value );

   if ( isEmpty() )  // List is empty
      firstPtr = lastPtr = newPtr;

   else {  // List is not empty
      lastPtr->nextPtr = newPtr;
      lastPtr = newPtr;

   } // end else

} // end function insertAtBack

// delete node from front of list
template< class NODETYPE >
bool List< NODETYPE >::removeFromFront( NODETYPE &value )
{
   if ( isEmpty() )  // List is empty
      return false;  // delete unsuccessful

   else {  
      ListNode< NODETYPE > *tempPtr = firstPtr;

      if ( firstPtr == lastPtr )
         firstPtr = lastPtr = 0;
      else
         firstPtr = firstPtr->nextPtr;

      value = tempPtr->data;  // data being removed
      delete tempPtr;

      return true;  // delete successful

   } // end else

} // end function removeFromFront

// delete node from back of list
template< class NODETYPE >
bool List< NODETYPE >::removeFromBack( NODETYPE &value )
{
   if ( isEmpty() )
      return false;  // delete unsuccessful

   else {
      ListNode< NODETYPE > *tempPtr = lastPtr;

      if ( firstPtr == lastPtr )
         firstPtr = lastPtr = 0;
      else {
         ListNode< NODETYPE > *currentPtr = firstPtr;

         // locate second-to-last element
         while ( currentPtr->nextPtr != lastPtr )
            currentPtr = currentPtr->nextPtr;

         lastPtr = currentPtr;
         currentPtr->nextPtr = 0;

      } // end else

      value = tempPtr->data;
      delete tempPtr;

      return true;  // delete successful

   } // end else

} // end function removeFromBack

// is List empty?
template< class NODETYPE > 
bool List< NODETYPE >::isEmpty() const 
{ 
   return firstPtr == 0; 
   
} // end function isEmpty

// return pointer to newly allocated node
template< class NODETYPE >
ListNode< NODETYPE > *List< NODETYPE >::getNewNode( 
   const NODETYPE &value )
{
   return new ListNode< NODETYPE >( value );

} // end function getNewNode

// display contents of List
template< class NODETYPE >
void List< NODETYPE >::print() const
{
   if ( isEmpty() ) {
      cout << "The list is empty\n\n";
      return;

   } // end if

   ListNode< NODETYPE > *currentPtr = firstPtr;

   cout << "The list is: ";

   while ( currentPtr != 0 ) {
      cout << currentPtr->data << ' ';
      currentPtr = currentPtr->nextPtr;

   } // end while

   cout << "\n\n";

} // end function print


template< class NODETYPE >
void List < NODETYPE >::insertMiddle(const NODETYPE & L, const int N) //insert middle function
{
	int size = 0; //creates a size variable to keep track of the linked list size
	
	ListNode< NODETYPE > *tempPtr;					//temp pointer variable
	ListNode< NODETYPE > *currentPtr = firstPtr;	//current pointer variable is set to the first pointer in the list
	ListNode< NODETYPE > *newPtr = getNewNode( L ); //new pointer is set to the new node with the data passed in
		
	while(currentPtr != 0) //cycles through the list and gets the size
	{
		currentPtr = currentPtr->nextPtr;
		size++;
	}
		
	currentPtr = firstPtr; //crrent pointer is set back to the first node
		
	if(N <= 1) //if the index passed in is less than or equal to 1
	{
		insertAtFront(L); //the data is inserted at the front
	}
	
	else if(N > size) //if the index pased in is greater than the size of the list
	{
		insertAtBack(L); //the data is inserted at the end
	}
	
	else
	{		
		for(int x = 2; x <= size; x++) //otherwise the loop looks for where the node will be inserted
		{			
			if(x < N) //if x isnt the index, it will continue through the list
			{
				currentPtr = currentPtr->nextPtr; //cycling through the list
			}
			
			if(x == N) //if x matches the index 
			{
				tempPtr = currentPtr;				//temp pointer is set equal to the current pointer, which is the spot befer the node should be inserted
				newPtr->nextPtr = tempPtr->nextPtr; //the new pointers next pointer then points to the pointer after the previous
				tempPtr->nextPtr = newPtr; 			//temp pointers next pointer is now pointing to the new pointer
			}
		}
	}
}


template< class NODETYPE >
bool List < NODETYPE >::removeMiddle( NODETYPE & value, const int N) //remove middle function
{
	int size = 0; //size of the list variable
	
	ListNode< NODETYPE > *tempPtr; //temp pointer variable
	ListNode< NODETYPE > *currentPtr = firstPtr; //current pointer is set to the first pointer in the list
	
	while(currentPtr != 0) //cycles through the list and counts the number of nodes
	{
		currentPtr = currentPtr->nextPtr;
		size++;
				
	}
	
	currentPtr = firstPtr; //current pointer is set back to the first node
		
	if(N < 1 || N > size) //if the index is out of bounds
	{
		return false; //returns false
	}
	
	else if(N == 1) //if the index it the first node
	{
		removeFromFront(value); //calls the removeFromBack function with value passed in
		return true; //returns true for success
	}
	
	else if(N == size) //if the index is the last node
	{
		removeFromBack(value); //calls removeFromBack
		return true; //returns true
	}
	
	else //if the index is in the lst but isnt first or last
	{
		for(int x = 1; x < size; x++) //cycles through the list
		{			
			if(x == N - 1) //if x is one less than the index
			{
				tempPtr = currentPtr; //temp pointer is set to the current pointer
				currentPtr = currentPtr->nextPtr; //current pointer is then set to the next pointer
			
				tempPtr->nextPtr = currentPtr->nextPtr; //temp pointers next pointer is set to current pointers next pointer
				
				value = currentPtr->data; //value is set to current pointers data
				delete currentPtr; //current ointer is then deleted
				
				return true; //return true for success
			}
			
			else //if n - 1 hasnt been reached yet in the list
			{
				currentPtr = currentPtr->nextPtr; //the current pointer is set to the next pointer
			}
		}
	}
}


template< class NODETYPE >   
List < NODETYPE >::List(const List& L) //copy constructor
{
	ListNode< NODETYPE > *tempPtr = L.firstPtr; //temp pointer is set to the passed in first pointer

	if(tempPtr != 0) //if the temp pointer isnt a null pointer
	{
		firstPtr = 0; //first pointer is set to 0
		
		while ( tempPtr != 0 ) //while temp pointer isnt 0
		{  
			insertAtBack(tempPtr->getData()); //a new list is created and the nodes are populated with the previous data
			tempPtr = tempPtr->nextPtr; //temp pointer is then set to the next pointer
		}
	}
	
	else //otherwise the first and last pointers are set ot 0
	{
		firstPtr = 0;
		lastPtr = 0;
	}
}


template< class NODETYPE >
List < NODETYPE > &List < NODETYPE >::operator = (const List< NODETYPE > &L) //assignment operator
{
	ListNode< NODETYPE > *tempPtr2 = L.firstPtr; //temp pointer 2 is set to the passed in first pointer
	
	if (this != &L) //if it snt the same
	{
		if ( !isEmpty() ) //if the list isnt empty
		{  
			ListNode< NODETYPE > *currentPtr = firstPtr; //creates a current pointer and sets it to the first pointer
			ListNode< NODETYPE > *tempPtr; //creates another temp pointer

			while ( currentPtr != 0 ) //while the curretnt pointer isnt 0
			{  
				tempPtr = currentPtr; //temp pointer is set to the current pointer
				currentPtr = currentPtr->nextPtr; //current pointer is then set to the next pointer
				delete tempPtr; //the "current" pointer is deleted (temp pointer)
			}
		}
		
		firstPtr = 0; //first pointer is set to 0
		
		while ( tempPtr2 != 0 ) //while temp pointer 2 isnt 0
		{
			insertAtBack(tempPtr2->getData()); //data is populated from the old to the current object
			tempPtr2 = tempPtr2->nextPtr; //temp pointer 2 then points to the next node
		}
	}
	
	return *this; //returns the current objects list data
}

//gg, what a class

#endif


