#ifndef _HASH_TABLE_
#define _HASH_TABLE_
#define DEFAULT_SIZE 8
#define REHASH_SIZE 0.75

#include <string>

struct Student
{
	unsigned age;
	unsigned weight;
};

typedef std::string studentName;

unsigned hashFunctionHorner(const studentName& name, unsigned key, unsigned bufferSize);
unsigned hash1(const studentName& name, unsigned bufferSize);
unsigned hash2(const studentName& name, unsigned bufferSize);

class HashTable
{
	static const unsigned defaultSize = DEFAULT_SIZE;
	constexpr static const double rehashSize = REHASH_SIZE;

	struct Node
	{
		studentName key;
		Student value = {0,0};
		bool state = true;
	};

	Node** array = NULL;
	unsigned numOfEl = 0;
	unsigned bufferSize = 0;
	unsigned sizeAllNonNullPtr = 0;

	void newArrayCreation(unsigned oldBufferSize, unsigned bufferSize, HashTable::Node** newArray);
	void resize();
	void rehash();

public:

	HashTable();
	~HashTable();
	HashTable(const HashTable& b);
	HashTable(HashTable&& b) noexcept(false);
	HashTable& operator=(const HashTable& b);
	HashTable& operator=(HashTable&& b) noexcept(false);
	void swap(HashTable& b);
	void clear();
	bool erase(const studentName& name);
	bool insert(const studentName& name, const Student& value);
	bool contains(const studentName& key) const; 
	Student& operator[](const studentName& name);
	Student& at(const studentName& name);
	const Student& cat(const studentName& name) const;
	size_t size() const;
	bool empty() const;
	
	friend bool operator==(const HashTable& a, const HashTable& b);
	friend bool operator!=(const HashTable& a, const HashTable& b);

};

bool operator==(const HashTable& a, const HashTable& b);
bool operator!=(const HashTable& a, const HashTable& b);

#endif
