
#include "Teacher.h"

template <typename T>
Teacher<T>::Teacher():Person<T>()
{
	this->facultyOfTeaching = "no faculty";
	this->tp = TeacherT;
}

template <typename T>
Teacher<T>::Teacher(const Teacher& source):Teacher(source.name,source.lastName,source.phoneNumber,source.data,source.facultyOfTeaching)
{
	this->tp = TeacherT;	
}
template <typename T>
Teacher<T>::Teacher(string name, string lastName, T phoneNumber, tm data, string faculty)
{
	Teacher();
	this->data = data;
	this->name = name;
	this->lastName = lastName;
	this->phoneNumber = phoneNumber;
	this->facultyOfTeaching = faculty;
	this->tp = TeacherT;
}


template <typename T>
std::ostream& operator << (std::ostream &os, const Teacher<T> &teacher)
{
	os << teacher.name<< " " << teacher.lastName
		<< " " << teacher.data.tm_year
		<< "/" << teacher.data.tm_mon
		<< "/" << teacher.data.tm_mday
		<< "   Номер =  " << teacher.phoneNumber
		<< "  Факультет = " << teacher.facultyOfTeaching;
	return os;
}
template <typename T>
string Teacher<T>::getTheStatus()
{
	return facultyOfTeaching;
}
template <typename T>
TypePerson Teacher<T>::getThePoint()
{
	return this->tp;
}
template <typename T>
bool operator == (Teacher<T> &left, Teacher<T> &right) {
	if (
		left.getData().tm_mday == right.getData().tm_mday
		&& left.getData().tm_year == right.getData().tm_year
		&& left.getData().tm_mon == right.getData().tm_mon
		&& left.getLastName() == right.getLastName()
		&& left.getPhone() == right.getPhone()
		&& left.getName() == right.getName()
		&& left.facultyOfTeaching == right.facultyOfTeaching
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
bool operator !=(Teacher<T> &left, Teacher<T> &right) {
	return !(left == right);
}
#include "pch.h"