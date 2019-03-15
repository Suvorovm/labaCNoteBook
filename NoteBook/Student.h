#pragma once
#include "Person.h"
#include <iostream>
#include "IStatus.h"
using namespace std;
template <typename T>
class Student:public Person<T>
{
private:
	string group;
public:
	Student();
	~Student();
	Student(string firstName, string LastName, tm data, string group, T phoneNumber);
	Student(string firstName, string LastName,T phoneNumber, string group);
	Student(const Student &stud);
	string getGroup();
	template <typename T>
	friend ostream& operator << (std::ostream &os, const Student<T> &p);
	template <typename T>
	friend bool operator == (Student<T> &left, Student<T> &right);
	TypePerson getThePoint() override;
	// Унаследовано через Person
   string getTheStatus();
};
#include "Student.cpp"
