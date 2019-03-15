#include "Student.h"

template <typename T>
Student<T>::Student():Person<T>()
{
	this->group = "not group";
	this->tp = StudentT;
}
template <typename T>
Student<T>::Student(const Student<T> &stud):Student(stud.name,stud.lastName,stud.data,stud.group,stud.phoneNumber){
	this->tp = StudentT;
}
template <typename T>
Student<T>::Student(string firstName, string LastName, tm data, string group, T phoneNumber){
	this->group = group;
	this->name = firstName;
	this->lastName = LastName;
	this->data = data;
	this->phoneNumber = phoneNumber;
	this->tp = StudentT;
}
template <typename T>
Student<T>::Student(string firstName, string lastName, T phoneNumber, string group)  {
	this->group=group;
	this->phoneNumber = phoneNumber;
	this->name = firstName;
	this->lastName = lastName;
	this->group = group;
	this->tp = StudentT;
}
template <typename T>
string Student<T>::getGroup()
{
	return group;
}
template <typename T>
Student<T>::~Student()
{
}
template <typename T>
TypePerson Student<T>::getThePoint()
{
	return this->tp;
}
template <typename T>
string Student<T>::getTheStatus()
{
	return group;
}
template <typename T>
std::ostream& operator << (ostream &os, const Student<T> &p)
{
	    os << p.name << " "
		<< p.lastName << " "
		<< p.data.tm_year << "/"
		<< p.data.tm_mon << "/"
		<< p.data.tm_mday <<
		"   Номер =  "
		<< p.phoneNumber
		<<"  Group = "<<  p.group;
	return os;
}
template <typename T>
bool operator == (Student<T> &left, Student<T> &right) {
	if (
		left.getData().tm_mday == right.getData().tm_mday
		&& left.getData().tm_year == right.getData().tm_year
		&& left.getData().tm_mon == right.getData().tm_mon
		&& left.getLastName() == right.getLastName()
		&& left.getPhone() == right.getPhone()
		&& left.getName() == right.getName()
		&& left.getGroup()==right.getGroup()
		)
	{

		return true;
	}
	else
	{
		return false;
	}
}
template <typename T>
bool operator != (Student<T> &left, Student<T> &right) {
	return !(left == right);
}
#include "pch.h"