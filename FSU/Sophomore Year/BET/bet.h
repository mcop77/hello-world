/* Name: Marshall Copeland
Date: 03/06/21
Section: #07
Assignment: Project #4
Due Date: 03/25/21
About this project: In this project, you are asked to develop a binary expression tree and use the tree to convert postfix expressions into infix expressions.

All work below was performed by Marshall Copeland */

#include <string>
#include <stack>
#include <vector>
#include <algorithm>

namespace std
{
	class BET
	{
		public:
			BET()
			{
				root = nullptr;
			}
			
			BET(const string postfix): root{ nullptr }
			{
				if(buildFromPostfix(postfix) == false)
				{
					cout << "Invalid postfix expression, Try Again!\n" << endl;
				}
			}
			
			BET(const BET& rhs): root{ nullptr }
			{
				root = clone( rhs.root );
			}
			
			~BET()
			{
				makeEmpty(root);
			}
			
			bool buildFromPostfix(const string postfix)
			{	
				string postfixTemp;
				string tempString;
				vector<string> postfixString;
				int tempCount = 0;
				
				postfixTemp.assign(postfix);
					
				postfixTemp.resize(postfix.size() + 1, ' ');
				
				for(int x = 0; x < postfixTemp.size(); x++)
				{		
					if(postfixTemp[x] != ' ')
					{
						tempString.resize(tempString.size() + 1, postfixTemp[x]);
						tempCount++;
					}
					
					else if(postfixTemp[x] == ' ')
					{	
						if(tempString.size() > 0)
						{
							postfixString.push_back(tempString);
						
							tempString.erase();
							tempString.resize(0);
							tempCount = 0;
						}
					}
				}
			
				stack<BinaryNode*> treeConstruct;
				
				for(int x = 0; x < postfixString.size(); x++)
				{							
					if(postfixString[x] == "+" || postfixString[x] == "-" || postfixString[x] == "*" || postfixString[x] == "/")
					{
						BinaryNode* node = new BinaryNode{postfixString[x], nullptr, nullptr};
						
						if(treeConstruct.size() <= 1)
						{
							cout << "Invalid postfix expression, Try Again!\n" << endl;
							return false;
						}
						
						else
						{
							node->right = treeConstruct.top();
							treeConstruct.pop();
						
							node->left = treeConstruct.top();
							treeConstruct.pop();
						
							treeConstruct.push(node);
						}
					}
					
					else
					{
						BinaryNode* node = new BinaryNode{postfixString[x], nullptr, nullptr};
						
						treeConstruct.push(node);
					}
				}
			
				if(treeConstruct.empty() == true)
				{
					cout << "Invalid postfix expression, Try Again!\n" << endl;
					return false;
				}
				
				else if(treeConstruct.size() > 1)
				{
					cout << "Invalid postfix expression, Try Again!\n" << endl;
					return false;
				}
				
				else
				{	
					root = treeConstruct.top();
					return true;
				}
				
			}
						
			const BET & operator=(const BET& b)
			{
				if(&b != this)
				{		
					root = clone(b.root);
				}
				
				return *this;
			}
			
			void printInfixExpression()
			{
				printInfixExpression(root);
				
				cout << "\n";
			}
			
			void printPostfixExpression()
			{
				printPostfixExpression(root);
				
				cout << "\n";
			}
			
			size_t size()
			{
				size(root);
			}
			
			size_t leaf_nodes()
			{
				leaf_nodes(root);
			}
			
			bool empty()
			{
				if(root == nullptr)
				{
					return true;
				}
				
				else return false;
			}
			
			
		private:
			struct BinaryNode
			{
				string element; 
				BinaryNode *left;
				BinaryNode *right;
				
				BinaryNode(const string& e, BinaryNode *l = NULL, BinaryNode *r = NULL)
					: element(e), left(l), right(r) {}

			};
			
			BinaryNode *root;
			
			void printInfixExpression(BinaryNode *n)
			{				
				if(n == nullptr)
				{
					return;
				}
				
				printInfixExpression(n->left);
				
				cout << n->element << " ";
				
				printInfixExpression(n->right);
			}
			
			void printPostfixExpression(BinaryNode *n)
			{
				if(n == nullptr)
				{
					return;
				}
				
				printPostfixExpression(n->left);
				
				printPostfixExpression(n->right);
				
				cout << n->element << " ";
			}
			
			void makeEmpty(BinaryNode* &t)
			{
				if( t != nullptr )
				{
					makeEmpty( t->left );
					makeEmpty( t->right );
					delete t;
				}
				
				t = nullptr;
			}
			
			BinaryNode * clone(BinaryNode* t) const
			{
				if( t == nullptr )
				{
					return nullptr;
				}
					
				else return new BinaryNode{ t->element, clone( t->left ), clone( t->right ) };
			}
			
			size_t size(BinaryNode *t)
			{
				if(t == nullptr)
				{
					return 0;
				}
				
				else return(size(t->left) + size(t->right) + 1);
			}
			
			size_t leaf_nodes(BinaryNode *t)
			{
				if(t != nullptr)
				{
					if(t->left == nullptr && t->right == nullptr)
					{
						return 1;
					}
					
					else
					{
						return leaf_nodes(t->left) + leaf_nodes(t->right);
					}
				}
				
				else return 0;
			}
			
		
	};
}
