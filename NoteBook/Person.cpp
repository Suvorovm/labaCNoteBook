#include "Person.h"

template <typename T>
inline string Person<T>::getName() {
	return name;
}
template <typename T>
inline string Person<T>::getLastName() {
	return lastName;
}
template <typename T>
inline tm Person<T>::getData() {
	return data;
}
template <typename T>
inline T Person<T>::getPhone() {
	return phoneNumber;
}
template <typename T>
inline Person<T>::Person()
{
	this->name = "no name";
	this->lastName = "no last Name";
	
	this->data.tm_year = 1900;
	this->data.tm_mday = 1;
	this->data.tm_mon = 1;

}
template <typename T>
Person<T>::Person(string name, string lastName, T phone, tm data) {
	this->name = name;
	this->lastName = lastName;
	this->phoneNumber = phone;
	this->data = data;
	
}
template <typename T>
inline Person<T>::Person(string name, string lastName) :Person()
{
	this->name = name;
	this->lastName = lastName;

}
template <typename T>
inline Person<T>::Person(string name) : Person(name, "no last Name") {

}
template <typename T>
Person<T>::Person(const Person<T> &person) : Person(person.name, person.lastName, person.phoneNumber, person.data) {
	tp = person.tp;
}
template <typename T>
std::ostream& operator << (std::ostream &os, const Person<T> &p)
{
	//auto s = to_string(p.phoneNumber);
   os << p.name << " " << p.lastName << " " << p.data.tm_year << "/" << p.data.tm_mon << "/" << p.data.tm_mday << "   Номер =  "<<p.phoneNumber;
	return os;
}
template <typename T>
inline std::string Person<T>::getTheStatus()
{
	return "Don't have the status";
}
template <typename T>
inline TypePerson Person<T>::getThePoint()
{
	return tp;
}
template <typename T>
inline  bool operator  == (Person<T> &left, Person<T> &right) {
	if (
		left.getData().tm_mday == right.getData().tm_mday
		&& left.getData().tm_year == right.getData().tm_year
		&& left.getData().tm_mon == right.getData().tm_mon
		&& left.getLastName() == right.getLastName()
		&& left.getPhone() == right.getPhone()
		&& left.getName() == right.getName()
		)
	{

		return true;
	}
	else
	{
		return false;
	}
}

#include "pch.h"