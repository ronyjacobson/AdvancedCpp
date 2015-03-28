#pragma once
#include "Person_t.h"
#include <iostream>
using namespace std;

class PersonArray_t
{
public:
	PersonArray_t();										//CTOR
	PersonArray_t(int minimal_number_of_elements);			//Another CTOR
	PersonArray_t(const PersonArray_t& pr);					//Copy CTOR
	~PersonArray_t();										//DTOR
	const PersonArray_t& operator=(const PersonArray_t& pr);//Operator =

	// Functions

	int getSize() const{
		return m_size;
	};
	 
	int getCapacity() const{
		return m_capacity;
	};

	void insert(Person_t& person);

	Person_t& getFirst() const;

	Person_t& getLast() const;

	const Person_t* find(string name) const;

	void remove(string name);

	void removeAll ();

	void removeAndDelete(string name);

	void removeAndDeleteAll(string name);

	void append(int index);
	// TODO
	// Return element if succeeded and 0 otherwise

	void prepend(int index, Person_t& person);
	// TODO
	// Return if succeeds returns 1 if not, return 0;

	void print();

private:
	// Array
	Person_t **array;
	int const growth_size = 16; // Array Growth Size

	// Parameters
	int				m_size;		// Number Of Elements 
	int				m_capacity;	// Capacity
	Person_t		m_first;	// First Element
	Person_t		m_last;		// Last Element

	// Function
	void incSize() {
		m_size++;
	};

	void incCapacity();
};

