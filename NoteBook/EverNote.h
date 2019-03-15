#pragma once
#include "pch.h"
#include <vector>
#include "Student.h"
#include "Teacher.h"
#include "TypePerson.h"
using namespace std;
template <typename T>
 class EverNote {
private:
	vector<Student<T>> students;
	vector<Teacher<T>> teachers;
	int compareStrings(string first, string second);
	
public:
	EverNote();
	EverNote(EverNote<T> &helpNote);
	EverNote(Teacher<T> teacher, Student<T> student);
//	EverNote(Person person);
	bool IsEmpty();
	void SortByNameStudents();
	vector<Person<T>> FindPersonByLastname(std::string lastName);
	vector<Person<T>> FindPersonByName(std::string name);
	void SortByNameTeachers();
	void AddTeacher(const Teacher<T> teacher);
	void AddStudent(const Student<T> student);
	///
	///при отсутсвии такого человека return -1
	// ѕри нахождении 0
	int DeletePerson(string name, string lastnName, T phoneNumber, TypePerson personType);
	//void AddPerson(Person person);
	vector <Teacher<T>> getTeacherVector();
	vector <Student<T>> getStudentsVector();
	
};

#include "EverNote.cpp""