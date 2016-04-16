#pragma once

#include <vector>

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
	const unsigned int AddItem(T newObj);

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
	T GetItem(unsigned int objIndex) const;

	/*
	Returns all of the objects in the slot map
	@return the vector of arrays that the objects are stored in, 
		the vector can only be read from
	*/
	const vector<T*>& GetAll() const;

private:
	// vector of all the chunks of memory that have been created
	vector<T*> chunks;

	// vector of all the free locations in memory, effectively a stack
	vector<unsigned int> freePositions;
};

