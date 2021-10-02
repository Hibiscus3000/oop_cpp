#include "hashTable.h"

HashTable::HashTable()
{
	bufferSize = defaultSize;
	size = 0;
	sizeAllNonNullPtr = 0;
	array = new Node * [bufferSize];
	unsigned i;
	for (i = 0; i < bufferSize; ++i)
		array[i] = NULL;
}

HashTable::~HashTable()
{
	unsigned i;
	for (i = 0; i < bufferSize; ++i)
	{
		if (array[i])
			delete array[i];
	}
	delete array;
}