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
	name = "Иванов Иван Иванович";
	homePhone = "643426";
	workPhone = "83957770707";
	mobilePhone = "88005553535";
	additionalInfo = "НЕ БРАТЬ! ДОЛГ 3000";

}

Phones::~Phones()
{
	cout << "Удален объект: " << name << '\n';
}

void Phones::AddNewPhone()
{
	cout << "Заполните данные о новом контакте (чтобы пропустить поле, нажмите Enter):\n";

	cout << "Введите ФИО нового контакта: ";
	getline(cin, name);
	while (name.empty()) {
		cout << "ФИО не может быть пустым, введите ФИО: ";
		getline(cin, name);
	}
	
	cout << "Введите номер домашнего телефона контакта: ";
	getline(cin, homePhone);
	if (homePhone.empty())
		homePhone = "-";

	cout << "Введите номер рабочего телефона контакта: ";
	getline(cin, workPhone);
	if (workPhone.empty())
		workPhone = "-";

	cout << "Введите номер мобильного телефона контакта: ";
	getline(cin, mobilePhone);
	while (mobilePhone.empty()) {
		cout << "номер мобильного телефона не может быть пустым, введите номер мобильного телефона: ";
		getline(cin, mobilePhone);
	}
	cout << "Введите дополнительную информацию о контакте: ";
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
		cout << "ФИО: " << name << endl;
		cout << "Домашний телефон: " << homePhone << endl;
		cout << "Рабочий телефон: " << workPhone << endl;
		cout << "Мобильный телефон: " << mobilePhone << endl;
		cout << "Дополнительная информация: " << additionalInfo << endl;
	}
}

void Phones::DeletePhone(vector<string> ContactsVec, string path)
{
	string currentContact;
	string contactToFind;

	bool isFind = false;

	cout << "Введите ФИО контакта для удаления: ";
	getline(cin, contactToFind);

	while (true) {
		for (int i = 0;i < ContactsVec.size();i++) { // Поиск нужного ФИО по всем контактам
			if (contactToFind == ContactsVec[i].substr(0, ContactsVec[i].find("~"))) {
				currentContact = ContactsVec[i];
				isFind = true;
			}
		}
		if (!isFind) { // Если контакт не нашелся
			string answer = "";
			cout << "Контакта с данным именем не существует.\nПопробовать еще раз? yes/no: ";
			getline(cin, answer);
			if (answer == "yes" || answer == "y" || answer == "YES" || answer == "Yes") {
				cout << "Введите ФИО контакта для удаления: ";
				getline(cin, contactToFind);
				continue;
			}
			else if (answer == "no" || answer == "n" || answer == "NO" || answer == "No") {
				break;
			}
			else {
				cout << "Ошибка ввода\n";
			}
		}
		else { // Если контакт нашелся
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

	cout << "Введите ФИО контакта для поиска: ";
	getline(cin, contactToFind);

	while (true) {
		for (int i = 0;i < ContactsVec.size();i++) { // Поиск нужного ФИО по всем контактам
			if (contactToFind == ContactsVec[i].substr(0, ContactsVec[i].find("~"))) {
				currentContact = ContactsVec[i];
				isFind = true;
			}
		}
		if (!isFind) { // Если контакт не нашелся
			string answer = "";
			cout << "Контакта с данным именем не существует.\nПопробовать еще раз? yes/no: ";
			getline(cin, answer);
			if (answer == "yes" || answer == "y" || answer == "YES" || answer == "Yes") {
				cout << "Введите ФИО контакта для поиска: ";
				getline(cin, contactToFind);
				continue;
			}
			else if (answer == "no" || answer == "n" || answer == "NO" || answer == "No") {
				break;
			}
			else {
				cout << "Ошибка ввода\n";
			}
		}
		else { // Если контакт нашелся
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
