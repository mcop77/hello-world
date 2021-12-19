/* Name: Marshall Copeland
Date: 11/20/20
Section: #10
Assignment: HW #6
Due Date: 12/04/20
About this project: Write a program that uses a stack object to determine if a string is a palindrome (i.e. the string is spelled identically backward and forward). The program should ignore spaces and punctuation.

All work below was performed by Marshall Copeland */


// Fig. 21.15: Stackcomposition.h
// Template Stack class definition with composed List object.
#ifndef STACKCOMPOSITION_H
#define STACKCOMPOSITION_H

#include "list.h" // List class definition

template< typename STACKTYPE >
class Stack 
{
public:
   // no constructor; List constructor does initialization

   // push calls stackList object's insertAtFront member function
   void push( const STACKTYPE &data ) 
   { 
      stackList.insertAtFront( data ); 
   } // end function push
   
   // pop calls stackList object's removeFromFront member function
   bool pop( STACKTYPE &data ) 
   { 
      return stackList.removeFromFront( data ); 
   } // end function pop
   
   // isStackEmpty calls stackList object's isEmpty member function
   bool isStackEmpty() const 
   { 
      return stackList.isEmpty(); 
   } // end function isStackEmpty
   
   // printStack calls stackList object's print member function
   void printStack() const 
   { 
      stackList.print(); 
   } // end function printStack
private:
   List< STACKTYPE > stackList; // composed List object
}; // end class Stack

#endif
*******************************************************************/
