#pragma once

#include<string>

using namespace std;

class Phones
{
private:
	string name;
	string homePhone;
	string workPhone;
	string mobilePhone;
	string additionalInfo;
public:
	Phones(string name, string homePhone, string workPhone, string mobilePhone, string additionalInfo);
	Phones();

	~Phones();

	void AddNewPhone();
	void ChangeOldPhone();
	void ShowPhone();

	void DeletePhone();
	Phones FindPhone(vector<string>);

	void SaveFile(string path);
	vector<string> LoadFile(string path);
};

