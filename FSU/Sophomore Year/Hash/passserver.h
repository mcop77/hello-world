/* Name: Marshall Copeland
Date: 03/27/21
Section: #07
Assignment: Project #5
Due Date: 04/08/21
About this project: Implement a hash table ADT and other supporting user interfaces;  develop a simple password server program. Analyze the time complexity of certain functions.

All work below was performed by Marshall Copeland */

#include "unistd.h"
#include <cstring>
#include <string>
#include "hashtable.h"

class PassServer
{
	public:
		PassServer(size_t size = 101);
		~PassServer();
		
		bool load(const char *filename);
		bool addUser(std::pair<std::string, std::string> & kv);
		bool addUser(std::pair<std::string, std::string> &&kv);
		bool removeUser(const std::string & k);
		bool changePassword(const std::pair<std::string, std::string> & p, const std::string & newpassword);
		bool find(const std::string & user) const;
		
		void dump();
		
		size_t size() const;
		
		bool write_to_file(const char *filename) const;
		
		
	private:
		std::string encrypt(const std::string & str);
		cop4530::HashTable<std::string, std::string> passwordHashTable;
	
	
};

