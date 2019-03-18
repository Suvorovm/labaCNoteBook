
#include "pch.h"
#include <iostream>
#include "EverNote.h"
#include <vector>
#include <string>
#include <functional>

using namespace std;
int main()
{
	
	//string (*dele)(Student<string> student)
	setlocale(LC_ALL, "rus");
	tm data;
	data.tm_year = 1954;
	data.tm_mon = 2;
	data.tm_mday = 20;
	string name = "Иван";
	string name2 = "Иван123";
	string lastName = "Ивонов";
	string phoneNumper = "89648723383";
	string group = "17vi1";	
	
	string nameTeach = "Яков";
	string lastNameTeach = "Жижов";
	string phoneNumberTeach = "89648723103";
	string facility = "FVT";
	//Teacher<string> tch;
	//Person<int> pers("Антон","Доров",8984848,data);
	//
	//Teacher<string> teacherM(nameTeach, lastNameTeach, phoneNumberTeach, data, facility);

	//Student<string> student(name, lastName,data,  group,phoneNumper);
	//
	//EverNote<string> evertNote;
	//evertNote.AddStudent(student);
	//evertNote.AddTeacher(teacherM);

	//for (size_t i = 0; i < 5; i++)
	//{
	//	string tmp = name;
	//	tmp[0] -= 1;
	//	Student<string> temprory(tmp,lastName,data,group,phoneNumper);
	//	evertNote.AddStudent(temprory);
	//}
	//string tmp = nameTeach;
	//for (size_t i = 0; i < 5; i++)
	//{		
	//	tmp[0] -=1 ;
	//	Teacher<string> temprory(tmp,lastNameTeach,phoneNumberTeach,data,facility);
	//	evertNote.AddTeacher(temprory);
	//}
	//vector<Teacher<string>> returnsTeachers = evertNote.getTeacherVector();
	//cout << "\nДобавленные преподаватели \n";
	//for (size_t i = 0; i < returnsTeachers.size(); i++)
	//{
	//	cout << returnsTeachers[i]<<endl;
	//}
	//cout << "\nУдаление преподователя\n";
	//evertNote.DeletePerson(nameTeach,lastNameTeach,phoneNumberTeach,TeacherT);
	//cout << "Вектор - после удаления одного преподавателя: \n"<<teacherM<<endl;
	//returnsTeachers = evertNote.getTeacherVector();
	//cout << "----------------------------\n";
	//for (size_t i = 0; i < returnsTeachers.size(); i++)
	//{
	//	cout << returnsTeachers[i] << endl;
	//}
	//cout << "\nРезультаты сортировки преподавателей\n";
	//cout << "\n-------------------------\n";
	//evertNote.SortByNameTeachers();
	//returnsTeachers = evertNote.getTeacherVector();
	//cout << endl << endl;
	//for (size_t i = 0; i < returnsTeachers.size(); i++)
	//{
	//	cout << returnsTeachers[i] << endl;
	//}
	//cout << "\nПоиск персон \n";
	//Student<string> forSearching("Женя", "Иванов1", "895478962", "12VP1");
	//Teacher<string> forTeaching("Женя", "Иванов", "895478962", data, "ФПИСН");
	//evertNote.AddStudent(forSearching);
	//evertNote.AddTeacher(forTeaching);

	//vector<Person<string>> persons = evertNote.FindPersonByName("Женя");

	//for (size_t i = 0; i < persons.size(); i++)
	//{
	//	cout << persons[i] << endl;
	//}
	Student<string> student(name, lastName,data,  group,phoneNumper);
	EverNote<string> evertNote;
	auto deleg = [](Student<string> student) {
		return student.getName();//делегат
	};
	evertNote.AddStudent(student);
	 for (size_t i = 0; i < 5; i++)
		{
			string tmp = name;
			tmp[0] -= i;
			Student<string> temprory(tmp,lastName,data,group,phoneNumper);
			evertNote.AddStudent(temprory);
		}
	
	  cout << "\nДобавленные студенты \n";
	  vector<Student<string>> returnsStudents= evertNote.getStudentsVector();
	 for (size_t i = 0; i < returnsStudents.size(); i++)
	 {
	 	cout << returnsStudents[i]<<endl;
	 }
	 evertNote.SortStudents(deleg);//сортировка
	 returnsStudents = evertNote.getStudentsVector();
	
	 cout << "\nПосле сортировки студенты \n";
	 for (size_t i = 0; i < returnsStudents.size(); i++)
	 {
		 cout << returnsStudents[i] << endl;
	 }
	cout << "\n\n\n";
	return 0;
}

