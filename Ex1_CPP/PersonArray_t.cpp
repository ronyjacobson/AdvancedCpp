#include "PersonArray_t.h"
#include "Person_t.h"


PersonArray_t::PersonArray_t()
{
	array = new Person_t*[growth_size];
	m_size = 0;
	m_capacity = growth_size;
}


PersonArray_t::PersonArray_t(int minimal_number_of_elements)
{
	//TODO
}

PersonArray_t::PersonArray_t(const PersonArray_t& pr)					// Copy CTOR
{
	//TODO
}


PersonArray_t::~PersonArray_t()
{
	//TODO
}

const PersonArray_t& PersonArray_t::operator=(const PersonArray_t& pr)			//operator =
{
	// TODO
	return NULL;
}

void PersonArray_t::insert(Person_t& person){
	// Chcek if capacity needs to grow
	if (getSize() >= getCapacity()){
		incCapacity();
	}
	// Insert
	*(array + getSize()) = &person;
	incSize();
};

Person_t& PersonArray_t::getFirst() const{
	return *array[0];
};

Person_t& PersonArray_t::getLast() const{
	return *array[getSize() - 1];
};

Person_t* PersonArray_t::find(string name) const{
	for (int i = 0; i < getSize(); i++){
		if ((*array[i]).getName() == name){
			return array[i];
		}
	}
	return NULL;
};

void PersonArray_t::remove(string name) {
	for (int i = 0; i < getSize(); i++){
		if ((*array[i]).getName() == name){
			// Remove value
			array[i] = NULL;
			// Reorder remainig values
			if (getSize() != 1 && i != getSize() - 1){
				for (int j = i; j < getSize(); j++){
					if (j == getSize() - 1){
						array[j] = NULL;
					} else {
						array[j] = array[j + 1];
					}
				}
			}
			// Update Size
			m_size--;
			break;
		}
	}
};

void PersonArray_t::removeAll() {
	// Update capacity and size
	m_capacity = growth_size;
	m_size = 0;
	// Create a new array
	Person_t** newArray = new Person_t*[m_capacity];
	// Update to new array
	array = newArray;
};

void PersonArray_t::removeAndDelete(string name) {
	for (int i = 0; i < getSize(); i++){
		if ((*array[i]).getName() == name){
			// Release value
			delete array[i];
			// Copy over values
			memcpy(array[i], array[i + 1], (getSize() - i - 1) * sizeof(Person_t*));
			m_size--;
		}
	}
};

void PersonArray_t::removeAndDeleteAll(string name) {
	for (int i = 0; i < getSize(); i++){
		// Release value
		delete array[i];
	}
	// Update capacity and size
	m_capacity = growth_size;
	m_size = 0;
	// Create a new array
	Person_t** newArray = new Person_t*[m_capacity];
	// Release old array
	delete[] array;
	// Update to new array
	array = newArray;
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
	Person_t** newArray = new Person_t*[newCapacity];
	// Copy all old values
	memcpy(newArray, array, m_capacity * sizeof(Person_t*));
	// Update capacity
	m_capacity = newCapacity;
	// Release old array
	delete[] array;
	// Update to new array
	array = newArray;
};

void PersonArray_t::print() {
	// Print the array
	for (int i = 0; i < getSize(); i++){
		cout << "array[" << i << "]: " ;
		cout << (*array[i]).getName() << endl;
	}
};