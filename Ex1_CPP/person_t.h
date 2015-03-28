#pragma once
#include <string>

using namespace std;

class Person_t {
public:
	Person_t();										//CTOR
	~Person_t();									//DTOR
	Person_t(string& name, int age);				//Another CTOR
	Person_t(const Person_t& pr);					//Copy CTOR
	Person_t& operator=(const Person_t& pr);		//Operator =
	bool operator==(const Person_t& pr);			//Operator ==

	//Setters and Getters

	void setName(string& name){
		m_name = name;
	};

	string getName() const {
		return m_name;
	};

	void setAge(int age) {
		m_age = age;
	};

	int getAge() const {
		return m_age;
	};

private:
	const size_t 		m_id;		// Unique for each Person_t object
	string				m_name;		// use C++ class 'string', see #include <string>
	int					m_age;
	static size_t		m_globID;	// used to calculate m_id 
};