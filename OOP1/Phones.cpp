#include<iostream>
#include<fstream>
#include<vector>
#include "Phones.h"


using namespace std;

Phones::Phones(string namea, string homePhonea, string workPhonea, string mobilePhonea, string additionalInfoa)
{
	name = namea;
	homePhone = homePhonea;
	workPhone = workPhonea;
	mobilePhone = mobilePhonea;
	additionalInfo = additionalInfoa;
}

Phones::Phones()
{
	name = "������ ���� ��������";
	homePhone = "643426";
	workPhone = "83957770707";
	mobilePhone = "88005553535";
	additionalInfo = "�� �����! ���� 3000";

}

Phones::~Phones()
{
	cout << "������ ������: " << name << '\n';
}

void Phones::AddNewPhone()
{
	cout << "��������� ������ � ����� �������� (����� ���������� ����, ������� Enter):\n";

	cout << "������� ��� ������ ��������: ";
	getline(cin, name);
	while (name.empty()) {
		cout << "��� �� ����� ���� ������, ������� ���: ";
		getline(cin, name);
	}
	
	cout << "������� ����� ��������� �������� ��������: ";
	getline(cin, homePhone);
	if (homePhone.empty())
		homePhone = "-";

	cout << "������� ����� �������� �������� ��������: ";
	getline(cin, workPhone);
	if (workPhone.empty())
		workPhone = "-";

	cout << "������� ����� ���������� �������� ��������: ";
	getline(cin, mobilePhone);
	while (mobilePhone.empty()) {
		cout << "����� ���������� �������� �� ����� ���� ������, ������� ����� ���������� ��������: ";
		getline(cin, mobilePhone);
	}
	cout << "������� �������������� ���������� � ��������: ";
	getline(cin, additionalInfo);
	if (additionalInfo.empty())
		additionalInfo = "-";
}

void Phones::ChangeOldPhone()
{
}

void Phones::ShowPhone()
{
	if (name != "") {
		cout << "���: " << name << endl;
		cout << "�������� �������: " << homePhone << endl;
		cout << "������� �������: " << workPhone << endl;
		cout << "��������� �������: " << mobilePhone << endl;
		cout << "�������������� ����������: " << additionalInfo << endl;
	}
}

void Phones::DeletePhone(vector<string> ContactsVec, string path)
{
	string currentContact;
	string contactToFind;

	bool isFind = false;

	cout << "������� ��� �������� ��� ��������: ";
	getline(cin, contactToFind);

	while (true) {
		for (int i = 0;i < ContactsVec.size();i++) { // ����� ������� ��� �� ���� ���������
			if (contactToFind == ContactsVec[i].substr(0, ContactsVec[i].find("~"))) {
				currentContact = ContactsVec[i];
				isFind = true;
			}
		}
		if (!isFind) { // ���� ������� �� �������
			string answer = "";
			cout << "�������� � ������ ������ �� ����������.\n����������� ��� ���? yes/no: ";
			getline(cin, answer);
			if (answer == "yes" || answer == "y" || answer == "YES" || answer == "Yes") {
				cout << "������� ��� �������� ��� ��������: ";
				getline(cin, contactToFind);
				continue;
			}
			else if (answer == "no" || answer == "n" || answer == "NO" || answer == "No") {
				break;
			}
			else {
				cout << "������ �����\n";
			}
		}
		else { // ���� ������� �������
			int currentIndex = 0, nextIndex = currentContact.find("~");

			name = currentContact.substr(currentIndex, nextIndex - currentIndex);

			currentIndex = nextIndex + 1;
			nextIndex = currentContact.find("~", currentIndex);
			homePhone = currentContact.substr(currentIndex, nextIndex - currentIndex);

			currentIndex = nextIndex + 1;
			nextIndex = currentContact.find("~", currentIndex);
			workPhone = currentContact.substr(currentIndex, nextIndex - currentIndex);

			currentIndex = nextIndex + 1;
			nextIndex = currentContact.find("~", currentIndex);
			mobilePhone = currentContact.substr(currentIndex, nextIndex - currentIndex);

			currentIndex = nextIndex + 1;
			additionalInfo = currentContact.substr(currentIndex, currentContact.size());
			break;
		}
	}
	if (!isFind) {
		ofstream ofs;
		ofs.open(path, ofstream::out | ofstream::trunc);
		ofs.close();
		this->SaveFile(path);
	}
}

Phones Phones::FindPhone(vector<string> ContactsVec)
{
	string currentContact;
	string contactToFind;

	bool isFind = false;

	cout << "������� ��� �������� ��� ������: ";
	getline(cin, contactToFind);

	while (true) {
		for (int i = 0;i < ContactsVec.size();i++) { // ����� ������� ��� �� ���� ���������
			if (contactToFind == ContactsVec[i].substr(0, ContactsVec[i].find("~"))) {
				currentContact = ContactsVec[i];
				isFind = true;
			}
		}
		if (!isFind) { // ���� ������� �� �������
			string answer = "";
			cout << "�������� � ������ ������ �� ����������.\n����������� ��� ���? yes/no: ";
			getline(cin, answer);
			if (answer == "yes" || answer == "y" || answer == "YES" || answer == "Yes") {
				cout << "������� ��� �������� ��� ������: ";
				getline(cin, contactToFind);
				continue;
			}
			else if (answer == "no" || answer == "n" || answer == "NO" || answer == "No") {
				break;
			}
			else {
				cout << "������ �����\n";
			}
		}
		else { // ���� ������� �������
			int currentIndex = 0, nextIndex = currentContact.find("~");
			
			name = currentContact.substr(currentIndex, nextIndex - currentIndex);
			
			currentIndex = nextIndex + 1;
			nextIndex = currentContact.find("~", currentIndex);
			homePhone = currentContact.substr(currentIndex, nextIndex - currentIndex);
			
			currentIndex = nextIndex + 1;
			nextIndex = currentContact.find("~", currentIndex);
			workPhone = currentContact.substr(currentIndex, nextIndex - currentIndex);
			
			currentIndex = nextIndex + 1;
			nextIndex = currentContact.find("~", currentIndex);
			mobilePhone = currentContact.substr(currentIndex, nextIndex - currentIndex);
			
			currentIndex = nextIndex + 1;
			additionalInfo = currentContact.substr(currentIndex, currentContact.size());
			break;
		}
	}
	if (!isFind) {
		return {"", "", "", "", ""};
	}
	return { name, homePhone, workPhone, mobilePhone, additionalInfo };
}

void Phones::SaveFile(string path)
{
	ofstream file(path, ios::app);
	file << name << '~' << homePhone << '~' << workPhone << '~' << mobilePhone << '~' << additionalInfo << endl;
	file.close();
}

vector<string> Phones::LoadFile(string path)
{
	vector<string> ContactsVec;
	string str;
	ifstream file(path, ios::in);
	while (getline(file, str)) {
		ContactsVec.push_back(str);
	}
	file.close();
	return ContactsVec;
}
