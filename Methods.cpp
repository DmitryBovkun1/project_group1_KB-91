#pragma once
#include "Classes.h"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

string XOR_Crypt(string in, string pass = "vSE229NxY68R3VLhd585H3gcsMXeyd9c")//������� ���������� ������
//https://www.cyberforum.ru/cpp-builder/thread1423548.html
{
	string out;
	for (int x = 1; x < in.length() + 1; x++)
	{
		out += (char)(in[x] ^ pass[x % pass.length() + 1]);
	}
	return out;
}

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

void User::checkAdmin(string AdminName, string AdminSurname)//�������� �� �� ���� �� ������������ ���������������
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
			cout << "������� ������ ���� �� �������������" << endl;
			cout << "1 - � �� �������������" << endl;
			cout << "2 - ������ ������" << endl;
			cin >> choice;
			if (choice == "1")
			{
				cout << "----����� ���������� ������������!----" << endl;
				setAdminLicence(0);
				break;
			}
			else if (choice == "2")
			{
				adminConfig >> adminPassword;
				string password;
				cout << "������� ������:" << endl;
				cin >> password;

				if (XOR_Crypt(password) == adminPassword)
				{
					cout << "----����� ���������� �������������!----" << endl;
					setAdminLicence(1);
				    break;
				}
				else
				{
					cout << "������ ������������ ������! ���������� ��� ���!" << endl;
				}
			}
			else
			{
				cout << "������� ������������ ��������. ���������� ��� ���!" << endl;
			}
		}
	}
	else
	{
		cout << "----����� ���������� ������������!----" << endl;
		setAdminName(AdminName);
		setAdminSurname(AdminSurname);
		setAdminLicence(0);
	}
	adminConfig.close();
}

void User::changeAdmin(string AdminName, string AdminSurname)//����� ��� ��������� ���������� ��������������
{
	cout << "��� ���� ����� �������� ������������ ������� ������� ������" << endl;
	string currentPsw;
	cin >> currentPsw;
	if (XOR_Crypt(currentPsw) == getAdminPassword())
	{
		ofstream adminConfig;
		adminConfig.open("adminconfig.txt");
		adminConfig << AdminName << endl;
		adminConfig << AdminSurname << endl;
		cout << "���� ������� �������� ������ ������� 1" << endl;
		string t;
		cin >> t;
		if (t == "1")
		{
			string newPsw, repeatNewPsw;
			cout << "������� ����� ������" << endl;
			cin >> newPsw;
			cout << "��������� ������" << endl;
			cin >> repeatNewPsw;
			while (newPsw != repeatNewPsw)
			{
				cout << "������ �� ���������! ���������� ��� ���!" << endl;
				cout << "������� ����� ������" << endl;
				cin >> newPsw;
				cout << "��������� ������" << endl;
				cin >> repeatNewPsw;
			}
			adminConfig << XOR_Crypt(newPsw) << endl;
		}
		else
		{
			adminConfig << XOR_Crypt(currentPsw) << endl;
		}		
		cout << "��������� ������� ���������! �� ���������� ����� ��� ������� � ��������" << endl;
	}
	else
	{
		cout << "������ �������� ������� ������! ���������� ��� ���!" << endl;
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
	getline(searchConfig, DisciplineName);
	getline(searchConfig, GroupName);
	getline(searchConfig, NameTeacher);
	getline(searchConfig, Date);
	getline(searchConfig, Audience);
	searchConfig.close();
	setParametrs(DisciplineName, GroupName, NameTeacher, Date, Audience);
	ifstream deleteConfig;
	deleteConfig.open("deleteConfig.txt");
	getline(deleteConfig, DisciplineName);
	getline(deleteConfig, GroupName);
	getline(deleteConfig, NameTeacher);
	getline(deleteConfig, Date);
	getline(deleteConfig, Audience);
	deleteConfig.close();
	setDeleteParametrs(DisciplineName, GroupName, NameTeacher, Date, Audience);
}
void SearchDiscipline::setParametr(string parametr, int choice)//����� ��� ��������� ��������� ������
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
//����� ��� ��������� ���������� ������
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
//����� ��� ���������� ����� ����������
{
	fstream AllDiscipline;
	AllDiscipline.open("allDiscipline.html", ios_base::app);
	AllDiscipline << DisciplineName << endl;
	AllDiscipline << GroupName << endl;
	AllDiscipline << NameTeacher << endl;
	AllDiscipline << Date << endl;
	AllDiscipline << Audience << endl;
	AllDiscipline.close();
}

void SearchDiscipline::setResultOfSearch()//���������� ��������������� �������
{
	cout << "�������� ��������� ����������:" << endl;
	printDiscipline();
	ifstream AllDiscipline;
	AllDiscipline.open("allDiscipline.html");
	while (!AllDiscipline.eof())
	{
		string t;
		Discipline temp;
		getline(AllDiscipline, t);
		if (t == "")
		{
			break;
		}
		temp.setDisciplineName(t);
		getline(AllDiscipline, t);
		temp.setGroupName(t);
		getline(AllDiscipline, t);
		temp.setNameTeacher(t);
		getline(AllDiscipline, t);
		temp.setDate(t);
		getline(AllDiscipline, t);
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
	AllDiscipline.close();
}

void SearchDiscipline::printResult()//����� ��������������� �������
{
	cout << "���������� ������ ��������� �� �������� �����������:" << endl;
	for(int i = 0; i < resultOfSearch.size(); i++)
	{ 
		cout << "�������� ���������� - " << resultOfSearch[i].getDisciplineName() << endl;
		cout << "������ ������������ ���������� - " << resultOfSearch[i].getGroupName() << endl;
		cout << "������������� - " << resultOfSearch[i].getNameTeacher() << endl;
		cout << "���� ������������ - " << resultOfSearch[i].getDate() << endl;
		cout << "��������� ������������ - " << resultOfSearch[i].getAudience() << endl;
	}
	resultOfSearch.clear();
}

void SearchDiscipline::printDiscipline()//����� ���������� ������ ����������
{
	cout << "�������� ���������� - " << searchParametrs.getDisciplineName() << endl;
	cout << "������ ������������ ���������� - " << searchParametrs.getGroupName() << endl;
	cout << "������������� - " << searchParametrs.getNameTeacher() << endl;
	cout << "���� ������������ - " << searchParametrs.getDate() << endl;
	cout << "��������� ������������ - " << searchParametrs.getAudience() << endl;
}

void SearchDiscipline::printDeleteDiscipline()//����� ���������� �������� ����������
{
	cout << "�������� ���������� - " << deleteParametrs.getDisciplineName() << endl;
	cout << "������ ������������ ���������� - " << deleteParametrs.getGroupName() << endl;
	cout << "������������� - " << deleteParametrs.getNameTeacher() << endl;
	cout << "���� ������������ - " << deleteParametrs.getDate() << endl;
	cout << "��������� ������������ - " << deleteParametrs.getAudience() << endl;
}

void SearchDiscipline::deleteDiscipline()//����� ���������� �������� ����������
{
	ifstream AllDiscipline;
	AllDiscipline.open("allDiscipline.html");
	while (!AllDiscipline.eof())
	{
		string t;
		Discipline temp;
		getline(AllDiscipline, t);
		if (t == "")
		{
			break;
		}
		temp.setDisciplineName(t);
		getline(AllDiscipline, t);
		temp.setGroupName(t);
		getline(AllDiscipline, t);
		temp.setNameTeacher(t);
		getline(AllDiscipline, t);
		temp.setDate(t);
		getline(AllDiscipline, t);
		temp.setAudience(t);
		if (!(temp.getDisciplineName() == deleteParametrs.getDisciplineName() || deleteParametrs.getDisciplineName() == "None") ||
			!(temp.getGroupName() == deleteParametrs.getGroupName() || deleteParametrs.getGroupName() == "None") ||
			!(temp.getNameTeacher() == deleteParametrs.getNameTeacher() || deleteParametrs.getNameTeacher() == "None") ||
			!(temp.getDate() == deleteParametrs.getDate() || deleteParametrs.getDate() == "None") ||
			!(temp.getAudience() == deleteParametrs.getAudience() || deleteParametrs.getAudience() == "None"))
		{
			resultOfSearch.push_back(temp);
		}
	}
	AllDiscipline.close();

	ofstream Discipline;
	Discipline.open("allDiscipline.html");
	for (int i = 0; i < resultOfSearch.size(); i++)
	{
		Discipline << resultOfSearch[i].getDisciplineName() << endl;
		Discipline << resultOfSearch[i].getGroupName() << endl;
		Discipline << resultOfSearch[i].getNameTeacher() << endl;
		Discipline << resultOfSearch[i].getDate() << endl;
		Discipline << resultOfSearch[i].getAudience() << endl;
	}
	resultOfSearch.clear();
	Discipline.close();
}

void SearchDiscipline::setDeleteParametr(string parametr, int choice)//����� ��� ��������� ��������� ��������
{
	switch (choice)
	{
	case 1:
		deleteParametrs.setDisciplineName(parametr);
		break;
	case 2:
		deleteParametrs.setGroupName(parametr);
		break;
	case 3:
		deleteParametrs.setNameTeacher(parametr);
		break;
	case 4:
		deleteParametrs.setDate(parametr);
		break;
	case 5:
		deleteParametrs.setAudience(parametr);
		break;
	default:
		break;
	}

	ofstream deleteConfig;
	deleteConfig.open("deleteConfig.txt");
	deleteConfig << deleteParametrs.getDisciplineName() << endl;
	deleteConfig << deleteParametrs.getGroupName() << endl;
	deleteConfig << deleteParametrs.getNameTeacher() << endl;
	deleteConfig << deleteParametrs.getDate() << endl;
	deleteConfig << deleteParametrs.getAudience() << endl;
	deleteConfig.close();
}

void SearchDiscipline::setDeleteParametrs(string DisciplineName, string GroupName, string NameTeacher, string Date, string Audience)
//����� ��� ��������� ���������� ��������
{
	deleteParametrs.setDisciplineName(DisciplineName);
	deleteParametrs.setGroupName(GroupName);
	deleteParametrs.setNameTeacher(NameTeacher);
	deleteParametrs.setDate(Date);
	deleteParametrs.setAudience(Audience);


	ofstream deleteConfig;
	deleteConfig.open("deleteConfig.txt");
	deleteConfig << deleteParametrs.getDisciplineName() << endl;
	deleteConfig << deleteParametrs.getGroupName() << endl;
	deleteConfig << deleteParametrs.getNameTeacher() << endl;
	deleteConfig << deleteParametrs.getDate() << endl;
	deleteConfig << deleteParametrs.getAudience() << endl;
	deleteConfig.close();
}