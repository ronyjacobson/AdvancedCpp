#pragma once
#include <string>

using namespace std;

class Person_t {
public:
	Person_t(); //CTOR
	//~Person_t();
	Person_t(string& name, int age);
	Person_t(const Person_t& pr); //copy CTOR
	const Person_t& operator=(const Person_t& pr); //operator =
	bool operator==(const Person_t& pr); //operator ==

	//Setters and getters

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

