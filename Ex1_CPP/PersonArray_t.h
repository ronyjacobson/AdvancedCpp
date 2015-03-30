#pragma once
#include "Person_t.h"
#include <iostream>
using namespace std;

class PersonArray_t
{
public:
	PersonArray_t();										//CTOR
	PersonArray_t(int minimal_number_of_elements);			//Another CTOR
	~PersonArray_t();										//DTOR
	

	// Functions

	int getSize() const{
		return m_size;
	};

	int isEmpty() const{
		return (m_size==0);
	};
	 
	int getCapacity() const{
		return m_capacity;
	};

	int getExpandValue() const{
		return m_growthSize;
	};

	void insert(Person_t* const person);

	Person_t& getFirst() const;

	Person_t& getLast() const;

	const Person_t* find(const Person_t& person) const;

	Person_t* remove(const Person_t& person);

	void removeAll();

	int removeAndDelete(const Person_t& person);

	void removeAndDeleteAll();

	int append(int i, Person_t* const person);

	int prepend(int i, Person_t* const person);

	void print() const;
	

private:
	// Array
	Person_t **array;

	int const m_growthSize = 16; // Array Growth Size

	// Parameters
	int				m_size;		// Number Of Elements 
	int				m_capacity;	// Capacity

	const PersonArray_t& operator=(const PersonArray_t& pr);	//Operator =
	bool operator==(const PersonArray_t& pr) const;				//Operator ==
	PersonArray_t(const PersonArray_t& pr);						//Copy CTOR

	// Function
	void incSize() {
		m_size++;
	};

	void incCapacity();

	int PersonArray_t::insertToIndex(int i, Person_t* const person);
};

