#include "HashMap.hpp"


namespace
{
	unsigned int DefaultHashFunction(const std::string& string)  // djb2 by Dan Bernstein
	{
	    unsigned long hash = 5381;

	    for (auto c : string) 
	    {
	        hash = (hash << 5) + hash + c; /* hash * 33 + c */
	    }

	    return hash;
	}

}





// ============================ CONSTRUCTORS ============================

HashMap::HashMap()
	   : ArrayOfBuckets{new HashMap::Node*[initialBucketCount]}, CurrentSize{0}
{
	hasher = DefaultHashFunction;
	NumOfBuckets = initialBucketCount;

	for (int counter = 0; counter < initialBucketCount; counter++)
	{
		ArrayOfBuckets[counter] = nullptr;
	}
}



HashMap::HashMap(HashFunction hasher)
	   : ArrayOfBuckets{new HashMap::Node*[initialBucketCount]}, CurrentSize{0}
{
	hasher = hasher;
	NumOfBuckets = initialBucketCount;
	
	for (int counter = 0; counter < initialBucketCount; counter++)
	{
		ArrayOfBuckets[counter] = nullptr;
	}
}




// ============================ COPY CONSTRUCTOR ============================

HashMap::HashMap(const HashMap& hm)
	   : ArrayOfBuckets{new HashMap::Node*[hm.NumOfBuckets]}, CurrentSize{hm.CurrentSize}
{
	hasher = hm.hasher;
	NumOfBuckets = hm.NumOfBuckets;


	for (int counter = 0; counter < NumOfBuckets; counter++)
	{
		ArrayOfBuckets[counter] = nullptr;
	}


	for (int counter = 0; counter < NumOfBuckets; counter++)  // for each array index
	{
		Node* CurrentNode = hm.ArrayOfBuckets[counter];

		while (CurrentNode != nullptr)  // while the Node has stored info
		{
			std::string CurrentKey = CurrentNode->key;
			std::string CurrentValue = CurrentNode->value;
			add(CurrentKey, CurrentValue);

			CurrentNode = CurrentNode->next;
		}
	}
}




// ============================ DESTRUCTOR ============================

HashMap::~HashMap()  // deletes the array and all nodes with it
{
	for (int counter = 0; counter < NumOfBuckets; counter++)  // for each array index
	{
		Node* head = ArrayOfBuckets[counter];

		if (head != nullptr)
		{
			if (head->next == nullptr)
			{
				delete head;
			}

			else
			{
				while (head != nullptr)  // while there are nodes in this array index
				{
					Node* CurrentNode = head->next;
					head->next = CurrentNode->next;
					delete CurrentNode;
				}

				if (head != nullptr)
				{  
					delete head;
				}
			}
		}
		
	}

	delete[] ArrayOfBuckets;  // finally delete the array itself
}




// ============================ ASSIGNMENT OPERATOR ============================ 

HashMap& HashMap::operator=(const HashMap& hm)
{
	if (this != &hm)
	{
		this->~HashMap();
		ArrayOfBuckets = new Node*[hm.NumOfBuckets];


		for (int counter = 0; counter < hm.NumOfBuckets; counter++)
		{
			ArrayOfBuckets[counter] = nullptr;
		}


		for (int counter2 = 0; counter2 < hm.NumOfBuckets; counter2++)
		{
			Node* CurrentNode = hm.ArrayOfBuckets[counter2];

			while (CurrentNode != nullptr)
			{
				std::string CurrentKey = CurrentNode->key;
				std::string CurrentValue = CurrentNode->value;

				this->add(CurrentKey, CurrentValue);

				CurrentNode = CurrentNode->next;
			}
		}

		NumOfBuckets = hm.NumOfBuckets;
		CurrentSize = hm.CurrentSize;
		hasher = hm.hasher;

	}

	return *this;
}




// ============================ EDITOR FUNCTIONS ============================

void HashMap::add(const std::string& key, const std::string& value)  // not done
{

	if (contains(key) == 0)  // if the array does not contain the given key, do the function
	{
		int hashKey = DefaultHashFunction(key) % NumOfBuckets;
		Node* head = ArrayOfBuckets[hashKey];

		Node* NewNode = new Node{key, value, nullptr};

		if (head == nullptr)
		{  ArrayOfBuckets[hashKey] = NewNode;  }

		else
		{
			Node* CurrentNode = ArrayOfBuckets[hashKey]->next;  // goes to second node in ll

			while (CurrentNode != nullptr)
			{
				head = head->next;
				CurrentNode = CurrentNode->next;
			}

			head->next = NewNode;
		}

		CurrentSize++;

		if (loadFactor() > 0.8)
		{
			unsigned int newNumOfBuckets = NumOfBuckets * 2 + 1;  // get new amount of bucket count

			HashMap::Node** newArrayOfBuckets = new HashMap::Node*[newNumOfBuckets];  // create the new array of buckets with the new amount

			for (int counter = 0; counter < newNumOfBuckets; counter++)  // make all of the array indexes of nullptr
			{  newArrayOfBuckets[counter] = nullptr;  }

			for (int counter2 = 0; counter2 < NumOfBuckets; counter2++)  // go into old array
			{
				Node* CurrentNode = ArrayOfBuckets[counter2];  // saves the current node

				while (CurrentNode != nullptr)  // while the current node contains info
				{  
					Node* newNode = new Node{CurrentNode->key, CurrentNode->value, nullptr};  // make a new node and store the key and value
					int newHashKey = DefaultHashFunction(CurrentNode->key) % newNumOfBuckets;  // find hashkey for our new array
					Node* newArrayNode = newArrayOfBuckets[newHashKey];  // keep track of the new array on that index

					if (newArrayOfBuckets[newHashKey] == nullptr)  // if it's empty, make it into our new node
						{  newArrayOfBuckets[newHashKey] = newNode;  }

					else  // if not, do this
					{
						while (newArrayNode->next != nullptr)  // while our new array's index has nodes, keep skipping
						{
							newArrayNode = newArrayNode->next;
						}

						newArrayNode->next = newNode;  // finally we give our new node into our new array
					}

					CurrentNode = CurrentNode->next;
				}
			}

			this->~HashMap();
			NumOfBuckets = newNumOfBuckets;
			ArrayOfBuckets = newArrayOfBuckets;
		}

	}

	
}



void HashMap::remove(const std::string& key)
{
	if (contains(key) == 1)
	{
		int hashKey = DefaultHashFunction(key) % NumOfBuckets;
		Node* head = ArrayOfBuckets[hashKey];
		Node* CurrentNode = head->next;

		if (head->key == key)
		{
			delete head;
			head = CurrentNode;
			CurrentSize--;
			return;
		}

		else
		{
			while (CurrentNode != nullptr)
			{
				if (CurrentNode->key == key)
				{
					head->next = CurrentNode->next;
					delete CurrentNode;
					CurrentSize--;
					return;

				}

				else
				{
					CurrentNode = CurrentNode->next;
					head = head->next;
				}
				
			}
		}
	}
	
}




// ============================ RETURN FUNCTIONS ============================

bool HashMap::contains(const std::string& key) const
{
	int hashKey = DefaultHashFunction(key) % NumOfBuckets;
	Node* CurrentNode = ArrayOfBuckets[hashKey];

	while (CurrentNode != nullptr)
	{
		if (CurrentNode->key == key)
		{  
			return true;
		}

		else
			{  CurrentNode = CurrentNode->next;  }
		
	}

	return false;
}



std::string HashMap::value(const std::string& key) const
{
	int hashKey = DefaultHashFunction(key) % NumOfBuckets;
	Node* CurrentNode = ArrayOfBuckets[hashKey];

	while (CurrentNode != nullptr)
	{

		if (key == CurrentNode->key)
		{  return CurrentNode->value;  }

		CurrentNode = CurrentNode->next;
	}

	return "";
}



unsigned int HashMap::size() const
{
	return CurrentSize;
}



unsigned int HashMap::bucketCount() const
{
	return NumOfBuckets;
}



double HashMap::loadFactor() const
{
	return (double) size() / bucketCount();
}



unsigned int HashMap::maxBucketSize() const
{

	unsigned int CurrentLargest = 0;

	for (int counter = 0; counter < NumOfBuckets; counter++)
	{
		unsigned int NumOfNodes = 0;
		Node* CurrentNode = ArrayOfBuckets[counter];

		while (CurrentNode != nullptr)
		{
			NumOfNodes++;
			CurrentNode = CurrentNode->next;
		}

		if (NumOfNodes > CurrentLargest)
		{  CurrentLargest = NumOfNodes;  }
	}

	return CurrentLargest;
}