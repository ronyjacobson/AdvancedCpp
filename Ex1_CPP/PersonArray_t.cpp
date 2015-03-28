#include "PersonArray_t.h"
#include "Person_t.h"


PersonArray_t::PersonArray_t()
{
}


PersonArray_t::~PersonArray_t()
{
}

void PersonArray_t::insert(Person_t& person){
	// Chcek if capacity needs to grow
	if (getSize() >= getCapacity()){
		incCapacity();
	}
	// Insert
	*(array + getSize()) = person;
	incSize();
};

Person_t& PersonArray_t::getFirst() const{
	return array[0];
};

Person_t& PersonArray_t::getLast() const{
	return array[getSize() - 1];
};

Person_t& PersonArray_t::find(string name) const{
	for (int i = 0; i < getSize(); i++){
		if (array[i].getName == name){
			return array[i];
		}
	}
};

void PersonArray_t::remove(string name) {
	// TODO
};

void PersonArray_t::removeAll() {
	// TODO
};

void PersonArray_t::removeAndDelete(string name) {
	// TODO
};

void PersonArray_t::removeAndDeleteAll(string name) {
	// TODO
};

void PersonArray_t::append(int index) {
	// TODO
	// Return element if succeeded and 0 otherwise
};

void PersonArray_t::prepend(int index, Person_t& person) {
	// TODO
	// Return if succeeds returns 1 if not, return 0;
};

void PersonArray_t::incCapacity() {
	// Caclculate new capacity
	int newCapacity = m_capacity + growth_size;
	// Create a new bigger array
	Person_t* newArray = new Person_t[newCapacity];
	// Copy all old values
	memcpy(newArray, array, m_capacity * sizeof(Person_t));
	// Update capacity
	m_capacity = newCapacity;
	// Release old array
	delete[] array;
	// Update to new array
	array = newArray;
};