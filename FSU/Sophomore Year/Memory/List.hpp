/* Name: Marshall Copeland
Date: 02/02/21
Section: #07
Assignment: Project #2
Due Date: 02/11/21
About this project: This project has two parts. In the first part, you will implement a doubly-linked list named List (and corresponding) iterator support. In this second part, you will develop a simple memory management application using the doubly-linked list List that you have developed in the first part of the project. 

All work below was performed by Marshall Copeland */
#include <iostream>


//NESTED CONST ITERATOR FUNCTIONS
template<typename T>
	List<T>::const_iterator::const_iterator() : current { nullptr }
	{}

template<typename T> 
	const T & List<T>::const_iterator::operator*() const
	{
		return retrieve();
	}

template<typename T> 
	const T * List<T>::const_iterator::operator->() const
	{
		return *this;
	}

template<typename T> 
	typename List<T>::const_iterator & List<T>::const_iterator::operator++()
	{
		current = current->next;
					
		return *this;
	}

template<typename T> 
	typename List<T>::const_iterator List<T>::const_iterator::operator++(int)
	{
		const_iterator old = *this;
		++(*this);
						
		return old;
	}

template <typename T>
	typename List<T>::const_iterator & List<T>::const_iterator::operator--()
	{
		current = current->prev;
						
		return *this;
	}

template <typename T>
	typename List<T>::const_iterator List<T>::const_iterator::operator--(int)
	{
		const_iterator old = *this;
		--(*this);
						
		return old;
	}

template <typename T> 
	bool List<T>::const_iterator::operator==(const const_iterator &rhs) const
	{
		return current == rhs.current;
	}

template <typename T> 
	bool List<T>::const_iterator::operator!=(const const_iterator &rhs) const
	{
		return !(*this == rhs);
	}
	
template <typename T>
	T & List<T>::const_iterator::retrieve() const
	{
		return current->data;
		
	}
	
template <typename T>
	List<T>::const_iterator::const_iterator( Node *p ) : current{ p }
	{ }
	

		
		
		
//NESTED ITERATOR FUNCTIONS
template <typename T> 
	List<T>::iterator::iterator()
	{}

template <typename T> 
	T & List<T>::iterator::operator*()
	{
		return const_iterator::retrieve();
	}

template <typename T> 
	const T & List<T>::iterator::operator*() const
	{
		return const_iterator::operator*();
	}

template <typename T> 
	const T* List<T>::iterator::operator->() const
	{
		return const_iterator::operator->();
	}
	
template <typename T> 
	typename List<T>::iterator & List<T>::iterator::operator++()
	{
		this->current = this->current->next;
	
		return *this;
	}
	
template <typename T> 
	typename List<T>::iterator List<T>::iterator::operator++(int)
	{
		iterator old = *this;
		++( *this );
		
		return old;
	}

template <typename T> 
	typename List<T>::iterator & List<T>::iterator::operator--()
	{
		this->current = this->current->prev;
		
		return *this;
	}

template <typename T> 
	typename List<T>::iterator List<T>::iterator::operator--(int)
	{
		iterator old = *this;
		--( *this );
		
		return old;
	}
	
template <typename T>
	List<T>::iterator::iterator( Node *p ) : const_iterator{ p }
	{ }
	
	
	

//LIST FUNCTIONS	
template <typename T> 
	List<T>::List()
	{
		init();
	}

template <typename T> 
	List<T>::List(const List &rhs)
	{
		init();
		for(auto & x : rhs)
			push_back(x);
	}

template <typename T> 
	List<T>::List(List &&rhs) : theSize{ rhs.theSize }, head{ rhs.head }, tail{ rhs.tail }
	{
		rhs.theSize = 0;
		rhs.head = nullptr;
		rhs.tail = nullptr;
	}

template <typename T> 
	List<T>::List(int num, const T& val)
	{
		init();
		for(int x = 0; x < num; x++)
			push_back(val);
	}	

template <typename T> 
	List<T>::List(const_iterator start, const_iterator end)
	{
		init();
		for(const_iterator itr = start; itr != end; ++itr)
		{
			push_back(*itr);
		}
	}

template <typename T> 
	List<T>::~List()
	{
		clear();
		delete head;
		delete tail;
	}

template <typename T> 
	const typename List<T>::List & List<T>::operator=(const List &rhs)
	{
		List copy = rhs;
		std::swap( *this, copy );
		
		return *this;
	}

template <typename T> 
	typename List<T>::List & List<T>::operator=(List && rhs)
	{
		std::swap( theSize, rhs.theSize );
		std::swap( head, rhs.head );
		std::swap( tail, rhs.tail );
			return *this;
	}

template <typename T> 
	int List<T>::size() const
	{
		return theSize;
	}

template <typename T> 
	bool List<T>::empty() const
	{
		return size() == 0;
	}

template <typename T> 
	void List<T>::clear()
	{
		while(!empty())
			pop_front();
	}

template <typename T> 
	void List<T>::reverse()
	{
		List<T> tempList;
		
		
		Node *current = head->next;
		
		
		while(current != tail)
		{
			tempList.push_front(current->data);
			current = current->next;
		}
		
		 *this = tempList;
	}

template <typename T> 
	T & List<T>::front()
	{
		return *begin();
	}

template <typename T> 
	const T& List<T>::front() const
	{
		return *begin();
	}
	
template <typename T> 
	T & List<T>::back()
	{
		return *--end;
	}

template <typename T> 
	const T & List<T>::back() const
	{
		return *--end;
	}

template <typename T> 
	void List<T>::push_front(const T & val)
	{
		insert(begin(), val);
	}

template <typename T> 
	void List<T>::push_front(T && val)
	{
		insert(begin(), std::move(val));
	}
	
template <typename T> 
	void List<T>::push_back(const T & val)
	{
		insert(end(), val);
	}

template <typename T> 
	void List<T>::push_back(T && val)
	{
		insert(end(), std::move(val));
	}

template <typename T> 
	void List<T>::pop_front()
	{
		erase(begin());
	}

template <typename T> 
	void List<T>::pop_back()
	{
		erase(--end());
	}

template <typename T> 
	void List<T>::remove(const T &val)
	{ 	
		auto I = List<T>::begin();
	
		while(I != end()) 
		{
			 if(*I == val)
			{
				I = List<T>::erase(I);
			} 
			
			else 
			{
				I++;
			}
		}
		
	}

template <typename T> 
	void List<T>::print(std::ostream& os, char ofc) const
	{ 
		Node *current = head->next;
		
		while(current != nullptr)
		{
			os << current->data << ofc;
			current = current->next;
		}
	} 

template <typename T> 
	typename List<T>::iterator List<T>::begin()
	{
		return iterator(head->next);
	}

template <typename T> 
	typename List<T>::const_iterator List<T>::begin() const
	{
		return const_iterator(head->next);
	}

template <typename T> 
	typename List<T>::iterator List<T>::end()
	{
		return iterator(tail);
	}

template <typename T> 
	typename List<T>::const_iterator List<T>::end() const
	{
		return const_iterator(tail);
	}

template <typename T> 
	typename List<T>::iterator List<T>::insert(iterator itr, const T& val)
	{
		Node *p = itr.current;
		++theSize;
		
		return iterator( p->prev = p->prev->next = new Node{ val, p->prev, p});
	}

template <typename T> 
	typename List<T>::iterator List<T>::insert(iterator itr, T && val)
	{
		Node *p = itr.current;
		++theSize;
		
		return iterator( p->prev = p->prev->next = new Node{ std::move( val ), p->prev, p } );
	}

template <typename T> 
	typename List<T>::iterator List<T>::erase(iterator itr)
	{
		Node *p = itr.current;
		iterator retVal{ p->next };
		p->prev->next = p->next;
		p->next->prev = p->prev;
		delete p;
		--theSize;
		
		return retVal;
	}

template <typename T> 
	typename List<T>::iterator List<T>::erase(iterator start, iterator end)
	{
		for(iterator itr = start; itr != end; )
			itr = erase(itr);
		
		return end;
	}
	
template <typename T>
	void List<T>::init()
	{
		theSize = 0;
        head = new Node;
        tail = new Node;
        head->next = tail;
        tail->prev = head;
	}
	
	

// GLOBAL FUNCTIONS
template <typename T>
	bool operator==(const List<T> & lhs, const List<T> &rhs)
	{
		int count = 0;
	
		auto rhsItr = rhs.begin();
		
		if(lhs.size() == rhs.size())
		{
			for(auto lhsItr = lhs.begin(); lhsItr != lhs.end(); ++lhsItr)
			{
				if(*lhsItr == *rhsItr)
				{
					count++;
					rhsItr++;
				}
			}
			
			if(count == lhs.size())
			{
				return true;
			}
			
			else return false;
		}
		
		else return false;
	}

template <typename T>
	bool operator!=(const List<T> & lhs, const List<T> &rhs)
	{ 
		int count = 0;
	
		auto rhsItr = rhs.begin();
		
		if(lhs.size() == rhs.size())
		{
			for(auto lhsItr = lhs.begin(); lhsItr != lhs.end(); ++lhsItr)
			{
				if(*lhsItr == *rhsItr)
				{
					count++;
					rhsItr++;
				}
			}
			
			if(count < lhs.size())
			{
				return true;
			}
			
			else return false;
		}
		
		else return true;
	}


template <typename T>
	std::ostream & operator<<(std::ostream &os, const List<T> &l)
	{	
		l.print(os);
			
		return os;
	}
		







