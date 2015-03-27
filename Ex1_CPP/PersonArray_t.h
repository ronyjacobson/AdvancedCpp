#pragma once
#include "Person_t.h"

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
		// TODO
	};

	int getCapacity() const{
		// TODO
	};

	void insert(Person_t& person){
		// TODO
	};

	Person_t& getFirst() const{
		// TODO
	};

	Person_t& getLast() const{
		// TODO
	};

	Person_t& find(string name) const{
		// TODO
	};

	void remove(string name) {
		// TODO
	};

	void removeAll () {
		// TODO
	};

	void removeAndDelete(string name) {
		// TODO
	};

	void removeAndDeleteAll(string name) {
		// TODO
	};

	void append(int index) {
		// TODO
		// Return element if succeeded and 0 otherwise
	};

	void prepend(int index, Person_t& person) {
		// TODO
		// Return if succeeds returns 1 if not, return 0;
	};

private:
	int				m_size;		// Number Of Elements 
	int				m_capacity;	// Capacity
	Person_t		m_first;	// First Element
	Person_t		m_last;		// Last Element
};

