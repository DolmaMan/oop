#include "Student.h"
using namespace std;

void Student::SetName(const string& n) {
	const char* str = n.c_str();
	for (int i = 0;i < n.size();i++) {
		if ((str[i] < 'А' || str[i] > 'Я') &&
			(str[i] < 'а' || str[i] > 'я')) {
			name = "неверное имя";
			return;
		}
	}
	name = n;
}

void Student::SetName()
{
	char str[100];
	cout << "\nВведите имя: ";
	cin >> str;
	SetName(str);
}

void Student::SetBirthDay()
{
	int day, month, year;
	cout << "\nВведите год рождения: ";
	cin >> year;
	cout << "\nВведите месяц: ";
	cin >> month;
	cout << "\nВведите день: ";
	cin >> day;
	birthDay[0] = day;
	birthDay[1] = month;
	birthDay[2] = year;
}

void Student::SetPhoneNumber()
{
	string number;
	cout << "\nВведите номер телефона: ";
	cin >> number;
	phoneNumber = number;
}

void Student::SetCity()
{
	string city;
	cout << "\nВведите ваш город: ";
	cin >> city;
	phoneNumber = city;
}

void Student::SetCountry()
{
	string country;
	cout << "\nВведите вашу страну: ";
	cin >> country;
	phoneNumber = country;
}

void Student::SetAllEducat()
{
	string str;
	cout << "\nВведите название образовательной организации: ";
	cin >> str;
	nameEducate = str;

	cout << "\nВведите страну образовательной организации: ";
	cin >> str;
	countryEducate = str;

	cout << "\nВведите город образовательной организации: ";
	cin >> str;
	cityEducate = str;
}

void Student::SetGroupNumber()
{
	int num;
	cout << "\nВведите номер вашей группы: ";
	cin >> num;
	groupNumber = num;
}


void Student::Show() {
	cout << "ФИО: " << name << endl;
	cout << "Дата рождения: " << birthDay[0] + '.' + birthDay[1] + '.' + birthDay[2] << endl;
	cout << "Номер телефона: " << phoneNumber << endl;
	cout << "Страна: " << country << endl;
	cout << "Город: " << city << endl;
	cout << "Название образовательной организации: " << nameEducate << endl;
	cout << "Страна образовательной организации: " << countryEducate << endl;
	cout << "Город образовательной организации: " << cityEducate << endl;
	cout << "Номер группы: " << groupNumber << endl;
}