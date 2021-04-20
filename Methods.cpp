#pragma once
#include "Classes.h"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

Discipline::Discipline()
{}

void Discipline::setAudience(string Audience)
{
	audience = Audience;
}

void Discipline::setDate(string Date)
{
	date = Date;
}

void Discipline::setDisciplineName(string DisciplineName)
{
	disciplineName = DisciplineName;
}

void Discipline::setGroupName(string GroupName)
{
	groupName = GroupName;
}

void Discipline::setNameTeacher(string NameTeacher)
{
	nameTeacher = NameTeacher;
}

string Discipline::getAudience()
{
	return audience;
}

string Discipline::getDate()
{
	return date;
}

string Discipline::getDisciplineName()
{
	return disciplineName;
}

string Discipline::getGroupName()
{
	return groupName;
}

string Discipline::getNameTeacher()
{
	return nameTeacher;
}

User::User()
{
	adminLicence = 0;
}

void User::setAdminLicence(bool AdminLicense)
{
	adminLicence = AdminLicense;
}

void User::setAdminName(string AdminName)
{
	adminName = AdminName;
}

void User::setAdminSurname(string AdminSurname)
{
	adminSurname = AdminSurname;
}

void User::setAdminPassword(string AdminPassword)
{
	adminPassword = AdminPassword;
}

void User::checkAdmin(string AdminName, string AdminSurname)
{
	ifstream adminConfig;
	adminConfig.open("adminconfig.txt");
	adminConfig >> adminName;
	adminConfig >> adminSurname;
	
	if (adminName == AdminName && adminSurname == AdminSurname)
	{
		
		while (true)
		{
			string choice;
			cout << "Введите пароль если вы администратор" << endl;
			cout << "1 - Я не администратор" << endl;
			cout << "2 - Ввести пароль" << endl;
			cin >> choice;
			if (choice == "1")
			{
				cout << "----Добро пожаловать пользователь!----" << endl;
				setAdminLicence(0);
				break;
			}
			else if (choice == "2")
			{
				adminConfig >> adminPassword;
				string password;
				cout << "Введите пароль:" << endl;
				cin >> password;
				if (password == adminPassword)
				{
					cout << "----Добро пожаловать администратор!----" << endl;
					setAdminLicence(1);
				    break;
				}
				else
				{
					cout << "Введен неправильный пароль! Попробуйте ещё раз!" << endl;
				}
			}
			else
			{
				cout << "Выбрано неправильное действие. Попробуйте ещё раз!" << endl;
			}
		}
	}
	else
	{
		cout << "----Добро пожаловать пользователь!----" << endl;
		setAdminName(AdminName);
		setAdminSurname(AdminSurname);
		setAdminLicence(0);
	}
	adminConfig.close();
}

void User::changeAdmin(string AdminName, string AdminSurname)
{
	cout << "Для того чтобы поменять конфигурацию введите текущий пароль" << endl;
	string currentPsw;
	cin >> currentPsw;
	if (currentPsw == getAdminPassword())
	{
		ofstream adminConfig;
		adminConfig.open("adminconfig.txt");
		adminConfig << AdminName << endl;
		adminConfig << AdminSurname << endl;
		cout << "Если желаете поменять пароль нажмите 1" << endl;
		string t;
		cin >> t;
		if (t == "1")
		{
			string newPsw, repeatNewPsw;
			cout << "Введите новый пароль" << endl;
			cin >> newPsw;
			cout << "Повторите пароль" << endl;
			cin >> repeatNewPsw;
			while (newPsw != repeatNewPsw)
			{
				cout << "Пароли не совпадают! Попробуйте ещё раз!" << endl;
				cout << "Введите новый пароль" << endl;
				cin >> newPsw;
				cout << "Повторите пароль" << endl;
				cin >> repeatNewPsw;
			}
			adminConfig << newPsw << endl;
		}
		else
		{
			adminConfig << currentPsw << endl;
		}		
		cout << "Изменения успешно сохранены! Со следующего входа они вступят в действие" << endl;
	}
	else
	{
		cout << "Введен неверный текущий пароль! Попробуйте ещё раз!" << endl;
	}
	system("PAUSE");
	system("cls");
}

bool User::getAdminLicence()
{
	return adminLicence;
}

string User::getAdminPassword()
{
	return adminPassword;
}

string User::getAdminName()
{
	return adminName;
}

string User::getAdminSurname()
{
	return adminSurname;
}

SearchDiscipline::SearchDiscipline()
{
	ifstream searchConfig;
	searchConfig.open("searchConfig.txt");
	string DisciplineName, GroupName, NameTeacher, Date, Audience;
	searchConfig >> DisciplineName;
	searchConfig >> GroupName;
	searchConfig >> NameTeacher;
	searchConfig >> Date;
	searchConfig >> Audience;
	searchConfig.close();
	setParametrs(DisciplineName, GroupName, NameTeacher, Date, Audience);
}
void SearchDiscipline::setParametr(string parametr, int choice)
{
	switch (choice)
	{
	case 1:
		searchParametrs.setDisciplineName(parametr);
		break;
	case 2:
		searchParametrs.setGroupName(parametr);
		break;
	case 3:
		searchParametrs.setNameTeacher(parametr);
		break;
	case 4:
		searchParametrs.setDate(parametr);
		break;
	case 5:
		searchParametrs.setAudience(parametr);
		break;
	default:
		break;
	}

	ofstream searchConfig;
	searchConfig.open("searchConfig.txt");
	searchConfig << searchParametrs.getDisciplineName() << endl;
	searchConfig << searchParametrs.getGroupName() << endl;
	searchConfig << searchParametrs.getNameTeacher() << endl;
	searchConfig << searchParametrs.getDate() << endl;
	searchConfig << searchParametrs.getAudience() << endl;
	searchConfig.close();
}

void SearchDiscipline::setParametrs(string DisciplineName, string GroupName, string NameTeacher, string Date, string Audience)
{
	searchParametrs.setDisciplineName(DisciplineName);
	searchParametrs.setGroupName(GroupName);
	searchParametrs.setNameTeacher(NameTeacher);
	searchParametrs.setDate(Date);
	searchParametrs.setAudience(Audience);


	ofstream searchConfig;
	searchConfig.open("searchConfig.txt");
	searchConfig << searchParametrs.getDisciplineName() << endl;
	searchConfig << searchParametrs.getGroupName() << endl;
	searchConfig << searchParametrs.getNameTeacher() << endl;
	searchConfig << searchParametrs.getDate() << endl;
	searchConfig << searchParametrs.getAudience() << endl;
	searchConfig.close();
}

void SearchDiscipline::AddDiscipline(string DisciplineName, string GroupName, string NameTeacher, string Date, string Audience)
{
	fstream AllDiscipline;
	AllDiscipline.open("allDiscipline.txt", ios_base::app);
	AllDiscipline << DisciplineName << endl;
	AllDiscipline << GroupName << endl;
	AllDiscipline << NameTeacher << endl;
	AllDiscipline << Date << endl;
	AllDiscipline << Audience << endl;
}

void SearchDiscipline::setResultOfSearch()
{
	cout << "Заданные параметры дисциплины:" << endl;
	printDiscipline();
	ifstream AllDiscipline;
	AllDiscipline.open("allDiscipline.txt");
	while (!AllDiscipline.eof())
	{
		string t;
		Discipline temp;
		AllDiscipline >> t;
		temp.setDisciplineName(t);
		AllDiscipline >> t;
		temp.setGroupName(t);
		AllDiscipline >> t;
		temp.setNameTeacher(t);
		AllDiscipline >> t;
		temp.setDate(t);
		AllDiscipline >> t;
		temp.setAudience(t);
		if ((temp.getDisciplineName() == searchParametrs.getDisciplineName() || searchParametrs.getDisciplineName() == "None")&&
			(temp.getGroupName() == searchParametrs.getGroupName() || searchParametrs.getGroupName() == "None") &&
			(temp.getNameTeacher() == searchParametrs.getNameTeacher() || searchParametrs.getNameTeacher() == "None") &&
			(temp.getDate() == searchParametrs.getDate() || searchParametrs.getDate() == "None") && 
			(temp.getAudience() == searchParametrs.getAudience() || searchParametrs.getAudience() == "None"))
		{
			resultOfSearch.push_back(temp);
		}
	}
}

void SearchDiscipline::printResult()
{
	cout << "Результаты поиска дисциплин за задаными параметрами:" << endl;
	for(int i = 0; i < resultOfSearch.size(); i++)
	{ 
		cout << "Название дисциплины - " << resultOfSearch[i].getDisciplineName() << endl;
		cout << "Группа преподавания дисциплины - " << resultOfSearch[i].getGroupName() << endl;
		cout << "Преподаватель - " << resultOfSearch[i].getNameTeacher() << endl;
		cout << "Дата преподавания - " << resultOfSearch[i].getDate() << endl;
		cout << "Аудитория преподавания - " << resultOfSearch[i].getAudience() << endl;
	}
}

void SearchDiscipline::printDiscipline()
{
	cout << "Название дисциплины - " << searchParametrs.getDisciplineName() << endl;
	cout << "Группа преподавания дисциплины - " << searchParametrs.getGroupName() << endl;
	cout << "Преподаватель - " << searchParametrs.getNameTeacher() << endl;
	cout << "Дата преподавания - " << searchParametrs.getDate() << endl;
	cout << "Аудитория преподавания - " << searchParametrs.getAudience() << endl;
}