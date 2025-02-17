#pragma once

#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Student {
	string name;
	int birthDay[3];
	string phoneNumber;
	string city;
	string country;

	string nameEducate;
	string cityEducate;
	string countryEducate;
	int groupNumber;

public:
	void SetName(const string& n);
	void SetName();

	void SetBirthDay();
	
	void SetPhoneNumber();
	void SetCity();
	void SetCountry();

	void SetAllEducat();
	void SetGroupNumber();
	
	void Show();
};