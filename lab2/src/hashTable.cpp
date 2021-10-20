#include "hashTable.h"

unsigned HashTable::hashFunctionHorner(const studentName& name, unsigned key)
{
	unsigned i, hashResult = 0, nameLength = (unsigned)(name.size());
	for (i = 0; i < nameLength; ++i)
		hashResult = (key * hashResult + (unsigned)(name[i])) % numOfEl;
	hashResult = (hashResult * 2 + 1) % numOfEl;
	return hashResult;
}

unsigned HashTable::hash1(const studentName& name)
{
	return hashFunctionHorner(name, numOfEl + 1);
}


unsigned HashTable::hash2(const studentName& name)
{
	return hashFunctionHorner(name, numOfEl - 1);
}

void HashTable::newArrayCreation(unsigned size, Node ** newArray)
{
	numOfEl = 0;
	sizeAllNonNullPtr = 0;
	unsigned i;
	for (i = 0; i < size; ++i)
		newArray[i] = NULL;
	std::swap(newArray, array);
	for (i = 0; i < size; ++i)
		if ((newArray[i]) && (newArray[i]->state))
		{
			insert(newArray[i]->key, newArray[i]->value);
			delete(newArray[i]);
		}
}

void HashTable::resize()
{
	unsigned oldBufferSize = bufferSize;
	bufferSize *= 2;
	Node** newArray = new Node * [bufferSize];
	if (!newArray)
		return;
	newArrayCreation(oldBufferSize,newArray);
}

void HashTable::rehash()
{
	Node** newArray = new Node * [bufferSize];
	if (!newArray)
		return;
	newArrayCreation(bufferSize, newArray);
}

HashTable::HashTable()
{
	bufferSize = defaultSize;
	numOfEl = 0;
	sizeAllNonNullPtr = 0;
	array = new Node * [bufferSize];
	unsigned i;
	for (i = 0; i < bufferSize; ++i)
		array[i] = NULL;
}

HashTable::~HashTable()
{
	this->clear();
	delete array;
}

HashTable::HashTable(const HashTable& b)
{
	numOfEl = b.numOfEl;
	bufferSize = b.bufferSize;
	sizeAllNonNullPtr = b.sizeAllNonNullPtr;
	array = new Node * [bufferSize];
	unsigned i;
	for (i = 0; i < bufferSize; ++i)
		array[i] = b.array[i];
}

HashTable::HashTable(HashTable&& b)
{
	numOfEl = b.numOfEl;
	bufferSize = b.bufferSize;
	sizeAllNonNullPtr = b.sizeAllNonNullPtr;
	array = b.array;
	delete(b.array);
}

void HashTable::swap(HashTable& b)
{
	unsigned tnumOfEl = numOfEl, tbufferSize = bufferSize, tsizeAllNonNullPtr = sizeAllNonNullPtr;
	Node** tarray = array;
	numOfEl = b.numOfEl;
	bufferSize = b.bufferSize;
	sizeAllNonNullPtr = b.sizeAllNonNullPtr;
	array = b.array;
	b.numOfEl = tnumOfEl;
	b.bufferSize = tbufferSize;
	b.sizeAllNonNullPtr = tsizeAllNonNullPtr;
	b.array = tarray;
}

void HashTable::clear()
{
	unsigned i;
	for (i = 0; i < bufferSize; i++)
		delete(array[i]);
}

bool HashTable::erase(const studentName& name)
{
	unsigned h1 = hash1(name), h2 = hash2(name), i = 0;
	while ((array[h1]) && (i < bufferSize))
	{
		if ((!array[h1]->key.compare(name)) && (array[h1]->state))
		{
			array[h1]->state = false;
			--numOfEl;
			return true;
		}
		++i;
	}
	return false;
}

bool HashTable::insert(const studentName& name, const Student& value)
{
	if (numOfEl >= rehashSize * bufferSize)
		resize();
	else
		if (sizeAllNonNullPtr >= 2 * numOfEl)
			rehash();
	unsigned i = 0, h1 = hash1(name), h2 = hash2(name), firstDeleted = -1;
	while ((array[h1]) && (i < bufferSize))
	{
		if ((!array[h1]->key.compare(name)) && (array[h1]->state))
			return false;
		if ((!array[h1]->state) && (firstDeleted == -1))
		{
			firstDeleted = h1;
			break;
		}
		h1 = (h1 + h2) & bufferSize;
		++i;
	}
	if (firstDeleted != -1)
	{
		array[h1]->key = name;
		array[h1]->value = value;
		array[h1]->state = true;
	}
	else
	{
		array[h1] = new Node;
		array[h1]->key = name;
		array[h1]->value = value;
		array[h1]->state = true;
		++sizeAllNonNullPtr;
	}
	++numOfEl;
	return true;
}

bool HashTable::contains(const studentName& name)
{
	unsigned h1 = hash1(name), h2 = hash2(name), i = 0;
	while ((array[h1]) && (i < bufferSize))
	{
		if ((!array[h1]->key.compare(name)) && (array[h1]->state))
			return true;
		h1 = (h1 + h2) % bufferSize;
		++i;
	}
	return false;
}

size_t HashTable::size() const
{
	return sizeAllNonNullPtr * sizeof(Node*);
}

bool HashTable::empty() const
{
	if (this->size())
		return 1;
	return 0;
}