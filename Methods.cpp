#pragma once
#include "Classes.h"
#include <vector>
#include <string>

using namespace std;

Discipline::Discipline()
{

}

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

void User::checkAdmin(string AdminName, string AdminSurname)
{

}

void User::changeAdmin(string AdminName, string AdminSurname)
{

}

bool User::getAdminLicence()
{
	return adminLicence;
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

}

void SearchDiscipline::setParametrs(string GroupName, string NameTeacher, string Date, string Audience)
{

}

void SearchDiscipline::LastSearch()
{

}

void SearchDiscipline::AddDiscipline(string DisciplineName, string GroupName, string NameTeacher, string Date, string Audience)
{

}

void SearchDiscipline::setResultOfSearch()
{

}

void SearchDiscipline::printResult()
{

}