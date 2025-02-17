#include<iostream>
#include<Windows.h>
#include<string>
#include<vector>
#include"Fraction.h"
#include"Student.h"
//#include"Point.h"
#include"Phones.h"



int main() {
	setlocale(LC_ALL, "RU");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	string path = "phones.txt";
	
	string name = "Фамилия Имя Отчество";
	string homePhone = "345676";
	string workPhone = "";
	string mobilePhone = "88005553535";
	string additionalInfo = "конаткт";

	Phones contact1;
	
	contact1 = contact1.FindPhone(contact1.LoadFile(path));
	contact1.ShowPhone();

	//contact1.

	/*Fraction fr1;
	fr1.GetFraction();*/


	/*point1.LoadFile("data.txt");
	point1.Show();*/
	return 0;
}