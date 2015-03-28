#include "PersonArray_t.h"
#include "Person_t.h"


PersonArray_t::PersonArray_t()
{
	// Initialize
	array = new Person_t*[growth_size];
	m_size = 0;
	m_capacity = growth_size;
}


PersonArray_t::PersonArray_t(int minimal_number_of_elements)					// CTOR from integer (initial minimal number of elements)
{
	// Initialize
	array = new Person_t*[growth_size];
	m_size = 0;
	m_capacity = growth_size;
	// Insert new people
	for (int i = 0; i < minimal_number_of_elements; i++){
		Person_t* person = new Person_t();
		insert(person);
	}
}

PersonArray_t::PersonArray_t(const PersonArray_t& pr)							// Copy CTOR
{
	array = pr.array;
	m_size = pr.m_size;
	m_capacity = pr.m_capacity;
}


PersonArray_t::~PersonArray_t()
{
	removeAndDeleteAll();
}

const PersonArray_t& PersonArray_t::operator=(const PersonArray_t& pr)			// Operator =
{
	array = pr.array;
	m_size = pr.m_size;
	m_capacity = pr.m_capacity;
	return *this;
}

bool PersonArray_t::operator==(const PersonArray_t& pr)							// Operator ==
{
	if (getSize() != pr.getSize() || getCapacity() != pr.getCapacity()){
		return false;
	}
	for (int i = 0; i < getSize(); i++){
		if (!((*array[i]) == (*pr.array[i]))){
			return false;
		}
	}
	return true;
}

void PersonArray_t::insert(Person_t* person){
	insertToIndex(getSize(), *person);
};

Person_t& PersonArray_t::getFirst() const{
	return *array[0];
};

Person_t& PersonArray_t::getLast() const{
	return *array[getSize() - 1];
};

Person_t* PersonArray_t::find(Person_t person) const{
	for (int i = 0; i < getSize(); i++){
		if ((*array[i]) == person){
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
			// Remove value
			delete array[i];
			array[i] = NULL;
			// Reorder remainig values
			if (getSize() != 1 && i != getSize() - 1){
				for (int j = i; j < getSize(); j++){
					if (j == getSize() - 1){
						array[j] = NULL;
					}
					else {
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

void PersonArray_t::removeAndDeleteAll() {
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

//append a new element after specific index in array	
int PersonArray_t::append(int i, Person_t& person) {
	return insertToIndex(i + 1, person);
};

//prepend a new element before specific index in array
int PersonArray_t::prepend(int i, Person_t& person) {
	return insertToIndex( i , person);

};

int PersonArray_t::insertToIndex(int i, Person_t& person) {
	//Check if index is out of bounds
	if ( (i > getSize()) || (i < 0) ) {
		cout << "Error: Index out of bounds!" << endl;
		return 0;
	}

	// Chcek if capacity needs to grow
	if (getSize() >= getCapacity()){
		incCapacity();
	}

	if (i != getSize()) {
		// Shift elements from index i
		memcpy(array+(i+1),
			array+i,
			(getSize() - i) * sizeof(Person_t*));
	}

	// Insert element
	*(array + i) = &person;
	incSize();
	return 1;
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