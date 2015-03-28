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
	 
	int getCapacity() const{
		return m_capacity;
	};

	void insert(Person_t* person);

	Person_t& getFirst() const;

	Person_t& getLast() const;

	Person_t* find(Person_t person) const;

	void remove(string name);

	void removeAll ();

	void removeAndDelete(string name);

	void removeAndDeleteAll();

	int append(int i, Person_t& person);

	int prepend(int i, Person_t& person);

	int PersonArray_t::insertToIndex(int i, Person_t& person);

	void print();

private:
	// Array
	Person_t **array;
	int const growth_size = 16; // Array Growth Size

	// Parameters
	int				m_size;		// Number Of Elements 
	int				m_capacity;	// Capacity

	const PersonArray_t& operator=(const PersonArray_t& pr);	//Operator =
	bool operator==(const PersonArray_t& pr);					//Operator ==
	PersonArray_t(const PersonArray_t& pr);						//Copy CTOR

	// Function
	void incSize() {
		m_size++;
	};

	void incCapacity();
};

