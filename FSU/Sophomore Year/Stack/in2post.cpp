/* Name: Marshall Copeland
Date: 02/14/21
Section: #07
Assignment: Project #3
Due Date: 02/25/21
About this project: Implement a generic stack container as an adaptor class template. Implement a program that converts infix expression to postfix expression and implement a program that evaluates postfix expression using the stack container you develop

All work below was performed by Marshall Copeland */

#include <iostream>
#include <string>
#include <istream>
#include <sstream>
#include <cstdio>
#include <cctype>
#include "stack.h"

using namespace std;
using namespace cop4530;

int main()
{
	Stack<string> myStack;
	Stack<string> evaluation;
	
	string plus = "+"; //operators
	string minus = "-";
	string mult = "*";
	string div = "/";
	string parenL = "(";
	string parenR = ")";
	string space = " ";
	
	int parenLCount = 0;
	int parenRCount = 0;
	
	bool error = false;
	
	vector<string> infix;
	vector<string> print;
	
	string infixExpression;
	string tempString;
	int tempCount = 0;
	
	bool variable = false;
	string varCheck;
	
	string operandOne;
	string operandTwo;
	
	int operandResult;
	float operandResultFloat;
	
	string strOperandResult;

	do{
		cout << "Enter infix expression (\"exit\" to quit): ";
		getline(cin,infixExpression);
	
		if(infixExpression != "exit")
		{	
			infixExpression.resize(infixExpression.size() + 1, ' ');
				
			for(int x = 0; x < infixExpression.size(); x++)
			{		
				if(infixExpression[x] != ' ')
				{
					tempString.resize(tempString.size() + 1, infixExpression[x]);
					tempCount++;
				}
				
				else if(infixExpression[x] == ' ')
				{	
					if(tempString.size() > 0)
					{
						infix.push_back(tempString);
					
						tempString.erase();
						tempString.resize(0);
						tempCount = 0;
					}
				}
			}
			
			for(int x = 0; x < infix.size(); ++x) 
			{	
				if(error == false) 
				{
					if(infix[x] != plus && infix[x] != minus && infix[x] != mult && infix[x] != div && infix[x] != parenL && infix[x] != parenR) 
					{
						if((x > 0 && infix[x - 1] == plus) || (x > 0 && infix[x - 1] == minus) || (x > 0 && infix[x - 1] == mult) || (x > 0 && infix[x - 1] == div) || (x > 0 && infix[x - 1] == parenL) || infix.size() == 1)
						{
							print.push_back(infix[x]);
						}
						
						else if((x + 1 < infix.size() && infix[x + 1] == plus) || (x + 1 < infix.size() && infix[x + 1] == minus) || (x + 1 < infix.size() && infix[x + 1] == mult) || (x + 1 < infix.size() && infix[x + 1] == div) || (x + 1 < infix.size() && infix[x + 1] == parenR))
						{
							print.push_back(infix[x]);
						}
						
						else 
						{
							error = true;
							cout << "\nError: Missing operators in the expression" << endl;
						}
					}
					
					else if(infix[x] == plus || infix[x] == minus || infix[x] == mult || infix[x] == div)
					{					
						if((x > 0 && infix[x - 1] == plus) || (x > 0 && infix[x - 1] == minus) || (x > 0 && infix[x - 1] == mult) || (x > 0 && infix[x - 1] == div) || (x > 0 && infix[x - 1] == parenL) || infix.size() == 1)
						{
							error = true;
							cout << "\nError: Missing operands in the expression" << infix[x] << endl;
						}
						
						else if((x + 1 < infix.size() && infix[x + 1] == plus) || (x + 1 < infix.size() && infix[x + 1] == minus) || (x + 1 < infix.size() && infix[x + 1] == mult) || (x + 1 < infix.size() && infix[x + 1] == div) || (x + 1 < infix.size() && infix[x + 1] == parenR))
						{
							error = true;
							cout << "\nError: Missing operands in the expression" << endl;
						}
						
						else
						{
							while(myStack.empty() == false && myStack.top() != parenL && ((myStack.top() == mult && infix[x] == mult) || (myStack.top() == mult && infix[x] == div) || (myStack.top() == div && infix[x] == mult) || (myStack.top() == div && infix[x] == div) || (myStack.top() == mult && infix[x] == plus) || (myStack.top() == mult && infix[x] == minus) || (myStack.top() == div && infix[x] == plus) || (myStack.top() == div && infix[x] == minus) || (myStack.top() == plus && infix[x] == plus) || (myStack.top() == plus && infix[x] == minus) || (myStack.top() == minus && infix[x] == plus) || (myStack.top() == minus && infix[x] == minus)))
							{
								print.push_back(myStack.top());
								myStack.pop();
							}
					
							myStack.push(infix[x]);
						}
					} 
					
					else if(infix[x] == parenL)
					{
						parenLCount++;
						
						if((x > 0 && infix[x - 1] != plus) && (x > 0 && infix[x - 1] != minus) && (x > 0 && infix[x - 1] != mult) && (x > 0 && infix[x - 1] != div) && (x > 0 && infix[x - 1] != parenL) || infix.size() == 1)
						{
							error = true;
							cout << "\nError: Missing operands in the expression" << endl;
						}
						
						else if((x + 1 < infix.size() && infix[x + 1] == plus) || (x + 1 < infix.size() && infix[x + 1] == minus) || (x + 1 < infix.size() && infix[x + 1] == mult) || (x + 1 < infix.size() && infix[x + 1] == div) || (x + 1 < infix.size() && infix[x + 1] == parenR))
						{
							error = true;
							cout << "\nError: Missing operands in the expression" << endl;
						}
						
						else myStack.push(infix[x]);
					}
					
					else if(infix[x] == parenR) 
					{
						parenRCount++;
						
						if(parenRCount != parenLCount)
						{
							error = true;
						}
						
						if(error == false)
						{
							if((x > 0 && infix[x - 1] == plus) || (x > 0 || infix[x - 1] == minus) && (x > 0 && infix[x - 1] == mult) || (x > 0 && infix[x - 1] == div) || (x > 0 && infix[x - 1] == parenL) || infix.size() == 1)
							{
								error = true;
								cout << "\nError: Missing operands in the expression" << endl;
							}
							
							else if((x + 1 < infix.size() && infix[x + 1] != plus) && (x + 1 < infix.size() && infix[x + 1] != minus) && (x + 1 < infix.size() && infix[x + 1] != mult) && (x + 1 < infix.size() && infix[x + 1] != div) && (x + 1 < infix.size() && infix[x + 1] != parenR))
							{
								error = true;
								cout << "\nError: Missing operands in the expression" << endl;
							}
							
							else
							{
								while (myStack.top() != parenL) 
								{
									print.push_back(myStack.top());
									myStack.pop();
								}
						
								myStack.pop();
							}
						}
					}	
				}
			}
			
			if(parenLCount != parenRCount)
			{
				cout << "Mismatched parentheses" << endl;
				error = true;
			}
			
			if(error == false)
			{
				while (!myStack.empty()) 
				{
					print.push_back(myStack.top());
					myStack.pop();
				}
				
				cout << "\n\nPostfix expression: ";
				
				for(int x = 0; x < print.size(); ++x)
				{
					cout << print[x] << space;
				}
				
				cout << endl;
				
				cout << "Postfix evaluation: ";
								
				for(int x = 0; x < print.size(); ++x)
				{
					if(print[x] != plus && print[x] != minus && print[x] != mult && print[x] != div)
					{
						varCheck = print[x];
						
						if(isalpha(varCheck[0]) != 0)
						{
							variable = true;
						}
					} 
					
					if(variable == false)
					{
						if(print[x] != plus && print[x] != minus && print[x] != mult && print[x] != div)
						{
							evaluation.push(print[x]);
						}

						else if(evaluation.size() >= 2 && (print[x] == plus || print[x] == minus || print[x] == mult || print[x] == div))
						{
							operandOne = evaluation.top();
							evaluation.pop();
							
							operandTwo = evaluation.top();
							evaluation.pop();
							
							if(print[x] == plus)
							{
								stringstream one(operandOne);
								stringstream two(operandTwo);
								
								int One;
								int Two;
								
								float OneFloat = stof(operandOne);
								float TwoFloat = stof(operandTwo);
																
								one >> One;
								two >> Two;
								
								if(One != OneFloat || Two != TwoFloat)
								{
									operandResultFloat = OneFloat + TwoFloat;
									strOperandResult = to_string(operandResultFloat);
								}
								
								else
								{
									operandResult = One + Two;
									strOperandResult = to_string(operandResult);
								}
								
								evaluation.push(strOperandResult);
							}
							
							else if(print[x] == minus)
							{
								stringstream one(operandOne);
								stringstream two(operandTwo);
								
								int One;
								int Two;
								
								float OneFloat = stof(operandOne);
								float TwoFloat = stof(operandTwo);
																
								one >> One;
								two >> Two;
								
								if(One != OneFloat || Two != TwoFloat)
								{
									operandResultFloat = OneFloat - TwoFloat;
									strOperandResult = to_string(operandResultFloat);
								}
								
								else
								{
									operandResult = One - Two;
									strOperandResult = to_string(operandResult);
								}
								
								evaluation.push(strOperandResult);
							}
							
							else if(print[x] == mult)
							{
								stringstream one(operandOne);
								stringstream two(operandTwo);
								
								int One;
								int Two;
								
								float OneFloat = stof(operandOne);
								float TwoFloat = stof(operandTwo);
																
								one >> One;
								two >> Two;
								
								if(One != OneFloat || Two != TwoFloat)
								{
									operandResultFloat = OneFloat * TwoFloat;
									strOperandResult = to_string(operandResultFloat);
								}
								
								else
								{
									operandResult = One * Two;
									strOperandResult = to_string(operandResult);
								}
								
								evaluation.push(strOperandResult);
							}
							
							else if(print[x] == div)
							{
								stringstream one(operandOne);
								stringstream two(operandTwo);
								
								int One;
								int Two;
								
								float OneFloat = stof(operandOne);
								float TwoFloat = stof(operandTwo);
																
								one >> One;
								two >> Two;
								
								if(One != OneFloat || Two != TwoFloat)
								{
									operandResultFloat = OneFloat / TwoFloat;
									strOperandResult = to_string(operandResultFloat);
								}
								
								else
								{
									operandResult = One / Two;
									strOperandResult = to_string(operandResult);
								}
								
								evaluation.push(strOperandResult);
							}
						}
						
						else if(evaluation.size() < 2 && (print[x] == plus || print[x] == minus || print[x] == mult || print[x] == div))
						{
							cout << "Error. Not enough operands in stack" << endl;
							
						}
					}					
				}
				
				if(variable == true)
				{
					for(int x = 0; x < print.size(); ++x)
					{
						cout << print[x] << space;
					}	
						
					cout << " = ";
					
					for(int x = 0; x < print.size(); ++x)
					{
						cout << print[x] << space;
					}	
					
					cout << "\n" << endl;
				}
				
				else
				{
					if(evaluation.size() > 1)
					{
						cout << "Error. More than one operand left in stack" << endl;
					}
					
					else if(evaluation.size() == 1)
					{
						for(int x = 0; x < print.size(); ++x)
						{
							cout << print[x] << space;
						}
						
						cout << " = " << evaluation.top() << endl;	
					}
					
					else cout << "= 0" << endl;
		
					cout << "\n" << endl;
				}	
			}
		}
		
		evaluation.clear();
		print.clear();		
		infix.clear();
		varCheck.clear();
		variable = false;
		error = false;
		
	} while(cin.eof() != true && infixExpression != "exit");
	
	return 0;
}
