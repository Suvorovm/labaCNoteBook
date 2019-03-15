#pragma once
#include "Person.h"
#include <iostream>
#include <string>
using namespace std;
template <typename T>
class Teacher:public Person<T>
{
	string facultyOfTeaching;
public:
	Teacher();
	Teacher(const Teacher& source);
	Teacher(string name, string lastName, T phoneNumber, tm data, string faculty);
	//~Teacher();
	template <typename T>
	friend bool operator !=(Teacher &left, Teacher &right);
	template <typename T>
	friend ostream& operator <<  (ostream &os, const Teacher<T> &teacher);
	// Унаследовано через Person
	string getTheStatus() override;
	TypePerson getThePoint() override;
};
#include"Teacher.cpp"

