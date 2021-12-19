/* Name: Marshall Copeland
Date: 02/14/21
Section: #07
Assignment: Project #3
Due Date: 02/25/21
About this project: Implement a generic stack container as an adaptor class template. Implement a program that converts infix expression to postfix expression and implement a program that evaluates postfix expression using the stack container you develop

All work below was performed by Marshall Copeland */

template <typename T>
	Stack<T>::Stack()
	{
		std::vector<T> myStack;
	}
	
template <typename T>
	Stack<T>::~Stack()
	{}
	
template <typename T>
	Stack<T>::Stack(const Stack<T> & rhs)
	{
		//std::vector<T> myStack;
		
		for(int x = 0; x < rhs.size(); ++x)
		{
			myStack.push_back(rhs.myStack[x]);
		}
	}
	
template <typename T>
	Stack<T>::Stack(Stack<T>&& rhs)
	{
		myStack = std::move(rhs.myStack);
		
		rhs.clear();
	}
	
template <typename T>
	typename Stack<T>::Stack & Stack<T>::operator=(const Stack<T>& rhs)
	{
		std::vector<T> copy = rhs.myStack;
		
		std::swap(myStack, copy);
		
		return *this;
	}
	
template <typename T>
	typename Stack<T>::Stack & Stack<T>::operator=(Stack<T> && rhs)
	{
		std::swap(myStack, rhs.myStack);
		
		return *this;
	}
	
template <typename T>
	bool Stack<T>::empty() const
	{
		if(myStack.size() == 0)
		{
			return true;
		}
		
		else return false;
	}
	
template <typename T>
	void Stack<T>::clear()
	{
		for(int x = 0; x < myStack.size(); ++x)
		{
			myStack.pop_back();
		}
	}
	
template <typename T>
	void Stack<T>::push(const T& x)
	{
		myStack.push_back(x);
	}
	
template <typename T>
	void Stack<T>::push(T && x)
	{
		myStack.push_back(x);
	}
	
template <typename T>
	void Stack<T>::pop()
	{
		myStack.pop_back();
	}
	
template <typename T>
	T & Stack<T>::top()
	{
		return myStack[myStack.size() - 1];
	}
	
template <typename T>
	const T & Stack<T>::top() const
	{
		return myStack[myStack.size() - 1];
	}
	
template <typename T>
	int Stack<T>::size() const
	{
		return myStack.size();
	}
	
template <typename T>
	void Stack<T>::print(std::ostream& os, char ofc) const
	{
		for(T value : myStack)
		{
			os << value << ofc;
		}
		
		os << std::endl;
	}
	


//global functions
template <typename T>
	std::ostream& operator<<(std::ostream& os, const Stack<T>& a)
	{
		a.print(os);
		
		return os;
	}
	
template <typename T>
	bool operator==(const Stack<T>& lhs, const Stack<T>& rhs)
	{
		Stack<T> lhsCopy = lhs;
		Stack<T> rhsCopy = rhs;
		
		int count = 0;
		
		if(lhsCopy.size() == rhsCopy.size())
		{
			for(int x = 0; x < lhs.size(); ++x)
			{
				if(lhsCopy.top() == rhsCopy.top())
				{
					count++;
					lhsCopy.pop();
					rhsCopy.pop();
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
	bool operator!=(const Stack<T>& lhs, const Stack<T>& rhs)
	{
		Stack<T> lhsCopy = lhs;
		Stack<T> rhsCopy = rhs;
		
		int count = 0;
		
		if(lhs.size() == rhs.size())
		{
			for(int x = 0; x < lhs.size(); ++x)
			{
				if(lhsCopy.top() == rhsCopy.top())
				{
					count++;
					
					lhsCopy.pop();
					rhsCopy.pop();
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
	bool operator<=(const Stack<T>& a, const Stack<T>& b)
	{
		Stack<T> lhsCopy = a;
		Stack<T> rhsCopy = b;
		
		int count = 0;
		
		for(int x = 0; x < a.size(); ++x)
		{
			if(lhsCopy.top() <= rhsCopy.top())
			{
				count++;
				
				lhsCopy.pop();
				rhsCopy.pop();
			}
		}
		
		if(count == a.size())
		{
			return true;
		}
		
		else return false;
	}
	
	
	
	
	
