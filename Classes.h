#pragma once
#include <vector>
#include <string>

using namespace std;

class Discipline
{
private:
	string disciplineName;
    string groupName;
	string nameTeacher;
	string date;
	string audience;
public:
	Discipline();
	void setDisciplineName(string DisciplineName);
	string getDisciplineName();
	void setGroupName(string GroupName);
	string getGroupName();
	void setNameTeacher(string NameTeacher);
	string getNameTeacher();
	void setDate(string Date);
	string getDate();
	void setAudience(string Audience);
	string getAudience();
};

class User
{
private:
	bool adminLicence;
	string adminName;
	string adminSurname;
public:
	User();
	void setAdminLicence(bool AdminLicense);
	bool getAdminLicence();
	void setAdminName(string AdminName);
	string getAdminName();
	void setAdminSurname(string AdminSurname);
	string getAdminSurname();
	void checkAdmin(string AdminName, string AdminSurname);
	void changeAdmin(string AdminName, string AdminSurname);
};
class SearchDiscipline
{
private:
	vector<Discipline> resultOfSearch;
	Discipline searchParametrs;
	User currentUser;
public:
	SearchDiscipline();
	void setParametrs(string GroupName, string NameTeacher, string Date, string Audience);
	void LastSearch();
	void AddDiscipline(string DisciplineName, string GroupName, string NameTeacher, string Date, string Audience);
	void setResultOfSearch();
	void printResult();
};