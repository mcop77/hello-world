/* Name: Marshall Copeland
Date: 03/27/21
Section: #07
Assignment: Project #5
Due Date: 04/08/21
About this project: Implement a hash table ADT and other supporting user interfaces;  develop a simple password server program. Analyze the time complexity of certain functions.

All work below was performed by Marshall Copeland */

#include "passserver.h"

PassServer::PassServer(size_t size) : passwordHashTable(size)
{}

PassServer::~PassServer()
{
	passwordHashTable.clear();
}

bool PassServer::load(const char *filename)
{
	return passwordHashTable.load(filename);
}

bool PassServer::addUser(std::pair<std::string, std::string> & kv)
{
	std::string password = encrypt(kv.second);
	
	std::pair<std::string, std::string> newPair;
	
	newPair = std::make_pair(kv.first, password);
	
	if(find(newPair.first))
	{
		return false;
	}
	
	else return passwordHashTable.insert(newPair);
}

bool PassServer::addUser(std::pair<std::string, std::string> &&kv)
{
	std::string password = encrypt(kv.second);
	
	std::pair<std::string, std::string> newPair;
	
	newPair = std::make_pair(kv.first, password);
	
	if(find(newPair.first))
	{
		return false;
	}
	
	else return passwordHashTable.insert(std::move(newPair));
}

bool PassServer::removeUser(const std::string & k)
{
	return passwordHashTable.remove(k);
}

bool PassServer::changePassword(const std::pair<std::string, std::string> & p, const std::string & newpassword)
{
	std::string oldPassword = encrypt(p.second);
	std::string newPassword = encrypt(newpassword);
	
	std::pair<std::string, std::string> oldPair;
	oldPair = std::make_pair(p.first, oldPassword);
	
	std::pair<std::string, std::string> newPair;
	newPair = std::make_pair(p.first, newPassword);
	
	if(passwordHashTable.match(oldPair))
	{
		if(oldPassword != newPassword)
		{
			passwordHashTable.insert(newPair);
			return true;
		}
		
		else return false;	
	}
				
	else return false;
}

bool PassServer::find(const std::string & user) const
{
	return passwordHashTable.contains(user);	
}
		
void PassServer::dump()
{
	passwordHashTable.dump();
}
		
size_t PassServer::size() const
{
	return passwordHashTable.size();
}
		
bool PassServer::write_to_file(const char *filename) const
{
	return passwordHashTable.write_to_file(filename);
}

std::string PassServer::encrypt(const std::string & str)
{
	char salt[] = "$1$########";
	char * password = new char[35];
	strcpy(password, crypt(str.c_str(), salt));
	
	std::string pass(password);
	std::string delim = "$";
	
	std::string encryptedPassword = pass.substr(12, 22);
	
	return encryptedPassword;
}


