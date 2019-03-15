#pragma once
using namespace std;

#include "pch.h"

#include <string>
#include <iostream>
#include"IStatus.h"
#include "TypePerson.h"

template <typename T>
 class Person:IStatus{
  
protected:
	string name;
	string lastName;
	T phoneNumber;
	tm data;
	TypePerson tp;
public:	
     string getName() ;
	 string getLastName();
	 tm getData();	 
	 T getPhone();
	 Person();
     Person(string name, string lastName, T phone, tm data);
	 Person(string name, string lastName);
	 Person(string name);
    Person(const Person<T> &person);
	template <typename T>
	 friend std::ostream& operator << (std::ostream &os, const Person<T> &p);	
	 // Унаследовано через IStatus
	 virtual std::string getTheStatus() override;
	 virtual TypePerson getThePoint() override;
	 template <typename T>
	 friend bool operator == (Person<T> &left, Person<T> &right);
 };


 #include "Person.cpp"
