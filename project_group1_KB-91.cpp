#include <iostream>
#include <windows.h>
#include "Classes.h"

using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    SearchDiscipline currentSearch;
    string nameUser, surnameUser;

    cout << "Введите ваше имя" << endl;
    cin >> nameUser;
    cout << "Введите вашу фамилию" << endl;
    cin >> surnameUser;
    currentSearch.currentUser.checkAdmin(nameUser, surnameUser);
    system("PAUSE");
    system("cls");

    while (true)
    {
        cout << currentSearch.currentUser.getAdminName() << " " << currentSearch.currentUser.getAdminSurname() << " выбирите желаемое действие: " << endl;
        cout << "1 - Поиск дисциплины по заданым параметрам" << endl;
        cout << "2 - Изменить заданые параметры" << endl;
        if (currentSearch.currentUser.getAdminLicence() == 1)
        {
            cout << "3 - Добавить дисциплину" << endl;
            cout << "4 - Изменить параметры администратора" << endl;
            cout << "5 - Обновить базу даных за указаными параметрами" << endl;
            cout << "6 - Удалить дисциплину за указанными параметрами" << endl;
        }
        cout << "0 - Выйти" << endl;

        string choice;
        cin >> choice;
        

        if (choice == "1")
        {
            currentSearch.setResultOfSearch();
            cout << endl << endl;
            currentSearch.printResult();
            system("PAUSE");
            system("cls");
        }
        else if (choice == "2")
        {
            while (true)
            {
                system("PAUSE");
                system("cls");
                int choiceChanges;
                cout << "Текущие параметры (параметр None - параметр по умолчанию)" << endl;
                currentSearch.printDiscipline();
                cout << "Выбирите параметры которые нужно изменить для поиска " << endl;
                cout << "1 - Изменить название предмета" << endl;
                cout << "2 - Изменить группу преподавания " << endl;
                cout << "3 - Изменить искомого преподавателя " << endl;
                cout << "4 - Изменить дату преподавания " << endl;
                cout << "5 - Изменить искомую аудиторию " << endl;
                cout << "6 - Изменить всё параметры " << endl;
                cout << "0 - Выход из процедуры" << endl;
                cin >> choiceChanges;
                system("PAUSE");
                system("cls");
                bool end = 0;
                switch (choiceChanges)
                {
                case 1:
                {
                    string disciplineName;
                    cout << "Введите новое название предмета для поиска" << endl;
                    cin.ignore();
                    getline(cin, disciplineName);
                    currentSearch.setParametr(disciplineName, choiceChanges);
                    break;
                }
                case 2:
                {
                    string groupName;
                    cout << "Введите новое название группы" << endl;
                    cin.ignore();
                    getline(cin, groupName);
                    currentSearch.setParametr(groupName, choiceChanges);
                    break;
                }
                case 3:
                {
                    string nameTeacher;
                    cout << "Введите фамилию преподавателя для поиска" << endl;
                    cin.ignore();
                    getline(cin, nameTeacher);
                    currentSearch.setParametr(nameTeacher, choiceChanges);
                    break;
                }
                case 4:
                {
                    string date;
                    cout << "Введите дату проведения занятия для поиска" << endl;
                    cin.ignore();
                    getline(cin, date);
                    currentSearch.setParametr(date, choiceChanges);
                    break;
                }
                case 5:
                {
                    string audience;
                    cout << "Введите аудиторию для поиска" << endl;
                    cin.ignore();
                    getline(cin, audience);
                    currentSearch.setParametr(audience, choiceChanges);
                    break;
                }
                case 6:
                {
                    string disciplineName, groupName, nameTeacher, date, audience;
                    cout << "Введите новое название предмета для поиска" << endl;
                    cin.ignore();
                    getline(cin, disciplineName, '\n');
                    cout << "Введите новое название группы" << endl;
                    getline(cin, groupName, '\n');
                    cout << "Введите фамилию преподавателя для поиска" << endl;
                    getline(cin, nameTeacher, '\n');
                    cout << "Введите дату проведения занятия для поиска" << endl;
                    getline(cin, date, '\n');
                    cout << "Введите аудиторию для поиска" << endl;
                    getline(cin, audience, '\n');
                    currentSearch.setParametrs(disciplineName, groupName, nameTeacher, date, audience);
                    break;
                }
                case 0:
                {
                    end = 1;
                    break;
                }
                default:
                    cout << "Введено неверное значение! Попробуйте ещё раз!" << endl;
                    cin.fail();
                    break;
                }
                
                if (end == 1)
                {
                    break;
                }
            }
        }
        else if (choice == "3" && currentSearch.currentUser.getAdminLicence() == 1)
        {
            string disciplineName, groupName, nameTeacher, date, audience;
            cout << "Введите  параметры новой дисциплины" << endl;
            cout << "Введите название новой дисциплины" << endl;
            cin.ignore();
            getline(cin, disciplineName, '\n');

            cout << "Введите название группы " << endl;
            getline(cin, groupName, '\n');

            cout << "Введите фамилию преподавателя" << endl;
            getline(cin, nameTeacher, '\n');

            cout << "Введите дату проведения занятия" << endl;
            getline(cin, date, '\n');

            cout << "Введите аудиторию" << endl;
            getline(cin, audience, '\n');

            currentSearch.AddDiscipline(disciplineName, groupName, nameTeacher, date, audience);
            system("PAUSE");
            system("cls");
        }
        else if (choice == "4" && currentSearch.currentUser.getAdminLicence() == 1)
        {
            string AdminName, AdminSurname;
            cout << "Введите новое имя администратора" << endl;
            cin.ignore();
            getline(cin, AdminName, '\n');
            cout << "Введите новую фамилию администратора" << endl;
            getline(cin, AdminSurname, '\n');
            currentSearch.currentUser.changeAdmin(AdminName, AdminSurname);
        }
        else if (choice == "5" && currentSearch.currentUser.getAdminLicence() == 1)
        {
            system("start myScript.exe");
            system("PAUSE");
            system("cls");
        }
        else if (choice == "6" && currentSearch.currentUser.getAdminLicence() == 1)
        {
            while (true)
            {
                system("PAUSE");
                system("cls");
                int choiceChanges;
                cout << "Текущие параметры (параметр None - параметр по умолчанию)" << endl;
                currentSearch.printDeleteDiscipline();
                cout << "Выбирите параметры которые нужно изменить для удаления " << endl;
                cout << "1 - Изменить название предмета" << endl;
                cout << "2 - Изменить группу преподавания " << endl;
                cout << "3 - Изменить искомого преподавателя " << endl;
                cout << "4 - Изменить дату преподавания " << endl;
                cout << "5 - Изменить искомую аудиторию " << endl;
                cout << "6 - Изменить всё параметры " << endl;
                cout << "7 - Удалить за заданными параметрами" << endl;
                cout << "0 - Выход из процедуры" << endl;
                cin >> choiceChanges;
                system("PAUSE");
                system("cls");
                bool end = 0;
                switch (choiceChanges)
                {
                case 1:
                {
                    string disciplineName;
                    cout << "Введите новое название предмета для поиска" << endl;
                    cin.ignore();
                    getline(cin, disciplineName);
                    currentSearch.setDeleteParametr(disciplineName, choiceChanges);
                    break;
                }
                case 2:
                {
                    string groupName;
                    cout << "Введите новое название группы" << endl;
                    cin.ignore();
                    getline(cin, groupName);
                    currentSearch.setDeleteParametr(groupName, choiceChanges);
                    break;
                }
                case 3:
                {
                    string nameTeacher;
                    cout << "Введите фамилию преподавателя для поиска" << endl;
                    cin.ignore();
                    getline(cin, nameTeacher);
                    currentSearch.setDeleteParametr(nameTeacher, choiceChanges);
                    break;
                }
                case 4:
                {
                    string date;
                    cout << "Введите дату проведения занятия для поиска" << endl;
                    cin.ignore();
                    getline(cin, date);
                    currentSearch.setDeleteParametr(date, choiceChanges);
                    break;
                }
                case 5:
                {
                    string audience;
                    cout << "Введите аудиторию для поиска" << endl;
                    cin.ignore();
                    getline(cin, audience);
                    currentSearch.setDeleteParametr(audience, choiceChanges);
                    break;
                }
                case 6:
                {
                    string disciplineName, groupName, nameTeacher, date, audience;
                    cout << "Введите новое название предмета для поиска" << endl;
                    cin.ignore();
                    getline(cin, disciplineName, '\n');
                    cout << "Введите новое название группы" << endl;
                    getline(cin, groupName, '\n');
                    cout << "Введите фамилию преподавателя для поиска" << endl;
                    getline(cin, nameTeacher, '\n');
                    cout << "Введите дату проведения занятия для поиска" << endl;
                    getline(cin, date, '\n');
                    cout << "Введите аудиторию для поиска" << endl;
                    getline(cin, audience, '\n');
                    currentSearch.setDeleteParametrs(disciplineName, groupName, nameTeacher, date, audience);
                    break;
                }
                case 7:
                    currentSearch.deleteDiscipline();
                    cout << "Дисциплины удалены" << endl;
                    break;
                case 0:
                {
                    end = 1;
                    break;
                }
                default:
                    cout << "Введено неверное значение! Попробуйте ещё раз!" << endl;
                    cin.fail();
                    break;
                }

                if (end == 1)
                {
                    break;
                }
            }
        }
        else if (choice == "0")
        {
            return 0;
        }
        else
        {
            cout << "Выбрано неверное действие! Попробуйте ещё раз!" << endl;
            system("PAUSE");
            system("cls");
        }
    }
}