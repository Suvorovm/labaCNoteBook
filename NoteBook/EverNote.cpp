#include "EverNote.h"

	
	//перва€ строка меньше второй - то -1
	// если втора€ строка меньше первой 1
	//если равны = 0
template <typename T>
	int EverNote<T>::compareStrings(string first, string second) {
		int r = 0;
		for (size_t i = 0; i < first.size() && r == 0; ++i)
			r = tolower(first[i]) - tolower(second[i]);

		if (r < 0) {
			return -1;
		}
		else {
			if (r > 0) {
				return 1;
			}
			else {
				return 0;
			}
		}
	}
	template <typename T>
	bool EverNote<T>::IsEmpty() {
		
		return teachers.size()==students.size()==0;
	}
	template <typename T>
	void EverNote<T>::SortByNameStudents()
	{
		int i, j, step;
		Student<T> tmp;
		int n = students.size();
		for (step = n / 2; step > 0; step /= 2)
			for (i = step; i < n; i++)
			{
				tmp = students[i];
				for (j = i; j >= step; j -= step)
				{
					if (compareStrings(tmp.getName(), students[j - step].getName()) == -1)
						students[j] = students[j - step];
					else
						break;
				}
				students[j] = tmp;
			}
	}

	//¬озвращает 1 - если удалено и из students и из teAachers
	//return 0 - удален
	// return -1 никто не удален
	template <typename T>
	int EverNote<T>::DeletePerson(string name, string lastnName, T phoneNumber,TypePerson personType)
	{
		//auto iterator = persons.cbegin();
		switch (personType)
		{
		case TeacherT: {
			auto iterator = teachers.cbegin();
			for (size_t i = 0; i < teachers.size(); i++)
			{
				if (teachers[i].getName() == name && teachers[i].getLastName() == lastnName && teachers[i].getPhone() == phoneNumber) {
					teachers.erase(iterator + i);
					return 0;
				}
			}
			return -1;
		}
			break;
		case StudentT: {
			auto iteratorS = students.cbegin();
			for (size_t i = 0; i < students.size(); i++)
			{
				if (students[i].getName() == name && students[i].getLastName() == lastnName && students[i].getPhone() == phoneNumber) {
					students.erase(iteratorS + i);
					return 0;
				}
			}
			return -1;
		}
			break;
		case UnIndeficated: {
			int fTeach = DeletePerson(name, lastnName, phoneNumber, TeacherT);
			int fStud =  DeletePerson(name, lastnName, phoneNumber, StudentT);
			if (fTeach != -1 || fStud != -1) {
				return -1;
			}
			else {
				return 1;
			}
		}
			break;
		
		}
		
	}
	template <typename T>
	vector<Teacher<T>> EverNote<T>::getTeacherVector()
	{
		return teachers;
	}
	template <typename T>
	vector<Student<T>> EverNote<T>::getStudentsVector()
	{
		return students;
	}
	
	//<summary>возвращает вектор объектов с заданным именем< / summary>
	template <typename T>
	vector<Person<T>> EverNote<T>::FindPersonByName(string name) {
		vector<Person<T>> personst;
		for (size_t i = 0; i < students.size(); i++)
		{
			if (name == students[i].getName()) {
				Student<T> temrory(students[i]);
				personst.push_back(temrory);
			}			
		}
		for (size_t i = 0; i < teachers.size(); i++)
		{
			if (name == teachers[i].getName()) {
				Teacher<T> temrory(teachers[i]);				
				personst.push_back(temrory);
			}
		}		
			return personst;	
		
	}
	
	template<typename T>
	void EverNote<T>::SortStudents(T(*predicate)(Student<T>))//можно отрифакторить, если вспомнить		
	{
int i, j, step;
		Student<T> tmp;
		int n = students.size();
		if (n = 0) {
			throw runtime_error("invalibal size");
		}
	
		for (step = n / 2; step > 0; step /= 2)
			for (i = step; i < n; i++)
			{
				tmp = students[i];
				for (j = i; j >= step; j -= step)
				{
					
					if (compareStrings (predicate(tmp), predicate(students[j - step]))==-1)
						students[j] = students[j - step];
					else
						break;
				}
				students[j] = tmp;
			}
	}

	template<typename T>
	void EverNote<T>::SortTeachers(T(*predicate)(Teacher<T>))
	{
		int i, j, step;
		Teacher<T> tmp;
		int n = teachers.size();
		for (step = n / 2; step > 0; step /= 2)
			for (i = step; i < n; i++)
			{
				tmp = teachers[i];
				for (j = i; j >= step; j -= step)
				{
					if (compareStrings(predicate(tmp), predicate(teachers[j - step])) == -1)
						teachers[j] = teachers[j - step];
					else
						break;
				}
				teachers[j] = tmp;
			}
	}

	//<summary>возвращает вектор объектов с заданной фамилией< / summary>
	template <typename T>
	vector<Person<T>> EverNote<T>::FindPersonByLastname(string lastName) {
		vector<Person<string>> personst;
		for (size_t i = 0; i < students.size(); i++)
		{
			if (lastName == students[i].getName()) {
				Student temrory(students[i]);
				personst.push_back(temrory);
			}
		}
		for (size_t i = 0; i < students.size(); i++)
		{
			if (lastName == students[i].getName()) {
				Student temrory(students[i]);
				personst.push_back(temrory);
			}
		}		
			return personst;
	}		
	template <typename T>
	void EverNote<T>::SortByNameTeachers()
	{
		int i, j, step;
		Teacher<T> tmp;
		int n = teachers.size();
		for (step = n / 2; step > 0; step /= 2)
			for (i = step; i < n; i++)
			{
				tmp = teachers[i];
				for (j = i; j >= step; j -= step)
				{
					if (compareStrings (tmp.getName(), teachers[j - step].getName())==-1)
						teachers[j] = teachers[j - step];
					else
						break;
				}
				teachers[j] = tmp;
			}
	}
	template <typename T>
	void EverNote<T>::AddTeacher(const Teacher<T> teacher)
	{
		teachers.push_back(teacher);
	}
	template <typename T>
	void EverNote<T>::AddStudent(const Student<T> student)
	{
		students.push_back(student);	
	}
	template <typename T>
	EverNote<T>::EverNote() {
		students = vector<Student<T>>();
		teachers = vector<Teacher<T>>();
	}
	template <typename T>
	EverNote<T>::EverNote(Teacher<T> teacher,Student<T> student):EverNote() {
		
		teachers.push_back(teacher);
		students.push_back(student);
	}
	template <typename T>
	EverNote<T>::EverNote( EverNote<T> &helpNote) {
		for (size_t i = 0; i < helpNote.students.size(); i++)
		{

			Student temrory(helpNote.students[i]);
			students.push_back(temrory);
		}	
		for (size_t i = 0; i < helpNote.teachers.size(); i++)
		{
			Teacher temrory(helpNote.teachers[i]);
			teachers.push_back(temrory);
		}

	}
#include "pch.h"