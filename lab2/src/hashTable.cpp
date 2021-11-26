#include "hashTable.h"
#include <iostream>

unsigned hashFunctionHorner(const studentName& name, unsigned key, unsigned bufferSize)
{
	unsigned i, hashResult = 0, nameLength = (unsigned)(name.size());
	for (i = 0; i < nameLength; ++i)
		hashResult = (key * hashResult + (unsigned)(name[i])) % bufferSize;
	hashResult = (hashResult * 2 + 1) % bufferSize;
	return hashResult;
}

unsigned hash1(const studentName& name, unsigned bufferSize)
{
	return hashFunctionHorner(name, bufferSize + 1, bufferSize);
}

unsigned hash2(const studentName& name, unsigned bufferSize)
{
	return hashFunctionHorner(name, bufferSize - 1, bufferSize);
}

void HashTable::newArrayCreation(unsigned oldBufferSize, unsigned bufferSize, HashTable::Node** newArray)
{
	numOfEl = 0;
	sizeAllNonNullPtr = 0;
	unsigned i;
	for (i = 0; i < bufferSize; ++i)
		newArray[i] = NULL;
	std::swap(newArray, array);
	for (i = 0; i < oldBufferSize; ++i)
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
	newArrayCreation(oldBufferSize,bufferSize, newArray);
}

void HashTable::rehash()
{
	Node** newArray = new Node * [bufferSize];
	newArrayCreation(bufferSize,bufferSize, newArray);
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
	delete[] array;
}

HashTable::HashTable(const HashTable& b)
{
	numOfEl = b.numOfEl;
	bufferSize = b.bufferSize;
	sizeAllNonNullPtr = b.sizeAllNonNullPtr;
	array = new Node * [bufferSize];
	unsigned i;
	for (i = 0; i < bufferSize; ++i)
	{
		array[i] = new Node;
		array[i] = b.array[i];
	}
}

HashTable::HashTable(HashTable&& b) noexcept
{
	numOfEl = b.numOfEl;
	bufferSize = b.bufferSize;
	sizeAllNonNullPtr = b.sizeAllNonNullPtr;
	array = b.array;
	b.array = NULL;
	b.numOfEl = b.sizeAllNonNullPtr = b.bufferSize = 0;
}

HashTable& HashTable::operator=(const HashTable& b)
{
	if (&b == this)
		return *this;
	numOfEl = b.numOfEl;
	bufferSize = b.bufferSize;
	sizeAllNonNullPtr = b.sizeAllNonNullPtr;
	delete array;
	array = new Node * [bufferSize];
	unsigned i;
	for (i = 0; i < bufferSize; ++i)
	{
		array[i] = new Node;
		array[i] = b.array[i];
	}
	return *this;
}

HashTable& HashTable::operator=(HashTable&& b) noexcept
{
	if (&b == this)
		return *this;
	numOfEl = b.numOfEl;
	bufferSize = b.bufferSize;
	sizeAllNonNullPtr = b.sizeAllNonNullPtr;
	delete array;
	array = b.array;
	b.array = NULL;
	b.numOfEl = b.bufferSize = b.sizeAllNonNullPtr = 0;
	return *this;
}

void HashTable::swap(HashTable& b)
{
	std::swap(numOfEl, b.numOfEl);
	std::swap(bufferSize, b.bufferSize);
	std::swap(sizeAllNonNullPtr, b.sizeAllNonNullPtr);
	std::swap(array, b.array);
}

void HashTable::clear()
{
	unsigned i;
	for (i = 0; i < bufferSize; ++i)
		if (array[i])
			delete(array[i]);
}

bool HashTable::erase(const studentName& name)
{
	unsigned h1 = hash1(name, bufferSize), h2 = hash2(name, bufferSize), i = 0;
	while ((array[h1]) && (i < bufferSize))
	{
		if ((!array[h1]->key.compare(name)) && (array[h1]->state))
		{
			array[h1]->state = false;
			--numOfEl;
			return true;
		}
		h1 = (h1 + h2) % bufferSize;
		++i;
	}
	return false;
}

bool HashTable::insert(const studentName& name, const Student& value)
{
	if (numOfEl >= rehashSize * bufferSize)
		resize();
	else
		if ((sizeAllNonNullPtr >= 2 * numOfEl) && (numOfEl))
			rehash();
	unsigned i = 0, h1 = hash1(name, bufferSize), h2 = hash2(name, bufferSize);
	bool firstDeleted = false;
	while ((array[h1]) && (i < bufferSize))
	{
		if ((!array[h1]->key.compare(name)) && (array[h1]->state))
			return false;
		if ((!array[h1]->state) && (!firstDeleted))
		{
			firstDeleted = true;
			break;
		}
		h1 = (h1 + h2) % bufferSize;
		++i;
	}
	if (firstDeleted)
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

bool HashTable::contains(const studentName& name) const
{
	unsigned h1 = hash1(name, bufferSize), h2 = hash2(name, bufferSize), i = 0;
	while ((array[h1]) && (i < bufferSize))
	{
		if ((!array[h1]->key.compare(name)) && (array[h1]->state))
			return true;
		h1 = (h1 + h2) % bufferSize;
		++i;
	}
	return false;
}

Student& HashTable::operator[](const studentName& name)
{
	unsigned h1 = hash1(name, bufferSize), h2 = hash2(name, bufferSize), i = 0;
	while ((array[h1]) && (i < bufferSize))
	{
		if ((!array[h1]->key.compare(name)) && (array[h1]->state))
			return array[h1]->value;
		h1 = (h1 + h2) % bufferSize;
		++i;
	}
	Student value;
	insert(name, value);
	return (*this)[name];
}

Student& HashTable::at(const studentName& name)
{
	return const_cast<Student&>(cat(name));
}

const Student& HashTable::cat(const studentName& name) const
{
	unsigned h1 = hash1(name, bufferSize), h2 = hash2(name, bufferSize), i = 0;
	while ((array[h1]) && (i < bufferSize))
	{
		if ((!array[h1]->key.compare(name)) && (array[h1]->state))
			return array[h1]->value;
		h1 = (h1 + h2) % bufferSize;
		++i;
	}
	throw std::exception("couldn't find student with given name");
}

size_t HashTable::size() const
{
	return numOfEl;
}

bool HashTable::empty() const
{
	if (!this->size())
		return true;
	return false;
}

bool operator==(const HashTable& a, const HashTable& b)
{
	return !(a != b);
}

bool operator!=(const HashTable& a, const HashTable& b)
{
	if (&a == &b)
		return false;
	if ((a.numOfEl != b.numOfEl) || (a.sizeAllNonNullPtr != b.sizeAllNonNullPtr))
		return true;
	unsigned i;
	for (i = 0; i < a.bufferSize; ++i)
	{
		if ((a.array[i] && !b.array[i]) || (!a.array[i] && b.array[i]))
			return true;
		if (!a.array[i])
			continue;
		if (a.array[i]->key.compare(b.array[i]->key))
			return true;
		if (a.array[i]->value.weight != b.array[i]->value.weight)
			return true;
		if (a.array[i]->value.age != b.array[i]->value.age)
			return true;
		if (a.array[i]->state != b.array[i]->state)
			return true;
	}
	return false;
}
