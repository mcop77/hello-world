/* Name: Marshall Copeland
Date: 03/27/21
Section: #07
Assignment: Project #5
Due Date: 04/08/21
About this project: Implement a hash table ADT and other supporting user interfaces;  develop a simple password server program. Analyze the time complexity of certain functions.

All work below was performed by Marshall Copeland */

// returns largest prime number <= n or zero if input is too large
// This is likely to be more efficient than prime_above(), because
// it only needs a vector of size n

template <typename K, typename V>
	HashTable<K,V>::HashTable(size_t s) : hashTableSize{0}
	{	
		hashTable.resize(prime_below(s));
		std::cout << prime_below(s) << "\n" << std::endl;
	}

template <typename K, typename V>
	HashTable<K,V>::~HashTable()
	{
		clear();
	}

template <typename K, typename V>				
	bool HashTable<K,V>::contains(const K & k) const
	{
		bool found = false;
				
		for(auto & hash : hashTable)
		{
			for(auto lst = hash.begin(); lst != hash.end(); ++lst)
			{
				if((*lst).first == k)
				{
					found = true;
				}
			}
		}

		if(found == true)
		{
			return true;
		}
		
		else return false;
	}

template <typename K, typename V>
	bool HashTable<K,V>::match(const std::pair<K,V> &kv) const
	{
		bool found = false;
				
		for(auto & hash : hashTable)
		{
			for(auto lst = hash.begin(); lst != hash.end(); ++lst)
			{
				if((*lst).first == kv.first)
				{
					if((*lst).second == kv.second)
					{
						found = true;
					}
				}
			}
		}

		if(found == true)
		{
			return true;
		}
		
		else return false;
	}

template <typename K, typename V>
	bool HashTable<K,V>::insert(const std::pair<K, V> & kv)
	{
		bool found = false;
				
		auto & lst = hashTable[myhash(kv.first)];
				
		for(auto itr = lst.begin(); itr != lst.end(); ++itr)
		{
			if((*itr).first == kv.first && (*itr).second == kv.second)
			{	
				return false;	
			}
					
			else if((*itr).first == kv.first)
			{
				(*itr).second = kv.second;
				return true;
			}
		}		

		lst.push_back(kv);

		if(++hashTableSize > hashTable.capacity())
		{
			rehash();
		}

		return true;
	}

template <typename K, typename V>
	bool HashTable<K,V>::insert(std::pair<K,V> && kv)
	{
		bool found = false;
				
		auto & lst = hashTable[myhash(kv.first)];
				
		for(auto itr = lst.begin(); itr != lst.end(); ++itr)
		{
			if((*itr).first == kv.first && (*itr).second == kv.second)
			{		
				return false;		
			}
					
			else if((*itr).first == kv.first)
			{
				(*itr).second = kv.second;
				return true;
			}
		}		

		lst.push_back(std::move(kv));

		if(++hashTableSize > hashTable.capacity())
		{
			rehash();
		}

		return true;
	}

template <typename K, typename V>
	bool HashTable<K,V>::remove(const K & k)
	{
		bool found = false;
				
		for(int x = 0; x < hashTable.capacity(); ++x)
		{
			for(auto lst = hashTable[x].begin(); lst != hashTable[x].end(); ++lst)
			{
				if((*lst).first == k)
				{
					hashTable[x].erase(lst);
					--hashTableSize;
					return true;
				}
			}
		}

		return false;
	}

template <typename K, typename V>
	void HashTable<K,V>::clear()
	{
		makeEmpty();
	}

template <typename K, typename V>
	bool HashTable<K,V>::load(const char *filename)
	{
		std::ifstream file;
		
		file.open(filename);
		
		std::string tempKey;
		std::string tempValue;
	
		if(!file)
		{
			return false;
		}
		
		else
		{
			while(file)
			{
				std::getline(file, tempKey, ' ');

				std::getline(file, tempValue, '\n');

				
				std::stringstream key(tempKey);
				std::stringstream value(tempValue);
								
				K Key;
				V Value;				
																
				key >> Key;
				value >> Value;
			
				insert(std::make_pair(Key, Value));
			}
			
			file.close();
			return true;
		}
	}

template <typename K, typename V>	
	void HashTable<K,V>::dump() const
	{		
		for(int x = 0; x < hashTable.capacity(); ++x)
		{
			std::cout << "[" << x << "]: ";
				
			for(auto lst = hashTable[x].begin(); lst != hashTable[x].end(); ++lst)
			{
				std::cout << (*lst).first << " " << (*lst).second;
					
				if(lst != --hashTable[x].end())
				{
					std::cout << ":";
				}
			}
				
			std::cout << "\n";
		}
	}

template <typename K, typename V>	
	size_t HashTable<K,V>::size() const
	{
		return hashTableSize;
	}
	
template <typename K, typename V>	
	bool HashTable<K,V>::write_to_file(const char *filename) const
	{
		std::ofstream file;
		
		file.open(filename);
		
		if(!file)
		{
			return false;
		}
		
		else
		{
			for(auto & hash : hashTable)
			{
				for(auto list = hash.begin(); list != hash.end(); ++list)
				{
					file << (*list).first << " " << (*list).second << "\n";
				}
			}
			
			file.close();
			return true;
		}
	}


//private functions


template <typename K, typename V>
	void HashTable<K,V>::makeEmpty()
	{
		for (auto & hash : hashTable)
		{
			hash.clear();	
		}
		
		hashTableSize = 0;
	}
	
template <typename K, typename V>
	void HashTable<K,V>::rehash()
	{
		//changed multiplier from 2 to 3
		//talked to Prof. Duan, he said it should be fine
		
		auto tempHashTable = hashTable;
			
		hashTable.resize( prime_below(3 * hashTable.capacity()));
		
		makeEmpty();
		
		for(auto & hash : tempHashTable)
		{
			for(auto lst = hash.begin(); lst != hash.end(); ++lst)
			{
				insert(*lst);
			}
		}
	}

template <typename K, typename V>
	size_t HashTable<K,V>::myhash(const K &k) const
	{
		static std::hash<K> h;
		return h(k) % hashTable.size();	
	}

template <typename K, typename V>
	unsigned long HashTable<K,V>::prime_below (unsigned long n)
	{
	  if (n > max_prime)
		{
		  std::cerr << "** input too large for prime_below()\n";
		  return 0;
		}
	  if (n == max_prime)
		{
		  return max_prime;
		}
	  if (n <= 1)
		{
			std::cerr << "** input too small \n";
		  return 0;
		}

	  // now: 2 <= n < max_prime
	  std::vector <unsigned long> v (n+1);
	  setPrimes(v);
	  while (n > 2)
		{
		  if (v[n] == 1)
		return n;
		  --n;
		}

	  return 2;
	}

//Sets all prime number indexes to 1. Called by method prime_below(n) 
template <typename K, typename V>
	void HashTable<K,V>::setPrimes(std::vector<unsigned long>& vprimes)
	{
	  int i = 0;
	  int j = 0;

	  vprimes[0] = 0;
	  vprimes[1] = 0;
	  int n = vprimes.capacity();

	  for (i = 2; i < n; ++i)
		vprimes[i] = 1;

	  for( i = 2; i*i < n; ++i)
		{
		  if (vprimes[i] == 1)
			for(j = i + i ; j < n; j += i)
			  vprimes[j] = 0;
		}
	}
