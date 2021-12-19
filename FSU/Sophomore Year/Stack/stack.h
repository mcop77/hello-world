/* Name: Marshall Copeland
Date: 02/14/21
Section: #07
Assignment: Project #3
Due Date: 02/25/21
About this project: Implement a generic stack container as an adaptor class template. Implement a program that converts infix expression to postfix expression and implement a program that evaluates postfix expression using the stack container you develop

All work below was performed by Marshall Copeland */
#include <vector>
#include <iostream>

namespace cop4530
{
	template <typename T>
		class Stack
		{
			public:
				Stack();
				~Stack();
				Stack(const Stack<T>&);
				Stack(Stack<T>&&);
				Stack<T>& operator=(const Stack <T>&);
				Stack<T> & operator=(Stack<T> &&);
				
				bool empty() const;
				
				void clear();
				void push(const T& x);
				void push(T && x);
				void pop();
				
				T& top();
				
				const T& top() const;
				
				int size() const;
				
				void print(std::ostream& os, char ofc = ' ') const;
			
			private:
				std::vector<T> myStack;
			
		};
	
		template <typename T>
			std::ostream& operator<<(std::ostream& os, const Stack<T>& a);
			
		template <typename T>
			bool operator==(const Stack<T>&, const Stack<T>&);
			
		template <typename T>
			bool operator!=(const Stack<T>&, const Stack<T>&);
			
		template <typename T>
			bool operator<=(const Stack<T>& a, const Stack<T>& b);
	
	
	
	
	
	
	
	
	#include "stack.hpp"
}
