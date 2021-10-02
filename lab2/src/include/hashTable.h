#ifndef _HASH_TABLE_
#define _HASH_TABLE_
#define DEFAULT_SIZE 8
#define REHASH_SIZE 0.75

#include <string>

using namespace std;

typedef struct Student;

struct Student
{
	unsigned age;
	unsigned weight;
};

typedef string StudentName;

class HashTable
{
	static const unsigned defaultSize = DEFAULT_SIZE;
	constexpr static const double rehashSize = REHASH_SIZE;

	struct Node
	{
		Student value;
		StudentName key;
	};

	Node** array;
	unsigned size;
	unsigned bufferSize;
	unsigned sizeAllNonNullPtr; 

public:
	

	HashTable();
	~HashTable();
};

#endif