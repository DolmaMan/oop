#include "Student.h"
using namespace std;

void Student::SetName(const string& n) {
	const char* str = n.c_str();
	for (int i = 0;i < n.size();i++) {
		if ((str[i] < '�' || str[i] > '�') &&
			(str[i] < '�' || str[i] > '�')) {
			name = "�������� ���";
			return;
		}
	}
	name = n;
}

void Student::SetName()
{
	char str[100];
	cout << "\n������� ���: ";
	cin >> str;
	SetName(str);
}

void Student::SetBirthDay()
{
	int day, month, year;
	cout << "\n������� ��� ��������: ";
	cin >> year;
	cout << "\n������� �����: ";
	cin >> month;
	cout << "\n������� ����: ";
	cin >> day;
	birthDay[0] = day;
	birthDay[1] = month;
	birthDay[2] = year;
}

void Student::SetPhoneNumber()
{
	string number;
	cout << "\n������� ����� ��������: ";
	cin >> number;
	phoneNumber = number;
}

void Student::SetCity()
{
	string city;
	cout << "\n������� ��� �����: ";
	cin >> city;
	phoneNumber = city;
}

void Student::SetCountry()
{
	string country;
	cout << "\n������� ���� ������: ";
	cin >> country;
	phoneNumber = country;
}

void Student::SetAllEducat()
{
	string str;
	cout << "\n������� �������� ��������������� �����������: ";
	cin >> str;
	nameEducate = str;

	cout << "\n������� ������ ��������������� �����������: ";
	cin >> str;
	countryEducate = str;

	cout << "\n������� ����� ��������������� �����������: ";
	cin >> str;
	cityEducate = str;
}

void Student::SetGroupNumber()
{
	int num;
	cout << "\n������� ����� ����� ������: ";
	cin >> num;
	groupNumber = num;
}


void Student::Show() {
	cout << "���: " << name << endl;
	cout << "���� ��������: " << birthDay[0] + '.' + birthDay[1] + '.' + birthDay[2] << endl;
	cout << "����� ��������: " << phoneNumber << endl;
	cout << "������: " << country << endl;
	cout << "�����: " << city << endl;
	cout << "�������� ��������������� �����������: " << nameEducate << endl;
	cout << "������ ��������������� �����������: " << countryEducate << endl;
	cout << "����� ��������������� �����������: " << cityEducate << endl;
	cout << "����� ������: " << groupNumber << endl;
}