/* Name: Marshall Copeland
Date: 02/02/21
Section: #07
Assignment: Project #2
Due Date: 02/11/21
About this project: This project has two parts. In the first part, you will implement a doubly-linked list named List (and corresponding) iterator support. In this second part, you will develop a simple memory management application using the doubly-linked list List that you have developed in the first part of the project. 

All work below was performed by Marshall Copeland */

#include <iostream>

	MyMemoryBlock::MyMemoryBlock(int ind, int len)
	{
		index = ind;
		length = len;
	}

	int MyMemoryBlock::get_length() const
	{
		return length;
	}

	int MyMemoryBlock::get_index() const
	{
		return index;
	}

	int MyMemoryBlock::allocate_mem(int len)
	{
		length = length - len;
		
		if(length < 0)
		{
			return -1;
		}
		
		else return len;
	}
	
	void MyMemoryBlock::free_mem(int len)
	{
		length = length + len;
	}
	

	MyMemory::MyMemory(int num, int len)
	{		
		max_index = num - 1;
		block_size = len;
		
				
		for(int x = 0; x < num; x++)
		{
			mlist->push_back(MyMemoryBlock(x, len));
		}
		
	}
	
	void MyMemory::resize(int num, int len)
	{
		if(mlist->size() != 0)
		{
			mlist->clear(); 
			
			for(int x = 0; x < num; x++)
			{
				mlist->push_back(MyMemoryBlock(len, x));
			}
		}
		
		else
		{
			for(int x = 0; x < num; x++)
			{
				mlist->push_back(MyMemoryBlock(len, x));
			}
		}
	}
	
	int MyMemory::req_mem(int len) //i kept getting undefined references to the -> operator so i commented out the code
	{ /*
		int tempIndex;
		bool breakLoop = false;
				
		for(List<MyMemoryBlock>::iterator I = mlist->begin(); I != mlist->end(); ++I)
		{
			if(I->get_length() >= len)
			{
				I->allocate_mem(len);
				tempIndex = I->get_index();
				
				if(I->get_length() == 0)
				{
					mlist->remove(*I);
					breakLoop = true;
				}
			}
		}
		
		if(breakLoop == true)
		{
			return tempIndex;
		}
		
		else return -1;
		*/
	}
	
	bool MyMemory::release_mem(int ind, int len)
	{ /*
		bool indexCheck = false;
		bool increaseIndexCheck = false;
		
		auto I = mlist->begin();
		
		while(I != mlist->end())
		{
			if(I->get_index() == ind)
			{
				I->free_mem(len);
				indexCheck = true;
				
				return true;
			}
		}
		
		if(indexCheck == false)
		{
			I = mlist->begin();
			
			while(I != mlist->end() && increaseIndexCheck == false)
			{
				if(I->get_index() > ind)
				{
					mlist->insert(I, MyMemoryBlock(ind, len));
					increaseIndexCheck = true;
					
					return true;
				}
			}
		}
		
		if(increaseIndexCheck == false)
		{
			return false;
		}	
		
		else return true;
		*/
	}
	
	void MyMemory::merge_mem()
	{	/*
		auto nextLength = mlist->begin();
		
		for(auto I = mlist->begin(); I != mlist->end(); ++I)
		{
			if(++I != mlist->end())
			{
				nextLength = ++I;
				
				while((I->get_length() + nextLength->get_length()) <= block_size)
				{
					I->free_mem(nextLength->get_length());
					mlist->remove(*nextLength);
				}
			}
		}
*/
	}
	
	void MyMemory::dump()
	{	/*
		std::cout << "Number of blocks: " << block_size << std::endl;
		
		for(auto I = mlist->begin(); I != mlist->end(); ++I)
		{
			std::cout << "Block(index = " << I->get_index() << "): " << I->get_length() << std::endl;
		}
		*/
	}
	
	MyMemory::~MyMemory()
	{
		delete mlist;
	}
	

	
	
	

	
	
