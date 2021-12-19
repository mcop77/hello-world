/* Name: Marshall Copeland
Date: 02/02/21
Section: #07
Assignment: Project #2
Due Date: 02/11/21
About this project: This project has two parts. In the first part, you will implement a doubly-linked list named List (and corresponding) iterator support. In this second part, you will develop a simple memory management application using the doubly-linked list List that you have developed in the first part of the project. 

All work below was performed by Marshall Copeland */

#include <iostream>

#include "List.h"

using namespace cop4530;

class MyMemoryBlock
{	
	public:
		MyMemoryBlock(int ind = 0, int len = 0);
				
		int get_length() const;
		int get_index() const;
		int allocate_mem(int len);
			
		void free_mem(int len);
		
	private:
		int index;
		int length;
			
};


class MyMemory
{
	public:
		MyMemory(int num = 0, int len = 0);
		
		void resize(int num = 100, int len = 100);
		
		int req_mem(int len);
		
		bool release_mem(int ind, int len);
		
		void merge_mem();
		
		void dump();
		
		~MyMemory();
	
	
	
		List<MyMemoryBlock>* mlist;
		
		int max_index;
		int block_size;
			
};




#include "MyMemory.hpp"
