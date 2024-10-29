#pragma once

#include <iostream>
#include <memory>
#include <string>

class Person {
	std::string m_name;
	int m_age;
	std::weak_ptr<Person> m_brother;

public:
	Person(const std::string& name, int age)
		: m_name(name)
		, m_age(age)
	{}
	~Person() {
		std::cout << "dtor von " << m_name << std::endl;
	}

	int getAge() const;
	std::string getName() const;
	void setAge(int age);
	void setName(const std::string& name);
	void setBrother(const std::shared_ptr<Person>& brother) { 
		m_brother = brother; 
	}

	friend std::ostream& operator<<(std::ostream& os, const Person& p);
};