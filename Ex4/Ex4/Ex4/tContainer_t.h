#ifndef TCONTAINER_T
#define TCONTAINER_T

#include <algorithm>
#include<iostream>
#include <list>
#include <vector>

using namespace std;

#ifdef TEMPLATE_TEMPLATE_MODE

	#define template_decleration  template<typename T, template <typename, typename> class CT> 
	template <typename T, template <typename, typename> class CT> class tContainer_t

#else

	#define template_decleration  template <typename T, typename CT> 
	template <typename T, typename CT > class tContainer_t

#endif

{
	// << Operator
	template_decleration friend ostream& operator<<(ostream& os, const tContainer_t<T, CT> & cont);

public:

	// Default CTOR
	tContainer_t();

	// Defualt DTOR
	virtual ~tContainer_t();

	// Return true/false according to is array empty or not
	inline bool isEmpty() const;

	// Return number of elements in array
	inline size_t numberOfElements() const;

	// Insert a new element in the end of array
	inline void insert(T * element);

	// Return first element in container
	inline T* first() const;

	// Return last element in container
	inline T* last() const;

	// Find specific element by value
	T* find(const T & element) const;

	// Remove specific element and returns pointer to it
	T* remove(const T & element);

	// Remove all elements
	void removeAll();

	// Remove and delete specific element 
	void removeAndDelete(const T& element);

	// Remove and delete all elements
	void removeAndDeleteAll();

	// [] Operator
	T* & operator[] (size_t index);
	T* operator[] (size_t index) const;

private:

	// Copy CTOR
	tContainer_t<T, CT>(const tContainer_t<T, CT>& container);

	// = Operator
	tContainer_t<T, CT>&  operator=(const tContainer_t<T, CT>& container);

#ifdef TEMPLATE_TEMPLATE_MODE

	CT<T *, allocator<T *>> m_container;
	typedef typename CT<T*, allocator<T*>>::const_iterator const_iterator_t;
	typedef typename CT<T*, allocator<T*>>::iterator iterator_t;

#else
	CT m_container;
	typedef typename CT::iterator iterator_t;
	typedef typename CT::const_iterator const_iterator_t;

#endif

};

// << Operator
	template_decleration ostream& operator<<(ostream& os, const tContainer_t<T, CT> & container)
{
	tContainer_t<T, CT>::const_iterator_t iterator;
	for (iterator = container.m_container.begin(); iterator != container.m_container.end(); iterator++)
	{
		os << **iterator << endl;
	}
	return os;
}

// Default DTOR
template_decleration tContainer_t<T, CT>:: ~tContainer_t(){
	// Does Nothing
}

// Defalt CTOR
template_decleration tContainer_t<T, CT>::tContainer_t(){
	// Does Nothing
}

// Return true/false according to is array empty or not
template_decleration bool tContainer_t<T, CT>::isEmpty() const
{
	return m_container.empty();
}

// Return number of elements in array
template_decleration size_t tContainer_t<T, CT>::numberOfElements() const
{
	return m_container.size();
}

// Insert a new element in the end of array
template_decleration void tContainer_t<T, CT>::insert(T * element)
{
	m_container.insert(m_container.end(), element);
}

// Return first element in container
template_decleration T* tContainer_t<T, CT>::first() const
{
	if (!isEmpty()) {
		return m_container.front();
	}
	return nullptr;

}

// Return last element in container
template_decleration T* tContainer_t<T, CT>::last() const
{
	if (!isEmpty()) {
		return m_container.back();
	}
	return nullptr;
}

// Find specific element by value
template_decleration T* tContainer_t<T, CT>::find(const T & element) const
{
	// Use STL algorithm “find_if”  with eh compare predicate
	const_iterator_t found = find_if(m_container.begin(), m_container.end(), compare<T>(element));

	if (found == m_container.end()){
		return 0;
	}

	return *found;
}

// Remove specific element and returns pointer to it
template_decleration T* tContainer_t<T, CT>::remove(const T & element)
{
	// Use STL algorithm “find_if”  with eh compare predicate
	const_iterator_t found = find_if(m_container.begin(), m_container.end(), compare<T>(element));

	if (found == m_container.end()){
		return 0;
	}

	T * result = *found;
	m_container.erase(found);
	return result;
}

// Remove all elements
template_decleration void tContainer_t<T, CT>::removeAll()
{
	m_container.clear();
}

// Remove and delete specific element 
template_decleration void tContainer_t<T, CT>::removeAndDelete(const T& element)
{

	T * found = remove(element);

	if (found != 0)
	{
		delete found;
	}

}

// Remove and delete all elements
template_decleration void  tContainer_t<T, CT>::removeAndDeleteAll()
{
	const_iterator_t iterator;
	for (iterator = m_container.begin(); iterator != m_container.end(); iterator++)
	{
		delete (*iterator);
	}
	removeAll();
}


// [] Operator
template_decleration T*&  tContainer_t<T, CT>::operator[] (size_t index)
{
	// Check if using vector or list
	if (typeid(m_container) == typeid(vector<T*>)) {
		// use vector implementation
		return ((vector<T*>)m_container)[index];
	} else if (typeid(m_container) == typeid(list<T*>)) {
		const_iterator_t iterator = m_container.begin();
		advance(iterator, index);
		return *iterator;

	}
}

template_decleration T* tContainer_t<T, CT>::operator[] (size_t index) const
{
	// Check if using vector or list
	if (typeid(m_container) == typeid(vector<T*>)) {
		// use vector implementation
		return ((vector<T*>)m_container)[index];
	} else if (typeid(m_container) == typeid(list<T*>)) {
		const_iterator_t iterator = m_container.begin();
		advance(iterator, index);
		return *iterator;
	}
}


// Compare predicate for the STL algorithm “find_if”
template <class T> struct compare
{
	// CTOR
	compare(T val) : first(val){
		// Assignment in the signature
		// Does nothing in the body
	};

	// Call compare
	bool operator()(T* second) const { 
		return *second == first;
	}

private:
	T first;
};

#endif


