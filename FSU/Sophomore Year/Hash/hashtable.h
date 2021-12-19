/* Name: Marshall Copeland
Date: 03/27/21
Section: #07
Assignment: Project #5
Due Date: 04/08/21
About this project: Implement a hash table ADT and other supporting user interfaces;  develop a simple password server program. Analyze the time complexity of certain functions.

All work below was performed by Marshall Copeland */

#include <iostream>
#include <vector>
#include <list>
#include <fstream>
#include <string>
#include <sstream>
#include <istream>

#ifndef HASHTABLE_H
#define HASHTABLE_H


namespace cop4530
{
	template <typename K, typename V>
		class HashTable
		{
			public:
				HashTable(size_t size = 101);
				~HashTable();
				
				bool contains(const K & k) const;
				bool match(const std::pair<K,V> &kv) const;
				bool insert(const std::pair<K,V> & kv);
				bool insert(std::pair<K,V> && kv);
				bool remove(const K & k);
				
				void clear();
				
				bool load(const char *filename);
				
				void dump() const;
				
				size_t size() const;
				
				bool write_to_file(const char *filename) const;
				
				// max_prime is used by the helpful functions provided
				// to you.
				static const unsigned int max_prime = 1301081;
				// the default_capacity is used if the initial capacity 
				// of the underlying vector of the hash table is zero. 
				static const unsigned int default_capacity = 11;
			
			
			private:
				void makeEmpty();
				
				void rehash();
				
				size_t myhash(const K & k) const;
				
				unsigned long prime_below(unsigned long);
				
				void setPrimes(std::vector<unsigned long>&);
				
				std::vector<std::list<std::pair<K, V>>> hashTable;
				size_t hashTableSize;
						
		};
		
	#include "hashtable.hpp"
}

 
#endif
