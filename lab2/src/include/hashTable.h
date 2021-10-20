#ifndef _HASH_TABLE_
#define _HASH_TABLE_
#define DEFAULT_SIZE 8
#define REHASH_SIZE 0.75

#include <string>

using namespace std;

struct Student
{
	unsigned age;
	unsigned weight;
};

typedef string studentName;

class HashTable
{
	static const unsigned defaultSize = DEFAULT_SIZE;
	constexpr static const double rehashSize = REHASH_SIZE;

	struct Node
	{
		Student value;
		studentName key;
		bool state;
	};

	Node** array;
	unsigned numOfEl;
	unsigned bufferSize;
	unsigned sizeAllNonNullPtr; 

	unsigned hashFunctionHorner(const studentName& name, unsigned key);
	unsigned hash1(const studentName& name);
	unsigned hash2(const studentName& name);
	void newArrayCreation(unsigned size, Node ** newArray);
	void resize();
	void rehash();

public:
	
	HashTable();
	~HashTable();
	HashTable(const HashTable& b);
	HashTable(HashTable&& b);
	void swap(HashTable& b);
	void clear();
	bool erase(const studentName& name);
	bool insert(const studentName& name, const Student& value);
	bool contains(const studentName& key); 
	size_t size() const;
	bool empty() const;
};

#endif