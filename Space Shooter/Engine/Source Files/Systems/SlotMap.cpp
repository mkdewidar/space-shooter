#include "../../Header Files/Systems/SlotMap.h"



template<class T>
SlotMap<T>::SlotMap(int size = 5)
	: chunkSize(size)
{
	this->chunks.push_back(new T[this->chunkSize]);
	// since the vector of free positions acts like a stack
	// the numbers are inserted backwards to start from the top
	// of the chunk (from 0) to the max chunk size
	for (size_t index = this->chunkSize; index >= 0; index--)
	{
		this->freePositions.push_back(index);
	}
}

template<class T>
SlotMap<T>::~SlotMap()
{
	for (T* singleChunk : this->chunks)
	{
		delete[] singleChunk;
	}
}

template<class T>
const unsigned int SlotMap<T>::AddItem(T newObj)
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
		for (size_t index = this->chunkSize; index >= 0; index--)
		{
			this->freePositions.push_back(index);
		}
	}

	newObjIndex = this->freePositions.back();
	this->freePositions.pop_back();

	this->chunks[(newObjIndex / this->chunkSize)][(newObjIndex % this->chunkSize)] = T;

	return newObjIndex;
}

template<class T>
void SlotMap<T>::RemoveItem(unsigned int objIndex)
{
	// TODO: split index into version and id to actually make the index unique
	// and unusable after removal from the structure
	this->freePositions.push_back(objIndex);
}

template<class T>
T SlotMap<T>::GetItem(unsigned int objIndex) const
{
	return this->chunks[ (objIndex / this->chunkSize) ][ (objIndex % this->chunkSize) ];
}

template<class T>
const vector<T*>& SlotMap<T>::GetAll() const
{
	return this->chunks;
}
