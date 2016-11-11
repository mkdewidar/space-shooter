#pragma once

#include <vector>
#include "../GameObject.h"

using std::vector;

/*
Data structure that expands on vectors to deal with the 
problem of vector indecies expiring when objects are 
deleted or added to the vector
*/
template <class T>
class SlotMap
{
public:
	SlotMap(int size = 5);
	~SlotMap();

	const int chunkSize = 5;

	/*
	Adds the item provided to the slot map and returns it's
		id in the structure
	@param newObj the new object that is to be added to the 
		data structure
	@return the id of the newly added object in the data structure
	*/
	unsigned int AddItem(T newObj);

	/*
	Removes the item with the index provided from the structure
	@param objIndex the index of the object to be removed
	*/
	void RemoveItem(unsigned int objIndex);

	/*
	Returns the item that had the index provided
	@param objId the index of the item to be returned
	@return the item that was identified in the data structure
		using the index provided
	*/
	T operator[](unsigned int objIndex) const;

	/*
	Returns all of the objects in the slot map
	@return the vector of arrays that the objects are stored in, 
		the vector can only be read from
	*/
	const vector<T*>& GetAll() const;

	/*
	Returns the capacity of the slot map
	@return returns the size of the slot map in memory
	*/
	size_t Capacity() const;

	/*
	Returns the size of the slot map
	@return returns the number of elements in the slot map
	*/
	size_t Size() const;

private:
	// vector of all the chunks of memory that have been created
	vector<T*> chunks;

	// vector of all the free locations in memory, effectively a stack
	vector<unsigned int> freePositions;
};

template<class T>
SlotMap<T>::SlotMap(int size = 5)
	: chunkSize(size)
{
	this->chunks.push_back(new T[this->chunkSize]());
	// since the vector of free positions acts like a stack
	// the numbers are inserted backwards to start from the top
	// of the chunk (from 0) to the max chunk size
	// unlike other loops must be int since I'm checking when it 
	// goes less than 0, if unsigned int (size_t) will wrap around
	int index = (int)this->Capacity() - 1;
	for (; index > (int)(this->Capacity() - 1 - this->chunkSize); index--)
	{
		this->freePositions.push_back(index);
	}
}

template<class T>
SlotMap<T>::~SlotMap()
{
	for (size_t chunkIndex = 0; chunkIndex < this->chunks.size(); chunkIndex++)
	{
		delete[] this->chunks[chunkIndex];
	}
}

template<class T>
unsigned int SlotMap<T>::AddItem(T newObj)
{
	// if there is no more space a new chunk is allocated,
	// the free space is noted
	// either way the object is assigned to the position on
	// the top of the free list stack

	if (this->freePositions.empty())
	{
		this->chunks.push_back(new T[this->chunkSize]);
		// since the vector of free positions acts like a stack
		// the numbers are inserted backwards to start from the top
		// of the chunk (from 0) to the max chunk size
		size_t index = this->Capacity() - 1;
		for (; index >= (this->Capacity() - this->Size()); index--)
		{
			this->freePositions.push_back(index);
			this->chunks[(index / this->chunkSize)][(index % this->chunkSize)] = nullptr;
		}
	}

	int newObjIndex = this->freePositions.back();
	this->freePositions.pop_back();

	this->chunks[(newObjIndex / this->chunkSize)][(newObjIndex % this->chunkSize)] = newObj;

	return newObjIndex;
}

template<class T>
void SlotMap<T>::RemoveItem(unsigned int objIndex)
{
	// TODO: split index into version and id to actually make the index unique
	// and unusable after removal from the structure
	this->freePositions.push_back(objIndex);
	this->chunks[(objIndex / this->chunkSize)][(objIndex % this->chunkSize)] = NULL;
}

template<class T>
T SlotMap<T>::operator[](unsigned int objIndex) const
{
	return this->chunks[(objIndex / this->chunkSize)][(objIndex % this->chunkSize)];
}

template<class T>
const vector<T*>& SlotMap<T>::GetAll() const
{
	return this->chunks;
}

template<class T>
size_t SlotMap<T>::Capacity() const
{
	return this->chunks.size() * this->chunkSize;
}

template<class T>
size_t SlotMap<T>::Size() const
{
	return this->Capacity() - this->freePositions.size();
}
