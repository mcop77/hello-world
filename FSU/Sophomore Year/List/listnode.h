/* Name: Marshall Copeland
Date: 11/20/20
Section: #10
Assignment: HW #6
Due Date: 12/04/20
About this project: Write a program that uses a stack object to determine if a string is a palindrome (i.e. the string is spelled identically backward and forward). The program should ignore spaces and punctuation.

All work below was performed by Marshall Copeland */


// Fig. 21.3: listnode.h
// Template ListNode class definition.
#ifndef LISTNODE_H
#define LISTNODE_H

// forward declaration of class List 
template< class NODETYPE > class List;  

template< class NODETYPE >
class ListNode {
   friend class List< NODETYPE >; // make List a friend

public:
   ListNode( const NODETYPE & );  // constructor
   NODETYPE getData() const;      // return data in node

private:
   NODETYPE data;                 // data
   ListNode< NODETYPE > *nextPtr; // next node in list

}; // end class ListNode

// constructor
template< class NODETYPE >
ListNode< NODETYPE >::ListNode( const NODETYPE &info )
   : data( info ), 
     nextPtr( 0 ) 
{ 
   // empty body

} // end ListNode constructor

// return copy of data in node
template< class NODETYPE >
NODETYPE ListNode< NODETYPE >::getData() const 
{ 
   return data; 
   
} // end function getData

#endif
